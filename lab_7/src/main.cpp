#include <iostream>
#include <list>
using namespace std;
class Object {
	string type;
public:
	virtual ~Object() {};
	virtual void draw() const = 0;
	string getType() { return type; }
	void setType(string s) { type = s; }
};
class Circle: public Object {
	double radius;
public:
	Circle() {
		radius = 0;
		this->setType("Circle");
	}
	Circle(const Circle& circle) {
		radius = circle.radius;
		this->setType("Circle");
	}
	Circle(double _radius) {
		radius = _radius;
		this->setType("Circle");
	}
	~Circle() {};
	void draw() const override {
		cout << "Circle's radius: " << this->radius << endl;
	}
	void setRadius(double r) { radius = r; }
};
class Square : public Object {
	double side;
public:
	Square() {
		side = 0;
		this->setType("Square");
	}
	Square(const Square& square) {
		side = square.side;
		this->setType("Square");
	}
	Square(double _side) {
		side = _side;
		this->setType("Square");
	}
	~Square() {};
	void draw() const override {
		cout << "Square's side: " << this->side << endl;
	}
	void setSide(double s) { side = s; }
};
class StraightLine : public Object {
	double length;
public:
	StraightLine() {
		length = 0;
		this->setType("Straight Line");
	}
	StraightLine(const StraightLine& straightline) {
		length = straightline.length;
		this->setType("Straight Line");
	}
	StraightLine(double _length) {
		length = _length;
		this->setType("Straight Line");
	}
	~StraightLine() {};
	void draw() const override {
		cout << "Line's lenght: " << this->length << endl;
	}
	void setLenght(double l) { length = l; }
};
class CurvedLine : public Object {
	int angle;
	double length;
public:
	CurvedLine() {
		angle = 0;
		length = 0;
		this->setType("Curved Line");
	}
	CurvedLine(const CurvedLine& curvedline) {
		angle = curvedline.angle;
		length = curvedline.length;
		this->setType("Straight Line");
	}
	CurvedLine(int _angle, double _length) {
		angle = _angle;
		length = _length;
		this->setType("Straight Line");
	}
	~CurvedLine() {};
	void draw() const override {
		cout << "Line's angle: " << this->angle << ", length: " << this->length << endl;
	}
	void setLenght(double l) { length = l; }
	void setAngle(int a) {
		if (a > 360) angle = (a % 360);
		else if (a < 0) {
			a += 360;
			angle = (a % 360);
		}
		else angle = a; 
	}
};
class Drawing {
	list<Object*> objects;
public:
	list<Object*>& getList() { return objects; }
	void insertObject(Object* object) {
		objects.push_back(object);
	}
	~Drawing() {};
};
class Painter {
	Drawing drawing;
public:
	virtual ~Painter() {};
	virtual Object* createObject()const = 0;
	void draw() {
		Object* object = createObject();
		drawing.insertObject(object);
	}
	void drawObject(Object* object) {
		drawing.insertObject(object);
	}
	void printMyWork() {
		for (Object* i : drawing.getList()) {
			cout << "Object: " << i->getType() << endl;
			i->draw();
		}
	}
};
class CirclePainter : public Painter {
public:
	Object* createObject() const override{ return new Circle(4); }
	~CirclePainter() {};
};
class SquarePainter : public Painter {
public:
	Square* createObject() const override { return new Square(3); }
	~SquarePainter() {};
};
class StraightLinePainter : public Painter {
public:
	StraightLine* createObject() const override { return new StraightLine(2); }
	~StraightLinePainter() {};
};
class CurvedLinePainter : public Painter {
public:
	CurvedLine* createObject() const override { return new CurvedLine(1,3); }
	~CurvedLinePainter() {};
};
int main(){
	Painter* painter = new CirclePainter();
	painter->draw();
	painter->drawObject(new Circle(3));
	painter->printMyWork();
	delete painter;
	return 0;
}
