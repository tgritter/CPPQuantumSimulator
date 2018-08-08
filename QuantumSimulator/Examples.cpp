#include "stdafx.h"
#include <iostream>
#include <complex>
#include <iomanip>
#include <vector>
#include "Circuit.h"

using namespace std;

Matrix loadBlank()
{
	Matrix m = Matrix(2, 5);

	return m;

}

Matrix loadBellState()
{
	Matrix m = Matrix(2, 5);

	vector<int> t1 = { 0 };
	m.AddGate("HG", 0, t1);

	vector<int> t2 = { 1 };
	m.AddGate("CN", 1, t2);

	return m;

}

Matrix loadDeutschJosza()
{
	Matrix m = Matrix(3, 5);

	vector<int> t1 = { 0 };
	m.AddGate("HG", 0, t1);

	vector<int> t2 = { 1 };
	m.AddGate("HG", 0, t2);

	vector<int> t3 = { 2 };
	m.AddGate("HG", 0, t3);

	vector<int> t4 = { 2 };
	m.AddGate("HG", 1, t4);

	vector<int> t5 = { 0 };
	m.AddGate("PZ", 2, t5);

	vector<int> t6 = { 1 };
	m.AddGate("CC", 2, t6);

	vector<int> t7 = { 2 };
	m.AddGate("CN", 2, t7);

	vector<int> t8 = { 2 };
	m.AddGate("HG", 3, t8);

	vector<int> t9 = { 0 };
	m.AddGate("HG", 4, t9);

	vector<int> t10 = { 1 };
	m.AddGate("HG", 4, t10);

	vector<int> t11 = { 2 };
	m.AddGate("HG", 4, t11);

	return m;

}