#include "headers/siniragi.h"

SinirAgi::SinirAgi()
{
    this->araKatmanCikislar[ARAKATMANSAYISI] = -1;
     // bu ara katmanda ki -1 değerine sahip değişken
    Sinif[0].noktaEkle(0,0,-1);
    Sinif[0].noktaEkle(1,1,-1);
    Sinif[1].noktaEkle(0,1,-1);
    Sinif[1].noktaEkle(1,0,-1);
}

void SinirAgi::ileriYonluHesaplama(int sinifIndex,int ornekIndex){

    Noktalar ornek;
    double toplam= 0;
    // Giris ve Ara katman arası çıktı
    // İ indexine sahip sınıftan j indexine sahip örneği al
    ornek = Sinif[sinifIndex].sinifaAitNoktaGet(ornekIndex);
    cout<<"Verilen Ornek: ";
    ornek.noktalarEkranaBas();
    for (int araKatmanIndex = 0; araKatmanIndex < ARAKATMANSAYISI ; araKatmanIndex++){
       for(int girisIndex = 0; girisIndex< GIRISSAYISI ; girisIndex++){
            toplam = toplam + ornek.getDegerler(girisIndex)* this->araKatman[araKatmanIndex].getGirisAgirligi(girisIndex);
       }
       this->araKatman[araKatmanIndex].noronCikislariSetle(toplam);
       toplam = 0;

       //Ara katman üzerine işlemler yapmak için -1 de dahil edilmiş tüm çıkışlar tek bir değişkende.
       this->araKatmanCikislar[araKatmanIndex] = this->araKatman[araKatmanIndex].getNetCikis();
    }

    // burası ara katman çıkış arası.
    toplam = 0;
     for(int noronlarArasiGecisIndex = 0; noronlarArasiGecisIndex < CIKISSAYISI; noronlarArasiGecisIndex++){
            for(int araKatmanGirisler = 0; araKatmanGirisler < ARAKATMANSAYISI+1;araKatmanGirisler++){
            toplam = toplam + this->cikisKatmani[noronlarArasiGecisIndex].getGirisAgirligi(araKatmanGirisler) * araKatmanCikislar[araKatmanGirisler];
            }
            cikisKatmani[noronlarArasiGecisIndex].noronCikislariSetle(toplam);
            toplam = 0;
     }
    agirliklariGuncelle(sinifIndex,ornekIndex,cikisKatmani[0].getNetCikis());
      // burdan sonra çıkış belli artk beklenen değere göre ağırlık güncellemesi
}

void SinirAgi::noronCikislariniEkranaBas(){
    for(int i = 0 ; i < ARAKATMANSAYISI;i++){
        cout<<this->araKatman[i].getNoronCikis()<<endl;
    }
}

double SinirAgi::getAraKatmanCikislar(int x){
    return this->araKatmanCikislar[x];
}

void SinirAgi::agirliklariGuncelle(int sinifIndex,int ornekIndex,double cikan){

}
