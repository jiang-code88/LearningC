#include <iostream>
int main()
{
    using namespace std;
    char ch;

    cout << "Enter a character: " << endl;
    cin >> ch;

    cout << "Hola! ";
    cout << "Thank you for the " << ch << " character." << endl; 

    int i = ch;
    cout << "The ASCII code for " << ch << " is " << i << endl;

    return 0;
}