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
    Hotel();
    Hotel(int roomCapacity);
    Hotel(Room* hotel, int roomCapacity);
    ~Hotel();
    void guestRegistration(unsigned int number, Date start, Date end, char* name);
    void availableRoom(Date date);
    void freeingRoom(unsigned int number);
    void check(Date from, Date to);
    void find(Date from, Date to);
    void close(Date from, Date to, int number);
    void read();
    //void write();

};

#endif
