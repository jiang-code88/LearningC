#include<iostream>
// 多态父类
class Shape
{
public:
    Shape() { };
    virtual ~Shape() {};
    virtual long getArea() { return -1; } // error
    virtual long getPerim() { return -1; } // error
    virtual void draw() { std::cout << "draw a shape !\n"; }
};

// 继承的多态父类
class Rectangle : public Shape
{
public:
    Rectangle( int newLength, int newWidth ):
        length(newLength),
        width(newWidth) {};
    virtual ~Rectangle() {};
    virtual long getArea() { return length * length; }
    virtual long getPerim() { return (2 * length) + (2 * width); }
    virtual int getLength() { return length; }
    virtual int getWidth() { return width; }
    virtual void draw() ;
private:
    int width;
    int length;
};
void Rectangle :: draw()
{
    for (int i = 0; i < length; i++)
    {
        for(int j = 0; j < width; j++)
        {
            std::cout << "x ";
        }
        std::cout << "\n";
    }
}

// 继承的子类 Circle
class Circle : public Shape
{
private:
    long radius ; // 半径
    long circumference ; // 圆周
public:
    Circle( int newRadius ) : radius( newRadius ) {}
    ~Circle() {}
    long getArea() { return 3 * radius * radius; } 
    long getPerim() { return 6 * radius; }
    void draw();
};
void Circle :: draw()
{
    std::cout << "Circle drawing routing here\n";
}

// 继承的子类 Square
class Square : public Rectangle
{
public:
    Square(int len);
    ~Square() {}
    long getPerim() { return 4 * getLength(); }
};
Square :: Square( int newLen):
    Rectangle(newLen, newLen)
{ }

int main(int argc, char const *argv[])
{
    // 实例化父类
    Shape * sp = new Shape;
    sp->draw();

    // 实例化父类
    std::cout << "-----------------------\n";
    Shape * sp2 = new Rectangle(6,10);
    sp2->draw();

    // 实例化子类
    std::cout << "-----------------------\n";
    Shape * sp1 = new Circle(5);
    sp1->draw();

    // 实例化子类
    std::cout << "-----------------------\n";
    Shape * sp3 = new Square(5);
    sp3->draw();
    return 0;
}

