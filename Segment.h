#ifndef INCLUDED_SEGMENT_H
#define INCLUDED_SEGMENT_H

#include "CollidingEntity.h"

namespace ent {
    class Segment : public CollidingEntity
    {
    private:
        float s;
    public:
        Segment(const string c = "");
        ~Segment();

        void setSizeTexture(const Vector2D<float> v);
        void setSizeTexture(const float x, const float y);
        const Vector2D<float> getSizeTexture() const;

        void setTexture (const string t);
        void InitialUpdate ();
        void UpdatePosition();
        void UpdateGerenciador ();
        void Update ();
        void Draw ();
    };
}

#endif // INCLUDED_SEGMENT_H
