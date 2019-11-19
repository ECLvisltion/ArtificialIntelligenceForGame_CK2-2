#include "Chromosome.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

Chromosome::Chromosome()
{
	ResetChromosome(6);
}

Chromosome::Chromosome(int size)
{
	ResetChromosome(size);
}

Chromosome::~Chromosome()
{
}

void Chromosome::ResetChromosome(int size)
{
	chromSize = size;
	fitness = 0;
	fitness = 0.0;
	genes.resize(size);
	InitChromosome();
}

void Chromosome::InitChromosome()
{
	for (int i = 0; i < chromSize; i++)
	{
		genes[i] = 0;
	}
}

void Chromosome::CalcFitness()
{
	fitness = 0;
	for(int i = 0; i < chromSize; i++)
	{
		fitness += genes[i];
	}
}

void Chromosome::Draw()
{
	for (int i = 0; i < chromSize; i++)
	{
		cout << genes[i];
	}
	// cout << " ==> " << fitness << " : " << fitnessRate << endl;
	cout << " ==> " << GetA() + (GetB() * 2) + (GetC() * 3) + (GetD() * 4);

	if (GetA() + (GetB() * 2) + (GetC() * 3) + (GetD() * 4) == 30)
		cout << " : Correct";

	cout << endl;
}

int Chromosome::GetA()
{
	// 0 ~ 4
	return ((genes[0] * 16) + (genes[1] * 8) + (genes[2] * 4) + (genes[3] * 2) + genes[4]);
}

int Chromosome::GetB()
{
	// 5 ~ 9
	return ((genes[5] * 16) + (genes[6] * 8) + (genes[7] * 4) + (genes[8] * 2) + genes[9]);
}

int Chromosome::GetC()
{
	// 10 ~ 14
	return ((genes[10] * 16) + (genes[11] * 8) + (genes[12] * 4) + (genes[13] * 2) + genes[14]);
}

int Chromosome::GetD()
{
	// 15 ~ 19
	return ((genes[15] * 16) + (genes[16] * 8) + (genes[17] * 4) + (genes[18] * 2) + genes[19]);
}
