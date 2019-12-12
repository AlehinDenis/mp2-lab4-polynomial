#include "Polynomial.h"

Monom::Monom(const Monom& copyMonom) :
	coeff(copyMonom.coeff), power(copyMonom.power), next(copyMonom.next) {}

Monom::Monom(double Coeff = 0, int Power = 0, Monom* Next = nullptr) :
	coeff(Coeff), power(Power), next(Next) {}

Polynomial::Polynomial(const Polynomial& copyPol) : 
	size(copyPol.size), data(copyPol.data){}
