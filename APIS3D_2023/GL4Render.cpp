#include "GL4Render.h"

GL4Render::GL4Render(int width, int height): GL1Render(width, height) {}

void GL4Render::setupObject(Object& obj)
{
    for (auto mesh : obj.getMeshes())
    {
        boIDS_t vbo;

        glGenVertexArrays(1, &vbo.id);

        glGenBuffers(1, &vbo.vbo);
        glGenBuffers(1, &vbo.idxbo);

        auto ta = mesh->getVertList();

        glBindBuffer(GL_ARRAY_BUFFER, vbo.vbo);

        glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_t) * mesh->getVertList().size(), //vertices = lista indices
            mesh->getVertList().data(), GL_STATIC_DRAW);


        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo.idxbo);


        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * mesh->getvTriangleIdxList().size(),
             mesh->getvTriangleIdxList().data(), GL_STATIC_DRAW);

        bufferObjectList[mesh->getMeshID()] = vbo;
        
    }

}

void GL4Render::removeObject(Object& obj)
{

}

void GL4Render::drawObjects(Object* obj)
{
        //actualizar matriz modelo
        obj->computeModelMatrix();
        //int cont = (int)obj->getMeshes().size();

        //auto model = obj->getModelMtx();
        System::setModelMatrix(obj->getModelMtx());
        
        //System::setModelMatrix(obj->getModelMtx());
        //activar buffers (en el render porque son los shaders)
        for (auto mesh : obj->getMeshes())
        //for (int i = 0; i < cont; i++)
        {
            boIDS_t buffer = this->bufferObjectList[mesh->getMeshID()];

            glBindVertexArray(buffer.id);
            glBindBuffer(GL_ARRAY_BUFFER, buffer.vbo);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer.idxbo);

            mesh->getMaterial()->prepare(); //setea program use y las variables atributo

            glDrawElements(GL_TRIANGLES, mesh->getvTriangleIdxList().size(),
                GL_UNSIGNED_INT, nullptr);
        }
}



