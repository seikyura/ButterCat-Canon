// COMP710 GP 2D Framework
#ifndef __BACKBUFFER_H__
#define __BACKBUFFER_H__

#include <string>
using namespace std;

// Forward Declarations:
class TextureManager;
class Sprite;
class AnimatedSprite;
struct SDL_Window;
struct SDL_Renderer;
struct SDL_Color;

class BackBuffer
{
	//Member Methods:
public:
	BackBuffer();
	~BackBuffer();

	bool Initialise(int width, int height);

	void Clear();
	void Present();

	void SetClearColour(unsigned char r, unsigned char g, unsigned char b);

	void SetDrawColour(unsigned char r, unsigned char g, unsigned char b);
	void SetDrawColour(unsigned char r, unsigned char g, unsigned char b, unsigned char a);

	void DrawSprite(Sprite& sprite);
	void DrawRectangle(int x1, int y1, int x2, int y2);
	void DrawLine(int x1, int y1, int x2, int y2);
	void DrawAnimatedSprite(AnimatedSprite& sprite);
	void DrawTextOnScreen(SDL_Color colour, string fontType, const char* text, int textSize, int x, int y);
	Sprite* CreateSprite(const char* pcFilename);
	AnimatedSprite* CreateAnimatedSprite(const char* pcFilename);

	
protected:
	void LogSDLError();

private:
	BackBuffer(const BackBuffer& backBuffer);
	BackBuffer& operator=(const BackBuffer& backBuffer);

	//Member Data:
public:

protected:
	TextureManager* m_pTextureManager;

	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	int m_width;
	int m_height;

	unsigned char m_clearRed;
	unsigned char m_clearGreen;
	unsigned char m_clearBlue;
	
private:

};

#endif // __BACKBUFFER_H__
