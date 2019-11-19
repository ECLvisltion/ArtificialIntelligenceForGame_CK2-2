#include "Chromosome.h"
#include "Population.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

Population::Population(int pSize, double cRate, double mRate)
	: popSize(pSize), crossoverRate(cRate), mutationRate(mRate)
{
	population.resize(pSize);
	oldPopulation.resize(pSize);

	for (int i = 0; i < pSize; i++)
	{
		population[i].ResetChromosome(chromSize);
	}

	Evaluation();
	CopyNewToOld();
}

Population::~Population()
{
}

Chromosome Population::Selection()
{
	int selectIndex = 0;
	double random = rand() / (double)RAND_MAX;
	double selRate = 0.0;
	for(int i = 0; i < popSize; i++)
	{
		selRate += population[i].GetFitnessRate();

		if (selRate > random)
		{
			selectIndex = i;
			break;
		}
	}

	return oldPopulation[selectIndex];
}

void Population::Crossover(Chromosome & gene1, Chromosome & gene2)
{
	int crossPoint = rand() % chromSize;
	vector<int> c1 = gene1.GetChromosome();
	vector<int> c2 = gene2.GetChromosome();

	for (int i = 0; i < crossPoint; i++)
	{
	int temp = c1[i];
	c1[i] = c2[i];
	c2[i] = temp;
	}
	gene1.ResetChromosome(c1);
	gene1.ResetChromosome(c2);
}

void Population::Mutation(Chromosome& gene)
{
	double random = rand() / double(RAND_MAX);

	if (random > mutationRate) { return; }

	int mutationPoint = rand() % 4;
	vector<int> g = gene.GetChromosome();

	for (int i = 4; i >= 0; i--)
	{
		if (g[i + (mutationPoint * 5)] == 0) { g[i + (mutationPoint * 5)]++; break; }
		else { g[i + (mutationPoint * 5)] = 0; }
	}

	gene.ResetChromosome(g);
}

void Population::Evaluation()
{
	totalFitness = 0;
	int bestFit = 0;
	int bestChromIndex = 0;

	for (int i = 0; i < popSize; i++)
	{
		/*
		population[i].CalcFitness();
		int curFitness = population[i].GetFitness();
		if (curFitness > bestFit)
		{
			bestChromIndex = i;
			bestFit = curFitness;
		}
		totalFitness += curFitness;
		*/
		int total = (population[i].GetD() * 4) + (population[i].GetC() * 3) + (population[i].GetB() * 2) + population[i].GetA();

		if (total < 30 && total > bestFit)
		{
			bestChromIndex = i;
			bestFit = population[i].GetD();
		}
	}

	// Setting fitnessRate
	for (int i = 0; i < popSize; i++)
	{
		double fRate = population[i].GetFitness() / (double)totalFitness;
		population[i].SetFitnessRate(fRate);
	}

	bestChrom = population[bestChromIndex];
}

int Population::GetWorstChromIndex()
{
	int worstFit = population[0].GetFitness();
	int worstIndex = 0;

	for (int i = 1; i < popSize; i++)
	{
		if (worstFit > population[i].GetFitness())
		{
			worstFit > population[i].GetFitness();
			worstIndex = i;
		}
	}

	return worstIndex;
}

void Population::CopyNewToOld()
{
	for (int i = 0; i < popSize; i++)
	{
		oldPopulation[i] = population[i];
	}
}

void Population::Draw()
{
	for (int i = 0; i < popSize; i++)
	{
		population[i].Draw();
	}
}

bool Population::IsCorrect()
{
	for (int i = 0; i < popSize; i++)
	{
		if ((population[i].GetD() * 4) + (population[i].GetC() * 3) + (population[i].GetB() * 2) + population[i].GetA() == 30)
		{
			return true;
		}
	}
	return false;
}
