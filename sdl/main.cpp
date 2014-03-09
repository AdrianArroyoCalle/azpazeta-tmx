#include <SDL/SDL.h>
#include "../lib/gl.hpp"

int main(int argc, char** argv)
{
	const SDL_VideoInfo* info = NULL;
	int width=640;
	int height=480;
	int bpp=0;
	int flags=0;
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		SDL_Quit();
		return 1;
	}
	info=SDL_GetVideoInfo();
	if(!info)
	{
		SDL_Quit();
		return 1;
	}
	bpp = info->vfmt->BitsPerPixel;
	SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 5 );
    SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 5 );
    SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 5 );
    SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 16 );
    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );
    
    flags = SDL_OPENGL | SDL_RESIZABLE;
    
    if(SDL_SetVideoMode(width, height, bpp, flags) < 0)
    {
		SDL_Quit();
		return 1;
	}
	StartGL();
	while(1)
	{
		SDL_Event event;
		while(SDL_PollEvent(&event))
		{
			switch (event.type){
				case SDL_KEYDOWN:
				SDL_Quit();
				return 0;
				break;
				case SDL_QUIT:
				SDL_Quit();
				return 0;
				break;
			}
		}
		RefreshGL();
		SDL_GL_SwapBuffers();
	}
	return 0;
}
