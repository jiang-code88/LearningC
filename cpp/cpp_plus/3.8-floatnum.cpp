#include <iostream>
int main()
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    float tub = 10.0 / 3.0 ;        // 3.3333333333333333333.....
    double mint = 10.0 / 3.0 ;      // 3.3333333333333333333.....
    const float million = 1.0e6 ;   // 1000,000

    cout << "tub = " << tub << endl; // 打印 7 位（6 位有效数字）- 无误差
    cout << "a million tubs = " << million * tub << endl; // 打印 7 + 6 位（13位）（6 位有效数字）
    cout << "the ten million tubs = " << 10 * million * tub << endl; // 打印 8 + 6 位（14位）（6 位有效数字）

    cout << "mint = " << mint << endl; // 打印 7 位 （15 位有效数字）
    cout << "a million tubs = " << million * mint << endl; // 打印 7 + 6 （13位）（15 位有效数字）
    cout << "the tem million tubs = " << 10 * million * mint << endl; // 打印 8 + 6 （14位）（15 位有效数字）

    cout << "the million million tubs = " << 10 * 10 * million * mint << endl;// 打印 9 + 6 （15位）（15 位有效数字）
    cout << "the million million tubs = " << 10 * 10 * 10 * million * mint << endl;// 打印 10 + 6 （16位）（15 位有效数字）- 无误差
    cout << "the million million tubs = " << 10 * 10 * 10 * 10 * million * mint << endl;// 打印 11 + 6 （17位）（15 位有效数字）
    
    return 0;
}