#include <iostream>
#include <cmath>

class Square {
private:
  double side;
  // Wspolrzedne
  int x=5;
  int y=5;
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
  double getSide(){return side;}
  double getX(){return x;}
  double getY(){return y;}
};

double Square::count = 0;

class Circle {
private:
  double radius;
  // Wspolrzedne
  int x=10;
  int y=10;
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
  double getRadius(){return radius;}
  double getX(){return x;}
  double getY(){return y;}
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
  Drawing(){
      std::cout<<"Object Drawing created"<<std::endl;
  }
  Drawing(const Drawing &drawing){
      s1=drawing.s1;
      c1=drawing.c1;
  }
  // Destruktor
  ~Drawing(){
      std::cout<<"Object Drawing destroyed"<<std::endl;
      delete s1;
      //std::cout<<"Object Square destroyed"<<std::endl;
      delete c1;
      //std::cout<<"Object Circle destroyed"<<std::endl;
  }
  // Pobierz Informacje
  void getInfo(){
      std::cout<<"***INFORMATION ABOUT DRAWING***"<<std::endl;
      std::cout<<"Contains 2 objects"<<std::endl;
      std::cout<<"Square:"<<std::endl;
      std::cout<<"side: "<<s1->getSide()<<std::endl;
      std::cout<<"position: ("<<s1->getX()<<","<<s1->getY()<<")"<<std::endl;
      std::cout<<"Circle:"<<std::endl;
      std::cout<<"radius: "<<c1->getRadius()<<std::endl;
      std::cout<<"position: ("<<c1->getX()<<","<<c1->getY()<<")"<<std::endl;
  }
};

int main(int argc, char *argv[]) { 
    Drawing* drawing1=new Drawing;
    std::cout<<std::endl;
    drawing1->getInfo();
    std::cout<<std::endl;
    Drawing drawing2=*drawing1;
    std::cout<<std::endl;
    drawing2.getInfo();
    std::cout<<std::endl;
    delete drawing1;
    std::cout<<std::endl;
    return 0;
 }