#include <iostream>
int main()
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    float begin, end;
    // double begin, end;
    cout << "Enter a number: ";
    cin >> begin;
    cout << "Enter another number: ";
    cin >> end;

    cout << "begin = " << begin << "  " << "end = " << end << endl;
    cout << "begin + end = " << begin + end << endl;
    cout << "begin - end = " << begin - end << endl;
    cout << "begin * end = " << begin * end << endl;
    cout << "begin / end = " << begin / end << endl;

    return 0;
}