#include "Student.h"

using namespace std;
Student::Student() : Man() {
	group = "Unknown group";
	university = "Unknow university";
}

Student::Student(Student& student) {
	all_name = student.all_name;
	birth_date = student.birth_date;
	group = student.group;
	university = student.university;
}

Student::Student(const string& allName, string birth_date, string group, string university): Man(all_name, birth_date)
{
	setGroup(group);
	setUniversity(university);
}

Student::~Student()
{
	delete& group;
	delete& university;
}

void Student::setGroup(string group)
{
	this->group = group;
}

void Student::setUniversity(string& university)
{
	this->university = university;
}

string Student::getGroup()
{
	return group;
}

string Student::getUniversity()
{
	return university;
}
