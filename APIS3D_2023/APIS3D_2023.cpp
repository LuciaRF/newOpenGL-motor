#include <iostream>
#include "common.h"
#include <math.h>
#include "TrianguloRot.h"
#include "FactoryEngine.h"
#include "System.h"

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

    FactoryEngine::setSelectedGraphicsBackend(FactoryEngine::GL1);
    FactoryEngine::setSelectedInputBackend(FactoryEngine::GLFW);
    System::initSystem();

    TrianguloRot triangulo;
    triangulo.setPosition(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
    triangulo.step(0.1f);
    System::addObject(&triangulo);

    System::mainLoop();
}
