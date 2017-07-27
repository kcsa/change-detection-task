# Read me for Color Change Detection Task
written by Kirsten Adam, last updated 27 July 2017
## Required software
This code runs in MATLAB using Psychtoolbox (<http://psychtoolbox.org>).

## Setting up the code
Place the experiment script and the instructions file in a folder, and make sure this folder is on Matlab's path. Right now, the script is set up to create a folder called `Subject Data` within the current directory and save the data there. If you want the data to be saved elsewhere, you will need to update the experiment's main directory, `p.root`. 
 
## Common changes that need to be made 
* Many of the key settings are in the sub-function `getPreferences()`. For example, you might change the number of blocks, set sizes, or number of trials per block. Set Size and Change (0 or 1) are fully counterbalanced within each block using the matlab function `fullfact`. To calculate the number of trials per block, multiple the length of `prefs.setSizes`, `prefs.change`, and the desired number of repetitions, `prefs.nTrialsPerCondition`. To add a new condition to be counterbalanced within block, you can easily do so by adding it to `prefs.fullFactorialDesign`. 
* For debugging mode, you can create a smaller window by setting `p.windowed` to 1. For experiment mode, set `p.windowed` to 0. You can manually change the size of the debugging window with the variables `x_size` and `y_size`. 
* You might want to adjust the size of the stimuli & the total area that stimuli can appear in depending on your monitor size & viewing distance. Stimulus size is controlled with `prefs.stimSize`. Area that stimuli can appaer in is controlled with `win.foreRect = [ 0 0 xLength yLength]`. This bounding box is then centered around fixation.
 