#ifndef PROJECT1_HOTEL_H
#define PROJECT1_HOTEL_H

#include <iostream>
#include <fstream>
#include "Rooms.h"
#include "Date.h"


class Hotel{
private:
    Room** hotel;
    int roomCapacity;
public:
    ///Default constructor without parameters
    Hotel();
    ///Initialize hotel as array from rooms
    Hotel(int roomCapacity);
    ///Initialize hotel as array from rooms and copies the rooms
    Hotel(Room* hotel, int roomCapacity);
    ///Destructor
    ~Hotel();
    ///Option 1-guest registration
    void guestRegistration(unsigned int number, Date start, Date end, char* name);
    ///Option 2-available room
    void availableRoom(Date date);
    ///Option 3-freeing a room
    void freeingRoom(unsigned int number);
    ///Option 4-check if room is free during period and return how many days its been used
    void check(Date from, Date to);
    ///Option 5-find a suitable room with minimal number of beds
    void find(Date from, Date to);
    ///Option 6-close a room for service
    void close(Date from, Date to, int number);
    ///Read info for rooms from file
    void read();
    //void write();

};

#endif
