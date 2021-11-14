//
// Created by KSZ on 2021-11-14.
//

#include <cmath>
#include "Punkt.h"

Punkt::Punkt(double ws_x, double ws_y)
    : x(ws_x),
      y(ws_y)
{

}

double Punkt::obliczOdleglosc()
{
    return fabs(x - y);
}
