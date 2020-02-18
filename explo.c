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
int loop_2;
int demande;
int nombre;
int piece = 200;
int demande_2;
int alea;

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

struct Objet{
  int classement;
  char nom[50];
  int nombre;
  int prix;
  int inventaire;
};

typedef struct Objet objet;
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

void defense_ogre(combat * player, combat * ogre, objet * attaque, objet * defense){
  printf("L'ennemie se defends !\n");

  (*attaque).inventaire -=1;
  if((*attaque).inventaire < 0){
      (*attaque).inventaire =0;
    }
  if(decision_combat == 1){
    printf("Tu attaque mais ton épée explose en morceau !\n");
    if((*attaque).inventaire > 0){

    (*ogre).vie = (*ogre).vie - ((*player).attaque/2);
    }
    else if ((*attaque).inventaire <=0){
      (*ogre).vie = (*ogre).vie - ((*player).attaque/4);

    }
  }
  if(decision_combat == 2){
    printf("Tu te defends aussi donc pas de degats !\n");
  }

  printf("Il te reste %d vie !\n", (*player).vie);
    printf("Il lui reste %d\n", (*ogre).vie);
}

void attaque_ogre(combat * ogre, combat * player, objet * attaque, objet * defense ){
  printf("L'ennemie attaque !\n");
  if(decision_combat == 1){
    printf("Tu attaque aussi !\n");
    if((*attaque).inventaire > 0){

    player->vie = player->vie - ogre->attaque;
    (*ogre).vie = (*ogre).vie - (*player).attaque;
    }
    else if((*attaque).inventaire <=0){
      player->vie = player->vie - ogre->attaque;
    (*ogre).vie = (*ogre).vie - ((*player).attaque /2);
    }
  }
  if(decision_combat == 2){
    printf("tu te defends !\n");
    if((*defense).inventaire > 0){
    (*player).vie = (*player).vie - ((*ogre).attaque /2);
    (*defense).inventaire -=1;
    printf("ton bouclier se brise sous sa force!\n");
    if((*defense).inventaire < 0){
      (*defense).inventaire = 0;
    }
    }
    else if ((*defense).inventaire <=0){
      printf("tu n'as plus de quoi te défendre\n");
      (*player).vie = (*player).vie - (*ogre).attaque;
    }
  }

  printf("Il te reste %d vie !\n", (*player).vie);
    printf("Il lui reste %d\n", (*ogre).vie);

}




void defense_slime(combat * player, combat * slime, objet * attaque){

  if(decision_combat == 1){
    (*attaque).inventaire -=1;
    printf("L'ennemie gobe ton épee !\n");
    if((*attaque).inventaire < 0){
      (*attaque).inventaire =0;
    }
  }
  if(decision_combat == 2){
    printf("Tu te defends ! Et lui aussi !\n");
  }

  printf("Il te reste %d vie !\n", (*player).vie);
    printf("Il lui reste %d\n", (*slime).vie);
}

void attaque_slime(combat * slime, combat * player, objet * attaque, objet * defense){
  printf("L'ennemie attaque !\n");
  if(decision_combat == 1){
    printf("Tu attaque aussi !\n");
    if((*attaque).inventaire > 0){
      player->vie = player->vie - slime->attaque;
    (*slime).vie = (*slime).vie - (*player).attaque;
    }
    else if ((*attaque).inventaire <=0){
      player->vie = player->vie - slime->attaque;
    (*slime).vie = (*slime).vie - ((*player).attaque /2);
    }

  }
  if(decision_combat == 2){
    printf("tu te defends !\n");
    printf("l'ennemie attaque !\n");
    if((*defense).inventaire > 0){
    (*player).vie = (*player).vie - ((*slime).attaque /2);
    printf("ton bouclier a pleins de morve dessus tu l'abandonne car elle te degoute\n");
    (*defense).inventaire -=1;
    if((*defense).inventaire < 0){
      (*defense).inventaire = 0;
    }
    }
    else if((*defense).inventaire <=0){
      printf("tu ne peux pas te defendre vu que tu n'as plus rien\n");
      (*player).vie = (*player).vie - (*slime).attaque;
    }
  }

  printf("Il te reste %d vie !\n", (*player).vie);
    printf("Il lui reste %d\n", (*slime).vie);

}



int main(){


  lieu lieux[20];
  lieux[1].difficulte = 15;
  strcpy(lieux[1].nom, "plage");
  strcpy(lieux[1].desc, "tu arrive sur une magnifique plage pleins de poissons morts. Ici tu peux fouiller ! (ecrire fouiller)\n");
  strcpy(lieux[3].desc_2, "");
  lieux[1].tableau[1] = 2 ;
  lieux[1].tableau[2] = 3 ;

  lieux[2].difficulte = 19;
  strcpy(lieux[2].nom, "montagne");
  strcpy(lieux[2].desc, "tu arrive sur vers une montagne avec un cimetiere abandonne ! Ici tu peux combattre (ecrire combat)\n");
  strcpy(lieux[3].desc_2, "");
  lieux[2].tableau[1] = 1 ;
  lieux[2].tableau[2] = 3 ;

  lieux[3].difficulte = 3;
  strcpy(lieux[3].nom, "village");
  strcpy(lieux[3].desc, "tu arrive sur vers un village magnifique de riche. Ici tu peux acheter (ecrire shop)\n");
  strcpy(lieux[3].desc_2, "");
  lieux[3].tableau[1] = 2 ;
  lieux[3].tableau[2] = 1 ;


  objet tableau[109];
  tableau[0].classement = 1;
  strcpy(tableau[0].nom, "bouclier");
  srand(time(NULL));
  tableau[0].nombre = rand()%11+1;
  tableau[0].prix = 10;
  tableau[0].inventaire = 1;

  tableau[1].classement = 2;
  strcpy(tableau[1].nom, "epee");
  srand(time(NULL));
  tableau[1].nombre =rand()%10+1;
  tableau[1].prix = 40;
  tableau[1].inventaire = 1;

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
player.vie = 100;
  printf("tu as %d stamina ! \n", stamina);
  printf("t'es pv sont restauree");
}
else if (strcmp(decision,"repos") == 0 && lieux[save].difficulte > 5){
  printf("tu ne peux te reposer tu es en endroit hostile !\n");
}

