#include <iostream>
#include <string>

using namespace std;

class CaracterJoc {
	string denumireCaracter = "Anonim";
	int nivelViata = 100;
	int nrAbilitati = 0;
	int* putereAtac = nullptr;
	double viteza = 0;
public:
	CaracterJoc(string _denumireCaracter, int _nrAbilitati, int* _putereAtac, double _viteza) {
		this->denumireCaracter = _denumireCaracter;
		this->viteza = _viteza;

		//validam
		if (_nrAbilitati > 0 && _putereAtac != nullptr) {
			//alocam dinamic inainte
			this->putereAtac = new int[_nrAbilitati];
			//punem doar valorile valide in
			for (int i = 0; i < _nrAbilitati; i++) {
				if (_putereAtac[i] >= 0 && _putereAtac[i] <= 100) {
					this->putereAtac[this->nrAbilitati] = _putereAtac[i];
					this->nrAbilitati++;
				}
			}
		}
	}
	bool adaugaPutereAtac(int _putere) {
		if (_putere >= 0 && _putere <= 100) {
			int* aux = new int[this->nrAbilitati + 1];
			for (int i = 0; i < this->nrAbilitati; i++) {
				aux[i] = this->putereAtac[i];
			}
			aux[this->nrAbilitati] = _putere;
			delete[] this->putereAtac;
			this->putereAtac = aux;
			this->nrAbilitati++;
			return true;
		}
		return false;
	}

	void anulareAbilitatePrag(int _prag) {
		for (int i = 0; i < this->nrAbilitati; i++) {
			if (this->putereAtac[i] < _prag) {
				this->putereAtac[i] = 0;
			}
		}
	}
	void afisare() const {
		cout << "Denumire: " << this->denumireCaracter
			<< ", Viata: " << this->nivelViata << "%"
			<< ", Numar abilitati: " << this->nrAbilitati
			<< ", Viteza: " << this->viteza
			<< ", Puteri de atac: ";

		for (int i = 0; i < this->nrAbilitati; i++) {
			cout << this->putereAtac[i] << " ";
		}

		cout << "\n";
	}
	void ataca(int* _putereAtacAdversar, int &_nrAbilitatiAdversar) {
		if (_putereAtacAdversar != nullptr && _nrAbilitatiAdversar > 0) {
			int indiceMaxim = 0;
			for (int i = 0; i < _nrAbilitatiAdversar; i++) {
				if (_putereAtacAdversar[i] > _putereAtacAdversar[indiceMaxim]) {
					indiceMaxim = i;
				}
			}
			if (adaugaPutereAtac(_putereAtacAdversar[indiceMaxim])) {
				for (int i = indiceMaxim; i < _nrAbilitatiAdversar - 1; i++) {
					_putereAtacAdversar[i] = _putereAtacAdversar[i + 1];
				}
				_nrAbilitatiAdversar--;
			}
			//aici puteam folosi functia adaugaPutereAtac() nu mi-am dat seama
			/*int* aux = new int[this->nrAbilitati + 1];
			for (int i = 0; i < this->nrAbilitati; i++) {
				aux[i] = this->putereAtac[i];
			}
			aux[this->nrAbilitati] = _putereAtacAdversar[indiceMaxim];
			delete[] this->putereAtac;
			this->putereAtac = aux;
			this->nrAbilitati++;*/

		}
	}
};

int main() {
	int puteri[] = { 99, 42, 56 };
	CaracterJoc cj1("Viking", 3, puteri, 8.2);
	cj1.afisare();
	cj1.adaugaPutereAtac(22);
	cj1.afisare();
	cj1.anulareAbilitatePrag(10);
	cj1.afisare();

	//Metoda Abilitati Adversar
	int nrAbilitatiAdversar = 5;
	int putereAtacAdversar[] = {20, 50, 92, 30, 99};
	cj1.ataca(putereAtacAdversar, nrAbilitatiAdversar);
	cj1.afisare();

	cout << "Abilitati ramase la adversar: ";
	for (int i = 0; i < nrAbilitatiAdversar; i++) {
		cout << putereAtacAdversar[i] << " ";
	}
}