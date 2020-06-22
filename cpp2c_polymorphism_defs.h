#ifndef __CPP2C_POLYMORPHISM_H__
#define __CPP2C_POLYMORPHISM_H__
#include <stdio.h>

typedef void (*funcptr)();

/* TextFormatter */

typedef struct TextFormatter
{
	funcptr* vptr;

}TextFormatter;



/*virtual ~TextFormatter() { };  */
void _ZN13TextFormatterD0Ev(const  TextFormatter *const);


/*virtual void print(const char* text) const = 0;*/



/* DefaultTextFormatter */

typedef struct DefaultTextFormatter /*: public TextFormatter*/
{
	TextFormatter textFormatter;
	int id;

}DefaultTextFormatter;


/*DefaultTextFormatter();*/
void _ZN20DefaultTextFormatterC1ERKS_(DefaultTextFormatter *const);

/*DefaultTextFormatter(const DefaultTextFormatter&);*/
void  _ZN20DefaultTextFormatterC1Ev(DefaultTextFormatter *const, const DefaultTextFormatter *const other);

/*DefaultTextFormatter& operator=(const DefaultTextFormatter&);*/
DefaultTextFormatter* _ZN20DefaultTextFormatteraSERKS_(DefaultTextFormatter *const, const DefaultTextFormatter *const other);
/*~DefaultTextFormatter();*/
void _ZN20DefaultTextFormatterD1Ev(DefaultTextFormatter *const);

/*virtual void print(const char* text) const;*/
void _ZNK20DefaultTextFormatter5printEPKc(const DefaultTextFormatter *const, const char* text);

/*DefaultTextFormatter* generateFormatterArray();*/
DefaultTextFormatter* _Z22generateFormatterArrayv();


/* PrePostFixer */

typedef struct PrePostFixer /*: public DefaultTextFormatter*/
{
	DefaultTextFormatter defaultTextFormatter;
	const char* pre;
    	const char* post;

}PrePostFixer;

/* PrePostFixer Defs */

/*PrePostFixer(const char* prefix, const char* postfix);*/
void _ZN12PrePostFixerC1EPKcS1_(PrePostFixer *const, const char* prefix, const char* postfix);

/*~PrePostFixer();*/
void _ZN12PrePostFixerD1Ev(PrePostFixer *const);

/*virtual void print(const char* text) const;*/
void _ZNK12PrePostFixer5printEPKc(const PrePostFixer *const, const char* text);

/* virtual void print(long num, char symbol = '\0') const;*/
void _ZNK12PrePostFixer5printElc(const PrePostFixer *const, long num, char symbol);

/*virtual char getDefaultSymbol() const;*/
char _ZNK12PrePostFixer16getDefaultSymbolEv(const PrePostFixer *const);



/* PrePostDollarFixer */

typedef struct PrePostDollarFixer /*: public PrePostFixer*/
{
	PrePostFixer prePostFixer;

}PrePostDollarFixer;

/* PrePostDollarFixer Defs */


/*PrePostDollarFixer(const char* prefix, const char* postfix);*/
void _ZN18PrePostDollarFixerC1EPKcS1_(PrePostDollarFixer *const, const char* prefix, const char* postfix);

/*PrePostDollarFixer(const PrePostDollarFixer& other);*/
void _ZN18PrePostDollarFixerC1ERKS_(PrePostDollarFixer *const, const PrePostDollarFixer* other);

/*~PrePostDollarFixer();*/
void _ZN18PrePostDollarFixerD1Ev(PrePostDollarFixer *const);

/*void print(int num, char symbol = DEFAULT_SYMBOL) const;*/
void _ZNK18PrePostDollarFixer5printEic(const PrePostDollarFixer *const, int num, char symbol);

/*void print(long num, char symbol = DEFAULT_SYMBOL) const;*/
void _ZNK18PrePostDollarFixer5printElc(const PrePostDollarFixer *const, long num, char symbol);

/*void print(double num, char symbol = DEFAULT_SYMBOL) const;*/
void _ZNK18PrePostDollarFixer5printEdc(const PrePostDollarFixer *const, double num, char symbol);

/*char getDefaultSymbol() const;*/
char _ZNK18PrePostDollarFixer16getDefaultSymbolEv(const PrePostDollarFixer *const);


/* PrePostHashFixer */

typedef struct PrePostHashFixer /*: public PrePostDollarFixer*/
{
	PrePostDollarFixer prePostDollarFixer;
	int precision;
    
}PrePostHashFixer;

