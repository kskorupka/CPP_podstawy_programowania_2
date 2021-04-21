#include <algorithm>
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <iterator>
#include <list>
#include <memory>
#include <typeinfo>
using namespace std;

class Figure {
    string type;
    class Point2D {
    public:
        int x_ob;
        int y_ob;
        Point2D() {
            x_ob = 0;
            y_ob = 0;
        }
        double getPtX() { return x_ob; };
        double getPtY() { return y_ob; };
        Point2D(int _x, int _y) {
            x_ob = _x;
            y_ob = _y;
        }
        void setPtXY(int x, int y) {
            x_ob = x;
            y_ob = y;
        }
    };
    Point2D coord;

public:
    Figure() {
        coord.x_ob = 0;
        coord.y_ob = 0;
    }
    virtual ~Figure() = default;
    void setXY(int _x, int _y) { coord.setPtXY(_x, _y); }
    void setType(const char* n) { type = n; }
    void getType() { cout << type; }
    string getTypeString() { return type; }
    void getCo() { cout << "(" << coord.x_ob << " , " << coord.y_ob << ")"; }
    virtual double getArea() const { return 0; };
    virtual double getCircumference() { return 0; };
    Figure(const Figure& f) {
        this->setXY(f.getX(), f.getY());
        this->type = f.type;
    }
    virtual Figure* clone() const { return new Figure(*this); }
    double getX() const { return this->coord.x_ob; }
    double getY() const { return this->coord.y_ob; }
};

class Square : public Figure {
private:
    string type = "Square";
    double side = 5;

public:
    static double count;

    Square(const Square& sq) : Figure(sq) {
        this->side = sq.side;
        count++;
    }

    Square(double _side_, int x, int y) {
        count++;
        side = _side_;
        //std::cout << "Object Square created" << std::endl;
        this->setType("Square");
        this->setXY(x, y);
    }
    Square() {
        count++;
        this->setType("Square");
    };
    ~Square() {
        count--;
        std::cout << "Object Square destroyed" << std::endl;
    }
    double getCircumference() override { return 4 * side; }
    double getArea() const override { return side * side; }
    double getSide() { return side; }
    void set(double n) { side = n; }
    void changePosS(int a, int b) { this->setXY(a, b); }
};
double Square::count = 0;
class Circle : public Figure {
private:
    double radius = 10;

public:
    Circle(const Circle& cir) : Figure(cir) { this->radius = cir.radius; }
    Circle(double _radius_, int x, int y) {
        radius = _radius_;
        //std::cout << "Object Circle created" << std::endl;
        this->setXY(x, y);
        this->setType("Circle");
    }
    Circle() {
        this->setType("Circle");
        this->setXY(0, 0);
    };
    ~Circle() { std::cout << "Object Circle destroyed" << std::endl; }
    double getCircumference() override { return 2 * M_PI * radius; }
    double getArea() const override { return M_PI * radius * radius; }
    static void print_pi() { std::cout << "Pi is " << M_PI << std::endl; }
    void set(double n) { radius = n; }
    double getRadius() { return radius; }
    void changePosC(int a, int b) { this->setXY(a, b); }
};

