#version 150 core

// 次のステージに渡す変数
out vec4 fragment;

void main() {
    //  カラーバッファに書き込む色を設定
    fragment = vec4(1.0, 0.0, 0.0, 1.0);
}