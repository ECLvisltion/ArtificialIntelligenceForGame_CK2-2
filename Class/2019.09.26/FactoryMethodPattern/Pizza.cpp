#include "Pizza.h"

void Pizza::Prepare()
{
	isPrepare = true;
}

void Pizza::Bake()
{
	if (isPrepare == true) { isBake = true; }
}

void Pizza::Cut()
{
	if (isBake == true) { isCut = true; }
}

void Pizza::Box()
{
	if (isBake == true) { isBox = true; }
}
