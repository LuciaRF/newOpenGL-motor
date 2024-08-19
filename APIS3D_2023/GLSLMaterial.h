#pragma once
#define GLAD_ONLY_HEADERS
#include "Material.h"
#include "vertex_t.h"
#include "System.h"
#include "renderTypes_e.h"
class GLSLMaterial: public Material
{
public:
	GLSLMaterial();
	void addSrc(std::string programName, renderTypes_e type) override;
	void loadPrograms() override;
	void prepare() override;

	RenderProgram* getProgram() override;
	void setProgram(RenderProgram* prg) override;

	Texture* getTexture() override;
	void setTexture(Texture* texture) override;
};

