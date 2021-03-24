#include <iostream>
#include <cmath>
#include <list>

class Figure{
    float x;
    float y;
public:
    float getX(){return x;}
    float getY(){return y;}
    Figure(){
        std::cout<<std::endl<<"***OBJECT FIGURE CREATED***"<<std::endl<<std::endl;
    }
    /*Figure (const Figure &figure){
        x=figure.x;
        y=figure.y;
    }*/
    virtual ~Figure(){
        std::cout<<std::endl<<"***OBJECT FIGURE DESTROYED***"<<std::endl<<std::endl;
    }
    virtual double field()=0;
    void setX(float _x){x=_x;}
    void setY(float _y){y=_y;}
};
class Square: public Figure{
    double side;
public:
    Square(float x,float y,double side){
        std::cout<<std::endl<<"***OBJECT SQUARE CREATED***"<<std::endl<<std::endl;
    }
    ~Square(){
        std::cout<<std::endl<<"***OBJECT SQUARE DESTROYED***"<<std::endl<<std::endl;
    }
    virtual double field(){
        return pow(side,2);
    }
};
class Circle: public Figure{
    double radius;
public:
    Circle(float x,float y, double radius){
        std::cout<<std::endl<<"***OBJECT CIRCLE CREATED***"<<std::endl<<std::endl;
    }
    ~Circle(){
        std::cout<<std::endl<<"***OBJECT CIRCLE DESTROYED***"<<std::endl<<std::endl;
    }
    virtual double field(){
        return M_PI*pow(radius,2);
    }
};
class Drawing{
    Figure *ptr;
public:
    std::list<Figure*> figures;
    void getPointer(Figure* w){ptr=w;}
    void addFigure(){
        figures.push_back(ptr);
    }
};
/*class Square {
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
};*/
int main(int argc, char *argv[]){
    Square s1(1,2,5);
    /*Figure *ptr=&s1;
    Drawing d1;
    d1.getPointer(ptr);
    d1.addFigure();*/
    std::cout<<s1.getX();
    return 0;
}