#include <iostream>
#include <cctype>

void zadanie1(std::string s)
{
    for (char& el : s)
        el = toupper(el);

    std::cout << s << '\n';
}

int main()
{
    zadanie1("ala ma kota");
    return 0;
}