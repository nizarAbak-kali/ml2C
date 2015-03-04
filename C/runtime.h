#include <stdio.h>
#include <stdlib.h>


/*  MLUnit */
typedef struct MLunit{
	int val = 0; 
	}MLunit;
void MLunitprint(MLunit u){
	printf("() \n");
	}
int MLunitAccess(MLunit u){
	return u.val;
	}

/*  MLBool */
typedef struct MLbool{
	int val = 1;//set a true de base  
	}MLbool;
void MLboolInit(MLbool u,int bool){
	
	}
void MLboolprint(MLbool u){
	if(u.val)
		printf("true \n");
	else printf("false \n");
	}
int MLboolAccess(MLbool u){
	return u.val;
	}



struct MLruntime {// on y fout les MLValue en tout genre
	
	
	
	
	}
