#include"head.h"

dormitory::dormitory()
{
	name = "MARK";
	age = 18;
	height = 175.0;
}

dormitory::dormitory(std::string Name, int Age, double Height)
{
	name = Name;
	age = Age;
	height = Height;
}

dormitory::~dormitory()
{
	std::cout << "delete" << std::endl;
}

dormitory dormitory::operator+(const dormitory & t)const
{
	dormitory Jake;
	Jake.name = name + t.name;
	Jake.age = t.age + age;
	Jake.height = t.height + height;
	return Jake;
}

dormitory dormitory::operator+(double H)const
{
	dormitory Jake;
	Jake.name = name;
	Jake.age = age;
	Jake.height = height + H;
	return Jake;
}

dormitory operator+(double H, dormitory & t)
{
	return t + H;
}

void dormitory::show()
{
	using std::cout;
	using std::endl;
	cout << name << endl;
	cout << age << endl << height << endl;
}