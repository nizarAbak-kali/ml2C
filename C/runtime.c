#include "runtime.h"



/*  MLunit  */
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

/*  MLint */
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

/*  MLdouble */
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

/*  MLstring */
void MLstringInit(MLstring u , string s){
    if(s && (!u)){// si s est non NULL et u pas encore
        u = malloc(sizeof(*u));
        u->val = malloc(strlen(s)*sizeof(*(u->val)));
        memcpy(s,u->val,sizeof(*u->val));
    }
    else printf("pb au niveau de Mlstring");
}

/*   MLvalue  */
void MLvalueInit(MLvalue v,const char* s,MLvalue init){
    v = malloc(sizeof(*v));
    memcpy(v->type,s,20);
    if(v){
        if(strcmp(v->type,"unit") == 0){
            MLunitInit(v->u,init->u);
        }
        if(strcmp(v->type,"int") == 0){
            MLintInit(v->i,init->i);
        }
        if(strcmp(v->type,"bool") == 0){
            MLboolInit(v->b,init->b);
        }
        if(strcmp(v->type,"double") == 0){
            MLdoubleInit(v->d,init->d);
        }
        if(strcmp(v->type,"string") == 0){
            MLstringInit(v->i,init->s);
        }
        if(strcmp(v->type,"pair") == 0){
            MLpairInit(v->p,init->p);
        }
        if(s


    trcmp(v->type,"list") == 0){
            MLlistInit(v->l,init->l,NULL);
        }
        if(strcmp(v->type,"fun") == 0){
            MLfunInit(v->f,init->f);
        }

    }
}

void MLvalueprint(MLvalue v){
    if(v){
        if(strcmp(v->type,"unit") == 0){
            MLunitprint(v->u);
        }
        if(strcmp(v->type,"int") == 0){
            MLintprint(v->i);
        }
        if(strcmp(v->type,"bool") == 0){
            MLboolprint(v->b);
        }
        if(strcmp(v->type,"double") == 0){
            MLdoubleprint(v->d);
        }
        if(strcmp(v->type,"string") == 0){
            MLstringprint(v->i);
        }
        if(strcmp(v->type,"pair") == 0){
            MLpairprint(v->p);
        }
        //  FAIRE LES LISTES et les FUN ET LES PRIMITIVES
        if(strcmp(v->type,"list") == 0){
            MLlistprint(v->l);
        }
        if(strcmp(v->type,"fun") == 0){
            MLfunprint(v->f);
        }
    }
}

MLvalue MLvalueAccess(MLvalue v){
    MLvalue ret ; 
    if(v){
        if(strcmp(v->type,"unit") == 0){
            MLunitAccess(v->u);
        }
        if(strcmp(v->type,"int") == 0){
            MLintAccess(v->i);
        }
        if(strcmp(v->type,"bool") == 0){
            MLboolAccess(v->b);
        }
        if(strcmp(v->type,"double") == 0){
            MLdoubleAccess(v->d);
        }
        if(strcmp(v->type,"string") == 0){
            MLstringAccess(v->i);
        }
        if(strcmp(v->type,"pair") == 0){
            MLpairAccess(v->p);
        }
        //  FAIRE LES LISTES et les FUN ET LES PRIMITIVES
        if(s


    trcmp(v->type,"list") == 0){
            MLlistAccess(v->l);
        }
        if(strcmp(v->type,"fun") == 0){
            MLfunprint(v->f);
        }   
    }
}


/*  MLPair */
void MLpairInit(MLpair p, MLvalue a , MLvalue b){
            // on alloue de la memoire pour les deux MLvalue
    if(a&&b){
        p = malloc(sizeof(*p));
        *p->MLfst = *a;
        *p->MLsnd = *b;
    }
}

void MLpairprint(MLpair p){
        // on ne connait pas le type de ce qui doit etre printer
    if(p){
        printf("value : (  \n");
        MLvalueprint(p->MLfst);
        MLvalueprint(p->MLsnd);
        printf("value : (  \n");
        }
    else printf("MLPairPrint error");
}

MLvalue MLpairAccess1(MLPair u){
    return u->MLfst;
}
MLvalue MLpairAccess2(MLPair u){
    return u->MLsnd;
}

/*  MLlist  */
void MLlistInit(MLlist l, MLvalue a, MLvalue b){
    l->MLcar = a ;
    l->MLcdr = b->l ;    
}


