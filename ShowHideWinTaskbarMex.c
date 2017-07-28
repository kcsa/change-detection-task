



<!DOCTYPE html>
<html>
<head>
 <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" >
 <meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1" >
 
 <meta name="ROBOTS" content="NOARCHIVE">
 
 <link rel="icon" type="image/vnd.microsoft.icon" href="http://www.gstatic.com/codesite/ph/images/phosting.ico">
 
 
 <script type="text/javascript">
 
 (function(){var a=function(b){this.t={};this.tick=function(b,c,d){c=void 0!=d?d:(new Date).getTime();this.t[b]=c};this.tick("start",null,b)},e=new a;window.jstiming={Timer:a,load:e};try{var f=null;window.chrome&&window.chrome.csi&&(f=Math.floor(window.chrome.csi().pageT));null==f&&window.gtbExternal&&(f=window.gtbExternal.pageT());null==f&&window.external&&(f=window.external.pageT);f&&(window.jstiming.pt=f)}catch(g){};})();

 
 
 
 
 var codesite_token = null;
 
 
 var CS_env = {"profileUrl":null,"token":null,"assetHostPath":"http://www.gstatic.com/codesite/ph","domainName":null,"assetVersionPath":"http://www.gstatic.com/codesite/ph/17134919371905794448","projectHomeUrl":"/p/psychtoolbox-3","relativeBaseUrl":"","projectName":"psychtoolbox-3","loggedInUserEmail":null};
 var _gaq = _gaq || [];
 _gaq.push(
 ['siteTracker._setAccount', 'UA-18071-1'],
 ['siteTracker._trackPageview']);
 
 _gaq.push(
 ['projectTracker._setAccount', 'UA-6031251-3'],
 ['projectTracker._trackPageview']);
 
 (function() {
 var ga = document.createElement('script'); ga.type = 'text/javascript'; ga.async = true;
 ga.src = ('https:' == document.location.protocol ? 'https://ssl' : 'http://www') + '.google-analytics.com/ga.js';
 (document.getElementsByTagName('head')[0] || document.getElementsByTagName('body')[0]).appendChild(ga);
 })();
 
 </script>
 
 
 <title>ShowHideWinTaskbarMex.c - 
 psychtoolbox-3 -
 
 
 Psychophysics Toolbox Version 3 is a free set of Matlab and GNU/Octave functions for psychophysics and neuroscience research. - Google Project Hosting
 </title>
 <link type="text/css" rel="stylesheet" href="http://www.gstatic.com/codesite/ph/17134919371905794448/css/core.css">
 
 <link type="text/css" rel="stylesheet" href="http://www.gstatic.com/codesite/ph/17134919371905794448/css/ph_detail.css" >
 
 
 <link type="text/css" rel="stylesheet" href="http://www.gstatic.com/codesite/ph/17134919371905794448/css/d_sb.css" >
 
 
 
<!--[if IE]>
 <link type="text/css" rel="stylesheet" href="http://www.gstatic.com/codesite/ph/17134919371905794448/css/d_ie.css" >
