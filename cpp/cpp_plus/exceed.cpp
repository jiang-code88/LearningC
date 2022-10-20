#include <iostream>
#include <climits>
#define ZERO 0
int main()
{
    using namespace std;

    short sam = SHRT_MAX;       // 32767
    unsigned short sue = sam;   // 32767
    cout << "Sam has " << sam << " dollars and sue has " << sue << " dollars." << endl;
    cout << "Add $1 to each account." << endl;
    sam = sam + 1;              // -32768
    sue = sue + 1;              // 32768
    cout << "Now ";
    cout << "Sam has " << sam << " dollars and sue has " << sue << " dollars." << endl;
    cout << "------------------------------------------" << endl;

    sam = ZERO;                 // 0
    sue = ZERO;                 // 0
    cout << "Sam has " << sam << " dollars and sue has " << sue << " dollars." << endl;
    cout << "Take $1 from each account." << endl;
    sam = sam - 1;              // -1
    sue = sue - 1;              // 65535
    cout << "Now ";
    cout << "Sam has " << sam << " dollars and sue has " << sue << " dollars." << endl;
    cout << "------------------------------------------" << endl;


    sue = 65535;
    cout << "Sue has " << sue << " dollars." << endl;
    cout << "Add $1 to sam's account. " << endl;
    sue = sue + 1;              // 0
    cout << "Now ";
    cout << "Sue has " << sue << " dollars." << endl;
    cout << "------------------------------------------" << endl;

    sam = -32768;
    cout << "Sam has " << sam << " dolloars" << endl;
    cout << "Take $1 from sam's accout. " << endl;
    sam = sam - 1;              // 32767
    cout << "Now ";
    cout << "Sam has " << sam << " dollars." << endl;
    cout << "------------------------------------------" << endl;

    sam = -1;
    cout << "Sam has " << sam << " dollars." << endl;
    cout << "Add $1 to sam's account." << endl;
    sam = sam + 1;              // 0
    cout << "Now ";
    cout << "Sam has " << sam << " dollars." << endl;
    cout << "------------------------------------------" << endl;

    return 0;
}