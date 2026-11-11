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
						_gradeGatire[i] = this->nrMaximGrade;
					}
				}
			}
		}
	}
};

int main() {
