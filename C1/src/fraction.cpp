#include "fraction.hpp"
#include "utils.hpp"

#include <iostream>

void Fraction::display() {
    std::cout << numerator << "/" << denominator;
}

float to_float (Fraction const& f1){
    return 1.f*f1.numerator / f1.denominator;
}

Fraction add(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.denominator + f2.numerator * f1.denominator,
        f1.denominator * f2.denominator
    });
}

Fraction operator+(Fraction const& f1, Fraction const& f2) {
    return simplify({f1.numerator * f2.denominator + f2.numerator * f1.denominator,
    f1.denominator*f2.denominator});
}

// Fraction add(Fraction const& f1, Fraction const& f2) {
//     Fraction result {
//         f1.numerator * f2.denominator + f2.numerator * f1.denominator
//         f1.denominator * f2.denominator
//     };

//     return simplify(result);
// }


Fraction sub(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.denominator - f2.numerator * f1.denominator,
        f1.denominator * f2.denominator
    });
}

Fraction operator-(Fraction const& f1, Fraction const& f2){
    return simplify({f1.numerator*f2.denominator - f2.numerator*f1.denominator, 
    f1.denominator*f2.denominator});
}

Fraction mul(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.numerator,
        f1.denominator * f2.denominator
    });
}

Fraction operator*(Fraction const& f1, Fraction const& f2){
    return simplify({
        f1.numerator*f2.numerator,
        f2.denominator*f2.denominator
    });
}

Fraction div(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.numerator,
        f1.denominator * f2.denominator
    });
}

Fraction operator/(Fraction const& f1, Fraction const& f2){
    return simplify({
        f1.numerator*f2.denominator,
        f1.denominator*f2.numerator
    });
}

std::ostream& operator<<(std::ostream& os, Fraction const& f) {
    return os << '(' << f.numerator << "/" << f.denominator << ')';
}

bool operator==(Fraction const& f1, Fraction const& f2){
    return (simplify(f1).numerator == simplify(f2).numerator && simplify(f1).denominator == simplify(f2).denominator);
}
// autre façon de faire
// bool operator==(Fraction const& f1, Fraction const& f2){
//     return (f1.numerator*f2.denominator == f1.denominator*f2.numerator);
// }

bool operator!=(Fraction const& f1, Fraction const& f2){
    return !(f1 == f2);
}

bool operator<(Fraction const& f1, Fraction const& f2){
    return (f1.numerator * f2.denominator < f2.numerator * f1.denominator);
}

bool operator>=(Fraction const& f1, Fraction const& f2){
    return !(f1 < f2);
}

bool operator<=(Fraction const& f1, Fraction const& f2){
    return (f1==f2 || f1<f2);
}

bool operator>(Fraction const& f1, Fraction const& f2){
    return (f1!=f2 || !(f1<f2));
}

Fraction operator+=(Fraction& f1, Fraction const& f2){
    f1=f1+f2;
    return f1;
}

Fraction operator-=(Fraction& f1, Fraction const& f2){
    return f1-f2;
}
    
Fraction operator*=(Fraction& f1, Fraction const& f2){
    return f1*f2;
}

Fraction operator/=(Fraction& f1, Fraction const& f2){
    return f1/f2;
}

// operator float(Fraction const& f1){  // PAS POSSIBLE POUR LES CONV
//     return to_float(f1);
// }

Fraction::operator float() const {
    return to_float(*this);
};

Fraction operator+(Fraction const& f, int const i){
    return simplify({
        f.numerator+i*f.denominator,
        f.denominator});
}

Fraction operator+(int const i, Fraction const& f){
    return f+i;
}

Fraction operator-(Fraction const& f, int const i){
    return simplify({
        f.numerator-i*f.denominator,
        f.denominator});
}

Fraction operator-(int const i, Fraction const& f){
    return simplify({
        -(f.numerator-i*f.denominator),
        f.denominator});
}