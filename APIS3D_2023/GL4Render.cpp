#include "GL4Render.h"

GL4Render::GL4Render(int width, int height): GL1Render(width, height) {}

void GL4Render::setupObject(Object& obj)
{
    boIDS_t vbo;
    int cont = (int)obj.getMeshes().size();

    glGenVertexArrays(1, &vbo.id);

    glGenBuffers(1, &vbo.vbo);
    glGenBuffers(1, &vbo.idxbo);

    glBindBuffer(GL_ARRAY_BUFFER, vbo.vbo);

    for (int i = 0; i < cont; i++)
    {
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_t) * obj.getMeshes()[i]->getVertList().size(), //vertices = lista indices
            obj.getMeshes()[i]->getVertList().data(), GL_STATIC_DRAW);
    }
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo.idxbo);

    for (int i = 0; i < cont; i++)
    {
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * obj.getMeshes()[i]->getvTriangleIdxList()->size(),
            obj.getMeshes()[i]->getvTriangleIdxList()->data(), GL_STATIC_DRAW);

        bufferObjectList[obj.getMeshes()[i]->getMeshID()] = vbo;
    }
}

void GL4Render::removeObject(Object& obj)
{

}

void GL4Render::drawObjects(std::vector<Object*>* objs)
{
    for (auto& obj : *objs)
    {
        //actualizar matriz modelo
        obj->computeModelMatrix();
        int cont = (int)obj->getMeshes().size();

        auto model = obj->getModelMtx();
        System::setModelMatrix(obj->getModelMtx());
        
        //System::setModelMatrix(obj->getModelMtx());
        //activar buffers (en el render porque son los shaders)

        for (int i = 0; i < cont; i++)
        {
            boIDS_t buffer = this->bufferObjectList[obj->getMeshes()[i]->getMeshID()];

            glBindVertexArray(buffer.id);
            glBindBuffer(GL_ARRAY_BUFFER, buffer.vbo);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer.idxbo);

            obj->getMeshes()[i]->getMaterial()->prepare(); //setea program use y las variables atributo

            glDrawElements(GL_TRIANGLES, obj->getMeshes()[i]->getvTriangleIdxList()->size(),
                GL_UNSIGNED_INT, nullptr);
        }

    }
}



