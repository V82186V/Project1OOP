
#include "RoomDB.h"

RoomDB::RoomDB() {
    this->start = nullptr;
    this->end = nullptr;
    this->name = nullptr;
    this->note = nullptr;
}

RoomDB::RoomDB(Date start, Date end, int status, char *name, char *note) {
    this->start = new Date(start);
    this->end = new Date(end);
    this->status = status;
    if (note) {
        this->note = new char[strlen(note) + 1];
        strcpy(this->note, note);
    } else this->note = nullptr;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

RoomDB::RoomDB(Date start, Date end) {
    this->start = new Date(start);
    this->end = new Date(end);
    this->name = nullptr;
    this->note = nullptr;
}

RoomDB::RoomDB(const RoomDB &other) {
    this->start = new Date(*other.start);
    this->end = new Date(*other.end);
    this->status = other.status;
    if (other.note) {
        delete note;
        this->note = new char[strlen(other.note) + 1];
        strcpy(this->note, other.note);
    } else this->note = nullptr;
    delete name;
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);
}

Date RoomDB::getStart() const {
    return *this->start;
}

Date RoomDB::getEnd() const {
    return *this->end;
}

RoomDB &RoomDB::operator=(const RoomDB &other) {
    if (this != &other) {
        this->start = new Date(*other.start);
        this->end = new Date(*other.end);
        this->status = other.status;
        if (other.note) {
            delete note;
            this->note = new char[strlen(other.note) + 1];
            strcpy(this->note, other.note);
        } else this->note = nullptr;
        delete name;
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
    }
    return *this;
}

RoomDB::~RoomDB() {
    delete start;
    delete end;
    delete[] name;
    delete[] note;
}

int RoomDB::getStatus() const {
    return this->status;
}

bool RoomDB::overlap(Date from, Date to) {
    if ((from < *start && to > *start) || (from > *start && to < *end) || (from < *end && to > *end)) return true;
    return false;
}