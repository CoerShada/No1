#include "Student.h"

using namespace std;
Student::Student() : Man() 
{
	SetGroup("Unknown group");
	SetUniversity("Unknow university");

}

Student::Student(Student& student) 
{
	SetAllName(student.all_name);
	SetBirthDate(student.birth_date);
	SetUniversity(student.university);
	SetGroup(student.group);
}

Student::Student(const char* all_name, const char* birth_date, const char* group, const char* university): Man(all_name, birth_date)
{
	SetGroup(group);
	SetUniversity(university);
}

Student::~Student()
{
	delete group;
	delete university;
}

void Student::SetGroup(const char* group)
{
	int len = strlen(group) + 1;
	this->group = new char[len];
	strcpy_s(this->group, len, group);
}

void Student::SetUniversity(const char* university)
{
	int len = strlen(university) + 1;
	this->university = new char[len];
	strcpy_s(this->university, len, university);
}

char* Student::GetGroup()
{
	return group;
}

char* Student::GetUniversity()
{
	return university;
}

std::ostream& operator<<(std::ostream& stream, Student& student) {
	return stream << "all_name = " << student.all_name << ", birht_date = " << student.birth_date << ", group = " << student.group << ", university = " << student.university;
}

Student& Student::operator=(const Student& student)
{
	SetAllName(student.all_name);
	SetBirthDate(student.birth_date);
	SetUniversity(student.university);
	SetGroup(student.group);
	return *this;
}