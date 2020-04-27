#include <Windows.h>
#include <iostream>
void main() {
	LPCSTR Password = "q9r03n9x4nqnxnnnar903";
	std::string upassword;
	std::cout << "Enter Password: "; 
	//push offset Str ; "Enter Password: "
	//mov eax, ds:?cout@std@@3V?$basic_ostream@DU?$char_traits@D@std@@@1@A ; std::basic_ostream<char,std::char_traits<char>> std::cout
	std::cin >> upassword; 
	//mov ecx, ds:?cin@std@@3V?$basic_istream@DU?$char_traits@D@std@@@1@A ; std::basic_istream<char,std::char_traits<char>> std::cin
	if (upassword == Password) {
		MessageBoxA(0, "Correct!", 0, 0);
		exit(0);
		/*
		mov     esi, esp
                push    0               ; uType
                push    0               ; lpCaption
                push    offset Text     ; "Correct!"
                push    0               ; hWnd
                call    ds:MessageBoxA
                cmp     esi, esp
                call    sub_411410
                mov     esi, esp
                push    0               ; Code
                call    ds:__imp_exit
		*/
	}
	else {
		MessageBoxA(0, "Incorrect!", 0, 0);
		exit(0);
		/*
                mov     esi, esp
                push    0               ; uType
                push    0               ; lpCaption
                push    offset aIncorrect ; "Incorrect!"
                push    0               ; hWnd
                call    ds:MessageBoxA
                cmp     esi, esp
                call    sub_411410
                mov     esi, esp
                push    0               ; Code
                call    ds:__imp_exit
	}
}
