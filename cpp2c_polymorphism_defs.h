#ifndef __CPP2C_POLYMORPHISM_H__
#define __CPP2C_POLYMORPHISM_H__

#include <stdio.h>


inline void printFunc(const char* fname)
{
    printf("%-60s | ", fname); 
}

/* TextFormatter */

typedef struct TextFormatter
{
	void* vptr;

}TextFormatter;



/*virtual ~TextFormatter() { };  */
void _ZN13TextFormatterD0Ev(const  TextFormatter *const);


/*virtual void print(const char* text) const = 0;*/



/* DefaultTextFormatter */

typedef struct DefaultTextFormatter /*: public TextFormatter*/
{
	void* vptr;
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
void _ZN20DefaultTextFormatterD1Ev(const DefaultTextFormatter *const);

/*virtual void print(const char* text) const;*/
void _ZNK20DefaultTextFormatter5printEPKc(const DefaultTextFormatter *const, const char* text);

/*DefaultTextFormatter* generateFormatterArray();*/
DefaultTextFormatter* _Z22generateFormatterArrayv(const DefaultTextFormatter *const);


/* PrePostFixer */

typedef struct PrePostFixer /*: public DefaultTextFormatter*/
{
	void* vptr;
	DefaultTextFormatter defaultTextFormatter;
	const char* pre;
    	const char* post;

}PrePostFixer;

/* PrePostFixer Defs */

/*PrePostFixer(const char* prefix, const char* postfix);*/
void _ZN12PrePostFixerC1EPKcS1_(PrePostFixer *const, const char* prefix, const char* postfix);
/*~PrePostFixer();*/
void _ZN12PrePostFixerD1Ev(const PrePostFixer *const);

/*virtual void print(const char* text) const;*/
void _ZNK12PrePostFixer5printEPKc(const PrePostFixer *const, const char* text);

/*virtual void print(long num, char symbol = '\0') const;*/
void _ZNK12PrePostFixer5printElc(const PrePostFixer *const, long num, char symbol);

/*virtual char getDefaultSymbol() const;*/
char _ZNK12PrePostFixer16getDefaultSymbolEv(const PrePostFixer *const);





/* PrePostDollarFixer */

typedef struct PrePostDollarFixer /*: public PrePostFixer*/
{
	void* vptr;
	PrePostFixer prePostFixet;

}PrePostDollarFixer;

/* PrePostDollarFixer Defs */


/*PrePostDollarFixer(const char* prefix, const char* postfix);*/
void _ZN18PrePostDollarFixerC1EPKcS1_(PrePostDollarFixer *const, const char* prefix, const char* postfix);

/*PrePostDollarFixer(const PrePostDollarFixer& other);*/
void _ZN18PrePostDollarFixerC1ERKS_(PrePostDollarFixer *const, const PrePostDollarFixer* other);

/*~PrePostDollarFixer();*/
void _ZN18PrePostDollarFixerD1Ev(const PrePostDollarFixer *const);

/*void print(int num, char symbol = DEFAULT_SYMBOL) const;*/
void _ZNK18PrePostDollarFixer5printEic(const PrePostDollarFixer *const, int num, char* symbol);

/*void print(long num, char symbol = DEFAULT_SYMBOL) const;*/
void _ZNK18PrePostDollarFixer5printElc(const PrePostDollarFixer *const, long num, char symbol);

/*void print(double num, char symbol = DEFAULT_SYMBOL) const;*/
void _ZNK18PrePostDollarFixer5printEdc(const PrePostDollarFixer *const, double num, char symbol);

/*char getDefaultSymbol() const;*/
char _ZNK18PrePostDollarFixer16getDefaultSymbolEv(const PrePostDollarFixer *const);



 
/* PrePostHashFixer */

typedef struct PrePostHashFixer /*: public PrePostDollarFixer*/
{
	void* vptr;
	PrePostDollarFixer prePostDollarFixer;
	int precision;
    
}PrePostHashFixer;

/* PrePostHashFixer Defs */

/*PrePostHashFixer(int prc = 4);*/
void _ZN16PrePostHashFixerC1Ei(PrePostHashFixer *const, int prc);

/*~PrePostHashFixer();*/
void _ZN16PrePostHashFixerD1Ev(const PrePostHashFixer *const);

/*void print(int num, char symbol = DEFAULT_SYMBOL) const;*/
void _ZNK16PrePostHashFixer5printEic(const PrePostHashFixer *const, int num, char symbol);

/*void print(long num, char symbol = DEFAULT_SYMBOL) const;*/
void _ZNK16PrePostHashFixer5printElc(const PrePostHashFixer *const, long num, char symbol);

/*void print(double num, char symbol = DEFAULT_SYMBOL) const;*/
void _ZNK16PrePostHashFixer5printEdc(const PrePostHashFixer *const, double num, char symbol);

/*char getDefaultSymbol() const;*/
char _ZNK16PrePostHashFixer16getDefaultSymbolEv(const PrePostHashFixer *const)






/* PrePostFloatDollarFixer */

typedef struct PrePostFloatDollarFixer /*: public PrePostDollarFixer*/
{
	PrePostDollarFixer prePostDollarFixer;
protected:
    static const char DEFAULT_SYMBOL = '@';

public:
    PrePostFloatDollarFixer(const char* prefix, const char* postfix);
    ~PrePostFloatDollarFixer();
    void print(float num) const;
    void print(float num, char symbol) const;
    char getDefaultSymbol() const;
}PrePostFloatDollarFixer;

//// PrePostFloatDollarFixer Defs ////////////

inline char PrePostFloatDollarFixer::getDefaultSymbol() const
{
    return DEFAULT_SYMBOL;
}

/* PrePostChecker */

typedef struct PrePostChecker /*: public PrePostFloatDollarFixer*/
{
	PrePostFloatDollarFixer prePostFloatDollarFixer;
public:
    PrePostChecker();
    ~PrePostChecker();
    
    void printThisSymbolUsingFunc() const;
    void printThisSymbolDirectly() const;    
    void printDollarSymbolByCastUsingFunc() const;
    void printDollarSymbolByScopeUsingFunc() const;
    void printDollarSymbolByCastDirectly() const;
    void printDollarSymbolByScopeDirectly() const;
}PrePostChecker;


/* Multiplier */

typedef struct Multiplier /*: public DefaultTextFormatter*/
{
	DefaultTextFormatter defaultTextFormatter;
	int times;
public:
    Multiplier(int t = 2);
    ~Multiplier();

    void print(const char*) const;
    int getTimes() const;
    void setTimes(int);
    
}Multiplier; 

//// Multiplier Defs ////////////

inline Multiplier::Multiplier(int t)
:   times(t)
{
    printf("--- Multiplier CTOR: times = %d\n", times);
}

inline Multiplier::~Multiplier()
{
    printf("--- Multiplier DTOR: times = %d\n", times);
}
    
inline int Multiplier::getTimes() const
{
    return times;
}

inline void Multiplier::setTimes(int t)
{
    times = t;
}



#endif // __CPP2C_POLYMORPHISM_H__

