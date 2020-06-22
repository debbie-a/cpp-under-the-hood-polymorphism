#include <stdlib.h>
#include "malloc.h"
#include "cpp2c_polymorphism_defs.h"

extern funcptr Multiplier_vtable[];

void doPrePostFixer()
{
	PrePostFixer angleBrackets;
    	printf("\n--- start doPrePostFixer() ---\n\n");

    	
	_ZN12PrePostFixerC1EPKcS1_(&angleBrackets, "<<< ", " >>>");
	_ZNK12PrePostFixer5printEPKc(&angleBrackets, "Hello World!");
	_ZNK12PrePostFixer5printElc(&angleBrackets, -777, '\0');
	_ZNK12PrePostFixer5printElc(&angleBrackets, 350, '#');
	_ZNK12PrePostFixer5printElc(&angleBrackets, (long)3.14, '\0');

	printf("\n--- end doPrePostFixer() ---\n\n");
	_ZN12PrePostFixerD1Ev(&angleBrackets);
}
void doPrePostDollarFixer()
{
	PrePostDollarFixer asterisks;
    	printf("\n--- start doPrePostDollarFixer() ---\n\n");

	_ZN18PrePostDollarFixerC1EPKcS1_(&asterisks, "***** ", " *****");
    	_ZNK18PrePostDollarFixer5printEic(&asterisks, -777, '$');
    	_ZNK18PrePostDollarFixer5printEic(&asterisks, 350, '#');
    	_ZNK18PrePostDollarFixer5printEdc(&asterisks, 3.14f, '$');

    	printf("\n--- end doPrePostDollarFixer() ---\n\n");
	_ZN18PrePostDollarFixerD1Ev(&asterisks);
}

void doPrePostChecker()
{
	PrePostChecker check;
    	printf("\n--- start doPrePostChecker() ---\n\n");

	_ZN14PrePostCheckerC1Ev(&check);
    	_ZNK14PrePostChecker24printThisSymbolUsingFuncEv(&check);
    	_ZNK14PrePostChecker23printThisSymbolDirectlyEv(&check);
    	_ZNK14PrePostChecker31printDollarSymbolByCastDirectlyEv(&check);
    	_ZNK14PrePostChecker32printDollarSymbolByScopeDirectlyEv(&check);
    	_ZNK14PrePostChecker32printDollarSymbolByCastUsingFuncEv(&check);
    	_ZNK14PrePostChecker33printDollarSymbolByScopeUsingFuncEv(&check);

    	printf("\n--- end doPrePostChecker() ---\n\n");
	_ZN14PrePostCheckerD1Ev(&check);
}

void doPrePostFloatDollarFixer()
{
	PrePostFloatDollarFixer hashes;
	PrePostDollarFixer hashes2;
    	printf("\n--- start doPrePostFloatDollarFixer() ---\n\n");

    	_ZN23PrePostFloatDollarFixerC1EPKcS1_(&hashes, "### ", " ###");
    	_ZNK23PrePostFloatDollarFixer5printEf(&hashes, -777);
    	_ZNK23PrePostFloatDollarFixer5printEfc(&hashes, 350, '#');
    	_ZNK23PrePostFloatDollarFixer5printEf(&hashes, 3.14f);

    	_ZN18PrePostDollarFixerC1ERKS_(&hashes2, (PrePostDollarFixer*)&hashes);
   	_ZNK18PrePostDollarFixer5printEdc(&hashes2, 7.5, '$');
    	_ZNK18PrePostDollarFixer5printEic(&hashes2, 100, '$');

    	printf("\n--- start doPrePostFloatDollarFixer() ---\n\n");
	_ZN18PrePostDollarFixerD1Ev(&hashes2);
	_ZN23PrePostFloatDollarFixerD1Ev(&hashes);
}

void runAsPrePostFixerRef(const PrePostFixer* pp)
{
    	printf("\n--- start runAsPrePostFixerRef() ---\n\n");

    	(pp->defaultTextFormatter.textFormatter.vptr[2])(pp, 123, '\0');

    	printf("\n--- end runAsPrePostFixerRef() ---\n\n");
}

