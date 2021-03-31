#ifndef LABORATOR6_UI_H
#define LABORATOR6_UI_H
#include "../Controller/FilmController.h"
#include <iostream>
#include <vector>
using namespace std;
class UI {

private:
    FilmController *controller;
    vector <Film> Watchliste;

    static void show_menu_Administrator();
    static void show_menu_Benutzer();
    void add_Film();
    void add_zu_Watchliste(string titel, string genre, string link, int jahr, int likes);
    void Loschen();//Loscht einen Element
    void Loschen_Watchliste(string val);
    void Bearbeiten();
    void Anschreiben();//Schreibt das Medikamenten Vektor an
    void Anschreiben_Watchliste();
    void lista_existenta();
public:
    UI(); //Konstruktor
    /*
     * Starts the UI with menu
     */
    void startUI();
};
#endif //LABORATOR5_UI_H
