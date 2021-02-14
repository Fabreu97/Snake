#include "Entity.h"

///IMPLEMENTACOES DA CLASS ENTIDADE

GraphicManager* ent::Entity::control = NULL;

ent::Entity::Entity(const string c)
{
    id = 0;
    path = c;
}

ent::Entity::~Entity()
{

}

void ent::Entity::setID(const unsigned long int ID)
{
    id = ID;
}

const unsigned long int ent::Entity::getID() const
{
    return(id);
}

void ent::Entity::setKey(const string k)
{
    key = k;
}

const string ent::Entity::getKey() const
{
    return(key);
}

const string ent::Entity::getTexture() const
{
    return(path);
}

void ent::Entity::setSizeTexture(const Vector2D<float> v)
{
    texture_size = v;
}

void ent::Entity::setSizeTexture(const float x, const float y)
{
    texture_size.x = x;
    texture_size.y = y;
}

const Vector2D<float> ent::Entity::getSizeTexture() const
{
    return(texture_size);
}

void ent::Entity::setPosition(const Vector2D<float> v)
{
    pos = v;
}

void ent::Entity::setPosition(const float x, const float y)
{
    pos.x = x;
    pos.y = y;
}

const Vector2D<float> ent::Entity::getPosition() const
{
    return(pos);
}

void ent::Entity::setGraphicManager(GraphicManager* pg)
{
    control = pg;
}

GraphicManager* ent::Entity::getGraphicManager()
{
    return(control);
}
