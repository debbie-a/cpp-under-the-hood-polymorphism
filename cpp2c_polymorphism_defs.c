#include "cpp2c_polymorphism_defs.h"
#include "malloc.h"

const char DEFAULT_SYMBOL_DOLLAR = '$';
const char DEFAULT_SYMBOL_HASH = '#';
const char DEFAULT_SYMBOL_FLOAT_DOLLAR = '@';

/* DefaultTextFormatter Defs */

int next_id = 0;

void (*TextFormatter_vtable[])() =
{
	NULL,
	_ZN13TextFormatterD0Ev
	
};

void (*DefaultTextFormatter_vtable[])() =
{
	_ZNK20DefaultTextFormatter5printEPKc,
	_ZN20DefaultTextFormatterD1Ev
};

void (*PrePostFixer_vtable[])() =
{
	_ZNK12PrePostFixer16getDefaultSymbolEv,
	_ZNK12PrePostFixer5printElc,
	_ZNK12PrePostFixer5printEPKc,
	_ZN12PrePostFixerD1Ev
};
void (*PrePostDollarFixer_vtable[])() =
{
	_ZNK18PrePostDollarFixer16getDefaultSymbolEv,
	_ZNK18PrePostDollarFixer5printEdc,
	_ZNK18PrePostDollarFixer5printElc,
	_ZNK18PrePostDollarFixer5printEic,
	_ZN18PrePostDollarFixerD1Ev

};
void (*PrePostHashFixer_vtable[])() =
{
	_ZNK16PrePostHashFixer16getDefaultSymbolEv,
	_ZNK16PrePostHashFixer5printEdc,
	_ZNK16PrePostHashFixer5printElc,
	_ZNK16PrePostHashFixer5printEic,
	_ZN16PrePostHashFixerD1Ev

};

void _ZN20DefaultTextFormatterC1ERKS_(DefaultTextFormatter *const this)
{
	this->textFormatter.vptr = TextFormatter_vtable;
	this->vptr = DefaultTextFormatter_vtable;
	this->id = next_id++;
    	printf("--- DefaultTextFormatter Default CTOR\n########## C %d ##########\n", this->id);
}

void _ZN20DefaultTextFormatterD1Ev(const DefaultTextFormatter *const this)
{
	
    	printf("--- DefaultTextFormatter DTOR\n########## D %d ##########\n", this->id);
}  

void  _ZN20DefaultTextFormatterC1Ev(DefaultTextFormatter *const this, const DefaultTextFormatter *const other)
{
	this->id = next_id++;
    	printf("--- DefaultTextFormatter Copy CTOR, from id: %d\n########## C %d ##########\n", other->id, this->id);
}

DefaultTextFormatter* _ZN20DefaultTextFormatteraSERKS_(DefaultTextFormatter *const this, const DefaultTextFormatter *const other)
{
    	printf("--- DefaultTextFormatter operator=(), from id: %d to id: %d\n", other->id, this->id);
    	return this;
}

void _ZNK20DefaultTextFormatter5printEPKc(const DefaultTextFormatter *const this, const char* text)
{
    	printf("%-60s | ", "[DefaultTextFormatter::print(const char*)]");   
    	printf("%s\n", text);
}

DefaultTextFormatter* _Z22generateFormatterArrayv(const DefaultTextFormatter *const this)
{
    	return malloc(sizeof(DefaultTextFormatter)*3);
}

/* PrePostFixer Defs */

void _ZN12PrePostFixerC1EPKcS1_(PrePostFixer *const this, const char* prefix, const char* postfix)  
{
	_ZN20DefaultTextFormatterC1ERKS_((DefaultTextFormatter*)this);
	this->vptr = PrePostFixer_vtable;
	this->pre = prefix;
  	this->post = postfix;
    	printf("--- PrePostFixer CTOR: \"%s\"...\"%s\"\n", this->pre, this->post);
}


void _ZN12PrePostFixerD1Ev(const PrePostFixer *const this)
{
    	printf("--- PrePostFixer DTOR: \"%s\"...\"%s\"\n", this->pre, this->post);
	_ZN20DefaultTextFormatterD1Ev((DefaultTextFormatter*)this);
}

