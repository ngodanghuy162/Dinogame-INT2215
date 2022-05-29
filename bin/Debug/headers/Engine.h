#ifndef ENGINE_H_INCLUDED
#define ENGINE_H_INCLUDED
#include "include.h"
const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 725
;

class Engine
{
public:
    SDL_Window* window;
    static SDL_Renderer* renderer;
    bool initProg();
    static int readHighscore();
    void closeProg();
private:
};

/*
static SDL_Window* window;
static SDL_Renderer* renderer;
bool initProg();
void closeProg();
*/
#endif // ENGINE_H_INCLUDED
