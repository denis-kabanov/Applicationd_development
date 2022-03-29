// Copyright 06.02.21 DenisKabanov

#include <Student.hpp>
#include <Group.hpp>
#include <Deanery.hpp>

int main() {
    // Работа с файлами и самим деканатом
    Deanery Deanery("Groups1.txt"); // Создаём группы деканата из файла
    Deanery.hireStudents("Students1.txt"); // Добавляем студентов в группы
    Deanery.addMarksToAll(); // Ставим случайные оценки всем студентам
    Deanery.addMarksToAll();
    Deanery.addMarksToAll();
    Deanery.getStatistics(); // Выводим статистику по студентам

    std::cout << "Старосты до назначения:" << std::endl;
    for (auto group : Deanery.getGroups()){
        std::cout << group->getHead()->getId() << std::endl;
    }
    
    Deanery.initHeads();
    std::cout << "Старосты после назначения:" << std::endl
    for (auto group : Deanery.getGroups()) {
        std::cout << group->getHead()->getId() << std::endl;
    }
    Deanery.fireStudents(); // Удаляем студентов с плохой успеваемостью

    Deanery.getStatistics(); // Смотрим новую статистику

    std::cout << "======================================" << std::endl;
    // Работа с созданными группами
    unsigned int id1 = 1, id2 = 2;
    std::string fio1 = "STUDENT1", fio2 = "STUDENT2";
    std::string spec = "SPECIAL1", title = "TITLE1";
    Student student1(id1, fio1), student2(id2, fio2); // Создаём двух студентов
    Group group(title, spec); // Создаём группу
    group.addStudent(&student1); // Добавляем студентов в группу
    group.addStudent(&student2);
    std::cout << "Title: " << group.getTitle() << " Spec: " << group.getSpec()
        << std::endl; // Выводим название и специальность группы
    std::cout << "Empty? " << group.isEmpty() << std::endl;
    student1.addMark(5); // Добавляем оценки студентам
    student1.addMark(2);
    student2.addMark(1);
    // Считаем средние оценки у группы, а также ищем студентов в группе
    std::cout << "Average mark: " << group.getAverageMark() << std::endl;
    std::cout << "address of student with id 2 " << group.getStudent(2)
        << std::endl;
    std::cout << "address of student with name STUDENT1 "
        << group.getStudent("STUDENT1") << std::endl;
    // Проверка принадлежности студента к группе
    if (student1.getGroup() != &group)
        throw "ERROR";
    group.removeStudent(&student1); // Убираем студента из группы
    if (student1.getGroup() == &group)
        throw "ERROR";
    // Группа не должна быть пуста, так как в ней было два студента
    if (group.isEmpty() == true)
        throw "ERROR";
    group.removeStudent(&student2); // Убираем второго студента из группы
    // Теперь группа должна быть пустой
    if (group.isEmpty() == false)
        throw "ERROR";
    return 0;
}
