#pragma once
#include <vector>
using namespace std;

class Chromosome
{
private:
	vector<int> genes;
	int chromSize;
	int fitness;
	double fitnessRate;

public:
	Chromosome();
	Chromosome(int size);
	~Chromosome();
	// setter
	void SetFitnessRate(double rate) { fitnessRate = rate; }
	void ResetChromosome(vector<int> genes) { this->genes = genes; }
	// getter
	vector<int> GetChromosome() { return genes; }
	int GetChromSize() const { return chromSize; }
	int GetFitness() const { return fitness; }
	double GetFitnessRate() const { return fitnessRate; }

	void ResetChromosome(int size);
	void InitChromosome();
	void CalcFitness();
	void Draw();

	int GetA();
	int GetB();
	int GetC();
	int GetD();
};
