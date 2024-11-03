#include <iostream>
#include "ComputingMachine.h"
#include "StationaryComputer.h"
#include "Monoblock.h"
#include "PortableComputer.h"
#include "Laptop.h"
#include "Tablet.h"
#include "Stack.h"
int main() 
{
	TestStack();
	ComputingMachine T_computer,computer;
	StationaryComputer T_stationary;
	Monoblock T_monoblock;
	PortableComputer T_portable;
	Laptop T_laptop;
	Tablet T_tablet;

	std::cout << "MONOBLOCK ARRAY\n-------------------------\n";
	const int numMonoblocks = 3;
	Monoblock monoblocks[numMonoblocks] = {
		Monoblock(3.5, 16, 512, 4, "Intel Z490", "NVIDIA RTX 3060", "Windows 10", 8),
		Monoblock(3.2, 8, 256, 4, "AMD B550", "AMD Radeon RX 580", "Windows 11", 7),
		Monoblock(4.0, 32, 1024, 8, "Intel Z590", "NVIDIA RTX 3080", "Linux", 9)
	};
	for (const auto& mb : monoblocks) {
		std::cout << mb << std::endl;
	}
	std::cout << "COMPUTING MACHINE\n-------------------------\n";
	std::cin >> T_computer;
	std::cout << T_computer;
	std::cout << "STATIONARY COMPUTER\n-------------------------\n";
	std::cin >> T_stationary;
	std::cout << T_stationary;
	std::cout << "PORTABLE COMPUTER\n-------------------------\n";
std::cin >> T_portable;
	std::cout << T_portable; 
	std::cout << "LAPTOP\n-------------------------\n";
	std::cin >> T_laptop;
	std::cout << T_laptop;
	std::cout << "TABLET\n-------------------------\n";
	std::cin >> T_tablet;
	std::cout << T_tablet;



}