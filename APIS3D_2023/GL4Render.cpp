#include "GL4Render.h"

GL4Render::GL4Render(int width, int height): GL1Render(width, height) {}

void GL4Render::setupObject(Object& obj)
{
    boIDS_t vbo;

    glGenVertexArrays(1, &vbo.id);

    glGenBuffers(1, &vbo.vbo);
    glGenBuffers(1, &vbo.idxbo);

    glBindBuffer(GL_ARRAY_BUFFER, vbo.vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(unsigned int) * obj.getMesh().getvTriangleIdxList()->size(), //vertices = lista indices
        obj.getMesh().getvTriangleIdxList()->data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo.idxbo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * obj.getMesh().getvTriangleIdxList()->size(),
        obj.getMesh().getvTriangleIdxList()->data(), GL_STATIC_DRAW);

    bufferObjectList[obj.getMesh().getMeshID()] = vbo; //id de la mesh? poligono en la de clase
}

void GL4Render::removeObject(Object& obj)
{

}

void GL4Render::drawObjects(std::vector<Object*>* objs)
{
    for (auto obj : *objs)
    {
        //actualizar matriz modelo
        obj->computeModelMatrix();

        //activar buffers (en el render porque son los shaders)
        boIDS_t buffer = this->bufferObjectList[obj->getMesh().getMeshID()];

        glBindVertexArray(buffer.id);
        glBindBuffer(GL_ARRAY_BUFFER, buffer.vbo);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer.idxbo);

        obj->getMesh().getMaterial()->prepare(); //setea program use y las variables atributo

        glDrawElements(GL_TRIANGLES, obj->getMesh().getvTriangleIdxList()->size(), 
            GL_UNSIGNED_INT, nullptr);
    }
}



