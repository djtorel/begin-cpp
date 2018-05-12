#include <iostream>
#include <string>

class Player {
  private:
    // Attributes
    std::string name;
    int health;
    int xp;

  public:
    Player();
    Player(std::string name_val);
    Player(std::string name_val, int health_val, int xp_val);

    int get_health();
    int get_xp();
};

Player::Player() : Player{"None", 0, 0} {
    std::cout << "No-args constructor" << std::endl;
}
Player::Player(std::string name_val) : Player{name_val, 0, 0} {
    std::cout << "One-arg constructor" << std::endl;
}
Player::Player(std::string name_val, int health_val, int xp_val)
    : name{name_val}, health{health_val}, xp{xp_val} {
    std::cout << "Three-args constructor" << std::endl;
}

int Player::get_health() { return health; }
int Player::get_xp() { return xp; }

int main() {
    Player empty;
    Player frank{"Frank"};
    Player villain{"Villain", 100, 55};

    return 0;
}
