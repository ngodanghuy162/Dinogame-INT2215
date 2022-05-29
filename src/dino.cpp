#include "dino.h"
Alldino::Alldino()
{
    dino.upImage("pics/dino.png");
    mPosX = 100;
    mPosY=posground;
}
Alldino::~Alldino()
{
    dino.free();
}
void Alldino::handleEventDino( SDL_Event &e )
{
	if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        switch  (e.key.keysym.sym)
        {
            case SDLK_UP:
                    up=true;
            case SDLK_SPACE:
                    up=true;
        }
    }
}
void Alldino::setupDino()
{
    mPosX = 100;
    mPosY=posground;
    bird.setupEnemy();
    fire.setupEnemy();
    fire2.setupEnemy();
    monster.setupEnemy();
}
void Alldino::generateLevel(int &level)
{
    if (score>=200)
        level=1;
    if (score>=400)
        level=2;
    if (score>=600)
        level=3;
    if (score>=800)
        level=4;
    if (score>=1100)
        level=5;
    if (score>=1400)
        level=6;
    if (score>=1700)
        level=7;
    if (score>=2000)
        level=8;
    if (score>=2500)
        level=9;
}
void Alldino::moveDino(int leveljump)
{
        {
            if (checkdino==2 && up==true)
                {
                    dinomusic.playjumpSound();
                    checkdino=1;
                }
            if (checkdino==1 && mPosY>=posground-jumpheight)
                    mPosY-=velJump[leveljump];
            if (checkdino==0 && mPosY<=posground)
                    mPosY+=velJump[leveljump];
            if  (mPosY>=posground)
                    {
                    checkdino=2;
                    up=false;
                    }
            if (mPosY<=posground-jumpheight)
                    checkdino=0;
        }
       // frame=(SDL_GetTicks()/speedAnimation)% WALKING_ANIMATION_FRAMES;
}
bool Alldino::checkimpactfire()
{
    int yEnemy=fire.geteposY();
    int yEnemymax=fire.geteposY()+fire.getheight();
    int eposXmax=fire.geteposX()+fire.getwidth();
    if (mPosY+dino.getHeight()-10>=yEnemy && mPosY+dino.getHeight()-8<=yEnemymax )
    {
        if (mPosX+20>=fire.geteposX() && mPosX +20<=eposXmax)
                    {
                    return true;
                    }
        if  (mPosX+dino.getWidth()/5-40>=fire.geteposX() && mPosX+dino.getWidth()/5-40<=eposXmax)
                    {
                    return true;
                    }
    return false;
    }
}bool Alldino::checkimpactfire2()
{
    int yEnemy=fire2.geteposY();
    int yEnemymax=fire2.geteposY()+fire2.getheight();
    int eposXmax=fire2.geteposX()+fire2.getwidth();
    if (mPosY+dino.getHeight()-10>=yEnemy && mPosY+dino.getHeight()-8<=yEnemymax )
    {
        if (mPosX+20>=fire2.geteposX() && mPosX +20<=eposXmax)
                    {
                    return true;
                    }
        if  (mPosX+dino.getWidth()/5-40>=fire2.geteposX() && mPosX+dino.getWidth()/5-40<=eposXmax)
                    {
                    return true;
                    }
    return false;
    }
}
bool Alldino::checkimpactmonster()
{
    int yEnemy=monster.geteposY();
    int yEnemymax=monster.geteposY()+monster.getheight();
    int eposXmax=monster.geteposX()+monster.getwidth();
    if (mPosY+dino.getHeight()-10>=yEnemy && mPosY+dino.getHeight()-8<=yEnemymax )
    {
    if (mPosX+20>=monster.geteposX() && mPosX +20<=eposXmax)
           {
                    return true;
                    }
    if  (mPosX+dino.getWidth()/5-30>=monster.geteposX() && mPosX+dino.getWidth()/5-30<=eposXmax)
                    {
                    return true;
                    }
    return false;
    }
}
bool Alldino::checkimpactbird()
{
    int yEnemy=bird.geteposY();
    int yEnemymax=bird.geteposY()+bird.getheight();
    int eposXmax=bird.geteposX()+bird.getwidth()/4;
    if (mPosY+dino.getHeight()-15>=yEnemy&& mPosY+dino.getHeight()-15<=yEnemymax)
    {
        if (mPosX+10>=bird.geteposX()&& mPosX +10<=eposXmax)
            return true;
        if  (mPosX+dino.getWidth()/5-40>=bird.geteposX() && mPosX+dino.getWidth()/5-40<=eposXmax)
            return true;
    }
    if (mPosY+15>=yEnemy && mPosY+15<=yEnemymax) //kiemtra dau dino co thuoc khoang hinh cngai vat ko
           {
            if (mPosX+30>=bird.geteposX()&& mPosX+30<=eposXmax)    //ben trai duoi con dino
                return true;
            if (mPosX+dino.getWidth()/5-30>=bird.geteposX() && mPosX+dino.getWidth()/5-30<=eposXmax)    //ben phai con dino
                return true;
           }
    return false;
}
/*bool Alldino::checkimpactFriend(Friend a)
{
    int yFriend=a.getfposY();
    int yFriendmax=a.getfposY()+a.getheight();
    int fposXmax=a.getfposX()+a.getwidth();
    if (mPosY+dino.getHeight()-15>=yFriend && mPosY+dino.getHeight()-15<=yFriendmax)
    {
        if (mPosX+10>=a.getfposX()&& mPosX +10<=fposXmax)
            return true;
        if  (mPosX+dino.getWidth()/5-30>=a.getfposX() && mPosX+dino.getWidth()/5-30<=fposXmax)
            return true;
    }
    if (mPosY+15>=yFriend && mPosY+15<=yFriendmax) //kiemtra dau dino co thuoc khoang hinh cngai vat ko
           {
            if (mPosX+30>=a.getfposX()&& mPosX+30<=fposXmax)    //ben trai duoi con dino
                return true;
            if (mPosX+dino.getWidth()/5-30>=a.getfposX() && mPosX+dino.getWidth()/5-30<=fposXmax)    //ben phai con dino
                return true;
           }
    return false;
}*/
void Alldino::renderDino()
{
    frame=(SDL_GetTicks()/speedAnimation[level])% WALKING_ANIMATION_FRAMES;
    dino.renderAnimation(mPosX,mPosY,80,80,frame,flip);
    bird.renderEnemyAnimation(level);
    if(level>5)
    {
        monster.renderEnemy();
    }
    fire.renderEnemy();
    fire2.renderEnemy();
}
