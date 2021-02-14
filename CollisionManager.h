#ifndef INCLUDED_COLLISION_MANAGER_H
#define INCLUDED_COLLISION_MANAGER_H

#include "Snake.h"
#include "Food.h"
#include "Field.h"

class CollisionManager
{
private:
    Snake* snake;
    Field* field;
    ent::Food* food;

public:

    CollisionManager();
    ~CollisionManager();

    void setSnake(Snake* s);
    void setField(Field* f);
    void setFood(ent::Food* fd);

    const bool CheckCollision(const VF sum_of_size, const VF pos1, const VF pos2);
    const bool CheckCollisionSnake() const;
    const bool CheckCollisionsField() const;
    const bool CheckCollisionsFood() const;
    void RandomPosiitonForFood();

};


#endif // INCLUDED_COLLISION_MANAGER_H
