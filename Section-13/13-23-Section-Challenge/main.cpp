#include "Movies.h"
#include <iostream>

// Prototypes for helper functions
void increment_watched(Movies &movies, std::string name);
void add_movie(Movies &movies, std::string name, std::string rating,
               int watched);

/**
 * Helper function
 * increment_watched expects a reference to a Movies object and the name of the
 * movie to increment the watched count.
 *
 * If the watched count was incremented successfully it displays a success
 * message. Otherwise, the watched count could not be incremented because the
 * name of the movie was not found.
 */

void increment_watched(Movies &movies, std::string name) {
    if (movies.increment_watched(name)) {
        std::cout << name << " watch incremented" << std::endl;
    } else {
        std::cout << name << " not found" << std::endl;
    }
}

/**
 * Helper function
 * add_movie expects a reference to a Movies object and the name of the movie,
 * the rating and the watched count.
 *
 * If the movie was successfully added to the movies object it displays a
 * success message. Otherwise,  the movie was not added.
 */
void add_movie(Movies &movies, std::string name, std::string rating,
               int watched) {
    if (movies.add_movie(name, rating, watched)) {
        std::cout << name << " was added" << std::endl;
    } else {
        std::cout << name << " already exists" << std::endl;
    }
}

int main() {
    Movies my_movies;

    my_movies.display();

    add_movie(my_movies, "Big", "PG-13", 2);
    add_movie(my_movies, "Star Wars", "PG", 5);
    add_movie(my_movies, "Cinderella", "PG", 7);

    my_movies.display();

    add_movie(my_movies, "Cinderella", "PG", 7);
    add_movie(my_movies, "Ice Age", "PG", 12);

    my_movies.display();

    increment_watched(my_movies, "Big");
    increment_watched(my_movies, "Ice Age");

    my_movies.display();
    increment_watched(my_movies, "XXX");
    return 0;
}
