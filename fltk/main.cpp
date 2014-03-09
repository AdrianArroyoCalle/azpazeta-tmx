#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Gl_Window.H>
#include "../lib/gl.hpp"

class TMXWin : public Fl_Gl_Window{
	public:
		TMXWin(int x, int y, int w, int h, const char* l=0) : Fl_Gl_Window(x,y,w,h,l)
		{
			StartGL();
		}
		void draw()
		{
			RefreshGL();
		}
		void resize(int X, int Y,int W, int H)
		{
			Fl_Gl_Window::resize(X,Y,W,H);
			ResizeGL(W,H);
		}
	
};

int main(int argc, char** argv)
{
	Fl_Window win(500,500,"Azpazeta TMX Viewer");
	TMXWin window(10,10,win.w()-20,win.h()-20);
	win.end();
	win.resizable(window);
	win.show(argc,argv);
	return Fl::run();
}


