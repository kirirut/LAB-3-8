#include "Monoblock.h"
#include "StationaryComputer.h"
#include "Monoblock.h"
#include <iomanip>
// ����������� �� ���������
Monoblock::Monoblock()
    : StationaryComputer(), OS(""), weight(0) {}

// ����������� � �����������
Monoblock::Monoblock(double CPUcapacity, double RAM, int DiskSpace, int CPUcores, const std::string& MotherBoardChipset, const std::string& GPU, const std::string& OS, int weight)
    : StationaryComputer(CPUcapacity, RAM, DiskSpace, CPUcores, MotherBoardChipset, GPU), OS(OS), weight(weight) {}

// ����������� �����������
Monoblock::Monoblock(const Monoblock& other)
    : StationaryComputer(other), OS(other.OS), weight(other.weight) {}

// �������� ������������
Monoblock& Monoblock::operator=(const Monoblock& other) {
    if (this == &other) {
        return *this; // ������ �� ����������������
    }

    StationaryComputer::operator=(other); // ������������ �������� ������
    OS = other.OS;
    weight = other.weight;

    return *this;
}

// ����������
Monoblock::~Monoblock() {
    // ������������ ��������, ���� ��� ����������
}

// ������ ��� OS
std::string Monoblock::GetOS() const {
    return OS;
}

// ������ ��� OS
void Monoblock::SetOS(const std::string& newOS) {
    OS = newOS;
}

// ������ ��� weight
int Monoblock::GetWeight() const {
    return weight;
}

// ������ ��� weight
void Monoblock::SetWeight(int newWeight) {
    weight = newWeight;
}

// ���������� ������
std::ostream& operator<<(std::ostream& os, const Monoblock& mb) {
    os << static_cast<const StationaryComputer&>(mb);

    // ��������������� ����� ������ ���������
    os << std::left << std::setw(20) << "\nOperating System:" << std::right << std::setw(15) << mb.GetOS() << std::endl
        << std::left << std::setw(15) << "Weight:" << std::right << std::setw(15) << mb.GetWeight() << " kg" << std::endl
        << "--------------------------------";

    return os;
}

// ���������� �����
std::istream& operator>>(std::istream& is, Monoblock& mb) {
    is >> static_cast<StationaryComputer&>(mb); // ���� ������ �������� ������

    std::cout << "Enter Operating System: ";
    is >> mb.OS;

    std::cout << "Enter Weight (kg): ";
    is >> mb.weight;

    return is;
}
