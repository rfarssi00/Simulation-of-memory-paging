#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define c1 "\x1b[35m"
#define c5 "\x1b[34m"
#define defaut   "\x1b[30m"

//structures utilisées


//liste des pages
 struct page{
	int adresse;
	struct page *page_svt;
};

//liste programme
 struct prog{
	char nom[15];
	int taille;
    struct page *page_prog;
	struct prog *prog_svt;
};

//prototypes
struct page * creation_liste_espace(struct page *p);
void afficher_espace(struct page* p);
int trouver_nbrPages(int t);
int Nbr_Elemt(struct page* pv);
struct page * creation_page(struct page *p, int t);
void afficher_page(struct page* pv);
struct prog* charger_prgm(struct prog * pgm,char l[],int taille,struct page*p);
struct page* supprimer_pages_charges(struct page *p,int taille);
struct prog* creation_programme(struct page* pg, struct prog* s,char n[] ,int t);
void afficher_prog(struct prog *p);
void afficher_prog_pages(struct prog *p);
void afficher_pages_prog(struct prog *p,char l[]);
struct prog * supprimer_prog(struct prog *pgm, char l[]);
struct page* fusionner(struct page* p,struct page* pg);
int get_taille(struct prog *p,char l[]);
struct page* get_listpage(struct prog *p,char l[]);
struct page * supprimerElementEnFin(struct page * pg);
int charcher(struct prog *p,char l[]);
void formater(char nom[20]);
char*  etat_memoire(struct prog *listeProg);


