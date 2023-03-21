#ifndef _wektor_
#define _wektor_
#include <iostream>

class wektor{
    double x, y;    
    public:
        wektor(): x{0}, y{0}{};
        wektor(double i, double j): x{i}, y{j}{};
        //wektor(wektor& b): x{b.wyjmij_x()}, y{b.wyjmij_x()}{};
        void wypisz(){
            std::cout<<"\nWspolrzedna wektora x: "<<this->x<<"\nWspolrzedna wektora y: "<<y;
        }
        wektor dodawanie_wektorow(const wektor &dru) const;
        wektor skalowanie(double wart) const;
        double iloczyn(wektor w1) const;
        void zamien_x(double i){
            this->x=i;
        }
        void zamien_y(double j){
            this->y=j;
        }
        void norma();
        double wyjmij_x(){
            return this->x;
        }
        double wyjmij_y(){
            return this->y;
        }
};

#endif