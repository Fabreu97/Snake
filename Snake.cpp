#include "Snake.h"

GraphicManager* Snake::g = NULL;

Snake::Snake(const unsigned int snake_size, const VF starting_position , const float block_size, const float spacing):
    direction(0),
    previous(0),
    body(),
    elapsed_time(0.0),
    ate(false),
    bs(block_size),
    spacing(spacing)
{
    unsigned int i;
    for(i = 0; i < snake_size; i++) {
        ent::Segment* aux = new ent::Segment();
        aux->setPosition(starting_position.x - (snake_size - (i + 1)) * (bs + spacing) , starting_position.y);
        aux->setSizeTexture(bs, bs);
        aux->setKey("body");
        body.enqueue(aux);
    }
}


Snake::~Snake()
{
    while(!body.empty())
    {
        delete body.front();
        body.dequeue();
    }
}

void Snake::setGraphicManager(GraphicManager* manager)
{
    g = manager;
}
void Snake::RelocatePosition(const VF starting_position) {
    unsigned int i;
    for(i = 0; i < body.getSize(); i++) {
        ent::Segment* aux = *body[i];
        aux->setPosition(starting_position.x - (body.getSize() - (i + 1)) * (bs + spacing) , starting_position.y);
    }
}

const float Snake::getSpacing () const {
    return spacing;
}

Queue<ent::Segment*>* Snake::getBody()
{
    return &body;
}

const float Snake::getBlockSize() const {
    return bs;
}

const VF Snake::getPosition()
{
    return( (*(body.back()))->getPosition() );
}

const VF Snake::getSegmentPosition(const unsigned int i)
{
    return (*body[i])->getPosition();
}

const unsigned int Snake::getSize() const
{
    return body.getSize();
}

const VF Snake::getSegmentPosition() {
    return (*body.front())->getSize();
}

void Snake::fullTummy()
{
    ate = true;
}

void Snake::move ()
{
    elapsed_time += g->get_Delta_Time();
    if(elapsed_time >= SLEEP)
    {
        ent::Segment* aux;
        if(ate) {
            aux = new ent::Segment();
            aux->setSizeTexture( (*body.front())->getSizeTexture() );
            aux->setKey("body");
            ate = false;
        } else {
            aux = *(body.front());
            body.dequeue();
        }
        if( direction != 2 && g->isP_Right() ) {
            aux->setPosition( (*(body.back()))->getPosition().x + 40.0f, (*(body.back()))->getPosition().y);
            direction = 0;
        } else if ( direction != 0 && g->isP_Left() ) {
            aux->setPosition( (*(body.back()))->getPosition().x - 40.0f, (*(body.back()))->getPosition().y);
            direction = 2;
        } else if ( direction != 3 && g->isP_UP() ) {
            aux->setPosition( (*(body.back()))->getPosition().x, (*(body.back()))->getPosition().y - 40.0f);
            direction = 1;
        } else if ( direction != 1 && g->isP_Down() ) {
            aux->setPosition( (*(body.back()))->getPosition().x, (*(body.back()))->getPosition().y + 40.0f);
            direction = 3;
        } else {
            switch(direction)
            {
                case 0:
                {
                    aux->setPosition( (*(body.back()))->getPosition().x + 40.0f, (*(body.back()))->getPosition().y);
                    break;
                }
                case 1:
                {
                    aux->setPosition( (*(body.back()))->getPosition().x, (*(body.back()))->getPosition().y - 40.0f);
                    break;
                }
                case 2:
                {
                    aux->setPosition( (*(body.back()))->getPosition().x - 40.0f, (*(body.back()))->getPosition().y);
                    break;
                }
                case 3:
                {
                    aux->setPosition( (*(body.back()))->getPosition().x, (*(body.back()))->getPosition().y + 40.0f);
                    break;
                }
            }
        }
        body.enqueue(aux);
        elapsed_time = 0.00f;
    }
}

void Snake::move2() {
    elapsed_time += g->get_Delta_Time();
    if(previous != 2 && g->isP_Right()) {
        direction = 0;
    } else if (previous != 3 && g->isP_UP()) {
        direction = 1;
    } else if (previous != 0 && g->isP_Left()) {
        direction = 2;
    } else if (previous != 1 && g->isP_Down()) {
        direction = 3;
    }
    if(elapsed_time > SLEEP) {
        ent::Segment* aux;
        if(ate) {
            aux = new ent::Segment();
            aux->setSizeTexture((*body.front())->getSizeTexture());
            aux->setKey("body");
            ate = false;
        } else {
            aux = *(body.front());
            body.dequeue();
        }
        if(direction == 0) {
            aux->setPosition( (*(body.back()))->getPosition().x + bs + spacing, ((*body.back()))->getPosition().y);
        } else if(direction == 1) {
            aux->setPosition( (*(body.back()))->getPosition().x, ((*body.back()))->getPosition().y - bs - spacing);
        } else if(direction == 2) {
            aux->setPosition( (*(body.back()))->getPosition().x - bs - spacing , ((*body.back()))->getPosition().y);
        } else if(direction == 3) {
            aux->setPosition( (*(body.back()))->getPosition().x, ((*body.back()))->getPosition().y + bs + spacing);
        }
        previous = direction;
        body.enqueue(aux);
        elapsed_time = 0.0;
    }
}

void Snake::Draw ()
{
    unsigned int i;
    for(i = 0; i < body.getSize(); i++) {
        (*body[i])->Update();
        (*body[i])->Draw();
    }
}

const bool Snake::different(const VF pos)
{
    unsigned int i;
    for(i = 0; i < body.getSize(); i++)
    {
        if( pos.x == (*(body[i]))->getPosition().x ) {
            if(pos.y == (*(body[i]))->getPosition().y) {
                return false;
            }
        }
    }
    return true;
}
