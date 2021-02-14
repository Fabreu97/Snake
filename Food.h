#ifndef INCLUDED_FOOD_H
#define INCLUDED_FOOD_H

#include "CollidingEntity.h"
namespace ent
{
    class Food : public CollidingEntity
    {
    public:

        Food(const VF starting_position, const VF size, const string c = "");
        ~Food();

        void setSizeTexture(const Vector2D<float> v);
        void setSizeTexture(const float x, const float y);

        void setTexture (const string t);
        void InitialUpdate ();
        void UpdatePosition();
        void UpdateGerenciador ();
        void Update ();
        void Draw ();
    };
}

#endif // INCLUDED_FOOD_H
