#include<iostream>
#include"head.h"

int main()
{
	{
		dormitory John;
		dormitory Make("Susan", 17, 160.0);
		dormitory Heavon = Make + John;
		John.show();
		Make.show();
		Heavon.show();
		John = John + 170.0;
		Make = 160.9 + Make;
		John.show();
		Make.show();
	}
	std::cin.get();
	std::cin.get();
	return 0;
}