// vim: set foldmethod=marker:

/* See LICENSE file for copyright and license details. */

/* appearance */


static const char font[]        = "FiraCode Nerd Font:style=Regular:size=10";

static const char col_foreground[] = "#ebdbb2";
static const char col_background[] = "#282828";
static const char col_color1[]     = "#cc241d";
static const char col_color7[]     = "#a89984";

static const char* normbgcolor  = col_background;
static const char* normfgcolor  = col_foreground;
static const char* selbgcolor   = col_color7;
static const char* selfgcolor   = col_background;
static const char* urgbgcolor   = col_color1;
static const char* urgfgcolor   = col_foreground;

static const char before[]      = "<";
static const char after[]       = ">";
static const char titletrim[]   = "...";
static const int  tabwidth      = 200;
static const Bool foreground    = True;
static       Bool urgentswitch  = False;

/*
 * Where to place a new tab when it is opened. When npisrelative is True,
 * then the current position is changed + newposition. If npisrelative
 * is False, then newposition is an absolute position.
 */
static int  newposition   = 0;
static Bool npisrelative  = False;

#define SETPROP(p) { \
        .v = (char *[]){ "/bin/sh", "-c", \
                "prop=\"`xwininfo -children -id $1 | grep '^     0x' |" \
                "sed -e's@^ *\\(0x[0-9a-f]*\\) \"\\([^\"]*\\)\".*@\\1 \\2@' |" \
                "xargs -0 printf %b | dmenu`\" &&" \
                "xprop -id $1 -f $0 8s -set $0 \"$prop\"", \
                p, winid, NULL \
        } \
}

#define MODKEY ControlMask
static Key keys[] = {
	/* { modifier     , key      , function    , { arguments } } */
	{ MODKEY, XK_Tab, rotate, { .i = +1   } },
	{ MODKEY|ShiftMask, XK_Tab, rotate, { .i = -1   } },
	{ MODKEY|ShiftMask,     XK_j,      movetab,     { .i = -1 } },
	{ MODKEY|ShiftMask,     XK_k,      movetab,     { .i = +1 } },
	{ 0, XK_F11, fullscreen, { 0         } },
};
