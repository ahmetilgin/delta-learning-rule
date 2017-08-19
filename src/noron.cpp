#include "headers/noron.h"
#include <time.h>
#include <iostream>
using namespace std;


Noron::Noron()
{

    // Her Nöron için başlangıç setlenmesi rastgele
    for(int i = 0; i < 3; i++){
        giris[i] = rand()% 10;
    }

}
void Noron::agirliklariEkrandaGoster(){
    for(int i = 0; i < 3;i++){
        cout<< giris[i] << ' ';
    }
    cout <<endl;
}


