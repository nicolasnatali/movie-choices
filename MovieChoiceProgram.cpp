#include "MovieChoiceProgram.h"

void MovieChoiceProgram::run() {
    std::cout << "Welcome to the Movie Choice Program!" << std::endl;
    addMovies();
    while (true) {
        std::cout << "Please select from the following options:" << std::endl;
        std::cout << "1. Display all movies" << std::endl;
        std::cout << "2. Change ranking of movie" << std::endl;
        std::cout << "3. Quit" << std::endl;
        std::cout << "> ";
        int userInput;
        std::cin >> userInput;
        std::cin.ignore();
        switch (userInput) {
            case 1:
                displayAllMovies();
                break;
            case 2:
                changeRanking();
                break;
            case 3:
                std::cout << "Thank you for using the Movie Choice Program!" << std::endl;
                return;
            default:
                std::cout << "Invalid input. Please try again." << std::endl;
                break;
        }
    }
}

void MovieChoiceProgram::addMovies() {
    std::cout << "Enter five movies:" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "> ";
        std::string movie;
        std::getline(std::cin, movie);
        while (movie.empty()) {
            std::cout << "Movie cannot be empty. Please try again." << std::endl;
            std::cout << "Enter movie " << i + 1 << ": ";
            std::getline(std::cin, movie);
        }
        movieList.push_back(movie);
    }
}

void MovieChoiceProgram::displayAllMovies() {
    auto it = movieList.begin();
    for (int i = 0; it != movieList.end(); it++, i++) {
        std::cout << i + 1 << ". " << *it << std::endl;
    }
}

void MovieChoiceProgram::changeRanking() {
    std::cout << "Enter the name of the movie:" << std::endl;
    std::cout << "> ";
    std::string movieName;
    std::getline(std::cin, movieName);
    std::cout << "Enter the new ranking of the movie:" << std::endl;
    std::cout << "> ";
    int movieRanking;
    std::cin >> movieRanking;
    auto it = movieList.begin();
    for (int i = 0; it != movieList.end(); it++, i++) {
        if (*it == movieName) {
            movieList.erase(it);
            break;
        }
    }
    it = movieList.begin();
    for (int i = 0; it != movieList.end(); it++, i++) {
        if (i == movieRanking - 1) {
            movieList.insert(it, movieName);
            break;
        }
    }
}
