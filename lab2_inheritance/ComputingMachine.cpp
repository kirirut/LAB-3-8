#include "ComputingMachine.h"
#include<iostream>
#include <iomanip>
ComputingMachine::ComputingMachine() : CPUcapacity(0), RAM(0), DiskSpace(0) {}
ComputingMachine::ComputingMachine(double CPUcapacity, double RAM, int DiskSpace)
    : CPUcapacity(CPUcapacity), RAM(RAM), DiskSpace(DiskSpace) {}
ComputingMachine::ComputingMachine(const ComputingMachine& other) {
    this->CPUcapacity = other.CPUcapacity;
    this->RAM = other.RAM;
    this->DiskSpace = other.DiskSpace;
}
ComputingMachine& ComputingMachine::operator=(const ComputingMachine& other) {
   
    if (this == &other) {
        return *this; 
    }
    this->CPUcapacity = other.CPUcapacity;
    this->RAM = other.RAM;
    this->DiskSpace = other.DiskSpace;
    return *this;
}
std::ostream& operator<<(std::ostream& os, ComputingMachine& cm) {
    os << std::endl<<"-------------------------\n"
        << std::left << std::setw(15) << "CPU Capacity:" << std::right << std::setw(8) << cm.CPUcapacity << " GHz"
        << std::endl
        << std::left << std::setw(15) << "RAM:" << std::right << std::setw(8) << cm.RAM << " GB"
        << std::endl
        << std::left << std::setw(15) << "Disk Space:" << std::right << std::setw(8) << cm.DiskSpace << " GB\n";
    return os;
}
std::istream& operator>>(std::istream& is, ComputingMachine& cm) {
    std::cout << "Enter CPU capacity (GHz): ";
    is >> cm.CPUcapacity;

    std::cout << "Enter RAM size (GB): ";
    is >> cm.RAM;

    std::cout << "Enter Disk Space (GB): ";
    is >> cm.DiskSpace;

    return is;
}
int ComputingMachine::GetDiskSpace() {
    return DiskSpace;
}

void ComputingMachine::SetDiskSpace(int newDiskSpace) {
    DiskSpace = newDiskSpace;
}
double ComputingMachine::GetCPUcapacity() {
    return CPUcapacity;
}

void ComputingMachine::SetCPUcapacity(double newCPUcapacity) {
    CPUcapacity = newCPUcapacity;
}
double ComputingMachine::GetRAM() {
    return RAM;
}

void ComputingMachine::SetRAM(double newRAM) {
    RAM = newRAM;
}

ComputingMachine::~ComputingMachine() {}
