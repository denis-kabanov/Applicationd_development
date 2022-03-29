// Copyright 06.02.21 DenisKabanov

#include <iostream>
#include <Group.hpp>
#include <Deanery.hpp>

Deanery::Deanery(std::string file) {
    createGroups(file);
}

void Deanery::createGroups(std::string fileName) {
    std::ifstream file(fileName);
    std::string input, spec, title;
    while (getline(file, input)) {
        int pos = input.find(':');
        if (pos == std::string::npos)
            throw "Неправильный формат ввода для группы!";
        title = input.substr(0, pos);
        spec = input.substr(pos + 1, input.size() - pos - 1);
        Group* group = new Group(title, spec);
        this->groups.push_back(group);
    }
    file.close();
}

void Deanery::hireStudents(std::string fileName) {
    std::ifstream file(fileName);
    std::string input;
    unsigned int id = 0;
    while (getline(file, input)) {
        Student* stud = new Student(++id, input);
        if (this->groups.size() == 0)
            throw "Нет подходящих групп для записи!";
        std::random_device rd;
        std::default_random_engine generator(rd());
        int toGroup = generator() % groups.size();
        this->groups[toGroup]->addStudent(stud);
        stud->addToGroup(groups[toGroup]);
    }
    file.close();
}

void Deanery::addMarksToAll() {
    for (auto group : groups) {
        for (auto stud : group->containsStudents()) {
            std::random_device rd;
            std::default_random_engine generator(rd());
            int mark = generator() % 6;
            stud->addMark(mark);
        }
    }
}

void Deanery::getStatistics() {
    for (auto group : this->groups) {
        std::cout << group->getTitle() << "\t"
            << group->getSpec() << "\t" << "Average mark: "
            << group->getAverageMark() << "\n";
        auto groupcont = group->containsStudents();
        std::cout << "Студенты группы:" << "\n";
        for (auto stud : groupcont) {
            std::cout << stud->getId() << " " << stud->getFio()
                << " avg mark:" << stud->getAverageMark() << "\n";
        }
    }
}

void Deanery::moveStudents(unsigned int id, std::string title) {
    bool flag = false;
    Student* stud = nullptr;
    for (auto group : this->groups) {
        if (group->getStudent(id) != nullptr) {
            stud = group->getStudent(id);
            group->removeStudent(stud);
            break;
        }
    }
    for (auto group : this->groups) {
        if ((group->getTitle() == title) && (stud != nullptr)) {
            group->addStudent(stud);
            stud->addToGroup(group);
            flag = true;
            break;
        }
    }
    if (flag == false)
        throw "Студент где-то потерялся!";
}

void Deanery::initHeads() {
    for (auto group : this->groups) {
        group->chooseHead();
    }
}

void Deanery::fireStudents() {
    for (auto group : this->groups) {
        auto groupCont = group->containsStudents();
        for (auto stud : groupCont) {
            float mark = stud->getAverageMark();
            if (mark < 3.0) {
                group->removeStudent(stud);
            }
        }
    }
}

std::vector<Group*> Deanery::getGroups() {
    return this->groups;
}

