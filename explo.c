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
int alea_monstre;
int decision_combat;
int decision_ennemie_ogre;
int decision_ennemie_slime;

struct Lieu{

char nom[25];
int difficulte;
int tableau[19];
char desc[1000];
char desc_2[1000];

};

struct Combat {
int vie;
int attaque;
};

typedef struct Lieu lieu;
typedef struct Combat combat;



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

void defense_ogre(combat * player, combat * ogre){
  printf("L'ennemie se defends !\n");
  if(decision_combat == 1){
    printf("Tu attaque mais ton épée explose en morceau !\n");
    (*ogre).vie = (*ogre).vie - ((*player).attaque/2);
  }
  if(decision_combat == 2){
    printf("Tu te defends aussi donc pas de degats !\n");
  }

  printf("Il te reste %d vie !\n", (*player).vie);
    printf("Il lui reste %d\n", (*ogre).vie);
}

void attaque_ogre(combat * ogre, combat * player){
  printf("L'ennemie attaque !\n");
  if(decision_combat == 1){
    printf("Tu attaque aussi !\n");
    player->vie = player->vie - ogre->attaque;
    (*ogre).vie = (*ogre).vie - (*player).attaque;
  }
  if(decision_combat == 2){
    printf("tu te defends !\n");
    (*player).vie = (*player).vie - ((*ogre).attaque /2);
  }

  printf("Il te reste %d vie !\n", (*player).vie);
    printf("Il lui reste %d\n", (*ogre).vie);

}




void defense_slime(combat * player, combat * slime){

  if(decision_combat == 1){
    printf("L'ennemie gobe ton épee !\n");
  }
  if(decision_combat == 2){
    printf("Tu te defends !\n");
  }

  printf("Il te reste %d vie !\n", (*player).vie);
    printf("Il lui reste %d\n", (*slime).vie);
}

void attaque_slime(combat * slime, combat * player){
  printf("L'ennemie attaque !\n");
  if(decision_combat == 1){
    printf("Tu attaque aussi !\n");
    player->vie = player->vie - slime->attaque;
    (*slime).vie = (*slime).vie - (*player).attaque;
  }
  if(decision_combat == 2){
    printf("tu te defends !\n");
    (*player).vie = (*player).vie - ((*slime).attaque /2);
  }

  printf("Il te reste %d vie !\n", (*player).vie);
    printf("Il lui reste %d\n", (*slime).vie);

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

  combat player = {100, 10};
  combat ogre = {200,5};
  combat slime =  {50, 2};





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
  if(stamina > 100){
  stamina = 100;
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
if(strcmp(decision, lieux[save].nom) ==0){
            printf("tu ne peux pas effectuer ce deplacements\n");
}

if(strcmp(lieux[save].nom, "montagne") == 0 && strcmp("combat", decision) == 0){
  printf("Tu attaque un monstre !");
  stamina = stamina - 20;
  srand(time(NULL));
  int nbgen=rand()%2+1;
  alea_monstre = nbgen;
  if(alea_monstre == 1){
    printf("Un ogre t'attaque !\n");
    printf("%d\n", ogre.vie);
    printf("%d\n", player.vie);
    while(ogre.vie > 0 && player.vie > 0){
      printf("Que veux tu faire ? (attaque =1 et defense = 2)\n");
      scanf("%d", &decision_combat);
      srand(time(NULL));
      int nbgen=rand()%2+1;
      decision_ennemie_ogre = nbgen;
      if(decision_ennemie_ogre == 1){
        defense_ogre(&player, &ogre);
      }
      if(decision_ennemie_ogre == 2){
        attaque_ogre(&ogre, &player);
      }
    }
    printf("Il est mort\n");
    printf("Ou veux-tu aller ?\n");
    printf("Tu peux aller : plage\n");
    printf("Tu peux aller : montagne\n");
    scanf("%s", decision);
  }
  else if(alea_monstre == 2){
    printf("Un slime t'attaque !");
    while(player.vie > 0 && slime.vie >0){
      printf("Que veux tu faire ? (attaque =1 et defense = 2)\n");
      scanf("%d", &decision_combat);
    srand(time(NULL));
      int nbgen=rand()%2+1;
      decision_ennemie_slime = nbgen;
      if(decision_ennemie_slime == 1){
        defense_slime(&player, &slime);
      }
      if(decision_ennemie_slime == 2){
        attaque_slime(&slime, &player);
      }
    }
    printf("Il est mort\n");
    printf("Ou veux-tu aller ?\n");
    printf("Tu peux aller : plage\n");
    printf("Tu peux aller : montagne\n");
    scanf("%s", decision);
  }
}


}




  return 0;
}
