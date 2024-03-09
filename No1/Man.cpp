#include "Man.h"

Man::Man() {
	all_name = "Defatult name";
	birth_date = "01.01.2000";
}

Man::Man(const string &allName, string birth_date) {
	setAllName(allName);
	setBirthDate(birth_date);
}

Man::Man(const Man &man): Man(man.all_name, man.birth_date) {}

Man::~Man() {
	delete &all_name;
	delete &birth_date;
}

void Man::setAllName(const string& all_name) {
	this->all_name = all_name;
}

void Man::setBirthDate(const string& birth_date) {
	this->all_name = birth_date;
}

string Man::getAllName() {
	return all_name;
}

string Man::getBirthDate() {
	return birth_date;
}

std::ostream& operator<<(std::ostream& stream, Man& man) {
	return stream << "all_name = " << man.all_name << ", birht_date = " << man.birth_date;
}

Man& Man::operator=(const Man& man) {
	this->all_name = man.all_name;
	this->birth_date = man.birth_date;
	return *this;
}