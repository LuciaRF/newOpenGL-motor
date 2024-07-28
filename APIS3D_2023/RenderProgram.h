#pragma once
#define GLAD_ONLY_HEADERS
#include "common.h"
#include "renderTypes_e.h"
#include "Shader.h"

class RenderProgram
{
	/*
	Esta es una clase abstracta “pura” que representará un programa encargado 
	de realizar las tareas de renderizado en un HW especial (GPU en nuestro caso, 
	aunque podría ser cualquier otro tipo de renderizador). Recibirá una lista de código 
	fuente para tratar vértices y fragmentos, lo compilará y creará un programa para poder 
	dibujar más adelante listas de vértices y triángulos.  
	*/
protected:

	static std::string errorMSGs;

	/*Revisar si esto es necesario finalmente*/
	GLenum type;
	char* source;
	unsigned int prId; //Identificador de programa
	//unsigned int shId; //Identificador de shader
	std::vector<Shader*> shaderList; //Lista de los shaders que voy incluyendo para posteriormente linkear
	std::map<std::string, unsigned int> varList;

public:

	virtual void setProgram(std::string  programSrc, renderTypes_e type) = 0;
	virtual void linkPrograms() = 0;
	virtual std::string getErrorMsg() = 0;
	virtual void use() = 0;
	
	/*Métodos para setear variables UNIFORM*/
	virtual void setInt(std::string, int val) = 0;
	virtual void setFloat(std::string loc, float val) = 0;
	virtual void setVec3(std::string loc, const glm::vec3& vec) = 0;
	virtual void setVec4(std::string loc, const glm::vec4& vec) = 0;
	virtual void setMatrix(std::string loc, const glm::mat4& matrix) = 0;

	virtual unsigned int getPrID() = 0;
	virtual void setPrID() = 0; //crea el id de un programa glCreateProgram, hay que llamarlo

	virtual std::map<std::string, unsigned int>& getVarList() = 0;
};