void runAsPrePostDollarFixerRef(const PrePostDollarFixer* pp)
{
    	printf("\n--- start runAsPrePostDollarFixerRef() ---\n\n");

    	_ZNK18PrePostDollarFixer5printEic(pp, 123, '$');

    	printf("\n--- end runAsPrePostDollarFixerRef() ---\n\n");
}

void runAsPrePostDollarFixerObj(const PrePostDollarFixer pp)
{
    	printf("\n--- start runAsPrePostDollarFixerObj() ---\n\n");

    	_ZNK18PrePostDollarFixer5printEic(&pp, 123, '$');

    	printf("\n--- end runAsPrePostDollarFixerObj() ---\n\n");
}

void runAsPrePostHashFixerRef(const PrePostHashFixer* pp)
{
    	printf("\n--- start runAsPrePostHashFixerRef() ---\n\n");

    	_ZNK16PrePostHashFixer5printEic(pp, 123, '#');

    	printf("\n--- end runAsPrePostHashFixerRef() ---\n\n");
}
void doMultiplier()
{
	Multiplier m1;
    	Multiplier m2;
    	Multiplier m3;
    	Multiplier m4;
    	printf("\n--- start doMultiplier() ---\n\n");
	
	_ZN20DefaultTextFormatterC1ERKS_((DefaultTextFormatter*)&m1);
	m1.defaultTextFormatter.textFormatter.vptr = Multiplier_vtable; 
    	m1.times = 3;
	printf("--- Multiplier CTOR: times = %d\n", m1.times);
	_ZN20DefaultTextFormatterC1ERKS_((DefaultTextFormatter*)&m2);
	m2.defaultTextFormatter.textFormatter.vptr = Multiplier_vtable;
    	m2.times = 5;
	printf("--- Multiplier CTOR: times = %d\n", m2.times);
	_ZN20DefaultTextFormatterC1Ev((DefaultTextFormatter*)&m3, (DefaultTextFormatter*)&m1);
	m3.defaultTextFormatter.textFormatter.vptr = Multiplier_vtable;
    	m3.times = m1.times;
	_ZN20DefaultTextFormatterC1Ev((DefaultTextFormatter*)&m4, (DefaultTextFormatter*)&m2);
    	m4.defaultTextFormatter.textFormatter.vptr = Multiplier_vtable;
    	m4.times = m2.times;

    	 _ZNK10Multiplier5printEPKc(&m1, "abc ");
    	 _ZNK10Multiplier5printEPKc(&m2, "abc ");
    	 _ZNK10Multiplier5printEPKc(&m3, "abc ");
    	 _ZNK10Multiplier5printEPKc(&m4, "abc ");

    	printf("\n--- start doMultiplier() ---\n\n");

	_ZN10MultiplierD1Ev(&m4);
	_ZN10MultiplierD1Ev(&m3);
	_ZN10MultiplierD1Ev(&m2);
	_ZN10MultiplierD1Ev(&m1);
}

void doFormatterArray()
{
	DefaultTextFormatter formatters[3];
	PrePostDollarFixer prePostDollarFixer;
	Multiplier multiplier;
	PrePostChecker prePostChecker;
	int i;
    	printf("\n--- start doFormatterArray() ---\n\n");

	_ZN18PrePostDollarFixerC1EPKcS1_(&prePostDollarFixer, "!!! ", " !!!");
	_ZN20DefaultTextFormatterC1Ev(&formatters[0], (DefaultTextFormatter*)&prePostDollarFixer);
	_ZN18PrePostDollarFixerD1Ev(&prePostDollarFixer);
	
	_ZN20DefaultTextFormatterC1ERKS_((DefaultTextFormatter*)&multiplier);
	multiplier.defaultTextFormatter.textFormatter.vptr = Multiplier_vtable; 
	multiplier.times = 4;
    	printf("--- Multiplier CTOR: times = %d\n", multiplier.times);
	_ZN20DefaultTextFormatterC1Ev(&formatters[1], (DefaultTextFormatter*)&multiplier);
	_ZN10MultiplierD1Ev(&multiplier);

	 _ZN14PrePostCheckerC1Ev(&prePostChecker);
	_ZN20DefaultTextFormatterC1Ev(&formatters[2], (DefaultTextFormatter*)&prePostChecker);
	_ZN14PrePostCheckerD1Ev(&prePostChecker);

    	for (i = 0; i < 3; ++i)
        	_ZNK20DefaultTextFormatter5printEPKc(&formatters[i], "Hello World!");
	
    	printf("\n--- end doFormatterArray() ---\n\n");


	for(i = 2; i >= 0; i--)
		_ZN20DefaultTextFormatterD1Ev(&(formatters[i]));
}

