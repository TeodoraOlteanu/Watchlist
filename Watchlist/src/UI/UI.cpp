#include "UI.h"
//#include <fstream>
#include <iostream>
//#include <exception>
#include <string>
#include "../../HTML.h"
#include "../../CSV.h"
#include <windows.h>
#include <shellapi.h>
//#include <ntgdi.h>
using namespace std;
UI::UI() {

    Watchliste = {};

    try {
        this->controller = new FilmController();
    } catch (FileNotFoundException &e) {
        cout << e.what() << endl;
        throw;
    }
}

void UI::show_menu_Administrator(){
    cout<<"\n1. Neuer Film einfuegen\n2. Film loschen\n3. Film bearbeiten\n4. Alle Filme anschreiben\n0. Exit";
}

void UI::show_menu_Benutzer(){
    cout<<"\n1. Ansehen nach dem Genre\n2. Film loeschen\n3. Wachtliste ansehen\n0. Exit";
}

void UI::add_Film(){

    string titel, genre, link;
    int jahr, likes;
    cout<<"Titel einfuegen: "; cin>>titel;
    cout<<"Genre einfuegen: "; cin>>genre;
    cout<<"Link einfuegen: "; cin>>link;
    cout<<"Jahr einfuegen: "; cin>>jahr;

    cout<<"Zahl von Likes: "; cin>>likes;


    controller->add_Film(titel,genre,link,jahr,likes);
}

void UI::add_zu_Watchliste(string titel, string genre, string link, int jahr, int likes)
{
    Watchliste.emplace_back(Film(titel,genre,link,jahr,likes));
}

void UI::lista_existenta()
{
    /*string titel, link, genre;
    int likes, jahr;

    ifstream fin (R"(E:\Clion_Projects\OOP\Laborator6\file.txt)");
    if (!fin.is_open())
        cout<<"Could not open text file";
    else
        while (fin>>titel>>genre>>link>>jahr>>likes)
        {
            controller.add_Film(titel,genre,link,jahr,likes);
        }
    fin.close();*/
}

void UI::Anschreiben()
{
    vector <Film> vec;
    vec = controller->get_Filme();
    for(auto i=vec.begin();i<vec.end();i++)
        cout<<i->get_Titel()<<" "<<i->get_Genre()<<" "<<i->get_Jahr()<<" "<<i->get_Likes()<<" " <<i->get_Link()<<"\n";
}
void UI::Anschreiben_Watchliste()
{
    for(auto i=Watchliste.begin();i<Watchliste.end();i++)
        cout<<i->get_Titel()<<" "<<i->get_Genre()<<" "<<i->get_Jahr()<<" "<<i->get_Likes()<<" " <<i->get_Link()<<"\n";
}

void UI::Loschen()
{
    string titel;
    cout<<"Titel des Films eingeben, der geloscht sein soll: "; cin>>titel;
    controller->delete_Film(titel);
}

void UI::Loschen_Watchliste(string val)
{
    for(auto i=0;i<Watchliste.size();i++)
        if(val == Watchliste[i].get_Titel())
            Watchliste.erase(Watchliste.begin() + i);
}

void UI::Bearbeiten()
{
    string titel, genre, link;
    int likes;
    cout<<"Titel einfuegen: ";
    cin>>titel;
    cout<<"neues Genre einfuegen: ";
    cin>>genre;
    cout<<"neuer Link einfuegen: ";
    cin>>link;
    cout<<"neue Zahl von Likes: ";
    cin>>likes;

    controller->Bearbeiten(titel,genre,link,0,likes);
}

