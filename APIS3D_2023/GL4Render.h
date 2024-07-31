#pragma once
#define GLAD_ONLY_HEADERS
#include "common.h" 
#include "GL1Render.h"
#include "System.h"

class GL4Render : public GL1Render
{
public:
	typedef struct boIDS_t
	{
		unsigned int id;
		unsigned int vbo;
		unsigned int idxbo;
	}boIDS_t;
	std::map<int, boIDS_t> bufferObjectList;

	GL4Render(int width, int height);
	void setupObject(Object& obj) override;
	void removeObject(Object& obj) override;
	void drawObjects(std::vector<Object*>* objs) override;
};