void MLlistprint(MLlist l){
    if(!l->MLcar){ printf("[]\n");}
    else{
        MLvalueprint(l->MLcar);
        


printf("::");
        MLlistprint(l->MLcdr);
    }
}


MLvalue MLlistAccess1(MLlist l){
    return l->MLcar;
}


MLlist MLlistAccess2(MLlist l){
    return l->MLcdr;
}

/*  MLfun ....nous y voila ....*/
void MLfunInit1(MLfun f){
    f = malloc(sizeof(*f));
    f->MLcounter = 0;
    f->MLenv = NULL;
}
void MLfunInit2(MLfun f,int n){
    f = malloc(sizeof(*f));
    f->MLcounter = 0;
    f->MLenv = malloc(n*sizeof(*(f->MLenv)));
}

void MLfunaddenv(MLfun f,MLvalue* 0_env, MLvalue a){
    int i ;
    for(i=0 ; i < f->MLcounter ;i++){
        MLenv[i]=0_env[i];
    }
    f->MLenv[MLcounter] = a;
    MLcounter++;
}

void MLfunprint(MLfun f){
    int i;
    printf("<fun> [ \n");
    for (i = 0; i < f->MLcounter; ++i)
    {
        MLvalueprint(f->MLenv[i]);
    }
    printf("]\n");
}
// pas besoin de creer invoke dans fun 

/*  PRIMITIVES */
/*  heritage des fonctions de MLfun*/
void MLprimitivefunInit1(MLprimitive p){
    f = malloc(sizeof(*f));
    f->MLcounter = 0;
    f->MLenv = NULL;
}
void MLprimitivefunInit2(MLprimitive f,int n){
    f = malloc(sizeof(*f));
    f->MLcounter = 0;
    f->MLenv = malloc(n*sizeof(*(f->MLenv)));
}

void MLprimitivefunaddenv(MLprimitive f,MLvalue* 0_env, MLvalue a){
    int i ;
    for(i=0 ; i < f->MLcounter ;i++){
        MLenv[i]=0_env[i];
    }
    f->MLenv[MLcounter] = a;
    MLcounter++;
}

void MLprimitivefunprint(MLprimitive f){
    int i;
    printf("<fun> [ \n");
    for (i = 0; i < f->MLcounter; ++i)
    {
        MLvalueprint(f->MLenv[i]);
    }
    printf("]\n");
}
//extensions de primitive avec invoke 
MLvalue invoke(MLprimitive p, MLvalue v){
    if(strcmp("hd",p->name)==0)return MLruntimeMLhd_real(v->l);
    else if(strcmp("tl",p->name)==0)return MLruntimeMLtl_real(v->l);
    else if(strcmp("fst",p->name)==0)return MLruntimeMLfst_real(v->p);
    else if(strcmp("snd",p->name)==0)return MLruntimeMLsnd_real(v->p);
    else{fprintf(stderr, "Unknown primitive %s\n",p->name); return v;}
}



/*
struct MLruntime {// on y fout les MLvalue et tout
*/
/*  LE RUUUUUUUUUUUUUUNTIIIIIIIIIIIME*/

// booleens
MLbool MLruntimeMLtrue(){
    MLbool res ;
    MLboolInit(res,true);
    return res ;
}
MLbool MLruntimeMLfalse(){
    MLbool res ;
    MLboolInit(res,false);
    return res;
}
//  unit
MLunit MLruntimeMLlrp(){
    MLunit res;
    MLunitInit(res);
    return res;
}

// nil
MLlist MLruntimeMLnil(){
    MLvalue res;
    MLvalue a,b;
    a = b = NULL;
    MLlistInit(res,a,b);
    return res;   
}

// arithmetique sur les entiers
MLint MLruntimeMLaddint(MLint x, MLint y){
    MLint res;
    MLintInit(MLint res,(int)(x->val+y->val));
    return res;
}
MLint MLruntimeMLsubint(MLint x, MLint y){
    MLint res;
    MLintInit(MLint res,(int)(x->val-y->val));
    return res;
}MLint MLruntimeMLmulint(MLint x, MLint y){
    MLint res;
    MLintInit(MLint res,(int)(x->val*y->val));
    return res;
}MLint MLruntimeMLdivint(MLint x, MLint y){
    MLint res;
    MLintInit(MLint res,(int)(x->val/y->val));
    return res;
}




int main(){
    return 0;
}
