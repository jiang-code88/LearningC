#include <iostream>
// 创建和使用引用
int main(int argc, char const *argv[])
{
    int intOne;
    // rSomeRef 是变量 intOne 的一个引用，是变量 intOne 的别名，其被初始化为指向 intOne。
    // 1.声明了引用后一定要初始化它。
    // 2.不能给引用本身重新赋值，引用始终是目标变量的别名，赋值最终也是对引用所指向的变量赋值。
    int &rSomeRef = intOne;

    intOne = 5;
    std::cout << "intOne: " << intOne <<".\n"; // 5
    std::cout << "rSomeRef: " << rSomeRef <<".\n"; // 5

    rSomeRef = 7;
    std::cout << "intOne: " << intOne <<".\n"; // 7
    std::cout << "rSomeRef: " << rSomeRef <<".\n"; // 7

    // 引用与变量的地址是相同的
    std::cout << "&intOne: " << &intOne << ".\n"; // &intOnde: 0x61fe14.
    std::cout << "&rSomeRef: " << &rSomeRef << ".\n";// &rSomeRef: 0x61fe14.

    int intTwo = 8;
    rSomeRef = intTwo; // 等价于 intOne = intTwo;
    std::cout << "intOne: " << intOne <<".\n"; // 8
    std::cout << "intTwo: " << intTwo <<".\n"; // 8
    std::cout << "rSomeRef: " << rSomeRef <<".\n"; // 8
    std::cout << "&intOne: " << &intOne <<".\n"; // 0x61fe14.
    std::cout << "&intTwo: " << &intTwo <<".\n"; // 0x61fe10.
    std::cout << "&rSomeRef: " << &rSomeRef <<".\n"; // 0x61fe14.

    return 0;
}
