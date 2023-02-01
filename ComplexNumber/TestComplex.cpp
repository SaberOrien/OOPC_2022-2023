#include "Complex.h"
#include <iostream>

using namespace std;

void setNumbers(Complex&, Complex&, Complex&, Complex&);

void testEqalNotEqal(Complex, Complex, Complex, Complex);

void testAddition(Complex, Complex, Complex, Complex);
void testSetAndAdditionNoBrackets(Complex, Complex, Complex);
void testSetAndAdditionWithBrackets(Complex, Complex, Complex);

void testSubtraction(Complex, Complex, Complex, Complex);
void testSetAndSubtractionNoBrackets(Complex, Complex, Complex);
void testSetAndSubtractionWithBrackets(Complex, Complex, Complex);

void testMultiplication(Complex, Complex, Complex, Complex);
void testSetAndMultiplicationNoBrackets(Complex, Complex, Complex);
void testSetAndMultiplicationWithBrackets(Complex, Complex, Complex);

void testDivision(Complex, Complex, Complex, Complex);
void testSetAndDivisionNoBrackets(Complex, Complex, Complex);
void testSetAndDivisionWithBrackets(Complex, Complex, Complex);

void phaseAndAmplitude(Complex, Complex, Complex, Complex);
void mixedComplexProblems(Complex, Complex, Complex, Complex);

void printValuesOfParameters(Complex, Complex, Complex, Complex);

int main()
{
	Complex A;
	Complex B;
	Complex C;
	Complex D;
	setNumbers(A, B, C, D);
	cout << "Running tests for the complex numbers: \nA" << A << "; B" << B
		 << "; \nC" << C << "; D" << D << ";" << endl;
	testEqalNotEqal(A, B, C, D);

	testAddition(A, B, C, D);
	testSubtraction(A, B, C, D);
	testMultiplication(A, B, C, D);
	testDivision(A, B, C, D);

	phaseAndAmplitude(A, B, C, D);
	mixedComplexProblems(A, B, C, D);
	return 0;
}

void setNumbers(Complex& A, Complex& B, Complex& C, Complex& D)
{
	float a = 4.5;
	float b = -6.2;
	float c = 5.7;
	float d = -6.3;
	A.setReal(a);
	A.setImag(b);
	B.setReal(b);
	B.setImag(c);
	C.setReal(c);
	C.setImag(d);
	D.setReal(d);
	D.setImag(a);
}

void printValuesOfParameters(Complex A, Complex B, Complex C, Complex E)
{
	cout << "A: " << A << endl;
	cout << "B: " << B << endl;
	cout << "C: " << C << endl;
	cout << "E: " << E << endl;
}

void testEqalNotEqal(Complex A, Complex B, Complex C, Complex D)
{
	cout << "\n===Checking == and != operators===\n" << endl;
	cout << "Check D + 7 == 7 + D" << endl;
	if (D + 7 == 7 + D)
		cout << "True!" << endl;
	else
		cout << "False!" << endl;

	cout << "\nCheck if A == B" << endl;
	if ((A == B))
		cout << "True!" << endl;
	else
		cout << "False!" << endl;

	cout << "\nCheck if C != B" << endl;
	if ((C != B))
		cout << "True!" << endl;
	else
		cout << "False!" << endl;

	cout << "\nCheck if A == 7" << endl;
	if ((A == 7))
		cout << "True!" << endl;
	else
		cout << "False!" << endl;

	cout << "\nCheck if A != A" << endl;
	if ((A != A))
		cout << "True!" << endl;
	else
		cout << "False!" << endl;
}

void testAddition(Complex A, Complex B, Complex C, Complex D)
{
	cout << "\n\n===Testing by Addition===\n" << endl;
	cout << "A + B + C = " << A + B + C << endl;
	cout << "(B + C) + D = " << (B + C) + D << endl;
	cout << "D + 7 + C = " << D + 7 + C << endl;
	cout << "7 + D + 3 = " << 7 + D + 3 << endl;
	testSetAndAdditionNoBrackets(A, B, C);
	testSetAndAdditionWithBrackets(A, B, C);
}

void testSetAndAdditionNoBrackets(Complex A, Complex B, Complex C)
{
	Complex E;
	cout << "\n===Checking E = A += B += C===\n" << endl;
	cout << "Pre-addition" << endl;
	printValuesOfParameters(A, B, C, E);
	E = A += B += C;
	cout << "\nPost-addition" << endl;
	printValuesOfParameters(A, B, C, E);
}

void testSetAndAdditionWithBrackets(Complex A, Complex B, Complex C)
{
	Complex E;
	cout << "\n===Checking E = (A += B) += C===\n" << endl;
	cout << "Pre-addition" << endl;
	printValuesOfParameters(A, B, C, E);
	E = (A += B) += C;
	cout << "\nPost-addition" << endl;
	printValuesOfParameters(A, B, C, E);
}

void testSubtraction(Complex A, Complex B, Complex C, Complex D)
{
	cout << "\n\n===Testing by Subtraction===\n" << endl;
	cout << "A - B - C = " << A - B - C << endl;
	cout << "(B - C) - D = " << (B - C) - D << endl;
	cout << "D - 7 - C = " << D - 7 - C << endl;
	cout << "7 - D - 3 = " << 7 - D - 3 << endl;
	testSetAndSubtractionNoBrackets(A, B, C);
	testSetAndSubtractionWithBrackets(A, B, C);
}

void testSetAndSubtractionNoBrackets(Complex A, Complex B, Complex C)
{
	Complex E;
	cout << "\n===Checking E = A -= B -= C===\n" << endl;
	cout << "Pre-subtraction" << endl;
	printValuesOfParameters(A, B, C, E);
	E = A -= B -= C;
	cout << "\nPost-subtraction" << endl;
	printValuesOfParameters(A, B, C, E);
}

