#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>

#include "header.h"
#include "invite.h"
#include "gestionnaire.h"





int f_menu_generale(){
    system("cls");
    int choix_menu_general;

    printf("        ======================================================================= \n");
    printf("                        M  E  N  U       G  E  N  E  R  A  L  \n");
    printf("        ======================================================================= \n");
    printf("                1 - INVITE \n");
    printf("                2 - GESTIONNAIRE \n");
    printf("                3 - QUITTER \n");
    printf("        Entrer votre choix : >>  ");
    scanf("%d",&choix_menu_general);

    return choix_menu_general;
}


int f_menu_principal_invite(){
    system("cls");
    int choix_menu_principal_invite;

    printf("        ======================================================================= \n");
    printf("                        M  E  N  U       I  N  V  I  T  E  \n");
    printf("        ======================================================================= \n");
    printf("                1 - S'ENREGISTER \n");
    printf("                2 - RESERVER \n");
    printf("                3 - LISTE DE SA RESERVATION \n");
    printf("                4 - REVENIR AU MENU PRINCIPAL \n");
    printf("                5 - QUITTER \n");
    printf("        Entrer votre choix : >>  ");
    scanf("%d",&choix_menu_principal_invite);

    return choix_menu_principal_invite;
}

int f_choix_type_ceremonie(){
    system("cls");
    int choix;

    printf("\n                      CHOISISSER LE TYPE DE CEREMONIE  \n");
    printf("        ======================================================================= \n");
    printf("                1 - MARIAGE \n");
    printf("                2 - RESTAURATION \n");
    printf("                3 - QUITTER \n");
    printf("        Entrer votre choix : >>  ");
    scanf("%d",&choix);

    return choix;
}

 void liste_plats(void){
    printf("        1 - poulets saute \n");
    printf("        2 - frittes aux sallades \n");
    printf("        3 - poissons avec de l'attieké \n");
    printf("        4 - boeuf a l'algerien  \n");
 }



 void f_chronogramme(MYSQL *connexion,int id_ceremonie){
    system("cls");

    //Déclaration des pointeurs de structure
    MYSQL_RES *result = NULL;
    MYSQL_ROW row;
    unsigned int i = 0;
    unsigned int num_champs = 0;
    int j =1;

    char requete[200];


    printf("        ===================================================================================== \n");
    printf("        C  H  R  O  N  O  G  R  A  M  M  E     D  E     L  A    C  E  R  E  M  O  N  I  E \n");
    printf("        ===================================================================================== \n");


    sprintf(requete,"select * from chronogramme where chronogramme.idceremonie = '%d' ",id_ceremonie);
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


        printf("     NON   : %s \n",row[3]);
        printf("     Date  :%s   \n", row[1]);
        printf("     Heure : %s   \n",row[2]);
        printf("            +++++  \n");
        j++;

        }

        //Libération du jeu de résultat
        mysql_free_result(result);


 }

 int f_choix_chronogramme_reserver(){
    system("cls");
    int choix;

    printf("        ======================================================================= \n");
    printf("                    M  E  N  U     C  E  R  E  M  O  N  I  E  \n");
    printf("        ======================================================================= \n");
    printf("                1 - RESERVER \n");
    printf("                2 - VOIR  LE CHRONOGRAMME  \n");
    printf("                3 - RETOURNER  \n");
    printf("        Entrer votre choix : >>  ");
    scanf("%d",&choix);

    return choix;
 }

int f_menu_principal_gestionnaire(){
    system("cls");
    int choix_menu_principal_gestionnaire;

    printf("        ======================================================================= \n");
    printf("                M  E  N  U       G  E  S  T  I  O  N  N  A  I  R  E  \n");
    printf("        ======================================================================= \n");
    printf("                1 - VOIR LISTE RESERVATION \n");
    printf("                2 - QUITTER \n");
    printf("        Entrer votre choix : >>  ");
    scanf("%d",&choix_menu_principal_gestionnaire);

    return choix_menu_principal_gestionnaire;
}

void f_show_reservation_info(int id_invite,int num_table,int num_siege,int plat,int ceremonie){
    char char_plat[10];
    char char_ceremonie[10];

    strcpy(char_plat,plat);
    strcpy(char_ceremonie,ceremonie);
    printf("\n");
    printf("        identifiant invite : %s \n",id_invite);
    printf("        numero de la table : %s \n",num_table);
    printf("        numero de la siege : %s \n",num_siege);
    printf("        le plat : ");
    switch(atoi(char_plat)){
        case 1 :printf("            poulets saute \n"); break;
        case 2 :printf("            frittes aux sallades \n");break;
        case 3 :printf("            poissons avec de l'attieké \n");break;
        case 4 :printf("            boeuf a l'algerien  \n");break;
        default: break;
    }

    printf("        le nom de la ceremonie : ");
    switch(atoi(char_ceremonie)){
        case 1 :printf("            MARIAGE \n"); break;
        case 2 :printf("            RESTAURATION \n");break;
        default: break;
    }

    printf("        ======================================================================= \n");

}


int choix_gestionnaire_2(){
    system("cls");
    int choix;
    printf("        ======================================================================= \n");
    printf("                    M  E  N  U        G  E  S  T  I  O  N  N  A  I  R  E  \n");
    printf("        ======================================================================= \n");
    printf("        1 - AJOUTER UNE CEREMONIE \n");
    printf("        2 - VOIR LA LISTE DES CEREMONIES \n");
    printf("        3 - VOIR LA LISTE DES RESERVATIONS \n");
    printf("        4 - RETOURNER \n");
    printf("        5 - QUITTER \n");
    printf("        Entrer votre choix : >>  ");
    scanf("%d",&choix);

    return choix;
}

