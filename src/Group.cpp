// Copyright 06.02.21 DenisKabanov

#include <Group.hpp>
#include <Student.hpp>

Group::Group(std::string newtitle, std::string newspec) {
    this->title = newtitle;
    this->spec = newspec;
}

void Group::addStudent(Student *newstudent) {
    if ((newstudent->getId() != 0) &&
        (newstudent->getFio() != "")) {
        this->students.push_back(newstudent);
        newstudent->addToGroup(this);
    }
}

void Group::chooseHead() {
    std::mt19937 gen(time(0));
    std::uniform_int_distribution<> uid(0, students.size() - 1);
    this->head = this->students[uid(gen)];
}

Student* Group::getStudent(unsigned int findid) {
    for (auto stud : this->students) {
        if (stud->getId() == findid)
            return stud;
    }
    return nullptr;
}

Student* Group::getStudent(std::string findfio) {
    for (auto stud : this->students) {
        if (stud->getFio() == findfio)
            return stud;
    }
    return nullptr;
}

float Group::getAverageMark() {
    float sum = 0;
    int counter = 0;
    for (auto stud : students) {
        sum = sum + stud->getAverageMark();
        counter++;
    }
    if (counter != 0)
        return (sum / counter);
    else
        return 0;
}

void Group::removeStudent(Student* delstudent) {
    delstudent->addToGroup(nullptr);
    if (this->head == delstudent)
        this->head = bullptr;
    this->students.erase(std::remove(this->students.begin(),
                         this->students.end(), delstudent));
}

bool Group::isEmpty() {
    if (this->students.size() == 0)
        return true;
    else
        return false;
}

int Group::getStudents() {
    int studcount = 0;
    for (auto stud : this->students) {
        studcount++;
    }
    return studcount;
}

std::string Group::getTitle() {
    return this->title;
}

std::string Group::getSpec() {
    return this->spec;
}

std::vector<Student*> Group::containsStudents() {
    return this->students;
}

Student* Group::getHead() {
    return this->head;
}
