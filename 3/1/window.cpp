#include "window.hpp"

static Window win;
static XEvent ev;
static Display *dpy;
static GC pen;
static int drawx[65536];
static int drawy[65536];
static int drawi = 0;

void winloop() {
	while (true) {
		XNextEvent(dpy, &ev);

		switch (ev.type) {
		case Expose:
			for (int i=0; i<drawi; i++) {
				XDrawPoint(dpy, win, pen, drawx[i], drawy[i]);
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

window::window(const vector &size):
size(size) {
	int scr;
	unsigned long black, white;
	XGCValues val;

	dpy = XOpenDisplay(NULL);
	scr = DefaultScreen(dpy);

	black = BlackPixel(dpy, scr);
	white = WhitePixel(dpy, scr);

	// Create a window.
	win = XCreateSimpleWindow(dpy, DefaultRootWindow(dpy),
	                          0, 0, size.x, size.y,
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

void window::clear() {
	drawi = 0;
}

void window::draw(const vector &pixel) {
	drawx[drawi] = pixel.x;
	drawy[drawi] = pixel.y;
	drawi++;
}

void wait_ms(int n){
	usleep(n*1000);
}
