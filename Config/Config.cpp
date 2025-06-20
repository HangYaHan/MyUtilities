#include "Config.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

// Create configuration file
bool Config::create(const std::string& filename) {
    std::ofstream outfile(filename);
    return outfile.is_open();
}

// Load configuration file
bool Config::load(const std::string& filename) {
    std::ifstream infile(filename);
    if (!infile.is_open()) return false;

    configMap.clear();
    std::string line;
    while (std::getline(infile, line)) {
        // Remove comments and blank lines
        auto commentPos = line.find('#');
        if (commentPos != std::string::npos) line = line.substr(0, commentPos);
        line.erase(0, line.find_first_not_of(" \t\r\n"));
        line.erase(line.find_last_not_of(" \t\r\n") + 1);

        if (line.empty()) continue;

        auto delimPos = line.find('=');
        if (delimPos == std::string::npos) continue;

        std::string key = line.substr(0, delimPos);
        std::string value = line.substr(delimPos + 1);

        // Trim leading and trailing whitespace
        key.erase(0, key.find_first_not_of(" \t\r\n"));
        key.erase(key.find_last_not_of(" \t\r\n") + 1);
        value.erase(0, value.find_first_not_of(" \t\r\n"));
        value.erase(value.find_last_not_of(" \t\r\n") + 1);

        configMap[key] = value;
    }
    return true;
}

// Get configuration item
std::string Config::get(const std::string& key, const std::string& defaultValue) const {
    auto it = configMap.find(key);
    if (it != configMap.end()) {
        return it->second;
    }
    return defaultValue;
}

// Set configuration item
void Config::set(const std::string& key, const std::string& value) {
    configMap[key] = value;
}

// Save configuration to file
bool Config::save(const std::string& filename) const {
    std::ofstream outfile(filename);
    if (!outfile.is_open()) {
        std::cout << "Failed to open file for saving: " << filename << std::endl;
        return false;
    }

    for (const auto& pair : configMap) {
        outfile << pair.first << "=" << pair.second << std::endl;
    }
    return true;
}