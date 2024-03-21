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

	void SetAllName(const string& all_name);
	void SetBirthDate(const string& birth_date);

	string GetAllName();
	string GetBirthDate();

	friend std::ostream& operator<<(std::ostream& stream, Man& m); 
	Man& operator=(const Man& m);
};

