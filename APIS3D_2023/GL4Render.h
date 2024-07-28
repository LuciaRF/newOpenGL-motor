#pragma once
#define GLAD_ONLY_HEADERS
#include "common.h" 
#include "GL1Render.h"

class GL4Render : public GL1Render
{
public:
	typedef struct boIDS_t
	{
		unsigned int id;
		unsigned int vbo;
		unsigned int idxbo;
	}boIDS_t;
	std::map<glm::uint32, boIDS_t> bufferObjectList; //int o uint32?

	GL4Render(int width, int height);
	void setupObject(Object& obj) override;
	void removeObject(Object& obj) override;
	void drawObjects(std::vector<Object*>* objs) override;
};

