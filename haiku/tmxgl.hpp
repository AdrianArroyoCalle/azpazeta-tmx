#ifndef TMXGL_HPP
#define TMXGL_HPP

class TMXGL : public BGLView {
public:
	TMXGL();
	virtual void AttachedToWindow();
	virtual void FrameResized(float width, float height);
	virtual void ErrorCallback(GLenum which);
	
	void Render();	
};

#endif
