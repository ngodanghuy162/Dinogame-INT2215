#include "Engine.h"

SDL_Renderer* Engine::renderer=nullptr;
bool Engine::initProg()
{
    bool success=true;

    if((SDL_INIT_EVERYTHING) < 0)
    {
        printf("Could not init SDL %s\n", SDL_GetError());
        success=false;
    }
    else{
        if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY,"1"))
        {
            printf("Warning: Linear texture filtering not enable ");
        }

        //Create window successfully
        window = SDL_CreateWindow( "Dino game project", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( window == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer successfully
			renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if( renderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
				if(TTF_Init() == -1)
                {
                    TTF_GetError();
                    success=false;
                }
				//Initialize SDL_mixer
                    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
                    {
                    printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
                    success = false;
                    }
			}
		}
	}
	return success;
}
int Engine::readHighscore()
{
    int best = 0;
    SDL_RWops *file = SDL_RWFromFile("score/score.bin", "r+b"); //nếu tệp không tồn tại thì sẽ được tạo và kỉ lục tính là 0
    if (file)
    {
        SDL_RWread(file, &best, sizeof(int), 1);
        SDL_RWclose(file);
    }
    return best;
}
void Engine::closeProg()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    window = nullptr;
    renderer = nullptr;
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
}
