#include "GLSLMaterial.h"

GLSLMaterial::GLSLMaterial() 
{
    program = new GLSLShader();
    program->setPrID();
}

void GLSLMaterial::addSrc(std::string programName, renderTypes_e type)
{
    listProgramSrc.push_back(programName);
    listType.push_back(type);
}

void GLSLMaterial::loadPrograms()
{
    int count = listProgramSrc.size();
    for (int i = 0; i<count;i++)
    {
        program->setProgram(listProgramSrc[i],listType[i]);
    }

    program->linkPrograms();
}


void GLSLMaterial::prepare()
{
    program->use();

    glEnableVertexAttribArray(program->getVarList()["vPos"]);
    glVertexAttribPointer(program->getVarList()["vPos"], 4, GL_FLOAT, GL_FALSE, sizeof(vertex_t), (void*)0x00); //ultimo param: es el primero y empieza en cero 


   /* glEnableVertexAttribArray(p.prg->varList["vcolor"]);
    glVertexAttribPointer(p.prg->varList["vcolor"], 4, GL_FLOAT, GL_FALSE, sizeof(vertex_t), (void*)(sizeof(glm::vec4)));*/ //ultimo param: lo que ocupe vpos
    auto model = System::getModelMatrix();
    program->setMatrix("mMat", System::getModelMatrix());

    //modificar para hacer el uso de texturas
}

RenderProgram* GLSLMaterial::getProgram()
{
    return program;
}
void GLSLMaterial::setProgram(RenderProgram* prg)
{
    program = prg;
}

Texture* GLSLMaterial::getTexture()
{
    return texture;
}

void GLSLMaterial::setTexture(Texture* texture)
{
    this->texture = texture;
}

