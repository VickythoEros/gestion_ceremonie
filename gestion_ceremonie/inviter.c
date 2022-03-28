#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>

#include "header.h"
#include "invite.h"
#include "gestionnaire.h"



void f_menu_enregister_invite(MYSQL *connexion,int *id_invite){
    system("cls");

    char nom[50];
    char prenom[100];
    char numero[20];

    char requete[150];
    char requete2[150];

    MYSQL_RES *resultat = NULL;

    printf("        ======================================================================= \n");
    printf("          E  N  R  E  G  I  S  T  R  E  M  E  N  T        I  N  V  I  T  E  \n");
    printf("        ======================================================================= \n");

    printf("         --  Entrer votre nom : > ");
    scanf("%s",nom);
    printf("\n");

    printf("        --  Entrer votre prenom : > ");
    scanf("%s",prenom);
    printf("\n");

    printf("        --  Entrer votre numero : > ");
    scanf("%s",numero);
    printf("\n");


    sprintf(requete2,"INSERT INTO invite VALUES('','%s','%s','%s')",nom,prenom,numero);
    mysql_query(connexion,requete2);


                    //Déclaration des pointeurs de structure
    MYSQL_RES *result = NULL;
    MYSQL_ROW row;
    unsigned int i = 0;
    unsigned int num_champs = 0;
    int j =0;

    sprintf(requete,"select * from invite where invite.numero = '%s'",numero);
    mysql_query(connexion,requete);

    //On met le jeu de résultat dans le pointeur result
    result = mysql_use_result(connexion);

    //On récupère le nombre de champs
    num_champs = mysql_num_fields(result);

    //on stock les valeurs de la ligne choisie
    while ((row = mysql_fetch_row(result))){

        //On déclare un pointeur long non signé pour y stocker la taille des valeurs
        unsigned long *lengths;

        //On stocke ces tailles dans le pointeur
        lengths = mysql_fetch_lengths(result);
        system("clear");
        printf("\n\n        ==================================================================\n");
        printf("           ||  V  O  T  R  E      I  D  E  N  T  I  F  I  A  N  T : %s       ||\n",row[0]);
        printf("\n\n        ==================================================================\n\n");
        //On affiche la position du joueur
        //printf("%ld- ", j);

        //On fait une boucle pour avoir la valeur de chaque champs
        //for(i = 1; i < num_champs; i++){

            //On ecrit toutes les valeurs
            //printf("%.*s ", (int) lengths[i], row[i] ? row[i] : "NULL");
        //}


        //On incrémente la position du joueur
        //j++;

        }

        //Libération du jeu de résultat
        mysql_free_result(result);

}


void f_menu_reservation(MYSQL *connexion,int id_ceremonie){
    system("cls");

    int numero_table;
    int numero_siege;
    int plat;
    int id_invite;
    char requete[150];
    //MYSQL_RES *resultat = NULL;

    printf("        ======================================================================= \n");
    printf("                        R  E  S  E  R  V  A  T  I  O  N  \n");
    printf("        ======================================================================= \n");

    printf("        --  Entrer votre identifiant : > ");
    scanf("%d",&id_invite);
    printf("\n");

    printf("        --  Entrer le numero de la table : > ");
    scanf("%d",&numero_table);
    printf("\n");

    printf("        --  Entrer le numero du siege : > ");
    scanf("%d",&numero_siege);
    printf("\n");

    printf("        ====== CHOISIR LE PLAT ====== \n");
    liste_plats();

    printf("\n      --  Entrer le numero du plat : > ");
    scanf("%d",&plat);


    sprintf(requete,"INSERT INTO reservation  VALUES('','%d','%d','%d','%d','%d')",numero_table,numero_siege,plat,id_invite,id_ceremonie);
    mysql_query(connexion,requete);
    //resultat = mysql_store_result(connexion);
    //d_invite = mysql_num_rows(resultat) + 1;

    //sprintf(requete2,"INSERT INTO invite VALUES('','%s','%s','%s')",nom,prenom,numero);
    //mysql_query(connexion,requete2);


}


void voir_reservation_inviter(MYSQL *connexion){

    system("cls");
    int id_invite;
    char requete[150];
    //MYSQL_RES *resultat = NULL;

    printf("        ======================================================================= \n");
    printf("         L  I  S  T  E     D  E      V  O  S    R  E  S  E  R  V  A  T  I  O  N  \n");
    printf("        ======================================================================= \n");

    printf("        --  Entrer votre identifiant : > ");
    scanf("%d",&id_invite);
    printf("\n");

    //Déclaration des pointeurs de structure
    MYSQL_RES *result = NULL;
    MYSQL_ROW row;
    unsigned int i = 0;
    unsigned int num_champs = 0;
    int j =1;

    sprintf(requete,"SELECT * FROM reservation WHERE reservation.idinvite =  '%d'",id_invite);
    mysql_query(connexion,requete);

    //On met le jeu de résultat dans le pointeur result
    result = mysql_use_result(connexion);

    //On récupère le nombre de champs
    num_champs = mysql_num_fields(result);

    //on stock les valeurs de la ligne choisie
    while ((row = mysql_fetch_row(result))){

        f_show_reservation_info(row[4],row[1],row[2],row[3],row[5]);
            //On incrémente la position du joueur
        j++;

        }


}


