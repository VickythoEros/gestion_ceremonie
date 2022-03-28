/**
 * \file main.c
 * \brief programme de gestion de menu de la ceremonie.
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
 * \fn int main (void)
 * \brief Entrée du programme.
 *
 * \return 0 - Arrêt normal du programme.
 */
int main()
{
    int liste_commandes[100] ;

    int choix ;
    int *id_invite;

    MYSQL* connexion;

    connexion = mysql_init(NULL);
    if(mysql_real_connect(connexion,"localhost","root","","ceremonies",0,NULL,0) != 0){
        //printf("connexion etablie avec succes");


        menuprincipal : choix = f_menu_generale();

             switch(choix){
                case 1 :{
                    int choix_m_invite;
                   choixMenuInvite: choix_m_invite = f_menu_principal_invite();

                    switch(choix_m_invite){
                        case 1 :{
                            f_menu_enregister_invite(connexion,id_invite);
                            system("pause");
                            goto choixMenuInvite;

                        };break;
                        case 2 :{
                            int choix_type_ceremonie;
                            int choix_menu_chrono_reserve;

                            choix_type_ceremonie = f_choix_type_ceremonie();
                           menuchoixchronoreserve: choix_menu_chrono_reserve = f_choix_chronogramme_reserver();

                            switch(choix_menu_chrono_reserve){
                                case 1: {
                                    f_menu_reservation(connexion,choix_type_ceremonie);
                                    f_chronogramme(connexion,choix_type_ceremonie);

                                    system("pause");
                                    goto menuchoixchronoreserve;
                                };break;
                                case 2: {
                                    f_chronogramme(connexion,choix_type_ceremonie);
                                    system("pause");
                                    goto menuchoixchronoreserve;
                                };break;
                                case 3: goto choixMenuInvite;break;
                                default: goto menuchoixchronoreserve;break;
                            }




                            system("pause");
                            goto choixMenuInvite;

                        };break;

                        case 3 :{
                            voir_reservation_inviter(connexion);
                            system("pause");
                            goto choixMenuInvite;

                        };break;

                        case 4 :{
                            goto menuprincipal;

                        };break;

                        case 5 :{
                            exit(1);

                        };break;
                        default: goto choixMenuInvite;break;
                        }

                } ; break;

                case 2 :{
                    int choix_m_gestion;
                    menu_m_gestion : choix_m_gestion = choix_gestionnaire_2();

                    switch(choix_m_gestion){
                        case 1 :{
                            ajouter_ceremonie(connexion);
                            system("pause");
                            goto menu_m_gestion;

                        };break;

                         case 2 :{
                            voir_liste_ceremonie(connexion);
                            system("pause");
                            goto menu_m_gestion;

                        };break;

                         case 3 :{
                            voir_liste_reservation(connexion);
                            system("pause");
                            goto menu_m_gestion;

                        };break;

                         case 4 :goto menuprincipal;break;
                         case 5 :exit(1);break;
                    }

                }; break;
                case 3 : exit(1); break;
                default: {
                    printf("!!!! CHOIX INCORRECT ... choisir entre 1 et 3 \n");
                }; break;

              }



    }



    mysql_close(connexion);

    return 0;
}
