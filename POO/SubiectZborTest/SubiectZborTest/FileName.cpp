#include <iostream>
#include <string>

using namespace std;

enum TipZbor {
    ECONOMIC,
    BUSINESS
};

class Zbor {
    const string codZbor;
    string destinatie = "Necunoscuta";
    int nrPasageri = 0;
    double* greutateBagaje = nullptr;
    double greutateInclusa = 23;
    TipZbor tip = ECONOMIC;

public:
    Zbor(string _codZbor, string _destinatie, int _nrPasageri,
        const double* _greutateBagaje, double _greutateInclusa,
        TipZbor _tip)
        : codZbor(_codZbor) {
        this->destinatie = _destinatie;
        this->tip = _tip;

        if (_greutateInclusa > 0) {
            this->greutateInclusa = _greutateInclusa;
        }

        if (_nrPasageri > 0 && _greutateBagaje != nullptr) {
            this->nrPasageri = _nrPasageri;
            this->greutateBagaje = new double[this->nrPasageri];

            for (int i = 0; i < this->nrPasageri; i++) {
                if (_greutateBagaje[i] < 0) {
                    this->greutateBagaje[i] = 0;
                }
                else if (_greutateBagaje[i] > 32) {
                    this->greutateBagaje[i] = 32;
                }
                else {
                    this->greutateBagaje[i] = _greutateBagaje[i];
                }
            }
        }
    }
    void afisare() const {
        cout << "Cod zbor: " << this->codZbor
            << " | Destinatie: " << this->destinatie
            << " | Pasageri: " << this->nrPasageri
            << " | Greutate inclusa: " << this->greutateInclusa << " kg"
            << " | Tip: " << (this->tip == ECONOMIC ? "Economic" : "Business")
            << " | Greutate bagaje (kg): ";

        for (int i = 0; i < this->nrPasageri; i++) {
            if (i > 0) {
                cout << ", ";
            }

            cout << this->greutateBagaje[i];
        }

        cout << '\n';
    }
    double taxaBagaj(double tarif) {
        double taxa = 0;
        for (int i = 0; i < this->nrPasageri; i++) {
            if (this->greutateBagaje[i] > this->greutateInclusa) {
                taxa += (this->greutateBagaje[i] - this->greutateInclusa) * tarif;
            }
        }
        return taxa;
    }
    string getDestinatie() {
        return this->destinatie;
    }

    double getTotalGreutateZbor() {
        double total = 0;
        for (int i = 0; i < this->nrPasageri; i++) {
            total += this->greutateBagaje[i];
        }
        return total;
    }

};

double transportBagaje(Zbor* zboruri, int nrZboruri, string dest) {
    double total = 0;
    for (int i = 0; i < nrZboruri; i++) {
        if (zboruri[i].getDestinatie() == dest) {
            total += zboruri[i].getTotalGreutateZbor();
        }
    }
    return total;
}

int main() {
    double bagaje1[] = { -5, 23, 40, 25 };
    double bagaje2[] = { 12, 20 };
    double bagaje3[] = { 18, 25 };

    Zbor zboruri[] = {
        { "RO101", "Roma", 4, bagaje1, 23, ECONOMIC },
        { "RO102", "Cluj", 2, bagaje2, 23, BUSINESS },
        { "RO103", "Roma", 2, bagaje3, 23, ECONOMIC }
    };
    for (int i = 0; i < 3; i++) {
        zboruri[i].afisare();
        cout << "\n";
    }
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << zboruri[i].taxaBagaj(1) << " ";
    }

    cout << endl;

    cout << transportBagaje(zboruri, 3, "Roma");
}