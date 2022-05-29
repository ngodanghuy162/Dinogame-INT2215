#ifndef FRIEND_H_INCLUDED
#define FRIEND_H_INCLUDED
#include "include.h"
#include "music.h"
#include "game_image.h"
#include "dino.h"
class Alldino;
class Friend
{
    public:
        Friend();
        double vel[10]={30,40,50,60,70,80,90,100,110,120};
        ManageTexture star;
        ManageTexture heart;
        void setupFriend();
        void moveFriend(int level);
        void moveHeart(int level);
        void renderFriend();
        void renderHeart();
        void render1life();
        void render2life();
        void render3life();
        void setupLive(int &countHeart,int &life);
        bool checkimpactdino(Alldino &xdino);
        bool checkimpactHeart(Alldino &xdino);
      /*  int getfposX();
        int getfposY();
        int getwidth();
        int getheight();*/
    private:
       // int miny;
        int fposX;
        int fposY;
     //   int eWidth, eHeight;
        SDL_RendererFlip flip=SDL_FLIP_NONE;
};



#endif // FRIEND_H_INCLUDED
