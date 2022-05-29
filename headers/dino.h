#ifndef DINO_H_INCLUDED
#define DINO_H_INCLUDED
#include "include.h"
#include "game_image.h"
#include "enemy.h"
#include "music.h"
#include "friend.h"
const int WALKING_ANIMATION_FRAMES = 5;
class Friend;
class Alldino
{
    public:
        const int jumpheight=200;
        const int posground=585;
        const int dino_v=5;
        double velJump[10]={5,5.5,6,6.5,7,7.5,8,8.5,9,9.5};
        Alldino();
        ~Alldino();
        void setupDino();
        void handleEventDino(SDL_Event &e);
        void moveDino(int leveljump);
        void renderDino();
        void setupXEnemy();
        bool checkimpactfire();
        bool checkimpactfire2();
        bool checkimpactbird();
        bool checkimpactmonster();
        //bool checkimpactFriend(Friend a);
        Enemy bird{"pics/bird1.png",1250,530,200};
        Enemy fire{"pics/fire.png",1650,605,200};
        Enemy fire2{"pics/fire.png",2050,605,200};
        Enemy monster{"pics/monster.png",2050,595,100};
        ManageTexture dino;
        Music dinomusic;
        int score;
        int level=0;
        int mPosX,mPosY;
        void generateLevel(int &level);
    private:
        int frame=0;
        int speedAnimation[10]={200,185,170,155,140,130,115,100,80,60};
        SDL_Rect dinoclip[WALKING_ANIMATION_FRAMES ];
        SDL_RendererFlip flip=SDL_FLIP_NONE;
        //int mPosX,mPosY;
        int checkdino=2;
        bool up=false;
        // 2 dung yen,1 len,0 xuong;
};
#endif // DINO_H_INCLUDED
