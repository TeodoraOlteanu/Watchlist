#include "../src/Controller/FilmController.h"
#include "gtest/gtest.h"

//Die Liste der Filme wie in UI fuer Validieren

vector <Film> create(FilmController controller) {
    controller.add_Film("Joker", "Thriller", "https://www.youtube.com/watch?v=zAGVQLHvwOY", 2019,
                        1000);
    controller.add_Film("TheManWithTheIronMask", "Action",
                        "https://www.youtube.com/watch?v=TUEQ4e0RVC4", 1998, 567);
    controller.add_Film("LOTR:TheFellowshipOfTheRing", "Adventure",
                        "https://www.youtube.com/watch?v=jhe6MYx9neo", 2001, 945);
    controller.add_Film("LOTR:TheBatlleOfTheTwoTowers", "Adventure",
                        "https://www.youtube.com/watch?v=cvCktPUwkW0", 2003, 982);
    controller.add_Film("LOTR:TheReturnOfTheKing", "Adventure",
                        "https://www.youtube.com/watch?v=yKjizAa8IHE", 2004, 1000);
    controller.add_Film("TheHobbit:AnUnexpectedJourney", "Adventure",
                        "https://www.youtube.com/watch?v=xJgLoV3i-mA", 2012, 785);
    controller.add_Film("The Hobbit:TheDesolationOfSmaug", "Adventure",
                        "https://www.youtube.com/watch?v=bkl8gNAKfVM", 2013, 846);
    controller.add_Film("TheHobbit:TheBatlleOfTheFiveArmies", "Adventure",
                        "https://www.youtube.com/watch?v=BLdMmA61UNc", 2014, 1000);
    controller.add_Film("PrideAndPrejudice", "Romance",
                        "https://www.youtube.com/watch?v=7Afx8MGg00g", 2005, 766);
    controller.add_Film("MansfieldPark", "Romance",
                        "https://www.youtube.com/watch?v=FRQSzU0q7Qg", 1999, 805);
    return controller.get_Filme();
}
vector <Film> loschen(FilmController controller) {
    controller.add_Film("Joker", "Thriller", "https://www.youtube.com/watch?v=zAGVQLHvwOY", 2019,
                        1000);
    controller.add_Film("TheManWithTheIronMask", "Action",
                        "https://www.youtube.com/watch?v=TUEQ4e0RVC4", 1998, 567);
    controller.add_Film("LOTR:TheFellowshipOfTheRing", "Adventure",
                        "https://www.youtube.com/watch?v=jhe6MYx9neo", 2001, 945);
    controller.add_Film("LOTR:TheBatlleOfTheTwoTowers", "Adventure",
                        "https://www.youtube.com/watch?v=cvCktPUwkW0", 2003, 982);
    controller.add_Film("LOTR:TheReturnOfTheKing", "Adventure",
                        "https://www.youtube.com/watch?v=yKjizAa8IHE", 2004, 1000);
    controller.add_Film("TheHobbit:AnUnexpectedJourney", "Adventure",
                        "https://www.youtube.com/watch?v=xJgLoV3i-mA", 2012, 785);
    controller.add_Film("The Hobbit:TheDesolationOfSmaug", "Adventure",
                        "https://www.youtube.com/watch?v=bkl8gNAKfVM", 2013, 846);
    controller.add_Film("TheHobbit:TheBatlleOfTheFiveArmies", "Adventure",
                        "https://www.youtube.com/watch?v=BLdMmA61UNc", 2014, 1000);
    controller.add_Film("PrideAndPrejudice", "Romance",
                        "https://www.youtube.com/watch?v=7Afx8MGg00g", 2005, 766);
    controller.add_Film("MansfieldPark", "Romance",
                        "https://www.youtube.com/watch?v=FRQSzU0q7Qg", 1999, 805);
    controller.delete_Film("MansfieldPark");
    controller.delete_Film("Joker");
    return controller.get_Filme();
}

string search(FilmController controller) {
    controller.add_Film("Joker", "Thriller", "https://www.youtube.com/watch?v=zAGVQLHvwOY", 2019,
                        1000);
    controller.add_Film("TheManWithTheIronMask", "Action",
                        "https://www.youtube.com/watch?v=TUEQ4e0RVC4", 1998, 567);

    return controller.find_Film("Joker").get_Titel();
}

TEST(FilmControllerTest, AddFilm) {
    FilmController controller = FilmController();
    vector <Film> vec;
    vec=create(controller);;
ASSERT_EQ(10, vec.size());
ASSERT_EQ("Joker", vec[0].get_Titel());
ASSERT_EQ("TheManWithTheIronMask", vec[1].get_Titel());
ASSERT_EQ("LOTR:TheFellowshipOfTheRing", vec[2].get_Titel());
ASSERT_EQ("LOTR:TheBatlleOfTheTwoTowers", vec[3].get_Titel());
ASSERT_EQ("LOTR:TheReturnOfTheKing", vec[4].get_Titel());
ASSERT_EQ("TheHobbit:AnUnexpectedJourney", vec[5].get_Titel());
ASSERT_EQ("The Hobbit:TheDesolationOfSmaug", vec[6].get_Titel());
ASSERT_EQ("TheHobbit:TheBatlleOfTheFiveArmies", vec[7].get_Titel());
ASSERT_EQ("PrideAndPrejudice", vec[8].get_Titel());
ASSERT_EQ("MansfieldPark", vec[9].get_Titel());
}

TEST(FilmControllerTest, DeleteFilm) {
    FilmController controller = FilmController();
    vector <Film> vec;
    vec=loschen(controller);
    ASSERT_EQ(8, vec.size());
    ASSERT_EQ("TheManWithTheIronMask", vec[0].get_Titel());
    ASSERT_EQ("PrideAndPrejudice", vec[7].get_Titel());
}

TEST(FilmControllerTest, SearchFilm){
    FilmController controller = FilmController();
    string f = search(controller);
    ASSERT_EQ(f,"Joker");
}

