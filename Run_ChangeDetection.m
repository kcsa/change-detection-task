%-------------------------------------------------------------------------
% Script to run a single-probe color change detection task for measuring
% visual working memory.
%
% Programmed by Kirsten Adam, June 2014; updated July 2017
%-------------------------------------------------------------------------
function Run_ChangeDetection
clear all;  % clear everything out!
close all;  % close existing figures
warning('off','MATLAB:dispatcher:InexactMatch');  % turn off the case mismatch warning (it's annoying)
dbstop if error  % tell us what the error is if there is one
AssertOpenGL;    % make sure openGL rendering is working (aka psychtoolbox is on the path)
%-------------------------------------------------------------------------
% Build a GUI to get subject number
%-------------------------------------------------------------------------
prompt = {'Subject Number'};            % what information do we want from the subject?
defAns = {''};                                           % fill in some stock answers - here the fields are left blank
box = inputdlg(prompt,'Enter Subject Info');       % build the GUI

p.date_time_start = clock; % record time and date of the start of the sesssion !!

if length(box) == length(defAns)                            % check to make sure something was typed in
    p.subNum = str2num(box{1});
else
    return;                                                 % if nothing was entered or the subject hit cancel, bail out
end

% Set the random seed
rng default
rng shuffle
p.rndSeed = rng;
%-------------------------------------------------------------------------
% Important options
%-------------------------------------------------------------------------
p.windowed = 0; % 1 = smaller window for easy debugging!
p.manually_initiate = 0; 
p.manually_hide_taskbar = 0; % If this is a PC and you want to use the Mex file to hide the taskbar manually

% Throw an error if you try to manually hide the taskbar on a Mac
if p.manually_hide_taskbar && ~ispc
    error('Cannot manually hide the taskbar on Mac OS!')
end
%-------------------------------------------------------------------------
% Build an output directory & check to make sure it doesn't already exist
%-------------------------------------------------------------------------
p.root = pwd;
% if the subject data directory doesn't exist, make one!!
if ~exist([p.root,filesep,'Subject Data',filesep], 'dir')
    mkdir([p.root,filesep,'Subject Data',filesep]);
end
%-------------------------------------------------------------------------
% Build psychtoolbox window & hide the task bar
%-------------------------------------------------------------------------
win = openWindow(p);
%Manually hide the task bar so it doesn't pop up because of flipping
%the PTB screen (Note, this is only needed because of an annoying
% glitch that I can't figure out wiht newer windows machines... 
% Setting the windows settings to "auto-hide the taskbar" can also work,
% try that first! if that doesn't work, use this Mex file .
if p.manually_hide_taskbar
    ShowHideWinTaskbarMex(0);
end
%-------------------------------------------------------------------------
% Run Experiment 1
%-------------------------------------------------------------------------
% Build an output file and check to make sure that it doesn't exist yet
% either
fileName = [p.root,filesep,'Subject Data',filesep,num2str(p.subNum), '_ColorK.mat'];
if p.subNum ~= 0 % "0" is considered the practice subject number -- if any other # except 0 don't allow over-writing of the file
    if exist(fileName)
        Screen('CloseAll');
        msgbox('File already exists!', 'modal')
        return;
    end
end
%----------------------------------------------------
% Get screen params, build the display
%----------------------------------------------------
commandwindow; % select the command win to avoid typing in open scripts
ListenChar(2); % don't print things in the command window

% set the random state to the random seed at the beginning of the experiment!!
prefs = getPreferences();  % function that grabs all of our preferences (at the bottom of this script)

% set up fixation point rect (b/c uses both prefs and win)
win.fixRect = [(win.centerX - prefs.fixationSize),(win.centerY - prefs.fixationSize), ...
    (win.centerX  + prefs.fixationSize), (win.centerY + prefs.fixationSize)];

win.colors = win.colors_9;
%--------------------------------------------------------
% Set up the keys on the keyboard we'll be using (unify so works on mac
% & PC)
%--------------------------------------------------------
while KbCheck; end;
KbName('UnifyKeyNames');   % This command switches keyboard mappings to the OSX naming scheme, regardless of computer.
% unify key names so we don't need to mess when switching from mac
% to pc ...
escape = KbName('ESCAPE');  % Mac == 'ESCAPE' % PC == 'esc'
prefs.changeKey = KbName('/?'); % on mac, 56 % 191 == / pc
prefs.nochangeKey = KbName('z'); % on mac, 29  % 90 == z
space = KbName('space');
%--------------------------------------------------------
% Preallocate some variable structures! :)
%--------------------------------------------------------
% Stimulus parameters:
stim.setSize = NaN(prefs.numTrials,prefs.numBlocks);
stim.change = NaN(prefs.numTrials,prefs.numBlocks);
% Response params
stim.response = NaN(prefs.numTrials,prefs.numBlocks);
stim.accuracy = NaN(prefs.numTrials,prefs.numBlocks);
stim.rt = NaN(prefs.numTrials,prefs.numBlocks);
% Location params
stim.probeLoc = NaN(prefs.numTrials,prefs.numBlocks,2); % 3rd dimension = (x,y) coordinates
stim.presentedColor = NaN(prefs.numTrials,prefs.numBlocks); % color originally presented at the probed location
stim.probeColor = NaN(prefs.numTrials,prefs.numBlocks); % color presented during the actual probe test
% If manually starting each trial, time how long it takes them. 
if p.manually_initiate 
    stim.time_to_initiate = NaN(prefs.numTrials,prefs.numBlocks);
