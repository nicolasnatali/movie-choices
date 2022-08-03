#ifndef MOVIE_CHOICES_MOVIECHOICEPROGRAM_H
#define MOVIE_CHOICES_MOVIECHOICEPROGRAM_H

#include <iostream>
#include <list>
#include <string>

class MovieChoiceProgram {
public:
    void run();

private:
    void addMovies();

    void displayAllMovies();

    void changeRanking();

    std::list<std::string> movieList;
};

#endif //MOVIE_CHOICES_MOVIECHOICEPROGRAM_H
