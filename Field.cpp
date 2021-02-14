#include "Field.h"

Field::Field(const float block_size, const unsigned int x, const unsigned int y, const float spacing):
    field(),
    bs(x,y)
{
    ent::Segment* wall1 = new ent::Segment();
    ent::Segment* wall2 = new ent::Segment();
    ent::Segment* wall3 = new ent::Segment();
    ent::Segment* wall4 = new ent::Segment();
    wall1->setSizeTexture(block_size * x + spacing * (x-1) + 2*WALL_WIDTH, WALL_WIDTH);
    wall2->setSizeTexture(WALL_WIDTH, block_size * y + spacing * (y-1));
    wall3->setSizeTexture(WALL_WIDTH, block_size * y + spacing * (y-1));
    wall4->setSizeTexture(block_size * x + spacing * (x-1) + 2*WALL_WIDTH, WALL_WIDTH);
    wall1->setPosition((block_size * x + spacing * (x-1))/2 + WALL_WIDTH, WALL_WIDTH/2.0);
    wall2->setPosition(WALL_WIDTH/2.0, (block_size * y + spacing * (y-1))/2 + WALL_WIDTH);
    wall3->setPosition(block_size * x + spacing * (x-1) + 3*WALL_WIDTH/2.0, (block_size * y + spacing * (y-1))/2 + WALL_WIDTH);
    wall4->setPosition((block_size * x + spacing * (x-1))/2 + WALL_WIDTH, block_size * y + spacing * (y-1) + 3*WALL_WIDTH/2.0);
    wall1->setKey("wall");
    wall2->setKey("wall");
    wall3->setKey("wall");
    wall4->setKey("wall");

    field.push_back(wall1);
    field.push_back(wall2);
    field.push_back(wall3);
    field.push_back(wall4);

}

Field::~Field() {
    unsigned int i;
    for(i = 0; i < field.size(); i++) {
        delete field[i];
    }
    field.clear();
}

void Field::Draw() {
    unsigned int i;
    for(i = 0; i < field.size(); i++) {
        field[i]->Update();
        field[i]->Draw();
    }
}

const VF Field::limitsX() const {
    return VF(field[1]->getPosition().x + WALL_WIDTH/2, field[2]->getPosition().x - WALL_WIDTH/2);
}

const VF Field::limitsY() const {
    return VF(field[0]->getPosition().y + WALL_WIDTH/2, field[3]->getPosition().y - WALL_WIDTH/2);
}

const VU Field::getBlockSize() const {
    return bs;
}

void Field::centralize(const VF center) {
    VF pcenter;
    VF lx = limitsX(),ly = limitsY();
    pcenter.x = center.x - (lx.y - lx.x)/2;
    pcenter.y = center.y - (ly.y - ly.x)/2;
    unsigned int i;
    for(i = 0; i < field.size(); i++) {
        field[i]->setPosition(field[i]->getPosition() + pcenter);
    }
}

const VF Field::getCenter() const {
    return VF((limitsX().y - limitsX().x)/2, (limitsY().y - limitsY().x)/2);
}
