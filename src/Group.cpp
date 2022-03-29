// Copyright 06.02.21 DenisKabanov

#include <Group.hpp>
#include <Student.hpp>

Group::Group(std::string newtitle, std::string newspec) {
    this->title = newtitle;
    this->spec = newspec;
}

void Group::addStudent(Student* newstudent) {
    if (this->getStudent(newstudent->getId()) == nullptr ) && 
    (this->getStudent(newstudent->getFio()) == nullptr ){
        this->students.push_back(newstudent);
        newstudent->addToGroup(this);
    }
}

void Group::chooseHead() {
    std::mt19937 gen(time(0));
    std::uniform_int_distribution<> uid(0, students.size() - 1);
    this->head = students[uid(gen)];
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
    for (auto stud : students) {
        sum = sum + stud->getAverageMark();
    }
    if (sum != 0)
        return (sum / this->getStudents());
    else
        return 0;
}

void Group::removeStudent(Student* delstudent) {
    delstudent->addToGroup(nullptr);
    this->students.erase(std::remove(students.begin(), students.end(), delstudent),
students.end());
}

bool Group::isEmpty() {
    if (students.size() == 0)
        return true;
    else
        return false;
}

int Group::getStudents() {
    int studcount = 0;
    for (auto members : this->students) {
        studcount++;
    }
    return studcount;
}

std::string Group::getTitle() {
    return title;
}

std::string Group::getSpec() {
    return spec;
}

std::vector<Student*> Group::containsStudents() {
    return students;
}

Student* Group::getHead() {
    return head;
}
