#include<iostream>

// 函数返回多个值

// 1.按指针,参数返回多个值
int factor( int, int*, int* );

// 2.按引用,参数返回多个值
enum ERR_CODE { SUCCESS, ERROR };

ERR_CODE factor( int, int&, int& );

int main(int argc, char const *argv[])
{
    // 使用枚举改造调用函数的调用结果返回值
    int number, squared, cubed;
    ERR_CODE result;

    std::cout << "Enter a number ( 0-20 ): ";
    std::cin >> number;

    result = factor( number, squared, cubed );

    if( result == SUCCESS )
    {
        std::cout << " number: " << number << "\n";
        std::cout << " squared: " << squared << "\n";
        std::cout << " cubed: " << cubed << "\n";
    }
    else
    {
        std::cout << "Error encountered!!\n";
    }   

    // 调用函数通过返回 0 / 1 返回调用结果
    /* int number, squared, cubed;
    short error;

    std::cout << "Enter a number ( 0-20 ): ";
    std::cin >> number;

    error = factor( number, &squared, &cubed );

    if( !error )
    {
        std::cout << " number: " << number << "\n";
        std::cout << " squared: " << squared << "\n";
        std::cout << " cubed: " << cubed << "\n";
    }
    else
    {
        std::cout << "Error encountered!!\n";
    } */

    return 0;
}

int factor( int n, int *pSquared, int *pCubed )
{
    int value = 0;
    if( n > 20 )
    {
        value = 1;
    }
    else
    {  
        *pSquared = n * n;
        *pCubed = n * n * n;
        value = 0;
    }
    return value;
}

ERR_CODE factor( int n, int &rSquared, int &rCubed )
{
    if( n > 20 )
    {
        return ERROR;
    }
    else
    {  
        rSquared = n * n;
        rCubed = n * n * n;
        return SUCCESS;
    }
}
