class Fraction{
    public:
        Fraction(int numerator, int denominator);

        Fraction operator+(const Fraction& num) const;
        Fraction operator-(const Fraction& num) const;
        Fraction operator*(const Fraction& num) const;
        Fraction operator/(const Fraction& num) const;
        bool operator<(const Fraction& num) const;
        bool operator<=(const Fraction& num) const;
        bool operator>(const Fraction& num) const;
        bool operator>=(const Fraction& num) const;

        void show() const;

    private:
        int _numerator;
        int _denominator;

        int gcd(const int x, const int y) const;
};