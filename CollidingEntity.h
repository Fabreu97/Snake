#ifndef INCLUDED_COLLIDING_ENTITY_H
#define INCLUDED_COLLIDING_ENTITY_H

#include "Entity.h"

namespace ent{
    class CollidingEntity: public Entity {
        protected:

            bool collided;
            Vector2D<float> colliding_size;

        public:

            CollidingEntity(const string c = "");
            virtual ~CollidingEntity();

            void setColisao(const bool c);
            const bool getColisao() const;

            void setSize(const Vector2D<float> v);
            void setSize(const float x, const float y);
            Vector2D<float> getSize() const;
            const Vector2D<float> getHalfSize() const;
            virtual void UpdatePosition() = 0;
    };
}

#endif // INCLUDED_COLLIDING_ENTITY_H
