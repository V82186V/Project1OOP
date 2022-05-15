#include "Init.h"

void Init::start()
{
    hotel.read(); ///Get info from file
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
            if(option == 1) ///Guest registration
            {
                unsigned int number;
                int day,month,year;
                char name[25];
                cout << "Enter number, start day, month, year: ";
                cin >> number >> day >> month >> year;
                Date start(year,month,day);
                cout << "Enter end day, month, year: ";
                cin >> day >> month >> year;
                Date end(year,month,day);
                cout << "Enter name: ";
                cin >> name;
                hotel.guestRegistration(number,start,end,name);
            }
            else if(option == 2) ///Checking availability
            {
                int day,month,year;
                cout << "Enter day, month, year: ";
                cin >> day >> month >> year;
                Date date(year,month,day);
                hotel.availableRoom(date);
            }
            else if(option == 3) ///Making a room free
            {
                int number;
                cout << "Enter number of room you want to free: ";
                cin >> number;
                hotel.freeingRoom(number);
            }
            else if(option == 4) ///Check usage of rooms
            {
                int day,month,year;
                cout << "Enter start day, month, year: ";
                cin >> day >> month >> year;
                Date start(year,month,day);
                cout << "Enter end day, month, year: ";
                cin >> day >> month >> year;
                Date end(year,month,day);
                hotel.check(start,end);
            }
            else if(option == 5) ///Find available room
            {
                int day,month,year;
                cout << "Enter start day, month, year: ";
                cin >> day >> month >> year;
                Date start(year,month,day);
                cout << "Enter end day, month, year: ";
                cin >> day >> month >> year;
                Date end(year,month,day);
                hotel.find(start,end);
            }
            else if(option == 6) ///Make room unavailable for service
            {
                int number;
                cout << "Enter number: ";
                cin >> number;
                int day,month,year;
                cout << "Enter start day, month, year: ";
                cin >> day >> month >> year;
                Date start(year,month,day);
                cout << "Enter end day, month, year: ";
                cin >> day >> month >> year;
                Date end(year,month,day);
                hotel.close(start,end, number);
            }
        }while(option < 0 || option > 6);
    }catch(const std::exception &e)
    {
        cout << e.what();
    }
}

