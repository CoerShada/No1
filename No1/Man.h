#pragma once
#include <iostream>

using namespace std;
class Man
{
protected:
	char* m_full_name;
	char* m_birth_date;

public:
	Man();
	Man(const Man &man);
	Man(const char* full_name, const char* birth_date);
	virtual ~Man();

	void SetFullName(const char* full_name);
	void SetBirthDate(const char* birth_date);

	char* GetFullName();
	char* GetBirthDate();

	virtual std::ostream& Print(std::ostream& stream);

	friend std::ostream& operator<<(std::ostream& stream, Man& man);
	friend std::ostream& operator<<(std::ostream& stream, Man* man);
	Man& operator=(const Man& man);
};

