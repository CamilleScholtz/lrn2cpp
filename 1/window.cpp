#include "window.hpp"

Window win;
XEvent ev;
Display *dpy;
GC pen;
int dx[8192];
int dy[8192];
int di = 0;

void winloop() {
	while (1) {
		XNextEvent(dpy, &ev);

		switch (ev.type) {
		case Expose:
			for (int i=0; i<di; i++) {
				XDrawPoint(dpy, win, pen, dx[i], dy[i]);
			}
			break;
		case KeyPress:
			if (XLookupKeysym(&ev.xkey, 0) == XK_q) {
				goto stop;
			}
			break;
		}
	}

stop:
	XDestroyWindow(dpy, win);
	XCloseDisplay(dpy);
}

window::window(int w, int h):
w(w), h(h) {
	int scr;
	unsigned long black, white;
	XGCValues val;

	dpy = XOpenDisplay(NULL);
	scr = DefaultScreen(dpy);

	black = BlackPixel(dpy, scr);
	white = WhitePixel(dpy, scr);

	// Create a window.
	win = XCreateSimpleWindow(dpy, DefaultRootWindow(dpy),
	                          0, 0, w, h,
	                          10, black,
	                          white);

	// Show the window.
	XSelectInput(dpy, win, ExposureMask|KeyPressMask);
	Atom delWindow = XInternAtom(dpy, "WM_DELETE_WINDOW", 0);
	XSetWMProtocols(dpy, win, &delWindow, 1);
	XMapWindow(dpy, win);

	val.foreground = black;
	val.line_width = 1;
	val.line_style = LineSolid;
	pen = XCreateGC(dpy, win,
		GCForeground|GCLineWidth|GCLineStyle, &val);

	atexit(winloop);
}

void window::draw(int x, int y) {
	dx[di] = x;
	dy[di] = y;
	di++;
}