<![endif]-->
 <style type="text/css">
 .menuIcon.off { background: no-repeat url(http://www.gstatic.com/codesite/ph/images/dropdown_sprite.gif) 0 -42px }
 .menuIcon.on { background: no-repeat url(http://www.gstatic.com/codesite/ph/images/dropdown_sprite.gif) 0 -28px }
 .menuIcon.down { background: no-repeat url(http://www.gstatic.com/codesite/ph/images/dropdown_sprite.gif) 0 0; }
 
 
 
  tr.inline_comment {
 background: #fff;
 vertical-align: top;
 }
 div.draft, div.published {
 padding: .3em;
 border: 1px solid #999; 
 margin-bottom: .1em;
 font-family: arial, sans-serif;
 max-width: 60em;
 }
 div.draft {
 background: #ffa;
 } 
 div.published {
 background: #e5ecf9;
 }
 div.published .body, div.draft .body {
 padding: .5em .1em .1em .1em;
 max-width: 60em;
 white-space: pre-wrap;
 white-space: -moz-pre-wrap;
 white-space: -pre-wrap;
 white-space: -o-pre-wrap;
 word-wrap: break-word;
 font-size: 1em;
 }
 div.draft .actions {
 margin-left: 1em;
 font-size: 90%;
 }
 div.draft form {
 padding: .5em .5em .5em 0;
 }
 div.draft textarea, div.published textarea {
 width: 95%;
 height: 10em;
 font-family: arial, sans-serif;
 margin-bottom: .5em;
 }

 
 .nocursor, .nocursor td, .cursor_hidden, .cursor_hidden td {
 background-color: white;
 height: 2px;
 }
 .cursor, .cursor td {
 background-color: darkblue;
 height: 2px;
 display: '';
 }
 
 
.list {
 border: 1px solid white;
 border-bottom: 0;
}

 
 </style>
</head>
<body class="t4">
<script type="text/javascript">
 window.___gcfg = {lang: 'en'};
 (function() 
 {var po = document.createElement("script");
 po.type = "text/javascript"; po.async = true;po.src = "https://apis.google.com/js/plusone.js";
 var s = document.getElementsByTagName("script")[0];
 s.parentNode.insertBefore(po, s);
 })();
</script>
<div class="headbg">

 <div id="gaia">
 

 <span>
 
 
 <a href="#" id="projects-dropdown" onclick="return false;"><u>My favorites</u> <small>&#9660;</small></a>
 | <a href="https://www.google.com/accounts/ServiceLogin?service=code&amp;ltmpl=phosting&amp;continue=http%3A%2F%2Fcode.google.com%2Fp%2Fpsychtoolbox-3%2Fsource%2Fbrowse%2Ftrunk%2FPsychtoolbox%2FPsychContributed%2FShowHideWinTaskbarMex.c%3Fr%3D2420&amp;followup=http%3A%2F%2Fcode.google.com%2Fp%2Fpsychtoolbox-3%2Fsource%2Fbrowse%2Ftrunk%2FPsychtoolbox%2FPsychContributed%2FShowHideWinTaskbarMex.c%3Fr%3D2420" onclick="_CS_click('/gb/ph/signin');"><u>Sign in</u></a>
 
 </span>

 </div>

 <div class="gbh" style="left: 0pt;"></div>
 <div class="gbh" style="right: 0pt;"></div>
 
 
 <div style="height: 1px"></div>
<!--[if lte IE 7]>
<div style="text-align:center;">
Your version of Internet Explorer is not supported. Try a browser that
contributes to open source, such as <a href="http://www.firefox.com">Firefox</a>,
<a href="http://www.google.com/chrome">Google Chrome</a>, or
<a href="http://code.google.com/chrome/chromeframe/">Google Chrome Frame</a>.
</div>
<![endif]-->



 <table style="padding:0px; margin: 0px 0px 10px 0px; width:100%" cellpadding="0" cellspacing="0"
 itemscope itemtype="http://schema.org/CreativeWork">
 <tr style="height: 58px;">
 
 
 
 <td id="plogo">
 <link itemprop="url" href="/p/psychtoolbox-3">
 <a href="/p/psychtoolbox-3/">
 
 
 <img src="/p/psychtoolbox-3/logo?cct=1334937400"
 alt="Logo" itemprop="image">
 
 </a>
 </td>
 
 <td style="padding-left: 0.5em">
 
 <div id="pname">
 <a href="/p/psychtoolbox-3/"><span itemprop="name">psychtoolbox-3</span></a>
 </div>
 
 <div id="psum">
 <a id="project_summary_link"
 href="/p/psychtoolbox-3/"><span itemprop="description">Psychophysics Toolbox Version 3 is a free set of Matlab and GNU/Octave functions for psychophysics and neuroscience research.</span></a>
 
 </div>
 
 
 </td>
 <td style="white-space:nowrap;text-align:right; vertical-align:bottom;">
 
 <form action="/hosting/search">
 <input size="30" name="q" value="" type="text">
 
 <input type="submit" name="projectsearch" value="Search projects" >
 </form>
 
 </tr>
 </table>

</div>

 
<div id="mt" class="gtb"> 
 <a href="/p/psychtoolbox-3/" class="tab ">Project&nbsp;Home</a>
 
 
 
 
 <a href="/p/psychtoolbox-3/downloads/list" class="tab ">Downloads</a>
 
 
 
 
 
 
 
 
 
 <a href="/p/psychtoolbox-3/source/checkout"
 class="tab active">Source</a>
 
 
 
 
 
 
 
 
 
 
 <div class=gtbc></div>
</div>
<table cellspacing="0" cellpadding="0" width="100%" align="center" border="0" class="st">
 <tr>
 
 
 
 
 
 
 
 <td class="subt">
 <div class="st2">
 <div class="isf">
 
 


 <span class="inst1"><a href="/p/psychtoolbox-3/source/checkout">Checkout</a></span> &nbsp;
 <span class="inst2"><a href="/p/psychtoolbox-3/source/browse/">Browse</a></span> &nbsp;
 <span class="inst3"><a href="/p/psychtoolbox-3/source/list">Changes</a></span> &nbsp;
 
 &nbsp;
 
 
 <form action="/p/psychtoolbox-3/source/search" method="get" style="display:inline"
 onsubmit="document.getElementById('codesearchq').value = document.getElementById('origq').value">
 <input type="hidden" name="q" id="codesearchq" value="">
 <input type="text" maxlength="2048" size="38" id="origq" name="origq" value="" title="Google Code Search" style="font-size:92%">&nbsp;<input type="submit" value="Search Trunk" name="btnG" style="font-size:92%">
 
 
 </form>
 <script type="text/javascript">
 
 function codesearchQuery(form) {
 var query = document.getElementById('q').value;
 if (query) { form.action += '%20' + query; }
 }
 </script>
 </div>
</div>

 </td>
 
 
 
 <td align="right" valign="top" class="bevel-right"></td>
 </tr>
</table>


<script type="text/javascript">
 var cancelBubble = false;
 function _go(url) { document.location = url; }
</script>
<div id="maincol"
 
>

 




<div class="expand">
<div id="colcontrol">
<style type="text/css">
 #file_flipper { white-space: nowrap; padding-right: 2em; }
 #file_flipper.hidden { display: none; }
 #file_flipper .pagelink { color: #0000CC; text-decoration: underline; }
 #file_flipper #visiblefiles { padding-left: 0.5em; padding-right: 0.5em; }
</style>
<table id="nav_and_rev" class="list"
 cellpadding="0" cellspacing="0" width="100%">
 <tr>
 
 <td nowrap="nowrap" class="src_crumbs src_nav" width="33%">
 <strong class="src_nav">Source path:&nbsp;</strong>
 <span id="crumb_root">
 
 <a href="/p/psychtoolbox-3/source/browse/?r=2420">svn</a>/&nbsp;</span>
 <span id="crumb_links" class="ifClosed"><a href="/p/psychtoolbox-3/source/browse/trunk/?r=2420">trunk</a><span class="sp">/&nbsp;</span><a href="/p/psychtoolbox-3/source/browse/trunk/Psychtoolbox/?r=2420">Psychtoolbox</a><span class="sp">/&nbsp;</span><a href="/p/psychtoolbox-3/source/browse/trunk/Psychtoolbox/PsychContributed/?r=2420">PsychContributed</a><span class="sp">/&nbsp;</span>ShowHideWinTaskbarMex.c</span>
 
 


 </td>
 
 
 <td nowrap="nowrap" width="33%" align="right">
 <table cellpadding="0" cellspacing="0" style="font-size: 100%"><tr>
 
 
 <td class="flipper"><b>r2420</b></td>
 
 </tr></table>
 </td> 
 </tr>
</table>

<div class="fc">
 
 
 
<style type="text/css">
.undermouse span {
 background-image: url(http://www.gstatic.com/codesite/ph/images/comments.gif); }
</style>
<table class="opened" id="review_comment_area"
><tr>
<td id="nums">
<pre><table width="100%"><tr class="nocursor"><td></td></tr></table></pre>
<pre><table width="100%" id="nums_table_0"><tr id="gr_svn2420_1"

><td id="1"><a href="#1">1</a></td></tr
><tr id="gr_svn2420_2"

><td id="2"><a href="#2">2</a></td></tr
><tr id="gr_svn2420_3"

><td id="3"><a href="#3">3</a></td></tr
><tr id="gr_svn2420_4"

><td id="4"><a href="#4">4</a></td></tr
><tr id="gr_svn2420_5"

><td id="5"><a href="#5">5</a></td></tr
><tr id="gr_svn2420_6"

><td id="6"><a href="#6">6</a></td></tr
><tr id="gr_svn2420_7"

><td id="7"><a href="#7">7</a></td></tr
><tr id="gr_svn2420_8"

><td id="8"><a href="#8">8</a></td></tr
><tr id="gr_svn2420_9"

><td id="9"><a href="#9">9</a></td></tr
><tr id="gr_svn2420_10"

><td id="10"><a href="#10">10</a></td></tr
><tr id="gr_svn2420_11"

><td id="11"><a href="#11">11</a></td></tr
><tr id="gr_svn2420_12"

><td id="12"><a href="#12">12</a></td></tr
><tr id="gr_svn2420_13"

><td id="13"><a href="#13">13</a></td></tr
><tr id="gr_svn2420_14"

><td id="14"><a href="#14">14</a></td></tr
><tr id="gr_svn2420_15"

><td id="15"><a href="#15">15</a></td></tr
><tr id="gr_svn2420_16"

><td id="16"><a href="#16">16</a></td></tr
><tr id="gr_svn2420_17"

><td id="17"><a href="#17">17</a></td></tr
><tr id="gr_svn2420_18"

><td id="18"><a href="#18">18</a></td></tr
><tr id="gr_svn2420_19"

><td id="19"><a href="#19">19</a></td></tr
><tr id="gr_svn2420_20"

><td id="20"><a href="#20">20</a></td></tr
><tr id="gr_svn2420_21"

><td id="21"><a href="#21">21</a></td></tr
><tr id="gr_svn2420_22"

><td id="22"><a href="#22">22</a></td></tr
><tr id="gr_svn2420_23"

><td id="23"><a href="#23">23</a></td></tr
><tr id="gr_svn2420_24"

><td id="24"><a href="#24">24</a></td></tr
><tr id="gr_svn2420_25"

><td id="25"><a href="#25">25</a></td></tr
><tr id="gr_svn2420_26"

><td id="26"><a href="#26">26</a></td></tr
><tr id="gr_svn2420_27"

><td id="27"><a href="#27">27</a></td></tr
><tr id="gr_svn2420_28"

><td id="28"><a href="#28">28</a></td></tr
><tr id="gr_svn2420_29"

><td id="29"><a href="#29">29</a></td></tr
><tr id="gr_svn2420_30"

><td id="30"><a href="#30">30</a></td></tr
><tr id="gr_svn2420_31"

><td id="31"><a href="#31">31</a></td></tr
><tr id="gr_svn2420_32"

><td id="32"><a href="#32">32</a></td></tr
><tr id="gr_svn2420_33"

><td id="33"><a href="#33">33</a></td></tr
><tr id="gr_svn2420_34"

><td id="34"><a href="#34">34</a></td></tr
><tr id="gr_svn2420_35"

><td id="35"><a href="#35">35</a></td></tr
><tr id="gr_svn2420_36"

><td id="36"><a href="#36">36</a></td></tr
><tr id="gr_svn2420_37"

><td id="37"><a href="#37">37</a></td></tr
><tr id="gr_svn2420_38"

><td id="38"><a href="#38">38</a></td></tr
><tr id="gr_svn2420_39"

><td id="39"><a href="#39">39</a></td></tr
><tr id="gr_svn2420_40"

><td id="40"><a href="#40">40</a></td></tr
><tr id="gr_svn2420_41"

><td id="41"><a href="#41">41</a></td></tr
><tr id="gr_svn2420_42"

><td id="42"><a href="#42">42</a></td></tr
><tr id="gr_svn2420_43"

><td id="43"><a href="#43">43</a></td></tr
><tr id="gr_svn2420_44"

><td id="44"><a href="#44">44</a></td></tr
><tr id="gr_svn2420_45"

><td id="45"><a href="#45">45</a></td></tr
><tr id="gr_svn2420_46"

><td id="46"><a href="#46">46</a></td></tr
><tr id="gr_svn2420_47"

><td id="47"><a href="#47">47</a></td></tr
><tr id="gr_svn2420_48"

><td id="48"><a href="#48">48</a></td></tr
></table></pre>
<pre><table width="100%"><tr class="nocursor"><td></td></tr></table></pre>
</td>
<td id="lines">
<pre><table width="100%"><tr class="cursor_stop cursor_hidden"><td></td></tr></table></pre>
<pre class="prettyprint lang-c"><table id="src_table_0"><tr
id=sl_svn2420_1

><td class="source">/*------------------------------------------------------------------------------<br></td></tr
><tr
id=sl_svn2420_2

><td class="source"> * ShowHideWinTaskbarMex.c -- A simple Matlab MEX file for showing/hiding the<br></td></tr
><tr
id=sl_svn2420_3

><td class="source"> * taskbar on Microsoft Windows.<br></td></tr
><tr
id=sl_svn2420_4

><td class="source"> *<br></td></tr
><tr
id=sl_svn2420_5

><td class="source"> * Usage:<br></td></tr
><tr
id=sl_svn2420_6

><td class="source"> * ShowHideWinTaskbarMex(1) -- To show the taskbar.<br></td></tr
><tr
id=sl_svn2420_7

><td class="source"> * ShowHideWinTaskbarMex(0) -- To hide the taskbar.<br></td></tr
><tr
id=sl_svn2420_8

><td class="source"> *<br></td></tr
><tr
id=sl_svn2420_9

><td class="source"> * Compile with:<br></td></tr
><tr
id=sl_svn2420_10

><td class="source"> *<br></td></tr
><tr
id=sl_svn2420_11

><td class="source"> * mex -v ShowHideWinTaskbarMex.c user32.lib<br></td></tr
><tr
id=sl_svn2420_12

><td class="source"> *<br></td></tr
><tr
id=sl_svn2420_13

><td class="source"> * If you want to compile on Octave, do this:<br></td></tr
><tr
id=sl_svn2420_14

><td class="source"> * mex -v ShowHideWinTaskbarMex.c user32.lib -DPTBOCTAVE3MEX<br></td></tr
><tr
id=sl_svn2420_15

><td class="source"> */<br></td></tr
><tr
id=sl_svn2420_16

><td class="source"><br></td></tr
><tr
id=sl_svn2420_17

><td class="source">/* Windows includes: */<br></td></tr
><tr
id=sl_svn2420_18

><td class="source">#include &lt;windows.h&gt;<br></td></tr
><tr
id=sl_svn2420_19

><td class="source"><br></td></tr
><tr
id=sl_svn2420_20

><td class="source">/* Matlab includes: */<br></td></tr
><tr
id=sl_svn2420_21

><td class="source">#include &quot;mex.h&quot;<br></td></tr
><tr
id=sl_svn2420_22

><td class="source"><br></td></tr
><tr
id=sl_svn2420_23

><td class="source">void showHide(int show)<br></td></tr
><tr
id=sl_svn2420_24

><td class="source">{<br></td></tr
><tr
id=sl_svn2420_25

><td class="source">    HWND hWnd;<br></td></tr
><tr
id=sl_svn2420_26

><td class="source">    hWnd = FindWindow(&quot;Shell_TrayWnd&quot;, NULL);<br></td></tr
><tr
id=sl_svn2420_27

><td class="source">    if (hWnd) {<br></td></tr
><tr
id=sl_svn2420_28

><td class="source">        ShowWindow(hWnd, (show) ? SW_SHOW : SW_HIDE);<br></td></tr
><tr
id=sl_svn2420_29

><td class="source">    } else {<br></td></tr
><tr
id=sl_svn2420_30

><td class="source">        mexPrintf(&quot;OOPS! Couldn&#39;t find taskbar window. Failed!\n&quot;);<br></td></tr
><tr
id=sl_svn2420_31

><td class="source">    }<br></td></tr
><tr
id=sl_svn2420_32

><td class="source">}<br></td></tr
><tr
id=sl_svn2420_33

><td class="source"><br></td></tr
><tr
id=sl_svn2420_34

><td class="source">void exitfunc(void)<br></td></tr
><tr
id=sl_svn2420_35

><td class="source">{<br></td></tr
><tr
id=sl_svn2420_36

><td class="source">    showHide(1);<br></td></tr
><tr
id=sl_svn2420_37

><td class="source">}<br></td></tr
><tr
id=sl_svn2420_38

><td class="source"><br></td></tr
><tr
id=sl_svn2420_39

><td class="source">/* This is the main entry point from Matlab: */<br></td></tr
><tr
id=sl_svn2420_40

><td class="source">void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray*prhs[])<br></td></tr
><tr
id=sl_svn2420_41

><td class="source">{<br></td></tr
><tr
id=sl_svn2420_42

><td class="source">    int show = 1;<br></td></tr
><tr
id=sl_svn2420_43

><td class="source">    <br></td></tr
><tr
id=sl_svn2420_44

><td class="source">    mexAtExit(exitfunc);    <br></td></tr
><tr
id=sl_svn2420_45

><td class="source">    if (nrhs &gt; 0) show = (int) mxGetScalar(prhs[0]);<br></td></tr
><tr
id=sl_svn2420_46

><td class="source">    showHide(show);<br></td></tr
><tr
id=sl_svn2420_47

><td class="source">    return;<br></td></tr
><tr
id=sl_svn2420_48

><td class="source">}<br></td></tr
></table></pre>
<pre><table width="100%"><tr class="cursor_stop cursor_hidden"><td></td></tr></table></pre>
</td>
</tr></table>

 
<script type="text/javascript">
 var lineNumUnderMouse = -1;
 
 function gutterOver(num) {
 gutterOut();
 var newTR = document.getElementById('gr_svn2420_' + num);
 if (newTR) {
 newTR.className = 'undermouse';
 }
 lineNumUnderMouse = num;
 }
 function gutterOut() {
 if (lineNumUnderMouse != -1) {
 var oldTR = document.getElementById(
 'gr_svn2420_' + lineNumUnderMouse);
 if (oldTR) {
 oldTR.className = '';
 }
 lineNumUnderMouse = -1;
 }
 }
 var numsGenState = {table_base_id: 'nums_table_'};
 var srcGenState = {table_base_id: 'src_table_'};
 var alignerRunning = false;
 var startOver = false;
 function setLineNumberHeights() {
 if (alignerRunning) {
 startOver = true;
 return;
 }
 numsGenState.chunk_id = 0;
 numsGenState.table = document.getElementById('nums_table_0');
 numsGenState.row_num = 0;
 if (!numsGenState.table) {
 return; // Silently exit if no file is present.
 }
 srcGenState.chunk_id = 0;
 srcGenState.table = document.getElementById('src_table_0');
 srcGenState.row_num = 0;
 alignerRunning = true;
 continueToSetLineNumberHeights();
 }
 function rowGenerator(genState) {
 if (genState.row_num < genState.table.rows.length) {
 var currentRow = genState.table.rows[genState.row_num];
 genState.row_num++;
 return currentRow;
 }
 var newTable = document.getElementById(
 genState.table_base_id + (genState.chunk_id + 1));
 if (newTable) {
 genState.chunk_id++;
 genState.row_num = 0;
 genState.table = newTable;
 return genState.table.rows[0];
 }
 return null;
 }
 var MAX_ROWS_PER_PASS = 1000;
 function continueToSetLineNumberHeights() {
 var rowsInThisPass = 0;
 var numRow = 1;
 var srcRow = 1;
 while (numRow && srcRow && rowsInThisPass < MAX_ROWS_PER_PASS) {
 numRow = rowGenerator(numsGenState);
 srcRow = rowGenerator(srcGenState);
 rowsInThisPass++;
 if (numRow && srcRow) {
 if (numRow.offsetHeight != srcRow.offsetHeight) {
 numRow.firstChild.style.height = srcRow.offsetHeight + 'px';
 }
 }
 }
 if (rowsInThisPass >= MAX_ROWS_PER_PASS) {
 setTimeout(continueToSetLineNumberHeights, 10);
 } else {
 alignerRunning = false;
 if (startOver) {
 startOver = false;
 setTimeout(setLineNumberHeights, 500);
 }
 }
 }
 function initLineNumberHeights() {
 // Do 2 complete passes, because there can be races
 // between this code and prettify.
 startOver = true;
 setTimeout(setLineNumberHeights, 250);
 window.onresize = setLineNumberHeights;
 }
 initLineNumberHeights();
</script>

 
 
 <div id="log">
 <div style="text-align:right">
 <a class="ifCollapse" href="#" onclick="_toggleMeta(this); return false">Show details</a>
 <a class="ifExpand" href="#" onclick="_toggleMeta(this); return false">Hide details</a>
 </div>
 <div class="ifExpand">
 
 
 <div class="pmeta_bubble_bg" style="border:1px solid white">
 <div class="round4"></div>
 <div class="round2"></div>
 <div class="round1"></div>
 <div class="box-inner">
 <div id="changelog">
 <p>Change log</p>
 <div>
 <a href="/p/psychtoolbox-3/source/detail?spec=svn2420&amp;r=1844">r1844</a>
 by kleinerm
 on Dec 2, 2010
 &nbsp; <a href="/p/psychtoolbox-3/source/diff?spec=svn2420&r=1844&amp;format=side&amp;path=/trunk/Psychtoolbox/PsychContributed/ShowHideWinTaskbarMex.c&amp;old_path=/trunk/Psychtoolbox/PsychContributed/ShowHideWinTaskbarMex.c&amp;old=">Diff</a>
 </div>
 <pre>* New mex file for Windows + Matlab
<a href="/p/psychtoolbox-3/source/detail?r=2007a">R2007a</a>: ShowHideWinTaskbarMex.

  Allows to programmatically show/hide the
Windows taskbar automatically
  shows it again at clear mex time.

  -&gt; May help to workaround weird issues
like discussed in forum
     message 11605.

</pre>
 </div>
 
 
 
 
 
 
 <script type="text/javascript">
 var detail_url = '/p/psychtoolbox-3/source/detail?r=1844&spec=svn2420';
 var publish_url = '/p/psychtoolbox-3/source/detail?r=1844&spec=svn2420#publish';
 // describe the paths of this revision in javascript.
 var changed_paths = [];
 var changed_urls = [];
 
 changed_paths.push('/trunk/Psychtoolbox/PsychBasic/MatlabWindowsFilesR2007a/ShowHideWinTaskbarMex.mexw32');
 changed_urls.push('/p/psychtoolbox-3/source/browse/trunk/Psychtoolbox/PsychBasic/MatlabWindowsFilesR2007a/ShowHideWinTaskbarMex.mexw32?r\x3d1844\x26spec\x3dsvn2420');
 
 
 changed_paths.push('/trunk/Psychtoolbox/PsychContributed/ShowHideWinTaskbarMex.c');
 changed_urls.push('/p/psychtoolbox-3/source/browse/trunk/Psychtoolbox/PsychContributed/ShowHideWinTaskbarMex.c?r\x3d1844\x26spec\x3dsvn2420');
 
 var selected_path = '/trunk/Psychtoolbox/PsychContributed/ShowHideWinTaskbarMex.c';
 
 
 function getCurrentPageIndex() {
 for (var i = 0; i < changed_paths.length; i++) {
 if (selected_path == changed_paths[i]) {
 return i;
 }
 }
 }
 function getNextPage() {
 var i = getCurrentPageIndex();
 if (i < changed_paths.length - 1) {
 return changed_urls[i + 1];
 }
 return null;
 }
 function getPreviousPage() {
 var i = getCurrentPageIndex();
 if (i > 0) {
 return changed_urls[i - 1];
 }
 return null;
 }
 function gotoNextPage() {
 var page = getNextPage();
 if (!page) {
 page = detail_url;
 }
 window.location = page;
 }
 function gotoPreviousPage() {
 var page = getPreviousPage();
 if (!page) {
 page = detail_url;
 }
 window.location = page;
 }
 function gotoDetailPage() {
 window.location = detail_url;
 }
 function gotoPublishPage() {
 window.location = publish_url;
 }
</script>

 
 <style type="text/css">
 #review_nav {
 border-top: 3px solid white;
 padding-top: 6px;
 margin-top: 1em;
 }
 #review_nav td {
 vertical-align: middle;
 }
 #review_nav select {
 margin: .5em 0;
 }
 </style>
 <div id="review_nav">
 <table><tr><td>Go to:&nbsp;</td><td>
 <select name="files_in_rev" onchange="window.location=this.value">
 
 <option value="/p/psychtoolbox-3/source/browse/trunk/Psychtoolbox/PsychBasic/MatlabWindowsFilesR2007a/ShowHideWinTaskbarMex.mexw32?r=1844&amp;spec=svn2420"
 
 >...07a/ShowHideWinTaskbarMex.mexw32</option>
 
 <option value="/p/psychtoolbox-3/source/browse/trunk/Psychtoolbox/PsychContributed/ShowHideWinTaskbarMex.c?r=1844&amp;spec=svn2420"
 selected="selected"
 >...tributed/ShowHideWinTaskbarMex.c</option>
 
 </select>
 </td></tr></table>
 
 
 




 
 </div>
 
 
 </div>
 <div class="round1"></div>
 <div class="round2"></div>
 <div class="round4"></div>
 </div>
 <div class="pmeta_bubble_bg" style="border:1px solid white">
 <div class="round4"></div>
 <div class="round2"></div>
 <div class="round1"></div>
 <div class="box-inner">
 <div id="older_bubble">
 <p>Older revisions</p>
 
 <a href="/p/psychtoolbox-3/source/list?path=/trunk/Psychtoolbox/PsychContributed/ShowHideWinTaskbarMex.c&start=1844">All revisions of this file</a>
 </div>
 </div>
 <div class="round1"></div>
 <div class="round2"></div>
 <div class="round4"></div>
 </div>
 
 <div class="pmeta_bubble_bg" style="border:1px solid white">
 <div class="round4"></div>
 <div class="round2"></div>
 <div class="round1"></div>
 <div class="box-inner">
 <div id="fileinfo_bubble">
 <p>File info</p>
 
 <div>Size: 1181 bytes,
 48 lines</div>
 
 <div><a href="//psychtoolbox-3.googlecode.com/svn-history/r2420/trunk/Psychtoolbox/PsychContributed/ShowHideWinTaskbarMex.c">View raw file</a></div>
 </div>
 
 <div id="props">
 <p>File properties</p>
 <dl>
 
 <dt>svn:executable</dt>
 <dd>*</dd>
 
 </dl>
 </div>
 
 </div>
 <div class="round1"></div>
 <div class="round2"></div>
 <div class="round4"></div>
 </div>
 </div>
 </div>


</div>

</div>
</div>

<script src="http://www.gstatic.com/codesite/ph/17134919371905794448/js/prettify/prettify.js"></script>
<script type="text/javascript">prettyPrint();</script>


<script src="http://www.gstatic.com/codesite/ph/17134919371905794448/js/source_file_scripts.js"></script>

 <script type="text/javascript" src="http://www.gstatic.com/codesite/ph/17134919371905794448/js/kibbles.js"></script>
 <script type="text/javascript">
 var lastStop = null;
 var initialized = false;
 
 function updateCursor(next, prev) {
 if (prev && prev.element) {
 prev.element.className = 'cursor_stop cursor_hidden';
 }
 if (next && next.element) {
 next.element.className = 'cursor_stop cursor';
 lastStop = next.index;
 }
 }
 
 function pubRevealed(data) {
 updateCursorForCell(data.cellId, 'cursor_stop cursor_hidden');
 if (initialized) {
 reloadCursors();
 }
 }
 
 function draftRevealed(data) {
 updateCursorForCell(data.cellId, 'cursor_stop cursor_hidden');
 if (initialized) {
 reloadCursors();
 }
 }
 
 function draftDestroyed(data) {
 updateCursorForCell(data.cellId, 'nocursor');
 if (initialized) {
 reloadCursors();
 }
 }
 function reloadCursors() {
 kibbles.skipper.reset();
 loadCursors();
 if (lastStop != null) {
 kibbles.skipper.setCurrentStop(lastStop);
 }
 }
 // possibly the simplest way to insert any newly added comments
 // is to update the class of the corresponding cursor row,
 // then refresh the entire list of rows.
 function updateCursorForCell(cellId, className) {
 var cell = document.getElementById(cellId);
 // we have to go two rows back to find the cursor location
 var row = getPreviousElement(cell.parentNode);
 row.className = className;
 }
 // returns the previous element, ignores text nodes.
 function getPreviousElement(e) {
 var element = e.previousSibling;
 if (element.nodeType == 3) {
 element = element.previousSibling;
 }
 if (element && element.tagName) {
 return element;
 }
 }
 function loadCursors() {
 // register our elements with skipper
 var elements = CR_getElements('*', 'cursor_stop');
 var len = elements.length;
 for (var i = 0; i < len; i++) {
 var element = elements[i]; 
 element.className = 'cursor_stop cursor_hidden';
 kibbles.skipper.append(element);
 }
 }
 function toggleComments() {
 CR_toggleCommentDisplay();
 reloadCursors();
 }
 function keysOnLoadHandler() {
 // setup skipper
 kibbles.skipper.addStopListener(
 kibbles.skipper.LISTENER_TYPE.PRE, updateCursor);
 // Set the 'offset' option to return the middle of the client area
 // an option can be a static value, or a callback
 kibbles.skipper.setOption('padding_top', 50);
 // Set the 'offset' option to return the middle of the client area
 // an option can be a static value, or a callback
 kibbles.skipper.setOption('padding_bottom', 100);
 // Register our keys
 kibbles.skipper.addFwdKey("n");
 kibbles.skipper.addRevKey("p");
 kibbles.keys.addKeyPressListener(
 'u', function() { window.location = detail_url; });
 kibbles.keys.addKeyPressListener(
 'r', function() { window.location = detail_url + '#publish'; });
 
 kibbles.keys.addKeyPressListener('j', gotoNextPage);
 kibbles.keys.addKeyPressListener('k', gotoPreviousPage);
 
 
 }
 </script>
<script src="http://www.gstatic.com/codesite/ph/17134919371905794448/js/code_review_scripts.js"></script>
<script type="text/javascript">
 function showPublishInstructions() {
 var element = document.getElementById('review_instr');
 if (element) {
 element.className = 'opened';
 }
 }
 var codereviews;
 function revsOnLoadHandler() {
 // register our source container with the commenting code
 var paths = {'svn2420': '/trunk/Psychtoolbox/PsychContributed/ShowHideWinTaskbarMex.c'}
 codereviews = CR_controller.setup(
 {"profileUrl":null,"token":null,"assetHostPath":"http://www.gstatic.com/codesite/ph","domainName":null,"assetVersionPath":"http://www.gstatic.com/codesite/ph/17134919371905794448","projectHomeUrl":"/p/psychtoolbox-3","relativeBaseUrl":"","projectName":"psychtoolbox-3","loggedInUserEmail":null}, '', 'svn2420', paths,
 CR_BrowseIntegrationFactory);
 
 codereviews.registerActivityListener(CR_ActivityType.REVEAL_DRAFT_PLATE, showPublishInstructions);
 
 codereviews.registerActivityListener(CR_ActivityType.REVEAL_PUB_PLATE, pubRevealed);
 codereviews.registerActivityListener(CR_ActivityType.REVEAL_DRAFT_PLATE, draftRevealed);
 codereviews.registerActivityListener(CR_ActivityType.DISCARD_DRAFT_COMMENT, draftDestroyed);
 
 
 
 
 
 
 
 var initialized = true;
 reloadCursors();
 }
 window.onload = function() {keysOnLoadHandler(); revsOnLoadHandler();};

</script>
<script type="text/javascript" src="http://www.gstatic.com/codesite/ph/17134919371905794448/js/dit_scripts.js"></script>

 
 
 
 <script type="text/javascript" src="http://www.gstatic.com/codesite/ph/17134919371905794448/js/ph_core.js"></script>
 
 
 
 
</div> 

<div id="footer" dir="ltr">
 <div class="text">
 <a href="/projecthosting/terms.html">Terms</a> -
 <a href="http://www.google.com/privacy.html">Privacy</a> -
 <a href="/p/support/">Project Hosting Help</a>
 </div>
</div>
 <div class="hostedBy" style="margin-top: -20px;">
 <span style="vertical-align: top;">Powered by <a href="http://code.google.com/projecthosting/">Google Project Hosting</a></span>
 </div>

 
 


 
 
 <script type="text/javascript">_CS_reportToCsi();</script>
 
 </body>
</html>

