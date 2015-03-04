//#include "runtime.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char* string ;

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
  u = malloc(sizeof(*u));
  u->val = malloc(strlen(s)*sizeof(*(u->val)));
  
}
void MLStringprint(MLString u){
  printf("%f \n",u->val);
}
string MLStringAccess(MLString u){
  return u->val;
}


/*
struct MLruntime {// on y fout les MLValue en tout 	
};
*/

int main(){
  return 0;
}