int main()
{
   // system("color 30");
    char choix[15];
    int t;
    char n[15];
    int taille;
    struct page * p = NULL;
    struct page *pg;
    struct prog *pgm=NULL;
	p=(struct page*)(malloc(sizeof(struct page)));
	p->adresse=0;
    p->page_svt=NULL;
    p=creation_liste_espace(p);



/*Afficher le menu à l'utilisateur*/
	system("cls");
    system("cls");
    printf("\n\n");
    printf("\n\t\t\t\t\t\t    Bonjour (^_^) !!\n\t\t\t\t\t   Gestion de la memoire par pagination\n ");
    printf("\n                            +-----------------Ce programme a ete realise par:---------------+\n");
    printf("                            |                      * HANDI Kaoutar                          |\n");
    printf("                            |                      * MAKHCHOUN Khadija                      |\n");
    printf("                            |                      * ATMANI Houda                           |\n");
    printf("                            |                      * FARAH Manal                            |\n");
    printf("                            |                      * OUZOUGAGH Chaimae                      |\n");
    printf("                            |                      * FARSSI Rahma                           |\n");
    printf("                            *---------------------------Encadre par :-----------------------*\n");
    printf("                            |                   Mme.TOUHAMI OUAZZANI Khadija                |\n");
    printf("                            *---------------------------------------------------------------*\n\n");



 while (strcmp(choix,"9")!=0) {

    printf("\n                                 +------------------------------------------------------+\n");
    printf("                                 |                      ~~ MENU ~~                      |\n");
    printf("                                 +------------------------------------------------------+\n");
    printf("                                 |         1 . Charger un programme                     |\n");
    printf("                                 |         2 . Afficher les pages vides                 |\n");
    printf("                                 |         3 . Afficher la lise des programmes          |\n");
    printf("                                 |         4 . chercher un programme                    |\n");
    printf("                                 |         5 . Afficher les programme par pages         |\n");
    printf("                                 |         6 . Terminer l'execution d'un programme      |\n");
    printf("                                 |         7 . Afficher la memoire centrale             |\n");
    printf("                                 |         8 . Vider la memoire                         |\n");
    printf("                                 |         9 . Quitter                                  |\n");
    printf("                                 *------------------------------------------------------*\n");

        //printf(c5);
		printf("\n--------> Veuillez selectionner une option: ");
		//printf(defaut);
		scanf("%s", &choix);
		printf("\n");


		if ( strcmp(choix,"1")==0) {

			printf("--------> Veuillez saisir le nom du programme a charger: ");
			scanf("%s", &n);
			printf("--------> veuillez saisir la taille de ce programme: ");
			scanf("%d", &taille);

            pgm=charger_prgm(pgm,n, taille, p);
		}
		else if (strcmp(choix,"2")==0) {
            int l=Nbr_Elemt(p);
         if(l==0){
            printf("\n----------Aucune page vide n'existe dans la memoire !!!! \n\n");
         }
         else{
           printf("\n----------Les pages vides dans la memoire : \n\n");
            afficher_espace(p);
            printf("\n");
         }
		}
		else if (strcmp(choix,"3")==0) {

            int s=Nbr_Elemt(p);
            if(s==25){
                printf("\n");
                printf("----------la memoire est vide !!!");
                printf("\n");
            }
            else{
                printf ("\n----------La lise des programmes : \n\n");
                afficher_prog(pgm);
                printf("\n");
            }
		}
		else if (strcmp(choix,"4")==0) {
            printf("--------> Veuillez saisir le nom du programme a afficher: ");
			scanf("%s", &n);
            int v=charcher(pgm,n);
           if(v==0){
                printf("\n");
             printf("----------Ce programme n'existe pas !!!!\n");

           }
           else{
              printf("\n");
              printf("\n----------Les pages du programme %s : \n\n",n);
              printf("\t    ");
              afficher_pages_prog(pgm,n);
              printf("\n");
           }

		}
		else if (strcmp(choix,"5")==0) {
		    int s=Nbr_Elemt(p);
                if(s==25){
                printf("\n");
                printf("--------!!!la memoire est vide!!!-------");
                printf("\n");
            }
            else{
               printf("\n----------La Liste des programmes : \n\n");
               afficher_prog_pages(pgm);
            }

		}
		else if (strcmp(choix,"6")==0) {

			printf("--------> Veuillez saisir le nom du programme a supprimer: ");
			scanf("%s", &n);
           int v=charcher(pgm,n);
          if(v==0){
             printf("----------Ce programme n'existe pas !!!!!\n");
          }
          else{
            pg=get_listpage(pgm,n);
            pg=supprimerElementEnFin(pg);
            pgm=supprimer_prog(pgm, n);
            printf("\n--------le programme a ete bien supprime-------\n");
            p=fusionner(p->page_svt,pg);
          }
		}
		else if (strcmp(choix,"7")==0) {
        etat_memoire(pgm);
		}
		else if(strcmp(choix,"8")==0){
            if(pgm==NULL){
                printf("\n----------La m%cmoire est d%cja vide !!!!",130,138);
            }
            else{
                while(pgm!=NULL){
                pg=get_listpage(pgm,pgm->nom);
                pg=supprimerElementEnFin(pg);
                pgm=supprimer_prog(pgm, pgm->nom);
                p=fusionner(p->page_svt,pg);
		    }
		    printf("----------La m%cmoire a bien %ct%c vid%c ",130,130,130,130);
            }
		}
		else {

            printf(" !!!!!!!! veuillez saisir un numero depuis le menu !!!!!!! \n");

		}
}
 printf("\n\n *~~~~~~~~~~ Merci pour avoir utilise ce programme (^_^) a tres bientot ~~~~~~~~~~*  \n\n");
return 0;
}
struct page * creation_liste_espace(struct page *p){
        struct page* nouveau = NULL;
        nouveau=(struct page*)(malloc(sizeof(struct page)));
        nouveau->adresse=1;
        nouveau->page_svt=NULL;
        p->page_svt=nouveau;
    for (int i =2; i<=26; i++){
        struct page * courant = NULL;
        courant=(struct page*)(malloc(sizeof(struct page)));
        courant->adresse=i;
        courant->page_svt=NULL;
        nouveau->page_svt=courant;
        nouveau= nouveau->page_svt;
    }
  return p;
}

void afficher_espace(struct page* p){

     while(p->page_svt->page_svt!=NULL){
         printf(" %d  ", p->page_svt->adresse);
         p=p->page_svt;
    }
}

int trouver_nbrPages(int taille){
int nbr_pages;
    nbr_pages= (taille/100);
        if (taille%100!=0)
        {
           nbr_pages=nbr_pages+1;
        }
  return nbr_pages ;
}


int Nbr_Elemt(struct page* p){
  int n=0;
  while(p->page_svt->page_svt!=NULL){
         n=n+1;
         p=p->page_svt;}
 return n;
}

struct page * creation_page(struct page *p, int t){
  struct page * pg = NULL;
	pg=(struct page*)(malloc(sizeof(struct page)));

