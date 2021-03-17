#include <iostream>
#include <cmath>

class Square {
private:
  double side;
  // Wspolrzedne
public:
  static double count;
  Square(double _side_) {
    count++;
    side = _side_;
    std::cout << "Object Square created" << std::endl;
  }
  ~Square() {
    count--;
    std::cout << "Object Square destroyed" << std::endl;
  }
  Square(const Square &sqr1) { side = sqr1.side; }
  double getCircumference() const { return 4 * side; }
  double getArea() const { return side * side; }
};

double Square::count = 0;

class Circle {
private:
  double radius;
  // Wspolrzedne
public:
  Circle(double _radius_) {
    radius = _radius_;
    std::cout << "Object Circle created" << std::endl;
  }
  ~Circle() { std::cout << "Object Circle destroyed" << std::endl; }
  Circle(const Circle &cir1) { radius = cir1.radius; }
  double getCircumference() const { return 2 * M_PI * radius; }
  double getArea() const { return M_PI * radius * radius; }
  static double print_pi() { std::cout << "Pi is " << M_PI << std::endl; }
};

class Drawing {
private:
  // Kwadrat i Kolo
    Square* s1 = new Square(5);
    Circle* c1 = new Circle(5);
  // Rozmiar plotna
  const int width=20;
  const int height=20;


public:
  // Konstruktory
  // Destruktor
  // Pobierz Informacje
};

int main(int argc, char *argv[]) { 
    std::cout<<"Hello world"<<std::endl;
    return 0;
 }