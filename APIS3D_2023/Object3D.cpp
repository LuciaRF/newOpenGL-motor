#include "Object3D.h"

//Entity

glm::vec4 Object3D::getPosition()
{
	return position;
}

void Object3D::setPosition(glm::vec4 position)
{
	this->position = position;
}

glm::vec4 Object3D::getRotation()
{
	return rotation;
}

void Object3D::setRotation(glm::vec4 rotation)
{
	this->rotation = rotation;
}

glm::vec4 Object3D::getScaling()
{
	return scaling;
}

void Object3D::setScaling(glm::vec4 scaling)
{
	this->scaling = scaling;
}

glm::mat4 Object3D::getModelMtx()
{
	return modelMtx;
}

void Object3D::setModelMtx(glm::mat4 modelMtx)
{
	this->modelMtx = modelMtx;
}

void Object3D::computeModelMatrix()
{
	glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(position));
	model = glm::rotate(model, rotation.x, glm::vec3(1.0f, 0.0f, 0.0f)); //modelo que rota, angulo por el que rota, rotacion
	model = glm::rotate(model, rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
	model = glm::rotate(model, rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));
	model = glm::scale(model, glm::vec3(scaling));

	this->modelMtx = model;// el seteado se hace con setModelMtx??
}

void Object3D::step(float deltaTime)
{
	//El step lo modifica la clase del objeto que herede
}

//Object

//Mesh3D& Object3D::getMesh()
//{
//	return this->mesh;
//}
//
//void Object3D::setMesh(Mesh3D& mesh)
//{
//	this->mesh = mesh;
//
//}

vector<Mesh3D*>& Object3D::getMeshes()
{
	return meshes;
}

void Object3D::setMesh(Mesh3D& mesh)
{
	meshes.push_back(&mesh); //lo de & habría que mirarlo
}

int Object3D::getTipo()
{
	return tipo;
}

void Object3D::setTipo(int tipo)
{
	this->tipo = tipo;
}

template <typename T> //sirve para dividir las , de la lista de msh
std::vector<T> splitString(const std::string& str, char delim) {
    std::vector<T> elems;
    std::stringstream sstream(str);
    std::string item;
    T tipoDato;
    if (str != "") {
        while (std::getline(sstream, item, delim))
        {
            std::istringstream str(item);
            str >> tipoDato;
            elems.push_back(tipoDato);
        }
    }
    return elems;
}

void Object3D::loadDataFromFile(const char* fileName)
{
    string pathFileName = extractPath(fileName);

    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(fileName);
    if (result)
    {
        pugi::xml_node buffersNode = doc.child("mesh").child("buffers");

        for (pugi::xml_node bufferNode = buffersNode.child("buffer");
            bufferNode;
            bufferNode = bufferNode.next_sibling("buffer"))
        {
            Mesh3D* mesh = new Mesh3D();

            //Iteramos por todos los buffers
            Texture* texture = new GLTexture(bufferNode.child("material").child("texture").text().as_string());
            Material* material = FactoryEngine::getNewMaterial();
            material->setTexture(texture);

            auto textureName = bufferNode.child("material").child("texture").text().as_string();

            material->addSrc(bufferNode.child("material").child("vShader").text().as_string(), renderTypes_e::vertex);
            material->addSrc(bufferNode.child("material").child("fShader").text().as_string(), renderTypes_e::fragment);
            material->loadPrograms();

            mesh->setMaterial(material);

            std::vector<float> vList = splitString<float>(bufferNode.child("coords").text().as_string(), ',');
            std::vector<float> tcList = splitString<float>(bufferNode.child("texCoords").text().as_string(), ',');

            auto coord = vList.begin();
            auto texCoord = tcList.begin();

            while (coord != vList.end() && texCoord != tcList.end())
            {
                vertex_t v;
                v.pos.x = *coord++;
                v.pos.y = *coord++;
                v.pos.z = *coord++;
                v.pos.w = 1.0f;

                v.vText.x = *texCoord++;
                v.vText.y = *texCoord++;

                v.color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);

                mesh->addVertex(v);
            }

            vector<unsigned int> indices = splitString<unsigned int>(bufferNode.child("indices").text().as_string(), ',');
            mesh->setvTriangleIdxList(indices);
            setMesh(*mesh);
        }
    }
    else
    {
        //No se ha ppodido cargar
        std::cout << result.description() << std::endl;
    }
}



string Object3D::extractPath(std::string filename) {
    while (filename.find('\\') != std::string::npos)
        filename.replace(filename.find('\\'), 1, 1, '/');
    size_t pos = filename.rfind('/');
    if (pos == std::string::npos) return "";
    filename = filename.substr(0, pos);
    if (filename.size() > 0) filename += '/';
    return filename;
}
