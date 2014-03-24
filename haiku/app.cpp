#include "app.hpp"
#include "window.hpp"

AzpazetaTMX::AzpazetaTMX() : BApplication("application/azpazeta-tmx")
{
	
}
void AzpazetaTMX::ReadyToRun()
{
	BWindow* win=new Window();
	win->Show();
}
