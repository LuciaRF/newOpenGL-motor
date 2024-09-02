#include "Camera.h"
#include "System.h"

Camera::Camera(ProjectionType type, glm::vec3 position, glm::vec3 up, glm::vec3 lookAt)
{
    glm::mat4 viewMatrix = glm::mat4(1.0f); //matriz vista para sus posiciones
    glm::mat4 projMatrix = glm::mat4(1.0f);; //matriz proyeccion
    setPosition(glm::vec4(position, 1.0f));
    setRotation(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
    setScaling(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
    setModelMtx(glm::mat4(1.0f));
    this->up = up;
    this->lookAt = lookAt;

    computeProjectionMatrix();

    radio = lookAt - (glm::vec3)position;
}

glm::vec4 Camera::getPosition()
{
    return position;
}

void Camera::setPosition(glm::vec4 position)
{
    this->position = position;
}

glm::mat4 Camera::getProjection()
{

    return projection;
}

glm::mat4 Camera::getView()
{
    return view;
}

void Camera::setView(glm::mat4 view)
{
    this->view = view;
}

void Camera::setLookAt(glm::vec3 lookAt)
{
    this->lookAt = lookAt;
}

float Camera::getAngle()
{
    return angle;
}

glm::vec3 Camera::getRadio()
{
    return radio;
}

void Camera::computeProjectionMatrix()
{
    float width = System::render->getWidth();
    float height = System::render->getHeight();
    float resolution = width / height; //640.0f/480.0f

    projection = glm::perspective(glm::radians(getAngle()), 
        resolution, 0.1f, 100.0f);
   
    //lo de render del tamaño habría que ver si lo hace bien HAY QUE PONER LO DE LA VENTANA WINDOW
}

void Camera::computeViewMatrix()
{
    setView(glm::lookAt((glm::vec3)position, lookAt, up)); //calcula matriz vista
    view;
}

glm::vec4 Camera::getRotation()
{
    return rotation;
}

void Camera::setRotation(glm::vec4 rotation)
{
    this->rotation = rotation;
}

glm::vec4 Camera::getScaling()
{
    return scaling;
}

void Camera::setScaling(glm::vec4 scaling)
{
    this->scaling = scaling;
}

glm::mat4 Camera::getModelMtx()
{
    return modelMtx;
}

void Camera::setModelMtx(glm::mat4 modelMtx)
{
    this->modelMtx = modelMtx;
}

void Camera::computeModelMatrix()
{
    glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(position));
    model = glm::rotate(model, rotation.x, glm::vec3(1.0f, 0.0f, 0.0f)); //modelo que rota, angulo por el que rota, rotacion
    model = glm::rotate(model, rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::rotate(model, rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));
    model = glm::scale(model, glm::vec3(scaling));

    this->modelMtx = model;
}
