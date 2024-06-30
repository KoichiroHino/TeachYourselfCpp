#include <iostream>
#include <Fraction.h>


// function: constractor, validation check, dev gcd
//
// Fraction := numerator / denominator
//
Fraction::Fraction(int numerator, int denominator){
    int _gcd;

    // denominator cannot define 0 so I should define as error case. but it is not main task. iInstead of it, set the value to 0/1
    if(denominator == 0){
        std::cout << "arg (denominator) error" << std::endl;
        this->_denominator = 1;
        this->_numerator = 0;
    }else{
        // dev gcd
        _gcd = gcd(numerator, denominator);

        if(_gcd != 0){
            this->_numerator = numerator/_gcd;
            this->_denominator = denominator/_gcd;
        }else {
            std::cout << "gcd error" << std::endl;
            this->_denominator = 1;
            this->_numerator = 0;
        }
    }
}

// ----- function: add -----
// return:  Fraction
// e.g.) Fraction{a, b} + Fraction{c, d}
// -------------------------
Fraction Fraction::operator+(const Fraction& num) const{
    int tmp_nume, tmp_deno;

    tmp_deno = this->_denominator * num._denominator;
    tmp_nume = this->_numerator*num._denominator + num._numerator*this->_denominator;

    return Fraction{tmp_nume, tmp_deno};
}

// ----- function: sub -----
// return:  Fraction
// e.g.) Fraction{a, b} - Fraction{c, d}
// -------------------------
Fraction Fraction::operator-(const Fraction& num) const{
    int tmp_nume, tmp_deno;

    tmp_deno = this->_denominator * num._denominator;
    tmp_nume = this->_numerator*num._denominator - num._numerator*this->_denominator;

   return Fraction{tmp_nume, tmp_deno};
}

// ----- function: mul -----
// return:  Fraction
// e.g.) Fraction{a, b} * Fraction{c, d}
// -------------------------
Fraction Fraction::operator*(const Fraction& num) const{
    int tmp_nume, tmp_deno;

    tmp_deno = this->_denominator * num._denominator;
    tmp_nume = this->_numerator * num._numerator;

    return Fraction{tmp_nume, tmp_deno};
}

// ----- function: dev -----
// return:  Fraction
// e.g.) Fraction{a, b} / Fraction{c, d}
// -------------------------
Fraction Fraction::operator/(const Fraction& num) const{
    int tmp_nume, tmp_deno;

    tmp_deno = this->_denominator * num._numerator;
    tmp_nume = this->_numerator * num._denominator;
    
    return Fraction{tmp_nume, tmp_deno};
}

// ----- function: compare -----
// return:  bool
// e.g.) Fraction{a, b} < Fraction{c, d}
// -----------------------------
bool Fraction::operator<(const Fraction& num) const{
    std::cout << ((double)this->_numerator)/this->_denominator << ", " << (double)(num._numerator)/num._denominator << std::endl;
    return ((double)this->_numerator/this->_denominator) < ((double)num._numerator/num._denominator);

}


// ----- function: compare -----
// return:  bool
// e.g.) Fraction{a, b} <= Fraction{c, d}
// -----------------------------
bool Fraction::operator<=(const Fraction& num) const{
    return !(*this > num);
}

// ----- function: compare -----
// return:  bool
// e.g.) Fraction{a, b} > Fraction{c, d}
// -----------------------------
bool Fraction::operator>(const Fraction& num) const{
    std::cout << ((double)this->_numerator)/this->_denominator << ", " << (double)(num._numerator)/num._denominator << std::endl;
    return ((double)this->_numerator)/this->_denominator > ((double)num._numerator)/num._denominator;
}

// ----- function: compare -----
// return:  bool
// e.g.) Fraction{a, b} >= Fraction{c, d}
// -----------------------------
bool Fraction::operator>=(const Fraction& num) const{
    return !(*this < num);
}

// ----- function: display fraction -----
// return:  void
// e.g.) frac.show()
// ---------------------------------------
void Fraction::show() const{
    if(this->_denominator == 1){
        std::cout << this->_numerator << std::endl;
    }else{
        std::cout << this->_numerator << " / " << this->_denominator << std::endl;
    }
}

int Fraction::gcd(const int x, const int y) const{
    int r;
    int tmp_x = x, tmp_y = y;

    if(x == 0 || y == 0){
        return 0;
    }

    if(tmp_x<0){
        tmp_x *= -1;
    }
    if(tmp_y<0){
        tmp_y *= -1;
    }

    while((r = tmp_x % tmp_y) != 0){
        tmp_x = tmp_y;
        tmp_y = r;
    }
    return tmp_y;
}
