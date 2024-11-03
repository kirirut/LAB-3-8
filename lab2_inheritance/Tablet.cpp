#include "Tablet.h"
#include "PortableComputer.h"
#include<iomanip>

// Конструктор по умолчанию
Tablet::Tablet() : SIM(false), Gyroscope(false), ports(0) {}

// Конструктор с параметрами
Tablet::Tablet(double CPUcapacity, double RAM, int DiskSpace, double DisplaySize, const std::string& Resolution, int BatteryCapacity,
    bool SIM, bool Gyroscope, int ports)
    : PortableComputer(CPUcapacity, RAM, DiskSpace, DisplaySize, Resolution, BatteryCapacity),
    SIM(SIM), Gyroscope(Gyroscope), ports(ports) {}

// Конструктор копирования
Tablet::Tablet(const Tablet& other)
    : PortableComputer(other), SIM(other.SIM), Gyroscope(other.Gyroscope), ports(other.ports) {}

// Оператор присваивания
Tablet& Tablet::operator=(const Tablet& other) {
    if (this != &other) {
        PortableComputer::operator=(other); // Присваиваем данные базового класса
        SIM = other.SIM;
        Gyroscope = other.Gyroscope;
        ports = other.ports;
    }
    return *this;
}

// Деструктор
Tablet::~Tablet() {}

// Геттеры и сеттеры
bool Tablet::GetSIM() const {
    return SIM;
}

void Tablet::SetSIM(bool newSIM) {
    SIM = newSIM;
}

bool Tablet::GetGyroscope() const {
    return Gyroscope;
}

void Tablet::SetGyroscope(bool newGyroscope) {
    Gyroscope = newGyroscope;
}

int Tablet::GetPorts() const {
    return ports;
}

void Tablet::SetPorts(int newPorts) {
    ports = newPorts;
}

// Перегрузка оператора вывода
std::ostream& operator<<(std::ostream& os, Tablet& tablet) {
    os << static_cast<PortableComputer&>(tablet);

    // Форматированный вывод данных планшета
    os 
        << std::left << std::setw(20) << "SIM Support:" << std::right << std::setw(10) << (tablet.SIM ? "Yes" : "No") << std::endl
        << std::left << std::setw(20) << "Gyroscope:" << std::right << std::setw(10) << (tablet.Gyroscope ? "Yes" : "No") << std::endl
        << std::left << std::setw(20) << "Number of Ports:" << std::right << std::setw(10) << tablet.ports << std::endl;
    return os;
}

// Перегрузка оператора ввода
std::istream& operator>>(std::istream& is, Tablet& tablet) {
    is >> static_cast<PortableComputer&>(tablet); // Ввод данных базового класса
    std::cout << "SIM Support (1 - Yes, 0 - No): ";
    is >> tablet.SIM;
    std::cout << "Gyroscope (1 - Yes, 0 - No): ";
    is >> tablet.Gyroscope;
    std::cout << "Number of Ports: ";
    is >> tablet.ports;
    return is;
}
