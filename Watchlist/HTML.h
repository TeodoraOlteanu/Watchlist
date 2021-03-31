#ifndef LABORATOR6_HTML_H
#define LABORATOR6_HTML_H
#include "src/repository/FilmRepository.h"
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

class HTML{
private:
    string filename;
public:
    explicit HTML(string name)
    {
        ofstream fout(name);
        if (!fout.is_open()) {
            throw;
        }
        fout.close();
        filename = name;
    }

    void print(vector <Film> vect)
    {
        ofstream fout(filename);
        fout << "<!DOCTYPE html>\n" << "<html lang=\"en\" dir=\"ltr\">\n<head>\n";
        fout << "\t<meta charset=\"utf - 8\">\n";
        fout << "\t<meta name=\"viewport\" content=\"width = device - width, initial - scale = 1.0\" />\n";
        fout << "\t<meta http-equiv=\"refresh\" content=\"30\" />\n";
        fout << "\t<link rel=\"stylesheet\" href=\"style.css\">\n";
        fout << "\t<title>Watchliste</title>\n</head>\n<body>\n";
        fout << "\t<div class=\"table\">\n\t\t<table>\n\t\t\t<thead>\n\t\t\t\t<tr>\n";
        fout << "\t\t\t\t\t<th>Title</th>\n";
        fout << "\t\t\t\t\t<th>Genre</th>\n";
        fout << "\t\t\t\t\t<th>Release year</th>\n";
        fout << "\t\t\t\t\t<th>Likes</th>\n";
        fout << "\t\t\t\t\t<th>Trailer</th>\n\t\t\t\t</tr>\n\t\t\t</thead>\n\t\t\t<tbody>\n";
        for (Film p :vect)
        {
            fout << "\t\t\t\t<tr>\n";
            fout << "\t\t\t\t\t<td>" << p.get_Titel() << "</td>\n";
            fout << "\t\t\t\t\t<td>" << p.get_Genre() << "</td>\n";
            fout << "\t\t\t\t\t<td><a href=\"" << p.get_Link() << "\" target=\"_blank\">" << p.get_Link() << "</a></td>\n\t\t\t\t</tr>\n";
            fout << "\t\t\t\t\t<td>" << p.get_Jahr() << "</td>\n";
            fout << "\t\t\t\t\t<td>" << p.get_Likes() << "</td>\n";

        }
        fout << "\t\t\t</tbody>\n\t\t</table>\n\t</div>\n</body>\n</html>";
        fout.close();
    }

};

#endif //LABORATOR6_HTML_H
