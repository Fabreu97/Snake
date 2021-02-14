#include "CollisionManager.h"
#include <math.h>
CollisionManager::CollisionManager()
{
    snake = NULL;
    field = NULL;
    food = NULL;
}

CollisionManager::~CollisionManager() {
    snake = NULL;
    field = NULL;
    food = NULL;
}

void CollisionManager::setSnake(Snake* s)
{
    snake = s;
}
void CollisionManager::setField(Field* f)
{
    field = f;
}
void CollisionManager::setFood(ent::Food* fd)
{
    food = fd;
}

const bool CollisionManager::CheckCollisionSnake() const {
    VF head = snake->getPosition();
    unsigned int s = snake->getSize();
    unsigned int i;
    for(i = 0; i < (s - 1); i++) {
        if(head.x == snake->getSegmentPosition(i).x) {
            if(head.y == snake->getSegmentPosition(i).y) {
                return true;
            }
        }
    }
    return false;
}

const bool CollisionManager::CheckCollisionsField() const //REVIEW
{
    VF head = snake->getPosition();
    const float s = snake->getBlockSize()/2.0;
    VF limitsX = field->limitsX();
    VF limitsY = field->limitsY();
    if( (head.y - s) >= limitsY.x && (head.y + s) <= limitsY.y)
    {
        if((head.x - s)>= limitsX.x && (head.x + s) <= limitsX.y)
        {
            return false;
        }
    }
    return true;
}

const bool CollisionManager::CheckCollisionsFood() const
{
    if(food != NULL)
    {
        VF food_position = food->getPosition();
        VF food_size = food->getSizeTexture();
        VF snake_position = snake->getPosition();
        VF snake_size = VF(snake->getBlockSize(), snake->getBlockSize());

        VF intersect;

        intersect.x = abs(snake_position.x - food_position.x) - (snake_size.x + food_size.x)/2;
        intersect.y = abs(snake_position.y - food_position.y) - (snake_size.y + food_size.y)/2;
        if(intersect.x < 0.0f && intersect.y < 0.0f)
        {
            return true;
        }
    }
    return false;
}

void CollisionManager::RandomPosiitonForFood()
{
    srand(time(NULL));
    VF pos;
    bool different = false;
    VF limitsX = field->limitsX();
    VF limitsY = field->limitsY();
    VU fsize = field->getBlockSize();
    float blocksize = snake->getBlockSize();
    float spacing = snake->getSpacing();
    while(!different) {
        pos.x = limitsX.x + rand()%fsize.x * (blocksize + spacing) + blocksize/2;
        pos.y = limitsY.x + rand()%fsize.y * (blocksize + spacing) + blocksize/2;
        different = snake->different(pos);
    }
    food->setPosition(pos);
}
