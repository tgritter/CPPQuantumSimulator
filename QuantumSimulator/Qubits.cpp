#include "stdafx.h"
#include <iostream>
#include <complex>
#include <iomanip>
#include "Qubits.h"
#include <bitset>

using namespace std;

Qubit::Qubit(): m_a(complex<double>(1,0)), m_b(complex<double>(0,0))
{
}

void Qubit::SetAState(complex<double> a)
{
	m_a = a;

}

void Qubit::SetBState(complex<double> b)
{
	m_b = b;

}


void Qubit::Print()
{
	std::cout << std::setprecision(8) << std::fixed;

	std::cout << m_a.real() << "+" << m_a.imag() << "i |0> Prob: --%" << std::endl;
	std::cout << m_b.real() << "+" << m_b.imag() << "i |1> Prob: --%" << std::endl;
}

Register::Register(size_t n): m_size(n), m_reg() {}

void Register::SetState(vector<complex<double>> newState)
{
	m_states = newState;
}

void Register::InitRegister() 
{
	for (size_t i = 0; i < m_size; ++i)
	{
		Qubit q;
		m_reg.push_back(q);
	}

	ResetState();
}

void Register::ResetState()
{
	std::vector<complex<double>> v1;
	v1.push_back(m_reg[0].getAState());
	v1.push_back(m_reg[0].getBState());

	for (unsigned int i = 1; i < m_reg.size(); ++i)
	{
		vector<complex<double>> v2;
		v2.push_back(m_reg[i].getAState());
		v2.push_back(m_reg[i].getBState());

		vector<complex<double>> newVector;

		newVector.reserve(v1.size() * v2.size());

		for (unsigned int i = 0; i < v1.size(); ++i)
		{
			for (unsigned int j = 0; j < v2.size(); ++j)
			{
				newVector.push_back(v1[i] * v2[j]);
			}
		}
		v1 = newVector;
	}

	SetState(v1);
}



void Register::Print()
{
	vector<complex<double>> states = getState();

	std::cout << "Measure: " << std::endl;
	std::cout << std::fixed;
	std::cout << std::setprecision(8);


	for (unsigned int i = 0; i < states.size(); ++i)
	{

		std::string s = std::bitset< 64 >(i).to_string();
		
		cout << "State |";

		cout << s.substr(s.length() - log2(states.size()));

		cout << "> " << states.at(i).real() << "+" << states.at(i).imag();
		
		cout << " Prob: " << ((states.at(i).real()* states.at(i).real()) + (states.at(i).imag()* states.at(i).imag())) * 100 << "%" << '\n';

	}
}

void Register::ApplyGate(vector<complex<double>> matrix)
{

	vector<complex<double>> reg = getState();

	vector<complex<double>> newState(reg.size());

	size_t matrixSize = (sqrt(matrix.size()));

	for (size_t i = 0; i < matrixSize; ++i) {

		complex<double> newNumber(0, 0);

		for (size_t j = 0; j < matrixSize; ++j)
		{
			newNumber += (reg[j] * matrix.at(i * (matrixSize) + j));
		}
		newState[i] = newNumber;

	}

	SetState(newState);
}





