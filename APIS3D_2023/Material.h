#pragma once
#define GLAD_ONLY_HEADERS
#include "common.h"
#include "GLSLShader.h"
#include "Texture.h"

class Material
{
protected:
	RenderProgram* program;
	/*Puntero a una implementación de programas de renderizado (en 
nuestro caso, shaders). ¡¡OJO!! Deberá ser inicializado por el constructor de la 
clase que implemente un Material setea prID? */
	std::vector<std::string> listProgramSrc;
	std::vector<renderTypes_e> listType;

	Texture* texture;
public:
	virtual void addSrc(std::string programName, renderTypes_e type) = 0;
	virtual void loadPrograms() = 0;
	/*nombre del programa que lo carga*/
	virtual void prepare() = 0;

	virtual RenderProgram* getProgram() = 0;
	virtual void setProgram(RenderProgram* prg) = 0;

	virtual Texture* getTexture() = 0;
	virtual void setTexture(Texture* texture) = 0;
}; 

