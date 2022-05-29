#include "enemy.h"
Enemy::Enemy(string path,int posXrender,int posYrender,int randomX)
{
    enemy.upImage(path);
    eposX=rand()%randomX+posXrender;
    eposY=posYrender;
    eposXconst=posXrender;
    eposYconst=posYrender;
}
Enemy::~Enemy()
{
   enemy.free();
}
void Enemy::setupEnemy()
{
    eposX=eposXconst;
    eposY=eposYconst;
}
void Enemy::moveEnemy(int level)
{
    if (eposX>=0)
        eposX-=velEnemy[level];
    if (eposX<=0)
        eposX=1250;
}
int Enemy::geteposX()
{
    return eposX;
}
int Enemy::geteposY()
{
    return eposY;
}
int Enemy::getwidth()
{
    return enemy.getWidth();
}
int Enemy::getheight()
{
    return enemy.getHeight();
}
void Enemy::renderEnemy()
{
    enemy.render(eposX,eposY,nullptr,0,nullptr,flip);
}
void Enemy::renderEnemyAnimation(int level)
{
    enemyFrame=(SDL_GetTicks()/enemyspeedanimation[level])%FLYING_ANIMATION_FRAMES;
    enemy.renderAnimation(eposX,eposY,enemy.getWidth()/4,enemy.getHeight(),enemyFrame,enemyflip);
}
