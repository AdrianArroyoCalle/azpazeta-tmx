#include <GL/gl.h>
#include <GL/glx.h>
#include <GL/glu.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <stdio.h>

#include "../lib/gl.hpp"

Display                 *display;
Window                  root;
GLint                   att[] = { GLX_RGBA, GLX_DEPTH_SIZE, 24, GLX_DOUBLEBUFFER, None };
XVisualInfo             *vi;
Colormap                cmap;
XSetWindowAttributes    swa;
Window                  win;
GLXContext              glc;
XWindowAttributes       gwa;
XEvent                  xev;

int main(int argc, char** argv)
{
	display=XOpenDisplay(NULL);
	if(!display)
	{
		printf("[ERROR] Cannot open X11 display");
		return 1;
	}
	root=DefaultRootWindow(display);
	vi=glXChooseVisual(display, 0, att);
	cmap=XCreateColormap(display, root, vi->visual, AllocNone);
	swa.colormap = cmap;
	swa.event_mask = ExposureMask | KeyPressMask;
	win = XCreateWindow(display, root, 0, 0, 600, 600, 0, vi->depth, InputOutput, vi->visual, CWColormap | CWEventMask, &swa);
	XMapWindow(display, win);
	XStoreName(display, win, "Azpazeta TMX Viewer");
	glc=glXCreateContext(display,vi,NULL,GL_TRUE);
	glXMakeCurrent(display,win,glc);
	StartGL();
	while(1) {
        XNextEvent(display, &xev);
        
        if(xev.type == Expose) {
                XGetWindowAttributes(display, win, &gwa);
                glViewport(0, 0, gwa.width, gwa.height);
                RefreshGL();
                glXSwapBuffers(display, win);
        }
                
        else if(xev.type == KeyPress) {
                glXMakeCurrent(display, None, NULL);
                glXDestroyContext(display, glc);
                XDestroyWindow(display, win);
                XCloseDisplay(display);
                return 0;
        }
    }
}
