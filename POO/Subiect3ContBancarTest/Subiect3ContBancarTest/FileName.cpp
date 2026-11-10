#include <iostream>
#include <string>

using namespace std;

enum Tip {
	CURENT,
	ECONOMII
};

class ContBancar {
	string titular = "-";
	const string IBAN;
	double sold = 0;
	int nrTranzactii = 0;
	double* tranzactii = nullptr;
	Tip tip = CURENT;
public:
	ContBancar(string _titular, string _IBAN, double _soldInitial, int _nrTranzactii, double* _tranzactii,Tip _tip) : IBAN(_IBAN){
		this->titular = _titular;
		this->tip = _tip;
		
		if (_soldInitial > 0) {
			this->sold = _soldInitial;
		}
		if (_nrTranzactii > 0 && _tranzactii != nullptr) {
			this->tranzactii = new double[_nrTranzactii];

			for (int i = 0; i < _nrTranzactii; i++) {
				if (_tranzactii[i] != 0 || this->sold + _tranzactii[i] >= 0) {
					this->tranzactii[this->nrTranzactii] = _tranzactii[i];
					this->sold += this->tranzactii[this->nrTranzactii];
					this->nrTranzactii++;
				}
			}
		}
	};

	double getSold() {
		return this->sold;
	}

	Tip getTip() {
		return this->tip;
	}

	double raport() {
		double totalDepuneri = 0;
		double totalRetrageri = 0;

		for (int i = 0; i < this->nrTranzactii; i++) {
			if (this->tranzactii[i] > 0) {
				totalDepuneri += this->tranzactii[i];
			}
			else {
				totalRetrageri = totalRetrageri - this->tranzactii[i];
			}
		}
		if (totalRetrageri == 0) return -1;
		return totalDepuneri / totalRetrageri;
	}

	void afisare() const {
		cout << "Titular: " << this->titular
			<< " | IBAN: " << this->IBAN
		<< " | Sold: " << this->sold
			<< " | Tip: " << (this->tip == CURENT ? "Curent" : "Economii")
			<< " | Nr. tranzactii: " << this->nrTranzactii
			<< " | Tranzactii:";

		for (int i = 0; i < this->nrTranzactii; i++) {
			if (this->tranzactii[i] > 0) {
				cout << " +" << this->tranzactii[i];
			}
			else {
				cout << " (" << -this->tranzactii[i] << ")";
			}
		}

		cout << '\n';
	}
};

double soldTotalTip(ContBancar* conturi, int nrConturi, Tip tipCont) {
	double total = 0;
	for (int i = 0; i < nrConturi; i++) {
		if (conturi[i].getTip() == tipCont) {
			total += conturi[i].getSold();
		}
	}
	return total;
}

int main() {
	double tranzactiiAna[] = { -50, 0, 12, -3 };
	double tranzactiiMihai[] = { 100 };
	double tranzactiiIoana[] = { 20, -10 };

	ContBancar conturi[] = {
		{ "Ana", "RO-TEST-01", 20, 4, tranzactiiAna, CURENT },
		{ "Mihai", "RO-TEST-02", 0, 1, tranzactiiMihai, ECONOMII },
		{ "Ioana", "RO-TEST-03", 60, 2, tranzactiiIoana, CURENT }
	};

	for (int i = 0; i < 3; i++) {
		conturi[i].afisare();
		cout << "Raport depuneri/retrageri: "
			<< conturi[i].raport() << '\n';
	}

	cout << "Total sold conturi: " << soldTotalTip(conturi, 3, CURENT);
}