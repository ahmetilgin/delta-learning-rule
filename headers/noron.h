#ifndef NORON_H
#define NORON_H


class Noron
{
    double girisAgirligi[3];
    double cikis;
    double netCikis;
public:
    Noron();
    void agirliklariEkrandaGoster();
    void noronCikislariSetle(double x);
    double getGirisAgirligi(int index);
    double getNoronCikis();
    double getNetCikis();
    double sigmoidFonksiyonu(double x);
    double fnetFonksiyonu(double x);

};

#endif // NORON_H
