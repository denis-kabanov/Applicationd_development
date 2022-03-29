// Copyright 06.02.21 DenisKabanov

#ifndef INCLUDE_DEANERY_H_
#define INCLUDE_DEANERY_H_

#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <ctime>
#include <fstream>
#include <iostream>
#include <Student.hpp>
#include <Group.hpp>

class Deanery {
 private:
    std::vector<Group*> groups;
    unsigned int groupid = 0;

 public:
    explicit Deanery(std::string file); // коснтруктор для объекта класса деканат
    void createGroups(std::string file);
    void hireStudents(std::string file);
    void addMarksToAll();
    void getStatistics(std::string file);
    void moveStudents(int id, std::string title);
    void saveStaff(std::string filegroups, std::string filestudents);
    void initHeads();
    void fireStudents();
    Group* getGroup(std::string title);
    Student* getStudent(int id);
};
#endif  // INCLUDE_DEANERY_H_
