#include <iostream>
#include <string>

using namespace std;

class Pacient {
	string nume = "-";
	int varsta = 0;
	int nrMasuratori = 0;
	int* glicemie = nullptr;
	static int nrPacienti;
	bool adult = true;
public:
	Pacient(string _nume, int _varsta, int _nrMasuratori, int* _glicemie, bool _adult) {
		this->nume = _nume;
		this->adult = _adult;
		if (_varsta >= 0 && _varsta <= 120) {
			this->varsta = _varsta;
		}
		else {
			this->varsta = 0;
		}
		
		if (_nrMasuratori > 0 && _glicemie != nullptr) {
			int nrValide = 0;
			for (int i = 0; i < _nrMasuratori; i++) {
				if (_glicemie[i] >= 40 && _glicemie[i] <= 400) {
					nrValide++;
				}
			}

			if (nrValide > 0) {
				this->glicemie = new int[nrValide];
				int j = 0;
				for (int i = 0; i < _nrMasuratori; i++) {
					if (_glicemie[i] >= 40 && _glicemie[i] <= 400) {
						this->glicemie[j] = _glicemie[i];
						j++;
					}
				}
				this->nrMasuratori = nrValide;
			}

		}
		nrPacienti++;
	}

	static int getNrPacienti() {
		return nrPacienti;
	}

	int diferentaMaxima() {
		int maxim = this->glicemie[0];
		int minim = this->glicemie[0];

		for (int i = 0; i < this->nrMasuratori; i++) {
			if (this->glicemie[i] > maxim) {
				maxim = this->glicemie[i];	
			}
		}
		for (int i = 0; i < this->nrMasuratori; i++) {
			if (this->glicemie[i] < minim) {
				minim = this->glicemie[i];
			}
		}
		return maxim - minim;
	}
	void afisare() const {
		cout << "Nume: " << this->nume << '\n';
		cout << "Varsta: " << this->varsta << '\n';
		cout << "Numar masuratori: " << this->nrMasuratori << '\n';

		cout << "Glicemie: ";
		for (int i = 0; i < this->nrMasuratori; i++) {
			if (i > 0) {
				cout << ", ";
			}

			cout << this->glicemie[i];
			if (this->glicemie[i] > 180) {
				cout << '!';
			}
		}

		cout << "\nAdult: ";
		if (this->adult == true) {
			cout << "DA";
		}
		else {
			cout << "NU";
		}


		cout << "\nNumar total de pacienti creati: " << getNrPacienti() << '\n';
	}
	void adaugaMasurare(int _valoare) {
		if (!(_valoare >= 40 && _valoare <= 400)) {
			return;
		}
		int inceput = 0;
		if (this->nrMasuratori >= 10) {
			inceput = this->nrMasuratori - 9;
		}
		int nr = this->nrMasuratori - inceput;
		int* aux = new int[nr + 1]; // valori pt masura noua
		for (int i = 0; i < nr; i++) {
			aux[i] = this->glicemie[inceput + i];
		}
		aux[nr] = _valoare;

		delete[] this->glicemie;
		this->glicemie = aux;
		this->nrMasuratori = nr + 1;
	}
};
int Pacient::nrPacienti = 0;

int main() {
	int valori[] = { 95, 190, 25, 110, 180, 40, 400, 401,
					120, 130, 140, 150 };

	Pacient p1("Ana", 35, 12, valori, true);
	Pacient p2("Mihai", 135, 0, nullptr, false);

	p1.afisare();
	cout << "Diferenta maxima: " << p1.diferentaMaxima() << '\n';
	p1.adaugaMasurare(200);
	p1.afisare();
}