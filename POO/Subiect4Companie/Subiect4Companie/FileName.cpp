#include <iostream>
#include <string>

using namespace std;

class Companie {
	string denumire = "-";
	int nrAni = 0;
	float* venitAnual = nullptr;
	float costuriOperationale = 0;
	bool listataBursa = true;
public:
	Companie(string _denumire, int _nrAni, float* _venitAnual, float _costuriOperationale,
		bool _listataBursa) {
		this->denumire = _denumire;
		this->costuriOperationale = _costuriOperationale;
		if (_nrAni > 0 && _venitAnual != nullptr) {
			this->nrAni = _nrAni;
			this->venitAnual = new float[this->nrAni];
			float suma = 0;
			for (int i = 0; i < this->nrAni; i++) {
				if (_venitAnual[i] <= 0) {
					if (i == 0) {
						_venitAnual[i] = this->costuriOperationale;
					}
					else {
						_venitAnual[i] = suma / i;
					}
				}
				this->venitAnual[i] = _venitAnual[i];
				suma += this->venitAnual[i];
			}
		}
	}
	int faliment(int x) {
		int nr = 0;
		for (int i = 0; i < this->nrAni; i++) {
			if (this->venitAnual[i] < this->costuriOperationale) {
				nr++;

				if (nr == x) {
					return true;
				}
			}
			else {
				nr = 0;
			}
		}
		return false;
	}
	void afisare() const {
		float venitTotal = 0;

		for (int i = 0; i < this->nrAni; i++) {
			venitTotal += this->venitAnual[i];
		}

		cout << "Denumire: " << this->denumire << '\n';
		cout << "Numar ani: " << this->nrAni << '\n';
		cout << "Venit total: " << venitTotal << '\n';
		cout << "Costuri operationale anuale: "
			<< this->costuriOperationale << '\n';
		cout << "Listata la bursa: "
			<< (this->listataBursa!=0 ? "Da" : "Nu") << '\n';
	}
	void setListataLaBursa(bool ok) {
		this->listataBursa = ok;
	}
};
void adaugaVenit(float*& venituri, int& nrVenituri, float venitNou) {
	float* aux = new float[nrVenituri + 1];

	for (int i = 0; i < nrVenituri; i++) {
		aux[i] = venituri[i];
	}
	aux[nrVenituri] = venitNou;

	delete[] venituri;
	venituri = aux;
	nrVenituri++;

}

int main() {
	float venituriInitiale[] = { 800, 50, 200, 900 };
	Companie c1("Firma", 4, venituriInitiale, 1000, false);

	c1.setListataLaBursa(true);
	c1.afisare();

	if (c1.faliment(3)) {
		cout << "Firma da faliment";
	}
	else {
		cout << "Firma nu da faliment";
	}
	int nrAni = 2;
	float* venituriTest = new float[2] {1100, 1300};

	adaugaVenit(venituriTest, nrAni, 1500);

	cout << "\nVenituri dupa adaugare: ";
	for (int i = 0; i < nrAni; i++) {
		cout << venituriTest[i] << ' ';
	}
	cout << '\n';
	delete[] venituriTest;
}