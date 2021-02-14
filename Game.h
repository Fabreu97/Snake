#ifndef INCLUDED_GAME_H
#define INCLUDED_GAME_H

#include "CollisionManager.h"
#include <fstream>

#define WINDOWSIZE VU(1200, 800u)
#define BLOCKSIZE 40.0f
#define BLOCKSX 19
#define BLOCKSY 11
#define SPACING 10.0f
#define SNAKESIZE 2

using namespace ent;

class Game {
private:
    GraphicManager* g;
    CollisionManager* c;
    Snake* snake;
    Field* field;
    Food* food;
    unsigned int score;

public:
    Game();
    ~Game();

    void run();
    void record();
};

#endif // INCLUDED_GAME_H
