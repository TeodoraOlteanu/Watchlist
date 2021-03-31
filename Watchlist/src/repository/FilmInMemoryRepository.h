#ifndef LABORATOR6_FILMINMEMORYREPOSITORY_H
#define LABORATOR6_FILMINMEMORYREPOSITORY_H

#include "../repository/FilmRepository.h"

class FilmInMemoryRepository: public FilmRepository {
private:
    vector<Film> filme;
public:
    FilmInMemoryRepository() : FilmRepository(){
        filme = {};
    }
    void add_Film(string titel, string genre, string link, int jahr, int likes) override {
        filme.emplace_back(titel, genre, link,jahr,likes);
    }
    vector<Film> get_all() override {
        return filme;
    }
};

#endif //LABORATOR6_FILMINMEMORYREPOSITORY_H