	pg->adresse=0;
	pg->page_svt=NULL;
	struct page * nouveau = NULL;
	nouveau=(struct page*)(malloc(sizeof(struct page)));
    nouveau->adresse=p->page_svt->adresse;
    nouveau->page_svt=NULL;
    pg->page_svt=nouveau;

    for(int i=2; i<=t+1; i++){
        struct page * courant = NULL;
        courant=(struct page*)(malloc(sizeof(struct page)));
        courant->adresse=p->page_svt->page_svt->adresse;
        courant->page_svt=NULL;
        nouveau->page_svt=courant;
        nouveau= nouveau->page_svt;
        p=p->page_svt;

    	}
   return pg;
}

void afficher_page(struct page* pv){
     while(pv->page_svt->page_svt!=NULL){
         printf(" %d ", pv->page_svt->adresse);
         pv=pv->page_svt;
    }
}


struct page * supprimer_pages_charges(struct page *pr,int taille){
      struct page *nouveau;
      for (int i=0; i<taille ;i++){
       nouveau=pr->page_svt;
       pr->page_svt=pr->page_svt->page_svt;
        free(nouveau);
       }
  return pr;
}


void afficher_prog(struct prog *p){
     while(p!=NULL){
        printf("-----------------# %s \n",p->nom);
        p=p->prog_svt;
    }
}

void afficher_prog_pages(struct prog *p){
     while(p!=NULL){
        printf("-----------------# %s  :",p->nom);
        afficher_page(p->page_prog);
        printf("\n\n");
        p=p->prog_svt;
    }
}

struct prog* creation_programme(struct page* pg, struct prog* s,char n[] ,int t){
   struct prog* p;
   p = (struct prog*)malloc(sizeof(struct prog));
   strcpy(p->nom,n);
   p->taille=t;
   p->page_prog = pg;
   p->prog_svt = s;
 return p;
}

struct prog* charger_prgm(struct prog * pgm,char l[],int taille,struct page *p){
  if(taille<=0){
     printf("\n----------!!!taille insuportable!!!! \n");
  }
  else{
       struct page * nv = NULL;
       int t=trouver_nbrPages(taille);
       int n=Nbr_Elemt(p);
       int v=charcher(pgm,l);
  if(v==0){
      if (t>n){
         printf("\n----------!!!taille insuportable!!! \n");
      }
    else{
          struct page * Pg = NULL;
	      Pg=(struct page*)(malloc(sizeof(struct page)));
          Pg=creation_page(p, t);
          struct page * nv = NULL;
        nv=(struct page*)(malloc(sizeof(struct page)));
        nv=supprimer_pages_charges(p,t);
         printf("\n");
         if (pgm==NULL){
            pgm=creation_programme(Pg,NULL,l,t);
            printf("\n--------------le programme a ete bien enregistre \n");
         }
         else{
            struct prog *tmp;
            tmp=(struct prog*)(malloc(sizeof(struct prog)));
            tmp=pgm;
            while(tmp->prog_svt != NULL){

                 tmp = tmp->prog_svt;
            }
           tmp->prog_svt = creation_programme(Pg,NULL,l,t);
           printf("\n--------------le programme a ete bien enregistre \n");
         }
       }
   }
  else{
    printf("\n----------!!!!ce programme existe deja!!!! ");
  }
  }
 return pgm;
}

void afficher_pages_prog(struct prog *p,char l[]){

    while(p!=NULL){

         if(strcmp(l,p->nom)==0){
         afficher_page(p->page_prog);
          }
         p=p->prog_svt;
    }
}

int charcher(struct prog *p,char l[]){
   int v=0;
    while(p!=NULL){

         if(strcmp(l,p->nom)==0){
             v=1;
          }
         p=p->prog_svt;
    }
  return v;
}

struct page* get_listpage(struct prog *p,char l[]){

  struct prog * tmp = (struct prog * ) malloc(sizeof(struct prog * ));
  tmp = p;
  while (tmp) {
    if (strcmp(tmp->nom, l) == 0) {
      return tmp->page_prog;
    }
    tmp = tmp->prog_svt;
  }
}

