#ifndef INCLUDED_SNAKE_H
#define INCLUDED_SNAKE_H

#define SLEEP 0.11f
#include "Segment.h"
#include "Queue.h"

class Snake {
private:
    unsigned char direction;
    unsigned char previous;
    Queue<ent::Segment*> body;
    static GraphicManager* g;
    float elapsed_time;
    bool ate;
    float bs;
    float spacing;

public:
    Snake (const unsigned int snake_size = 3, const VF starting_position = VF(440.0f, 400.0f), const float block_size = 40.0f, const float spacing = 0.0f);
    ~Snake ();

    static void setGraphicManager(GraphicManager* manager);
    void RelocatePosition(const VF starting_position);
    const float getSpacing () const;

    Queue<ent::Segment*>* getBody();
    const float getBlockSize() const;
    const VF getPosition();
    const VF getSegmentPosition(const unsigned int i);
    const unsigned int getSize() const;
    const VF getSegmentPosition();
    void fullTummy();
    void move ();
    void move2();
    void Draw ();
    const bool different(const VF pos);
};

#endif // INCLUDED_SNAKE_H
