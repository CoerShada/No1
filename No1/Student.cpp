#include "Student.h"

using namespace std;
Student::Student() : Man()
{
	m_group = nullptr;
	m_university = nullptr;
	SetGroup("Unknown group");
	SetUniversity("Unknown university");
}

Student::Student(Student& student): Man(student)
{
	m_group = nullptr;
	m_university = nullptr;
	SetUniversity(student.m_university);
	SetGroup(student.m_group);
}

Student::Student(const char* full_name, const char* birth_date, const char* group, const char* university): Man(full_name, birth_date)
{
	m_group = nullptr;
	m_university = nullptr;
	SetGroup(group);
	SetUniversity(university);
}

Student::~Student()
{
	delete m_group;
	delete m_university;
}

void Student::SetGroup(const char* group)
{
	if (m_group)
		delete m_group;

	int len = strlen(group) + 1;
	m_group = new char[len];
	strcpy_s(m_group, len, group);
}

void Student::SetUniversity(const char* university)
{
	if (m_university)
		delete m_university;

	int len = strlen(university) + 1;
	m_university = new char[len];
	strcpy_s(m_university, len, university);
}

char* Student::GetGroup()
{
	return m_group;
}

char* Student::GetUniversity()
{
	return m_university;
}

std::ostream& Student::Print(std::ostream& stream)
{
	return stream << "m_full_name = " << GetFullName() << ", m_birht_date = " << GetBirthDate() << ", m_group = " << GetGroup() << ", m_university = " << GetUniversity();
}

std::ostream& operator<<(std::ostream& stream, Student& student) {
	return student.Print(stream);
}

std::ostream& operator<<(std::ostream& stream, Student *student) {
	return student->Print(stream);
}

Student& Student::operator=(const Student& student)
{
	SetFullName(student.m_full_name);
	SetBirthDate(student.m_birth_date);
	SetUniversity(student.m_university);
	SetGroup(student.m_group);
	return *this;
}