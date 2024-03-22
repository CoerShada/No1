#pragma once
#include <iostream>

using namespace std;
class Man
{
protected:
	char* all_name;
	char* birth_date;

public:
	Man();
	Man(const Man &man);
	Man(const char* all_name, const char* birth_date);
	virtual ~Man();

	void SetAllName(const char* all_name);
	void SetBirthDate(const char* birth_date);

	char* GetAllName();
	char* GetBirthDate();

	friend std::ostream& operator<<(std::ostream& stream, Man& m); 
	Man& operator=(const Man& m);
};

