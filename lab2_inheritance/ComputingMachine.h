#pragma once
#include<iostream>
class ComputingMachine {
protected:
    double CPUcapacity;
    double RAM;
    int DiskSpace;

public:
    ComputingMachine();  
    ComputingMachine(double CPUcapacity, double RAM, int DiskSpace);  
    ComputingMachine(const ComputingMachine& other);  
    ComputingMachine& operator=(const ComputingMachine& other);  
    ~ComputingMachine();  
    int GetDiskSpace();  
    void SetDiskSpace(int newDiskSpace);
    double GetCPUcapacity();  
    void SetCPUcapacity(double newCPUcapacity); 
    double GetRAM();  
    void SetRAM(double newRAM); 
    friend std::ostream& operator<<(std::ostream& os, ComputingMachine& cm);
    friend std::istream& operator>>(std::istream& is, ComputingMachine& cm);
};

