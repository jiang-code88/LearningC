#include <iostream>
#include <cstring>
int main()
{
    using namespace std;
    int ArgSize = 3;
    char name[ArgSize];
    char dessert[ArgSize];
    char address[ArgSize];
    char describe[ArgSize];

    cout << "Enter your name: " << endl;  // 12
    // cin >> name;  // 1
    cin.getline(name,ArgSize); // 2
    // cin.get(name,ArgSize).get(); // 3

    cout << "Enter your favoriter dessert: " << endl; // 34
    // cin >> dessert;  // 1
    cin.getline(dessert,ArgSize); // 2
    // cin.get(dessert,ArgSize).get(); // 3

    cout << "Enter your address: " << endl; // '\n'
    cin.getline(address,ArgSize);  // 2
    // cin.get(address,ArgSize);
    // cin.clear(); // 消除空行带来失效位置，恢复读取输入。
    // cin.get(); // 将之前导致空行的剩下的换行符读取掉。 // 3

    cout << "Enter your describe: " << endl;  // 56
    cin.getline(describe,ArgSize); // 2
    // cin.get(describe,ArgSize).get();// 在重新的一行开始读取。// 3

    cout << "I have some delicious " << dessert << " for you " << name << "." << endl; 
    cout << "The letters length of name: " << strlen(name) << endl;
    cout << "The bytes size of name: " << sizeof(name) << endl;
    cout << "Your address: " << address << endl;
    cout << "Your describe: " << describe << endl;

    return 0;
}