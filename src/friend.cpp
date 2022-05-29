#include "friend.h"
Friend::Friend()
{
    heart.upImage("pics/heart.png");
    star.upImage("pics/star.png");
    fposX=rand()%1000+1200;
    fposY=rand()%800+100;
}
void Friend::setupFriend()
{
    fposX=rand()%1000+1200;
    fposY=rand()%900+100;
}
void Friend::moveFriend(int level)
{
    if (fposX>=0)
        fposX-=vel[level];
    if (fposX<=0)
       {
        fposX=1250+rand()%1000;
         fposY=rand()%800+100;
       }
}
void Friend::setupLive(int &countHeart,int &life)
{
    if (life>=3)
        countHeart=10;
    if (countHeart>=5 && countHeart<10)
            life=2;
    if (countHeart>=10 && countHeart<15)
            life=3;
}
void Friend::moveHeart(int level)
{
    if(fposX>=0)
        fposX -=(vel[level]+15);
    if (fposX<=0)
    {
        fposX=rand()%1000+1200;
        fposY=rand()%800+100;
    }
}
void Friend::renderFriend()
{
    star.render(fposX,fposY,nullptr,0,nullptr,flip);
}
void Friend::renderHeart()
{
    heart.render(fposX,fposY,nullptr,0,nullptr,flip);
}
void Friend::render1life()
{
    heart.render(1000,20,nullptr,0,nullptr,flip);
}
void Friend::render2life()
{
    heart.render(1000,20,nullptr,0,nullptr,flip);
    heart.render(1080,20,nullptr,0,nullptr,flip);
}
void Friend::render3life()
{
    heart.render(1000,20,nullptr,0,nullptr,flip);
    heart.render(1080,20,nullptr,0,nullptr,flip);
    heart.render(1160,20,nullptr,0,nullptr,flip);
}
bool Friend::checkimpactdino(Alldino &xdino)
{
    int yDino=xdino.mPosY;
    int yDinomax=xdino.mPosY+xdino.dino.getHeight();
    int mposXmax=xdino.mPosX+xdino.dino.getWidth()/4;
    if (fposY+star.getHeight()>=yDino&& fposY+star.getHeight()<=yDinomax)
        {
        if (fposX>=xdino.mPosX&& fposX<=mposXmax)
            return true;
        if  (fposX+star.getWidth()>=xdino.mPosX && fposX+star.getWidth()<=mposXmax)
            return true;
        }
    if (fposY>=yDino && fposY<=yDinomax) //kiemtra dau dino co thuoc khoang hinh cngai vat ko
           {
            if (fposX>=xdino.mPosX&& fposX<=mposXmax)    //ben trai duoi con dino
                return true;
            if (fposX+star.getWidth()>=xdino.mPosX && fposX+star.getWidth()<=mposXmax)    //ben phai con dino
                return true;
           }
    return false;
}
bool Friend::checkimpactHeart(Alldino &xdino)
{
    int yDino=xdino.mPosY;
    int yDinomax=xdino.mPosY+xdino.dino.getHeight();
    int mposXmax=xdino.mPosX+xdino.dino.getWidth()/4;
    if (fposY+heart.getHeight()>=yDino&& fposY+heart.getHeight()<=yDinomax)
        {
        if (fposX>=xdino.mPosX&& fposX<=mposXmax)
            return true;
        if  (fposX+heart.getWidth()>=xdino.mPosX && fposX+heart.getWidth()<=mposXmax)
            return true;
        }
    if (fposY>=yDino && fposY<=yDinomax) //kiemtra dau dino co thuoc khoang hinh cngai vat ko
           {
            if (fposX>=xdino.mPosX&& fposX<=mposXmax)    //ben trai duoi con dino
                return true;
            if (fposX+heart.getWidth()>=xdino.mPosX && fposX+heart.getWidth()<=mposXmax)    //ben phai con dino
                return true;
           }
    return false;
}
/*int Friend::getwidth()
{
    return star.getWidth();
}
int Friend::getheight()
{
    return star.getHeight();
}*/
