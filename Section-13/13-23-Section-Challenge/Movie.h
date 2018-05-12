#pragma once
#include <string>

class Movie {
  private:
    std::string name;
    std::string rating;
    int watched;

  public:
    // Default constructor
    Movie(std::string name_val, std::string rating_val, int watched_val = 0);
    // Copy constructor
    Movie(const Movie &source);
    ~Movie();

    // Implementation of getters and setters
    void set_name(std::string name) { this->name = name; }
    std::string get_name() const { return name; }

    void set_rating(std::string rating) { this->rating = rating; }
    std::string get_rating() const { return rating; }

    void set_watched(int watched) { this->watched = watched; }
    int get_watched() const { return watched; }

    // Implementation of increment_watched() method
    // Should just increase watched attribute by 1
    void increment_watched() { ++watched; }

    // Display the movie info, ex: Movie_Title, PG, 2
    void display() const;
};
