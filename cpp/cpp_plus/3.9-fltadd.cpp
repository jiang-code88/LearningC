#include <iostream>
int main()
{
    using namespace std;
    float a = 123.456f;     // 123.456
    float b = a + 1.0f;     // b-a = 1

    float a_1 = 123456789.0f;   // 1.23457e+08
    float b_1 = a_1 + 1.0f;     // b-a = 0

    float a_2 = 2.34E+22f;  // 2.34e+22
    float b_2 = a_2 + 1.0f; // b-a = 0

    cout << "a = " << a_2 << endl;
    cout << "b = " << b_2 << endl;
    cout << "b - a = " << b_2-a_2 << endl;
    return 0;
}