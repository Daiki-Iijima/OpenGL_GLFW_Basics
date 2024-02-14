#version 150 core
//  前のステージから受け取る頂点の位置
in vec4 position;

//  エントリーポイント
void main(){
    //  gl_Positionに代入した値が次のステージに渡される
    gl_Position = position;
}