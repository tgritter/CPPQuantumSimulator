// QuantumSimulator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <complex>
#include <cmath>
#include <iomanip>
#include <vector>
#include <math.h>
#include "Qubits.h"
#include "QuantumGates.h"
#include "Circuit.h"
#include "Examples.h"

using namespace std;

const int gridSize = 5;


int inputNumberOfQubits()
{
	std::cout << "Enter number of qubits: ";
	int x;
	std::cin >> x;

	return x;

}

Matrix getExample(Matrix &m)
{

	std::cout << "Enter Example Circuit: ";
	std::string s;
	std::cin >> s;

	if (s == "bs")
		return loadBellState();
	else if (s == "dj")
		return loadDeutschJosza();
	else if (s == "b")
		return loadBlank();
	else
		return m;

}


void addGate(Matrix &m)
{
	cout << "Enter Gate: ";
	std::string code;
	cin >> code;

	if (code == "HG" || code == "PX" || code == "PY" || code == "PZ" || code == "P2" || code == "P4" || code == "P8" || code == "CN" || code == "SS")
	{
		cout << "Enter Column: ";
		int col;
		cin >> col;

		cout << "Enter Target Qubit: ";
		int t;
		cin >> t;

		vector<int> targets;

		targets.push_back(t);

		int c;
		if (code == "CN" || code == "SS")
		{
			cout << "Enter Control Qubit: ";
			cin >> c;

			vector<int> control;

			control.push_back(c);

			m.AddGate("CC", col, control);
		}

		m.AddGate(code, col, targets);
	}else 
	{
		cout << "Invalid Gate Name" << endl;
	}

}


int main()
{
	//Create Qubits

	int n = inputNumberOfQubits();
	Matrix m = Matrix(n, gridSize);
	m.Print();
	m.Initialize();

	Register r(n);
	r.InitRegister();
	

	std::string c = "";

	while (c != "q") {

		cout << "Enter command: ";
		cin >> c;

		//Add Gate
		if (c == "a")
		{
			addGate(m);
			m.Print();
		}
		//Evalulate
		else if (c == "e")
		{
			m.Evaluate(r);
			r.Print();
			r.ResetState();
		}
		//Load
		else if (c == "l")
		{
			m = getExample(m);
			m.Print();

		}
		//Reset
		else if (c == "r")
		{
			n = inputNumberOfQubits();
			Register temp(n);
			r = temp;
			r.InitRegister();

			m = Matrix(n, gridSize);
			m.Initialize();
			m.Print();
		}
		else {
			cout << "Invalid command" << endl;
		}
	}

    return 0;
}

