#include <iostream>
#include <GLFW/glfw3.h>

int main() {
    if(glfwInit() == GL_FALSE){
        std::cerr << "GLFWの初期化失敗じゃ!" << std::endl;
        return EXIT_FAILURE;
    }

    GLFWwindow* window = glfwCreateWindow(800,640,"OpeGLサンプル", nullptr, nullptr);

    if(window == nullptr){
        std::cerr << "ウィンドウの生成に失敗" << std::endl;
        return EXIT_FAILURE;
    }

    glfwMakeContextCurrent(window);

    while(glfwWindowShouldClose(window) == GL_FALSE){
        glfwWaitEvents();
    }

    return EXIT_SUCCESS;
}
