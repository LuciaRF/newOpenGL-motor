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
    int count = (int)listProgramSrc.size();
    for (int i = 0; i<count;i++)
    {
        program->setProgram(listProgramSrc[i],listType[i]);
    }

    program->linkPrograms();
}


void GLSLMaterial::prepare()
{
    program->use();


    auto m = program->getVarList()["vtextcoord"];
    glEnableVertexAttribArray(program->getVarList()["vPos"]);
    glVertexAttribPointer(program->getVarList()["vPos"], 4, GL_FLOAT, GL_FALSE, 
        sizeof(vertex_t), (void*)0x00); //ultimo param: es el primero y empieza en cero 


    //glEnableVertexAttribArray(program->getVarList()["vcolor"]);
    //glVertexAttribPointer(program->getVarList()["vcolor"], 4, GL_FLOAT, GL_FALSE, 
    //    sizeof(vertex_t), (void*)(sizeof(glm::vec4))); //ultimo param: lo que ocupe vpos
    
    glEnableVertexAttribArray(program->getVarList()["vtextcoord"]);
    glVertexAttribPointer(program->getVarList()["vtextcoord"], 2, GL_FLOAT, GL_FALSE,
        //sizeof(vertex_t), (void*)(sizeof(glm::vec4) + sizeof(glm::vec4)));
        sizeof(vertex_t), (void*)offsetof(vertex_t, vText));
        

    getTexture()->bind(0);//ver si está funcionando, y además si lo de hardcodear el 0 tambien
    
    program->setFloat("colorText", 0);

    //camera
    //glm::mat4 MVP = c.projMatrix * c.viewMatrix * p.modelMtx;
    Camera* camera = System::getCamera();
    glm::mat4 MVP = camera->getProjection() * camera->getView() * System::getModelMatrix();

    program->setMatrix("mMat", MVP);

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