void UI::startUI() {
    int input = -1, type_access;

    lista_existenta();
    cout<<"1 eintippen fuer Administrator; 2 eintippen fuer Benutzer\n Antwort: "; cin>>type_access;

    //Administrator
    if(type_access==1) {

        while (input != 0) {
            show_menu_Administrator();
            cout << "\nGeben Sie den Input ein: ";
            cin >> input;
            switch (input) {
                case 1: {
                    add_Film();
                    break;
                }
                case 2: {
                    Loschen();
                    break;
                }
                case 3: {
                    Bearbeiten();
                    break;
                }
                case 4: {
                    Anschreiben();
                    break;
                }
                default:
                    break;
            }
        }
    }
    else
        if(type_access==2) {//Benutzer

            int mod;
            cout << "1 eintippen fuer CSV\n2 eintippen fuer HTML\n";
            cin >> mod;
            while (input != 0) {
                show_menu_Benutzer();
                cout << "\nGeben Sie den Input ein: ";
                cin >> input;
                vector <Film> vec;
                vec = controller->get_Filme();
                auto j=vec.begin();
                switch(input){
                    case 1:
                    {
                        int ct=0;
                        string genre;
                        cout<<"Geben Sie das Genre an: "; cin>>genre;
                         if(genre!="*")
                             controller->Ansehen_Genre(genre);
                         else {
                             for(j=vec.begin();j<vec.end() && ct<vec.size();j++)
                             {
                                 cout << "Film: " << j->get_Titel() << " " << j->get_Genre() << " " << j->get_Jahr()
                                      << " " << j->get_Likes() << " " << j->get_Link() << "\n";
                                 system(("start " + j->get_Link()).c_str());

                                 int antwort;
                                 cout << "\nHat Ihnen den Film gefallen?\n1-Ja  0-Nein";
                                 cout << "\nAnwort: ";
                                 cin >> antwort;
                                 if (antwort == 1) {
                                     add_zu_Watchliste(j->get_Titel(), j->get_Genre(), j->get_Link(), j->get_Jahr(),
                                                       j->get_Likes());
                                     cout<<"Film zu der Watchliste aingefuegt!";
                                 }
                                 cout<<"\nWollen Sie weitergehen oder jetzt stoppen? 0-stoppen, 1-weitergehen";
                                 cout << "\nAnwort: ";
                                 cin >> antwort;
                                 if (antwort == 0)
                                     break;
                                 ct++;
                             }
                         }
                         break;
                    }
                    case 2:
                    {
                        //Loschen
                        for(j=vec.begin();j<vec.end();j++) {
                            int antwort, aux;
                            cout << "Film: " << j->get_Titel() << " " << j->get_Genre() << " " << j->get_Jahr()
                                 << " " << j->get_Likes() << " " << j->get_Link() << "\n";
                            cout << "Wollen Sie diesen Film loeschen?\n1-Ja  0-Nein";
                            cout << "Anwort: ";
                            cin >> antwort;
                            if (antwort == 1)
                            {
                                cout << "Hat es Ihnen den Film gefallen?\n1-Ja  0-Nein";
                                cout << "Anwort: ";
                                cin >> antwort;
                                if (antwort == 1) {
                                    cout << "Wollen Sie einen Like dem Film geben?\n1-Ja  0-Nein";
                                    cout << "Anwort: ";
                                    cin >> antwort;
                                    if (antwort == 1) {
                                        aux = j->get_Likes();//Anzahl der Likes des Films in Repo
                                        aux++;
                                        j->set_Likes(aux);
                                    }
                            }
                                Loschen_Watchliste(j->get_Titel());
                                cout << "Der Film wurde aus der Watchliste geloscht!";
                                break;
                            }
                        }
                        break;
                    }
                    case 3: {
                        Anschreiben_Watchliste();
                       switch (mod)
                        {
                            case 1:
                            {
                                //if ((int)ShellExecute( NULL, "open", "E:\\Clion_Projects\\OOP\\Laborator6\\filme2.csv", NULL, NULL, SW_SHOWNORMAL ) <= 32)
                                    ///fooey();
                                //system(R"(E:\Clion_Projects\OOP\Laborator6\filme2.csv)");
                                string Command = R"(E:\Clion_Projects\OOP\Laborator6\filme2.csv)";
                                //int rc = system( Command.c_str() );
                                system(( Command.c_str()));
                                break;
                            }
                            case 2:
                            {
                                vector <Film> vec = Watchliste;
                                HTML html( R"(E:\Clion_Projects\OOP\Laborator6\filme1.html)");
                                html.print(vec);

                                LPCTSTR helpFile = R"(E:\Clion_Projects\OOP\Laborator6\filme1.html)";
                                ShellExecute(NULL, "open", helpFile, NULL, NULL, SW_SHOWNORMAL);
                                system("PAUSE");
                                break;
                            }
                        }
                        break;
                        }
                    //}
                }
            }
        }
}

