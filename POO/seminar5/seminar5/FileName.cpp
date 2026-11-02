#include <iostream>
using namespace std;

//fct globala
// get si set pe vector + pasrare incapsulare
// meth de afisare
// constructor

class Produs {
	string denumire = "Anonim";
	int stoc = 0;
	float* preturi = nullptr; // istoricul preturilor (diferite de la unul la altul)
	int nrPreturi = 0;

public:
	Produs(string _denumire, int _stoc, float _pret) {
		if (_denumire.size() >= 3) {
			this->denumire = _denumire;
		}
		if (_stoc > 0) {
			this->stoc = _stoc;
		}
		if (_pret > 0) {
			this->nrPreturi = 1;
			this->preturi = new float[this->nrPreturi];
			this->preturi[0] = _pret;
		}
	}

	void afisare() {
		cout << "\nProdus: " << this->denumire << ", Stoc: " << this->stoc << ", Istoric Preturi: ";
		for (int i = 0; i < this->nrPreturi; i++) {
			cout << this->preturi[i] << " ";
		}
	}

	void setStoc(int _stoc) {
		if (_stoc > 0) {
			this->stoc = _stoc;
		}
	}
	int getStoc() {
		return this->stoc;
	}

	void setDenumire(string _denumire) {
		if (_denumire.size() >= 3) {
			this->denumire = _denumire;
		}
	}
	string getDenumire() {
		return this->denumire;
	}

	void setPret(float _pret) {
		if (_pret > 0 && this->preturi != nullptr && _pret != this->preturi[this->nrPreturi - 1]) {
			float* aux = new float[this->nrPreturi + 1];
			for (int i = 0; i < this->nrPreturi; i++) {
				aux[i] = this->preturi[i];
			}
			aux[this->nrPreturi] = _pret;
			delete[] this->preturi;
			this->preturi = aux;
			this->nrPreturi++;
		}
	}

	int getNrPreturi() {
		return this->nrPreturi;
	}
	float* getPreturi() {
		float* aux = new float[this->nrPreturi];
		for (int i = 0; i < this->nrPreturi; i++) {
			aux[i] = this->preturi[i];
		}
		return aux;
	}

	float getMaximPret() {
		if (this->nrPreturi > 0) {
			float maxim = this->preturi[0];
			for (int i = 1; i < this->nrPreturi; i++) {
				if(this->preturi[i] > maxim)
					maxim = this->preturi[i];
			}
			return maxim;
		}
		return 0;
	}
	void eliminareK(int k) {
		if (k >= 0 && k <= this->nrPreturi) {
			float* aux = new float[this->nrPreturi - k];
			for (int i = 0; i < this->nrPreturi - k; i++) {
				aux[i] = this->preturi[k + i];
			}
			delete[] this->preturi;
			this->preturi = aux;
			this->nrPreturi -= k;
		}
	}
	void elimMediu() {
		//Calculam media si suma
		float medie, suma = 0;
		if (this->nrPreturi > 0) {
			for (int i = 0; i < this->nrPreturi; i++) {
				suma += this->preturi[i];
			}
			medie = suma / this->nrPreturi;
		}
		//Numerele ramase dupa eliminare pentru a aloca dinamic cat trebuie
		int nr = 0;
		for (int i = 0; i < this->nrPreturi; i++) {
			if (this->preturi[i] >= medie) {
				nr++;
			}
		}
		//Alocam dinamic intr-un aux elementele ramase
		int j = 0;
		float* aux = new float[nr];
		for (int i = 0; i < this->nrPreturi; i++) {
			if (this->preturi[i] >= medie) {
				aux[j] = this->preturi[i];
				j++;
			}
		}
		//nu uitam sa dezalocam!
		delete[] this->preturi;
		this->preturi = aux;
		this->nrPreturi = nr;
	}
};

void afisareProdus(Produs p) {
	p.afisare();

}

int main() {
	Produs p1("Abecedar", 7, 20);
	p1.afisare(); // afiseaza pe o linie info despre produs
	//functia din clasa=>metoda
	//afisareProdus(p1);
	p1.setStoc(25);
	p1.afisare();
	p1.setPret(20);
	p1.afisare();
	p1.setDenumire("Pix");
	p1.setStoc(35);
	p1.setPret(30);
	p1.setPret(35);
	p1.setPret(15);
	cout << "\nStoc: " << p1.getStoc();
	p1.afisare();
	cout << endl;

	int numar = p1.getNrPreturi();
	float* listaPreturi = p1.getPreturi();
	for (int i = 0; i < numar; i++) {
		cout << listaPreturi[i] << " ";
	}
	delete[] listaPreturi;
	listaPreturi = nullptr;

	cout << endl;
	cout << p1.getMaximPret();
	p1.eliminareK(-1);
	p1.afisare();
	p1.elimMediu();
	p1.afisare();
}
//TO DO HOME
// toate formele de get si set 
// getPreturi(); care sa respecte incapsularea 
// metoda care returneaza cel mai mare pret
// metoda care elimina preturile sub pretl mediu
// met care elimina primele k preturi
