// Copyright 06.02.21 DenisKabanov

#include <Student.hpp>
#include <Group.hpp>
#include <Deanery.hpp>

int main() {
    // Работа с файлами и самим деканатом
    Deanery Deanery("Groups1.txt");
    Deanery.hireStudents("Students1.txt");
    Deanery.addMarksToAll();
    Deanery.addMarksToAll();
    Deanery.addMarksToAll();
    Deanery.getStatistics();
    Deanery.fireStudents();
    std::cout << "======================================" << std::endl;
    // Работа с созданными группами
    unsigned int id1 = 1, id2 = 2;
    std::string fio1 = "STUDENT1", fio2 = "STUDENT2";
    std::string spec = "SPECIAL1", title = "TITLE1";
    Student student1(id1, fio1), student2(id2, fio2);
    Group group(title, spec);
    group.addStudent(&student1);
    group.addStudent(&student2);
    std::cout << "Title: " << group.getTitle() << " Spec: " << group.getSpec()
        << std::endl;
    std::cout << "Empty? " << group.isEmpty() << std::endl;
    student1.addMark(5);
    student1.addMark(2);
    student2.addMark(1);
    std::cout << "Average mark: " << group.getAverageMark() << std::endl;
    std::cout << "address of student with id 2 " << group.getStudent(2)
        << std::endl;
    std::cout << "address of student with name STUDENT1 "
        << group.getStudent("STUDENT1") << std::endl;
    group.removeStudent(&student1);
    if (student1.getGroup() == &group)
        throw "ERROR";
    return 0;
}
