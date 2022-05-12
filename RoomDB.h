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
    RoomDB();
    RoomDB(Date start, Date end, int status, char* name, char* note = nullptr);
    RoomDB(Date start, Date end);
    RoomDB(const RoomDB& other);
    RoomDB& operator=(const RoomDB& other);
    ~RoomDB();
    Date getStart() const;
    Date getEnd() const;
    int getStatus() const;
    bool overlap(Date from, Date to);
};

#endif //PROJECT1_ROOMDB_H
