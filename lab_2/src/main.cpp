#include <iostream>
#include <math.h>
class Circle{
    public:
    double r;
    static double PI(){
        return M_PI;
    }
    double Perimeter(double r){
        return 2*PI()*r;
    }
    double Field(double r){
        return pow(r,2)*PI();
    }
};
class Square{
    public:

};
int main(int argc, char *argv[]){
    return 0;
}