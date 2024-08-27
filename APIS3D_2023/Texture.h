#pragma once
#define GLAD_ONLY_HEADERS
#include "common.h" 

typedef struct color32_t {
	unsigned char r, g, b, a;
}v;

class Texture
{
public:

	int width, height, comp;
	color32_t* pixels = nullptr;
	GLuint textID;

	virtual void load(const char* fileName) = 0;
	virtual GLuint getId() = 0;
	virtual glm::ivec2 getSize() = 0;
	virtual void bind(GLuint textureUnit) = 0;
};

