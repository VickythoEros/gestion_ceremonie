#ifndef INVITE_H_INCLUDED
#define INVITE_H_INCLUDED

    void f_menu_enregister_invite(MYSQL *connexion,int *id_invite);
    void f_menu_reservation(MYSQL *connexion,int id_ceremonie);
    void voir_reservation_inviter(MYSQL *connexion);

#endif // INVITE_H_INCLUDED
