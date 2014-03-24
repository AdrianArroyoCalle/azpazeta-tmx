#include "gl.hpp"

void StartGL()
{
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glEnable(GL_TEXTURE_2D);
}
void RefreshGL()
{
	glLoadIdentity();
	//glClear(GL_COLOR_BUFFER_BIT);
	glColor4f(1, 1, 1, 1);
    glBegin(GL_QUADS);
		glVertex3f(0,0,0);
		glVertex3f(50,0,0);
		glVertex3f(50,50,0);
		glVertex3f(0,50,0);
	glEnd();
}
void ResizeGL(int width, int height)
{
	glLoadIdentity();
	//glClear(GL_COLOR_BUFFER_BIT);
	glColor4f(1, 1, 1, 1);
    glBegin(GL_QUADS);
		glVertex3f(0,0,0);
		glVertex3f(width,0,0);
		glVertex3f(width,height,0);
		glVertex3f(0,height,0);
	glEnd();
}
