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

Player::Player() : name{"None"}, health{0}, xp{0} {}
Player::Player(std::string name_val) : name{name_val}, health{0}, xp{0} {}
Player::Player(std::string name_val, int health_val, int xp_val)
    : name{name_val}, health{health_val}, xp{xp_val} {}

int Player::get_health() { return health; }
int Player::get_xp() { return xp; }

int main() {
    Player empty;
    Player frank{"Frank"};
    Player villain{"Villain", 100, 55};

    return 0;
}
