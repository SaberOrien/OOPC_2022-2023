#include "Complex.h"
#include <cmath>
#include <iostream>

using namespace std;

Complex::Complex()
{
	init(0, 0);
}
Complex::Complex(float Real, float Imag)
{
	init(Real, Imag);
}
Complex::Complex(float Real)
{
	init(Real, 0);
}

void Complex::setReal(float RealVal)
{
	Real = RealVal;
}

float Complex::getReal()
{
	return Real;
}

void Complex::setImag(float ImagVal)
{
	Imag = ImagVal;
}

float Complex::getImag()
{
	return Imag;
}

void Complex::init(float Real, float Imag)
{
	this->Real = Real;
	this->Imag = Imag;
}

float Complex::getPhase()
{
	float theta = atan2(this->Imag, this->Real);
	return theta;
}

float Complex::getAmplitude()
{
	return sqrt(pow(this->Real, 2) + pow(this->Imag, 2));
}

Complex& Complex::operator=(const Complex& num)
{
	this->Real = num.Real;
	this->Imag = num.Imag;
	return *this;
}

bool operator==(Complex a, Complex b)
{
	return ((a.Real == b.Real && a.Imag == b.Imag));
}

bool operator!=(Complex a, Complex b)
{
	return (!(a.Real == b.Real && a.Imag == b.Imag));
}

Complex Complex::operator-()
{
	return Complex(-this->Real, -this->Imag);
}

Complex operator+(Complex a, Complex b)
{
	// Complex num(a);
	return a += b;
}

Complex& Complex::operator+=(const Complex& num)
{
	this->Real += num.Real;
	this->Imag += num.Imag;
	return *this;
}

Complex operator-(Complex a, Complex b)
{
	// Complex num(a);
	return a -= b;
}

Complex& Complex::operator-=(const Complex& num)
{
	this->Real -= num.Real;
	this->Imag -= num.Imag;
	return *this;
}

Complex operator*(Complex a, Complex b)
{
	// Complex num(a);
	return a *= b;
}

Complex& Complex::operator*=(const Complex& num)
{
	//(a + bi)(c + di) = ac + adi + cbi - bd = ac - bd + adi + cbi
	float tempReal = this->Real;
	tempReal = this->Real * num.Real - this->Imag * num.Imag;
	this->Imag = this->Real * num.Imag + this->Imag * num.Real;
	this->Real = tempReal;
	return *this;
}

Complex operator/(Complex a, Complex b)
{
	// Complex num(a);
	return a /= b;
}

Complex& Complex::operator/=(const Complex& num)
{
	if (num.Real == 0 && num.Imag == 0) {
		cout << "Trying to divide by 0; Aborting" << endl;
		abort();
	}
	float tempReal = this->Real;
	float simplifiedDenominator = pow(num.Real, 2) + pow(num.Imag, 2);
	tempReal = ((this->Real * num.Real) + (this->Imag * num.Imag)) /
			   simplifiedDenominator;
	this->Imag = ((this->Imag * num.Real) - (this->Real * num.Imag)) /
				 simplifiedDenominator;
	this->Real = tempReal;
	return *this;
}

ostream& operator<<(ostream& s, const Complex& num)
{
	char sign;
	if (num.Imag == 0) {
		s << num.Real;
		return s;
	}
	if (num.Imag >= 0) {
		sign = '+';
	}
	else {
		sign = '-';
	}
	s << "(" << num.Real << " " << sign << abs(num.Imag) << "i)";
	return s;
}
