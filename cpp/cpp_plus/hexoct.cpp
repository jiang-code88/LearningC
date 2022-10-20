#include <iostream> 
int main()
{
    using namespace std;
    int num_1 = 42;     // decimal integer literal
    int num_2 = 042;    // octal integer literal
    int num_3 = 0x42;   // hexadecimal integer literal 

    cout << "num_1: " << num_1 << " (42 in decimal )" << endl;       // 42
    cout << "num_2: " << num_2 << " (042 in octal)" << endl;         // 34
    cout << "num_3: " << num_3 << " (0x42 in hexadecimal)" << endl;  // 66
    cout << "--------------------------------------------" << endl;

    int num = 42;
    cout << "num_1: " << num << " (decimal for 42)" << endl;

    cout << oct;
    cout << "num_1: " << num << " (octal for 42)" << endl;
    
    cout << hex;
    cout << "num_1: " << num << " (hexadecimal for 42)" << endl;
    cout << "--------------------------------------------" << endl;

    return 0;
}