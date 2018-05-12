#include "Player.h"
#include <iostream>

void display_active_players() {
    std::cout << "Active players: " << Player::get_num_players() << std::endl;
}

int main() {
    display_active_players();
    Player hero{"Hero"};
    display_active_players();
    {
        Player dom{"Dom"};
        display_active_players();
    }

    display_active_players();
    return 0;
}
