#ifndef ROOMS_H
#define ROOMS_H

#include <iostream>
#include "Date.h"
#include <cstring>
#include "RoomDB.h"

class Room
{
private:
    unsigned int number;
    unsigned int beds;
    RoomDB* dates;
    int size;
    int capacity;
    void resize();
public:
    ///Copy constructor
    Room(const Room& other);
    ///Overload operator =
    Room& operator=(const Room& other);
    ///Destructor
    ~Room();
    ///Constructor with 2 parameters
    Room(unsigned int number, unsigned int beds);
    ///Getter for the room number
    unsigned int getNumber() const;
    ///Check if the room is free during dates
    bool isFree(Date date) const;
    ///Make a room free
    void free();
    ///Helper function for check function
    void getDate(Date from, Date to) const;
    ///Helper function for Guest registration and Closing of room functions
    void add(Date from, Date to,int status, char* name, char* note = nullptr);
    ///Finding room with lowest amount of beds
    int find(Date from, Date to, int& index) const;
};

#endif //ROOMS_H
