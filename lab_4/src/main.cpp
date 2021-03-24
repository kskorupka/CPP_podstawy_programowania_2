#include <iostream>
#include <cmath>
#include <list>

class Figure{
    std::string type;
    float x;
    float y;
public:
    float getX(){return x;}
    float getY(){return y;}
    std::string getType(){return type;}
    Figure(){
        //std::cout<<std::endl<<"***OBJECT FIGURE CREATED***"<<std::endl<<std::endl;
    }
    Figure (Figure &figure){
        x=figure.x;
        y=figure.y;
    }
    virtual ~Figure(){
        //std::cout<<std::endl<<"***OBJECT FIGURE DESTROYED***"<<std::endl<<std::endl;
    }
    virtual double field()=0;
    void setX(float _x){x=_x;}
    void setY(float _y){y=_y;}
    void setType(std::string s){type=s;}
};
class Square: public Figure{
    double side;
public:
    Square(float _x,float _y,double _side,std::string type="square"){
        setX(_x);
        setY(_y);
        side=_side;
        setType(type);
        //std::cout<<std::endl<<"***OBJECT SQUARE CREATED***"<<std::endl<<std::endl;
    }
    Square(Square &square){
        setX(square.getX());
        setY(square.getY());
        side=square.side;
        setType(square.getType());
    }
    ~Square(){
        //std::cout<<std::endl<<"***OBJECT SQUARE DESTROYED***"<<std::endl<<std::endl;
    }
    virtual double field(){
        return pow(side,2);
    }
};
class Circle: public Figure{
    double radius;
public:
    Circle(float _x,float _y, double _radius,std::string type="circle"){
        setX(_x);
        setY(_y);
        radius=_radius;
        setType(type);
        //std::cout<<std::endl<<"***OBJECT CIRCLE CREATED***"<<std::endl<<std::endl;
    }
    Circle(Circle &circle){
        setX(circle.getX());
        setY(circle.getY());
        radius=circle.radius;
        setType(circle.getType());
    }
    ~Circle(){
        //std::cout<<std::endl<<"***OBJECT CIRCLE DESTROYED***"<<std::endl<<std::endl;
    }
    virtual double field(){
        return M_PI*pow(radius,2);
    }
};
class Drawing{
    double sizeA,sizeB;
    Figure *ptr;
public:
    std::list<Figure*> figures;
    void addFigure(Figure* ptr){
        figures.push_back(ptr);
    }
    void setSize(double _a,double _b){
        sizeA=_a;
        sizeB=_b;
    }
    double getSizeA(){return sizeA;}
    double getSizeB(){return sizeB;}
    Drawing(double _a,double _b){
        setSize(_a,_b);
        //std::cout<<std::endl<<"***OBJECT DRAWING CREATED***"<<std::endl<<std::endl;
    }
    ~Drawing(){
        //std::cout<<std::endl<<"***OBJECT DRAWING DESTROYED***"<<std::endl<<std::endl;
    }
};
int main(int argc, char *argv[]){
    Drawing d1(20,30);
    Figure *ptr;
    Square *s=new Square(5,6,7);
    ptr=s; d1.addFigure(ptr);
    Circle *c=new Circle(1,1,3);
    ptr=c; d1.addFigure(ptr);
    Square s1=*s;
    ptr=&s1; d1.addFigure(ptr);
    Circle c1=*c;
    ptr=&c1; d1.addFigure(ptr);
    c=new Circle(10,20,3);
    ptr=c; d1.addFigure(ptr);
    std::cout<<"Drawing "<<d1.getSizeA()<<"x"<<d1.getSizeB()<<std::endl;
    for(Figure* i:d1.figures){
        std::cout<<"figure: "<<i->getType()<<", "<<"positon: ("<<i->getX()<<","<<i->getY()<<"), field: "<<i->field()<<std::endl;
    }
    return 0;
}