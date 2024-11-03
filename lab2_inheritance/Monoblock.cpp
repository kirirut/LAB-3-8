#include "Monoblock.h"
#include "StationaryComputer.h"
#include "Monoblock.h"
#include <iomanip>
// Конструктор по умолчанию
Monoblock::Monoblock()
    : StationaryComputer(), OS(""), weight(0) {}

// Конструктор с параметрами
Monoblock::Monoblock(double CPUcapacity, double RAM, int DiskSpace, int CPUcores, const std::string& MotherBoardChipset, const std::string& GPU, const std::string& OS, int weight)
    : StationaryComputer(CPUcapacity, RAM, DiskSpace, CPUcores, MotherBoardChipset, GPU), OS(OS), weight(weight) {}

// Конструктор копирования
Monoblock::Monoblock(const Monoblock& other)
    : StationaryComputer(other), OS(other.OS), weight(other.weight) {}

// Оператор присваивания
Monoblock& Monoblock::operator=(const Monoblock& other) {
    if (this == &other) {
        return *this; // Защита от самоприсваивания
    }

    StationaryComputer::operator=(other); // Присваивание базового класса
    OS = other.OS;
    weight = other.weight;

    return *this;
}

// Деструктор
Monoblock::~Monoblock() {
    // Освобождение ресурсов, если это необходимо
}

// Геттер для OS
std::string Monoblock::GetOS() const {
    return OS;
}

// Сеттер для OS
void Monoblock::SetOS(const std::string& newOS) {
    OS = newOS;
}

// Геттер для weight
int Monoblock::GetWeight() const {
    return weight;
}

// Сеттер для weight
void Monoblock::SetWeight(int newWeight) {
    weight = newWeight;
}

// Перегрузка вывода
std::ostream& operator<<(std::ostream& os, const Monoblock& mb) {
    os << static_cast<const StationaryComputer&>(mb);

    // Форматированный вывод данных моноблока
    os << std::left << std::setw(20) << "\nOperating System:" << std::right << std::setw(15) << mb.GetOS() << std::endl
        << std::left << std::setw(15) << "Weight:" << std::right << std::setw(15) << mb.GetWeight() << " kg" << std::endl
        << "--------------------------------";

    return os;
}

// Перегрузка ввода
std::istream& operator>>(std::istream& is, Monoblock& mb) {
    is >> static_cast<StationaryComputer&>(mb); // Ввод данных базового класса

    std::cout << "Enter Operating System: ";
    is >> mb.OS;

    std::cout << "Enter Weight (kg): ";
    is >> mb.weight;

    return is;
}
