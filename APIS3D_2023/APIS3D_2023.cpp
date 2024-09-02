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

    //CubeTex cube;
    //CubeTex cube("data/lightCube.msh");
    CubeTex cube("data/asian_town.msh");
    cube.setPosition(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
    System::addObject(&cube);

    //Asian Town

    //CubeTex cube("data/asian_town.msh");
    glm::vec3 positionCamera = glm::vec3(0.12f, 0.013f, 0.142f);
    //cube.setPosition(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));

    auto type = Camera::ProjectionType::Perspective;

    CameraKeyboard camera(type, positionCamera,
        glm::vec3(0.0f, 2.0f, 0.0f),
        glm::vec3(cube.getPosition()));

    System::setCamera(&camera);

    System::mainLoop();
}
