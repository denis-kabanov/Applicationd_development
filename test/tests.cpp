// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>
#include <Student.hpp>
#include <Group.hpp>
#include <Deanery.hpp>

// Работа функции Student::getFio
TEST(Test, test1) {
  unsigned int id = 1;
  std::string fio = "Studen1";
  Student student(id, fio);
  EXPECT_EQ("Studen1", student.getFio());
}

// Работа функции Student::getId
TEST(Test, test2) {
  unsigned int id = 1;
  std::string fio = "Studen1";
  Student student(id, fio);
  EXPECT_EQ(1, student.getId());
}

// Работа функции Student::addMark и Student::getAverageMark
TEST(Test, test3) {
  unsigned int id1 = 1;
  std::string fio1 = "Studen1";
  Student student1(id1, fio1);
  student1.addMark(5);
  student1.addMark(1);
  EXPECT_EQ(3, student1.getAverageMark());
}

// Работа функции Student::getMarks
TEST(Test, test4) {
  unsigned int id1 = 1;
  std::string fio1 = "Studen1";
  Student student1(id1, fio1);
  student1.addMark(5);
  EXPECT_EQ(std::vector{5}, student1.getMarks());
}

// Работа функции Group::addStudent и Student::getGroup
TEST(Test, test5) {
  unsigned int id1 = 1;
  std::string fio1 = "Studen1";
  std::string title = "TITLE1", spec = "SPEC1";
  Student student1(id1, fio1);
  Group group(title, spec);
  group.addStudent(&student1);
  EXPECT_EQ(&group, student1.getGroup());
}

// Работа функции Group::getStudent(FIO)
TEST(Test, test6) {
  unsigned int id1 = 10;
  std::string fio1 = "Studen1";
  std::string title = "TITLE1", spec1 = "SPEC1";
  Student student1(id1, fio1);
  Group group1(title, spec1);
  group1.addStudent(&student1);
  EXPECT_EQ(&student1, group1.getStudent("Studen1"));
}

// Работа функции Group::chooseHead и Group::hetHead
TEST(Test, test7) {
  unsigned int id1 = 1;
  std::string fio1 = "Studen1";
  std::string title = "TITLE1", spec1 = "SPEC1";
  Student student1(id1, fio1);
  Group group1(title, spec1);
  group1.addStudent(&student1);
  group1.chooseHead();
  EXPECT_EQ(&student1, group1.getHead());
}

// Работа функции Group::getAverageMark
TEST(Test, test8) {
  unsigned int id1 = 1, id2 = 2;
  std::string fio1 = "Studen1", fio2 = "Student2";
  std::string title = "TITLE1", spec1 = "SPEC1";
  Student student1(id1, fio1), student2(id2, fio2);
  Group group1(title, spec1);
  group1.addStudent(&student1);
  group1.addStudent(&student2);
  student1.addMark(1);
  student2.addMark(3);
  EXPECT_EQ(2, group1.getAverageMark());
}

// Работа функции Group::isEmpty
TEST(Test, test9) {
  unsigned int id1 = 1, id2 = 2;
  std::string fio1 = "Studen1", fio2 = "Student2";
  std::string title = "TITLE1", spec1 = "SPEC1";
  Student student1(id1, fio1), student2(id2, fio2);
  Group group1(title, spec1);
  group1.addStudent(&student1);
  group1.addStudent(&student2);
  EXPECT_EQ(false, group1.isEmpty());
}

// Работа функции Group::isEmpty
TEST(Test, test10) {
  std::string title = "TITLE1", spec1 = "SPEC1";
  Group group1(title, spec1);
  EXPECT_EQ(true, group1.isEmpty());
}

// Работа функции Group::getTitle
TEST(Test, test11) {
  std::string title = "TITLE1", spec1 = "SPEC1";
  Group group1(title, spec1);
  EXPECT_EQ("TITLE1", group1.getTitle());
}

// Работа функции Group::getSpec
TEST(Test, test12) {
  std::string title = "TITLE1", spec1 = "SPEC1";
  Group group1(title, spec1);
  EXPECT_EQ("SPEC1", group1.getSpec());
}

// Работа функции Group::removeStudent
TEST(Test, test13) {
  unsigned int id1 = 1;
  std::string fio1 = "Studen1";
  std::string title = "TITLE1", spec1 = "SPEC1";
  Student student1(id1, fio1);
  Group group1(title, spec1);
  group1.addStudent(&student1);
  group1.removeStudent(&student1);
  EXPECT_EQ(true, group1.isEmpty());
}

// Работа функции Group::getStudent(id)
TEST(Test, test14) {
  unsigned int id1 = 1;
  std::string fio1 = "Studen1";
  std::string title = "TITLE1", spec1 = "SPEC1";
  Student student1(id1, fio1);
  Group group1(title, spec1);
  group1.addStudent(&student1);
  EXPECT_EQ(&student1, group1.getStudent(id1));
}
