#include "Man.h"

Man::Man() {
	SetAllName("Defatult name");
	SetBirthDate("01.01.2000");
}

Man::Man(const char* allName, const char* birth_date)
{
	SetAllName(allName);
	SetBirthDate(birth_date);
}

Man::Man(const Man &man): Man(man.all_name, man.birth_date) {}

Man::~Man() 
{
	delete all_name;
	delete birth_date;
}

void Man::SetAllName(const char* all_name) 
{
	int len = strlen(all_name) + 1;
	this->all_name = new char[len];
	strcpy_s(this->all_name, len, all_name);
}

void Man::SetBirthDate(const char* birth_date) 
{
	int len = strlen(birth_date) + 1;
	this->birth_date = new char[len];
	strcpy_s(this->birth_date, len, birth_date);
}

char* Man::GetAllName() 
{
	return all_name;
}

char* Man::GetBirthDate() 
{
	return birth_date;
}

std::ostream& operator<<(std::ostream& stream, Man& man) 
{
	return stream << "all_name = " << man.all_name << ", birht_date = " << man.birth_date;
}

Man& Man::operator=(const Man& man) 
{
	SetAllName(man.all_name);
	SetBirthDate(man.birth_date);
	return *this;
}