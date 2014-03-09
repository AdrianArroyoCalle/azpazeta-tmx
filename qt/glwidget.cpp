#include <QHBoxLayout>
#include <QtOpenGL>

#include <math.h>

#include "glwidget.hpp"

#include "../lib/gl.hpp"

#ifndef GL_MULTISAMPLE
#define GL_MULTISAMPLE  0x809D
#endif

GLWidget::GLWidget(QWidget *parent)
    : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
	
}

GLWidget::~GLWidget()
{
}

QSize GLWidget::minimumSizeHint() const
{
    return QSize(50, 50);
}

QSize GLWidget::sizeHint() const
{
    return QSize(400, 400);
}

static void qNormalizeAngle(int &angle)
{
    while (angle < 0)
        angle += 360 * 16;
    while (angle > 360 * 16)
        angle -= 360 * 16;
}

void GLWidget::initializeGL()
{
    //qglClearColor(qtPurple.dark());
	StartGL();
}

void GLWidget::paintGL()
{
    RefreshGL();
}

void GLWidget::resizeGL(int width, int height)
{
    ResizeGL(width, height);
}
