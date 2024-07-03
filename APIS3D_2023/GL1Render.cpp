#include "GL1Render.h"

GL1Render::GL1Render(int width, int height)
{
    this->width = width;
    this->height = height;
    window = nullptr;
}

int GL1Render::getWidth()
{
    return width;
}
void GL1Render::setWidth(int width)
{
    this->width = width;
}

int GL1Render::getHeight()
{
    return height;
}

void GL1Render::setHeight(int height)
{
    this->height = height;
}

void GL1Render::init()
{
    if (!glfwInit())
    {
        cout << "ERROR GLWFINIT" << endl;
    }
}

void GL1Render::setupObject(Object* obj)
{

}

void GL1Render::removeObject(Object* obj)
{

}

void GL1Render::drawObjects(std::vector<Object*>* objs)
{
    for (auto& obj : *objs) //esto utiliza copia o el original
    {
        obj->computeModelMatrix();

        glBegin(GL_TRIANGLES);
        //seteos de vertices y colores

        Mesh3D* mesh = obj->getMesh();
        glColor3f(1.0f,1.0f,1.0f);

        for (auto vert : *mesh->getVertList())
        {
            vert.pos = obj->getModelMtx() * vert.pos;
            glVertex3f(vert.pos.x, vert.pos.y, vert.pos.z);
        }

        glEnd();

    }
}

bool GL1Render::isClosed()
{
    return true;
}