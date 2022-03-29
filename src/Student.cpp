// Copyright 06.02.21 DenisKabanov

#include <Student.hpp>

Student::Student(unsigned int newid, std::string newfio) {
    this->id = newid;
    this->fio = newfio;
}

void Student::addToGroup(Group* togroup) {
    this->group = togroup;
}

void Student::addMark(int newmark) {
    this->marks.push_back(newmark);
}

float Student::getAverageMark() {
    float allmarks = 0;
    int counter = 0;
    for (auto m : this->marks) {
        counter++;
        allmarks = allmarks + m;
    }
    if (counter != 0)
        return allmarks / counter;
    else
        return 0;
}

bool Student::isHeadOfGroup() {
    if (this == group->getHead())
        return true;
    else
        return false;
}

int Student::getId() {
    return this->id;
}

std::string Student::getFio() {
    return this->fio;
}

Group* Student::getGroup() {
    return this->group;
}

std::vector<int> Student::getMarks() {
    return this->marks;
}
