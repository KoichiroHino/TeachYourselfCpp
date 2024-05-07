#include <iostream>
// enumクラスをsigned char型で宣言
enum class Category : signed char
{
  Value1, // 先頭を明示的に指定しないと0となる
  Value2,
  Value3 = 100, // 明示的に指定もできる
  Value4,       // 101となる
};

int main()
{
  // 列挙体の変数を宣言して初期化
  Category cat = Category::Value3;  // スコープ解決演算子を使う
  // int型へ明示的にキャスト
  std::cout << static_cast<int>(cat) << std::endl;

  // 2.3 参照
  // 参照は変数のエイリアスなので初期化が必ず必要
  int value{42};
  int& ref = value; // 参照先と同じ型にする
  std::cout << &value << ", " << value << std::endl;
  std::cout << &ref << ", " << ref << std::endl;
  ref = 0;          // (*)間接参照演算子を使わないでアクセス可能, value = 0;と同じ
  std::cout << &value << ", " << value << std::endl;
  std::cout << &ref << ", " << ref << std::endl;
  
  // const参照
  // 関数の引数としてよく使う（書き換えたくないことを明示的に書ける）
  const int cons = 42;
  const int& ref_cons = cons;
  // cons = 42;      // const変数なのでコンパイルエラー
  // ref_cons = 42:  // const参照なのでコンパイルエラー
  
  const int& cref = value;  // 変更可能な変数valueのconst参照を宣言
  value = 0;                // value自体はconstでないので変更可能
  // cref = 42;             // const参照なのでコンパイルエラー

  // 2.4 型推論
  // 範囲for文で走査するときに得られる各要素はautoと書ける
  int array[] = {1,2,3,4,5,};
  for( auto elem : array ){ // elemはint型に推論される
    std::cout << elem << std::endl;
  }
  // 注意: 型推論(auto)を使うことでは、配列を宣言できない

  // decltype(式) を使うとその式の型を得ることができる
  decltype(1) j;
  j = 42.195;     // int型に推論されているので、暗黙の型変換が行われ切り捨てが発生
  std::cout << j << std::endl;

  // 2.5 型の別名定義
  using integer = int;  // int型の別名を宣言
  integer i = 42;
  // C言語では、typedef int integer;と書く

  // 2.8 ラムダ式
  // コピーキャプチャ
  int a = 0;
  auto lambda = [a]()
  {
      // OK。変数aのコピーがラムダ式内部に存在する
      std::cout << "a=" << a << std::endl;
      // a = 10; // エラー：コピーキャプチャはconstであるため
  };

  lambda(); // コピーしたときのaの中身が表示される

  // ラムダ式はコピーを持っているので、元の変数が変更されても
  // コピーの中身は変わらない
  a = 42;

  lambda(); // コピーした変数は影響を受けない

  // 参照キャプチャ
  int b = 0;
  auto lambda2 = [&b]() // bを参照でキャプチャする
  {
      std::cout << "キャプチャした変数：" << b << std::endl;
      ++b; // 参照でキャプチャした変数を変更する（mutableの指定は不要）
  };

  lambda2();

  // ラムダ式の中で変更が加えられている
  std::cout << "元の変数：" << b << std::endl;

  b = 42; // キャプチャ元の変数を変更する

  // 参照でキャプチャしているので元の変数が変わればラムダ式の中で見える値も変わる
  lambda2();

}
