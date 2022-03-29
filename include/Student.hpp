// Copyright 06.02.21 DenisKabanov

#ifndef INCLUDE_STUDENT_HPP_
#define INCLUDE_STUDENT_HPP_

#include <string>
#include <vector>
#include <Group.hpp>

class Group;

class Student {
 private:
    /// идентификатор студента
    unsigned int id;
    /// ФИО студента
    std::string fio;
    /// группа, к которой принадлежит студент
    Group* group = nullptr;
    /// оценки студента
    std::vector<int> marks;

 public:
    /// конструктор для объекта класса студент
    Student(unsigned int newid, std::string newfio);
    /// функция добавления студента в группу
    void addToGroup(Group* togroup);
    /// функция добавления оценки студенту
    void addMark(int newmark);
    /// функция, выдающая средний балл студента
    float getAverageMark();
    /// функция, проверяющая является ли студент старостой группы
    bool isHeadOfGroup();
    /// функция, возвращающая id студента
    int getId();
    /// функция, возвращающая ФИО студента
    std::string getFio();
    /// функция, возвращающая группу к которой принадлежит студент
    Group* getGroup();
    /// функция, возвращающая все оценки студента
    std::vector<int> getMarks();
};

#endif  // INCLUDE_STUDENT_HPP_
