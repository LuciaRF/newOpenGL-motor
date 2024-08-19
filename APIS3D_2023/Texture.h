#pragma once
#define GLAD_ONLY_HEADERS
#include "common.h" 

class Texture
{
public:
	Texture* texture;//material? o algo que devuelve para el new FactoryEngine

	virtual void load(std::string filename) = 0;
	virtual void getId() = 0;
	virtual glm::ivec2 getSize() = 0;
	virtual void bind() = 0;
};

