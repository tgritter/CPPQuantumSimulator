#include "stdafx.h"
#include <iostream>
#include <complex>
#include <cmath>
#include <iomanip>
#include <vector>
#include <math.h>
#include "Qubits.h"
#include "QuantumGates.h"

using namespace std;
#pragma once

#ifndef CIRCUIT_H
#define CIRCUIT_H

class Matrix
{
public:
	Matrix(size_t rows, size_t cols);
	QuantumGate& operator()(size_t i, size_t j);
	QuantumGate operator()(size_t i, size_t j) const;
	void AddGate(std::string code, int col, vector<int> target);
	void Evaluate(Register &r);
	void Initialize();
	void Print();

private:
	size_t mRows;
	size_t mCols;
	std::vector<QuantumGate> mData;
};


#endif
