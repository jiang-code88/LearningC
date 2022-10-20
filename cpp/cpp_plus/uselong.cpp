#include <iostream>
int main()
{
    using namespace std;
    int  receipts = 560334;     // 32-bits
    long also = 560334;         // 32-bits
    cout << "receipts: " << receipts << endl; // 560334
    cout << "alse: " << also << endl;         // 560334

    short receipts_1 = 560334;  // 16-bits
    long also_1 = 560334;       // 32-bits
    cout << "receipts_1: " << receipts_1 << endl; // -29490
    cout << "alse_1: " << also_1 << endl;         // 560334

    return 0;
} 
