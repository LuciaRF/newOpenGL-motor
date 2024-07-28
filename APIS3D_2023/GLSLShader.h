#pragma once
#define GLAD_ONLY_HEADERS
#include "common.h"
#include "RenderProgram.h"
#include "Shader.h"
#include "renderTypes_e.h"

class GLSLShader : public RenderProgram
{
protected:

	
	//std::vector<Shader*> shaderList;
	

public:
	void setProgram(std::string  programSrc, renderTypes_e type) override;
	void linkPrograms() override;
	std::string getErrorMsg() override;
	void use() override;

	/*Métodos para setear variables UNIFORM*/
	void setInt(std::string, int val) override;
	void setFloat(std::string loc, float val) override;
	void setVec3(std::string loc, const glm::vec3& vec) override;
	void setVec4(std::string loc, const glm::vec4& vec) override;
	void setMatrix(std::string loc, const glm::mat4& matrix) override;

	std::map<std::string, unsigned int>& getVarList() override;

	unsigned int getPrID() override;
	void setPrID() override;

	void checkErrors();

	void setupShaderVarList();

};

