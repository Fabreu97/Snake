#include "Food.h"

ent::Food::Food(const VF starting_position, const VF size,const string c):
    CollidingEntity(c)
{
    key = "food";
    texture_size = size;
    pos = starting_position;

}

ent::Food::~Food() {}


void ent::Food::setSizeTexture(const Vector2D<float> v)
{
    texture_size = v;
}
void ent::Food::setSizeTexture(const float x, const float y)
{
    texture_size = VF(x,y);
}

void ent::Food::setTexture (const string t)
{
    path = t;
    control->setTexture(key, path);
}
void ent::Food::InitialUpdate ()
{
    control->setSize(key, texture_size);
    control->setPosition(key, pos);
    control->setTexture(key, path);
}
void ent::Food::UpdatePosition()
{
    pos = control->getPosition(key);
}
void ent::Food::UpdateGerenciador ()
{

}
void ent::Food::Update ()
{
    control->setSize(key, texture_size);
    control->setPosition(key, pos);
}
void ent::Food::Draw ()
{
    control->Draw(key);
}
