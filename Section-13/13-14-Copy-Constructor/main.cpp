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

    // Copy Constructor
    Player(const Player &source);

    // Destructor
    ~Player();

    std::string get_name();
    int get_health();
    int get_xp();
};

Player::Player(std::string name_val, int health_val, int xp_val)
    : name{name_val}, health{health_val}, xp{xp_val} {}

Player::Player(const Player &source)
    : name{source.name}, health{source.health}, xp{source.xp} {
    std::cout << "Copy constructor - made a copy of: " << source.name
              << std::endl;
}

Player::~Player() {
    std::cout << "Destructor called for " << name << std::endl;
}

void display_player(Player p) {
    std::cout << "Name: " << p.get_name() << std::endl
              << "Health: " << p.get_health() << std::endl
              << "XP: " << p.get_xp() << std::endl;
}

std::string Player::get_name() { return name; }
int Player::get_health() { return health; }
int Player::get_xp() { return xp; }

int main() {
    Player empty{"XXXXXX", 100, 50};

    Player my_new_object{empty};

    display_player(empty);

    Player frank{"Frank"};
    Player hero{"Hero", 100};
    Player villain{"Villain", 100, 55};

    return 0;
}
