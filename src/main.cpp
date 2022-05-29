#include "include.h"
#include "Engine.h"
#include "game_image.h"
#include "dino.h"
#include "enemy.h"
#include "button.h"
#include "menu.h"
#include "friend.h"
#include "music.h"
int main(int argc, char* argv[])
{
    Engine g;
    g.initProg();
    SDL_SetRenderDrawColor(Engine::renderer,255,255,255,255);
    Menu game;
  while (game.gameloop==true)
  {
    switch(Menu::status)
        {
        case 0:
            {
           game.renderMenu();
           break;
            }

        case 1:
            {
            game.renderGameplay();
            break;
            }
        case 2:
            {
            game.renderGameover();
            break;
            }
        }
  }
    cout<<"Mong tren B ltnc"<<endl;
}