struct prog * supprimer_prog(struct prog *pgm, char l[]){
    if(pgm == NULL)
        return NULL;
    if(strcmp(l,pgm->nom)==0)
    {
        struct prog* tmp = pgm->prog_svt;
        free(pgm);
        tmp = supprimer_prog(tmp, l);
        return tmp;
    }
    else
    {
        pgm->prog_svt = supprimer_prog(pgm->prog_svt,l);
        return pgm;
    }
 }

struct page* fusionner(struct page* p,struct page* pg)
{
    struct page* temp1=p;
    struct page* temp2=pg;

      if(temp1==NULL)
      {
         return temp2;
      }
      else if(temp2==NULL)
      {
         return temp1;
      }
      else if ((temp1->adresse) <= (temp2->adresse))
     {
          temp1->page_svt = fusionner(temp1->page_svt,temp2);
          return(temp1);
     }
      else
     {
         temp2->page_svt = fusionner(temp1,temp2->page_svt);
          return(temp2);
     }
}


struct page * supprimerElementEnFin(struct page * pg)
{
    if(pg == NULL)
        return NULL;
    if(pg->page_svt == NULL)
    {
        free(pg);
        return NULL;
    }

    struct page* tmp = pg;
    struct page* ptmp = pg;
    while(tmp->page_svt != NULL)
    {
        ptmp = tmp;
        tmp = tmp->page_svt;
    }
    ptmp->page_svt= NULL;
    free(tmp);
    return pg;
}

/****************************************Affichage**************************************************/

char*  etat_memoire(struct prog *listeProg){

    struct prog *p;
    p=listeProg;

    char T[25][10]={"","","","","","","","","","","","","","","","","","","","","","","","",""};

    while(p!=NULL){
              struct page *temp;
               temp=p->page_prog;
                while(temp->page_svt->page_svt!=NULL){

                temp=temp->page_svt;

                int j=temp->adresse;
                strcpy(T[j-1],p->nom);
            }
            temp=NULL;

            p=p->prog_svt;
    }

   printf(c5);
   printf("\n\t+********************************************************************+\n\t");
   printf("|\t\t\t\t\t\t\t\t     |\n");
   printf("\t|\t\t\t   ");
   printf(c1);
   printf("Memoire Centrale");
   printf(defaut);
   printf(c5);
   printf("   \t\t\t     |\n");
   printf("\t|\t\t\t\t\t\t\t\t     |\n");
   printf("\t+************++************++************++************++************+\n\t");
   printf(defaut);
    for (int i=0;i<5;i++){
       // printf(c);
        formater(T[i]);
       // printf(defaut);
    }
    printf("\n");
    printf(c5);
    printf("\t+************++************++************++************++************+\n\t");
    printf(defaut);
    for (int i=5;i<10;i++){
      // printf(c);
        formater(T[i]);
       // printf(defaut);
    }
    printf("\n");
    printf(c5);
    printf("\t+************++************++************++************++************+\n\t");
    printf(defaut);
    for (int i=10;i<15;i++){
        //printf(c);
        formater(T[i]);
        //printf(defaut);
    }
    printf("\n");
    printf(c5);
   printf("\t+************++************++************++************++************+\n\t");
   printf(defaut);
    for (int i=15;i<20;i++){
         //printf(c);
        formater(T[i]);
        //printf(defaut);
    }
    printf("\n");
    printf(c5);
    printf("\t+************++************++************++************++************+\n\t");
    printf(defaut);
    for (int i=20;i<25;i++){
        //printf(c);
        formater(T[i]);
        //printf(defaut);
    }
    printf("\n");
    printf(c5);
    printf("\t+************++************++************++************++************+\n\n\t");
    printf(defaut);
    return T;
}


void formater(char nom[20]) {
  char
  var [20] = "";
  int b = strlen(nom);
  if (b == 12) {
    printf(c5);
    printf( "|");
    printf(defaut);
    printf( "%s" , nom);
    printf(c5);
    printf( "|");
    printf(defaut);

  } else {
    int m = 12 - strlen(nom);
    int i;
    for (i = 0; i < m / 2; i++) {
      var [i] = ' ';
    }
    for (i = m / 2; i < b + m / 2; i++) {
      var [i] = nom[i - m / 2];
    }
    for (i = b + m / 2; i < b + m; i++) {
      var [i] = ' ';
    }
    printf(c5);
    printf( "|");
    printf(defaut);
    printf("%s",var);
    printf(c5);
    printf( "|");
    printf(defaut);

  }

}












