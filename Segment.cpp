#include "Segment.h"

ent::Segment::Segment(const string c):
    CollidingEntity(c)
{

}

ent::Segment::~Segment() {}

void ent::Segment::setSizeTexture(const Vector2D<float> v)
{
    texture_size = v;
}
void ent::Segment::setSizeTexture(const float x, const float y)
{
    texture_size = Vector2D<float>(x,y);
}

const Vector2D<float> ent::Segment::getSizeTexture() const {
    return texture_size;
}

void ent::Segment::setTexture (const string t)
{
    path = t;
    control->setTexture(key, path);
}
void ent::Segment::InitialUpdate ()
{
    control->setSize(key, texture_size);
    control->setPosition(key, pos);
    //control->setTexture(key, path);
}
void ent::Segment::UpdatePosition()
{
    pos = control->getPosition(key);
}
void ent::Segment::UpdateGerenciador ()
{

}
void ent::Segment::Update ()
{
    control->setSize(key, texture_size);
    control->setPosition(key, pos);
}
void ent::Segment::Draw ()
{
    control->Draw(key);
}
