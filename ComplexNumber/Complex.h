#pragma once
#include <iostream>

class Complex {
  private:
	float Real;
	float Imag;
	void init(float Real, float Imag);

  public:
	Complex();
	Complex(float Real, float Imag);
	Complex(float Real);
	float getPhase();
	float getAmplitude();
	void setReal(float RealVal);
	float getReal();
	void setImag(float ImagVal);
	float getImag();
	Complex operator-();
	Complex& operator=(const Complex&);
	Complex& operator+=(const Complex&);
	Complex& operator-=(const Complex&);
	Complex& operator*=(const Complex&);
	Complex& operator/=(const Complex&);
	friend bool operator==(Complex a, Complex b);
	friend bool operator!=(Complex a, Complex b);
	friend std::ostream& operator<<(std::ostream& s, const Complex& num);
};
Complex operator+(Complex a, Complex b);
Complex operator-(Complex a, Complex b);
Complex operator*(Complex a, Complex b);
Complex operator/(Complex a, Complex b);
