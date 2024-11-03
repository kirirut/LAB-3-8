#include "PortableComputer.h"
#include "ComputingMachine.h"
#include<iomanip>
// ����������� �� ���������
PortableComputer::PortableComputer()
    : ComputingMachine(), DisplaySize(0), Resolution(""), BatteryCapacity(0) {}

// ����������� � �����������
PortableComputer::PortableComputer(double CPUcapacity, double RAM, int DiskSpace, int DisplaySize, const std::string& Resolution, int BatteryCapacity)
    : ComputingMachine(CPUcapacity, RAM, DiskSpace), DisplaySize(DisplaySize), Resolution(Resolution), BatteryCapacity(BatteryCapacity) {}

// ����������� �����������
PortableComputer::PortableComputer(const PortableComputer& other)
    : ComputingMachine(other), DisplaySize(other.DisplaySize), Resolution(other.Resolution), BatteryCapacity(other.BatteryCapacity) {}

// �������� ������������
PortableComputer& PortableComputer::operator=(const PortableComputer& other) {
    if (this == &other) {
        return *this; // ������ �� ����������������
    }

    ComputingMachine::operator=(other); // ������������ �������� ������
    DisplaySize = other.DisplaySize;
    Resolution = other.Resolution;
    BatteryCapacity = other.BatteryCapacity;

    return *this;
}

// ����������
PortableComputer::~PortableComputer() {
    // ������������ ��������, ���� ��� ����������
}

// ������ ��� DisplaySize
int PortableComputer::GetDisplaySize() const {
    return DisplaySize;
}

// ������ ��� DisplaySize
void PortableComputer::SetDisplaySize(int newDisplaySize) {
    DisplaySize = newDisplaySize;
}

// ������ ��� Resolution
std::string PortableComputer::GetResolution() const {
    return Resolution;
}

// ������ ��� Resolution
void PortableComputer::SetResolution(const std::string& newResolution) {
    Resolution = newResolution;
}

// ������ ��� BatteryCapacity
int PortableComputer::GetBatteryCapacity() const {
    return BatteryCapacity;
}

// ������ ��� BatteryCapacity
void PortableComputer::SetBatteryCapacity(int newBatteryCapacity) {
    BatteryCapacity = newBatteryCapacity;
}

// ���������� ������
std::ostream& operator<<(std::ostream& os, PortableComputer& pc) {
    // ����� ������ �������� ������ (ComputingMachine)
    os << static_cast< ComputingMachine&>(pc);
    // ��������������� ����� ������ ������������ ����������
    os << std::left << std::setw(20) << "\nDisplay Size:" << std::right << std::setw(10) << pc.GetDisplaySize() << " inches" << std::endl
        << std::left << std::setw(20) << "Resolution:" << std::right << std::setw(10) << pc.GetResolution() << std::endl
        << std::left << std::setw(20) << "Battery Capacity:" << std::right << std::setw(10) << pc.GetBatteryCapacity() << " mAh" << std::endl;

    return os;
}

// ���������� �����
std::istream& operator>>(std::istream& is, PortableComputer& pc) {
    is >> static_cast<ComputingMachine&>(pc); // ���� ������ �������� ������

    std::cout << "Enter Display Size (inches): ";
    is >> pc.DisplaySize;
    
    std::cout << "Enter Resolution: ";
    is >> pc.Resolution;

    std::cout << "Enter Battery Capacity (mAh): ";
    is >> pc.BatteryCapacity;

    return is;
}