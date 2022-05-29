#ifndef GAME_IMAGE__H_INCLUDED
#define GAME_IMAGE__H_INCLUDED

#include "include.h"
#include "Engine.h"
class ManageTexture
{
    public:

        //Init
        ManageTexture();

        //Close
        ~ManageTexture();

        //Load image
        bool upImage(string path);


        //Creates image from font string
        bool loadFromRenderedText (string textureText, SDL_Color textColor);


        //Destroy
        void free();

        //Set color modulation
		void setColor( Uint8 red, Uint8 green, Uint8 blue );

		//Set blending
		void setBlendMode( SDL_BlendMode blending );

		//Set alpha modulation
		void setAlpha( Uint8 alpha );

		//Renders texture at given point
		void render( int x, int y, SDL_Rect* clip , double angle , SDL_Point* center , SDL_RendererFlip &flip);
        void renderAnimation(int x,int y,int width,int height,int frame,SDL_RendererFlip &flip);
        void rendertext(int x,int y,int width,int height);
		//Gets image dimensions
		int getWidth();
		int getHeight();

    private:
		//The actual hardware texture
		SDL_Texture* mTexture;
        TTF_Font* gFont ;
        //Image dimensions
		int mWidth;
		int mHeight;
};

#endif // GAME_IMAGE__H_INCLUDED
