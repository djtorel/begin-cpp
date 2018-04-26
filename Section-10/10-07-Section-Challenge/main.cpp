#include <iostream>
#include <string>

int main() {
    std::string alphabet{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1"
                         "234567890,.?!'\":- "};
    std::string key{"Lwm.FuG-4A7\"U0'29?T5n3P6dH:M8O1B "
                    "EJZvpqXQeWKak,YVrjcigbSshR!yDtNlIoCzfx"};

    std::cout << "Enter your secret message: ";
    std::string message{};
    std::getline(std::cin, message);

    std::cout << std::endl << "Encrypting message..." << std::endl;

    std::string encrypted_message{};
    for (char ch : message) {
        size_t position{alphabet.find(ch)};
        if (position != std::string::npos) {
            char found_key{key.at(position)};
            encrypted_message += found_key;
        } else {
            encrypted_message += ch;
        }
    }

    std::cout << std::endl
              << "Encrypted message: " << encrypted_message << std::endl;

    std::cout << std::endl << "Decrypting message..." << std::endl;

    std::string decrypted_message{};
    for (char ch : encrypted_message) {
        size_t position{key.find(ch)};
        if (position != std::string::npos) {
            char found_char{alphabet.at(position)};
            decrypted_message += found_char;
        } else {
            decrypted_message += ch;
        }
    }

    std::cout << std::endl
              << "Decrypted message: " << decrypted_message << std::endl;

    std::cout << std::endl;
    return 0;
}
