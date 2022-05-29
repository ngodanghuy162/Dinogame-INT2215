#include "menu.h"
int Menu::status=0;
Menu::Menu()
{
    menu.upImage("pics/menu.jpg");
    instrucstion.upImage("pics/huongdan.jpg");
    gameover.upImage("pics/playagain.jpg");
    background.upImage("pics/background.jpg");
    highscore.upImage("pics/score.jpg");
    renderStar.upImage("pics/star.png");
    musicOnl.upImage("pics/on.png");
    musicOff.upImage("pics/off.png");
}
void Menu::renderGameplay()
{
    Mix_HaltMusic();
    if(countMusic%2==0)
        music.playbgrdMusic();
    time_score=SDL_GetTicks();
    countStar=0;
    countHeart=0;
    live=1;
    maindino.score=0;
    while(playgame==true)
                {
                    SDL_RenderClear(Engine::renderer);
                    while(SDL_PollEvent(&e) != 0)
                        {
                            if(e.type == SDL_QUIT)
                                   {
                                       playgame=false;
                                       gameloop=false;
                                   }
                        maindino.handleEventDino(e);
                        }
                if(live>0)
                {
                    if ((maindino.checkimpactbird()==false) && (maindino.checkimpactfire()==false) &&(maindino.checkimpactfire2()==false) && (maindino.level<=5 || (!maindino.checkimpactmonster() && maindino.level>5)))
                    {
                            if( scrollingOffset < -background.getWidth() )
                                {
                                    scrollingOffset = 0;
                                }
                    maindino.score=(SDL_GetTicks()-time_score)/100;
                    maindino.generateLevel(maindino.level);
                    scrollingOffset -=rollLevel[maindino.level];
                    score_text.loadFromRenderedText(to_string(maindino.score),textColor);
                    star_count_text.loadFromRenderedText(to_string(countStar),textColor);
                    background.render( scrollingOffset, 0,nullptr,0,nullptr,allflip );
                    background.render( scrollingOffset + background.getWidth(), 0,nullptr,0,nullptr,allflip );
                    renderStar.render(950,110,nullptr,0,nullptr,allflip);
                    heart.renderHeart();
                    heart.moveFriend(maindino.level);
                    heart.setupLive(countHeart,live);
                    if(heart.checkimpactHeart(maindino)==true)
                    {
                        countHeart++;
                        heart.setupFriend();
                    }
                    if(live==1)
                        heart.render1life();
                    if(live==2)
                        heart.render2life();
                    if(live==3)
                        heart.render3life();
                    maindino.renderDino();
                    score_text.rendertext(50,50,50,50);
                    maindino.moveDino(maindino.level);
                    maindino.fire.moveEnemy(maindino.level);
                    for(int i=0;i<4;i++)
                       {
                           star[i].renderFriend();
                           star[i].moveFriend(maindino.level);
                       }
                    for(int i=0;i<4;i++)
                        {
                           if (star[i].checkimpactdino(maindino)==true)
                                {
                                    countStar++;
                                    star[i].setupFriend();
                               }
                        }
                    star_count_text.rendertext(1000,100,60,60);
                    if(maindino.level<=5 || maindino.fire2.geteposX()<1250)
                        {
                            maindino.fire2.moveEnemy(maindino.level);
                        }
                    maindino.bird.moveEnemy(maindino.level);
                    if (maindino.level>5)
                        {
                            maindino.monster.moveEnemy(maindino.level);
                        }
                    }
                }
                    if ((maindino.checkimpactfire2()==true)||(maindino.checkimpactbird()==true) || (maindino.checkimpactfire()==true) || (maindino.checkimpactmonster()==true && maindino.level>5))
                    {
                        live--;
                        countHeart-=5;
                        maindino.setupDino();
                    }
                    if (live==0)
                    {
                        music.playloseSound();
                      //  maindino.score=maindino.score+countStar*20;
                        score_end=maindino.score+countStar*8;
                        if(score_end>Engine::readHighscore())
                        {
                            SDL_RWops *file = SDL_RWFromFile("score/score.bin", "w+b");
                            SDL_RWwrite(file, &score_end, sizeof(int), 1);
                            SDL_RWclose(file);
                        }
                        SDL_RenderClear(Engine::renderer);
                        gamelose=true;
                        Menu::status=2;
                        playgame=false;
                        Mix_HaltMusic();
                    }
                    SDL_RenderPresent(Engine::renderer);
                }
}
void Menu::renderMenu()
{
    while(!quit)
                    {
                        while(SDL_PollEvent(&e) != 0)
                               {
                                if(e.type == SDL_QUIT)
                                    quit = true;
                                if (play.isInside()==true && (e.type ==SDL_MOUSEBUTTONDOWN))
                                    {
                                        Mix_HaltMusic();
                                        playgame=true;
                                        quit=true;
                                        Menu::status=1;
                                    }
                                if (instructionButton.isInside()==true && (e.type ==SDL_MOUSEBUTTONDOWN))
                                    {
                                        music.playmouseSound();
                                        renderInstruction();
                                    }
                                if (musicControl.isInside()==true && (e.type ==SDL_MOUSEBUTTONDOWN))
                                    {
                                        music.playmouseSound();
                                        countMusic++;
                                    }
                                if (score.isInside()==true && (e.type ==SDL_MOUSEBUTTONDOWN))
                                  {
                                      music.playmouseSound();
                                      renderHighScore();
                                  }
                                if(e.type == SDL_QUIT)
                                            exit(0);
                                if (exitButton.isInside()==true && (e.type ==SDL_MOUSEBUTTONDOWN))
                                {
                                    music.playmouseSound();
                                    exit(0);
                                }

                                }
                            if (countMusic%2==0)
                            {
                                music.playmenuMusic();
                            }
                            else
                                {
                                    Mix_HaltMusic();
                                }
                            SDL_RenderClear(Engine::renderer);
                            menu.render(0,0,nullptr,0,nullptr,allflip);
                            if(countMusic%2==0)
                                musicOnl.render(1100,15,nullptr,0,nullptr,allflip);
                            else
                                musicOff.render(1100,15,nullptr,0,nullptr,allflip);
                            SDL_RenderPresent(Engine::renderer);
                    }
}
void Menu::renderInstruction()
{
    isrenderInstruction=true;
    while (isrenderInstruction==true)
    {
    SDL_RenderClear(Engine::renderer);
    instrucstion.render(0,0,nullptr,0,nullptr,allflip);
    while(SDL_PollEvent(&e) != 0)
        {
                if(e.type == SDL_QUIT)
                    exit(0);
                if (backtomenu.isInside()==true && (e.type ==SDL_MOUSEBUTTONDOWN))
                    {
                            music.playmouseSound();
                            isrenderInstruction=false;
                    }
        }
     SDL_RenderPresent(Engine::renderer);
    }
}
void Menu::renderGameover()
{
    endScore_text.loadFromRenderedText(to_string(score_end),textColor);
    while (gamelose==true)
    {
        SDL_RenderClear(Engine::renderer);
        gameover.render(0,0,nullptr,0,nullptr,allflip);
        endScore_text.rendertext(680,360,160,160);
        while(SDL_PollEvent(&e) != 0)
        {
            if(exit_again.isInside()==true && (e.type ==SDL_MOUSEBUTTONDOWN))
               {
                   music.playmouseSound();
                   exit(0);
               }
            if (playagain.isInside()==true && (e.type ==SDL_MOUSEBUTTONDOWN))
                {
                    music.playmouseSound();
                    Menu::status=1;
                    playgame=true;
                    maindino.setupDino();
                    time_score=SDL_GetTicks();
                    gamelose=false;
                }
            if (home.isInside()==true && (e.type ==SDL_MOUSEBUTTONDOWN))
                {
                    music.playmouseSound();
                    Menu::status=0;
                    quit=false;
                    maindino.setupDino();
                    gamelose=false;
                }
        }
        SDL_RenderPresent(Engine::renderer);
    }
}
void Menu::renderHighScore()
{
    isrenderScore=true;
    highscore_text.loadFromRenderedText(to_string(Engine::readHighscore()),textColor);
    while (isrenderScore==true)
    {
    SDL_RenderClear(Engine::renderer);
    highscore.render(0,0,nullptr,0,nullptr,allflip);
    highscore_text.rendertext(500,460,250,250);
        while(SDL_PollEvent(&e) != 0)
            {
                if(e.type == SDL_QUIT)
                    exit(0);
                if (backtomenu.isInside()==true && (e.type ==SDL_MOUSEBUTTONDOWN))
                    {
                            music.playmouseSound();
                            isrenderScore=false;
                    }
            }
     SDL_RenderPresent(Engine::renderer);
    }
}
