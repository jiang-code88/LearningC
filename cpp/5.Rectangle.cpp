#include<iostream>

// 重载成员函数

class Rectangle
{
private:
    int width;
    int height;
public:
    // 无参构造函数声明和实现
    Rectangle(){ width = 5; height = 5;}
    // 有参构造函数声明
    Rectangle(int width, int height);
    ~Rectangle();

    void drawShape() const;
    void drawShape(int width, int height) const;
};

// 有参构造函数实现
Rectangle::Rectangle(int newWidth, int newHeight)
{
    width = newWidth;
    height = newHeight;
}

// 析构函数
Rectangle::~Rectangle()
{}

// 成员函数
void Rectangle::drawShape() const
{
    drawShape(width, height);
}
// 重载成员函数
void Rectangle::drawShape(int width, int height) const
{
    for( int i = 0; i < height; i++ )
    {
        for( int j = 0; j < width; j++){
            std::cout << "*";
        }
        std::cout << "\n";
    }
}


int main(int argc, char const *argv[])
{
    // 根据函数参数列表的不同，自动选择不同的重载函数执行。
    Rectangle box1(30, 5);
    Rectangle box2;
    std::cout << "drawShape(): \n";
    box1.drawShape();
    std::cout << "\n drawShape(40,2): \n";
    box1.drawShape(40,2);
    std::cout << "\n constructor's drawShap(): \n";
    box2.drawShape();
    return 0;
}

