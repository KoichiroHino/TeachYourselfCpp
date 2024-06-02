#include <iostream>
#define TEST_CODE

#ifdef TEST_CODE // define "array of int" type and "array of int ref" type
using sample_int = int[5];
using sample_ref_int = int (&)[5];
#endif

int main()
{
#ifdef TEST_CODE
    sample_int array = { 0, 1, 2, 3, 4 };
    sample_ref_int ref = array;
#else
    int array[5] = { 0, 1, 2, 3, 4 };
    int(&ref)[5] = array; // 配列への参照
#endif

    int(*ptr)[5] = &array; // 配列へのポインター

    for (int e : *ptr) // ポインターなので間接参照演算子が必要
    {
        std::cout << e << std::endl;
    }

    std::cout << std::endl;

    for (int e : ref) // 参照なので間接参照演算子は不要
    {
        std::cout << e << std::endl;
    }
}
