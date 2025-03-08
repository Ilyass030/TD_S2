#include <iostream>
#include "fraction.hpp"


int main()
{
    Fraction f1 { 3, 4 };
    Fraction f2 { 1, 2 };
    int i=3;

    std::cout << "f1 = ";
    f1.display();
    std::cout << " f2 = ";
    f2.display();
    std::cout << std::endl;

    //Fraction f3 { add(f1, f2) };
    Fraction f3 {f1 + f2};

    std::cout << "add(f1, f2) = ";
    f3.display();

    std::cout << std::endl << "sub(f1, f2) = ";
    //(sub(f1, f2)).display();
    Fraction {f1-f2}.display();

    std::cout << std::endl << "mul(f1, f2) = ";
    //(mul(f1, f2)).display();
    Fraction {f1*f2}.display();

    std::cout << std::endl << "div(f1, f2) = ";
    //(div(f1, f2)).display();
    //Fraction {f1/f2}.display();
    std::cout << Fraction {f1/f2} ;

    std::cout << std::endl << "add(1/6, 2/6) = ";
    // //(add({1, 6}, {2, 6})).display();
    Fraction {Fraction {1, 6} + Fraction {2, 6}}.display();
    //std::cout << Fraction {Fraction {1, 6} + Fraction {2, 6}};

    // std::cout << std::endl;
    // if (Fraction{2, 4} == Fraction{1, 2} ){
    //     std::cout << "f1 et f2 sont égaux";
    // }
    // else {
    //     std::cout << "f1 et f2 ne sont pas égaux";
    // }
    std::cout << std::endl;
    if (Fraction{3, 4} != Fraction{1, 2} ){
        std::cout << "f1 et f2 ne sont pas égaux";
    }
    else {
        std::cout << "f1 et f2 sont égaux";
    }

    std::cout << std::endl;
    if (Fraction{3, 4} < Fraction{1, 2} ){
        std::cout << "f1 est plus petite que f2 ";
    }
    else {
        std::cout << "f1 est plus grande que f2";
    }

    std::cout << std::endl << "f1/=f2 =";
    std::cout << Fraction {f1/=f2};

    std::cout << std::endl << "conv float :" ;
    // std::cout << to_float(Fraction {10, 3});
    std::cout << static_cast <float> (Fraction {10, 3});

    std::cout << std::endl << "add(i/f1) = ";
    //std::cout << f1+i;
    std::cout << i/f1;

    std::cout << std::endl << "abs(-1/2) = ";
    std::cout << abs(Fraction {-1,2});

    std::cout << std::endl << "arrondi supp(-1/2) = ";
    std::cout << ceil(Fraction {-1,2});

    std::cout << std::endl << "arrondi inf(-1/2) = ";
    std::cout << floor(Fraction {-1,2});

    // std::cout << std::endl << "arrondi (10/3) = ";
    // std::cout << floor(Fraction {10,-3});
    return 0;
}