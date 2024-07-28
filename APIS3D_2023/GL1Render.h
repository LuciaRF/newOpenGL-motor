#pragma once
#define GLAD_ONLY_HEADERS
#include "common.h" 
#include "Object.h"
#include "Render.h"

class GL1Render : public Render
{
public:
	GL1Render(int width, int height);

	int getWidth() override;
	void setWidth(int width) override;
	int getHeight() override;
	void setHeight(int height) override;
	GLFWwindow* getWindow() override;
	void setWindow(GLFWwindow* window) override;

	void init() override;
	void setupObject(Object& obj) override;
	void removeObject(Object& obj) override;
	void drawObjects(std::vector<Object*>* objs) override;
	bool isClosed() override;
};

