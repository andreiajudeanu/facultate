#include <iostream>
#include <string>

using namespace std;

enum Categorie{
	ALIMENTAR,
	NEALIMENTAR
};

class Produs {
	string denumire = "anonim";
	int stoc = 0;
	int nrAprovizionari = 0;
	int* cantitate = nullptr;
	Categorie categorie = NEALIMENTAR;
public:
	Produs(string _denumire, int _nrAprovizionari, int* _cantitate, Categorie _categorie) {
		this->denumire = _denumire;
		this->categorie = _categorie;
		if (_nrAprovizionari > 0 && _cantitate != nullptr) {
			this->nrAprovizionari = _nrAprovizionari;
			this->cantitate = new int[this->nrAprovizionari];
		}
		for (int i = 0; i < this->nrAprovizionari; i++) {
			if (_cantitate[i] > 0 && _cantitate[i] <= 100) {
				this->cantitate[i] = _cantitate[i];
			}
			else {
				this->cantitate[i] = 1;
			}
			this->stoc += this->cantitate[i];
		}
	}
	void afisare() {
		cout << "\nDenumire: " << this->denumire;
		cout << "\nStoc: " << this->stoc;
		cout << "\nNumar aprovizionari: " << this->nrAprovizionari;

		cout << "\nCantitati: ";
		for (int i = 0; i < this->nrAprovizionari; i++) {
			cout << this->cantitate[i] << " ";
		}
		if (this->categorie == ALIMENTAR) {
			cout << "\nAlimentar";
		}
		else {
			cout << "\nNealimentar";
		}
		cout << endl;
	}
	int nrIndiceAproviz() {
		if (this->nrAprovizionari > 0) {
			int medie = this->stoc / this->nrAprovizionari;
			for (int i = 0; i < this->nrAprovizionari; i++) {
				if (this->cantitate[i] > medie) {
					return i;
				}
			}
		}
		return -1;
	}
	void stergereAprovizPrag(int k) {
		if (this->nrAprovizionari > 0) {
			int nr = 0;
			int j = 0;
			int stocNou = 0;
			for (int i = 0; i < this->nrAprovizionari; i++) {
				if (this->cantitate[i] >= k) {
					nr++;
					stocNou += this->cantitate[i];
				}
			}
			if (nr > 0) {
				int* aux = new int[nr];
				for (int i = 0; i < this->nrAprovizionari; i++) {
					if (this->cantitate[i] >= k) {
						aux[j] = this->cantitate[i];
						j++;
					}
				}
				delete[] this->cantitate;
				this->cantitate = aux;
				this->nrAprovizionari = nr;
				this->stoc = stocNou;
			}
		}
	}
};

int main() {
	int cantitati[] = {20, 10, 15, 15, 40};
	Produs p1("Lapte", 5, cantitati, ALIMENTAR);	
	p1.afisare();
	cout << p1.nrIndiceAproviz() << " ";
	p1.stergereAprovizPrag(16);
	p1.afisare();

}