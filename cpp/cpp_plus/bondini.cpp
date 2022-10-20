#include <iostream>
#include <cfloat>
int main()
{
    using namespace std;
    cout << "\aOperation \"HyperHype\" is now activated! \n";
    cout << "Enter your agent code:_____\b\b\b\b\b";
    int code;
    cin >> code;
    cout << "\aYou entered " << code << "...\n";
    cout << "\aCode verified! Proceed with Plan z3!\n";

    bool is_ready = true;
    int ans = true;
    int promise = false;
    cout << "is_ready: " << is_ready << endl;
    cout << "ans: " << ans << endl;
    cout << "promise: " << promise << endl;

    bool start = -100; 
    bool stop = 0;
    cout << "start: " << start << endl;
    cout << "stop: " << stop << endl;

    return 0;
}