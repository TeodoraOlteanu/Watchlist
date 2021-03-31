#include "Film.h"

Film::Film(){};

Film::Film(string titel, string genre, string link, int jahr, int likes)
{
    this->Titel=titel;
    this->Genre=genre;
    this->Link=link;
    this->Jahr=jahr;
    this->Likes=likes;
}

string Film::get_Titel() {
    return Titel;
}

string Film::get_Genre() {
    return Genre;
}

string Film::get_Link() {
    return Link;
}

int Film::get_Jahr() {
    return Jahr;
}

int Film::get_Likes(){
    return Likes;
}

void Film::set_Titel(string val) {
    Titel=val;
}

void Film::set_Genre(string val) {
    Genre=val;
}

void Film::set_Link(string val) {
    Link=val;
}

void Film::set_Jahr(int val) {
    Jahr=val;
}
void Film::set_Likes(int val) {
    Likes=val;
}

