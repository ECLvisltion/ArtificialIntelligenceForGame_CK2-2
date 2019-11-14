#include "Chromosome.h"
#include "Population.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	srand((unsigned)time(nullptr));

	Population ga(6, 10, 0.7, 0.03);

	Chromosome bestChrom = ga.GetBestChrom();
	int bestFit = bestChrom.GetFitness();

	int popSize = ga.GetPopSize();
	int generation = 0;
	int sol = bestChrom.GetChromSize();

	double crossoverRate = ga.GetCrossoverRate();
	ga.Draw();
	cout << endl;

	// 섵책된 염색체를 저장할 변수
	Chromosome select1(sol);
	Chromosome select2(sol);

	while (true)
	{
		generation++;

		cout << "========== ";
		if (generation < 10) { cout << "0000" << generation; }
		else if (generation < 100) { cout << "000" << generation; }
		else if (generation < 1000) { cout << "00" << generation; }
		else if (generation < 10000) { cout << "0" << generation; }
		cout << " ==========" << endl;

		ga.Draw();
		cout << "Best Chrom : ";
		bestChrom.Draw();
		cout <<  endl;
		
		if (bestFit == sol) { break; }

		double random;
		for (int i = 0; i < popSize; i += 2)
		{
			random = rand() / (double)RAND_MAX;
			if (random < crossoverRate) // crossoverRate(0.7 == 70%)의 확률로 선택
			{
				select1 = ga.Selection();
				select2 = ga.Selection();
				ga.Crossover(select1, select2);
				ga.Mutation(select1);
				ga.Mutation(select2);
				select1.CalcFitness();
				select2.CalcFitness();
				ga.PushChromToPop(i, select1);
				ga.PushChromToPop(i + 1, select2);
			}
		}
		int worstIndex = ga.GetWorstChromIndex();
		ga.PushChromToPop(worstIndex, bestChrom);

		ga.Evaluation();
		ga.CopyNewToOld();

		bestChrom = ga.GetBestChrom();
		bestFit = bestChrom.GetFitness();
	}

	return 0;
}