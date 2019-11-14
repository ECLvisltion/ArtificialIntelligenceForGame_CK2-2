#pragma once
#include "Chromosome.h"

class Population
{
private:
	vector<Chromosome> population; // ���ο� ������ ����
	vector<Chromosome> oldPopulation; // �θ� ������ ����
	Chromosome bestChrom;

	int popSize;
	int chromSize;
	double crossoverRate;
	double mutationRate;
	int totalFitness;

public:
	Population(int pSize, int gSize, double cRate, double mRate);
	~Population();

	// genetic operators
	Chromosome Selection();
	void Crossover(Chromosome& gene1, Chromosome& gene2);
	void Mutation(Chromosome& gene);
	void Evaluation();

	// getter
	Chromosome GetBestChrom() const { return bestChrom; }
	int GetWorstChromIndex();
	int GetPopSize() const { return popSize; }
	int GetChromSize() const { return chromSize; }
	double GetCrossoverRate() { return crossoverRate; }
	double GetMutationRate() { return mutationRate; }

	void CopyNewToOld();
	void PushChromToPop(int pos, Chromosome chrom) { population[pos] = chrom; }
	void Draw();
};
