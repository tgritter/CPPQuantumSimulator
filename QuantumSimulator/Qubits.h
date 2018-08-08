#include <iostream>
#include <complex>
#include <iomanip>
#include <vector>

using namespace std;

#pragma once
#ifndef QUBITS_H
#define QUBITS_H


class Qubit {

private:
	complex<double> m_a;
	complex<double> m_b;

public:

	Qubit();

	void SetAState(complex<double> a);

	void SetBState(complex<double> b);

	void Print();

	complex<double> getAState() { return m_a; }

	complex<double> getBState() { return m_b; }

};

class Register {

private:
	size_t m_size;
	vector<Qubit> m_reg;
	vector<complex<double>> m_states;

public:

	Register(size_t n);

	void InitRegister();

	void ResetState();

	void Print();

	void ApplyGate(vector<complex<double>> matrix);

	void SetState(vector<complex<double>> states);

	vector<complex<double>> Evaluate();

	vector<Qubit> getReg() { return m_reg; }
	vector<complex<double>> getState() { return m_states; }
};


#endif
