#include "common.h"
#include "TrianguloRot.h"
#include "CubeTex.h"
#include "FactoryEngine.h"
#include "CameraKeyboard.h"

using namespace std;

int main(int argc, char** argv)
{
   /* Mesh3D meshClass;
    vector<vertex_t>& vertices = meshClass.getVertList();

    Mesh3D * myMesh = new Mesh3D();
    Mesh3D * myMesh2 = new Mesh3D();

    std::cout << "\nEl ID de la mesh0: ";
    std::cout << meshClass.getMeshID();
    std::cout << "\nMostrar posicion: \n";
    for (const auto& vertex : vertices) {
        std::cout << "Vertex Position: ("
            << vertex.pos.x << ", "
            << vertex.pos.y << ", "
            << vertex.pos.z << ", "
            << vertex.pos.w << ")\n";
    }

    std::cout << "\nEl ID de la mesh1: ";
    std::cout << myMesh->getMeshID();
    std::cout << "\nEl ID de la mesh2: ";
    std::cout << myMesh2->getMeshID() << endl;*/

    int width = 640;
    int height = 480;

    FactoryEngine::setSelectedGraphicsBackend(FactoryEngine::GL4);
    FactoryEngine::setSelectedInputBackend(FactoryEngine::GLFW);
    System::initSystem(width, height);

    //TrianguloRot triangulo;
    //TrianguloRot triangulo2;

    //triangulo.setPosition(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
    //System::addObject(&triangulo);

    CubeTex cube("data/front.png");
    cube.setPosition(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
    System::addObject(&cube);

    auto type = Camera::ProjectionType::Perspective;

    CameraKeyboard camera(type, glm::vec3(0.0f, 0.0f, 3.0f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(cube.getPosition()));

    System::setCamera(&camera);

    System::mainLoop();
}
