#include <iostream>
#include "Config.cpp"


void test_Config();

int main() {
    std::cout << "Hello, world!" << std::endl;
    test_Config();
    return 0;
}

void test_Config() {
    Config config;
    if (config.create("config.txt")) {
        std::cout << "Configuration file created successfully." << std::endl;
    } else {
        std::cerr << "Failed to create configuration file (file may already exist)." << std::endl;
    }

    if (config.load("config.txt")) {
        std::cout << "Configuration loaded successfully." << std::endl;
    } else {
        std::cerr << "Failed to load configuration file." << std::endl;
    }

    config.set("server", "localhost");

    config.save("config.txt");
    std::cout << "Configuration saved successfully." << std::endl;
}