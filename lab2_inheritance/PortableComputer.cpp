#include "PortableComputer.h"
#include "ComputingMachine.h"
#include<iomanip>
// Конструктор по умолчанию
PortableComputer::PortableComputer()
    : ComputingMachine(), DisplaySize(0), Resolution(""), BatteryCapacity(0) {}

// Конструктор с параметрами
PortableComputer::PortableComputer(double CPUcapacity, double RAM, int DiskSpace, int DisplaySize, const std::string& Resolution, int BatteryCapacity)
    : ComputingMachine(CPUcapacity, RAM, DiskSpace), DisplaySize(DisplaySize), Resolution(Resolution), BatteryCapacity(BatteryCapacity) {}

// Конструктор копирования
PortableComputer::PortableComputer(const PortableComputer& other)
    : ComputingMachine(other), DisplaySize(other.DisplaySize), Resolution(other.Resolution), BatteryCapacity(other.BatteryCapacity) {}

// Оператор присваивания
PortableComputer& PortableComputer::operator=(const PortableComputer& other) {
    if (this == &other) {
        return *this; // Защита от самоприсваивания
    }

    ComputingMachine::operator=(other); // Присваивание базового класса
    DisplaySize = other.DisplaySize;
    Resolution = other.Resolution;
    BatteryCapacity = other.BatteryCapacity;

    return *this;
}

// Деструктор
PortableComputer::~PortableComputer() {
    // Освобождение ресурсов, если это необходимо
}

// Геттер для DisplaySize
int PortableComputer::GetDisplaySize() const {
    return DisplaySize;
}

// Сеттер для DisplaySize
void PortableComputer::SetDisplaySize(int newDisplaySize) {
    DisplaySize = newDisplaySize;
}

// Геттер для Resolution
std::string PortableComputer::GetResolution() const {
    return Resolution;
}

// Сеттер для Resolution
void PortableComputer::SetResolution(const std::string& newResolution) {
    Resolution = newResolution;
}

// Геттер для BatteryCapacity
int PortableComputer::GetBatteryCapacity() const {
    return BatteryCapacity;
}

// Сеттер для BatteryCapacity
void PortableComputer::SetBatteryCapacity(int newBatteryCapacity) {
    BatteryCapacity = newBatteryCapacity;
}

// Перегрузка вывода
std::ostream& operator<<(std::ostream& os, PortableComputer& pc) {
    // Вывод данных базового класса (ComputingMachine)
    os << static_cast< ComputingMachine&>(pc);
    // Форматированный вывод данных портативного компьютера
    os << std::left << std::setw(20) << "\nDisplay Size:" << std::right << std::setw(10) << pc.GetDisplaySize() << " inches" << std::endl
        << std::left << std::setw(20) << "Resolution:" << std::right << std::setw(10) << pc.GetResolution() << std::endl
        << std::left << std::setw(20) << "Battery Capacity:" << std::right << std::setw(10) << pc.GetBatteryCapacity() << " mAh" << std::endl;

    return os;
}

// Перегрузка ввода
std::istream& operator>>(std::istream& is, PortableComputer& pc) {
    is >> static_cast<ComputingMachine&>(pc); // Ввод данных базового класса

    std::cout << "Enter Display Size (inches): ";
    is >> pc.DisplaySize;
    
    std::cout << "Enter Resolution: ";
    is >> pc.Resolution;

    std::cout << "Enter Battery Capacity (mAh): ";
    is >> pc.BatteryCapacity;

    return is;
}