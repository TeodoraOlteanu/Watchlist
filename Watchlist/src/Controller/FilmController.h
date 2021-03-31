#ifndef LABORATOR6_FILMCONTROLLER_H
#define LABORATOR6_FILMCONTROLLER_H
#include "../repository/FilmRepository.h"
#include "../../CSV.h"
#include "../repository/FilmInMemoryRepository.h"

class FilmController {

private:
    FilmRepository *repository;
public:
    /*
     * Konstruktor
     * repository - eine Instanz von FilmRepository
     */
    explicit FilmController();
    /*
       * Fuegt einen Film zu dem Repository ein
       * Titel - Titel des Films
       * Genre - Den Typ des Films zb. Thriller
       * Link - wo man den Trailer des Films ansehen kann
       * Jahr - Erscheinungsjahr des Films
       * Likes - Zahl von gegebenen Likes (Thumbs Up)
       */

    // Alle Funktionen benutzen die Funktionen von Repository
    void add_Film(string titel, string genre, string link, int jahr, int likes);

    void delete_Film(string val);

    Film find_Film(string titel);

    void Anschreiben();

    vector <Film> get_Filme();

    void Bearbeiten(string titel, string genre, string link, int jahr, int likes);

    void Ansehen_Genre(string val);

};
#endif //LABORATOR5_FILMCONTROLLER_H
