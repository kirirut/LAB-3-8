#include "Laptop.h"
#include "PortableComputer.h"
#include "ComputingMachine.h"
#include <iomanip>
// ����������� �� ���������
Laptop::Laptop() : Keyboardlight(false), Microphone(false), ScreenType("Unknown") {}

// ����������� � �����������
Laptop::Laptop(double CPUcapacity, double RAM, int DiskSpace, double ScreenSize, const std::string& Resolution, int BatteryCapacity,
    bool Keyboardlight, bool Microphone, const std::string& ScreenType)
    : PortableComputer(CPUcapacity, RAM, DiskSpace, ScreenSize, Resolution, BatteryCapacity),
    Keyboardlight(Keyboardlight), Microphone(Microphone), ScreenType(ScreenType) {}

// ����������� �����������
Laptop::Laptop(const Laptop& other)
    : PortableComputer(other), Keyboardlight(other.Keyboardlight), Microphone(other.Microphone), ScreenType(other.ScreenType) {}

// �������� ������������
Laptop& Laptop::operator=(const Laptop& other) {
    if (this != &other) {
        PortableComputer::operator=(other);  // ����������� ������ �������� ������
        Keyboardlight = other.Keyboardlight;
        Microphone = other.Microphone;
        ScreenType = other.ScreenType;
    }
    return *this;
}

// ����������
Laptop::~Laptop() {}

// ������� � �������
bool Laptop::GetKeyboardlight() const {
    return Keyboardlight;
}

void Laptop::SetKeyboardlight(bool newKeyboardlight) {
    Keyboardlight = newKeyboardlight;
}

bool Laptop::GetMicrophone() const {
    return Microphone;
}

void Laptop::SetMicrophone(bool newMicrophone) {
    Microphone = newMicrophone;
}

std::string Laptop::GetScreenType() const {
    return ScreenType;
}

void Laptop::SetScreenType(const std::string& newScreenType) {
    ScreenType = newScreenType;
}

// ���������� ��������� ������
std::ostream& operator<<(std::ostream& os, Laptop& laptop) {
    os << static_cast<PortableComputer&>(laptop);
  
       os << std::left << std::setw(15) << "Keyboard Light:" << std::right << std::setw(10) << (laptop.Keyboardlight ? "Yes" : "No") << std::endl
        << std::left << std::setw(15) << "Microphone:" << std::right << std::setw(10) << (laptop.Microphone ? "Yes" : "No") << std::endl
        << std::left << std::setw(15) << "Screen Type:" << std::right << std::setw(10) << laptop.ScreenType << std::endl;

    return os;
}
std::istream& operator>>(std::istream& is, Laptop& laptop) {
    is >> static_cast<PortableComputer&>(laptop);  // ���� ������ �������� ������
    std::cout << "Keyboard Light (1 - Yes, 0 - No): ";
    is >> laptop.Keyboardlight;
    std::cout << "Microphone (1 - Yes, 0 - No): ";
    is >> laptop.Microphone;
    std::cout << "Screen Type: ";
    is >> laptop.ScreenType;
    return is;
}
