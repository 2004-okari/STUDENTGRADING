// Rooney Nyandika 鲁尼 192464217
// Student Grading Management System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define PASS_MARK 50

typedef struct {
  int id;
  char name[50];
  char class[10];
  int math;
  int english;
  int computer;
  float average;
} Student;

Student students[MAX_STUDENTS];
int student_count = 0;

void add_student() {
  if (student_count >= MAX_STUDENTS) {
    printf("Maximum student limit reached.\n");
    return;
  }
  Student s;
  printf("Enter student id: ");
  scanf("%d", &s.id);
  printf("Enter student name: ");
  scanf("%s", s.name);
  printf("Enter student class: ");
  scanf("%s", s.class);
  printf("Enter math score: ");
  scanf("%d", &s.math);
  printf("Enter english score: ");
  scanf("%d", &s.english);
  printf("Enter computer score: ");
  scanf("%d", &s.computer);
  s.average = (s.math + s.english + s.computer) / 3.0;
  students[student_count++] = s;
  printf("Student added successfully.\n");
}

void query_student() {
  int choice, id;
  char name[50];
  printf("Query by: 1. ID 2. Name\n");
  scanf("%d", &choice);
  if (choice == 1) {
    printf("Enter student id: ");
    scanf("%d", &id);
    for (int i = 0; i < student_count; i++) {
      if (students[i].id == id) {
        printf("ID: %d, Name: %s, Class: %s, Math: %d, English: %d, Computer: %d, Average: %.2f\n",students[i].id, students[i].name, students[i].class, students[i].math, students[i].english, students[i].computer, students[i].average);
        return;
      }
    }
    printf("Student not found.\n");
  } else if (choice == 2) {
    printf("Enter student name: ");
    scanf("%s", name);
    for (int i = 0; i < student_count; i++) {
      if (strcmp(students[i].name, name) == 0) {
        printf("ID: %d, Name: %s, Class: %s, Math: %d, English: %d, Computer: %d, Average: %.2f\n",
        students[i].id, students[i].name, students[i].class, students[i].math, students[i].english, students[i].computer, students[i].average);
        return;
      }
    }
    printf("Student not found.\n");
  } else {
    printf("Invalid choice.\n");
  }
}

void sort_students_by_average() {
  for (int i = 0; i < student_count - 1; i++) {
    for (int j = 0; j < student_count - i - 1; j++) {
      if (students[j].average < students[j + 1].average) {
        Student temp = students[j];
        students[j] = students[j + 1];
        students[j + 1] = temp;
      }
    }
  }
  printf("Students sorted by average score.\n");
}

void sort_students_by_computer() {
  for (int i = 0; i < student_count - 1; i++) {
    for (int j = 0; j < student_count - i - 1; j++) {
      if (students[j].computer < students[j + 1].computer) {
        Student temp = students[j];
        students[j] = students[j + 1];
        students[j + 1] = temp;
      }
    }
  }
  printf("Students sorted by computer score.\n");
}

void delete_student() {
  int id;
  printf("Enter student id to delete: ");
  scanf("%d", &id);
  for (int i = 0; i < student_count; i++) {
    if (students[i].id == id) {
      for (int j = i; j < student_count - 1; j++) {
        students[j] = students[j + 1];
      }
      student_count--;
      printf("Student deleted successfully.\n");
      return;
    }
  }
  printf("Student not found.\n");
}

void modify_student() {
  int id;
  printf("Enter student id to modify: ");
  scanf("%d", &id);
  for (int i = 0; i < student_count; i++) {
    if (students[i].id == id) {
      printf("Enter new student name: ");
      scanf("%s", students[i].name);
      printf("Enter new student class: ");
      scanf("%s", students[i].class);
      printf("Enter new math score: ");
      scanf("%d", &students[i].math);
      printf("Enter new english score: ");
      scanf("%d", &students[i].english);
      printf("Enter new computer score: ");
      scanf("%d", &students[i].computer);
      students[i].average = (students[i].math + students[i].english + students[i].computer) / 3.0;
      printf("Student modified successfully.\n");
      return;
    }
  }
  printf("Student not found.\n");
}

void class_performance_analysis() {
  int total_math = 0, total_english = 0, total_computer = 0;
  int highest_math = 0, highest_english = 0, highest_computer = 0;
  int lowest_math = 100, lowest_english = 100, lowest_computer = 100;
  int pass_count = 0;

  for (int i = 0; i < student_count; i++) {
    total_math += students[i].math;
    total_english += students[i].english;
    total_computer += students[i].computer;

    if (students[i].math > highest_math) highest_math = students[i].math;
    if (students[i].english > highest_english) highest_english = students[i].english;
    if (students[i].computer > highest_computer) highest_computer = students[i].computer;

    if (students[i].math < lowest_math) lowest_math = students[i].math;
    if (students[i].english < lowest_english) lowest_english = students[i].english;
    if (students[i].computer < lowest_computer) lowest_computer = students[i].computer;

    if (students[i].average >= PASS_MARK) pass_count++;
  }

  printf("Class Performance Analysis:\n");
  printf("Average Math Score: %.2f\n", total_math / (float)student_count);
  printf("Average English Score: %.2f\n", total_english / (float)student_count);
  printf("Average Computer Score: %.2f\n", total_computer / (float)student_count);
  printf("Highest Math Score: %d\n", highest_math);
  printf("Highest English Score: %d\n", highest_english);
  printf("Highest Computer Score: %d\n", highest_computer);
  printf("Lowest Math Score: %d\n", lowest_math);
  printf("Lowest English Score: %d\n", lowest_english);
  printf("Lowest Computer Score: %d\n", lowest_computer);
  printf("Pass Rate: %.2f%%\n", (pass_count / (float)student_count) * 100);
}

void output_students() {
  printf("ID\tName\tClass\tMath\tEnglish\tComputer\tAverage\n");
  for (int i = 0; i < student_count; i++) {
    printf("%d\t%s\t%s\t%d\t%d\t%d\t%.2f\n", students[i].id, students[i].name, students[i].class, students[i].math, students[i].english, students[i].computer, students[i].average);
  }
}

int main() {
  int choice;
  while (1) {
    printf("1. Add Student\n2. Query Student\n3. Sort Students by Average\n4. Sort Students by Computer\n5. Delete Student\n6. Modify Student\n7. Class Performance Analysis\n8. Output Students\n9. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        add_student();
        break;
      case 2:
        query_student();
        break;
      case 3:
        sort_students_by_average();
        break;
      case 4:
        sort_students_by_computer();
        break;
      case 5:
        delete_student();
        break;
      case 6:
        modify_student();
        break;
      case 7:
        class_performance_analysis();
        break;
      case 8:
        output_students();
        break;
      case 9:
        exit(0);
      default:
        printf("Invalid choice.\n");
    }
  }
  return 0;
}