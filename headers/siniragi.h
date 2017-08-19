#ifndef SINIRAGI_H
#define SINIRAGI_H
#include "noron.h"
#include "siniflar.h"

class SinirAgi
{
public:
    SinirAgi();
    Siniflar Sinif[2];
    Noron araKatman[2];
    Noron cikisKatmani;
    void hesaplama(double x,double y,double z);
};

#endif // SINIRAGI_H
