#pragma once
#include "Man.h"
class Student :
    public Man
{
private:
    char* m_group;
    char* m_university;


public:
    Student();
    Student(Student& student);
    Student(const char* full_name, const char* birth_date, const char* group, const char* university);
    virtual ~Student();

    void SetGroup(const char* group);
    void SetUniversity(const char* university);

    char* GetGroup();
    char* GetUniversity();

	virtual std::ostream& Print(std::ostream& stream);

	friend std::ostream& operator<<(std::ostream& stream, Student& student);
	friend std::ostream& operator<<(std::ostream& stream, Student *student);
    Student& operator=(const Student& m);


};

