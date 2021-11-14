//
// Created by KSZ on 2021-11-14.
//

#ifndef JIPP2_FIGURA_H
#define JIPP2_FIGURA_H

struct wierzcholek {
    double x;
    double y;
};

class Figura {
public:
    int liczbaWierzcholkow;
    struct wierzcholek* wierzcholki;
    Figura();
    ~Figura();
};


#endif //JIPP2_FIGURA_H
