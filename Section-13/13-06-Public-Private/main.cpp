#include <iostream>
#include <string>
#include <vector>

class Player {
  private:
    // Attributes
    std::string name;
    int health;
    int xp;

  public:
    // Methods
    void talk(std::string message) {
        std::cout << name << " says, '" << message << "'" << std::endl;
    }
    bool is_dead();
};

class Account {
  private:
    // Attributes
    std::string name;
    double balance;

  public:
    // Methods
    bool deposit(double bal);
    bool withdraw(double bal);
};

int main() {
    Player frank;
    // frank.name = "Frank";
    // std::cout << frank.health << std::endl;

    frank.talk("Hello there.");
    return 0;
}
