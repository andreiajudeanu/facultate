#include <iostream>
#include <string>

using namespace std;

enum TipCompanie{
	SRL,
	SA
};

class Companie {
	string denumire = "anonim";
	int nrAngajati = 0;
	float* salariuLunar = nullptr;
	float salariuMaxim = 0;
	float fondTotalSalarii = 0;
	TipCompanie tip = SRL;
public:
	Companie(string _denumire, int _nrAngajati, float* _salariuLunar, float _salariuMaxim,
		float _fondTotalSalarii, TipCompanie _tip) {
		this->denumire = _denumire;
		if (_fondTotalSalarii > 0) {
			this->fondTotalSalarii = _fondTotalSalarii;
		}
		if (_salariuMaxim > 0) {
			this->salariuMaxim = _salariuMaxim;
		}
		this->tip = _tip;
		if (_nrAngajati > 0 && _salariuLunar != nullptr) {
			this->salariuLunar = new float[this->nrAngajati];
			float totalLunar = 0;
			for (int i = 0; i < _nrAngajati; i++) {
				if (_salariuLunar[i] < 0) {
					_salariuLunar[i] = -_salariuLunar[i];
				}
				if (_salariuLunar[i] > this->salariuMaxim) {
					_salariuLunar[i] = this->salariuMaxim;
				}
				if ((totalLunar + _salariuLunar[i]) * 12 <= this->fondTotalSalarii) {
					this->salariuLunar[this->nrAngajati] = _salariuLunar[i];
					this->nrAngajati++;
					totalLunar += _salariuLunar[i];
				}	
			}
		}
	}

	int nrMinimAngajati() {
		float salariuAnual = 0;
		for (int i = 0; i < this->nrAngajati; i++) {
			salariuAnual += this->salariuLunar[i];
		}
		salariuAnual *= 12;
		float fondRamas = 0;
		fondRamas = this->fondTotalSalarii - salariuAnual;
		return (int)(fondRamas / (this->salariuMaxim*12));
	}

	void afisare() const {
		cout << "Companie: " << this->denumire
			<< " | Numar angajati: " << this->nrAngajati
			<< " | Salariu maxim: " << this->salariuMaxim
			<< " | Fond anual: " << this->fondTotalSalarii
			<< " | Tip: ";
		if (this->tip == SRL) {
			cout << "SRL";
		}
		else cout << "SA";

		cout << " | Salarii lunare: ";

		for (int i = 0; i < this->nrAngajati; i++) {
			if (i > 0) {
				cout << ", ";
			}
			cout << this->salariuLunar[i];
		}

		cout << '\n';
	}
};

void stergereUltimSalMaxim(float*& salarii, int& nrSalarii) {
	for (int i = 0; i < nrSalarii; i++) {

	}
}

int main() {
	float salariiInitiale[] = { 3000, -7000, 4000 };
	Companie c1("Firma", 3, salariiInitiale, 5000, 240000, SA);

	c1.afisare();
	cout << endl;
	cout << c1.nrMinimAngajati();
	
}