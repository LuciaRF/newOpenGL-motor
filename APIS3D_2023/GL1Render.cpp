 #include "GL1Render.h"

GL1Render::GL1Render(int width, int height) 
{
    this->height = height;
    this->width = width;
}

int GL1Render::getWidth()
{
    return width;
}
void GL1Render::setWidth(int width)
{
    this->width = width;
}

int GL1Render::getHeight()
{
    return height;
}

void GL1Render::setHeight(int height)
{
    this->height = height;
}

GLFWwindow* GL1Render::getWindow()
{
    return window;
}
void  GL1Render::setWindow(GLFWwindow* window)
{
    this->window = window;
}

void GL1Render::init()
{
    if (!glfwInit())
    {
        cout << "ERROR GLWFINIT" << endl;
    }
    window = glfwCreateWindow(this->width, this->height, "Triangulo", nullptr, nullptr);

    glfwMakeContextCurrent(window);
    gladLoadGL(glfwGetProcAddress);
}

void GL1Render::setupObject(Object& obj)
{
    /*Setea datos en GPU: todavía no se implementa*/
}

void GL1Render::removeObject(Object& obj)
{
    /*Setea datos en GPU: todavía no se implementa*/
}

void GL1Render::drawObjects(std::vector<Object*>* objs)
{
    for (auto& obj : *objs) //esto utiliza copia o el original
    {
        obj->computeModelMatrix();

        /*CPU*/

        //glBegin(GL_TRIANGLES);
        ////seteos de vertices y colores

        //Mesh3D mesh = obj->getMesh();
        //glColor3f(1.0f,1.0f,1.0f);

        //for (auto vert : mesh.getVertList())
        //{
        //    vert.pos = obj->getModelMtx() * vert.pos;
        //    glVertex3f(vert.pos.x, vert.pos.y, vert.pos.z);
        //}

        //glEnd();

        /*GPU*/

        glPushMatrix();
        glMultMatrixf(&(obj->getModelMtx()[0][0]));

        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, sizeof(vertex_t), obj->getMesh().getVertList().data());
       
        /* glEnableClientState(GL_COLOR_ARRAY);
        glColorPointer(4, GL_FLOAT, sizeof(vertex_t), &(p.vertices.data()->color));*/
       
        glDrawElements(GL_TRIANGLES, obj->getMesh().getvTriangleIdxList()->size(), GL_UNSIGNED_INT, obj->getMesh().getvTriangleIdxList()->data());
        glDisableClientState(GL_VERTEX_ARRAY);
        //glDisableClientState(GL_COLOR_ARRAY);

        glPopMatrix();
    }
}

bool GL1Render::isClosed()
{
    //comprobar si se ha cerrado o no la ventana
    if (glfwWindowShouldClose(window))
        return true;
    else
        return false;
}