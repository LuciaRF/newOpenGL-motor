#pragma once
#define GLAD_ONLY_HEADERS
#include "common.h"
#include "Texture.h"

class GLTexture : public Texture
{
public:

	GLTexture(const char* fileName); //para cuando solo sea color

	void load(const char* fileName) override;
	GLuint getId() override;
	glm::ivec2 getSize() override;
	void bind(GLuint textureUnit) override;
};

