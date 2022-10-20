#include <iostream>
#include <string>   // make string class available
#include <cstring>  // c-style string library
using namespace std;
int main()
{
    char charr1[20];
    char charr2[20] = "charArray"; // 9
    char charr3[20];

    string str1;
    string str2 = "string"; // 6
    string str3;
    string str4;

    str1 = str2;
    strcpy(charr1,charr2);

    str1 += str2;
    strcat(charr1,charr2);

    int len_str = str1.size();
    int len_char = strlen(charr1); // 函数strlen( )从数组的第一个元素开始计算字节数，直到遇到空字符

    cout << "The string " << str1 << " contains " << len_str << " characters." << endl;
    cout << "The string " << charr1 << " contains " << len_char << " characters." << endl;


    char site[10] = "house"; // 5
    // strcpy(site,"yes of cource."); // 14 // 覆盖相邻的内存。这可能导致程序终止，或者程序继续运行，但数据被损坏。
    // cout << "The string site: "<< site << endl;
    strncpy(site,"1234567890",9); // 接受指出目标数组最大允许长度的第三个参数
    cout << "The string site: "<< site << endl;

    // 整行输入
    cout << "Enter a line of text: " << endl;
    cin.getline(charr3,30);
    cout << "Your entered: " << charr3 << endl;

    cout << "Enter another line of text: " << endl;
    getline(cin,str3);
    cout << "Your entered: " << str3 << endl;

    cout << "Enter other line of text: " << endl;
    cin >> str4;
    cout << "the first word of your entered line: " << str4 << endl;

    return 0;
}