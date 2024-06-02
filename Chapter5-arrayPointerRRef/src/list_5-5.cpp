#include <iostream>

#define TEST_CODE
class Triangle
{
    int m_height; // 高さ
    int m_base_length; // 底辺の長さ

public:
    explicit Triangle(int height, int base_length);
    int height() const;
    int base_length() const;
};

Triangle::Triangle(int height, int base_length)
    : m_height(height), m_base_length(base_length)
{
}

int Triangle::height() const
{
    return m_height;
}

int Triangle::base_length() const
{
    return m_base_length;
}

int main()
{
    Triangle triangles[] =
    {
#ifdef TEST_CODE
        Triangle(10.0, 20), // OK case
        Triangle{10.0, 20}, // NG case {} has strict rule about type convert of args.
#else
        Triangle{10, 20}, // 配列の各要素のコンストラクターにそれぞれ引数を渡している
#endif
        Triangle{20, 30},
        Triangle{40, 50},
    };

    // Triangle triangle1 = {1, 3};

    for (auto& tri : triangles)
    {
        std::cout << "面積: " << (tri.base_length() * tri.height() / 2)
            << std::endl;
    }
}