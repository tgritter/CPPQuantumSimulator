#include "stdafx.h"
#include <iostream>
#include <complex>
#include <cmath>
#include <iomanip>
#include <vector>
#include <math.h>
#include "Qubits.h"

using namespace std;
#pragma once

#ifndef QUANTUMGATES_H
#define QUANTUMGATES_H



class QuantumGate {

private:
	std::string m_gateCode;
	vector<int> m_targets;

public:
	QuantumGate();
	explicit QuantumGate(const std::string gc, vector<int> targets);

	std::string getGateCode(){return m_gateCode;}

	vector<int> getTargets() { return m_targets; }

	void printGateCode();

	vector<complex<double>> GateMatrix();
};

#endif
