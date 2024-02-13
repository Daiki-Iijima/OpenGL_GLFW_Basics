#include <cstdlib>
#include <iostream>
#include <GLFW/glfw3.h>
#include <GL/gl.h>

int main() {

    if(glfwInit() == GL_FALSE){
        std::cerr << "GLFWの初期化失敗じゃ!" << std::endl;
        return EXIT_FAILURE;
    }

    //  終了時の処理で必ず呼び出されるようにTerminate関数を登録
    atexit(glfwTerminate);

    //  ウィンドウ生成
    GLFWwindow* window = glfwCreateWindow(800,640,"OpeGLサンプル", nullptr, nullptr);
    if(window == nullptr){
        std::cerr << "ウィンドウの生成に失敗" << std::endl;
        return EXIT_FAILURE;
    }

    //  生成したウィンドウのコンテキストをカレントにする
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
        //  カラーバッファをClearColorに指定した色でクリア
        glClear(GL_COLOR_BUFFER_BIT);

        //  メイン処理

        //  スワップ
        glfwSwapBuffers(window);

        //  イベントを取り出す
        glfwWaitEvents();
    }

    return EXIT_SUCCESS;
}
