#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class Shape {
private:
    std::string name;

public:
    Shape() {}

    virtual double surface() const = 0;

    std::string getName() const {
        return name;
    }

    void setName(const std::string& newName) {
        name = newName;
    }
};

class Triangle : public Shape {
private:
    double base;
    double height;

public:
    Triangle(double base, double height) : base(base), height(height) {
        setName("Triangle");
    }

    double surface() const override {
        return (base * height) / 2;
    }
};

class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double length, double width) : length(length), width(width) {
        setName("Rectangle");
    }

    double surface() const override {
        return length * width;
    }
};

class Trapeze : public Shape {
private:
    double base1;
    double base2;
    double height;

public:
    Trapeze(double base1, double base2, double height)
        : base1(base1), base2(base2), height(height) {
        setName("Trapeze");
    }

    double surface() const override {
        return ((base1 + base2) * height) / 2;
    }
};

int main() {
    std::srand(std::time(nullptr)); // pseudo-random number generator

    std::vector<Shape*> figury;

    // add random shapes to the vector
    for (int i = 0; i < 2; i++) {
        double base = std::rand() % 10 + 1; // random number from 1-10 range
        double height = std::rand() % 10 + 1;
        figury.push_back(new Triangle(base, height));
    }

    for (int i = 0; i < 2; i++) {
        double length = std::rand() % 10 + 1;
        double width = std::rand() % 10 + 1;
        figury.push_back(new Rectangle(length, width));
    }

    for (int i = 0; i < 2; i++) {
        double base1 = std::rand() % 10 + 1;
        double base2 = std::rand() % 10 + 1;
        double height = std::rand() % 10 + 1;
        figury.push_back(new Trapeze(base1, base2, height));
    }

    // iterate the vector and output the surface area and shape name
    for (const auto& figura : figury) {
        std::cout << figura->getName() << " surface area: " << figura->surface() << std::endl;
    }

    // clear memory
    for (const auto& figura : figury) {
        delete figura;
    }

    return 0;
}

