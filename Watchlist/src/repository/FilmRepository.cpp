#include "FilmRepository.h"
//#include <exception>

FilmRepository::FilmRepository()
{
    Filme = {};
}
void FilmRepository::add_Film(string titel, string genre, string link, int jahr, int likes) {
    ValidationClass v;
    for (auto i = Filme.begin(); i < Filme.end(); i++)
        if (i->get_Titel() == titel) {
            cout << "Der Film existiert schon!";
            break;
        }
    //wenn der Film nicht existiert, wird er eingefuegt
    if (v.check_string(titel) == false)
        throw invalid_argument("\nTitle is incorrect\n");
    if (v.check_string(genre) == false)
        throw invalid_argument("\nGenre is incorrect\n");
    if (v.check_number(jahr) == false)
        throw invalid_argument("\nYear is incorrect\n");
    if (v.check_number(likes) == false)
        throw invalid_argument("\nYear is incorrect\n");
    Filme.emplace_back(Film(titel, genre, link, jahr, likes));
}

void FilmRepository::delete_Film(string titel)
{
    int found=0;
    for(auto i=0;i<Filme.size();i++)
        if(titel == Filme[i].get_Titel())
        {
            Filme.erase(Filme.begin() + i);
            found=1;
        }
    //Der Film existiert nicht
    if(found==0)
        throw invalid_argument("Film existiert nicht");
}
Film FilmRepository::search_Film(string titel) {

    for(auto & i : Filme)
        if(i.get_Titel()==titel)
            return i;
    return Film("","","",0,0);
}

vector <Film> FilmRepository::get_all() {
    return Filme;
}

void FilmRepository::Anschreiben()
{
    for(auto i=Filme.begin();i<Filme.end();i++)
        cout<<i->get_Titel()<<" "<<i->get_Genre()<<" "<<i->get_Jahr()<<" "<<i->get_Likes()<<" " <<i->get_Link()<<"\n";
}

void FilmRepository::Bearbeiten(string titel, string genre, string link, int jahr, int likes)
{
    int found = 0;
    for (auto &i : Filme)
        if (i.get_Titel() == titel) {
            i.set_Genre(genre);
            i.set_Link(link);
            i.set_Likes(likes);
            found = 1;
        }
    if(found == 0)
        throw invalid_argument("Film existiert nicht");
}

void FilmRepository::Ansehen_Genre(string val)
{
    for(auto i=Filme.begin();i<Filme.end();i++)
        if(i->get_Genre()==val)
            cout<<i->get_Titel()<<" "<<i->get_Genre()<<" "<<i->get_Jahr()<<" "<<i->get_Likes()<<" " <<i->get_Link()<<"\n";
}