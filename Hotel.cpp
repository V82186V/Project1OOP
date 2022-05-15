#include "Hotel.h"

Hotel::Hotel() {
    this->hotel = nullptr;
    this->roomCapacity = 0;
}

Hotel::Hotel(int roomCapacity) {
    this->roomCapacity = roomCapacity;
    this->hotel = new Room *[roomCapacity];
}

Hotel::Hotel(Room *hotel, int roomCapacity) {
    this->roomCapacity = roomCapacity;
    this->hotel = new Room *[roomCapacity];
    for (int i = 0; i < roomCapacity; ++i) {
        this->hotel[i] = new Room(hotel[i]);
    }
}

Hotel::~Hotel() {

    for (int i = 0; i < roomCapacity; ++i) {
        if (hotel[i]) delete this->hotel[i];
        else break;
    }
    delete[] this->hotel;

}

void Hotel::guestRegistration(unsigned int number, Date start, Date end, char *name) {
    if (roomCapacity == 0) throw std::invalid_argument("No rooms initialized");
    for (int i = 0; i < roomCapacity; ++i) {
        if (hotel[i]->getNumber() == number) {
            std::cout << "Do you want a note?(0-yes,other-no)";
            int temp;
            std::cin >> temp;
            char* note = nullptr;
            if(temp == 0)
            {
                std::cout << "Enter note: " << std::endl;
                note = new char[1024];
                std::cin >> note;
            }
            hotel[i]->add(start,end,1,name,note);
        }
    }
}

void Hotel::availableRoom(Date date)
{
    for (int i = 0; i < roomCapacity; ++i) {
        if(hotel[i]->isFree(date)) std::cout << hotel[i]->getNumber();
    }
}

void Hotel::freeingRoom(unsigned int number)
{
    for (int i = 0; i < roomCapacity; ++i) {
        if(hotel[i]->getNumber() == number)
        {
            hotel[i]->free();
            break;
        }
    }
}

void Hotel::check(Date from, Date to)
{
    for (int i = 0; i < roomCapacity; ++i) {
        hotel[i]->getDate(from,to);
    }
}

void Hotel::find(Date from, Date to)
{
    int minID=-1;
    int minBeds = INT_MAX;
    int x,result;
    for (int i = 0; i < roomCapacity; ++i) {
        x = hotel[i]->find(from,to,minID);
        if(x < minBeds) result = minID;
    }
    std::cout << result << std::endl;
}

void Hotel::close(Date from, Date to, int number)
{
    for (int i = 0; i < roomCapacity; ++i) {
        if(hotel[i]->getNumber() == number){
            char buffer[1024];
            std::cin >> buffer;
            hotel[i]->add(from,to,2,"Service",buffer);
            break;
        }
    }
}

void Hotel::read(){
    std::ifstream reader("data.txt");
    if(!reader.is_open()) throw std::invalid_argument("Cannot open file");
    char buffer[1024];
    reader >> buffer;
    this->roomCapacity = std::stoi(buffer);
    this->hotel = new Room*[roomCapacity];
    int num,size,i=0;
    while(reader >> num >> size)
    {
        this->hotel[i] = new Room(num,size);
        i++;
    }
    reader.close();
}