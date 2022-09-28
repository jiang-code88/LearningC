#include<iostream>
// 按引用传递函数参数
// 通过引用传递参数，可以让函数直接修改指向的对象
// 头文件和函数原型的作用：类的使用者依赖于头文件来获悉需要的所有信息，在 C++ 中头文件相当于类或函数的接口,而实际实现对使用者是隐蔽的。

// 1.函数是按值传参，无法操作
void swap( int x, int y );
// 2.使用指针完成操作
void PointerSwap( int *x, int *y);
// 3.使用引用完成操作(将常规变量方便易于使用和指针按引用传递的功能融为一体)
void ReferenceSwap( int &x, int &y );
int main(int argc, char const *argv[])
{
    int x = 5, y = 10;
    std::cout << "Main. Before swap, x: " << x << " y: " << y << "\n";
    swap(x,y);
    std::cout << "Main. After swap, x: " << x << " y: " << y << "\n";

    std::cout << "--------------------------------------------------\n";
    std::cout << "Main. Before swap, x: " << x << " y: " << y << "\n";
    PointerSwap(&x,&y);
    std::cout << "Main. After swap, x: " << x << " y: " << y << "\n";

    std::cout << "--------------------------------------------------\n";
    std::cout << "Main. Before swap, x: " << x << " y: " << y << "\n";
    ReferenceSwap(x,y);
    std::cout << "Main. After swap, x: " << x << " y: " << y << "\n";
    return 0;
}

void swap( int x, int y )
{
    int temp ;
    std::cout << "Swap. Before swap, x: " << x << " y: " << y << "\n";

    temp = x;
    x = y;
    y = temp;

    std::cout << "Swap. After swap, x: " << x << " y: " << y << "\n";
}

void PointerSwap( int *x, int *y)
{
    int temp ;
    std::cout << "Swap. Before swap, x: " << *x << " y: " << *y << "\n";

    temp = *x;
    *x = *y;
    *y = temp;

    std::cout << "Swap. After swap, x: " << *x << " y: " << *y << "\n";
}

void ReferenceSwap( int &rx, int &ry )
{
    int temp ;
    std::cout << "Swap. Before swap, x: " << rx << " y: " << ry << "\n";

    temp = rx;
    rx = ry;
    ry = temp;

    std::cout << "Swap. After swap, x: " << rx << " y: " << ry << "\n";
}
