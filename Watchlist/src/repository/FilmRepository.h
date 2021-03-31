#ifndef LABORATOR6_FILMREPOSITORY_H
#define LABORATOR6_FILMREPOSITORY_H
#include "../domain/Film.h"
#include <iostream>
#include <vector>
#include "../ValidClass/ValidationClass.h"
using namespace std;
class FilmRepository {
private:
    vector <Film> Filme;
public:

    explicit FilmRepository();
/*
     * Fuegt einen Film zu dem Repository ein
     * Titel - Titel des Films
     * Genre - Den Typ des Films zb. Thriller
     * Link - wo man den Trailer des Films ansehen kann
     * Jahr - Erscheinungsjahr des Films
     * Likes - Zahl von gegebenen Likes (Thumbs Up)
     */

    virtual void add_Film(string titel, string genre, string link, int jahr, int likes);
    /*
     * Fuegt ein Objekt vom Typ Film in dem Film Vektor ein
     */

    void delete_Film(string titel);
    /*
     * Entfernt ein Objekt vom Typ Film von dem Film Vektor
     * Es wird nach dem Titel identifiziert
     */

    Film search_Film(string titel);
    /*
     * Sucht ein Objekt vom Typ Film mit dem Titel titel in dem Medikamenten Vektor
     * return - Das Objekt wird zuruckgegeben
     */

    virtual vector <Film> get_all();
    /*
     * return - Filmvektor
     */
    void Anschreiben();
    /*
     * schreibt den Filmvektor an
     */

    void Bearbeiten(string titel, string genre, string link, int jahr, int likes);
    /*
     * Man kann hier das Genre, den Link und die Likes eines Films andern,
     */

    void Ansehen_Genre(string val);
};

#endif //LABORATOR5_FILMREPOSITORY_H
