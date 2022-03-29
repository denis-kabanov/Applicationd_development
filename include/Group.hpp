// Copyright 06.02.21 DenisKabanov

#ifndef INCLUDE_GROUP_HPP_
#define INCLUDE_GROUP_HPP_

#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <ctime>
#include <Student.hpp>

class Student;

class Group {
 private:
    /// название группы
    std::string title;
    /// специальность
    std::string spec;
    /// студенты в данной группе
    std::vector<Student*> students;
    /// староста группы
    Student* head = nullptr;

 public:
    /// конструктор группы
    Group(std::string newtitle, std::string newspec);
    /// функция добавления студента в группу
    void addStudent(Student* newstudent);
    /// функция выбора старосты
    void chooseHead();
    /// функция получения студента по его id
    Student* getStudent(unsigned int findid);
    /// функция получения студента по его ФИО
    Student* getStudent(std::string findfio);
    /// функция подсчёта среднего балла по группе
    float getAverageMark();
    /// функция удаления студента из группы
    void removeStudent(Student* delstudent);
    /// функция проверки группы на наличие в ней студентов
    bool isEmpty();
    /// функция, возвращающая число студентов в группе
    int getStudents();
    /// функция, возвращающая название группы
    std::string getTitle();
    /// функция, возвращающая специальность группы
    std::string getSpec();
    /// функция для получения всех студентов группы
    std::vector<Student*> containsStudents();
    /// функция для получения старосты группы
    Student* getHead();
};

#endif  // INCLUDE_GROUP_HPP_
