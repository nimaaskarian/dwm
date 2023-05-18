// vim:fileencoding=utf-8:foldmethod=marker 
/* See LICENSE file for copyright and license details. */

/* appearance {{{*/
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "JetBrainsMono Nerd Font Mono:size=12" };
static const char dmenufont[]       = "JetBrainsMono Nerd Font Mono:size=12";
/*}}}*/
/* normal colors {{{*/
// static const char col_gray1[]       = "#222222";
// static const char col_gray2[]       = "#444444";
// static const char col_gray3[]       = "#bbbbbb";
// static const char col_gray4[]       = "#eeeeee";
// static const char col_cyan[]        = "#327956";
// static const char col_inactive[]    = "#144229";
// static const char *colors[][3]      = {
// 	/*               fg						bg						 border   */
// 	[SchemeNorm]	 = { col_gray3, col_gray1,		 col_gray2 },
// 	[SchemeSel]		 = { col_gray4, col_cyan,			 col_cyan  },
// 	[SchemeInact]	 = { col_gray4, col_inactive,  col_inactive  },
// };
/*}}}*/
/* pywal {{{*/
#include "colors-wal-my-dwm.h"
static const char *colors[][3]      = {
	/*               fg						bg						 border   */
	[SchemeNorm]	 = { norm_fg,   norm_bg,   		 norm_border},
	[SchemeSel]		 = { sel_fg,    sel_bg,  			 sel_border},
	[SchemeInact]	 = { inact_fg,  inact_bg,  		 inact_border},
};
/*}}}*/
/* tagging {{{*/
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class						instance    title					tags mask     isfloating   monitor */
	{ "Gimp",						NULL,       NULL,					0,            1,           -1 },
	{ "firefox",				NULL,       NULL,					1<<1,         0,           -1 },
	{ "Gimp",						NULL,       NULL,					0,            1,           -1 },
	{ "Xournalpp",			NULL,       NULL,					1<<8,         0,           -1 },
	{ "Chromium",				NULL,       NULL,					1<<1,         0,           -1 },
	{ "Zathura",				NULL,       NULL,					1<<6,         0,           -1 },
	{ "st-256color",		NULL,       "st",					1,            0,           -1 },
	{ "st-256color",		NULL,       "lvim",				1<<4,         0,           -1 },
	{ "st-256color",		NULL,       "ranger",			1<<7,         0,           -1 },
};
/*}}}*/
/* layout(s) {{{*/
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};
/*}}}*/
/* key definitions {{{*/
#define MODKEY Mod4Mask
#define ALTKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }
/*}}}*/
/* commands {{{*/
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
// static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", norm_bg, "-nf", norm_fg, "-sb", sel_bg, "-sf", sel_fg, NULL };
// static const char *dmenucmd[] = { "rofi", "-show", "drun"};
// static const char *termcmd[]  = { "kitty", NULL };
static const char *termcmd[]  = { "st", NULL };
static const char *rangercmd[]  = { "st","-e","ranger", NULL };
static const char *warpdcmd[]  = { "warpd","--hint",";","killall","warpd", NULL };
static const char *editorcmd[]  = { "st","-e","/home/nima/.local/bin/lvim", NULL };
static const char *screenshotcmd[]  = { "flameshot","gui", NULL };
static const char *powermenucmd[]  = { "/home/nima/Scripts/dmenu-powermenu.sh",norm_bg,norm_fg,sel_fg,sel_bg,dmenufont, NULL };
static const Key keys[] = {
	/* modifier                     key						 function        argument */
	{ ALTKEY,                       XK_d,					 spawn,          {.v = dmenucmd } },
	{ ALTKEY,                       XK_q,					 spawn,          {.v = powermenucmd } },
	{ MODKEY,                       XK_Return,		 spawn,          {.v = termcmd } },
	{ MODKEY|ControlMask,           XK_Return,		 zoom,           {0} },
	{ MODKEY,                       XK_b,					 togglebar,      {0} },
	{ MODKEY,                       XK_j,					 focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,					 focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,					 incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,					 incnmaster,     {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_h,					 setmfact,       {.f = -0.05} },
	{ MODKEY|ShiftMask,             XK_l,					 setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_Return,		 spawn,          {.v = editorcmd} },
	{ MODKEY,                       XK_s,					 spawn,          {.v = screenshotcmd} },
	{ MODKEY,                       XK_Tab,				 view,           {0} },
	{ MODKEY,                       XK_q,					 killclient,     {0} },
	{ MODKEY,                       XK_t,					 setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_p,					 setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_f,					 setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,			 setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,			 togglefloating, {0} },
	{ MODKEY|ShiftMask,             XK_e,					 spawn,        	 {.v = rangercmd} },
	{ MODKEY,                       XK_0,					 view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,					 tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_h,					 focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_l,					 focusmon,       {.i = +1 } },
	{ MODKEY|ControlMask,           XK_h,					 tagmon,         {.i = -1 } },
	{ MODKEY|ControlMask,           XK_h,					 spawn,          {.v = warpdcmd } },
	{ MODKEY|ControlMask,           XK_l,					 tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,													 0)
	TAGKEYS(                        XK_2,													 1)
	TAGKEYS(                        XK_3,													 2)
	TAGKEYS(                        XK_4,													 3)
	TAGKEYS(                        XK_5,													 4)
	TAGKEYS(                        XK_6,													 5)
	TAGKEYS(                        XK_7,													 6)
	TAGKEYS(                        XK_8,													 7)
	TAGKEYS(                        XK_9,													 8)
	{ MODKEY|ShiftMask,             XK_q,					 quit,           {0} },
};
/*}}}*/
/* button definitions {{{*/
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
/*}}}*/
