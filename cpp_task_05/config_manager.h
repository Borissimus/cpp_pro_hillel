#ifndef CONFIG_MANAGER_H
#define CONFIG_MANAGER_H

#include <string>
#include <map>
#include <mutex>

class ConfigManager {
public:
    static ConfigManager& getInstance() {
        static ConfigManager instance; // Guaranteed to be destroyed and instantiated on first use
        return instance;
    }

    // Prevent copying
    ConfigManager(ConfigManager const&) = delete;
    void operator=(ConfigManager const&) = delete;

    void setConfig(const std::string& key, const std::string& value) {
        std::lock_guard<std::mutex> guard(config_mutex); // Ensure thread safety
        config_map[key] = value;
    }

    std::string getConfig(const std::string& key) {
        std::lock_guard<std::mutex> guard(config_mutex); // Ensure thread safety
        auto it = config_map.find(key);
        if (it != config_map.end()) {
            return it->second;
        } else {
            return "Key not found";
        }
    }

private:
    ConfigManager() {}

    std::map<std::string, std::string> config_map; // Map to store config pairs
    mutable std::mutex config_mutex; // Mutex for thread safety
};

#endif // CONFIG_MANAGER_H
