// Copyright 06.02.21 DenisKabanov

#include <Deanery.hpp>
#include <Group.hpp>
#include <Student.hpp>

int main() {
    unsigned int id1 = 1, id2 = 2;
    std::string fio1 = "Vasya Pupkin", fio2 = "Danya Kvasin";
    std::string spec = "SPECIAL1", title = "TITLE1";
    Student student1(id1, fio1), student2(id2, fio2);
    Group group(title, spec);
    /*
    group.addStudent(&student1);
    group.addStudent(&student2);
    std::cout << "Title: " << group.getTitle() << " Spec: " << group.getSpec()
<< std::endl;
    std::cout << "Empty? " << group.isEmpty() << std::endl;
    student1.addMark(5);
    student2.addMark(1);
    std::cout << "Average mark: " << group.getAverageMark() << std::endl;
    std::cout << "address of student with id 2 " << group.getStudent(2)
<< std::endl;
    std::cout << "address of student with name Danya Kvasin "
<< group.getStudent("Danya Kvasin") << std::endl;
*/
	/*Deanary deanary("Groups1");
    deanary.hireStudents("Students1");
    deanary.addMarksToAll();
    deanary.addMarksToAll();
    deanary.addMarksToAll();
    deanary.getStatistics("Stat1.txt");
    deanary.fireStudents();
    deanary.saveStaff("Groups2.txt", "Students2.txt");*/
    return 0;
}
