#include <Windows.h>
#include <iostream>
void main() {
	LPCSTR Password = "q9r03n9x4nqnxnnnar903";
	std::string upassword;
	std::cout << "Enter Password: ";
	std::cin >> upassword;
	if (upassword == Password) {
		MessageBoxA(0, "Correct!", 0, 0);
		exit(0);
	}
	else {
		MessageBoxA(0, "Incorrect!", 0, 0);
		exit(0);
	}
}
