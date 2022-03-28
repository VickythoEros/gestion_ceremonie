/**
 * \file controllers.c
 * \brief fichier permettant de stocker les differentes fonctions utilées lors de l'execution du programme.
 * \author kone vakaramoko
 * \version 0.1
 * \date 15 mars 20223
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>

#include "header.h"
#include "invite.h"
#include "gestionnaire.h"



/**
 * \fn int menu_principal(void)
 * \brief la fonction menu_principale permet d'afficher le menu principal de l'application.
 *
 * \param aucun parametre.
 * \return retourne rien.
 */
 int menu_principal(void){

    //system("cls");
    int choix;

    printf(" ++++++++++++++++++++++++                                      ++++++++++++++++++++++++++ \n");
    printf(" ++++++++++++++++++++++++   MENU DE GESTION DE LA CEREMONIE    ++++++++++++++++++++++++++ \n");
    printf(" ++++++++++++++++++++++++                                      ++++++++++++++++++++++++++ \n\n");
    printf("            1 -   PRENDDRE UNE COMMANDE \n");
    printf("            2 -   VOIR LA LISTE DES COMMANDES  \n");
    printf("            3 -   VOIR LE CHRONOGRAMME DE LA CEREMONIE  \n");
    printf("            4 -   QUITTER  \n\n");
    printf(" ENTRER VOTRE CHOIX : >  ");
    scanf("%d",&choix);
    return choix;

 }


/**
 * \fn void liste_plats(void)
 * \brief la fonction liste_plats permet d'afficher la liste des plats.
 *
 * \param aucun parametre.
 * \return retourne rien.
 */



 /**
 * \fn void prendre_demande(void)
 * \brief la fonction prendre_demande permet de prendre les commandes.
 *
 * \param aucun parametre.
 * \return retourne rien.
 */
 void prendre_demande(MYSQL* connexion){
    char numero_table[10];
    char numero_siege[10];
    //int numero_invite;
    //char[] commandes;
    int plats ;

    MYSQL_RES *resultat = NULL;
    MYSQL_ROW row;
    unsigned int nombre_champs = 0;
    char requete[400];

    printf("        PRISE DE COMMANDE   \n\n");
    printf("     --  Entrer le numero de la table : > ");
    scanf("%s",&numero_table);
    printf("\n");

    printf("     --  Entrer le numero du siege : > ");
    scanf("%s",&numero_siege);

    //printf("\n");
    //printf("     --  Entrer le numero de l'invite : > ");
    //scanf("%d",&numero_invite);

    printf("\n");
    printf("     ====== CHOISIR LE PLAT ====== \n\n");
    liste_plats();

    printf("\n     --  Entrer le numero du plat : > ");
    scanf("%d",&plats);

    sprintf(requete,"select * from invite where num_table= %s and num_siege=%s ",&numero_table,&numero_siege);
    mysql_query(connexion,requete);
    resultat = mysql_store_result(connexion);
    nombre_champs = mysql_num_rows(resultat);

    printf("%d",nombre_champs);

    printf("\n");
    printf("  \n\n");

 }


/**
 * \fn void voir_liste_commande(void)
 * \brief la fonction voir_liste_commande permet de voir la liste des commandes.
 *
 * \param aucun parametre.
 * \return retourne rien.
 */
void voir_liste_commande(void){


}


void chronogramme(void){

    printf("\n\n      CHORNOGRAMME DE LA CEREMONIE   \n\n");
    printf("   1 -   Accueil des invites (08h00)  \n");
    printf("   2 -   Installation des invites (09h 00)   \n");
    printf("   3 -   Debut de la ceremonie (10h00)   \n");
    printf("   4 -   Dejeuner (14h00)   \n");

}


