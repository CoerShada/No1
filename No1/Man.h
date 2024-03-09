#pragma once
#include <string>
#include <iostream>

using namespace std;
class Man
{
protected:
	string all_name;
	string birth_date;

public:
	Man();
	Man(const Man &man);
	Man(const string& all_name, string birth_date);
	virtual ~Man();

	void setAllName(const string& all_name);
	void setBirthDate(const string& birth_date);

	string getAllName();
	string getBirthDate();

	friend std::ostream& operator<<(std::ostream& stream, Man& m); 
	Man& operator=(const Man& m);
};

