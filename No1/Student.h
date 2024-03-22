#pragma once
#include "Man.h"
class Student :
    public Man
{
private:
    char* group;
    char* university;


public:
    Student();
    Student(Student& student);
    Student(const char* allName, const char* birth_date, const char* group, const char* university);
    virtual ~Student();

    void SetGroup(const char* group);
    void SetUniversity(const char* university);

    char* GetGroup();
    char* GetUniversity();

    friend std::ostream& operator<<(std::ostream& stream, Student& student);
    Student& operator=(const Student& m);


};