scanf("%s", decision);

if(stamina <= 0){
  printf("tu es mort de fatigue !\n");
  return 0;
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
        defense_ogre(&player, &ogre, &tableau[1], &tableau[0]);
      }
      if(decision_ennemie_ogre == 2){
        attaque_ogre(&ogre, &player, &tableau[1], &tableau[0]);
      }
    }
    if(ogre.vie <= 0){
      printf("Il est mort\n");
      printf("Tu prends de la force et obtient de l'argent !");
      ogre.attaque += 10;
      slime.vie +=50;
      player.attaque += 20;
      piece += 40;
    }
    if(player.vie <= 0){
      printf("tu es mort\n");
      return 0;
    }
    printf("Ou veux-tu aller ?\n");
    printf("Tu peux aller : plage\n");
    printf("Tu peux aller : village\n");
    scanf("%s", decision);
    if(strcmp("montagne", decision)==0){
      printf("tu ne peux pas aller ici\n");
    }
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
        defense_slime(&player, &slime, &tableau[1]);
      }
      if(decision_ennemie_slime == 2){
        attaque_slime(&slime, &player, &tableau[1], &tableau[0]);
      }
    }
    if(slime.vie <= 0){
      printf("Il est mort\n");
      printf("Tu prends de la force et obtient de l'argent !");
      slime.attaque += 10;
      slime.vie +=30;
      player.attaque += 15;
      piece +=5;
    }
    if(player.vie <= 0){
      printf("tu es mort\n");
      return 0;
    }
    printf("Ou veux-tu aller ?\n");
    printf("Tu peux aller : plage\n");
    printf("Tu peux aller : village\n");
    scanf("%s", decision);
    if(strcmp("montagne", decision)==0){
      printf("tu ne peux pas aller ici\n");
    }
  }
}

if(strcmp(lieux[save].nom, "village") == 0 && strcmp("shop", decision) == 0){
  loop_2 = 1;
  while(loop_2 == 1){
    printf("Tu as : %d $ restant !\n", piece );
    printf("Que veux tu faire /1 inventaire /2 magasin /3 partir\n");
    scanf("%d", &demande );
  switch(demande){
    case 1:

    printf("Tu rentre dans l'inventaire\n");
    for(int i = 0; i <= 1; i++){
            printf("[%d] %s :  tu en as %d\n",tableau[i].classement, tableau[i].nom, tableau[i].inventaire);
          }

  break;
    case 2 :
    printf("tu rentre dans le shop\n");
    for(int i = 0; i <= 1; i++){
            printf("[%d] %s :  il en a %d  a %d $\n",tableau[i].classement, tableau[i].nom, tableau[i].nombre , tableau[i].prix );
          }

          printf("Tu veux quoi ?\n");
            scanf("%d", &demande_2);
            demande_2 -=1;
            printf("Tu en veux combien ?\n");
            scanf("%d", &nombre);
            if(nombre <= tableau[demande_2].nombre && piece > (tableau[demande_2].prix*nombre)){
              printf("tu choisi %s\n", tableau[demande_2].nom);
            tableau[demande_2].inventaire += nombre;
            tableau[demande_2].nombre -= nombre;
            piece -= tableau[demande_2].prix*nombre;
            printf("Tu as achete %d %s au prix de %d\n", nombre, tableau[demande_2].nom, (tableau[demande_2].prix*nombre) );
            }
            else if(piece < (tableau[demande_2].prix*nombre) ){
              printf("Tu n'as pas assez d'argent\n");
            }
            else if(nombre > tableau[demande_2].nombre){
              printf("Le vendeur n'a pas tout ca !\n");
            }


  break;
    case 3:

    printf("Tu pars !\n");
    loop_2 = 0;

  break;
  }
  }
  printf("Ou veux-tu aller ?\n");
  printf("Tu peux aller : plage\n");
  printf("Tu peux aller : montagne\n");
  scanf("%s", decision);
  if(strcmp(decision, "village")==0){
    printf("Tu ne peux pas faire ça\n");
  }
}


if(strcmp(lieux[save].nom, "plage") == 0 && strcmp("fouiller", decision) == 0){
  printf("tu fouille les lieux !");

srand(time(NULL));
      int aleanb=rand()%2+1;
      alea = aleanb;

      if(alea == 1){
        printf("Tu ne trouve que des poissons morts et tu te blesse\n");
        player.vie -=5;
      }
      else if(alea == 2){
        printf("tu trouve un corps\n");
        srand(time(NULL));
      int nbgen=rand()%2+1;
      int choix = nbgen;
      if(choix == 1){
        printf("tu trouve une epee\n");
        tableau[1].inventaire +=1;
      }
      else if(choix == 2){
        printf("tu trouve un bouclier\n");
        tableau[0].inventaire +=1;
      }
      }
      printf("tu ne peux plus fouiller ici pour le moment. ");
  printf("Ou veux-tu aller ?\n");
  printf("Tu peux aller : village\n");
  printf("Tu peux aller : montagne\n");
  scanf("%s", decision);
  if(strcmp(decision, "plage")==0){
    printf("Tu ne peux pas faire ça\n");
  }
  }

}

  return 0;
}
