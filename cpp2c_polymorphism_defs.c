#include "malloc.h"
#include "cpp2c_polymorphism_defs.h"

static const char DEFAULT_SYMBOL_DOLLAR = '$';
static const char DEFAULT_SYMBOL_HASH = '#';
static const char DEFAULT_SYMBOL_FLOAT_DOLLAR = '@';
static int next_id = 0;
/* DefaultTextFormatter Defs */



funcptr TextFormatter_vtable[] =
{
	(funcptr)_ZN13TextFormatterD0Ev,
	NULL
};

funcptr DefaultTextFormatter_vtable[] =
{
	(funcptr)_ZN20DefaultTextFormatterD1Ev,
	(funcptr)_ZNK20DefaultTextFormatter5printEPKc
};

funcptr PrePostFixer_vtable[] =
{
	(funcptr)_ZN12PrePostFixerD1Ev,
	(funcptr)_ZNK12PrePostFixer5printEPKc,
	(funcptr)_ZNK12PrePostFixer5printElc,
	(funcptr)_ZNK12PrePostFixer16getDefaultSymbolEv
	
};
funcptr PrePostDollarFixer_vtable[] =
{
	(funcptr)_ZN18PrePostDollarFixerD1Ev,
	(funcptr)_ZNK12PrePostFixer5printEPKc,
	(funcptr)_ZNK18PrePostDollarFixer5printElc,
	(funcptr)_ZNK18PrePostDollarFixer16getDefaultSymbolEv

};
funcptr PrePostHashFixer_vtable[] =
{
	(funcptr)_ZN16PrePostHashFixerD1Ev,
	(funcptr)_ZNK12PrePostFixer5printEPKc,
	(funcptr)_ZNK16PrePostHashFixer5printElc,
	(funcptr)_ZNK16PrePostHashFixer16getDefaultSymbolEv

};
funcptr PrePostFloatDollarFixer_vtable[] =
{
	(funcptr)_ZN23PrePostFloatDollarFixerD1Ev,
	(funcptr)_ZNK12PrePostFixer5printEPKc,
	(funcptr)_ZNK18PrePostDollarFixer5printElc,
	(funcptr)_ZNK23PrePostFloatDollarFixer16getDefaultSymbolEv
};
funcptr PrePostChecker_vtable[] =
{
	(funcptr)_ZN14PrePostCheckerD1Ev,
	(funcptr)_ZNK12PrePostFixer5printEPKc,
	(funcptr)_ZNK18PrePostDollarFixer5printElc,
	(funcptr)_ZNK23PrePostFloatDollarFixer16getDefaultSymbolEv
};
funcptr Multiplier_vtable[] =
{
	(funcptr)_ZN10MultiplierD1Ev,
	(funcptr)_ZNK10Multiplier5printEPKc
};
void _ZN13TextFormatterD0Ev(const TextFormatter *const this)
{
}

void _ZN20DefaultTextFormatterC1ERKS_(DefaultTextFormatter *const this)
{
	this->textFormatter.vptr = DefaultTextFormatter_vtable;
	this->id = next_id++;
    	printf("--- DefaultTextFormatter Default CTOR\n########## C %d ##########\n", this->id);
}

