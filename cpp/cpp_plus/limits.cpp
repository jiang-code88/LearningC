#include <iostream>
#include <climits>
int main()
{
    using namespace std;

    int n_int = INT_MAX;
    short n_short = SHRT_MAX;
    long n_long = LONG_MAX;
    long long n_llong = LONG_LONG_MAX;

    cout << "int is " << sizeof(int) << " bytes." << endl;      // int is 4 bytes.  
    cout << "short is " << sizeof n_short << " bytes." << endl; // short is 2 bytes.
    cout << "long is " << sizeof n_long << " bytes." << endl;   // long is 4 bytes. 
    cout << "long is " << sizeof n_llong << " bytes." << endl;  // long is 8 bytes.
    cout << "----------------------------------" << endl;

    cout << "Maximum values: " << endl;     
    cout << "int: " << n_int << endl;           // 2147483647
    cout << "short: " << n_short << endl;       // 32767
    cout << "long: " << n_long << endl;         // 2147483647
    cout << "long long: " << n_llong << endl;   // 9223372036854775807
    cout << "----------------------------------" << endl;

    cout << "Minimum values: " << endl;
    cout << "int: " << INT_MIN << endl;         // -2147483648
    cout << "----------------------------------" << endl;

    cout << "Bits per byte = " << CHAR_BIT << " bits." <<  endl; // Bits per byte = 8 bits.
    cout << "----------------------------------" << endl;

    return 0;
}