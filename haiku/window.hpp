#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <Window.h>
#include <opengl/GLView.h>
#include "tmxgl.hpp"

class Window : public BWindow{
public:
	Window();
	bool QuitRequested();
	void MessageReceived(BMessage* msg);
private:
	TMXGL* gl;	
};
#endif WINDOW_HPP
