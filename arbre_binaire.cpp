#include <stdio.h>
#include <stdlib.h>
typedef struct  arbre_t{
   int valeur ;
    arbre_t * gauche;
    arbre_t * droit ;
}arbre_t;

arbre_t *cree_arbre ( int valeur , arbre_t *gauche , arbre_t *droit ) {
    arbre_t *arbre = (arbre_t*)malloc (sizeof (arbre_t));
    arbre->valeur = valeur ;
    arbre->gauche= gauche ;
    arbre->droit = droit ;
    return arbre ;
}



arbre_t *insere ( arbre_t *arbre , int valeur ) {
    if ( arbre== NULL)
        return cree_arbre (valeur,NULL,NULL) ;
    else {
        if ( valeur < arbre->valeur )
            arbre->gauche = insere(arbre->gauche , valeur ) ;
        else 
        arbre->droit = insere(arbre->droit , valeur ) ;
    return arbre ;
}
}


void afficher(arbre_t *arbre){
	if(arbre!=NULL){
		afficher(arbre->gauche);
		if(arbre->gauche!=NULL)
		   printf(",");
		   printf("%d",arbre->valeur);
		   printf(",");
		afficher(arbre->droit);
		if(arbre->droit!=NULL) ;
		 
			
	}
}

arbre_t *trouve_noeud ( arbre_t *arbre , int valeur ) {
 if ( arbre==NULL){
 	return NULL;
 }
if ( valeur == arbre->valeur ){
	printf("la valeure %d  est la ");

}
if ( valeur <arbre->valeur ) {
	if(arbre->gauche==NULL){
		return NULL;
	}
	else{
		while(arbre->gauche!=NULL){
	    	if(valeur==(arbre->gauche->valeur)){
			
	         	printf("est la ");
	         	break;
	         }
	         else{
	         	printf("n'est pas la ");
	         	break;
			 }
	         	
	}
	}
}
 else{
 	if(arbre->droit==NULL){
 		return NULL;
 		
	 }
	 else{
	 	while(arbre->droit!=NULL){
	 		if(valeur=(arbre->droit->valeur)){
	 			printf("elle est la ");
	 			break;
	 		
			 }
			 else{
			 	printf("elle n'est pas la ");
			 	break;
			 }
		 }
	 }
 }	


}

void afficher_arbre(arbre_t *arbre){
	afficher(arbre);
	printf("\n");
	
}
int nmbr_noeud(arbre_t *arbre){
	if(arbre==NULL)
	return 0;
	else{
	      return (1+nmbr_noeud(arbre->droit)+nmbr_noeud(arbre->gauche));
	}
}

void complet (arbre_t *arbre){
	if(arbre==NULL){
	  printf("arbre est complet ") ;
	}
	
	else if((arbre->gauche==NULL)&&(arbre->droit==NULL)||(arbre->droit!=NULL)&&(arbre->gauche!=NULL)){
		    printf("arbre  est complet ");
		}
	else{
		printf("arbre n'est pas complet ");
	}	
}
	
	
int max(int a,int b) 
{ 
	return (a>b)? a : b ; 
}	
int hauteure (arbre_t *arbre)  
{  
        if ( arbre==NULL ) {
                return 0;  
            }
        else  {
		
                return 1+max(hauteure(arbre->gauche ),hauteure(arbre->droit) );  
            }
}


int parfait(arbre_t *arbre){
	if(arbre==NULL){
		printf("arbre est parfait");
	}
	else {
		if(!complet){
			printf("arbre n'est pas complet donc n'est pas parfait  parfait ");
			
		}
		else{
			if(hauteure(arbre->droit)!=hauteure(arbre->gauche)){
				printf("hauteure(FG != FD )Donc arbre n'est pas parfait ");
			}
			else{
				printf("hauteure FG = FD  est arbre est complet Donc elle  est parfait ");
			}
		}
		
	}
	
}
int main(){
	int i,n,a,nb,rac,chx,option;

	arbre_t *abr=NULL;
	printf("donnez le nombre de la racine : ");
	scanf("%d",&rac);
	abr= cree_arbre(rac,NULL,NULL);
printf("donnez les element de arbre :");
	scanf("%d",&nb);
    for(i=0;i<nb;i++){
    	scanf("%d",&n);
    	abr=insere(abr,n);
	}	


printf("\n");


while(option){
		printf("Menu principale");
		printf("\n1.afficher: \n2.nombre_nouede:  \n3.Recherche_element: \n4.Verfier_complet:  \n5.la hauteure d'arbre \n6 arbre_parfait");
		printf("\n\5 donnez votre choix ");
		scanf("%d",&chx);
		
	switch (chx) {
        case 1:
           printf("le affichage de arbre : \n");
		   afficher(abr);
           break;
      case 2:
        printf("\n");
        printf("le nombre de noeude est =%d",nmbr_noeud(abr));  
         break;
        case 3:
          printf("donnez le nombre que vous avez rechercher  : ");
          scanf("%d",&a);
          trouve_noeud(abr,a);
          break;
        case 4:
           printf("\n");
           complet(abr);

        	break;
        case 5:
		  printf("la hauteure de arbre est = %d",hauteure(abr));
		  break;
		case 6:
		  parfait(abr);
		  break;	
 }
 printf("\n tapez 1 si vous avez continue et 0 pour quitez  : ");
      scanf("%d",&option);
  }
	
}





