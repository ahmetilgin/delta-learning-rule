#include <iostream>
#include "headers/siniragi.h"
using namespace std;

int main()
{
    SinirAgi deltaAgi;


    deltaAgi.araKatman[0].agirliklariEkrandaGoster();
    deltaAgi.araKatman[1].agirliklariEkrandaGoster();
    deltaAgi.cikisKatmani.agirliklariEkrandaGoster();
    deltaAgi.Sinif[0].beklenenDeger = 1;
    deltaAgi.Sinif[1].beklenenDeger = -1;


    return 0;
}