/* PrePostHashFixer Defs */

/*PrePostHashFixer(int prc = 4);*/
void _ZN16PrePostHashFixerC1Ei(PrePostHashFixer *const, int prc);

/*~PrePostHashFixer();*/
void _ZN16PrePostHashFixerD1Ev(PrePostHashFixer *const);

/*void print(int num, char symbol = DEFAULT_SYMBOL) const;*/
void _ZNK16PrePostHashFixer5printEic(const PrePostHashFixer *const, int num, char symbol);

/*void print(long num, char symbol = DEFAULT_SYMBOL) const;*/
void _ZNK16PrePostHashFixer5printElc(const PrePostHashFixer *const, long num, char symbol);

/*void print(double num, char symbol = DEFAULT_SYMBOL) const;*/
void _ZNK16PrePostHashFixer5printEdc(const PrePostHashFixer *const, double num, char symbol);

/*char getDefaultSymbol() const;*/
char _ZNK16PrePostHashFixer16getDefaultSymbolEv(const PrePostHashFixer *const);






/* PrePostFloatDollarFixer */

typedef struct PrePostFloatDollarFixer /*: public PrePostDollarFixer*/
{
	PrePostDollarFixer prePostDollarFixer;
   
}PrePostFloatDollarFixer;


/* PrePostFloatDollarFixer Defs */

/*PrePostFloatDollarFixer(const char* prefix, const char* postfix);*/
void _ZN23PrePostFloatDollarFixerC1EPKcS1_(PrePostFloatDollarFixer *const, const char* prefix, const char* postfix);

/*~PrePostFloatDollarFixer();*/
void _ZN23PrePostFloatDollarFixerD1Ev(PrePostFloatDollarFixer *const);

/*void print(float num) const;*/
void _ZNK23PrePostFloatDollarFixer5printEf(const PrePostFloatDollarFixer *const, float num);

/*void print(float num, char symbol) const;*/
void  _ZNK23PrePostFloatDollarFixer5printEfc(const PrePostFloatDollarFixer *const, float num, char symbol);

/*char getDefaultSymbol() const;*/
char _ZNK23PrePostFloatDollarFixer16getDefaultSymbolEv(const PrePostFloatDollarFixer *const);


/* PrePostChecker */

typedef struct PrePostChecker /*: public PrePostFloatDollarFixer*/
{
	PrePostFloatDollarFixer prePostFloatDollarFixer;

}PrePostChecker;

/*PrePostChecker();*/
void  _ZN14PrePostCheckerC1Ev(PrePostChecker *const);

/*~PrePostChecker();*/
void _ZN14PrePostCheckerD1Ev(PrePostChecker *const);

/*void printThisSymbolUsingFunc() const;*/
void _ZNK14PrePostChecker24printThisSymbolUsingFuncEv(const PrePostChecker *const);

/*void printThisSymbolDirectly() const;*/
void _ZNK14PrePostChecker23printThisSymbolDirectlyEv(const PrePostChecker *const);

/*void printDollarSymbolByCastUsingFunc() const;*/
void  _ZNK14PrePostChecker32printDollarSymbolByCastUsingFuncEv(PrePostChecker *const);

/*void printDollarSymbolByScopeUsingFunc() const;*/
void _ZNK14PrePostChecker33printDollarSymbolByScopeUsingFuncEv(const PrePostChecker *const);

/*void printDollarSymbolByCastDirectly() const;*/
void _ZNK14PrePostChecker31printDollarSymbolByCastDirectlyEv(const PrePostChecker *const);

/*void printDollarSymbolByScopeDirectly() const;*/
void _ZNK14PrePostChecker32printDollarSymbolByScopeDirectlyEv(const PrePostChecker *const);



typedef struct Multiplier /*: public DefaultTextFormatter*/
{
	DefaultTextFormatter defaultTextFormatter;
	int times;

}Multiplier;

/*Multiplier(int t = 2);*/
void _ZN10MultiplierC1Ei(Multiplier *const, int t);

/*~Multiplier();*/
void  _ZN10MultiplierD1Ev(Multiplier *const);

/*void print(const char*) const;*/
void _ZNK10Multiplier5printEPKc(const Multiplier *const, const char*);

/*int getTimes() const;*/
int _ZTI10Multiplier0getTimes(const Multiplier *const);

/*void setTimes(int);*/
int _ZTI10Multiplier0setTimes(const Multiplier *const);

#endif /* __CPP2C_POLYMORPHISM_H__*/

