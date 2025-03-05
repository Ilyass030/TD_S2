#pragma once
#include <iostream>

struct Fraction {
    unsigned int numerator;
    unsigned int denominator;

    void display();
};

Fraction add(Fraction const& f1, Fraction const& f2);
Fraction sub(Fraction const& f1, Fraction const& f2);
Fraction mul(Fraction const& f1, Fraction const& f2);
Fraction div(Fraction const& f1, Fraction const& f2);

Fraction operator+(Fraction const& f1, Fraction const& f2);
Fraction operator-(Fraction const& f1, Fraction const& f2);
Fraction operator*(Fraction const& f1, Fraction const& f2);
Fraction operator/(Fraction const& f1, Fraction const& f2);

std::ostream& operator<<(std::ostream& os, Fraction const& f);