class Drawing {
private:
    int r_x, r_y;
    list<Figure*> figureList;

public:
    Drawing() {
        r_x = 20;
        r_y = 20;
    };
    Drawing(int _rx, int _ry) {
        r_x = _rx;
        r_y = _ry;
        //cout << "Drawing has been created." << endl;
    }
    Drawing(const Drawing& f) {};
    ~Drawing() {
        figureList.clear();
        cout << endl << "Clear the lsit." << endl;
    }
    Drawing* deepcopy(const Drawing* copy) { return new Drawing(*copy); }
    void setSize(int rx, int ry) {
        r_x = rx;
        r_y = ry;
    }
    void addFigure(Figure* ab) { figureList.push_back(ab); };
    void printList() {
        cout << endl << "List of elements: " << endl;
        for (auto const& v : figureList) {
            cout << "Figure type: ";
            v->getType();
            cout << " ";
            cout << endl << "Co-ordinates: ";
            v->getCo();
            cout << endl;
            cout << "Area: " << v->getArea()
                << " Circumference: " << v->getCircumference() << endl
                << endl;
        }
        cout << endl;
    }
    void eraser(int idx) {
        list<Figure*>::iterator itr = figureList.begin();
        advance(itr, idx);
        figureList.erase(itr);
    }
    void setList(list<Figure*>& lista) {figureList = lista;}
    list<Figure*>& getList(){return figureList;}
    int getX()const { return r_x; }
    int getY()const { return r_y; }
    bool operator==(Drawing& drawing) {
        if (this->getX() != drawing.getX() || this->getX() != drawing.getY()) return false;
        //Are the lists the same if they have the same address or the same content??
        //list address:
        /*
        list<Figure*> lista1 = this->getList();
        list<Figure*> lista2 = drawing.getList();
        if (&lista1 != &lista2) return false;*/
        //list content:
        list<Figure*>::iterator i = this->getList().begin();
        list<Figure*>::iterator j = drawing.getList().begin();
        do {
            if (((*i)->getTypeString() != (*j)->getTypeString()) || ((*i)->getX() != (*j)->getX()) || ((*i)->getY() != (*j)->getY()) || ((*i)->getArea() != (*j)->getArea()) || ((*i)->getCircumference() != (*j)->getCircumference())) return false;
            i++;
            j++;
        } while (i != this->getList().end() && j != drawing.getList().end());
        return true;
    }
     Figure*& operator[](size_t n) {
        list<Figure*>::iterator it = this->getList().begin();
        advance(it, n);
        return *it;
    }
     Figure*& operator()(size_t n) {
         list<Figure*>::iterator it = this->getList().begin();
         advance(it, n);
         return *it;
     }
     Drawing operator=(Drawing& drawing) {
         if (&drawing == this) return *this;
         figureList = drawing.getList();
         r_x = drawing.getX();
         r_y = drawing.getY();
         return *this;
     }
     Drawing& operator+=(Drawing& drawing) {
         list<Figure*>::iterator start = drawing.getList().begin();
         list<Figure*>::iterator end = this->getList().end();
         for (Figure* i : drawing.getList()) this->getList().insert(end, i);
         return *this;
     }
};
std::ostream& operator<<(std::ostream& os, Drawing& obj) {
    cout<<"Drawing's size: "<< obj.getX()<< " X " << obj.getY() << endl;
    for (Figure* i : obj.getList()) {
        cout << "type: ";
        i->getType();
        cout<< ", position: (" << i->getX() << ", " << i->getY() << "), field: " << i->getArea() << endl;
    }
    return os;
}
std::istream& operator>>(std::istream& is, Drawing& obj)
{
    // read obj from stream
    if (&obj == NULL) is.setstate(std::ios::failbit);
    //set size
    int x, y;
    is >> x >> y;
    obj.setSize(x, y);
    return is;
}
bool PComp(const Figure* const& a, const Figure* const& b) {
    if (a->getArea() < b->getArea()) return true;
    return false;
}
Drawing operator+(Drawing& drawing1, Drawing& drawing2) {
    Drawing* new_drawing = new Drawing();
    *new_drawing = drawing1;
    list<Figure*>::iterator itr = new_drawing->getList().end();
    for (Figure* i : drawing2.getList()) new_drawing->getList().insert(itr, i);
    drawing1 = *new_drawing;
    delete new_drawing;
    return drawing1;
}
int main(int argc, char* argv[]) {
    Drawing* drawing = new Drawing(100, 100);
    Drawing* drawing2 = new Drawing(200, 200);

    Circle* c1 = new Circle(5, 10, 15);
    Square* s1 = new Square(5, 10, 15);
    drawing->addFigure(c1);
    drawing->addFigure(s1);

    drawing2->addFigure(c1);
    drawing2->addFigure(s1);

    Square* sq1 = new Square(*s1);
    Circle* cir2 = new Circle(*c1);
    drawing->addFigure(cir2);
    drawing->addFigure(sq1);

    // 1 // print all available info
    // std::cout << *drawing << std::endl;
    //done

    // 2 // change the drawing dimensions
    // std::cin >> *drawing;
    //done

    // 3 // comparison
    // if (*drawing == *drawing2) {
    //  std::cout << "Drawing are equal" << std::endl;
    // }
    //done

    // 4 // sort the figures based on area (compare pointer by the dereference)
    // uncoment also PComp function
    // drawing->getList().sort(PComp);
    //done

    // 5 // return the n'th element in the figure list
    // std::cout << (*drawing)[0] << std::endl;
    //done

    // 6 // return the n'th element in the figure list
    // std::cout << (*drawing)(0);
    //done

    // 7 // add figures from drawing2 to drawing
    // *drawing += *drawing2; //
    // *drawing = *drawing + *drawing2;

    // 8 //add copy assigment operator
    // *drawing = *drawing2;

    // 9 // fix the memory leak

    // 10 // clean the code
    cout << "cout<<*drawing : " << endl;
    cout <<*drawing << endl;
    Drawing* drawing3 = new Drawing();
    *drawing3 = *drawing;
    cout << "if drawing == drawing3 (drawing3 is drawing's copy): "<<endl;
    if (*drawing3 == *drawing) cout << "true" << endl;
    else cout << "false" << endl;
    cout << "if drawing == drawing2: ";
    if (*drawing2 == *drawing) cout << "true" << endl;
    else cout << "false" << endl;
    drawing->getList().sort(PComp);
    cout <<endl<<"drawing (after sort): "<<endl<< *drawing<<endl;
    cout <<"(*drawing)[2]: type: "<<(*drawing)[2]->getTypeString()<<", area: "<<(*drawing)[2]->getArea()<<endl;
    cout << "(*drawing)(1): type: " << (*drawing)(1)->getTypeString() << ", area: " << (*drawing)(1)->getArea() << endl<<endl;
    cout << "drawing+=drawing2: " << endl << endl;
    *drawing += *drawing2;
    cout << *drawing << endl;
    cout << endl << "*drawing = *drawing2: " << endl;
    *drawing = *drawing2;
    cout << *drawing;
    //cout<<"Set the dimension for *drawing (2 int numbers): ";
    //cin>>*drawing;
    cout<<endl<<*drawing<<endl;
    delete drawing;
    delete c1;
    delete s1;
    delete sq1;
    delete cir2;
    delete drawing2;
    delete drawing3;
    cout<<endl<<"\"cin>>*drawing\" wasn't used, but it's implemented and works as it should (uncomment lines: 314, 315)"<<endl;
    return 0;
}
