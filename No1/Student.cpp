#include "Student.h"

using namespace std;
Student::Student() : Man() 
{
	group = "Unknown group";
	university = "Unknow university";
}

Student::Student(Student& student) 
{
	all_name = student.all_name;
	birth_date = student.birth_date;
	group = student.group;
	university = student.university;
}

Student::Student(const string& allName, string birth_date, string group, string university): Man(all_name, birth_date)
{
	SetGroup(group);
	SetUniversity(university);
}

Student::~Student()
{
	delete& group;
	delete& university;
}

void Student::SetGroup(string group)
{
	this->group = group;
}

void Student::SetUniversity(string& university)
{
	this->university = university;
}

string Student::GetGroup()
{
	return group;
}

string Student::GetUniversity()
{
	return university;
}