end
% stim.itemLocs is a cell structure that will save the locations (centroids
% of all items. stim.itemLocs{trialNumber,blockNumber} = [xloc1 xloc2 ....; yloc1, yloc2 ...];
% stim.itemColors is a cell structure taht identifies the color of each
% item. stim.itemColors{trialNumber,blockNumber} = [col1,col2...]. To
% identify the RGB value, find the matching row in win.colors
%---------------------------------------------------
%  Put up instructions
instruct(win)
%---------------------------------------------------
% Begin Block loop
%---------------------------------------------------
for b = 1:prefs.numBlocks
    
    %%%% pick out the order of trials for this block, based on
    %%%% full Factorial Design
    prefs.order(:,b) = Shuffle(1:prefs.numTrials);
    stim.setSize(:,b) = prefs.setSizes(prefs.fullFactorialDesign(prefs.order(:,b), 1));
    stim.change(:,b) = prefs.change(prefs.fullFactorialDesign(prefs.order(:,b),2));
    
    %-------------------------------------------------------
    % Begin Trial Loop
    %-------------------------------------------------------
    for t = 1:prefs.numTrials
        %--------------------------------------------------------
        % Figure out the conditions for this  trial!
        %--------------------------------------------------------
        nItems = stim.setSize(t,b);
        change = stim.change(t,b);
        %------------------------------------------------------------------
        % Figure out the change stuff for this trial! 
        %------------------------------------------------------------------
        % compute and grab a random index into the color matrix
        colorIndex = randperm(size(win.colors,1));
        
        % calculate the stimulus locations for this trial!
        %%% centroid coordinates for all items!!
        [xPos,yPos] = getStimLocs(prefs,win,nItems);
        RECTS = [(xPos-prefs.stimSize/2);(yPos-prefs.stimSize/2);(xPos+prefs.stimSize/2);(yPos+prefs.stimSize/2)];
        
        %%%% save the locations of ALL items!!!!
        stim.itemLocs{t,b} = [xPos;yPos];
        stim.itemColors{t,b} = colorIndex(1:nItems);
        changeIndex = randperm(nItems);
        changeLocX = xPos(changeIndex(1)); changeLocY = yPos(changeIndex(1));
        
        sColor = colorIndex(changeIndex(1));  % sColor is the square-of-interest's color if NOT a change condition!
        dColors = Shuffle(colorIndex(~ismember(colorIndex,sColor))); % different colors from chosen square
        changeColor = dColors(1); % now we use the index to pick the change color!
        
        if change == 1
            testColor = changeColor;
        else
            testColor = sColor;
        end
        stim.probeColor(t,b) = testColor;
        stim.probeLoc(t,b,:) = [changeLocX,changeLocY];
        stim.presentedColor(t,b) = sColor; % actual color that was presented
        %--------------------------------------------------------
        % Now that we're done, actually run all the trial events! 
        %--------------------------------------------------------
       
        % manually initiate each trial if p.manual_initiate is set to 1 
        if p.manually_initiate 
            % Wait for a spacebar press to continue with next block
            start_initiate = GetSecs; 
            while 1
                [keyIsDown,secs,keyCode]=KbCheck;
                if keyIsDown
                    kp = find(keyCode);
                    if kp == space
                        end_initiate = GetSecs;
                        break;
                    end
                end
            end
            stim.time_to_initiate(t,b) = end_initiate-start_initiate; 
        end
        
        Screen('FillRect',win.onScreen,win.foreColor);      % Draw the foreground win
        Screen('FillOval',win.onScreen,win.black,win.fixRect);           % Draw the fixation point
        Screen('DrawingFinished',win.onScreen);                          % Tell ptb we're done drawing for the moment (makes subsequent flip command execute faster)
        Screen('Flip',win.onScreen);                                     % Flip all the stuff we just drew onto the main display
        
        % Wait the fixation interval
        WaitSecs(prefs.ITI); % For better timing with EEG, use with the 'UntilTime' option with the WaitSecs function. Not really necessary for behavior tasks.
        
        % Draw squares on the main win
        Screen('FillRect',win.onScreen,win.foreColor);            % Draw the background win (not just in foreground, or taskbar will show up!!)
        Screen('FillOval',win.onScreen,win.black,win.fixRect);           % Draw the fixation point
        Screen('FillRect',win.onScreen,win.colors(colorIndex(1:nItems),:)',RECTS);
        Screen('DrawingFinished',win.onScreen);
        Screen('Flip',win.onScreen);
        
        % Wait the sample duration
        WaitSecs(prefs.stimulusDuration);
        
        % draw blank screen
        Screen('FillRect',win.onScreen,win.foreColor);
        Screen('FillOval',win.onScreen,win.black,win.fixRect);           % Draw the fixation point
        Screen('DrawingFinished',win.onScreen);
        Screen('Flip',win.onScreen);
        
        % wait the ISI
        WaitSecs(prefs.retentionInterval); % stimulus Dur + retention, since not a memory task ...
        
        % Draw a new square on the screen, with the color value determined
        % by whether it's a change trial or not
        Screen('FillRect',win.onScreen,win.foreColor);
        Screen('FillOval',win.onScreen,win.black,win.fixRect);           % Draw the fixation point
        Screen('FillRect',win.onScreen,win.colors(testColor,:),[(changeLocX-prefs.stimSize/2),(changeLocY-prefs.stimSize/2),(changeLocX+prefs.stimSize/2),(changeLocY+prefs.stimSize/2)]);
        Screen('DrawingFinished',win.onScreen);
        Screen('Flip',win.onScreen);
        
        % Wait for a response
        rtStart = GetSecs;
        
        % use a while loop for the response so that we can escape out and
        % save all data if we press escape! 
        while 1
            [keyIsDown,secs,keyCode]=KbCheck;
            if keyIsDown
                if keyCode(escape)                              % if escape is pressed, bail out
                    ListenChar(0);
                    % save data file if we abort the session
                    p.date_time_end = clock; % record time and date of the end of the sesssion
                    save(fileName,'p','stim','prefs','win');
                    Screen('CloseAll');
                    return;
                end
                kp = find(keyCode);
                kp = kp(1); % in case they press 2 buttons at the EXACT same time!!! Not that this happened at the most aggravating possible point in some previous experiment sessions, but yep. it did.
                if kp== prefs.changeKey || kp== prefs.nochangeKey
                    stim.response(t,b)=kp;
                    rtEnd = GetSecs;
                    break
                end
            end
        end
        
        % Blank the screen after the response 
        Screen('FillRect',win.onScreen,win.foreColor);            % Draw the foreground win
        Screen('FillOval',win.onScreen,win.black,win.fixRect);           % Draw the fixation point
        Screen('DrawingFinished',win.onScreen);
        Screen('Flip',win.onScreen);
        
        stim.rt(t,b) = rtEnd-rtStart;
        
        % Check accuracy
        if change == 1
            if stim.response(t,b) == prefs.changeKey
                stim.accuracy(t,b)=1;
            else
                stim.accuracy(t,b)=0;
            end
        else
            if stim.response(t,b) == prefs.nochangeKey
                stim.accuracy(t,b)=1;
            else
                stim.accuracy(t,b)=0;
            end
        end

    end    % end of trial loop
    
    % save data file at the end of each block
    save(fileName,'p','stim','prefs','win');
    
    % tell subjects that they've finished the current block / the experiment
    if b<prefs.numBlocks
        tic
        while toc < prefs.breakLength*60
            tocInd = round(toc);
            Screen('FillRect',win.onScreen,win.foreColor);            % Draw the foreground win
            Screen('FillOval',win.onScreen,win.black,win.fixRect);           % Draw the fixation point
            Screen(win.onScreen, 'DrawText', 'Take a break.', win.centerX-110, win.centerY-75, [255 255 255]);
            Screen(win.onScreen, 'DrawText',['Time Remaining: ',char(num2str((prefs.breakLength*60)-tocInd))], win.centerX-110, win.centerY-40, [255 0 0 ]);
            Screen(win.onScreen, 'DrawText', ['Block ',num2str(b),' of ',num2str(prefs.numBlocks),' completed.'], win.centerX-110, win.centerY+20, [255 255 255]);
            Screen('Flip', win.onScreen);
        end
    end
    
    if b == prefs.numBlocks
        
        Screen('TextSize',win.onScreen,24);
        Screen('TextFont',win.onScreen,'Arial');
        Screen(win.onScreen, 'DrawText', 'Finished! Please see the experimenter.', win.centerX-250, win.centerY-75, [255 255 255]);
        Screen('Flip', win.onScreen);
        
        % Wait for a spacebar press to continue with next block
        while 1
            [keyIsDown,secs,keyCode]=KbCheck;
            if keyIsDown
                kp = find(keyCode);
                if kp == space
                    break;
                end
            end
        end
        
    end
end    % end of the block loop

p.date_time_end = clock; % record time and date of the end of the sesssion
% save data file at the end of the whole session
save(fileName,'p','stim','prefs','win');
%-------------------------------------------------------------------------
% Close psychtoolbox window and clear it all out!
%-------------------------------------------------------------------------
sca; % close psychtoolbox screen
ListenChar(0); % allow typing again
if p.manually_hide_taskbar
    ShowHideWinTaskbarMex(1);
end
close all;
end % End of the main "run experiment" function

%-------------------------------------------------------------------------
%  ADDITIONAL FUNCTIONS EMBEDDED IN SCRIPT !!
%-------------------------------------------------------------------------
function instruct(win)

InstructImage = imread([pwd,'/Instructions_CD'],'png','BackgroundColor',[win.gray/255,win.gray/255,win.gray/255]); % load instructusion picture, make the clear background the same color as our window
textOffset = 200; % There's probably a smarter way to center this, but just offset a bit for now
textSize = 15;

sizeInstruct = size(InstructImage);
rectInstruct = [0 0 sizeInstruct(2) sizeInstruct(1)];
rectTestCoor = [win.centerX,win.centerY-(sizeInstruct(1)*.2)];

InstructText = ['Remember the colors! \n'...
    '1. Wait for the squares to appear.\n'...
    '2. See the squares \n'...
    '3. Remember the squares \n'...
    '4. Same or different? \n'...
    '  \n'...
    'If the color is the same, press "z".\n'...
    'If the color is different, press "/". \n'...
    'Press spacebar to begin'];

% Show image again, but with explanatory text
Screen('FillRect', win.onScreen, win.gray);
Screen('TextSize', win.onScreen, win.fontsize);
Screen('PutImage',win.onScreen,InstructImage,CenterRectOnPoint(rectInstruct,rectTestCoor(1),rectTestCoor(2)));
Screen('TextSize', win.onScreen, textSize); % 24 = number pixels
DrawFormattedText(win.onScreen, InstructText, win.centerX-textOffset,win.centerY+(sizeInstruct(1)*.35),win.white);
Screen('Flip', win.onScreen);

% Wait for a spacebar press to continue with next block
while KbCheck; end;
KbName('UnifyKeyNames');   % This command switches keyboard mappings to the OSX naming scheme, regardless of computer.
space = KbName('space');
while 1
    [keyIsDown,secs,keyCode]=KbCheck;
    if keyIsDown
        kp = find(keyCode);
        if kp == space
            break;
        end
    end
end
end
%-------------------------------------------------------------------------
function [xPos,yPos] = getStimLocs(prefs,win,nItems)
% segment the inner window into four quadrants - for xCoords, 1st
% row = positions in left half of display, 2nd row = right half.
% For yCoords - 1st row = top half, 2nd row = bottom half
xCoords = [linspace((win.foreRect(1)+prefs.stimSize),win.centerX-prefs.stimSize,300); linspace(win.centerX+prefs.stimSize,(win.foreRect(3)-prefs.stimSize),300)];
yCoords = [linspace((win.foreRect(2)+prefs.stimSize),win.centerY-prefs.stimSize,300); linspace(win.centerY+prefs.stimSize,(win.foreRect(4)-prefs.stimSize),300)];
xLocInd = randperm(size(xCoords,2)); yLocInd = randperm(size(yCoords,2));

% Pick x,y coords for drawing stimuli on this trial, making sure
% that all stimuli are seperated by >= prefs.minDist
if nItems ==1
    xPos = [xCoords(randi(2),xLocInd(1))];  % pick randomly from first and second x rows (L/R halves)
    yPos = [yCoords(randi(2),yLocInd(1))];  % pick randomly from first and second y rows (Top/Bottom).
elseif nItems ==2
    randomPosition = randi(2);
    if randomPosition == 1
        xPos = [xCoords(1,xLocInd(1)),xCoords(2,xLocInd(2))]; % pick one left and one right item
        yPos = [yCoords(randi(2),yLocInd(1)),yCoords(randi(2),yLocInd(2))]; % pick randomly, top or bottom
    else
        xPos = [xCoords(randi(2),xLocInd(1)),xCoords(randi(2),xLocInd(2))]; % pick randomly, left or right!
        yPos = [yCoords(1,yLocInd(1)),yCoords(2,yLocInd(2))]; % pick one top, one bottom!
    end
elseif nItems ==3
    xPos = [xCoords(1,xLocInd(1)),xCoords(2,xLocInd(2)),xCoords(1,xLocInd(3)),xCoords(2,xLocInd(4))]; % one L one R
    yPos = [yCoords(1,yLocInd(1)),yCoords(1,yLocInd(2)),yCoords(2,yLocInd(3)),yCoords(2,yLocInd(4))]; % one top one bottom for e/ L/R
    % let's use the same scheme as 4 items, but randomly leave one
    % out!
    randomOrder = randperm(4);
    xPos = xPos(randomOrder(1:3));
    yPos = yPos(randomOrder(1:3));
elseif nItems ==4
    xPos = [xCoords(1,xLocInd(1)),xCoords(2,xLocInd(2)),xCoords(1,xLocInd(3)),xCoords(2,xLocInd(4))]; % one L one R
    yPos = [yCoords(1,yLocInd(1)),yCoords(1,yLocInd(2)),yCoords(2,yLocInd(3)),yCoords(2,yLocInd(4))]; % one top one bottom for e/ L/R
elseif nItems ==5
    randomPosition = randi(2); % pick one of two quadrants to stick the second item
    while 1
        if randomPosition == 1
            xLocInd = Shuffle(xLocInd); yLocInd = Shuffle(yLocInd);
            xPos = [xCoords(1,xLocInd(1)),xCoords(2,xLocInd(2)),xCoords(1,xLocInd(3)),xCoords(2,xLocInd(4)),xCoords(1,xLocInd(5))];
            yPos = [yCoords(1,yLocInd(1)),yCoords(1,yLocInd(2)),yCoords(2,yLocInd(3)),yCoords(2,yLocInd(4)),yCoords(1,yLocInd(5))];
            % make sure that w/in quadrant points satisfy the minimum
            % distance requirement
            if sqrt(abs(xPos(1)-xPos(5))^2+abs(yPos(1)-yPos(5))^2)>prefs.minDist
                %             if sqrt((xPos(2)-xPos(6))^2+(yPos(2)-yPos(6))^2)>prefs.minDist
                break;
            end
        elseif randomPosition == 2
            xLocInd = Shuffle(xLocInd); yLocInd = Shuffle(yLocInd);
            xPos = [xCoords(1,xLocInd(1)),xCoords(2,xLocInd(2)),xCoords(1,xLocInd(3)),xCoords(2,xLocInd(4)),xCoords(2,xLocInd(5))];
            yPos = [yCoords(1,yLocInd(1)),yCoords(1,yLocInd(2)),yCoords(2,yLocInd(3)),yCoords(2,yLocInd(4)),yCoords(1,yLocInd(5))];
            % make sure that w/in quadrant points satisfy the minimum
            % distance requirement
            if sqrt((xPos(2)-xPos(5))^2+(yPos(2)-yPos(5))^2)>prefs.minDist
                break;
            end
        end
    end
elseif nItems ==6
    randomPosition = randi(2); % put extra squares in top or bottom half;
    while 1
        if randomPosition == 1
            xLocInd = Shuffle(xLocInd); yLocInd = Shuffle(yLocInd);
            xPos = [xCoords(1,xLocInd(1)),xCoords(2,xLocInd(2)),xCoords(1,xLocInd(3)),xCoords(2,xLocInd(4)),xCoords(1,xLocInd(5)),xCoords(2,xLocInd(6))];
            yPos = [yCoords(1,yLocInd(1)),yCoords(1,yLocInd(2)),yCoords(2,yLocInd(3)),yCoords(2,yLocInd(4)),yCoords(1,yLocInd(5)),yCoords(1,yLocInd(6))];
            % make sure that w/in quadrant points satisfy the minimum
            % distance requirement
            if sqrt(abs(xPos(1)-xPos(5))^2+abs(yPos(1)-yPos(5))^2)>prefs.minDist
                if sqrt((xPos(2)-xPos(6))^2+(yPos(2)-yPos(6))^2)>prefs.minDist
                    break;
                end
            end
        else
            xLocInd = Shuffle(xLocInd); yLocInd = Shuffle(yLocInd);
            xPos = [xCoords(1,xLocInd(1)),xCoords(2,xLocInd(2)),xCoords(1,xLocInd(3)),xCoords(2,xLocInd(4)),xCoords(1,xLocInd(5)),xCoords(2,xLocInd(6))];
            yPos = [yCoords(1,yLocInd(1)),yCoords(1,yLocInd(2)),yCoords(2,yLocInd(3)),yCoords(2,yLocInd(4)),yCoords(2,yLocInd(5)),yCoords(2,yLocInd(6))];
            % make sure that w/in quadrant points satisfy the minimum
            % distance requirement
            if sqrt(abs(xPos(3)-xPos(5))^2+abs(yPos(3)-yPos(5))^2)>prefs.minDist
                if sqrt((xPos(4)-xPos(6))^2+(yPos(4)-yPos(6))^2)>prefs.minDist
                    break;
                end
            end
        end
    end
elseif nItems == 8
    while 1
        xLocInd = Shuffle(xLocInd); yLocInd = Shuffle(yLocInd);
        xPos = [xCoords(1,xLocInd(1)),xCoords(2,xLocInd(2)),xCoords(1,xLocInd(3)),xCoords(2,xLocInd(4)),xCoords(1,xLocInd(5)),xCoords(2,xLocInd(6)),xCoords(1,xLocInd(7)),xCoords(2,xLocInd(8))];
        yPos = [yCoords(1,yLocInd(1)),yCoords(1,yLocInd(2)),yCoords(2,yLocInd(3)),yCoords(2,yLocInd(4)),yCoords(1,yLocInd(5)),yCoords(1,yLocInd(6)),yCoords(2,yLocInd(7)),yCoords(2,yLocInd(8))];
        % make sure that w/in quadrant points satisfy the minimum
        % distance requirement
        if sqrt(abs(xPos(1)-xPos(5))^2+abs(yPos(1)-yPos(5))^2)>prefs.minDist
            if sqrt((xPos(2)-xPos(6))^2+(yPos(2)-yPos(6))^2)>prefs.minDist
                if sqrt((xPos(3)-xPos(7))^2+(yPos(3)-yPos(7))^2)>prefs.minDist
                    if sqrt((xPos(4)-xPos(8))^2+(yPos(4)-yPos(8))^2)>prefs.minDist
                        break;
                    end
                end
            end
        end
    end
end

end
%-------------------------------------------------------------------------
%  OPEN THE MAIN EXPERIMENT WINDOW!
%-------------------------------------------------------------------------
function win = openWindow(p) % open up the window!

win.screenNumber = max(Screen('Screens')); % may need to change for multiscreen displays!! 

if ~ispc % On mac's, it won't open a psychtoolbox window if it can't detect the refresh rate!!! Skip sync tests to avoid this.
    Screen('Preference','SkipSyncTests',1);
end

%-------------------------------------------------------------------------
%  SMALLER DEBUGGING WINDOW: p.windowed = 0; FULL SCREEN: p.windowed == 1
%-------------------------------------------------------------------------
if p.windowed % manually pick a size to show on your monitor
    x_size=  1024; y_size = 768;
    [win.onScreen,rect] = Screen('OpenWindow', win.screenNumber, [128 128 128],[0 0 x_size y_size],[],[],[]);
    win.screenX = x_size;
    win.screenY = y_size;
    win.screenRect = [0 0 x_size y_size];
    win.centerX = (x_size)/2; % center of screen in X direction
    win.centerY = (y_size)/2; % center of screen in Y direction
    win.centerXL = floor(mean([0 win.centerX])); % center of left half of screen in X direction
    win.centerXR = floor(mean([win.centerX win.screenX])); % center of right half of screen in X direction
    % size of bounding box for squares to appear in
    win.foreRect = [0 0 700 700]; %%% change me!
    win.foreRect = CenterRect(win.foreRect,win.screenRect);
else
    [win.onScreen rect] = Screen('OpenWindow', win.screenNumber, [128 128 128],[],[],[],[]);
    [win.screenX, win.screenY] = Screen('WindowSize', win.onScreen); % check resolution
    win.screenRect  = [0 0 win.screenX win.screenY]; % screen rect
    win.centerX = win.screenX * 0.5; % center of screen in X direction
    win.centerY = win.screenY * 0.5; % center of screen in Y direction
    win.centerXL = floor(mean([0 win.centerX])); % center of left half of screen in X direction
    win.centerXR = floor(mean([win.centerX win.screenX])); % center of right half of screen in X direction
    % size of bounding box for squares to appear in
    win.foreRect = [0 0 700 700];
    win.foreRect = CenterRect(win.foreRect,win.screenRect);
    
    HideCursor; % hide the cursor since we're not debugging
end

Screen('BlendFunction', win.onScreen, 'GL_SRC_ALPHA', 'GL_ONE_MINUS_SRC_ALPHA');

% basic drawing and screen variables
win.black    = BlackIndex(win.onScreen);
win.white    = WhiteIndex(win.onScreen);
win.gray     = mean([win.black win.white]);

win.backColor = win.gray;
win.foreColor = win.gray;

%%% 9 colors mat
win.colors_9 = [255 0 0; ... % red
    0 255 0; ...% green
    0 0 255; ...% blue
    255 255 0; ... % yellow
    255 0 255; ... % magenta
    0 255 255; ... % cyan
    255 255 255; ... % white
    1 1 1; ... %black
    255 128 0]; % orange!

win.fontsize = 24;

% make a dummy call to GetSecs to load the .dll before we need it
dummy = GetSecs; clear dummy;
end
%-------------------------------------------------------------------------
%  CHANGE PREFERENCES!
%-------------------------------------------------------------------------
function prefs = getPreferences
%%%% Design conditions
prefs.numBlocks = 4;
prefs.nTrialsPerCondition = 8;
prefs.setSizes = [4,6,8]; 
prefs.change = [0,1]; % 0 = no change, 1 = change!

%%%%% timing
prefs.retentionInterval =  1.000;  % Could randomize with jitter if you want
prefs.stimulusDuration = .250;
prefs.ITI = 1.000;
prefs.breakLength = .5;

%%%%% stimulus size & positions
prefs.stimSize = 60;
prefs.minDist = prefs.stimSize*1.5;
prefs.fixationSize = 6;

%%%%% full factorial design matrix (randomize later)
prefs.fullFactorialDesign = fullfact([length(prefs.setSizes), ...
    length(prefs.change), ...
    prefs.nTrialsPerCondition]);

%%%%% total number of trials within each fully-balanced block.
prefs.numTrials = size(prefs.fullFactorialDesign,1);
end



