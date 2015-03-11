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
typedef struct MLpair{
  MLvalue MLfst;
  MLvalue MLsnd;
}* MLPair;

/*  MLlist  */
typedef struct MLlist{
  MLvalue MLcar;
  MLlist* MLcdr;
}* MLlist;

/*  MLfun  */
typedef struct MLfun{
  int MLcounter;
  MLvalue* MLenv;
}* MLfun;

/*  MLprimitive  extends MLfun  */
typedef struct MLprimitive{
  char* name;
}* MLprimitive;

/*  MLruntime : les fonctions sont dans le .c */
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
void MLstringInit(MLstring u,char* s);
void MLstringprint(MLstring u);
string MLstringAccess(MLstring u);

// VALUE
void MLvalueInit(MLvalue v,const char* s);
void MLvalueprint(MLvalue v);
MLvalue MLvalueAccess(MLvalue v);

//	PAIR
void MLpairInit(MLPair p, MLvalue a , MLvalue b);
void MLpairprint(MLPair p);
MLvalue* MLpairAccess1(MLPair p); // retourne un tab de MLvalue 
MLvalue* MLpairAccess2(MLPair p);

//  LIST
void MLlistInit(MLlist l, MLvalue a, MLvalue b);
void MLlistprint(MLlist l);
MLvalue MLlistAccess1(MLlist l);
MLlist MLlistAccess2(MLlist l);

//  FUN