void testSetAndSubtractionWithBrackets(Complex A, Complex B, Complex C)
{
	Complex E;
	cout << "\n===Checking E = (A -= B) -= C===\n" << endl;
	cout << "Pre-subtraction" << endl;
	printValuesOfParameters(A, B, C, E);
	E = (A -= B) -= C;
	cout << "\nPost-subtraction" << endl;
	printValuesOfParameters(A, B, C, E);
}

void testMultiplication(Complex A, Complex B, Complex C, Complex D)
{
	cout << "\n\n===Testing by Multiplication===\n" << endl;
	cout << "A * B * C = " << A * B * C << endl;
	cout << "(B * C) * D = " << (B * C) * D << endl;
	cout << "D * 7 * C = " << D * 7 * C << endl;
	cout << "7 * D * 3 = " << 7 * D * 3 << endl;
	testSetAndMultiplicationNoBrackets(A, B, C);
	testSetAndMultiplicationWithBrackets(A, B, C);
}

void testSetAndMultiplicationNoBrackets(Complex A, Complex B, Complex C)
{
	Complex E;
	cout << "\n===Checking E = A *= B *= C===\n" << endl;
	cout << "Pre-multiplication" << endl;
	printValuesOfParameters(A, B, C, E);
	E = A *= B *= C;
	cout << "\nPost-multiplication" << endl;
	printValuesOfParameters(A, B, C, E);
}

void testSetAndMultiplicationWithBrackets(Complex A, Complex B, Complex C)
{
	Complex E;
	cout << "\n===Checking E = (A *= B) *= C===\n" << endl;
	cout << "Pre-multiplication" << endl;
	printValuesOfParameters(A, B, C, E);
	E = (A *= B) *= C;
	cout << "\nPost-multiplication" << endl;
	printValuesOfParameters(A, B, C, E);
}

void testDivision(Complex A, Complex B, Complex C, Complex D)
{
	cout << "\n\n===Testing by Division===\n" << endl;
	cout << "A / B / C = " << A / B / C << endl;
	cout << "(B / C) / D = " << (B / C) / D << endl;
	cout << "D / 7 / C = " << D / 7 / C << endl;
	cout << "7 / D / 3 = " << 7 / D / 3 << endl;
	// cout << "D / 0 = " << D / 0 << endl;
	testSetAndDivisionNoBrackets(A, B, C);
	testSetAndDivisionWithBrackets(A, B, C);
}

void testSetAndDivisionNoBrackets(Complex A, Complex B, Complex C)
{
	Complex E;
	cout << "\n===Checking E = A /= B /= C===\n" << endl;
	cout << "Pre-division" << endl;
	printValuesOfParameters(A, B, C, E);
	E = A /= B /= C;
	cout << "\nPost-division" << endl;
	printValuesOfParameters(A, B, C, E);
}

void testSetAndDivisionWithBrackets(Complex A, Complex B, Complex C)
{
	Complex E;
	cout << "\n===Checking E = (A /= B) /= C===\n" << endl;
	cout << "Pre-division" << endl;
	printValuesOfParameters(A, B, C, E);
	E = (A /= B) /= C;
	cout << "\nPost-division" << endl;
	printValuesOfParameters(A, B, C, E);
}

void phaseAndAmplitude(Complex A, Complex B, Complex C, Complex D)
{
	cout << "\n\nGet Phase And Amplitude: " << endl;
	cout << "For A" << A << ": \n-phase: " << A.getPhase()
		 << "\n-amplitude: " << A.getAmplitude() << endl;
	cout << "For B" << B << ": \n-phase: " << B.getPhase()
		 << "\n-amplitude: " << B.getAmplitude() << endl;
	cout << "For C" << C << ": \n-phase: " << C.getPhase()
		 << "\n-amplitude: " << C.getAmplitude() << endl;
	cout << "For D" << D << ": \n-phase: " << D.getPhase()
		 << "\n-amplitude: " << D.getAmplitude() << endl;
}

void mixedComplexProblems(Complex A, Complex B, Complex C, Complex D)
{
	cout << "\n\nTesting mixed-operation problems: " << endl;
	cout << "(A - 2) * (B - 7) = " << (A - 2) * (B - 7) << endl;
	cout << "(C * D) / (7+ 3 + B) = " << (C * D) / (7 + 3 + B) << endl;
	cout << "(A / 3) - (B * C * 2 * D) = " << (A / 3) - (B * C * 2 * D) << endl;
	cout << "A * A + B * B + 8 = " << A * A + B * B + 8 << endl;
	cout << "(A += B) * A / A = " << (A += B) * A / A << endl;
	cout << "2 * A * A + 3 * B = " << 2 * A * A + 3 * B << endl;
	cout << "(A/=B) + A * B = " << (A /= B) + A * B << endl;
	cout << "8 * A / (3 * B) - B + 5 * A = " << 8 * A / (3 * B) - B + 5 * A
		 << endl;
	cout << "-7 * B * 2.5 * A - 3 * B / B = " << -7 * B * 2.5 * A - 3 * B / B
		 << endl;
	cout << "(-B -= A) * (-A + B) = " << (-B -= A) * (-A + B) << endl;
	cout << "B / (-A) + A * (-B) = " << B / (-A) + A * (-B) << endl;
	cout << "3.8 * (B *= A) / (7 * A) = " << 3.8 * (B *= A) / (7 * A) << endl;
	cout << "-2 * A * 6*B + B / (3.2*A) = " << -2 * A * 6 * B + B / (3.2 * A)
		 << endl;
}
