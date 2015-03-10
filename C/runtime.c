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
        // a modifier par une suite de if else
        /*switch(v->type){
        case "int":

        break;
        case "unit":
        MLunitInit(v->u);
        break;
        MLdoubleInit(v->d);
        case "bool":
        MLboolInit(v->b);
        break;
        //j''ai pas mis de pair pour unraison simple pair a deux
        case "double":
        break;
        case "string":
        MLstringInit(v->s);
        break;
        case "list":// a faire ....
        MLlistInit(v->l);
        break;
        case "fun" //aussi a faire
        MLfunInit(v-f);

        default
        printf("MLvalueprint:types nom connue");
        break;
    }*/
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
        MLstringInit(v->i,init->i);
    }
}
}

void MLvalueprint(MLvalue v){
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
            case "string":
            MLstringprint(v->s);
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

    MLvalue MLvalueAccess(MLvalue v){

        if(v){
            switch(v->type){
                case "int":
                int i ;
                MLintAccess(v->i);
                break;
                case "unit":
                MLunitAccess(v->u);
                break;
                case "bool":
                MLboolAccess(v->b);
                break;
                //j''ai pas mis de pair pour unraison simple pair a deux
                case "double":
                MLdoubleAccess(v->d);
                break;
                case "string":
                MLstringAccess(v->s);
                break;
                /*case "list":// a faire ....
                MLlistAccess(v->l);
                break;
                case "fun" //aussi a faire
                MLfunAcess(v->f);
                */
                default:
                printf("MLvalueprint:types nom connue");
                exit(0);
                break;
            }
        }
    }


    /*  MLPair */
    void MLPairInit(MLPair p, MLvalue a , MLvalue b){
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
            printf("value : (  \n");
            MLvalueprint(p->MLfst);
            MLvalueprint(p->MLsnd);
            printf("value : (  \n");
        }
        else print("MLPairPrint error")
    }
    MLpair MLPairAccess(MLPair u){
        return u->val;
    }





    /*
    struct MLruntime {// on y fout les MLvalue en tout
};
*/

int main(){
    return 0;
}
