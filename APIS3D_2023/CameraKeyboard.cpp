#include "CameraKeyboard.h"

CameraKeyboard::CameraKeyboard(ProjectionType type, glm::vec3 position, glm::vec3 up, glm::vec3 lookAt) :
	Camera(type, position, up, lookAt) {}

void CameraKeyboard::step(float deltaTime)
{
	/*
		El método step consultará el estado del teclado en la clase “InputManager” a través de la clase 
		estática “System”. Se debe poder mover en 3 dimensiones y girar el punto de mira respecto de 
		la posición de la cámara
	*/

	static double prevX = 0, prevY = 0;
	float speedMX = 0;
	float speedMY = 0;
	glm::vec4 position = getPosition();
	glm::vec4 rotation = getRotation();

	//Más adelante hay que modificar el mov del ratón FALTA PARTE DE RATÓN

	if (System::inputManager->isPressed(GLFW_KEY_A)) position.x -= 0.01f;
	if (System::inputManager->isPressed(GLFW_KEY_D)) position.x += 0.01f;
	if (System::inputManager->isPressed(GLFW_KEY_W)) position.y += 0.01f;
	if (System::inputManager->isPressed(GLFW_KEY_S)) position.y -= 0.01f;
	if (System::inputManager->isPressed(GLFW_KEY_Q)) position.z += 0.01f;
	if (System::inputManager->isPressed(GLFW_KEY_R)) position.z -= 0.01f;

	setPosition(position);

	//ROTATION

	//speedMX = prevX - GLFWInputManager::getMouseX();
	//prevX = GLFWInputManager::getMouseX();
	//rotation.y += speedMX * 0.001f;

	//speedMY = prevY - GLFWInputManager::getMouseY();
	//prevY = GLFWInputManager::getMouseY();
	//rotation.x += speedMY * 0.001f;
	//setRotation(rotation);

	glm::vec3 lookAt = glm::rotate(glm::mat4(1.0f), rotation.y, glm::vec3(0.0f, 1.0f, 0.0f))*
		glm::rotate(glm::mat4(1.0f), rotation.x, glm::vec3(1.0f, 0.0f, 0.0f))*
		glm::vec4(getRadio(), 1.0f); //me da lo que he girado en el 0,0 ahora tengo que desplazarme
	lookAt += glm::vec3(position);
	setLookAt(lookAt);

	computeViewMatrix(); //esto lo hace y se guarda?
}
