
static const char font[] = "FiraCode Nerd Font:style=Regular:size=10";

static const char col_foreground[] = "#ebdbb2";
static const char col_background[] = "#1d2021";
static const char col_color1[]     = "#cc241d";
static const char col_color7[]     = "#a89984";

static const char* normbgcolor = col_background;
static const char* normfgcolor = col_foreground;
static const char* selbgcolor  = col_color7;
static const char* selfgcolor  = col_background;
static const char* urgbgcolor  = col_color1;
static const char* urgfgcolor  = col_foreground;

static const char before[]     = "<";
static const char after[]      = ">";
static const char titletrim[]  = "...";
static const int  tabwidth     = 200;
static const Bool foreground   = True;
static       Bool urgentswitch = False;

/*
 * Where to place a new tab when it is opened. When npisrelative is True,
 * then the current position is changed + newposition. If npisrelative
 * is False, then newposition is an absolute position.
 */
static int  newposition  = 0;
static Bool npisrelative = False;

static Key keys[] = {
	{ 0,                     XK_Tab, rotate,  { .i = +1 } },
	{ ShiftMask,             XK_Tab, rotate,  { .i = -1 } },
	{ ControlMask,           XK_Tab, movetab, { .i = +1 } },
	{ ControlMask|ShiftMask, XK_Tab, movetab, { .i = -1 } },
};
