#include<iostream>

// 类接口定义——纯虚函数——ADT
// 1.纯虚函数是必须在子类中重写的虚函数
// 2.包含一个或多个纯虚函数的类都是 ADT，不能对他实例化。
// 3.继承自 ADT 但是没有重写实现完所有的纯虚函数时，都是不能实例化的。
class Shape
{
public:
    Shape() { } ;
    virtual ~Shape() {} ;
    virtual long getArea() const = 0 ;
    virtual long getPerim() const = 0 ;
    virtual void draw() const = 0 ;
};
void Shape::draw() const
{
    std::cout << "Abstract drawing mechanism\n";
}

// 继承的多态父类
class Rectangle : public Shape
{
public:
    Rectangle( int newLength, int newWidth ):
        length(newLength),
        width(newWidth) {};
    virtual ~Rectangle() {};
    long getArea() const { return length * length; }
    long getPerim() const { return (2 * length) + (2 * width); }
    virtual int getLength() const { return length; }
    virtual int getWidth() const { return width; }
    void draw() const ;
private:
    int width;
    int length;
};
void Rectangle :: draw() const
{
    for (int i = 0; i < length; i++)
    {
        for(int j = 0; j < width; j++)
        {
            std::cout << "x ";
        }
        std::cout << "\n";
    }
    // 调用父类实现的成员方法
    Shape::draw();
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
    long getArea() const { return 3 * radius * radius; } 
    long getPerim() const { return 6 * radius; }
    void draw() const;
};
void Circle :: draw() const
{
    std::cout << "Circle drawing routing here\n";
    // 调用父类实现的成员方法
    Shape::draw();
}

// 继承的子类 Square
class Square : public Rectangle
{
public:
    Square(int len);
    ~Square() {}
    long getPerim() const { return 4 * getLength(); }
};
Square :: Square( int newLen):
    Rectangle(newLen, newLen)
{ }

int main(int argc, char const *argv[])
{
    // 不能实例化 ADT
    // Shape * sp = new Shape;
    // sp->draw();

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

