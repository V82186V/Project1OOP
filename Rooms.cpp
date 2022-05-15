#include "Rooms.h"

Room::Room(unsigned int number, unsigned int beds) {
    this->number = number;
    this->beds = beds;
    this->size = 0;
    this->capacity = 1;
    this->dates = nullptr;
}

Room::Room(const Room &other) {
    this->number = other.number;
    this->beds = other.beds;
    this->size = other.size;
    this->capacity = other.capacity;
    this->dates = new RoomDB[capacity];
    for (int i = 0; i < size; ++i) {
        this->dates[i] = other.dates[i];
    }
}

Room &Room::operator=(const Room &other) {
    if (this != &other) {
        this->number = other.number;
        this->beds = other.beds;
        this->size = other.size;
        this->capacity = other.capacity;
        this->dates = new RoomDB[capacity];
        for (int i = 0; i < size; ++i) {
            this->dates[i] = other.dates[i];
        }
    }
    return *this;
}

void Room::resize() {
    capacity *= 2;
    RoomDB *newDates = new RoomDB[capacity];
    for (int i = 0; i < size; ++i) {
        newDates[i] = dates[i];
    }
    delete[] dates;
    dates = newDates;
}

Room::~Room() {
    delete[] dates;
}

unsigned int Room::getNumber() const {
    return this->number;
}

bool Room::isFree(Date date) const {
    for (int i = 0; i < size; ++i) {
        if (dates[i].getStart() < date && date < dates[i].getEnd()) continue;
        else return true;
    }
    return false;
}

void Room::free() {
    this->size = 0;
    this->capacity = 1;
    delete[] dates;
}

void Room::getDate(Date from, Date to) const {
    for (int i = 0; i < size; ++i) {
        if (from < dates[i].getStart() && to < dates[i].getEnd()) {
            std::cout << this->number << " " << diff(from, to) << std::endl;
        } else if (dates[i].getStart() < from && dates[i].getEnd() < to) {
            std::cout << this->number << " " << diff(from, dates[i].getEnd()) << std::endl;
        } else if (dates[i].getStart() > from && dates[i].getEnd() < to) {
            std::cout << this->number << " " << diff(dates[i].getStart(), dates[i].getEnd()) << std::endl;
        }
    }
}

void Room::add(Date from, Date to, int status, char *name, char *note) {
    if (!dates) {
        dates = new RoomDB[capacity];
    }
    if (size == capacity) {
        resize();
    }
    for (int i = 0; i < size; ++i) {
        if (dates[i].overlap(from, to)) throw std::invalid_argument("Room unavailable");
    }
    RoomDB temp(from, to, status, name, note);
    dates[size] = temp;
    size++;
}

int Room::find(Date from, Date to, int &index) const {
    for (int i = 0; i < size; ++i) {
        if (dates[i].getStart() > from && dates[i].getEnd() < to) {
            index = number;
            return this->beds;
        }
    }
    return -1;
}


