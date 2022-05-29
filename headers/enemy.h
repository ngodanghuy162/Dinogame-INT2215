#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED
#include "game_image.h"
#include "include.h"
const int FLYING_ANIMATION_FRAMES = 4;
class Enemy
{
   public:
        double velEnemy[10]={4,4.5,5,5.5,6,6.75,7.5,8.5,9.5,10.5};
        Enemy(string path,int posXrender,int posYrender,int randomX);
        ~Enemy();
        void setupEnemy();
        void moveEnemy(int level);
        void renderEnemy();
        void renderEnemyAnimation(int level);
        int geteposX();
        int geteposY();
        int getwidth();
        int getheight();
       ManageTexture enemy;
    private:
        int enemyspeedanimation[10]={200,185,170,155,140,130,115,100,80,60};
        int enemyFrame=0;
        int eposX;
        int eposY;
        int eposXconst;
        int eposYconst;
        int eWidth, eHeight;
        SDL_RendererFlip flip=SDL_FLIP_NONE;
        SDL_RendererFlip enemyflip=SDL_FLIP_HORIZONTAL;
};
#endif // ENEMY_H_INCLUDED
