Azpazeta TMX 
============

Azpazeta TMX is a tool for see native TMX maps for Azpazeta without opening Azpazeta. It uses OpenGL ES 2 and uses differents backends:
* Haiku
* wxWidgets
* FLTK
* Gtk
* X11
* QT
* SDL
* WinAPI

Azpazeta TMX uses the same implementation of TMX as Azpazeta based on TinyXML.

Building
========

First you need to configure the backends that you want to build. Something like that for SDL and QT:
```
cmake . -DSDL_BACKEND=ON -DQT_BACKEND=ON

make
```

