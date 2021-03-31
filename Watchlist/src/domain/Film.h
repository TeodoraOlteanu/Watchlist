#include <iostream>
#ifndef LABORATOR6_FILM_H
#define LABORATOR6_FILM_H
using namespace std;

class Film {

private:
    string Titel;
    string Genre;
    string Link;
    int Jahr;
    int Likes;

public:
    //Konstruktor
    Film(string titel, string genre, string link, int jahr, int likes);
    Film();

    //Getters
    string get_Titel();//Gibt den Titel zuruck
    string get_Genre();//gibt das Genre zuruck
    string get_Link();//gibt den Link zuruck
    int get_Jahr();//gibt den Jahr zuruck
    int get_Likes();//gibt die Likes zuruck

    //Setters
    void set_Titel(string val);//Gibt dem Titel einen Wert
    void set_Genre(string val);//gibt dem Genre einen Wert
    void set_Link(string val);//gibt dem Link einen Wert
    void set_Jahr(int val);//gibt dem Jahr einen Wert
    void set_Likes(int val);//gibt der Likes einen Wert
};

#endif //LABORATOR5_FILM_H