void _ZNK12PrePostFixer5printEPKc(const PrePostFixer *const this, const char* text)
{
    	printf("%-60s | ", "[PrePostFixer::print(const char*)]");
    	printf("%s%s%s\n", this->pre, text, this->post);
}
void _ZNK12PrePostFixer5printElc(const PrePostFixer *const this, long num, char* symbol)
{
    	printf("%-60s | ", "[PrePostFixer::print(long, char)]");
    	printf("-->\n");
    
    	if (symbol)    
        {
		printFunc("[PrePostFixer::print_num(long, char)]"); 
    		printf("%s%s%ld%s\n", this->pre, symbol, num, this->post);
	}
    	else
        {
		printFunc("[PrePostFixer::print_num(long)]"); 
    		printf("%s%ld%s\n", this->pre, num, this->post);
	}
}

char _ZNK12PrePostFixer16getDefaultSymbolEv(const PrePostFixer *const this)
{
	return '\0';
}

/* PrePostDollarFixer Defs */

void _ZN18PrePostDollarFixerC1EPKcS1_(PrePostDollarFixer *const this, const char* prefix, const char* postfix)
{
	_ZN12PrePostFixerC1EPKcS1_(this, prefix, postfix);
	this->vptr = PrePostDollarFixer_vtable;
    	printf("--- PrePostDollarFixer CTOR: \"%s\"...\"%s\"\n", getPrefix(), getPostfix());
}

void _ZN18PrePostDollarFixerC1ERKS_(PrePostDollarFixer *const, const PrePostDollarFixer* other)
{
	_ZN12PrePostFixerC1EPKcS1_((PrePostFixer*)this, other->pre, other->post);
	this->vptr = PrePostDollarFixer_vtable;
    	printf("--- PrePostDollarFixer Copy CTOR: \"%s\"...\"%s\"\n", getPrefix(), getPostfix());
}

void _ZN18PrePostDollarFixerD1Ev(const PrePostDollarFixer *const)
{
    	printf("--- PrePostDollarFixer DTOR: \"%s\"...\"%s\"\n", this->pre, this->post);
	_ZN12PrePostFixerD1Ev((PrePostFixer*)this)
}

void _ZNK18PrePostDollarFixer5printEic(const PrePostDollarFixer *const, int num, char* symbol
{
    	printf("%-60s | ", "[PrePostDollarFixer::print(int, char)]"); 
    	printf("-->\n");

    	_ZNK18PrePostDollarFixer5printEic(this, long(num), symbol);
}

void _ZNK18PrePostDollarFixer5printElc(const PrePostDollarFixer *const this, long num, char symbol)
    	printf("%-60s | ", "[PrePostDollarFixer::print(long, char)]");
    	printf("-->\n");
    	_ZNK18PrePostDollarFixer5printEdc(this, num, symbol);
}

void _ZNK18PrePostDollarFixer5printEdc(const PrePostDollarFixer *const this, double num, char symbol)
{
    	printf("%-60s | ", "[PrePostDollarFixer::print(double, char)]"); 
    	printf("%s%c%f%s\n", this->prePostFixet.pre, symbol, num, this->prePostFixet.post);
}

char _ZNK18PrePostDollarFixer16getDefaultSymbolEv(const PrePostDollarFixer *const this)
{
    	return DEFAULT_SYMBOL_DOLLAR;
}


/* PrePostHashFixer Defs */

void _ZN16PrePostHashFixerC1Ei(PrePostHashFixer *const this, int prc);
{
	_ZN18PrePostDollarFixerC1EPKcS1_(this, "===> ", " <===")
	this->precision = prc;
    	printf("--- PrePostHashFixer CTOR: \"%s\"...\"%s\", precision: %d\n", this->prePostDollarFixer.prePostFixet.pre, this->prePostDollarFixer.prePostFixet.post, precision);   

    	print(9999.9999);
}

void _ZN16PrePostHashFixerD1Ev(const PrePostHashFixer *const this)
{
    	printf("--- PrePostHashFixer DTOR: \"%s\"...\"%s\"\n", this->prePostDollarFixer.prePostFixet.pre, this->prePostDollarFixer.prePostFixet.post);
	_ZN18PrePostDollarFixerD1Ev(this);
}
    
void _ZNK16PrePostHashFixer5printEic(const PrePostHashFixer *const this, int num, char symbol)
{
    	printf("%-60s | ","[PrePostHashFixer::print(int, char)]"); 
    	printf("-->\n");

    	print(this, double(num), symbol);
}

