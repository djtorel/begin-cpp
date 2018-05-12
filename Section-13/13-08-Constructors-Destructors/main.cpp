#include <iostream>
#include <string>

class Player {
  private:
    // Attributes
    std::string name;
    int health;
    int xp;

  public:
    // Methods
    void set_name(std::string name_val) { name = name_val; }

    // Overloaded Constructors
    Player() { std::cout << "No args constructor called" << std::endl; }
    Player(std::string name_val) {
        name = name_val;
        std::cout << "String arg constructor called" << std::endl;
    }
    Player(std::string name_val, int health_val, int xp_val) {
        name = name_val;
        health = health_val;
        xp = xp_val;
        std::cout << "Three args constructor called" << std::endl;
    }
    ~Player() { std::cout << "Destructor called for " << name << std::endl; }
};

int main() {

    {
        Player slayer;
        slayer.set_name("Slayer");
    }

    {
        Player frank;
        frank.set_name("Frank");
        Player hero("Hero");
        hero.set_name("Hero");
        Player villain("Villain", 100, 12);
        villain.set_name("Villain");
    }

    Player *enemy = new Player;
    enemy->set_name("Enemy");

    delete enemy;

    return 0;
}
