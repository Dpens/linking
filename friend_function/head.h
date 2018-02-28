#ifndef HEAD_H
#include<iostream>
#include<string>
#define HEAD_H

class dormitory
{
private:
	std::string name;
	int age;
	double height;
public:
	dormitory();
	dormitory(std::string Name, int Age, double Height);
	~dormitory();
	dormitory operator+(const dormitory & t)const;
	dormitory operator+(double H)const;
	friend dormitory operator+(double H, dormitory & t);
	void show();
};
#endif // !HEAD_H