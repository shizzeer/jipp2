//
// Created by Kamil on 18.10.2021.
//

#include <iostream>

void pole(double a, double b, double& p)
{
    p = a * b;
}

void pole(double a, double b, double c, double& p)
{
    p = a * b * c;
}

void pole(double r, double& p)
{
    p = 3.14 * (r * r);
}
void drukujMenu()
{
    std::cout << "Program liczacy pole wybranej figury geometrycznej\n"
                 "Wybierz jedna figure z ponizszej listy wpisujac numer opcji:\n"
                 "1. Prostokat\n"
                 "2. Prostopadloscian\n"
                 "3. Kolo\n";
}

