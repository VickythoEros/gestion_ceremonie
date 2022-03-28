#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>

#include "header.h"
#include "invite.h"
#include "gestionnaire.h"





void voir_liste_reservation(MYSQL *connexion){
    system("cls");

    char requete[150];
    printf("        ======================================================================= \n");
    printf("                L  I  S  T  E       R  E  S  E  R  V  A  T  I  O  N  \n");
    printf("        ======================================================================= \n\n");
    printf("  \n");


    //Déclaration des pointeurs de structure
    MYSQL_RES *result = NULL;
    MYSQL_ROW row;
    unsigned int i = 0;
    unsigned int num_champs = 0;
    int j =1;

    sprintf(requete,"select * from reservation");
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

        f_show_reservation_info(row[4],row[1],row[2],row[3],row[5]);


        j++;

        }

        //Libération du jeu de résultat
        mysql_free_result(result);


}


void ajouter_ceremonie(MYSQL * connexion){
    system("cls");
    char nom_ceremonie[200];
    char requete[200];

    printf("        ======================================================================= \n");
    printf("            A  J  O  U  T  E  R      U  N  E      C  E  R  E  M  O  N  I  E   \n");
    printf("        ======================================================================= \n");
    printf("        Entrer le nom de la ceremonie : >>  ");
    scanf("%s",nom_ceremonie);

    sprintf(requete,"INSERT INTO ceremonie  VALUES('','%s')",nom_ceremonie);
    mysql_query(connexion,requete);

}



 void voir_liste_ceremonie(MYSQL *connexion){
    system("cls");

    //Déclaration des pointeurs de structure
    MYSQL_RES *result = NULL;
    MYSQL_ROW row;
    unsigned int i = 0;
    unsigned int num_champs = 0;
    int j =1;

    char requete[200];


    printf("        ===================================================================================== \n");
    printf("                        L  I  S  T  E       C  E  R  E  M  O  N  I  E \n");
    printf("        ===================================================================================== \n");

    sprintf(requete,"select * from ceremonie ");
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

       // f_show_reservation_info(row[4],row[1],row[2],row[3],row[5]);


        printf("     NON   : %s \n",row[1]);
       // printf("     Date  :%s   \n", row[1]);
        //printf("     Heure : %s   \n",row[2]);
        printf("            +++++  \n");
        j++;

        }

        //Libération du jeu de résultat
        mysql_free_result(result);


 }

