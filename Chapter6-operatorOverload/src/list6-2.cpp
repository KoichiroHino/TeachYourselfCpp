#include <iostream>
#include <Fraction.h>

int main(void){
    Fraction frac{1, 3};
    // Fraction frac{1, 0}; // invalid num
    frac.show();

    if(frac > Fraction{1, 2}){
        std::cout << "left side is bigger." << std::endl;
    }else{
        std::cout << "right side is equal bigger." << std::endl;
    }

    frac = frac + Fraction{1, 5};
    frac.show();

    if(frac >= Fraction{1, 2}){
        std::cout << "left side is equal bigger." << std::endl;
    }else{
        std::cout << "right side is bigger." << std::endl;
    }

    frac = frac - Fraction{1, 3};
    frac.show();

    if(frac < Fraction{1, 2}){
        std::cout << "right side is bigger." << std::endl;
    }else{
        std::cout << "left side is equal bigger." << std::endl;
    }

    frac = frac * Fraction{5, 4};
    frac.show();

    if(frac <= Fraction{1, 2}){
        std::cout << "right side is equal bigger." << std::endl;
    }else{
        std::cout << "left side is bigger." << std::endl;
    }

    frac = frac / Fraction{1, 4};
    frac.show();

    return 0;
}