void doFormatterPtrs()
{
	DefaultTextFormatter *pfmt[3];
	int i;
    	printf("\n--- start doFormatterPtrs() ---\n\n");
	
    	pfmt[0] = malloc(sizeof(PrePostDollarFixer));
	_ZN18PrePostDollarFixerC1EPKcS1_((PrePostDollarFixer*)pfmt[0], "!!! ", " !!!");
	pfmt[1] = malloc(sizeof(Multiplier));
	_ZN20DefaultTextFormatterC1ERKS_((DefaultTextFormatter*)pfmt[1]);
	((Multiplier*)pfmt[1])-> defaultTextFormatter.textFormatter.vptr = Multiplier_vtable; 
	((Multiplier*)pfmt[1])->times = 4;
    	printf("--- Multiplier CTOR: times = %d\n", ((Multiplier*)pfmt[1])->times);

	pfmt[2] = malloc(sizeof(PrePostChecker));
	 _ZN14PrePostCheckerC1Ev((PrePostChecker*)pfmt[2]);

    	for (i = 0; i < 3; ++i)
        	(pfmt[i]->textFormatter.vptr[1])(pfmt[i], "Hello World!");

    	for (i = 2; i >= 0; i--)
        {
		(pfmt[i]->textFormatter.vptr[0])(pfmt[i]);
		free(pfmt[i]);
		pfmt[i] = NULL;
	}
    	printf("\n--- end doFormatterPtrs() ---\n\n");
}

void doFormatterDynamicArray()
{
	DefaultTextFormatter *formatters;
	int i;
    	printf("\n--- start doFormatterDynamicArray() ---\n\n");
	formatters = _Z22generateFormatterArrayv();

    	for (i = 0; i < 3; ++i)
	{
        	formatters[i].textFormatter.vptr[1](&formatters[i], "Hello World!");
	}
	for (i = 2; i >= 0; i--)
        {
		formatters[i].textFormatter.vptr[0](&formatters[i]);
	}

	free(formatters);
	formatters = NULL;
    	printf("\n--- start doFormatterDynamicArray() ---\n\n");
}

int main()
{
	PrePostHashFixer hfix;
	PrePostDollarFixer copy;
    	printf("\n--- Start main() ---\n\n");

    	doPrePostFixer();
    	doPrePostDollarFixer();
   	doPrePostFloatDollarFixer();
    	doPrePostChecker();

	_ZN16PrePostHashFixerC1Ei(&hfix, 4);
    	runAsPrePostFixerRef((PrePostFixer*)&hfix);
    	runAsPrePostDollarFixerRef((PrePostDollarFixer*)&hfix);
	_ZN18PrePostDollarFixerC1ERKS_(&copy, (PrePostDollarFixer*)&hfix);
    	runAsPrePostDollarFixerObj(copy);
	_ZN18PrePostDollarFixerD1Ev(&copy);
    	runAsPrePostHashFixerRef((PrePostHashFixer*)&hfix);

    	doMultiplier();

    	doFormatterArray();
    	doFormatterPtrs();
    	doFormatterDynamicArray();

    	printf("\n--- End main() ---\n\n");

	_ZN16PrePostHashFixerD1Ev(&hfix);

    	return 0;
}



