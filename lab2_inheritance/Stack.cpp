#include "Stack.h"
#include "ComputingMachine.h"
void TestStack()
{
	
	Stack<ComputingMachine> stack;
	std::cout << "--------------------------------\nTEST\n" << "Stack size:" << stack.size() << std::endl;
	ComputingMachine T_computer(3.0, 16, 512);
	ComputingMachine T_computer1(4.2, 8, 1024);
	stack.push(T_computer);
	ComputingMachine T_buff = stack.top();
	std::cout << "" << T_buff << std::endl;
	stack.push(T_computer1);
	T_buff = stack.top();
	std::cout << "" << T_buff << std::endl;
	std::cout << "Stack size:" << stack.size() << std::endl<<"\n--------------------------------\n";
	try {
		ComputingMachine found = stack.find(4.21);
		std::cout << "Found computer: " << found<< " with CPU capacity "  << "4.21\n----------------------"<<std::endl;
	}
	catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
	} 
		
	
}