#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* string ;

/********************************	Structures	*/
/*  MLunit */
typedef struct MLunit{
  int val ;
} *MLunit;

/*  MLbool */
typedef struct MLbool{
  int val;
}* MLbool;

/*  MLint */
typedef struct MLint{
  int val;
}* MLint;

/*  MLdouble */
typedef struct MLdouble{
  double val;
}* MLdouble;

/*  MLString */
typedef struct MLstring{
  string val;
}* MLstring;

/*   MLvalue  */
typedef struct MLvalue {
  const char type[20];//un tag pour savoir quelle type il en question
    // un pointeur vers:
    // un MLunit
    MLunit u;
    // un MLbool
    MLbool b;
    // un MLint
    MLint i;
    // un MLdouble
    MLdouble d;
		//un MLstring
		MLstring s;
    // un MLpair
    MLpair p;
    //MLlist
    MLlist l;
    //MLfun
    MLfun f;
} *MLvalue;

/*  MLPair */
typedef struct MLPair{
  MLvalue MLfst;
  MLvalue MLsnd;
}* MLPair;




/******************************************* 	Prototypes */

//	 UNIT
void MLunitInit(MLunit u);
void MLunitprint(MLunit u);
int MLunitAccess(MLunit u);

//	BOOL
void MLboolInit(MLbool u,int bool);
void MLboolprint(MLbool u);
int MLboolAccess(MLbool u);

//	INT
void MLintInit(MLint u,int n);
void MLintprint(MLint u);
int MLintAccess(MLint u);

//	DOUBLE
void MLdoubleInit(MLdouble u,double d);
void MLdoubleprint(MLdouble u);
double MLdoubleAccess(MLdouble u);

// STRING
void MLstringInit(MLstring u,string s);
void MLstringprint(MLstring u);
string MLstringAccess(MLstring u);

// VALUE
void MLvalueInit(MLvalue v,const char* s);
void MLvalueprint(MLvalue v);
MLvalue MLvalueAccess(MLvalue v);

//	PAIR
void MLPairInit(MLPair p, MLvalue a , MLvalue b);
void MLPairprint(MLPair p);
pair MLPairAccess(MLPair u){
