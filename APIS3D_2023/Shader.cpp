#include "Shader.h"

Shader::Shader(std::string fileName, renderTypes_e type)
{
	this->fileName = fileName;

	/*addshader según el tipo de program que sea*/
	if (renderTypes_e::vertex == type)
	{
		this->type = GL_VERTEX_SHADER;
	}
	else if (renderTypes_e::fragment == type)
	{
		this->type = GL_FRAGMENT_SHADER;
	}
	else
	{
		this->type = -1;
	}

	readSource();
	compileShader();
	checkErrors();
}

void Shader::readSource()
{
	std::streampos size;

	std::ifstream file(fileName, std::ios::in | std::ios::binary | std::ios::ate);
	if (file.is_open())
	{
		size = file.tellg();
		this->source = new char[size + std::streampos(1)];
		file.seekg(0, std::ios::beg);
		file.read(source, size);
		source[size] = '\0';
		file.close();
	}
	else std::cout << "Unable to open file";
}

void Shader::compileShader()
{
	this->shId = glCreateShader(this->type); //crear shader
	glShaderSource(shId, 1, &source, nullptr); //compilar el codigo shader que se ha creado con source
	glCompileShader(shId); //compilar el shader
}

void Shader::checkErrors()
{
	GLint fragment_compiled;
	glGetShaderiv(shId, GL_COMPILE_STATUS, &fragment_compiled);
	if (fragment_compiled != GL_TRUE)
	{
		GLsizei log_length = 0;
		GLchar message[1024];
		glGetShaderInfoLog(shId, 1024, &log_length, message);
		std::cout << "ERROR " << fileName << "\n" << message << "\n\n";
	}
}

unsigned int Shader::getShID()
{
	return shId;
}
