#include <iostream>
#include <string>

using namespace std;

class Angajat {
	string nume = "anonim";
	int nrLuni = 0;
	int* oreLucrate = nullptr;
	int nrMinimOreLucrate = 100;
	double tarifOraSuplimentara = 1;
	double salariuDeBaza = 0;
public:
	Angajat(string _nume, int _nrLuni, int* _oreLucrate, int _nrMinimOreLucrate, 
	double _tarifOraSuplimentara, double _salariuDeBaza) {
		this->nume = _nume;
		this->salariuDeBaza = _salariuDeBaza;

		if (_nrLuni > 0 && _oreLucrate != nullptr) {
			this->nrLuni = _nrLuni;
			this->oreLucrate = new int[this->nrLuni];

			for (int i = 0; i < this->nrLuni; i++) {
				if (_oreLucrate[i] >= this->nrMinimOreLucrate && _oreLucrate[i] <= 360) {
					this->oreLucrate[i] = _oreLucrate[i];
				}
				else {
					if (i == 0) {
						this->oreLucrate[i] = this->nrMinimOreLucrate;
					}
					else {
						int minim = this->oreLucrate[0];
						for (int j = 0; j < i; j++) {
							if (_oreLucrate[j] < minim) {
								minim = _oreLucrate[i];
							}
						}
						this->oreLucrate[i] = minim;
					}
				}
			}
		}
	}
	double salariuSuplimentar() {
		double salariuSuplimentar = 0;
		int oreSuplimentare = 0;
		for (int i = 0; i < this->nrLuni; i++) {
			oreSuplimentare += this->oreLucrate[i] - this->nrMinimOreLucrate;
		}
		salariuSuplimentar = oreSuplimentare * this->tarifOraSuplimentara;
		return salariuSuplimentar;
	}

	void afisare() {
		cout << "Nume: " << this->nume << '\n';
		cout << "Numar luni: " << this->nrLuni << '\n';
		cout << "Ore lucrate: ";
		for (int i = 0; i < this->nrLuni; i++) {
			if (i > 0) {
				cout << ", ";
			}
			cout << this->oreLucrate[i];
		}
		cout << '\n';

		cout << "Numar minim de ore: " << this->nrMinimOreLucrate << '\n';
		cout << "Tarif ora suplimentara: " << this->tarifOraSuplimentara << '\n';
		cout << "Salariu de baza: " << this->salariuDeBaza << '\n';
	}
	void adaugareLuni(int k) {
		int* aux = new int[this->nrLuni + k];

		for (int i = 0; i < this->nrLuni; i++) {
			aux[i] = this->oreLucrate[i];
		}

		for (int i = this->nrLuni; i < this->nrLuni + k; i++) {
			aux[i] = this->nrMinimOreLucrate;
		}

		delete[] this->oreLucrate;
		this->oreLucrate = aux;
		this->nrLuni += k;
	}
};
int main() {
	int OreLunare[] = {400, 180, 400};
	Angajat a1("Andrei", 3, OreLunare, 160, 20, 3500);
	a1.afisare();
	cout << a1.salariuSuplimentar();
	a1.adaugareLuni(2);
	a1.afisare();
}