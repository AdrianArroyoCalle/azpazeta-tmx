#include <opengl/GLView.h>
#include "tmxgl.hpp"
#include "../lib/gl.hpp"

TMXGL::TMXGL() : BGLView(BRect(0,0,800,600),"Azpazeta TMX",B_FOLLOW_ALL_SIDES,0,BGL_RGB|BGL_DOUBLE)
{
	
}
void TMXGL::AttachedToWindow()
{
	LockGL();
	BGLView::AttachedToWindow();
	StartGL();
	RefreshGL();
	Render();
	UnlockGL();
}
void TMXGL::FrameResized(float width, float height)
{
	LockGL();
	BGLView::FrameResized(width, height);
	ResizeGL((int)width,(int)height);
	UnlockGL();
	Render();
}
void TMXGL::ErrorCallback(GLenum which)
{
	
}
void TMXGL::Render()
{
	LockGL();
	RefreshGL();
	SwapBuffers();
	UnlockGL();
}
