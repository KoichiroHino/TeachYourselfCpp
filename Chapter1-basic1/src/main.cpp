#include <iostream>
#include <string>

int main(){
  // C++のバージョン確認
  std::cout << __cplusplus << std::endl;

  // 変数宣言と初期化を同時に行う
  // 4通りの構文があるが基本的には同じ
  int a(0);
  int b = 1;  // C言語チック
  int c{2};   // 一様初期化（C++11以降で推奨）
  int d = {3};

  // const修飾子
  const int e = 1;  // int const e = 1; としても同じ
  // e = 2;  // 再代入が不可能

  // char型は1[byte]であることが決められている
  std::cout << "sizeof( char )  :" << sizeof( char ) << "[byte]" << std::endl;
  // これらの実行結果は環境によって異なる
  std::cout << "sizeof( short ) :" << sizeof( short ) << "[byte]" << std::endl;
  std::cout << "sizeof( int )   :" << sizeof( int ) << "[byte]" << std::endl;
  std::cout << "sizeof( long )  :" << sizeof( long ) << "[byte]" << std::endl;
  std::cout << "sizeof( long long )  :" << sizeof( long long ) << "[byte]" << std::endl;
  std::cout << "sizeof( double ):" << sizeof( double ) << "[byte]" << std::endl;
  std::cout << "sizeof( float ) :" << sizeof( float ) << "[byte]" << std::endl;
  
  // const変数にはconstポインタを使う
  const int* p = &e;
  // *p = 2; // デリファレンスをしての再代入が不可能

  // 通常のポインタ変数にはconst変数のアドレスが代入不可能
  // int* p = &e; // ←これはコンパイルエラー

  // ポインタ自体をconstにしたいときは以下
  int* const pp = &a; // 参照を使った方が分かりやすい
  // pp = &b; // ←コンパイルエラー（後から参照先の変更が不可）
  *pp = 2;  // 参照先自体はconstでないため、再代入可能

  char hoge = 99;
  std::cout << hoge << std::endl;   // ASCIIコードとして扱われる
  std::cout << static_cast<int>(hoge) << std::endl; // int型にキャストされる

  int array[5] = {1, 2, 3, 4, 5}; // int array[] = {1,2,3,4,5}でも同じ
  // int array[5] = {};           // 全要素が0で初期化される

  // 配列の要素数を取得するイディオム
  std::size_t arraySize = sizeof( array ) / sizeof( array[0] );
  std::cout << "arraySize = " << arraySize << std::endl;

  // 文字列をchar型配列で扱う
  // char hello[5] = "Hello";  // ヌル文字のスペースが無いのでコンパイルエラー
  char hello[6] = "Hello";  // コンパイルが通る
  // 文字列リテラルはヌル終端文字列なので、明示的に\0を書かなくてよい
  // char hello[] = "Hello"; とした方がよい
  std::cout << hello << std::endl;

  // std::stringは長さが可変
  std::string str = "Hello";
  std::cout << str;
  str = ", string";
  std::cout << str << std::endl;

  // 範囲for文
  // 今の参照先が何番目かを知る方法はない
  // 先頭から順番に走査することしかできない
  for( int elem : array ){
    std::cout << elem << std::endl;
    // elem = array[i] と等価
  }

  // main関数の末尾には暗黙的にreturn 0;が書かれているとされている
}
