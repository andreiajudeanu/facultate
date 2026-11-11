#include <iostream>
#include <string>
//Subiect5
using namespace std;

enum TipCuptor {
	GAZ,
	ELECTRIC,
	AIRFRYER
};

class Cuptor {
	string numeProducator = "-";
	int nrRetete = 0;
	int* gradeGatire = nullptr;
	int nrMaximGrade = 0;
	TipCuptor tipCuptor;
public:
	Cuptor(string _numeProducator, int _nrRetete, int* _gradeGatire, int _nrMaximGrade, TipCuptor _tipCuptor) {
		this->numeProducator = _numeProducator;
		this->tipCuptor = _tipCuptor;
		this->nrMaximGrade = _nrMaximGrade;
		if (_nrRetete > 0 && _gradeGatire != nullptr) {
			this->nrRetete = _nrRetete;
			this->gradeGatire = new int[this->nrRetete];
			for (int i = 0; i < this->nrRetete; i++) {
				if (_gradeGatire[i] < 100) {
					this->gradeGatire[i] = 100;
				}
				else {
					if (_gradeGatire[i] > this->nrMaximGrade) {
						this->gradeGatire[i] = this->nrMaximGrade;
					}
					else {
						this->gradeGatire[i] = _gradeGatire[i];
					}
				}
			}
		}
	}
	void sortareTimpAsteptare() {
		for (int i = 0; i < this->nrRetete - 1; i++) {
			for (int j = i + 1; j < this->nrRetete;j++) {
				if (this->gradeGatire[i] > this->gradeGatire[j]) {
					int aux = this->gradeGatire[i];
					this->gradeGatire[i] = this->gradeGatire[j];
					this->gradeGatire[j] = aux;
				}
			}
		}
	}

	void stergereSubMedie() {
		int suma = 0;
		for (int i = 0; i < this->nrRetete; i++) {
			suma += this->gradeGatire[i];
		}
		double medie = suma / this->nrRetete;

		int nrRamase = 0;
		for (int i = 0; i < this->nrRetete; i++) {
			if (this->gradeGatire[i] >= medie) {
				nrRamase++;
			}
		}

		if (nrRamase > 0) {
			int* aux = new int[nrRamase];
			int j = 0;
			for (int i = 0; i < this->nrRetete; i++) {
				if (this->gradeGatire[i] >= medie) {
					aux[j] = this->gradeGatire[i];
					j++;
				}
			}
			delete[] gradeGatire;
			this->gradeGatire = aux;
			this->nrRetete = nrRamase;
		}
		
	}

	void afisare() const {
		cout << "Producator: " << this->numeProducator << "\n";
		cout << "Numar retete: " << this->nrRetete << "\n";

		cout << "Grade gatire: ";
		for (int i = 0; i < this->nrRetete; i++) {
			if (i > 0) {
				cout << ", ";
			}
			cout << this->gradeGatire[i];
		}
		cout << "\n";

		cout << "Numar maxim grade: " << this->nrMaximGrade << "\n";

		cout << "Tip cuptor: ";
		if (this->tipCuptor == ELECTRIC) {
			cout << "Electric";
		}
		else {
			cout << "Gaz";
		}
		cout << "\n";
	}
};


int main() {
	int grade[] = { 200, 80, 300, 150 };

	Cuptor c1("Bosch", 4, grade, 250, ELECTRIC);

	c1.sortareTimpAsteptare();
	c1.afisare();
	cout << endl;
	c1.stergereSubMedie();
	c1.afisare();
}
