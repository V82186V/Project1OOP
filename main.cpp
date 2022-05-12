#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
    cout << "1 - Guest registration" << endl
         << "2 - Available rooms" << endl
         << "3 - Freeing room" << endl
         << "4 - Check usage of rooms during days" << endl
         << "5 - Finding available room" << endl
         << "6 - Making a room unavailable" << endl;
    int option = 0;
    do {
        cin >> option;
    }while(option < 0 || option > 6);

    return 0;
}
