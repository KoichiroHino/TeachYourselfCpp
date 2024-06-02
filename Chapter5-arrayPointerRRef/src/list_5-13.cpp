#include <iostream>
#include <string>

// #define TEST_CODE

class Object
{
protected:
    std::string name;

public:
    Object() : Object("NO NAME") { }
    explicit Object(std::string name) : name(name) { }
    virtual ~Object();

    virtual void show_name() const;
};

Object::~Object()
{
    std::cout << "Objectのデストラクター" << std::endl;
}

void Object::show_name() const
{
    std::cout << "object name: " << name << std::endl;
}

class SubObject: public Object{
    public:
        SubObject() : Object("SubObject") { }
        explicit SubObject(std::string name) : Object(name) { }
        ~SubObject();
        void show_name() const override;
};

SubObject::~SubObject()
{
    std::cout << "SubObjectのデストラクター" << std::endl;
}

void SubObject::show_name() const
{
    std::cout << "super object name: " << name << std::endl;
}

int main()
{
    // 配列のnew演算子。戻り値の型がポインターであることに注意
#ifndef TEST_CODE 
    Object* obj = new Object[10]
    {
        Object{"first"},
        Object{"second"},
    };
#else // if you use polymorphism, you should use pointer. If you don't use pointer, additional functions of superclass can't be used. 
    Object* obj[4] =
    {
        new Object{"first"},
        new Object{"second"},
        new SubObject{"third"},
        new SubObject{},
        // これ以降の要素はデフォルトコンストラクターで初期化される
    };
#endif

#ifndef TEST_CODE
    obj[0].show_name();
    obj[1].show_name();
    obj[2].show_name();
    
    // 配列のdelete演算子。各要素の（ここでは10個の）デストラクターがすべて呼ばれる
    delete [] obj;
#else
    obj[0]->show_name();
    obj[1]->show_name();
    obj[2]->show_name();
    obj[3]->show_name();

    delete obj[3];
    delete obj[2];
    delete obj[1];
    delete obj[0];
#endif
}
