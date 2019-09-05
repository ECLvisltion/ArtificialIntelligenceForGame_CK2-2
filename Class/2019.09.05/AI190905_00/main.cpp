#include "Duck.h"
#include "Flyable.h"
#include "FlyWithBigWings.h"
#include "FlyWithWings.h"
#include "MallardDuck.h"
#include "Quackable.h"
#include "Quacking.h"
#include "QuackingLoud.h"
#include "RedHeadDuck.h"

int main()
{
	Duck * mallardDuck = new MallardDuck();
	Duck * redHeadDuck = new RedHeadDuck();

	Flyable * mallardDuckFly;
	Quackable * mallardDuckQuack;
	Flyable * redHeadDuckFly;
	Quackable * redHeadDuckQuack;

	FlyWithWings normalWings;
	FlyWithBigWings bigWings;
	Quacking normalQuack;
	QuackingLoud loudQuack;

	// ------------------------------

	mallardDuckFly = &normalWings;
	mallardDuckQuack = &normalQuack;

	mallardDuck->SetFly(mallardDuckFly);
	mallardDuck->SetQuack(mallardDuckQuack);

	mallardDuck->Draw();
	mallardDuck->PerformFly();
	mallardDuck->PerformQuack();

	// ------------------------------

	mallardDuckFly = &bigWings;
	mallardDuckQuack = &loudQuack;

	mallardDuck->SetFly(mallardDuckFly);
	mallardDuck->SetQuack(mallardDuckQuack);

	mallardDuck->Draw();
	mallardDuck->PerformFly();
	mallardDuck->PerformQuack();

	// ------------------------------

	redHeadDuckFly = &bigWings;
	redHeadDuckQuack = &normalQuack;

	redHeadDuck->SetFly(redHeadDuckFly);
	redHeadDuck->SetQuack(redHeadDuckQuack);

	redHeadDuck->Draw();
	redHeadDuck->PerformFly();
	redHeadDuck->PerformQuack();

	// ------------------------------

	delete mallardDuck, redHeadDuck;

	return 0;
}