void _ZNK16PrePostHashFixer5printElc(const PrePostHashFixer *const this, long num, char symbol)
{
    	printf("%-60s | ","[PrePostHashFixer::print(long, char)]"); 
    	printf("-->\n");

    	_ZNK16PrePostHashFixer5printEdc(double(num), symbol);
}
void _ZNK16PrePostHashFixer5printEdc(const PrePostHashFixer *const this, double num, char symbol)
{
    	printf("%-60s | ","[PrePostHashFixer::print(double, char)]"); 

    	printf("%s[%c%.*f]%s\n", this->prePostDollarFixer.prePostFixet.pre, symbol, this->precision, num, this->prePostDollarFixer.prePostFixet.post);
}

char _ZNK12PrePostFixer16getDefaultSymbolEv(const PrePostFixer *const this)
{
    	return DEFAULT_SYMBOL_HASH;
}


/* PrePostFloatDollarFixer Defs */
/*
PrePostFloatDollarFixer::PrePostFloatDollarFixer(const char* prefix, const char* postfix)
:   PrePostDollarFixer(prefix, postfix)
{
    printf("--- PrePostFloatDollarFixer CTOR: \"%s\"...\"%s\"\n", getPrefix(), getPostfix());
}

PrePostFloatDollarFixer::~PrePostFloatDollarFixer()
{
    printf("--- PrePostFloatDollarFixer DTOR: \"%s\"...\"%s\"\n", getPrefix(), getPostfix());
}

void PrePostFloatDollarFixer::print(float num) const
{
    printFunc("[PrePostFloatDollarFixer::print(float)]");
    printf("-->\n");

    print(num, DEFAULT_SYMBOL);
}

void PrePostFloatDollarFixer::print(float num, char symbol) const
{
    printFunc("[PrePostFloatDollarFixer::print(float, char)]"); 

    printf("%s%c%.2f%s\n", getPrefix(), symbol, num, getPostfix());
}
*/
/* PrePostChecker Defs */
/*
PrePostChecker::PrePostChecker()
:   PrePostFloatDollarFixer("[[[[ ", " ]]]]")
{
    printf("--- PrePostChecker CTOR: \"%s\"...\"%s\"\n", getPrefix(), getPostfix());
}    

PrePostChecker::~PrePostChecker()
{
    printf("--- PrePostChecker CTOR: \"%s\"...\"%s\"\n", getPrefix(), getPostfix());
}

void PrePostChecker::printThisSymbolUsingFunc() const
{
    printFunc("[PrePostChecker::printThisSymbolUsingFunc()]");

    printf("Default symbol is %c\n", this->getDefaultSymbol());
}

void PrePostChecker::printThisSymbolDirectly() const
{
    printFunc("[PrePostChecker::printThisSymbolDirectly()]");

    printf("Default symbol is %c\n", this->DEFAULT_SYMBOL);
}

void PrePostChecker::printDollarSymbolByCastUsingFunc() const
{
    printFunc("[PrePostChecker::printDollarSymbolByCastUsingFunc()]");

    printf("Default symbol is %c\n", ((PrePostDollarFixer*)(this))->getDefaultSymbol());
}

void PrePostChecker::printDollarSymbolByScopeUsingFunc() const
{
    printFunc("[PrePostChecker::printDollarSymbolByScopeUsingFunc()]");

    printf("Default symbol is %c\n", this->PrePostDollarFixer::getDefaultSymbol());
}

void PrePostChecker::printDollarSymbolByCastDirectly() const
{
    printFunc("[PrePostChecker::printDollarSymbolByCastDirectly()]");

    printf("Default symbol is %c\n", ((PrePostDollarFixer*)(this))->DEFAULT_SYMBOL);
}

void PrePostChecker::printDollarSymbolByScopeDirectly() const
{
    printFunc("[PrePostChecker::printDollarSymbolByScopeDirectly()]");

    printf("Default symbol is %c\n", this->PrePostDollarFixer::DEFAULT_SYMBOL);
}
*/

/* Multiplier Defs */
/*
void Multiplier::print(const char* text) const
{
    printFunc("[Multiplier::print(const char*)]");
    
    for (int i = 0; i < times; ++i)
        printf("%s", text);
    printf("\n");
}
*/

