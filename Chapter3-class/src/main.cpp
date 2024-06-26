#include <iostream>
#include <string>

// check the difference between polymorphism and non
#define POLYMORPHISM

class person
{

protected:
    std::string m_name;
    int m_age;

    person(int age);

public:
    person();
    person(std::string name, int age);

    person(const person& other); // コピーコンストラクター
#ifdef POLYMORPHISM
    virtual void set_name(std::string name);
#else
    void set_name(std::string name);
#endif
    void set_age(int age);

    std::string name() const;
    int age() const;
};

class SuperPerson : public person
{
    public:
    #ifdef POLYMORPHISM
        void set_name(std::string name) override;
    #else
        void set_name(std::string name);
    #endif
};

void SuperPerson::set_name(std::string name){
    m_name = "super " + name;
}

person::person(int age) : m_age(age)
{
    std::cout << "共通コンストラクター呼び出し" << std::endl;
}

person::person() : person(-1)
{
    std::cout << "引数なしコンストラクター呼び出し" << std::endl;
}

person::person(std::string name, int age) : person(age)
{
    std::cout << "引数付きコンストラクター呼び出し" << std::endl;
    set_name(name);
}

// コピーコンストラクター
person::person(const person& other)
{
    std::cout << "コピーコンストラクター呼び出し" << std::endl;
    // 名前をコピーする
    set_name(other.name());
    set_age(other.age());
}

void person::set_name(std::string name)
{
    m_name = name;
}

void person::set_age(int age)
{
    m_age = age;
}

std::string person::name() const
{
    return m_name;
}

int person::age() const
{
    return m_age;
}

class S
{
    static int count; // インスタンスの数を数えるstaticメンバー変数

public:
    S();
    ~S();

    static void show_count(); // staticメンバー関数の宣言
};

int S::count = 0; // staticメンバー変数の実体を定義して0で初期化する

S::S()
{
    // インスタンスが作られたらインクリメントする
    ++count;
}

S::~S()
{
    // 破棄されたらデクリメントする
    --count;
}

void S::show_count()
{
    std::cout << "S::count: " << count << std::endl;
}

int main()
{
    // コピーコンストラクタ
    person alice("alice", 15);

    // クラスの宣言
    std::cout << "test" << std::endl;
    person person1 = person();
    person person2;
    std::cout << "test" << std::endl;

    person copy(alice); // コピーコンストラクター呼び出し
    // person copy = alice;  // このように書いてもコピーコンストラクタが呼び出される
    std::cout << copy.name() << std::endl;
    std::cout << alice.name() << std::endl;

    // ポリモーフィズムで動きの変わる処理
    #ifdef POLYMORPHISM
    person *sp = new SuperPerson();
    sp->set_name("aaa");
    std::cout << "name: " << sp->name() << std::endl;

    #else
    SuperPerson sp2;
    sp2.set_name("aaa");
    std::cout << "name: " << sp2.name() << std::endl;    
    #endif
    // staticクラスメンバ
    // privateなのでクラス外からのアクセスは出来ない
    // std::cout << S::count << std::endl;

    // どのインスタンスにも結び付かないのでインスタンスがなくても呼ぶことができる
    S::show_count();

    S a;
    a.show_count(); // インスタンスを使って呼び出すこともできる
}
