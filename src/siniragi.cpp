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







void SinirAgi::ogrenmeBaslat(){
  while(hata > hataOrani){
    for(int i = 0; i < SINIFSAYISI ; i++){
        for(int j = 0; j < this->Sinif[i].getOrnekSayisi();j++){
            ileriYonluHesaplama(i,j);
        }
    }
  }
}











void SinirAgi::ileriYonluHesaplama(int sinifIndex,int ornekIndex){

    Noktalar ornek;
    double toplam= 0;
    // Giris ve Ara katman arası çıktı
    // İ indexine sahip sınıftan j indexine sahip örneği al
    ornek = Sinif[sinifIndex].sinifaAitNoktaGet(ornekIndex);
    cout<<"Verilen Ornek: "<<endl;
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
            agirliklariGuncelle(sinifIndex,ornekIndex,cikisKatmani[noronlarArasiGecisIndex].getNetCikis());
     }

}





void SinirAgi::agirliklariGuncelle(int sinifIndex,int ornekIndex,double cikan){
    double deltaW[GIRISSAYISI];
    double deltaV[3];
    Noktalar ornek = Sinif[sinifIndex].sinifaAitNoktaGet(ornekIndex);
    cout<<"Beklenen Cİkan Farki: "<<(this->Sinif[sinifIndex].beklenenDegerGet() - cikan)<<endl;
    // bu Kısımda ara katman ve cikis katmani arasında ki noronlar güncelleniyor.
    for(int i = 0; i < CIKISNORONSAYISI;i++){
        for (int j = 0; j< GIRISSAYISI;j++){
            deltaW[j] = (mu * (this->Sinif[sinifIndex].beklenenDegerGet() - cikan)) * ((FTUREVI) * this->araKatmanCikislar[j]);
            cikisKatmani[i].setGirisAgirliklari(deltaW[j] +  cikisKatmani[i].getGirisAgirligi(j),j);
        }
    }

    for(int a = 0; a < CIKISNORONSAYISI;a++){
        for(int i = 0; i < ARAKATMANSAYISI;i++){
            for(int j = 0; j < GIRISSAYISI; j++){
                    deltaV[j] = (mu *araKatman[i].getNetCikis() * ornek.getDegerler(j) * (this->Sinif[sinifIndex].beklenenDegerGet() - cikan)*cikisKatmani[a].getNetCikis() * cikisKatmani[a].getGirisAgirligi(j));
                    cout<<"Onceki agirlik  : "<<araKatman[i].getGirisAgirligi(j);
                    cout<<"Deltalar: "<<deltaV[j]<<endl;
                    araKatman[i].setGirisAgirliklari(araKatman[i].getGirisAgirligi(j) + deltaV[j],j);
            }
        }
    }
}







void SinirAgi::noronCikislariniEkranaBas(){
    for(int i = 0 ; i < ARAKATMANSAYISI;i++){
        cout<<this->araKatman[i].getNoronCikis()<<endl;
    }
}

double SinirAgi::getAraKatmanCikislar(int x){
    return this->araKatmanCikislar[x];
}


double SinirAgi::getMu() {
    return this->mu;
}

