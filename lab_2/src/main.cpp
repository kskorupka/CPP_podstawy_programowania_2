#include <iostream>
#include <math.h>
class Circle{
    public:
    double r;
    static double PI(){
        return M_PI;
    }
    double Perimeter(){
        return 2*PI()*r;
    }
    double Field(){
        return pow(r,2)*PI();
    }
    Circle(){
        std::cout<<"***NEW CIRCLE CREATED***"<<std::endl;
        count++;
    }
    Circle(const Circle &circle){
        r=circle.r;
        std::cout<<"***CIRCLE'S COPY CREATED***"<<std::endl;
    }
    ~Circle(){
        std::cout<<"***CIRCLE DESTROYED***"<<std::endl;
    }
};
class Square{
    public:
    double a;
    double Perimeter(){
        return 4*a;
    }
    double Field(){
        return pow(a,2);
    }
    Square(){
        std::cout<<"***NEW SQUARE CREATED***"<<std::endl;
        count++;
    }
    Square(const Square &square){
        a=square.a;
        std::cout<<"***SQUARE'S COPY CREATED***"<<std::endl;
    }
    ~Square(){
        std::cout<<"***SQUARE DESTROYED***"<<std::endl;
    }
};
int main(int argc, char *argv[]){
    Circle o1;
    o1.r=3.0;
    std::cout<<"Perimeter of circle for r="<<o1.r<<" is: "<<o1.Perimeter()<<std::endl;
    std::cout<<"Field of circle for r="<<o1.r<<" is: "<<o1.Field()<<std::endl<<std::endl;
    Square k1;
    k1.a=5.0;
    std::cout<<"Perimeter of square for a="<<k1.a<<" is: "<<k1.Perimeter()<<std::endl;
    std::cout<<"Field of square for a="<<k1.a<<" is: "<<k1.Field()<<std::endl<<std::endl;
    Circle o2=o1;
    Square k2=k1;
    std::cout<<std::endl<<std::endl;
    Circle *pc=new Circle;
    Circle o3=*pc;
    std::cout<<std::endl<<std::endl;
    return 0;
}