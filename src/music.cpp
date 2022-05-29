#include "music.h"
Music::Music()
{

	menuMusic = Mix_LoadMUS( "sound/sound_menu_audio.wav" );
	if( menuMusic == NULL )
	{
		printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
	}

	bgrdMusic = Mix_LoadMUS( "sound/sound_bkgr_audio.wav" );
	if( bgrdMusic == NULL )
	{
		printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
	}

	//Load sound effects
	jumpSound = Mix_LoadWAV( "sound/sound_jump_sound.wav" );
	if( jumpSound == NULL )
	{
		printf( "Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
	}

	loseSound = Mix_LoadWAV( "sound/sound_lose_sound.wav" );
	if( loseSound == NULL )
	{
		printf( "Failed to load high sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
	}

	mouseClick = Mix_LoadWAV( "sound/sound_mouse_click.wav" );
	if( mouseClick == NULL )
	{
		printf( "Failed to load medium sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
	}
}
void Music::playbgrdMusic()
{
   if (!Mix_PlayingMusic())
            Mix_PlayMusic(bgrdMusic, -1);
}
void Music::playjumpSound()
{
    Mix_PlayChannel(-1, jumpSound, 0);
}
void Music::playloseSound()
{
    Mix_PlayChannel(-1, loseSound, 0);
}
void Music::playmenuMusic()
{
    if (!Mix_PlayingMusic())
            Mix_PlayMusic(menuMusic, -1);
}
void Music::playmouseSound()
{
    Mix_PlayChannel(-1, mouseClick, 0);
}
