#include "CameraKeyboard.h"

CameraKeyboard::CameraKeyboard(ProjectionType type, glm::vec3 position, glm::vec3 up, glm::vec3 lookAt) :
	Camera(type, position, up, lookAt) {}

void CameraKeyboard::step(float deltaTime)
{
	static double prevX = 0, prevY = 0;
	std::cout << getPosition().x << " " << getPosition().y << " " << getPosition().z << endl;
	/*
		El método step consultará el estado del teclado en la clase “InputManager” a través de la clase 
		estática “System”. Se debe poder mover en 3 dimensiones y girar el punto de mira respecto de 
		la posición de la cámara
	*/

	float speedMX = 0;
	float speedMY = 0;
	glm::vec4 position = getPosition();
	glm::vec4 rotation = getRotation();

	glm::vec3 movement = glm::vec3(0.0f);
	float velocity = 0.1f;

	//Más adelante hay que modificar el mov del ratón FALTA PARTE DE RATÓN

	if (System::inputManager->isPressed(GLFW_KEY_A)) movement.x += 0.01f;
	if (System::inputManager->isPressed(GLFW_KEY_D)) movement.x -= 0.01f;
	if (System::inputManager->isPressed(GLFW_KEY_Z)) movement.y += 0.01f;
	if (System::inputManager->isPressed(GLFW_KEY_X)) movement.y -= 0.01f;
	if (System::inputManager->isPressed(GLFW_KEY_W)) movement.z += 0.01f;
	if (System::inputManager->isPressed(GLFW_KEY_S)) movement.z -= 0.01f;

	if (movement.x != 0.0f || movement.y != 0.0f || movement.z != 0.0f)
	{
		// Vector de la camara mirando a la posicion del lookAt
		glm::vec3 CP = getLookAt() - glm::vec3(position);
		CP.y = 0;

		// Vector directores frontal y derecho del personaje
		glm::vec3 CPforward = normalizeVector(CP);
		glm::vec3 CPright = (-1.0f) * glm::vec3(-CPforward.z, 0, CPforward.x);

		// Vector de movimiento asociado al world
		glm::vec3 mov = CPforward * movement.z + CPright * movement.x;
		glm::vec3 realMovement = normalizeVector(mov) * glm::vec3(deltaTime) * velocity;

		// Combinamos con la posicion
		position.x += realMovement.x;
		position.y += movement.y * deltaTime * velocity;
		position.z += realMovement.z;
		setPosition(position);
		
	}

	//ROTATION

	speedMY = prevY - GLFWInputManager::posY;
	prevY = GLFWInputManager::posY;
	rotation.x += speedMY * 0.001f; //mover el ratón

	speedMX = prevX - GLFWInputManager::posX;
	prevX = GLFWInputManager::posX;
	rotation.y += speedMX * 0.001f; //mover el ratón

	setRotation(rotation);

	glm::vec3 lookAt = glm::rotate(glm::mat4(1.0f), rotation.y, glm::vec3(0.0f, 1.0f, 0.0f))*
		glm::rotate(glm::mat4(1.0f), rotation.x, glm::vec3(1.0f, 0.0f, 0.0f))*
		glm::vec4(getRadio(), 1.0f); //me da lo que he girado en el 0,0 ahora tengo que desplazarme
	lookAt += glm::vec3(position);
	setLookAt(lookAt);

	computeViewMatrix(); //esto lo hace y se guarda?
}

glm::vec3 CameraKeyboard::normalizeVector(glm::vec3& v)
{
	if (v.x == 0 && v.y == 0 && v.z == 0) return v;
	float length_of_v = sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
	return glm::vec3(v.x / length_of_v, v.y / length_of_v, v.z / length_of_v);
}
