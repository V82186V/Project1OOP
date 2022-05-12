#include "Init.h"

void Init::start()
{
    hotel.read();
    cout << "1 - Guest registration" << endl
         << "2 - Available rooms" << endl
         << "3 - Freeing room" << endl
         << "4 - Check usage of rooms during days" << endl
         << "5 - Finding available room" << endl
         << "6 - Making a room unavailable" << endl;
    int option = 0;
    try{
        do {
            cin >> option;
            if(option == 1)
            {
                unsigned int number;
                int day,month,year;
                char name[25];
                cin >> number >> day >> month >> year;
                Date start(year,month,day);
                cin >> day >> month >> year;
                Date end(year,month,day);
                cin >> name;
                hotel.guestRegistration(number,start,end,name);
            }
            else if(option == 2)
            {
                int day,month,year;
            }
        }while(option < 0 || option > 6);
    }catch(const std::exception &e)
    {
        cout << e.what();
    }
}

