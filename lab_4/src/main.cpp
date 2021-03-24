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
    Figure (const Figure &figure){
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
    ~Circle(){
        //std::cout<<std::endl<<"***OBJECT CIRCLE DESTROYED***"<<std::endl<<std::endl;
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
    Drawing d1;
    Square s1(1,2,5);
    Square s2(3,4,7);
    Circle c1(1,1,3);
    Figure *ptr=&s1;
    d1.getPointer(ptr);
    d1.addFigure();
    ptr=&s2;
    d1.getPointer(ptr);
    d1.addFigure();
    ptr=&c1;
    d1.getPointer(ptr);
    d1.addFigure();
    for(Figure* i:d1.figures){
        std::cout<<"figure: "<<i->getType()<<" ,"<<"positon: ("<<i->getX()<<","<<i->getY()<<"), field: "<<i->field()<<std::endl;
    }
    return 0;
}