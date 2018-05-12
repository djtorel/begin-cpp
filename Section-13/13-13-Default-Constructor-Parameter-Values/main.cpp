#include <iostream>
#include <string>

class Player {
  private:
    // Attributes
    std::string name;
    int health;
    int xp;

  public:
    Player(std::string name_val = "None", int health_val = 0, int xp_val = 0);

    int get_health();
    int get_xp();
};

Player::Player(std::string name_val, int health_val, int xp_val)
    : name{name_val}, health{health_val}, xp{xp_val} {}

int Player::get_health() { return health; }
int Player::get_xp() { return xp; }

int main() {
    Player empty;
    Player frank{"Frank"};
    Player hero{"Hero", 100};
    Player villain{"Villain", 100, 55};

    return 0;
}
