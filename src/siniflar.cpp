#include "headers/siniflar.h"

Siniflar::Siniflar()
{

}
void Siniflar::noktaEkle(double x, double y, double z){
    Noktalar noktam;
    noktam.x = x;
    noktam.y = y;
    noktam.z = z;

    this->sinifaAitNoktalar.push_back(noktam);
}


void Siniflar::sinifAitNoktalariGoster(){
    for(int i=0; i<this->sinifaAitNoktalar.size(); ++i)
         cout << this->sinifaAitNoktalar[i].x << ' ' << this->sinifaAitNoktalar[i].y << ' ' << this->sinifaAitNoktalar[i].z << endl ;
}
