#include <iostream>
#include "punkt.h"
#include "wektor.h"
#include "Pwr.h"
#include <fstream>



int main() {
    using std::cout, std::endl;
    PunktWRuchu zmienna(punkt(1.5,1.6));
    cout<<zmienna.dajmase()<<endl;
    cout<<zmienna.wektorze_daj_x()<<endl;
    cout<<zmienna.punkcie_daj_y()<<endl;
    symulacja pierwsza;
    pierwsza.dodajPunkt(punkt(1,7), wektor(2.7,2.9), 8.7);
    pierwsza.dodajPunkt(punkt(1,5));
    pierwsza.zapisz();
    symulacja druga;
    try{
    druga.wgraj("Symulacja_numer_1.txt", pierwsza.metoda());
    }
    catch(const std::overflow_error& e){
        std::cout<<"Overflow error\n";
    }
    druga.zapisz(2);
    return 0;
}