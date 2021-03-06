#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

class QSlider;

class GLWidget;

class Window : public QWidget
{

public:
    Window();

protected:
    void keyPressEvent(QKeyEvent *event);

private:
    GLWidget *glWidget;
};

#endif
