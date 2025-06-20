#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <unordered_map>

class Config {
public:
    // Create configuration file
    bool create(const std::string& filename);

    // Load configuration file
    bool load(const std::string& filename);

    // Get configuration item, return default value if not found
    std::string get(const std::string& key, const std::string& defaultValue = "") const;

    // Set configuration item
    void set(const std::string& key, const std::string& value);

    // Save configuration to file
    bool save(const std::string& filename) const;

private:
    std::unordered_map<std::string, std::string> configMap;
};

#endif // CONFIG_H