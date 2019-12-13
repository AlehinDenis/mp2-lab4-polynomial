#include "Polynomial.h"
#include <string>

Monom::Monom(const Monom& copyMonom) : 
	coeff(copyMonom.coeff), power(copyMonom.power) {}

Monom::Monom(std::string Coeff, std::string Power)
{
	coeff = stod(Coeff);
	power = stoi(Power);
}

Monom::Monom(double Coeff, int Power)
{
	coeff = Coeff;
	power = Power;
}

Polynomial::Polynomial(const Polynomial& copyPol) : 
	size(copyPol.size), data(copyPol.data){}

Polynomial& Polynomial::operator=(const Polynomial& copyPol)
{
	if (this == &copyPol)
		return *this;
	size = copyPol.size;
	data = copyPol.data;
	return *this;
}

Polynomial Polynomial::operator+(const Polynomial& right)
{
	if (size != right.size)
		throw ("Error");
	Polynomial temp = *this;
	for (int i = 0; i < temp.size; i++)
	{
		int power = temp.data.getElement(i).getPower();
		for(int j = 0; j<right.size;j++)
			if (right.data.getElement(j).getPower() == power)
			{
				double leftCoeff = temp.data.getElement(i).getCoeff();
				double rightCoeff = right.data.getElement(j).getCoeff();
				temp.data.changeElement(i, Monom(leftCoeff + rightCoeff, power));
				rightCoeff = 1;
				break;
			}
	}
	return temp;
}

Polynomial Polynomial::operator-(const Polynomial& right)
{
	return Polynomial();
}

Polynomial Polynomial::operator*(const Polynomial& right)
{
	return Polynomial();
}

std::istream& operator>>(std::istream& in, Polynomial& obj)
{
	std::string pol;
	in >> pol;
	int i = 0;
	while (i < pol.size())
	{
		std::string coeff = "";
		std::string power = "";
		while (pol[i] != '*')
			coeff += pol[i++];
		i += 3;
		while ((pol[i] != '+' && pol[i] != '-') && i != pol.size())
			power += pol[i++];
		obj.data.push_back(Monom(coeff, power));
		obj.size++;
	}
	return in;
}

std::ostream& operator<<(std::ostream& out, const Polynomial& obj)
{
	for (int i = 0; i < obj.size; i++)
	{
		out << obj.data.getElement(i).getCoeff() << "*x^"
			<< obj.data.getElement(i).getPower();
		if (i != obj.size - 1)
			if (obj.data.getElement(i + 1).getCoeff() >= 0) out << "+";
			else out << "-";
	}
	return out;
}
