#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED
#include "include.h"

class LButton
{
	public:

		//Initializes internal variables
		LButton(int x,int y, int w,int h);

		bool isInside();


	private:
		//Top left position
		SDL_Point mPosition;

		//Currently used global sprite
        int BUTTON_WIDTH;
        int BUTTON_HEIGHT;
};

#endif // BUTTON_H_INCLUDED
