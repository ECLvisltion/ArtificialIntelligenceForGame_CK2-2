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
	double random;

	for (int i = 0; i < chromSize; i++)
	{
		random = rand() / (double)RAND_MAX;
		genes[i] = (random >= 0.5) ? 1 : 0;
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
	cout << " ==> " << fitness << " : " << fitnessRate << endl;
}
