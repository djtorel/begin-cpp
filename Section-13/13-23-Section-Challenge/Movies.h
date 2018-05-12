#pragma once
#include "Movie.h"
#include <string>
#include <vector>

class Movies {
  private:
    std::vector<Movie> movies;

  public:
    Movies();
    ~Movies();

    /**
     * add_movie expects name of a movie, rating and watched count
     *
     * It will search the movies vector to see if a movie object already exists
     * with the same name
     *
     * If it does then return false. Otherwise, create a movie from provided
     * information.
     */
    bool add_movie(std::string name, std::string rating, int watched);

    /**
     * increment_watched expects the name of the movie to increment the watched
     * count
     *
     * It searched the movies vector to see if the movie objec exists already
     * with the same name. if it does then increment that objects watched by 1
     * and return true
     *
     * Otherwise, return false since no movies object with the provided name
     * exists.
     */
    bool increment_watched(std::string name);

    /**
     * display
     * Calls display on all movie objects in the movies vector
     */
    void display() const;
};
