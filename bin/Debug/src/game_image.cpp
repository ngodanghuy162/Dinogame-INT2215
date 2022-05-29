#include "game_image.h"
#include "Engine.h"

ManageTexture::ManageTexture()
{
	//Init
	mTexture = nullptr;
	mWidth = 0;
	mHeight = 0;
}

ManageTexture::~ManageTexture()
{
	free();
}

bool ManageTexture::upImage( string path )
{
	free();

	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str());

	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Color key image
		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(Engine::renderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}
		else
		{
			//Get image dimensions
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	//Return success
	mTexture = newTexture;
	return mTexture != NULL;
}


bool ManageTexture::loadFromRenderedText(string textureText, SDL_Color textColor )
{
	//Get rid of preexisting texture
	free();
    gFont = TTF_OpenFont("pics/lazy.ttf", 30);
	//Render text surface
	SDL_Surface* textSurface = TTF_RenderText_Solid( gFont, textureText.c_str(), textColor );
	if( textSurface != NULL )
	{
		//Create texture from surface pixels
        mTexture = SDL_CreateTextureFromSurface( Engine::renderer, textSurface );
		if( mTexture == NULL )
		{
			printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
		}
		/*else
		{
			//Get image dimensions
			mWidth = textSurface->w;
			mHeight = textSurface->h;
		}*/
		//Get rid of old surface
		SDL_FreeSurface( textSurface );
	}
	else
	{
		printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
	}

	//Return success
	return mTexture != NULL;
}

void ManageTexture::free()
{
	if( mTexture != NULL )
	{
		SDL_DestroyTexture( mTexture );
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void ManageTexture::setColor( Uint8 red, Uint8 green, Uint8 blue )
{
	//Modulate texture rgb
	SDL_SetTextureColorMod( mTexture, red, green, blue );
}

void ManageTexture::setBlendMode( SDL_BlendMode blending )
{
	//Set blending function
	SDL_SetTextureBlendMode( mTexture, blending );
}

void ManageTexture::setAlpha( Uint8 alpha )
{
	//Modulate texture alpha
	SDL_SetTextureAlphaMod( mTexture, alpha );
}

void ManageTexture::render( int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip &flip )
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	//Set clip rendering dimensions
	if( clip != NULL )
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}
	//Render to screen
	SDL_RenderCopyEx( Engine::renderer, mTexture, clip, &renderQuad, angle, center, flip );
}
void ManageTexture::renderAnimation(int x,int y,int width,int height,int frame,SDL_RendererFlip &flip)
{
    SDL_Rect src={width*frame,0,width,height};
    SDL_Rect dest={x,y,width,height};
    SDL_RenderCopyEx( Engine::renderer, mTexture, &src, &dest, 0, nullptr, flip );
}
void ManageTexture::rendertext(int x,int y,int width,int height)
{
    SDL_Rect des={x,y,width,height};
    SDL_RenderCopy(Engine::renderer,mTexture,NULL,&des);
}
int ManageTexture::getWidth()
{
	return mWidth;
}

int ManageTexture::getHeight()
{
	return mHeight;
}
