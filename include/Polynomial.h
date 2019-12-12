#pragma once
#include "List.h"

struct Monom
{
	Monom(const Monom& copyMonom);
	Monom(double Coeff = 0, int Power = 0, Monom* Next = nullptr);
	double coeff;
	int power;
};

class Polynomial
{
public:
	Polynomial(const Polynomial& copyPol);
	Polynomial() : size(0) {}
private:
	List<Monom> data;
	int size;
};