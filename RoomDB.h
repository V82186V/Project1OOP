#ifndef PROJECT1_ROOMDB_H
#define PROJECT1_ROOMDB_H

#include "Date.h"
#include <cstring>

class RoomDB{
private:
    Date* start;
    Date* end;
    char* note;
    char* name;
    int status;
public:
    ///Default constructor with no parameters
    RoomDB();
    ///Constructor with 5 parameters
    RoomDB(Date start, Date end, int status, char* name, char* note = nullptr);
    ///Copy constructor
    RoomDB(const RoomDB& other);
    ///Overload operator =
    RoomDB& operator=(const RoomDB& other);
    ///Destructor
    ~RoomDB();
    ///Getter for start date
    Date getStart() const;
    ///Getter for end date
    Date getEnd() const;
    ///Function to check if dates overlap
    bool overlap(Date from, Date to);
};

#endif //PROJECT1_ROOMDB_H
