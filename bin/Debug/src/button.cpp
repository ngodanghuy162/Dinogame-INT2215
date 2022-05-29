#include "button.h"
LButton::LButton(int x,int y, int w,int h)
{
	mPosition.x = x;
	mPosition.y = y;
    BUTTON_WIDTH=w;
    BUTTON_HEIGHT=h;
}
bool LButton::isInside()
{
    int x, y;
		SDL_GetMouseState( &x, &y );
		//Check if mouse is in button
		bool inside = true;

		//Mouse is left of the button
		if( x < mPosition.x )
		{
			inside = false;
		}
		//Mouse is right of the button
		else if( x > mPosition.x + BUTTON_WIDTH )
		{
			inside = false;
		}
		//Mouse above the button
		else if( y < mPosition.y )
		{
			inside = false;
		}
		//Mouse below the button
		else if( y > mPosition.y + BUTTON_HEIGHT )
		{
			inside = false;
		}
    return inside;
}
