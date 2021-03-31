#ifndef LABORATOR6_CSV_H
#define LABORATOR6_CSV_H

#include "src/repository/FilmRepository.h"
#include "src/domain/Film.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <exception>
//#include <winuser.h>
//#include <shellapi.h>
#include <sstream>
#include "FileNotFoundException.cpp"

using namespace std;

/*class CSV : public FilmRepository
{
public:
    void Print(const vector<Film>& v)
    {
            Scrie in fisierul de tip ".csv"
            v = vector cu obiecte de tip "Film"

            std::ofstream fout("filme2.csv", std::ios_base::out);
            if (!fout.is_open())
                cout<<"Could not open File";
            for (Film p : v)
                fout << p.get_Titel() << ", " << p.get_Genre() << ", " << p.get_Link() << ", " << p.get_Jahr() << ", " << p.get_Likes() << '\n';
            fout.close();
    }

    void Open()
    {
            Deschide fisierul de tip ".csv"

        if (32 >= (int)ShellExecute(NULL, "open", "watchliste.csv", NULL, NULL, SW_SHOWNORMAL))
            throw "Linkul nu poate fi deschis\n";
    }
};*/
class CSV : public FilmRepository {
private:
    string fileName;

    //splits each line of the file and return a movie
    static Film split(const string &line, char delimiter) {
        string buffer;
        string result[5];
        int size = 0;
        for (char c : line) {
            if (c != delimiter) {
                buffer += c;
            } else if (!buffer.empty()) {
                result[size++] = buffer;
                buffer = "";
            }
        }
        if (!buffer.empty()) {
            result[size++] = buffer;
        }
        stringstream jahrString(result[3]);
        int jahr = 0;
        jahrString >> jahr;
        stringstream likesString(result[4]);
        int likes = 0;
        likesString >> likes;
        return Film(result[0], result[1], result[2], jahr, likes);
    }

public:
    explicit CSV(const string &fileName) : FilmRepository() {
        ifstream file(fileName);
        //fstream file(this->fileName);
        //file.open(fileName, ios::in);
        if (!file.is_open()) {
            throw FileNotFoundException(fileName);
        }
        file.close();
        this->fileName = fileName;
    }

    void add_Film(string titel, string genre, string link, int jahr, int likes) override {
        ofstream file (this->fileName, std::ios_base::app);
        file << '\n' << titel << ',' << genre << ',' << link << ',' << jahr << ',' << likes;
        file.close();
    }
    vector<Film> get_all() override {
        ifstream file(this->fileName);
        vector<Film> filme = {};
        string line;
        if (!file.is_open()) {
            return filme;
        }
        while(getline(file, line)) {
            Film film = split(line, ',');
            filme.emplace_back(film);
        }
        file.close();
        return filme;
    }
};
#endif //LABORATOR6_CSV_H
