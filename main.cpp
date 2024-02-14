#include <cstdlib>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

/// GLSLバーテックスシェーダとフラグメントシェーダ
/// \param vsrc
/// \param fsrc
/// \return
GLuint crateProgram(const char* vsrc,const char *fsrc){
    //  プログラムオブジェクトの作成
    const GLuint program = glCreateProgram();

    //  バーテックスシェーダの作成とコンパイル、プログラムオブジェクトへのアタッチ
    if(vsrc != nullptr){
        //  バーテックスシェーダのシェーダオブジェクトを作成する
        const GLuint vobj = glCreateShader(GL_VERTEX_SHADER);
        //  ソースは1行であると想定
        glShaderSource(vobj,1,&vsrc,nullptr);
        //  コンパイル
        glCompileShader(vobj);

        //  バーテックスシェーダのシェーダオブジェクトをプログラムオブジェクトにアタッチ
        glAttachShader(program,vobj);
        //  シェーダオブジェクトはもうそのまま保持しておく必要がないので、削除マークをつける
        glDeleteShader(vobj);
    }

    //  フラグメントシェーダの作成とコンパイル、プログラムオブジェクトへのアタッチ
    if(fsrc != nullptr){
        //  フラグメントシェーダのシェーダオブジェクトを作成する
        const GLuint fobj = glCreateShader(GL_FRAGMENT_SHADER);
        //  ソースは1行であると想定
        glShaderSource(fobj,1,&fsrc,nullptr);
        //  コンパイル
        glCompileShader(fobj);

        //  フラグメントシェーダのシェーダオブジェクトをプログラムオブジェクトにアタッチ
        glAttachShader(program,fobj);
        //  シェーダオブジェクトはもうそのまま保持しておく必要がないので、削除マークをつける
        glDeleteShader(fobj);
    }

    //  各シェーダ持つattributeとリンク
    glBindAttribLocation(program,0,"position");
    glBindFragDataLocation(program,0,"fragment");
    glLinkProgram(program);

    return program;
}

int main() {

    if(glfwInit() == GL_FALSE){
        std::cerr << "GLFWの初期化失敗じゃ!" << std::endl;
        return EXIT_FAILURE;
    }

    //  終了時の処理で必ず呼び出されるようにTerminate関数を登録
    atexit(glfwTerminate);

    //  使用するOpenGLのバージョンを指定
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,6);
    //  OpenGL3.0以降の機能のみを使用するための設定
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

    //  ウィンドウ生成
    GLFWwindow* window = glfwCreateWindow(800,640,"OpeGLサンプル", nullptr, nullptr);
    if(window == nullptr){
        std::cerr << "ウィンドウの生成に失敗" << std::endl;
        return EXIT_FAILURE;
    }

    //  垂直同期のタイミングを待つ
    //  カラーバッファのスワップタイミングの指定
    glfwSwapInterval(1);

    //  生成したウィンドウのコンテキストをカレントにする
    glfwMakeContextCurrent(window);

    //  OpenGLのバージョンを取得
    const GLubyte* version = glGetString(GL_VERSION);
    if(version != nullptr){
        std::cout << "Version: " << version << std::endl;
    }

    //  クリアカラーの設定
    glClearColor(1.f, 1.f, 1.f, 1.f);

    //  GLEWの初期化
    glewExperimental = GL_TRUE;
    if(glewInit() != GLEW_OK){
        std::cerr << "GLEWの初期化に失敗" << std::endl;
        return EXIT_FAILURE;
    }

    // スタック上にバーテックスシェーダのソースプログラムを用意
    static constexpr GLchar vsrc[]=
            "#version 150 core¥n"
            "in vec4 position;¥n"
            "void main()¥n"
            "{¥n"
            "  gl_Position = position;¥n"
            "}¥n";

    // スタック上にバーテックスシェーダのフラグメントシェーダのソースプログラム
    static constexpr GLchar fsrc[] =
            "#version 150 core¥n"
            "out vec4 fragment;¥n"
            "void main()¥n"
            "{¥n"
            "  fragment = vec4(1.0, 0.0, 0.0, 1.0);¥n"
            "}¥n";

    const GLuint program = crateProgram(vsrc,fsrc);

    //  メインループ
    while(glfwWindowShouldClose(window) == GL_FALSE){
        //  カラーバッファをClearColorに指定した色でクリア
        glClear(GL_COLOR_BUFFER_BIT);

        //  シェーダの使用
        //  シェーダを切り替えない場合は、メインループの前でも大丈夫
        glUseProgram(program);

        //  メイン処理

        //  スワップ
        glfwSwapBuffers(window);

        //  イベントを取り出す
        glfwWaitEvents();
    }

    return EXIT_SUCCESS;
}
