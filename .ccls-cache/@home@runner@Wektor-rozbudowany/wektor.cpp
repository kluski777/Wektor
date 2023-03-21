#include "wektor.h"
#include <cmath>


wektor wektor::dodawanie_wektorow(const wektor &dru) const {
        wektor wyniczek(this->x+dru.x,this->y+dru.y);
        return wyniczek;
    }

wektor wektor::skalowanie(double wart) const{
    wektor nowy(wart*this->x,wart*this->y);
    return nowy;
}

double wektor::iloczyn(wektor w1) const {
    return this->x*w1.x+this->y*w1.y;
}

void wektor::norma(){
    double sumcia=hypot(this->x,this->y);
    sumcia*=sumcia;
    this->x*=1/sumcia;
    this->y=1/sumcia;
}