#include <iostream>
#include <fstream>
#include <string>

class Person {
private:
    std::string name;
    int age;

public:
    Person(const std::string& name, int age) : name(name), age(age) {}

    // Serialization method to write object to file
    void serialize(std::ofstream& ofs) const {
        ofs << name << std::endl;
        ofs << age << std::endl;
    }

    // Deserialization method to read object from file
    void deserialize(std::ifstream& ifs) {
        std::getline(ifs, name);
        ifs >> age;
        // Consume newline character
        ifs.ignore();
    }

    void display() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

int main() {
    // Create a Person object
    Person person("Alice", 30);

    // Serialize the object to a file
    std::ofstream ofs("person.txt");
    if (ofs.is_open()) {
        person.serialize(ofs);
        ofs.close();
    } else {
        std::cerr << "Error: Unable to open file for writing." << std::endl;
        return 1;
    }

    // Deserialize the object from the file
    Person newPerson("", 0);
    std::ifstream ifs("person.txt");
    if (ifs.is_open()) {
        newPerson.deserialize(ifs);
        ifs.close();
    } else {
        std::cerr << "Error: Unable to open file for reading." << std::endl;
        return 1;
    }

    // Display the deserialized object
    newPerson.display();

    return 0;
}
