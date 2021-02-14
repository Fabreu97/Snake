#ifndef INCLUDED_FIELD_H
#define INCLUDED_FIELD_H

#include "Segment.h"
#include <vector>

#define WALL_WIDTH 10.0f

class Field {
private:
    vector<ent::Segment*> field;
    VU bs;

public:
    Field(const float block_size = 40.0f, const unsigned int x = 15u, const unsigned int y = 15u, const float spacing = 0.0f);
    ~Field();

    void Draw();
    const VF limitsX() const; //TO DO
    const VF limitsY() const;
    const VU getBlockSize() const;

    void centralize(const VF center);// TO DO
    const VF getCenter() const; //TO DO
};

#endif // INCLUDED_CAMP_H
