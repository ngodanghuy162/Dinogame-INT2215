#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "include.h"
#include "game_image.h"
#include "button.h"
#include "enemy.h"
#include "dino.h"
#include "Engine.h"
#include "music.h"
#include "friend.h"
class Menu
{
public:
    Menu();
    LButton play{560,365,120,100};
    LButton score{560,465,120,100};
    LButton exitButton{427,545,120,65};
    LButton exit_again{676,545,240,120};
    LButton instructionButton{686,545,120,65};
    LButton playagain{355,545,220,133};
    LButton backtomenu{0,0,146,75};
    LButton home{0,0,130,130};
    LButton musicControl{1100,15,80,80};
    ManageTexture musicOnl;
    ManageTexture musicOff;
    ManageTexture renderStar;
    ManageTexture star_count_text;
    ManageTexture endScore_text;
    ManageTexture score_text;
    ManageTexture highscore_text;
    ManageTexture background;
    ManageTexture menu;
    ManageTexture instrucstion;
    ManageTexture gameover;
    ManageTexture highscore;
    ManageTexture heart_text;
    Friend star[4];
    Friend heart;
    Music music;
    Alldino maindino;
    SDL_Color textColor = {0 ,255 ,0 };
    SDL_RendererFlip allflip=SDL_FLIP_NONE;
    SDL_Event e;
    bool gamelose=false;
    bool quit = false;
    bool playgame=true;
    bool gameloop=true;
    bool isrenderInstruction=false;
    bool isrenderScore=false;
    int time_score=0;
    int scrollingOffset = 0;
    int score_end;
    int countStar;
    int countMusic=0;
    int countHeart=0;
    int live=1;
    static int status;
    double rollLevel[10]={4,4.5,5,5.5,6,6.5,7,8,9,10};
    void renderMenu();
    void renderInstruction();
    void renderGameover();
    void renderGameplay();
    void renderHighScore();
    private:
};


#endif // MENU_H_INCLUDED
