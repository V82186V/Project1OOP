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
    Room(const Room& other);
    Room& operator=(const Room& other);
    ~Room();
    Room(unsigned int number, unsigned int beds);
    unsigned int getNumber() const;
    unsigned int getBeds() const;
    bool isFree(Date date) const;
    void free();
    void getDate(Date from, Date to) const;
    void add(Date from, Date to,int status, char* name, char* note = nullptr);
    int find(Date from, Date to, int& index) const;
};

#endif //ROOMS_H
