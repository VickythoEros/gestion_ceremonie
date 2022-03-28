#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

    int f_menu_generale();
    int f_menu_principal_invite();
    void liste_plats(void);
    int f_menu_principal_gestionnaire();
    void f_show_reservation_info(int id_invite,int num_table,int num_siege,int plat,int ceremonie);
    void f_chronogramme(MYSQL *connexion,int id_ceremonie);
    int f_choix_chronogramme_reserver();
    int choix_gestionnaire_2();

#endif // HEADER_H_INCLUDED
