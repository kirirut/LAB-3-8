#include "StationaryComputer.h"
#include "ComputingMachine.h"
#include<iomanip>
StationaryComputer::StationaryComputer()
    : ComputingMachine(), CPUcores(0), MotherBoardChipset(""), GPU("") {}
StationaryComputer::StationaryComputer(double CPUcapacity, double RAM, int DiskSpace, int CPUcores, const std::string& MotherBoardChipset, const std::string& GPU)
    : ComputingMachine(CPUcapacity, RAM, DiskSpace), CPUcores(CPUcores), MotherBoardChipset(MotherBoardChipset), GPU(GPU) {}

StationaryComputer::StationaryComputer(const ComputingMachine& other)
    : ComputingMachine(other), CPUcores(0), MotherBoardChipset(""), GPU("") {}
StationaryComputer& StationaryComputer::operator=(const StationaryComputer& other) {
    if (this == &other) {
        return *this;  
    }
    ComputingMachine::operator=(other);
    CPUcores = other.CPUcores;
    MotherBoardChipset = other.MotherBoardChipset;
    GPU = other.GPU;

    return *this;
}
// Геттеры
int StationaryComputer::GetCPUcores() const {
    return CPUcores;
}

void StationaryComputer::SetCPUcores(int newCPUcores) {
    CPUcores = newCPUcores;
}

std::string StationaryComputer::GetMotherBoardChipset() const {
    return MotherBoardChipset;
}

void StationaryComputer::SetMotherBoardChipset(const std::string& newChipset) {
    MotherBoardChipset = newChipset;
}

std::string StationaryComputer::GetGPU() const {
    return GPU;
}

void StationaryComputer::SetGPU(const std::string& newGPU) {
    GPU = newGPU;
}
std::ostream& operator<<(std::ostream& os, const StationaryComputer& sc) {
    os << "________________________________" << std::endl;
    // Форматированный вывод данных стационарного компьютера
    os << std::left << std::setw(20) << "CPU Capacity:" << std::right << std::setw(10) << sc.CPUcapacity << " GHz" << std::endl
        << std::left << std::setw(20) << "RAM:" << std::right << std::setw(10) << sc.RAM << " GB" << std::endl
        << std::left << std::setw(20) << "Disk Space:" << std::right << std::setw(10) << sc.DiskSpace << " GB" << std::endl
        << std::left << std::setw(20) << "CPU Cores:" << std::right << std::setw(10) << sc.CPUcores << std::endl
        << std::left << std::setw(20) << "Motherboard Chipset:" << std::right << std::setw(10) << sc.MotherBoardChipset << std::endl
        << std::left << std::setw(20) << "GPU:" << std::right << std::setw(10) << sc.GPU << std::endl;

    os << "--------------------------------" << std::endl;
    return os;
}
std::istream& operator>>(std::istream& is, StationaryComputer& sc) {
    double cpuCapacity, ram;
    int diskSpace, cpuCores;
    std::string motherboardChipset, gpu;

    is >> static_cast<ComputingMachine&>(sc);
    std::cout << "Enter Number of CPU Cores: ";
    is >> cpuCores;
    sc.SetCPUcores(cpuCores);

    std::cout << "Enter Motherboard Chipset: ";
    is >> motherboardChipset;
    sc.SetMotherBoardChipset(motherboardChipset);

    std::cout << "Enter GPU(manufacturer): ";
    is >> gpu;
    sc.SetGPU(gpu);

    return is;
}
StationaryComputer::~StationaryComputer() {
   
}