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

typedef std::complex<double> cplex;

const double pi = 3.14159265359;

struct Gates {

	vector<cplex> NoGate = {
		cplex(1,0)
	};

	vector<cplex> UnitGate = {
		cplex(1,0), cplex(0,0),
		cplex(0,0), cplex(1,0)
	};

	vector<cplex> HGate = {
		(cplex(1,0) / sqrt(2)), (cplex(1,0) / sqrt(2)),
		(cplex(1,0) / sqrt(2)), (cplex(-1,0) / sqrt(2))
	};

	vector<cplex> PXGate = {
		cplex(0,0), cplex(1,0),
		cplex(1,0), cplex(0,0)
	};

	vector<cplex> PYGate = {
		cplex(0,0), cplex(0,-1),
		cplex(0,1), cplex(0,0)
	};

	vector<cplex> PZGate = {
		cplex(1,0), cplex(0,0),
		cplex(0,0), cplex(-1,0)
	};

	vector<cplex> R2 = {
		cplex(1,0), cplex(0,0),
		cplex(0,0), exp (cplex(0,1)*(pi / 2))
	};
	vector<cplex> R4 = {
		cplex(1,0), cplex(0,0),
		cplex(0,0), exp(cplex(0,1)*(pi / 4))
	};
	vector<cplex> R8 = {
		cplex(1,0), cplex(0,0),
		cplex(0,0), exp(cplex(0,1)*(pi / 8))
	};

	std::vector<cplex> CNGate = {
		cplex(1,0), cplex(0,0), cplex(0,0), cplex(0,0),
		cplex(0,0), cplex(1,0), cplex(0,0), cplex(0,0),
		cplex(0,0), cplex(0,0), cplex(0,0), cplex(1,0),
		cplex(0,0), cplex(0,0), cplex(1,0), cplex(0,0)
	};
	std::vector<cplex> SSGate = {
		cplex(1,0), cplex(0,0), cplex(0,0), cplex(0,0),
		cplex(0,0), cplex(0,0), cplex(1,0), cplex(0,0),
		cplex(0,0), cplex(1,0), cplex(0,0), cplex(0,0),
		cplex(0,0), cplex(0,0), cplex(0,0), cplex(1,0)
	};
};


QuantumGate::QuantumGate(): m_gateCode("--"), m_targets(vector<int>(1)) {}

QuantumGate::QuantumGate(const std::string gc = "--", vector<int> targets = {}) : m_gateCode(gc), m_targets(targets) {}

void QuantumGate::printGateCode()
{
	cout << "-" << m_gateCode;
}

vector<cplex> QuantumGate::GateMatrix()
{
	Gates g;

	if (m_gateCode == "--")
	{
		return g.UnitGate;
	}
	else if (m_gateCode == "CC")
	{
		return g.NoGate;
	}
	else if (m_gateCode == "HG")
	{
		return g.HGate;
	}
	else if (m_gateCode == "PX")
	{
		return g.PXGate;
	}
	else if (m_gateCode == "PY")
	{
		return g.PYGate;
	}
	else if (m_gateCode == "PZ")
	{
		return g.PZGate;
	}
	else if (m_gateCode == "R2")
	{
		return g.R2;
	}
	else if (m_gateCode == "R4")
	{
		return g.R4;
	}
	else if (m_gateCode == "R8")
	{
		return g.R8;
	}
	else if (m_gateCode == "CN")
	{
		return g.CNGate;
	}
	else if (m_gateCode == "SS")
	{
		return g.SSGate;
	}
}



