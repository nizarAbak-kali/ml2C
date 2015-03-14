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
void MLvalueInit(MLvalue v,const char* s,MLvalue init,MLvalue init2){
    v = malloc(sizeof(*v));
    memcpy(v->type,s,20);
    if(v){
        if(strcmp(v->type,"unit") == 0){
            MLunitInit(v->u);
        }
        if(strcmp(v->type,"int") == 0){
            MLintInit(v->i,init->i->val);
        }
        if(strcmp(v->type,"bool") == 0){
            MLboolInit(v->b,init->b->val);
        }
        if(strcmp(v->type,"double") == 0){
            MLdoubleInit(v->d,init->d->val);
        }
        if(strcmp(v->type,"string") == 0){
            MLstringInit(v->i,init->s->val);
        }
        if(strcmp(v->type,"pair") == 0){
            MLpairInit(v->p,init,init2);
        }
        if(strcmp(v->type,"list") == 0){
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
            MLpairAccess1(v->p);
        }
        if(strcmp(v->type,"list") == 0){
            MLlistAccess1(v->l);
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

void MLfunaddenv(MLfun f,MLvalue* O_env, MLvalue a){
    int i ;
    for(i=0 ; i < f->MLcounter ;i++){
        MLenv[i]=O_env[i];
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
void MLprimitivefunInit1(MLprimitive f){
    f = malloc(sizeof(*f));
    f->MLcounter = 0;
    f->MLenv = NULL;
}
void MLprimitivefunInit2(MLprimitive f,int n){
    f = malloc(sizeof(*f));
    f->MLcounter = 0;
    f->MLenv = malloc(n*sizeof(*(f->MLenv)));
}

void MLprimitivefunaddenv(MLprimitive f,MLvalue* O_env, MLvalue a){
    int i ;
    for(i=0 ; i < f->MLcounter ;i++){
        MLenv[i]=O_env[i];
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
void MLprimitiveInit(MLprimitive p,string s){
    p->name = malloc(strlen(s)*sizeof(*p->name));
    int i ;
    for(i=0;i<strlen(p->name);i++)
        p->name[i] = s[i];
    MLprimitivefunInit1(p);//ou 2
}
MLvalue MLprimitiveinvoke(MLprimitive p, MLvalue v){
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
}
MLint MLruntimeMLmulint(MLint x, MLint y){
    MLint res;
    MLintInit(MLint res,(int)(x->val*y->val));
    return res;
}
MLint MLruntimeMLdivint(MLint x, MLint y){
    MLint res;
    MLintInit(MLint res,(int)(x->val/y->val));
    return res;
}

//  fonction equals
MLbool MLruntimeMLequal(MLvalue x,MLvalue y){
    MLbool btrue ;
    MLboolInit(btrue,true);
    MLbool bfalse;
    MLboolInit(bfalse,false);
    if(x==y)
        return btrue;
    if (strcmp(x->type,y->type)==0){
        if(strcmp(x->type,"unit") == 0){
            return btrue;
        }
        if(strcmp(x->type,"int") == 0){
            if(x->i == y->i){
                return btrue;
            }
            else{
                return bfalse;
            }
        }
        if(strcmp(x->type,"bool") == 0){
            if(x->b == y->b){
                return btrue;
            }
            else{
                return bfalse;
            }
        }
        if(strcmp(x->type,"double") == 0){
            if(x->d == y->d){
                return btrue;
            }
            else{
                return bfalse;
            }
        }
        if(strcmp(x->type,"string") == 0){
            if(strcmp(x->s,y->s)==0){
                return btrue;
            }
            else{
                return bfalse;
            }
        }
        if(strcmp(x->type,"pair") == 0){
            MLbool tmp1,tmp2,tmp3;
            // on compare les deux first 
            tmp1 = MLruntimeMLequal(x->p->MLfst,y->p->MLfst);
            // on compare les deux snd
            tmp2 = MLruntimeMLequal(x->p->MLsnd,y->p->MLsnd);
            // on compare le resultat des deux comparaisons precedentes 
            tmp3 = MLruntimeMLequal(tmp2,tmp1);
            
            if(tmp3->val==true)
                return btrue;
            else
                return bfalse;
        }
        if(strcmp(x->type,"list") == 0){
            MLbool tmp1 = MLruntimeMLequal(x->MLcar,y->MLcar);//en temps normal je foutre des MLAccess partout 
            MLbool tmp2 = MLruntimeMLequal(x->MLcdr,y->MLcdr);// mais la , la flemme 
            
            if(MLboolAccess(tmp2)==MLboolAccess(tmp1))
                return btrue;
            else 
                return bfalse;
        }
        // if(strcmp(v->type,"fun") == 0){
        //     MLfunprint(v->f);
        // }
    }
    else{
        fprintf(stderr,"type_different");
        MLboolInit(b,false);
        return b;
    }
}
// inégalites sur les entiers 
MLbool MLruntimeMLltint(MLint x,MLint y){
    MLbool b ;
    if(MLintAccess(x)<MLintAccess(y))
        MLboolInit(b,true);
    else 
        MLboolInit(b,false);
    return  b;
}

MLbool MLruntimeMLleint(MLint x,MLint y){
    MLbool b ;
    if(MLintAccess(x)<=MLintAccess(y))
        MLboolInit(b,true);
    else 
        MLboolInit(b,false);
    return  b;
}

MLbool MLruntimeMLgtint(MLint x,MLint y){
    MLbool b ;
    if(MLintAccess(x)>MLintAccess(y))
        MLboolInit(b,true);
    else 
        MLboolInit(b,false);
    return  b;
}

MLbool MLruntimeMLgeint(MLint x,MLint y){
    MLbool b ;
    if(MLintAccess(x)>=MLintAccess(y))
        MLboolInit(b,true);
    else 
        MLboolInit(b,false);
    return  b;
}
// paire
MLpair MLruntimeMLpair(MLvalue x,MLvalue y){
    MLpair p ;
    MLpairInit(p,x,y);
    return p;
}
// liste
MLlist MLruntimeMLlist(MLlist x,MLlist y){
    MLlist l;
    MLlistInit(l,x,y);
    return l;
}
// concat de string
MLstring MLruntimeMLconcat(MLstring x, MLstring y){
    MLstring mls;
    // on creer une chaine de char 
    // de la taille size(x)+size(y)
    string s = malloc(strlen(x->val)+strlen(y->val)*sizeof(*s));
    // on rempli s avec x 
    int i;
    for(i=0;i>strlen(x);i++){
        s[i]= x->val[i];
    }
    //on rempli un peu plus avec y 
    for(i=strlen(x);i>strlen(y);i++){
        s[i]= y->val[i];
    }
    MLstringInit(mls,s);
}

//Acces au champs des paires 
MLprimitive MLruntimeMLfst(MLprimitive p){
    string s = "fst";
    MLprimitiveInit(p,s);
}
MLvalue MLruntimeMLfst_real(MLpair p){
    return MLpairAccess1(p);
}
MLprimitive MLruntimeMLsnd(MLprimitive p){
    string s = "snd";
    MLprimitiveInit(p,s);
}
MLvalue MLruntimeMLsnd_real(MLpair p){
    return MLpairAccess2(p);
}

// acces aux champs des listes
MLprimitive MLruntimeMLhd(MLprimitive p){
    string s = "hd";
    MLprimitiveInit(p,s);
}
MLvalue MLruntimeMLhd_real(MLlist l){
    return MLlistAccess1(l);
}
MLprimitive MLruntimeMLtl(MLprimitive p){
    string s = "tl";
    MLprimitiveInit(p,s);
}
MLvalue MLruntimeMLtl_real(MLlist l){
    return MLlistAccess2(l);
}

// la fonction d'affichage
MLunit MLprint(MLvalue x){
    MLvalueprint(x);
    printf("\n");
    return MLruntimeMLlrp();
}


int main(){
    return 0;
}
