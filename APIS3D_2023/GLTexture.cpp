#include "GLTexture.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

GLTexture::GLTexture(const char* fileName)
{
	load(fileName);
}

void GLTexture::load(const char* fileName)
{
	pixels = (color32_t*)stbi_load(fileName, &width, &height, &comp, 4);

	glGenTextures(1, &textID);
	glBindTexture(GL_TEXTURE_2D, textID); //el bind sirve para decir que el resto de
	//instrucciones que vienen se ejecutan sobre esta textura que acabo de crear
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);//permite ejecutar los filtros en las texturas
	//1.param: tipo de imagen que se tiene
	//2.param: tipo o atributo que estas retocando, MIN_FILTER-MAX_FILTER (redimensionamiento hacerlo más grande o más pequeño)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);//carga a la GPU


	stbi_image_free(pixels);
}

GLuint GLTexture::getId()
{
	return textID;
}

glm::ivec2 GLTexture::getSize()
{
	return glm::ivec2(width,height);
}

void GLTexture::bind(GLuint textureUnit)
{
	glBindTexture(GL_TEXTURE_2D, getId());//se activa
	glActiveTexture(GL_TEXTURE0 + textureUnit);
}
