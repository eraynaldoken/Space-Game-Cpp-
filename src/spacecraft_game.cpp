#include <iostream>
#include<string>
#include <cstdlib>
#include <ctime>
#include <random>

using namespace std;

class Gemi {

private:
    // Her olusacak geminin temel parametreleri.
    double yakit;
    double saglik;
    double altin;

public:
    string isim; // her geminin kendi ismi olacak. hizli, guclu veya normal gemi.

    Gemi(string isim) : isim(isim), yakit(100), saglik(100), altin(0) {}

    virtual void asteroidKusagindanGecis() {
        cout << isim << " bir asteroid kusagindan geciyor... ";
        if (rand() % 2 == 0) {
            int t = hasarAl(10);
            cout << t << " hasar aldi." << endl;
        }
        else {
            cout << "Basariyla gecti, hasar almadi." << endl;
            yakit -= 33;
        }
    }

    virtual void terkedilmisGezegen() {
        cout << isim << " terkedilmis bir gezegene inis yapti.... ";
        if (rand() % 2 == 0) {
            altin += 10;
            cout << "10 altin buldu." << endl;

        }
        else {
            cout << "uzay korsanlari karsina cikti" << endl;
            uzayKorsanlari();
        }
    }

    virtual void uzayKorsanlari() {
        int secim;
        cout << isim << " uzay korsanlariyla karsilasti.... " << endl;
        cout << "1 - Kac, 2 - Savas, 3 - Pazarlik Et: ";
        cin >> secim;
        if (secim == 1) {

            if (yakit < 33) {
                cout << "Yeterli yakit yok, kacamazsin!" << endl;
                return;
            }
            yakit = yakit - 33;
            double kacisSansi = kacmaSansi();
            if (rand() % 100 < kacisSansi * 50) {  // %50 temel kacma sansi
                cout << " Basariyla kactin." << endl;
                return;
            }
            cout << "Kacamadin, uzay korsanlari ile karsilasmak zorundasin!" << endl;
            cout << "Guncel Yakit: " << yakit << endl;
            uzayKorsanlari();
        }
        else if (secim == 2) {
            if (rand() % 2 == 0) {
                cout << "Savasi kazandiniz ve hasar almadiniz." << endl;
            }
            else {
                int h = hasarAl(30);
                cout << "Savasi kaybettiniz ve " << h << " hasar aldiniz." << endl;
            }
        }
        else if (secim == 3) {
            int altinKaybi = (rand() % 3 + 1) * 10;
            if (altin >= altinKaybi) {
                altin -= altinKaybi;
                cout << "Korsanlarla pazarlik yaptiniz ve " << altinKaybi << " altin kaybettiniz." << endl;
            }
            else {
                if (rand() % 2 == 0) {
                    cout << altinKaybi << " altin gerekiyordu altinin yetmedi, savasa girdin ve savasi kazandiniz,hasar almadiniz." << endl;
                }
                else {
                    int h = hasarAl(30);
                    cout << altinKaybi << " altin gerekiyordu altinin yetmedi, savasa girdin ve savasi kaybettiniz ve " << h << " hasar aldiniz." << endl;
                }


            }

        }
    }

    virtual double kacmaSansi() = 0;

    virtual int hasarAl(int hasar) {
        saglik -= hasar;
        if (saglik < 0) saglik = 0;
        return 10;
    }

    double getYakit() const {

        return yakit;
    }
    double getSaglik() const {

        return saglik;

    }
    double getAltin() const {

        return altin;
    }
    double getPuan() const {

        return (yakit * 5) + (saglik * 10) + (altin * 10);
    }

    virtual ~Gemi() {}
};

class HizliGemi : public Gemi {
public:
    HizliGemi() : Gemi("Hizli Gemi") {}

    double kacmaSansi() override {
        return 0.75;  // Hizli gemi icin kacma ihtimali 1.5 kat
    }

    int hasarAl(int hasar) override {
        // Hizli gemi aldigi hasari 1.5 katina cikartir
        Gemi::hasarAl(static_cast<int>(hasar * 1.5));
        return hasar * 1.5;
    }
};

class GucluGemi : public Gemi {
public:
    GucluGemi() : Gemi("Guclu Gemi") {}

    double kacmaSansi() override {
        return 0.25;  // Guclu gemi icin kacma ihtimali daha az.
    }

    int hasarAl(int hasar) override {
        // Guclu gemi aldigi hasari yariya indirir

        Gemi::hasarAl(hasar / 2);
        return hasar * 0.5;
    }
};

class NormalGemi : public Gemi {
public:
    NormalGemi() : Gemi("Normal Gemi") {}

    double kacmaSansi() override {
        return 0.5;  // Normal gemi icin standart kacma ihtimali
    }
};

void OyunuBaslat(Gemi& gemi) {
    int flag = 1;
    if (gemi.getYakit() > 0 && flag == 1) {
        for (int i = 0; i < 5; i++) {
            int event = rand() % 3;
            switch (event) { //olaylar oyuncunun secimine gore yonlendirilir her event sonrasi guncel durum yazdirilir.
                case 0:
                    gemi.asteroidKusagindanGecis();
                    cout << "guncel yakit: " << gemi.getYakit() << endl;
                    cout << "guncel saglik: " << gemi.getSaglik() << endl;
                    cout << "guncel para: " << gemi.getAltin() << endl;
                    cout << "guncel puan: " << gemi.getPuan() << endl;
                    cout << "\n";
                    break;
                case 1:
                    gemi.terkedilmisGezegen();
                    cout << "guncel yakit: " << gemi.getYakit() << endl;
                    cout << "guncel saglik: " << gemi.getSaglik() << endl;
                    cout << "guncel para: " << gemi.getAltin() << endl;
                    cout << "guncel puan: " << gemi.getPuan() << endl;
                    cout << "\n";
                    break;
                case 2:
                    gemi.uzayKorsanlari();
                    cout << "guncel yakit: " << gemi.getYakit() << endl;
                    cout << "guncel saglik: " << gemi.getSaglik() << endl;
                    cout << "guncel para: " << gemi.getAltin() << endl;
                    cout << "guncel puan: " << gemi.getPuan() << endl;
                    cout << "\n";
                    break;
            }
            if (gemi.getYakit() <= 0) {
                cout << "Yakitiniz bitti. Oyun sona erdi." << endl;
                break;
            }
        }
        flag = 0;
    }

    cout << "Oyun sonu puaniniz: " << gemi.getPuan() << endl;
}

int main() {


    srand(static_cast<unsigned>(time(NULL))); // random sayilari daha da random hala getirdik.




    cout << "Hangi gemiyi secmek istersiniz? " << endl;
    cout << "1. Guclu Gemi" << endl;
    cout << "2. Normal Gemi " << endl;
    cout << "3. Hizli Gemi" << endl;

    int secim;
    cin >> secim;

    Gemi* gemi;
    switch (secim) {
        case 1:
            gemi = new GucluGemi();
            break;
        case 2:
            gemi = new NormalGemi();
            break;
        case 3:
            gemi = new HizliGemi();
            break;
        default:
            cout << "Gecersiz secim. Normal Gemi olarak devam ediliyor." << endl;
            gemi = new NormalGemi();
            break;
    }

    OyunuBaslat(*gemi);

    delete gemi;
    return 0;
}
