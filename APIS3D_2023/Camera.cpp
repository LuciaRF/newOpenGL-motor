#include "Camera.h"

Camera::Camera(glm::mat4 view, glm::mat4 projection, glm::vec3 up, glm::vec3 lookAt)
{
    this->view = view;
    this->projection = projection;
    this->up = up;
    this->lookAt = lookAt;
}

glm::mat4 Camera::getProjection()
{
    return projection;
}

glm::mat4 Camera::getView()
{
    return view;
}

void Camera::computeProjectionMatrix()
{

    //projection = glm::perspective(glm::radians(angle), 4.0f / 3.0f, 0.1f, 100.0f);
    //el 4/3 debería ser la relacion de la ventana que ponemos en el render
    //ancho/alto
}

void Camera::computeViewMatrix()
{
    this->view = glm::lookAt((glm::vec3)position, lookAt, up); //calcula matriz vista
}
