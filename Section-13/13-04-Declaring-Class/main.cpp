#include <iostream>
#include <string>
#include <vector>

class Player {
  public:
    // Attributes
    std::string name;
    int health;
    int xp;

    // Methods
    void talk(std::string message) {
        std::cout << name << " says, '" << message << "'" << std::endl;
    }
    bool is_dead();
};

class Account {
  public:
    // Attributes
    std::string name;
    double balance;

    // Methods
    bool deposit(double bal);
    bool withdraw(double bal);
};

int main() {
    Player frank;

    frank.name = "Frank";
    frank.health = 100;
    frank.xp = 12;

    frank.talk("Hi there.");

    Player *enemy = new Player;
    (*enemy).name = "Enemy";
    enemy->health = 100;
    enemy->xp = 15;

    enemy->talk("I will destroy you!");

    delete enemy;

    return 0;
}
