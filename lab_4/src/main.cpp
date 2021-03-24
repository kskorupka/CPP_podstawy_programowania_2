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
    Figure (const Figure &figure){
        x=figure.x;
        y=figure.y;
    }
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
    Square(float _x,float _y,double _side){
        setX(_x);
        setY(_y);
        side=_side;
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
    Circle(float _x,float _y, double _radius){
        setX(_x);
        setY(_y);
        radius=_radius;
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
int main(int argc, char *argv[]){
    Square s1(1,2,5);
    Figure *ptr=&s1;
    Drawing d1;
    d1.getPointer(ptr);
    d1.addFigure();
    for(Figure* i:d1.figures){
        std::cout<<i->field()<<std::endl;
    }
    return 0;
}