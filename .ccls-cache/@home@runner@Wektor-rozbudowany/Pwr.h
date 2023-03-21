#ifndef _a_
#define _a_
#include "wektor.h"
#include "punkt.h"
#include <vector>
#include <fstream>
#include <iostream>

class PunktWRuchu{
        wektor wektorek;
        punkt punkcik;
        double masa;
    public:
        PunktWRuchu(): wektorek(), punkcik(), masa(0){};
        PunktWRuchu(double xvec,double yvec, double xpun, double ypun, double m): wektorek(xvec,yvec), punkcik(xpun, ypun), masa{m}{};
        PunktWRuchu(punkt a, wektor b=wektor(0,0), double m=0): masa{m}, wektorek{b}, punkcik{a}{}; 
        void set_wektor_x(double x){
            wektorek.zamien_x(x);
        }
        void set_wektor_y(double y){
            wektorek.zamien_y(y);
        }
        double wektorze_daj_x(){
            return wektorek.wyjmij_x();
        }
        double wektorze_daj_y(){
            return wektorek.wyjmij_y();
        }
        void set_punkt_x(double x){
            punkcik.ustaw_x(x);
        }
        void set_punkt_y(double x){
            punkcik.ustaw_y(x);
        }
        double punkcie_daj_x(){
            return punkcik.wyjmij_x();
        }
        double punkcie_daj_y(){
            return punkcik.wyjmij_y();
        }
        void move(double t, wektor cus){
            punkcik.move(cus.skalowanie(t));
        }
        double dajmase(){
            return this->masa;
        }
        void zmien_mase(double x){
            this->masa=x;
        }
};

class symulacja{
        std::vector<PunktWRuchu> pierwszy;
    public:
        void dodajPunkt(punkt a, wektor b=wektor(0,0), double masa=0.0){
            pierwszy.push_back(PunktWRuchu(a,b,masa));
        }
        void zapisz(int i=1){
            std::string name_plik("Symulacja_numer_");
            name_plik+=std::to_string(i);
            name_plik+=".txt";
            std::ofstream plik;
            plik.open(name_plik);
            if(plik.is_open()){
                for(int i = 0; i<pierwszy.size();i++){
                    plik<<pierwszy[i].punkcie_daj_x()<<'\n'<<pierwszy[i].punkcie_daj_y()<<'\n'<<pierwszy[i].wektorze_daj_x()<<'\n'<<pierwszy[i].wektorze_daj_y()<<"\n"<<pierwszy[i].dajmase()<<'\n'<<"To byl punkt "<<i+1<<std::endl;
                }
            }
            plik.close();
        }
        std::vector<PunktWRuchu> metoda(){
            return pierwszy;
        }
        void wgraj(std::string cos, std::vector<PunktWRuchu> arg){
            
            std::string temp;
            int i=0;
            std::ifstream plik(cos);
            if(plik.good()){
                while(i<arg.size()){
                    pierwszy.push_back(PunktWRuchu(punkt(0,0)));
                    if(plik.eof()) std::cout<<"Koniec pliku\n";
                    getline(plik, temp);
                    std::cout<<temp<<std::endl;
                    pierwszy[i].set_punkt_x(stod(temp));
                    temp.clear();
                    getline(plik, temp);
                    std::cout<<temp<<std::endl;
                    pierwszy[i].set_punkt_y(stod(temp));
                    temp.clear();
                    getline(plik, temp);
                    std::cout<<temp<<std::endl;
                    pierwszy[i].set_wektor_x(stod(temp));
                    temp.clear();
                    getline(plik, temp);
                    std::cout<<temp<<std::endl;
                    pierwszy[i].set_wektor_x(stod(temp));
                    temp.clear();
                    getline(plik, temp);
                    std::cout<<temp<<std::endl;
                    pierwszy[i].zmien_mase(stod(temp));
                    getline(plik,temp);
                    std::cout<<temp<<std::endl;
                    temp.clear();
                    i++;
                }
            }
            else throw std::exception();
            plik.close();
        }
};

#endif