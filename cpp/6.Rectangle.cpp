#include<iostream>

// 使用函数参数的默认值
class Rectangle
{
private:
    int width;
    int height;
public:
    Rectangle();
    Rectangle( int width, int height );
    ~Rectangle(){} //内联实现析构函数
    // 函数声明赋予默认值
    void drawShap( int aWidth, 
                   int aHeight, 
                   bool useDefaultValue = false) const;
};

Rectangle::Rectangle( int aWidth, int aHeight )
{
    width = aWidth;
    height = aHeight;
}

void Rectangle::drawShap( 
        int aWidth, 
        int aHeight, 
        bool useDefaultValue ) const
{
    int printWidth;
    int printHeight;
    if( useDefaultValue )
    {
        printWidth = width;
        printHeight = height;
    }
    else
    {
        printWidth = aWidth;
        printHeight = aHeight;
    }
    for( int i = 0; i < printHeight; i++ )
    {
        for( int j = 0; j < printWidth; j++){
            std::cout << "*";
        }
        std::cout << "\n";
    }
}

int main(int argc, char const *argv[])
{
    
    Rectangle box(20,5);
    
    std::cout << "drawShap(5, 5, false) \n";
    box.drawShap(5,5); // 默认 false 使用当前调用函数传入的值

    std::cout << "drawShap(0, 0, true) \n";
    box.drawShap(5,5,true); // true 指定使用有参构造传入的width和height

    return 0;
}


