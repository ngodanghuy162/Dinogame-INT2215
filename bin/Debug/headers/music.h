#ifndef MUSIC_H_INCLUDED
#define MUSIC_H_INCLUDED
#include "include.h"
class Music
{
public:
    Music();
    void playjumpSound();
    void playmenuMusic();
    void playloseSound();
    void playmouseSound();
    void playbgrdMusic();
private:
    Mix_Chunk* jumpSound = NULL;
	Mix_Music* menuMusic = NULL;
	Mix_Chunk* loseSound = NULL;
	Mix_Music* bgrdMusic = NULL;
	Mix_Chunk* mouseClick = NULL;
};


#endif // MUSIC_H_INCLUDED
