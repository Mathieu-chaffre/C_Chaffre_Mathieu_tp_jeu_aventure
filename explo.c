#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char decision[20];
int reponse =1;
int loop =1;
int compteur =0;
int save;
int stamina=100;
int compteur_repos;

struct Lieu{

char nom[25];
int difficulte;
int tableau[19];
char desc[1000];
char desc_2[1000];

};

typedef struct Lieu lieu;



void nom( char * decision, lieu * lieu){
reponse =1;
reponse = strcmp(decision, (*lieu).nom  );



}

void deplacement(lieu * lieux){

  while(reponse !=0 && compteur <=3){
   compteur +=1;
   nom(decision, &lieux[compteur]);
    save = compteur;
}

   compteur = 0;
if(reponse == 0){

  printf("Tu te dirige vers %s\n ", decision);
  printf("%s", lieux[save].desc);
  printf("%s\n", lieux[save].desc_2);
   
}
printf("ou veux tu aller ?\n ");
printf("tu peux aller : %s\n", lieux[lieux[save].tableau[1]].nom);
printf("tu peux aller : %s\n", lieux[lieux[save].tableau[2]].nom);
}



int main(){


  lieu lieux[20];
  lieux[1].difficulte = 15;
  strcpy(lieux[1].nom, "plage");
  strcpy(lieux[1].desc, "tu arrive sur une magnifique plage pleins de poissons morts\n");
  strcpy(lieux[3].desc_2, "");
  lieux[1].tableau[1] = 2 ;
  lieux[1].tableau[2] = 3 ;

  lieux[2].difficulte = 19;
  strcpy(lieux[2].nom, "montagne");
  strcpy(lieux[2].desc, "tu arrive sur vers une montagne avec un cimetiere abandonne\n");
  strcpy(lieux[3].desc_2, "");
  lieux[2].tableau[1] = 1 ;
  lieux[2].tableau[2] = 3 ;

  lieux[3].difficulte = 3;
  strcpy(lieux[3].nom, "village");
  strcpy(lieux[3].desc, "tu arrive sur vers un village magnifique de riche\n");
  strcpy(lieux[3].desc_2, "");
  lieux[3].tableau[1] = 2 ;
  lieux[3].tableau[2] = 1 ;





  printf("tu peux aller %s ou %s ou encore %s\n", lieux[1].nom , lieux[2].nom, lieux[3].nom );
printf("Ou veux tu aller ?\n");
scanf("%s", decision);


while(loop == 1){
  if(strcmp(decision, lieux[save].nom) !=0 && strcmp(decision,"avantposte") != 0 && stamina > 0 && strcmp(decision,"repos") != 0 ){
          reponse =1;
          stamina = stamina - lieux[save].difficulte;
            deplacement(&lieux[0]);
            stamina = stamina - lieux[save].difficulte;
            printf("Il te reste %d stamina\n", stamina);

}


if(strcmp(decision,"avantposte") == 0 && lieux[save].difficulte >= 10){
  printf("tu creer un avant poste !\n");
  lieux[save].difficulte = lieux[save].difficulte/2;
  strcpy(lieux[save].desc_2, "il y a un avant poste\n");
  printf("la difficulte est : %d\n", lieux[save].difficulte);
}
else if ((strcmp(decision,"avantposte") == 0 && lieux[save].difficulte < 10)){
  printf("Tu ne peux pas creer d'avant poste !\n");
}

if(strcmp(decision,"repos") == 0 && lieux[save].difficulte <= 5){
  printf("tu te repose \n");
  while(stamina < 100 && compteur_repos < 50 ){
    compteur_repos += 1;
    stamina = stamina + compteur_repos;
  }
  printf("tu as %d stamina ! \n", stamina);
}
else if (strcmp(decision,"repos") == 0 && lieux[save].difficulte > 5){
  printf("tu ne peux te reposer tu es en endroit hostile !\n");
}

scanf("%s", decision);

if(strcmp(decision, "arreter")==0 || stamina <= 0){
  printf("tu t'arrete !");
  loop =0;
}
if(strcmp(decision, lieux[save].nom) ==0)
            printf("tu ne peux pas effectuer ce deplacements\n");
}




  return 0;
}
