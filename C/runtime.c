//#include "runtime.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char* string ;


/*   MLvalue  */

typedef struct MLvalue {
  const char type[20];//un tag pour savoir quelle type il en question
  union union_ML{
    MLunit u;
    MLbool b;
    MLint i;
    MLdouble d;
    MLpair p;
    MLlist l;
  }
    MLfun f;
} *MLValue;
//je sais pas si je dois init cette merde de union
void MLvalueInit(MLvalue v,const string s){
  v = malloc(sizeof(*v));
  v->type = s;
  if(v){
      switch(v->type){
      case "int":
	MLintInit(v->un3);
      break;
      case "unit":
	MLunitInit(v->u);
	break;
      case "bool":
	MLboolInit(v->b);
	break;
	//j''ai pas mis de pair pour unraison simple pair a deux
      case "double":
	MLdoubleInit(v->d);
	break;
      case "list":// a faire ....
	MLlistInit(v->l);
	break;
      case "fun" //aussi a faire
	MLfunInit(v-f);

      default:
	printf("MLvalueprint:types nom connue");
	break;
      }
  }
}



void MLvalueprint(Mlvalue v){
  if(v){
    switch(v->type){
    case "int":
      MLintprint(v->i);
      break;
    case "unit":
      MLunitprint(v->u);
      break;
    case "bool":
      MLboolprint(v->b);
      break;
      //j''ai pas mis de pair pour unraison simple pair a deux
    case "double":
      MLdoubleprint(v->d);
      break;
    case "list":// a faire ....
      MLlistprint(v->l);
      break;
    case "fun" //aussi a faire
      MLfunprint(v-f);

    default:
      printf("MLvalueprint:types nom connue");
      break;
    }
}



/*  MLUnit */
typedef struct MLunit{
  int val ;
} *MLunit;

void MLunitInit(MLunit u){
  u = malloc(sizeof(*u));
  u->val = 0;
}
void MLunitprint(MLunit u){
  printf("() \n");
}
int MLunitAccess(MLunit u){
  return u->val;
}

/*  MLBool */
typedef struct MLbool{
  int val;
}* MLbool;
void MLboolInit(MLbool u,int bool){
  u = malloc(sizeof(*u));
  u->val=bool;
}
void MLboolprint(MLbool u){
  if(u->val)
    printf("true \n");
  else printf("false \n");
}
int MLboolAccess(MLbool u){
  return u->val;
}

/*  MLInt */
typedef struct MLint{
  int val;
}* MLint;
void MLintInit(MLint u,int bool){
  u = malloc(sizeof(*u));
  u->val=bool;
}
void MLintprint(MLint u){
  printf("%d \n",u->val);
}
int MLintAccess(MLint u){
  return u->val;
}

/*  MLDouble */
typedef struct MLdouble{
  double val;
}* MLdouble;
void MLdoubleInit(MLdouble u , double bool){
  u = malloc(sizeof(*u));
  u->val = bool;
}
void MLdoubleprint(MLdouble u){
  printf("%f \n",u->val);
}
double MLdoubleAccess(MLdouble u){
  return u->val;
}

/*  MLString */
typedef struct MLString{
  string val;
}* MLString;
void MLStringInit(MLString u , String s){
  if(s && (!u)){// si s est non null et u pas encore
  u = malloc(sizeof(*u));
  u->val = malloc(strlen(s)*sizeof(*(u->val)));
  memcpy(s,);
  }
  else printf("pb au niveau de Mlstring");
}

void MLStringprint(MLString u){
  printf("%f \n",u->val);
}
string MLStringAccess(MLString u){
  return u->val;
}

/*  MLPair */
typedef struct MLPair{
  MLValue MLfst;
  MLValue MLsnd;
}* MLPair;

void MLPairInit(MLPair p, Mlvalue a , MLvalue b){
  // on alloue de la memoire pour les deux MLvalue
  if(a&&b){
    p = malloc(sizeof(*p));
    *p->MLfst = *a;
    *p->MLsnd = *b;
  }
}
void MLPairprint(MLPair p){
  // on ne connait pas le type de ce qui doit etre printer
  if(p){
    printf("value : \( \n");
    MLvalueprint(p->MLfst);
    MLvalueprint(p->MLsnd);
    printf("value : \) \n");
  }
  else print("MLPairPrint error")
}
pair MLPairAccess(MLPair u){
  return u->val;
}






/*
struct MLruntime {// on y fout les MLValue en tout
};
*/

int main(){
  return 0;
}