void _ZN20DefaultTextFormatterD1Ev(DefaultTextFormatter *const this)
{
    	printf("--- DefaultTextFormatter DTOR\n########## D %d ##########\n", this->id);
	this->textFormatter.vptr =  TextFormatter_vtable;
	_ZN13TextFormatterD0Ev((TextFormatter*)this);
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

DefaultTextFormatter* _Z22generateFormatterArrayv()
{
	DefaultTextFormatter *tmp = malloc(sizeof(DefaultTextFormatter)*3);
	int i;
	for(i = 0; i < 3; i++)
		_ZN20DefaultTextFormatterC1ERKS_(&tmp[i]);
    	return tmp;
}

/* PrePostFixer Defs */

void _ZN12PrePostFixerC1EPKcS1_(PrePostFixer *const this, const char* prefix, const char* postfix)  
{
	_ZN20DefaultTextFormatterC1ERKS_((DefaultTextFormatter*)this);
	this->defaultTextFormatter.textFormatter.vptr = PrePostFixer_vtable;
	this->pre = prefix;
  	this->post = postfix;
    	printf("--- PrePostFixer CTOR: \"%s\"...\"%s\"\n", this->pre, this->post);
}


void _ZN12PrePostFixerD1Ev(PrePostFixer *const this)
{
    	printf("--- PrePostFixer DTOR: \"%s\"...\"%s\"\n", this->pre, this->post);
	this->defaultTextFormatter.textFormatter.vptr = DefaultTextFormatter_vtable;
	_ZN20DefaultTextFormatterD1Ev((DefaultTextFormatter*)this);
}

void _ZNK12PrePostFixer5printEPKc(const PrePostFixer *const this, const char* text)
{
    	printf("%-60s | ", "[PrePostFixer::print(const char*)]");
    	printf("%s%s%s\n", this->pre, text, this->post);
}
void _ZNK12PrePostFixer5printElc(const PrePostFixer *const this, long num, char symbol)
{
    	printf("%-60s | ", "[PrePostFixer::print(long, char)]");
    	printf("-->\n");
    
    	if (symbol)    
        {
		printf("%-60s | ", "[PrePostFixer::print_num(long, char)]"); 
    		printf("%s%c%ld%s\n", this->pre, symbol, num, this->post);
	}
    	else
        {
		printf("%-60s | ", "[PrePostFixer::print_num(long)]"); 
    		printf("%s%ld%s\n", this->pre, num, this->pre);
	}
}

char _ZNK12PrePostFixer16getDefaultSymbolEv(const PrePostFixer *const this)
{
	return '\0';
}

/* PrePostDollarFixer Defs */

void _ZN18PrePostDollarFixerC1EPKcS1_(PrePostDollarFixer *const this, const char* prefix, const char* postfix)
{
	_ZN12PrePostFixerC1EPKcS1_((PrePostFixer*)this, prefix, postfix);
	this->prePostFixer.defaultTextFormatter.textFormatter.vptr = PrePostDollarFixer_vtable;
    	printf("--- PrePostDollarFixer CTOR: \"%s\"...\"%s\"\n", this->prePostFixer.pre, this->prePostFixer.post);
}

void _ZN18PrePostDollarFixerC1ERKS_(PrePostDollarFixer *const this, const PrePostDollarFixer *const other)
{
	_ZN20DefaultTextFormatterC1Ev((DefaultTextFormatter*)this, (DefaultTextFormatter*)other);
	this->prePostFixer.defaultTextFormatter.textFormatter.vptr = PrePostFixer_vtable;
	this->prePostFixer.pre = other->prePostFixer.pre;
	this->prePostFixer.post = other->prePostFixer.post;
	this->prePostFixer.defaultTextFormatter.textFormatter.vptr = PrePostDollarFixer_vtable;
    	printf("--- PrePostDollarFixer Copy CTOR: \"%s\"...\"%s\"\n", this->prePostFixer.pre, this->prePostFixer.post);
}

void _ZN18PrePostDollarFixerD1Ev(PrePostDollarFixer *const this)
{
    	printf("--- PrePostDollarFixer DTOR: \"%s\"...\"%s\"\n", this->prePostFixer.pre, this->prePostFixer.post);
	this->prePostFixer.defaultTextFormatter.textFormatter.vptr = PrePostFixer_vtable;
	_ZN12PrePostFixerD1Ev((PrePostFixer*)this);
}

void _ZNK18PrePostDollarFixer5printEic(const PrePostDollarFixer *const this, int num, char symbol)
{
    	printf("%-60s | ", "[PrePostDollarFixer::print(int, char)]"); 
    	printf("-->\n");

    	this->prePostFixer.defaultTextFormatter.textFormatter.vptr[2](this, (long)num, symbol);
}

void _ZNK18PrePostDollarFixer5printElc(const PrePostDollarFixer *const this, long num, char symbol)
{
    	printf("%-60s | ", "[PrePostDollarFixer::print(long, char)]");
    	printf("-->\n");
    	_ZNK12PrePostFixer5printElc((PrePostFixer*)this, num, symbol);
}

void _ZNK18PrePostDollarFixer5printEdc(const PrePostDollarFixer *const this, double num, char symbol)
{
    	printf("%-60s | ", "[PrePostDollarFixer::print(double, char)]"); 
    	printf("%s%c%f%s\n",  this->prePostFixer.pre, symbol, num, this->prePostFixer.post);
}

char _ZNK18PrePostDollarFixer16getDefaultSymbolEv(const PrePostDollarFixer *const this)
{
    	return DEFAULT_SYMBOL_DOLLAR;
}


/* PrePostHashFixer Defs */

void _ZN16PrePostHashFixerC1Ei(PrePostHashFixer *const this, int prc)
{
	_ZN18PrePostDollarFixerC1EPKcS1_((PrePostDollarFixer*)this, "===> ", " <===");
	this->prePostDollarFixer.prePostFixer.defaultTextFormatter.textFormatter.vptr = PrePostHashFixer_vtable;
	this->precision = prc;
    	printf("--- PrePostHashFixer CTOR: \"%s\"...\"%s\", precision: %d\n", this->prePostDollarFixer.prePostFixer.pre, this->prePostDollarFixer.prePostFixer.post, this->precision);   

	printf("%-60s | ","[PrePostHashFixer::print(double, char)]"); 

    	printf("%s[%c%.*f]%s\n", this->prePostDollarFixer.prePostFixer.pre, '#', this->precision, 9999.9999, this->prePostDollarFixer.prePostFixer.post);
}

void _ZN16PrePostHashFixerD1Ev(PrePostHashFixer *const this)
{
    	printf("--- PrePostHashFixer DTOR: \"%s\"...\"%s\"\n", this->prePostDollarFixer.prePostFixer.pre, this->prePostDollarFixer.prePostFixer.post);
	this->prePostDollarFixer.prePostFixer.defaultTextFormatter.textFormatter.vptr = PrePostDollarFixer_vtable;
	_ZN18PrePostDollarFixerD1Ev((PrePostDollarFixer*)this);
}
    
void _ZNK16PrePostHashFixer5printEic(const PrePostHashFixer *const this, int num, char symbol)
{
    	printf("%-60s | ","[PrePostHashFixer::print(int, char)]"); 
    	printf("-->\n");

    	printf("%-60s | ","[PrePostHashFixer::print(double, char)]"); 

    	printf("%s[%c%.*f]%s\n", this->prePostDollarFixer.prePostFixer.pre, symbol, this->precision, (double)num, this->prePostDollarFixer.prePostFixer.post);
}

void _ZNK16PrePostHashFixer5printElc(const PrePostHashFixer *const this, long num, char symbol)
{
    	printf("%-60s | ","[PrePostHashFixer::print(long, char)]"); 
    	printf("-->\n");

    	printf("%-60s | ","[PrePostHashFixer::print(double, char)]"); 

    	printf("%s[%c%.*f]%s\n", this->prePostDollarFixer.prePostFixer.pre, symbol, this->precision, (double)num, this->prePostDollarFixer.prePostFixer.post);
}

char _ZNK16PrePostHashFixer16getDefaultSymbolEv(const PrePostHashFixer *const this)
{
    	return DEFAULT_SYMBOL_HASH;
}


/* PrePostFloatDollarFixer Defs */


void _ZN23PrePostFloatDollarFixerC1EPKcS1_(PrePostFloatDollarFixer *const this, const char* prefix, const char* postfix)
{
	_ZN18PrePostDollarFixerC1EPKcS1_((PrePostDollarFixer*)this, prefix, postfix);
	this->prePostDollarFixer.prePostFixer.defaultTextFormatter.textFormatter.vptr = PrePostFloatDollarFixer_vtable;
    	printf("--- PrePostFloatDollarFixer CTOR: \"%s\"...\"%s\"\n",  this->prePostDollarFixer.prePostFixer.pre, this->prePostDollarFixer.prePostFixer.post);
}

void _ZN23PrePostFloatDollarFixerD1Ev(PrePostFloatDollarFixer *const this)
{
    	printf("--- PrePostFloatDollarFixer DTOR: \"%s\"...\"%s\"\n", this->prePostDollarFixer.prePostFixer.pre, this->prePostDollarFixer.prePostFixer.post);
	this->prePostDollarFixer.prePostFixer.defaultTextFormatter.textFormatter.vptr = PrePostDollarFixer_vtable;
	_ZN18PrePostDollarFixerD1Ev((PrePostDollarFixer*)this);
}

void _ZNK23PrePostFloatDollarFixer5printEf(const PrePostFloatDollarFixer *const this, float num)
{
    	printf("%-60s | ", "[PrePostFloatDollarFixer::print(float)]");
    	printf("-->\n");

    	_ZNK23PrePostFloatDollarFixer5printEfc(this, num, DEFAULT_SYMBOL_FLOAT_DOLLAR);
}

void  _ZNK23PrePostFloatDollarFixer5printEfc(const PrePostFloatDollarFixer *const this, float num, char symbol)
{
    	printf("%-60s | ", "[PrePostFloatDollarFixer::print(float, char)]"); 

    	printf("%s%c%.2f%s\n", this->prePostDollarFixer.prePostFixer.pre, symbol, num, this->prePostDollarFixer.prePostFixer.post);
}
char _ZNK23PrePostFloatDollarFixer16getDefaultSymbolEv(const PrePostFloatDollarFixer *const this)
{
	return DEFAULT_SYMBOL_FLOAT_DOLLAR;
}
/* PrePostChecker Defs */

void  _ZN14PrePostCheckerC1Ev(PrePostChecker *const this)   
{
	_ZN23PrePostFloatDollarFixerC1EPKcS1_((PrePostFloatDollarFixer*)this, "[[[[ ", " ]]]]");
	this->prePostFloatDollarFixer.prePostDollarFixer.prePostFixer.defaultTextFormatter.textFormatter.vptr = PrePostChecker_vtable;
    	printf("--- PrePostChecker CTOR: \"%s\"...\"%s\"\n",  this->prePostFloatDollarFixer.prePostDollarFixer.prePostFixer.pre, this->prePostFloatDollarFixer.prePostDollarFixer.prePostFixer.post);
}    

void _ZN14PrePostCheckerD1Ev(PrePostChecker *const this)
{
    	printf("--- PrePostChecker CTOR: \"%s\"...\"%s\"\n", this->prePostFloatDollarFixer.prePostDollarFixer.prePostFixer.pre, this->prePostFloatDollarFixer.prePostDollarFixer.prePostFixer.post);
	this->prePostFloatDollarFixer.prePostDollarFixer.prePostFixer.defaultTextFormatter.textFormatter.vptr = PrePostFloatDollarFixer_vtable;
	_ZN23PrePostFloatDollarFixerD1Ev((PrePostFloatDollarFixer*)this);
}

void _ZNK14PrePostChecker24printThisSymbolUsingFuncEv(const PrePostChecker *const this)
{
	
    	printf("%-60s | ", "[PrePostChecker::printThisSymbolUsingFunc()]");
    	printf("Default symbol is %c\n", ((char(*)(const void* const))(this->prePostFloatDollarFixer.prePostDollarFixer.prePostFixer.defaultTextFormatter.textFormatter.vptr[3]))(this));
}

void _ZNK14PrePostChecker23printThisSymbolDirectlyEv(const PrePostChecker *const this)
{
    	printf("%-60s | ", "[PrePostChecker::printThisSymbolDirectly()]");

    	printf("Default symbol is %c\n", DEFAULT_SYMBOL_FLOAT_DOLLAR);
}

void  _ZNK14PrePostChecker32printDollarSymbolByCastUsingFuncEv(PrePostChecker *const this)
{
    	printf("%-60s | ", "[PrePostChecker::printDollarSymbolByCastUsingFunc()]");
	this->prePostFloatDollarFixer.prePostDollarFixer.prePostFixer.defaultTextFormatter.textFormatter.vptr = PrePostFloatDollarFixer_vtable;
    	printf("Default symbol is %c\n", ((char(*)(const void* const))(this->prePostFloatDollarFixer.prePostDollarFixer.prePostFixer.defaultTextFormatter.textFormatter.vptr[3]))((PrePostFloatDollarFixer*)this));
	this->prePostFloatDollarFixer.prePostDollarFixer.prePostFixer.defaultTextFormatter.textFormatter.vptr = PrePostChecker_vtable;
}

void _ZNK14PrePostChecker33printDollarSymbolByScopeUsingFuncEv(const PrePostChecker *const this)
{
    	printf("%-60s | ", "[PrePostChecker::printDollarSymbolByScopeUsingFunc()]");

    	printf("Default symbol is %c\n", _ZNK18PrePostDollarFixer16getDefaultSymbolEv((PrePostDollarFixer*)this));
}

void _ZNK14PrePostChecker31printDollarSymbolByCastDirectlyEv(const PrePostChecker *const this)
{
    	printf("%-60s | ", "[PrePostChecker::printDollarSymbolByCastDirectly()]");

    	printf("Default symbol is %c\n", DEFAULT_SYMBOL_DOLLAR);
}
void _ZNK14PrePostChecker32printDollarSymbolByScopeDirectlyEv(const PrePostChecker *const this)
{
    	printf("%-60s | ", "[PrePostChecker::printDollarSymbolByScopeDirectly()]");

    	printf("Default symbol is %c\n", DEFAULT_SYMBOL_DOLLAR);

}
/* Multiplier Defs */

void  _ZN10MultiplierD1Ev(Multiplier *const this)
{
    	printf("--- Multiplier DTOR: times = %d\n", this->times);
	this->defaultTextFormatter.textFormatter.vptr = DefaultTextFormatter_vtable;
	_ZN20DefaultTextFormatterD1Ev((DefaultTextFormatter*)this);
}

void _ZNK10Multiplier5printEPKc(const Multiplier *const this, const char* text)
{
	int i;
    	printf("%-60s | ", "[Multiplier::print(const char*)]");
    
    	for (i = 0; i < this->times; ++i)
        	printf("%s", text);
    	printf("\n");
}


