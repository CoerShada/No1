#pragma once
#include <string>
#include "Man.h"
class Student :
    public Man
{
private:
    string group;
    string university;



public:
    Student();
    Student(Student& student);
    Student(const string& allName, string birth_date, string group, string university);
    virtual ~Student();

    void SetGroup(string group);
    void SetUniversity(string& university);

    string GetGroup();
    string GetUniversity();
};

