#include "punkt.h"
#include "wektor.h"

void punkt::move(wektor cus){
    this->x+=cus.wyjmij_x();
    this->y+=cus.wyjmij_x();
}