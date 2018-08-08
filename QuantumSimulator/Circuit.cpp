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

using namespace std;

const int gridSize = 10;

Matrix::Matrix(size_t rows, size_t cols): mRows(rows), mCols(cols),mData(rows * cols){}

void Matrix::Initialize()
{
	for (size_t i = 0; i < mRows; ++i) {
		for (size_t j = 0; j < mCols; ++j) {
			QuantumGate qg;
			mData[i * mCols + j] = qg;
		}
	}
}

QuantumGate& Matrix::operator()(size_t i, size_t j)
{
	return mData[i * mCols + j];
}

QuantumGate Matrix::operator()(size_t i, size_t j) const
{
	return mData[i * mCols + j];
}

void Matrix::AddGate(std::string code, int col, vector<int> targets)
{
	QuantumGate qg(code, targets);

	int row = targets[0];

	mData[row * mCols + col] = qg;
}

void Matrix::Evaluate(Register &r)
{
	for (size_t i = 0; i < mCols; ++i)
	{
		vector<complex<double>> v1 = mData[i].GateMatrix();

		for (size_t j = 1; j < mRows; ++j)
		{
			vector<complex<double>> v2 = mData[i + (mCols * j)].GateMatrix();
			vector<complex<double>> newVector;

			int m1size = sqrt(v1.size());
			int m2size = sqrt(v2.size());

			for (int x = 0; x < m1size; ++x)
			{
				for (int y = 0; y < m2size; ++y)
				{
					for (int w = 0; w < m1size; ++w)
					{
						for (int z = 0; z < m2size; ++z)
						{
							newVector.push_back(v1[x * m1size + w] * v2[y * m2size + z]);
						}
					}
				}
			}

			v1 = newVector;

		}
		r.ApplyGate(v1);
	}
}

void Matrix::Print()
{
	for (size_t i = 0; i < mRows; ++i) {
		cout << "0: ";
		for (size_t j = 0; j < mCols; ++j) {

			mData[i * mCols + j].printGateCode();
		}
		cout << endl;
	}
}