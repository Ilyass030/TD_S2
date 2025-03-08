#pragma once
#include <iostream>



struct Fraction {
     int numerator;
     int denominator;

    void display();

    operator float() const;
    float abs();
    int ceil(); //arrondi supp
    int floor(); //arrondi inf
    int round(); //arrondi en fct si le 10ème est > à 5
};

float to_float (Fraction const& f1);



Fraction add(Fraction const& f1, Fraction const& f2);
Fraction sub(Fraction const& f1, Fraction const& f2);
Fraction mul(Fraction const& f1, Fraction const& f2);
Fraction div(Fraction const& f1, Fraction const& f2);

Fraction operator+(Fraction const& f1, Fraction const& f2);
Fraction operator-(Fraction const& f1, Fraction const& f2);
Fraction operator*(Fraction const& f1, Fraction const& f2);
Fraction operator/(Fraction const& f1, Fraction const& f2);

std::ostream& operator<<(std::ostream& os, Fraction const& f);

bool operator==(Fraction const& f1, Fraction const& f2);
bool operator!=(Fraction const& f1, Fraction const& f2);

bool operator<(Fraction const& f1, Fraction const& f2);
bool operator>=(Fraction const& f1, Fraction const& f2);
bool operator<=(Fraction const& f1, Fraction const& f2);
bool operator>(Fraction const& f1, Fraction const& f2);

Fraction operator+=(Fraction& f1, Fraction const& f2);
Fraction operator-=(Fraction& f1, Fraction const& f2);
Fraction operator*=(Fraction& f1, Fraction const& f2);
Fraction operator/=(Fraction& f1, Fraction const& f2);

//operator float(Fraction const& f1); pas possible pour les conv

Fraction operator+(Fraction const& f, int const i);
Fraction operator+(int const i, Fraction const& f);

