#ifndef SINIRAGI_H
#define SINIRAGI_H
#include "noron.h"
#include "siniflar.h"


#define ORNEKSAYISI 2
#define GIRISSAYISI 3
#define CIKISSAYISI 1
#define SINIFSAYISI 2
#define ARAKATMANSAYISI 2
#define CIKISNORONSAYISI 1
#define FTUREVI 0.5



class SinirAgi
{
    double araKatmanCikislar[ARAKATMANSAYISI+1];
    double hataOrani = 0.1;
    double mu = 1.0;
    double hata=500;
public:
    SinirAgi();
    Siniflar Sinif[SINIFSAYISI];
    Noron araKatman[ARAKATMANSAYISI];
    Noron cikisKatmani[CIKISNORONSAYISI];
    void ileriYonluHesaplama(int sinifIndex,int ornekIndex);
    void noronCikislariniEkranaBas();
    double getAraKatmanCikislar(int x);
    void agirliklariGuncelle(int sinifIndex,int ornekIndex,double cikan);
    double getMu();
    void ogrenmeBaslat();
};

#endif // SINIRAGI_H
