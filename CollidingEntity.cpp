#include "CollidingEntity.h"

ent::CollidingEntity::CollidingEntity(const string c):
    Entity(c),
    collided(false)
{

}

ent::CollidingEntity::~CollidingEntity()
{

}

void ent::CollidingEntity::setColisao(const bool c)
{
    collided = c;
}

const bool ent::CollidingEntity::getColisao() const
{
    return(collided);
}

void ent::CollidingEntity::setSize(const Vector2D<float> v)
{
    colliding_size = v;
}

void ent::CollidingEntity::setSize(const float x, const float y)
{
    colliding_size.x = x;
    colliding_size.y = y;
}

Vector2D<float> ent::CollidingEntity::getSize() const
{
    return(colliding_size);
}

const Vector2D<float> ent::CollidingEntity::getHalfSize() const
{
    return(colliding_size * 0.5f);
}
