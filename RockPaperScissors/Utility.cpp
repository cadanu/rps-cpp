#include "Utility.h"


void Log(std::string msg)
{
	std::cout << msg << std::endl;
}

void clrscr()// clears screen - should work in Windows or Linux
{
	//system("pause");
	std::cout << "\033[2J\033[1;1H";// https://stackoverflow.com/questions/17335816/clear-screen-using-c
}
