# 独習C++ 第5章 hoge

## 5.2 オブジェクトの配列
### explicitの意味
オブジェクトを生成するときに、必ずコンストラクタ呼び出しをさせることを強制させる

explicitを付けている場合
MyClassが引数2つのコンストラクタ(int, int)の場合
1. MyClass hoge = ( 0, 1 ); // エラー
2. MyClass fuga = { 0, 1 }; // エラー
3. MyClass piyo( 0, 1 );    // 正常
4. MyClass piyo{ 0, 1 };    // 正常

explicitを付けていない場合
1. MyClass hoge = ( 0, 1 ); // エラー
2. MyClass fuga = { 0, 1 }; // 正常
3. MyClass piyo( 0, 1 );    // 正常
4. MyClass piyo{ 0, 1 };    // 正常

1.の書き方はそもそも文法エラー
ただし、2.は暗黙のコンストラクタ呼び出しが行われてしまう
（構造体的な初期化の方法）

### コンストラクタを呼び出すときの(), {}の違い
MyClassが引数2つのコンストラクタ(int, int)の場合
1. MyClass hoge( 0.0, 1 );  // 動いてしまう（暗黙的型変換が行われてしまう）
2. MyClass fuga{ 0.0, 1 };  // コンパイルエラーで弾ける(暗黙的変換を防げる)

右辺値でブレースで数値を囲うと、std::initializer_list<>
ex.) {0, 1, 2, 3, 4}の型はstd::initializer_list<int>となる
