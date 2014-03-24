#include "window.hpp"

const int32_t EXIT='EXIT';

Window::Window() : BWindow(BRect(50,50,800,600),"Azpazeta TMX",B_TITLED_WINDOW,0)
{
	gl=new TMXGL();
	AddChild(gl);
}
bool Window::QuitRequested()
{
	be_app_messenger.SendMessage(B_QUIT_REQUESTED);
	return BWindow::QuitRequested();
}
void Window::MessageReceived(BMessage* msg)
{
	switch(msg->what)
	{
		case EXIT : {
				QuitRequested();
				break;
			}
		default: {
			BWindow::MessageReceived(msg);
			}
	}
}
