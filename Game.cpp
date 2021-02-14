#include "Game.h"

Game::Game () :
    g(new GraphicManager("Snake", WINDOWSIZE)),
    c(new CollisionManager()),
    snake(new Snake(SNAKESIZE, VF(440.0, 400.0), BLOCKSIZE, SPACING)),
    field(new Field(BLOCKSIZE, BLOCKSX, BLOCKSY, SPACING)),
    food(new Food(VF(600.0, 500.0), VF(30.0, 30.0))),
    score(0u)
{
    Entity::setGraphicManager(g);
    Snake::setGraphicManager(g);
    g->AddBody("body");
    g->AddBody("head");
    g->AddBody("food");
    g->AddBody("wall");
    g->setColor("body", 0, 255, 0, 255);
    g->setColor("head", 0, 220, 0, 255);
    g->setColor("food", 255, 30, 30, 255);
    g->setColor("wall", 0, 0, 0, 255);
}

Game::~Game () {
    delete g;
    delete c;
    delete snake;
    delete field;
    delete food;
}

void Game::run () {
    //initial update
    c->setField(field);
    c->setSnake(snake);
    c->setFood(food);
    g->Centralize(800.0,400.0);
    g->setView();
    field->centralize(VF(800.0f, 400.0f));
    snake->RelocatePosition( VF(field->limitsX().x + BLOCKSIZE/2 + (BLOCKSIZE * (BLOCKSX/2 - 1)) + SPACING * (BLOCKSX/2 - 1), field->limitsY().x + BLOCKSIZE/2 + BLOCKSIZE * (BLOCKSY/2 - 1) + SPACING * (BLOCKSY/2 - 1) ) );
    //loop of game
    while(g->isOpen()) {
        g->set_Delta_Time();
        cout << g->get_Delta_Time() << endl;
        while(g->pollEvent()) {
            if(g->closed()) {
                g->close();
            } else if (g->Resized()) {
                g->ResizeView();
            }
        }
        if(c->CheckCollisionsFood()) {
            snake->fullTummy();
            c->RandomPosiitonForFood();
            score++;
        }
        if(c->CheckCollisionsField() || c->CheckCollisionSnake()) {
            this->record();
            delete snake;
            snake = new Snake(SNAKESIZE, VF(field->limitsX().x + BLOCKSIZE/2 + (BLOCKSIZE * (BLOCKSX/2 - 1)) + SPACING * (BLOCKSX/2 - 1), field->limitsY().x + BLOCKSIZE/2 + BLOCKSIZE * (BLOCKSY/2 - 1) + SPACING * (BLOCKSY/2 - 1) ), BLOCKSIZE, SPACING);
            c->setSnake(snake);
        }
        food->Update();
        snake->move2();

        g->clear(255,255,255);

        snake->Draw();
        food->Draw();
        field->Draw();

        g->display();
    }
}

void Game::record() {
    ifstream in;
    ofstream out;
    unsigned int s = 0;
    in.open("score.dat", ios::in);

    if(in) {
        in >> s;
    }
    in.close();
    if(score > s) {
        out.open("score.dat", ios::out);
        if(!out) {
            cerr << "ERRO: RECORDS" << endl;
            fflush(stdin);
            return;
        }
        out << score;
        out.close();
    } else {
        score = 0;
    }
}
