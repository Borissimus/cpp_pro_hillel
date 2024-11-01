#include <iostream>
#include <string>
#include <vector>

class GameActor {
public:
    // Default constructor
    GameActor() : name("Unnamed Actor") {}

    // Copy constructor
    GameActor(const GameActor& other) : name(other.name) {}

    // Method to draw the name
    void draw() const {
        std::cout << name << std::endl;
    }

    // Method to get the actor's name
    std::string get_name() const {
        return name;
    }

    // Method to set the actor's name
    void set_name(const std::string& new_name) {
        name = new_name;
    }

private:
    std::string name; // Private field to store the actor's name
};

// Global vector to store pointers to GameActor objects
std::vector<GameActor*> actors;

// Function to duplicate a GameActor by index
GameActor* duplicateGameActor(const int index) {
    if (index >= 0 && static_cast<size_t>(index) < actors.size()) {
        // Create a new copy of the GameActor at the specified index
        return new GameActor(*actors[index]); // Copy in dynamic memory
    } else {
        // If index is invalid, create a new GameActor using the default constructor
        return new GameActor(); // Default constructor
    }
}

// Function to duplicate a GameActor by pointer
GameActor* duplicateGameActor(GameActor* actor) {
    if (actor != nullptr) {
        // Create a new copy of the given GameActor
        return new GameActor(*actor); // Copy in dynamic memory
    } else {
        // If nullptr, create a new GameActor using the default constructor
        return new GameActor(); // Default constructor
    }
}

// Function to clean up the allocated memory
void clean() {
    for (GameActor* actor : actors) {
        delete actor; // Free dynamically allocated memory
    }
    actors.clear(); // Clear the vector
}

int main(void) {
    using namespace std;

    // Create some GameActor objects and add them to the global vector
    actors.emplace_back(new GameActor());
    actors.back()->set_name("First Actor");
    actors.emplace_back(new GameActor());
    actors.back()->set_name("Second Actor");

    // Duplicate actors using the duplicateGameActor function
    actors.emplace_back(duplicateGameActor(0)); // Copy of "First Actor"
    actors.emplace_back(duplicateGameActor(1)); // Copy of "Second Actor"
    actors.emplace_back(duplicateGameActor(2)); // New actor created with default constructor

    // Create a temporary GameActor for duplication
    GameActor inst;
    inst.set_name("Temporary Actor");
    actors.emplace_back(duplicateGameActor(&inst)); // Duplicate the temporary actor

    // Draw all actors
    for (GameActor* actor : actors) {
        actor->draw();
    }

    // Clean up allocated memory
    clean();

    return 0;
}
