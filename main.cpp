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

    //  OpenGLのバージョンを取得
    const GLubyte* version = glGetString(GL_VERSION);
    if(version != nullptr){
        std::cout << "Version: " << version << std::endl;
    }

    //  クリアカラーの設定
    glClearColor(1.f, 1.f, 1.f, 1.f);

    //  メインループ
    while(glfwWindowShouldClose(window) == GL_FALSE){
        glfwWaitEvents();
    }

    return EXIT_SUCCESS;
}
