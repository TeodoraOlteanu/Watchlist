#include "FilmController.h"

FilmController::FilmController(){
    this->repository = new CSV(R"(E:\Clion_Projects\OOP\Laborator6\filme2.csv)");
}

void FilmController::add_Film(string titel, string genre, string link, int jahr, int likes)
{
    repository->add_Film(titel,genre,link,jahr,likes);
}

void FilmController::delete_Film(string val)
{
    repository->delete_Film(val);
}
Film FilmController::find_Film(string titel) {
    return repository->search_Film(titel);
}

void FilmController::Anschreiben()
{
    repository->Anschreiben();
}
vector <Film> FilmController::get_Filme()
{
   return repository->get_all();
}

void FilmController::Bearbeiten(string titel, string genre, string link, int jahr, int likes)
{
    repository->Bearbeiten(titel,genre,link,jahr,likes);
}
void FilmController::Ansehen_Genre(string val)
{
    repository->Ansehen_Genre(val);
}