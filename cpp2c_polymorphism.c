#include <stdlib.h>
#include "malloc.h"
#include "cpp2c_polymorphism_defs.h"


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

    	_ZNK14PrePostChecker24printThisSymbolUsingFuncEv(&check);
    	_ZNK14PrePostChecker23printThisSymbolDirectlyEv(&check);
    	_ZNK14PrePostChecker31printDollarSymbolByCastDirectlyEv(&check);
    	_ZNK14PrePostChecker32printDollarSymbolByScopeDirectlyEv(&check);
    	_ZNK14PrePostChecker32printDollarSymbolByCastUsingFuncEv(&check);
    	_ZNK14PrePostChecker33printDollarSymbolByScopeUsingFuncEv(&check);

    	printf("\n--- end doPrePostChecker() ---\n\n");
}

void doPrePostFloatDollarFixer()
{
	PrePostFloatDollarFixer hashes;
	PrePostDollarFixer hashes2;
    	printf("\n--- start doPrePostFloatDollarFixer() ---\n\n");

    	_ZN23PrePostFloatDollarFixerC1EPKcS1_(&hashes, "### ", " ###");
    	_ZNK18PrePostDollarFixer5printEic(&(hashes.prePostDollarFixer), -777, '$');
    	_ZNK18PrePostDollarFixer5printEic(&(hashes.prePostDollarFixer), 350, '#');
    	_ZNK18PrePostDollarFixer5printEdc(&(hashes.prePostDollarFixer), 3.14f, '$');

    	_ZN18PrePostDollarFixerC1ERKS_(&hashes2, &(hashes.prePostDollarFixer));
   	_ZNK18PrePostDollarFixer5printEdc(&hashes2, 7.5, '$');
    	_ZNK18PrePostDollarFixer5printEic(&hashes2, 100, '$');

    	printf("\n--- start doPrePostFloatDollarFixer() ---\n\n");
	_ZN18PrePostDollarFixerD1Ev(&hashes2);
	_ZN23PrePostFloatDollarFixerD1Ev(&hashes);
}
/*
void runAsPrePostFixerRef(const PrePostFixer& pp)
{
    	printf("\n--- start runAsPrePostFixerRef() ---\n\n");

    	pp.print(123);

    	printf("\n--- end runAsPrePostFixerRef() ---\n\n");
}

void runAsPrePostDollarFixerRef(const PrePostDollarFixer& pp)
{
    	printf("\n--- start runAsPrePostDollarFixerRef() ---\n\n");

    	pp.print(123);

    	printf("\n--- end runAsPrePostDollarFixerRef() ---\n\n");
}

void runAsPrePostDollarFixerObj(const PrePostDollarFixer pp)
{
    	printf("\n--- start runAsPrePostDollarFixerObj() ---\n\n");

    	pp.print(123);

    	printf("\n--- end runAsPrePostDollarFixerObj() ---\n\n");
}

void runAsPrePostHashFixerRef(const PrePostHashFixer& pp)
{
    	printf("\n--- start runAsPrePostHashFixerRef() ---\n\n");

    	pp.print(123);

    	printf("\n--- end runAsPrePostHashFixerRef() ---\n\n");
}*/

void doMultiplier()
{
	Multiplier m1;
    	Multiplier m2;
    	Multiplier m3;
    	Multiplier m4;
    	printf("\n--- start doMultiplier() ---\n\n");
	
	_ZN20DefaultTextFormatterC1ERKS_(&m1);
    	m1.times = 3;
	printf("--- Multiplier CTOR: times = %d\n", m1.times);
	_ZN20DefaultTextFormatterC1ERKS_(&m2);
    	m2.times = 5;
	printf("--- Multiplier CTOR: times = %d\n", m2.times);
    	m3 = m1;
    	m4 = m2;

    	/*.print(&m1, "abc ");
    	print(&m2, "abc ");
    	m3.print(&m3, "abc ");
    	m4.print(&m4, "abc ");*/

    	printf("\n--- start doMultiplier() ---\n\n");

	printf("--- Multiplier DTOR: times = %d\n", m4.times);
	printf("--- Multiplier DTOR: times = %d\n", m3.times);
	printf("--- Multiplier DTOR: times = %d\n", m2.times);
	printf("--- Multiplier DTOR: times = %d\n", m1.times);
}
/*
void doFormatterArray()
{
    	printf("\n--- start doFormatterArray() ---\n\n");

    	DefaultTextFormatter formatters[] =
    	{
        	PrePostDollarFixer("!!! ", " !!!"),
        	Multiplier(4),
        	PrePostChecker()
    	};

    	for (int i = 0; i < 3; ++i)
        	formatters[i].print("Hello World!");

    	printf("\n--- end doFormatterArray() ---\n\n");
}

void doFormatterPtrs()
{
    	printf("\n--- start doFormatterPtrs() ---\n\n");

    	DefaultTextFormatter* pfmt[] =
    	{
        	new PrePostDollarFixer("!!! ", " !!!"),
        	new Multiplier(4),
        	new PrePostChecker()
    	};

    	for (int i = 0; i < 3; ++i)
        	pfmt[i]->print("Hello World!");

    	for (int i = 2; i >= 0; --i)
        	delete pfmt[i];

    	printf("\n--- end doFormatterPtrs() ---\n\n");
}*/

void doFormatterDynamicArray()
{
	DefaultTextFormatter* formatters =  _Z22generateFormatterArrayv();
    	printf("\n--- start doFormatterDynamicArray() ---\n\n");

    
    	for (int i = 0; i < 3; ++i)
	{
		_ZN20DefaultTextFormatterC1ERKS_(&formatters[i]);
        	(formatters[i].textFormatter.vptr[1])(&formatters[i], "Hello World!");
	}
	for (int i = 0; i < 3; ++i)
        {
		_ZN20DefaultTextFormatterD1Ev(&formatters[i]);
    		//free(formatters);
		//formatters = NULL;
	}

    	printf("\n--- start doFormatterDynamicArray() ---\n\n");
}

int main()
{
    	printf("\n--- Start main() ---\n\n");

    	doPrePostFixer();
    	doPrePostDollarFixer();
   	doPrePostFloatDollarFixer();
    	doPrePostChecker();

    	/*PrePostHashFixer hfix;
    	runAsPrePostFixerRef(hfix);
    	runAsPrePostDollarFixerRef(hfix);
    	runAsPrePostDollarFixerObj(hfix);
    	runAsPrePostHashFixerRef(hfix);

    	doMultiplier();

    	doFormatterArray();
    	doFormatterPtrs();*/
    	doFormatterDynamicArray();

    	printf("\n--- End main() ---\n\n");

    	return 0;
}



