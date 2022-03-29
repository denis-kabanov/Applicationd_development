// Copyright 06.02.21 DenisKabanov

#ifndef INCLUDE_DEANERY_HPP_
#define INCLUDE_DEANERY_HPP_

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

 public:
    /// коснтруктор для объекта класса деканат
    explicit Deanery(std::string file);
    /// функция, для создания объекта-группы из файла
    void createGroups(std::string file);
    /// функция, для создания объекта-студента из файла
    void hireStudents(std::string file);
    /// функция, для добавления всем студентам оценок
    void addMarksToAll();
    /// функция, для получение статистики по успеваемости студентов
    void getStatistics();
    /// функция для перевода студента из одной группы в другую
    void moveStudents(unsigned int id, std::string title);
    /// функция отчисления студентов за неуспеваемость
    void fireStudents();
    /// функция для назначения старост в группах
    void initHeads();
    /// функция, возвращающая определённую группу из деканата
    std::vector<Group*> getGroups();
};
#endif  // INCLUDE_DEANERY_HPP_
