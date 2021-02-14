#ifndef INCLUDED_ENTIDADE_H
#define INCLUDED_ENTIDADE_H

#include "GraphicManager.h"
#include "List.h"

using namespace Manager;

namespace ent {
    class Entity
    {
    protected:

        unsigned long int id;
        string key;  //ID for body
        string path; //texture
        Vector2D<float> texture_size;
        Vector2D<float> pos;

        static GraphicManager* control;

    public:

        Entity(const string c = "");
        virtual ~Entity();

        void setID(const unsigned long ID);
        const unsigned long int getID() const;

        void setKey(const string k);
        const string getKey() const;

        virtual void setTexture(const string t) = 0;
        const string getTexture() const;

        virtual void setSizeTexture(const Vector2D<float> v);
        virtual void setSizeTexture(const float x, const float y);
        const Vector2D<float> getSizeTexture() const;

        void setPosition(const Vector2D<float> v);
        void setPosition(const float x, const float y);
        const Vector2D<float> getPosition() const;

        static void setGraphicManager(GraphicManager* pg);
        static GraphicManager* getGraphicManager();

        virtual void InitialUpdate () = 0;
        virtual void UpdateGerenciador () = 0;
        virtual void Update () = 0;
        virtual void Draw () = 0;
    };
}

#endif // INCLUDED_ENTIDADE_H
