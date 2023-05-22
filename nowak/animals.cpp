#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class Animal {
protected:
    int age;
    int height;
public:
    Animal(int _age, int _height) : age(_age), height(_height) {}
    virtual void showInfo() = 0;
};

class Mammal : public Animal {
protected:
    std::string race;
    std::string sound;
public:
    Mammal(int _age, int _height, const std::string& _race, const std::string& _sound)
        : Animal(_age, _height), race(_race), sound(_sound) {}

    void showInfo() override {
        std::cout << "Mammal: Race = " << race << ", Sound = " << sound << ", Age = " << age << ", Height = " << height << std::endl;
    }
};

class Dog : public Mammal {
public:
    Dog(int _age, int _height, const std::string& _race, const std::string& _sound)
        : Mammal(_age, _height, _race, _sound) {}
};

class Cat : public Mammal {
public:
    Cat(int _age, int _height, const std::string& _race, const std::string& _sound)
        : Mammal(_age, _height, _race, _sound) {}
};

class Bird : public Animal {
protected:
    std::string species;
    std::string wingSpan;
    std::string flightAltitude;
public:
    Bird(int _age, int _height, const std::string& _species, const std::string& _wingSpan, const std::string& _flightAltitude)
        : Animal(_age, _height), species(_species), wingSpan(_wingSpan), flightAltitude(_flightAltitude) {}

    virtual bool canFly() const = 0; // Funkcja czysto wirtualna, wymaga implementacji w klasach pochodnych

    void showInfo() override {
        std::cout << "Bird: Species = " << species << ", Wing Span = " << wingSpan << ", Flight Altitude = " << flightAltitude << ", Age = " << age << ", Height = " << height;
        if (canFly())
            std::cout << ", Can Fly" << std::endl;
        else
            std::cout << ", Flightless" << std::endl;
    }
};

class Eagle : public Bird {
public:
    Eagle(int _age, int _height, const std::string& _wingSpan, const std::string& _flightAltitude)
        : Bird(_age, _height, "Eagle", _wingSpan, _flightAltitude) {}

    bool canFly() const override {
        return true;
    }
};

class Penguin : public Bird {
public:
    Penguin(int _age, int _height, const std::string& _wingSpan, const std::string& _flightAltitude)
        : Bird(_age, _height, "Penguin", _wingSpan, _flightAltitude) {}

    bool canFly() const override {
        return false;
    }
};

int main() {
    srand(time(NULL)); // Inicjalizacja generatora liczb losowych

    // Tworzenie obiektów i wywołanie funkcji showInfo()
    Dog dog(rand() % 10 + 1, rand() % 50 + 20, "Golden Retriever", "Woof");
    Cat cat(rand() % 15 + 1, rand() % 30 + 10, "Maine Coon", "Meow");
    Eagle eagle(rand() % 5 + 1, rand() % 20 + 10, "2 meters", "5000 meters");
    Penguin penguin(rand() % 10 + 1, rand() % 50 + 20, "1 meter", "100 meters");

    dog.showInfo();
    cat.showInfo();
    eagle.showInfo();
    penguin.showInfo();

    return 0;
}