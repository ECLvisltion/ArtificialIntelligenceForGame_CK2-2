#pragma once
#include "Chromosome.h"

class Population
{
private:
	vector<Chromosome> population; // 새로운 세대의 모집
	vector<Chromosome> oldPopulation; // 부모 세대의 모집
	Chromosome bestChrom;

	int popSize;
	int chromSize = 20;
	double crossoverRate;
	double mutationRate;
	int totalFitness;

public:
	Population(int pSize, double cRate, double mRate);
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

	bool IsCorrect();
};
