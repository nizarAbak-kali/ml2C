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
    if(s && (!u)){// si s est non null et u pas encore
        u = malloc(sizeof(*u));
        u->val = malloc(strlen(s)*sizeof(*(u->val)));
        memcpy(s,u->val,sizeof(*u->val));
    }
    else printf("pb au niveau de Mlstring");
}

void MLstringprint(MLstring u){
    printf("%s \n",u->val);
}
string MLstringAccess(MLstring u){
    return u->val;
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
        if(strcmp(v->type,"list") == 0){
            MLlistInit(v->l,init->l);
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
        if(strcmp(v->type,"list") == 0){
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
    f->MLenv = null;
}
void MLfunInit2(MLfun f,int n){
    f = malloc(sizeof(*f));
    f->MLcounter = 0;
    f->MLenv = malloc(n*sizeof(*(f->MLenv)));
}




/*
    struct MLruntime {// on y fout les MLvalue en tout

*/

        int main(){
            return 0;
        }
