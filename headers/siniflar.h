#ifndef SINIFLAR_H
#define SINIFLAR_H
#include <iostream>
#include "noktalar.h"
#include <vector>
using namespace std;

class Siniflar
{
    vector <Noktalar> sinifaAitNoktalar;
    int beklenenDeger;
public:
    Siniflar();
    void noktaEkle(double x, double y, double z);
    void sinifAitNoktalariGoster();
    void beklenenDegerSet(int x);
    Noktalar sinifaAitNoktaGet(int index);

};

#endif // SINIFLAR_H
