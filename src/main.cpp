#include <iostream>
#include "headers/siniragi.h"
using namespace std;

int main()
{
    SinirAgi deltaAgi;
    deltaAgi.araKatman[0].agirliklariEkrandaGoster();
    deltaAgi.araKatman[1].agirliklariEkrandaGoster();

    deltaAgi.Sinif[0].beklenenDegerSet(1);
    deltaAgi.Sinif[1].beklenenDegerSet(-1);

    deltaAgi.ileriYonluHesaplama(0,0);

    deltaAgi.noronCikislariniEkranaBas();
    deltaAgi.cikisKatmani[0].agirliklariEkrandaGoster();

    return 0;
}
