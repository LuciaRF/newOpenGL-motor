#pragma once
#define GLAD_ONLY_HEADERS
#include "common.h"
#include "renderTypes_e.h"

class Shader
{
private:
	unsigned int shId; //Identificador de shader
	std::string fileName;
	GLenum type;
	char* source;
public:

	Shader(std::string fileName, renderTypes_e type);
	void readSource();
	void compileShader();
	void checkErrors();
	void clean() {}; //Una vez todo compilado puedo liberar memoria

	unsigned int getShID();
};

