#pragma once
#include "List.h"
#include <iostream>
#include <string>
class Monom
{
public:
	Monom(const Monom& copyMonom);
	Monom(std::string Coeff, std::string Power);
	Monom(double Coeff, int Power);
	double getCoeff() const { return coeff; }
	int getPower() const { return power; }
	void setCoeff(double Coeff) { coeff = Coeff; }
	void setPower(int Power) { power = Power; }
private:
	double coeff;
	int power;
};

class Polynomial
{
public:
	Polynomial(const Polynomial& copyPol);
	Polynomial() : size(0) {}
	friend std::istream& operator>> (std::istream& in, Polynomial& obj);
	friend std::ostream& operator<< (std::ostream& out, const Polynomial& obj);
	Polynomial& operator=(const Polynomial&);
	Polynomial operator+(const Polynomial& right);
	Polynomial operator-(const Polynomial& right);
	Polynomial operator*(const Polynomial& right);
private:
	List<Monom> data;
	int size;
};