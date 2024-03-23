#include "Man.h"

Man::Man() {
	m_full_name = nullptr;
	m_birth_date = nullptr;
	SetFullName("Default name");
	SetBirthDate("01.01.2000");
}

Man::Man(const char* full_name, const char* birth_date)
{
	m_full_name = nullptr;
	m_birth_date = nullptr;
	SetFullName(full_name);
	SetBirthDate(birth_date);
}

Man::Man(const Man &man): Man(man.m_full_name, man.m_birth_date) {}

Man::~Man() 
{
	delete m_full_name;
	delete m_birth_date;
}

void Man::SetFullName(const char* full_name) 
{
	if (m_full_name)
		delete m_full_name;

	int len = strlen(full_name) + 1;
	m_full_name = new char[len];
	strcpy_s(m_full_name, len, full_name);
}

void Man::SetBirthDate(const char* birth_date) 
{
	if (m_birth_date)
		delete m_birth_date;

	int len = strlen(birth_date) + 1;
	m_birth_date = new char[len];
	strcpy_s(m_birth_date, len, birth_date);
}

char* Man::GetFullName() 
{
	return m_full_name;
}

char* Man::GetBirthDate() 
{
	return m_birth_date;
}

std::ostream& Man::Print(std::ostream& stream)
{
	return stream << "m_full_name = " << GetFullName() << ", m_birht_date = " << GetBirthDate();
}

std::ostream& operator<<(std::ostream& stream, Man& man)
{
	return man.Print(stream);
}

std::ostream& operator<<(std::ostream& stream, Man *man)
{
	return man->Print(stream);
}

Man& Man::operator=(const Man& man) 
{
	SetFullName(man.m_full_name);
	SetBirthDate(man.m_birth_date);
	return *this;
}