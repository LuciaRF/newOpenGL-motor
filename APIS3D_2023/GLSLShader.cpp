#include "GLSLShader.h"
/*shader + program*/

unsigned int GLSLShader::getPrID()
{
	return prId;
}

void GLSLShader::setPrID()
{
	prId = glCreateProgram();
}

void GLSLShader::setProgram(std::string  programSrc, renderTypes_e type)
{
	/*crea el programa*/
	Shader* sh = new Shader(programSrc, type);
	shaderList.push_back(sh);
}

void GLSLShader::linkPrograms()
{
	use(); //activo el programa ID para luego linkarlo, luego lo actualizaré aquí
	for (auto& sh : shaderList) {
		glAttachShader(prId, sh->getShID());
	}
	glLinkProgram(prId);
	checkErrors(); //checkShaderError

	use();
	setupShaderVarList();
}
std::string GLSLShader::getErrorMsg()
{
	return nullptr;
}

void GLSLShader::use()
{
	glUseProgram(prId);
}

void GLSLShader::setInt(std::string loc, int val)
{
	glUniform1i(varList[loc], val);
}
void GLSLShader::setFloat(std::string loc, float val)
{
	glUniform1f(varList[loc], val);
}
void GLSLShader::setVec3(std::string loc, const glm::vec3& vec)
{
	glUniform3f(varList[loc], vec[0], vec[1], vec[2]);
}
void GLSLShader::setVec4(std::string loc, const glm::vec4& vec)
{
	glUniform4f(varList[loc], vec[0], vec[1], vec[2], vec[3]);
}
void GLSLShader::setMatrix(std::string loc, const glm::mat4& matrix)
{
	glUniformMatrix4fv(varList[loc], 1, GL_FALSE, &matrix[0][0]);
}

std::map<std::string, unsigned int>& GLSLShader::getVarList()
{
	return varList;
}

void GLSLShader::checkErrors()
{
	GLint program_linked;
	glGetProgramiv(prId, GL_LINK_STATUS, &program_linked);
	if (program_linked != GL_TRUE)
	{
		GLsizei log_length = 0;
		GLchar message[1024];
		glGetProgramInfoLog(prId, 1024, &log_length, message);
		std::cout << "ERROR \n" << message << "\n\n";
	}
}

void GLSLShader::setupShaderVarList()
/*Método para interrogar shader y averiguar las variables de tipo uniform  y attribute,
podría cambiar por la de clase*/
{
	//std::map<renderTypes_e, unsigned int> programs; ??
	std::map <std::string, unsigned int > programVarList;
	int count = 0;
	int bufSize = 100;
	char* name = new char[bufSize];
	GLenum type;
	int size = 0;
	int length = 0;
	glGetProgramiv(prId, GL_ACTIVE_ATTRIBUTES, &count);
	printf("Active Attributes: %d\n", count);

	for (int i = 0; i < count; i++)
	{
		glGetActiveAttrib(prId, (GLuint)i, bufSize, &length, &size, &type,
			name);
		programVarList[std::string(name)] = glGetAttribLocation(prId, name);
	}
		glGetProgramiv(prId, GL_ACTIVE_UNIFORMS, &count);
	printf("Active Uniforms: %d\n", count);
	for (int i = 0; i < count; i++)
	{
		glGetActiveUniform(prId, (GLuint)i, bufSize, &length, &size,
			&type, name);
		programVarList[std::string(name)] = glGetUniformLocation(prId,
			name);
	}
}
