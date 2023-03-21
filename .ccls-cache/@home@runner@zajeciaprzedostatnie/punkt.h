#ifndef _punkt_
#define _punkt_
#include "wektor.h"

class punkt{
    double x,y;
    public:
    punkt(double i, double j): x{i}, y{j}{}
    punkt(): x{0},y{0}{}
    punkt(punkt one, wektor w1){
        x=one.x+w1.wyjmij_x();
        y=one.y+w1.wyjmij_y();
    }//najciezszy konstruktor
    void show(){
        std::cout<<"\nWspolrzedna x: "<<this->x<<
        "\nWspolrzedna y: "<<this->y<<std::endl;

    }
    void move(wektor vector);
    punkt displacement(punkt drugi){
        punkt zwrot(this->x-drugi.x, this->y-drugi.y);
        return zwrot;
    }
    double wyjmij_x(){
        return this->x;
    }
    double wyjmij_y(){
        return this->y;
    }
    void ustaw_x(double i){
        this->x=i;
    }
    void ustaw_y(double i){
        this->y=i;
    }
};

#endif