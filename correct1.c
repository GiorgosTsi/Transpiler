
#include "lambdalib.h"





#define SELF struct Teacher *self

typedef struct Teacher {
StringType firstName;
StringType lastName;
StringType department;
void (*setTeacher)(SELF , StringType firstName, StringType lastName, StringType department);

void (*printTeacher)(SELF );

} Teacher;
void setTeacher(SELF , StringType firstName, StringType lastName, StringType department) {
self->firstName = firstName;
self->lastName = lastName;
self->department = department;

}

void printTeacher(SELF ) {
write("Teacher: %s %s, Department: %s\n", self->firstName, self->lastName, self->department);

}

const Teacher ctor_Teacher = { .setTeacher=setTeacher,.printTeacher=printTeacher   };
#undef SELF


#define SELF struct Student *self

typedef struct Student {
StringType firstName;
StringType lastName;
int studentID;
StringType major;
void (*setStudent)(SELF , StringType firstName, StringType lastName, int studentID, StringType major);

void (*printStudent)(SELF );

} Student;
void setStudent(SELF , StringType firstName, StringType lastName, int studentID, StringType major) {
self->firstName = firstName;
self->lastName = lastName;
self->studentID = studentID;
self->major = major;

}

void printStudent(SELF ) {
write("Student: %s %s, ID: %d, Major: %s\n", self->firstName, self->lastName, self->studentID, self->major);

}

const Student ctor_Student = { .setStudent=setStudent,.printStudent=printStudent   };
#undef SELF


#define SELF struct University *self

typedef struct University {
StringType name;
StringType location;
Teacher teachers[10];
Student students[50];
int numOfTeachers;
int numOfStudents;
void (*setUniversity)(SELF , StringType name, StringType location);

void (*addTeacher)(SELF , Teacher t);

void (*addStudent)(SELF , Student s);

void (*printUniversityInfo)(SELF );

} University;
void setUniversity(SELF , StringType name, StringType location) {
self->name = name;
self->location = location;
self->numOfTeachers = 0;
self->numOfStudents = 0;

}

void addTeacher(SELF , Teacher t) {
if (self->numOfTeachers < 10) {
self->teachers[self->numOfTeachers] = t;
self->numOfTeachers += 1;

}

}

void addStudent(SELF , Student s) {
if (self->numOfStudents < 50) {
self->students[self->numOfStudents] = s;
self->numOfStudents += 1;

}

}

void printUniversityInfo(SELF ) {
write("University: %s, Location: %s\n", self->name, self->location);
write("Teachers:\n");
for (int i = 0; i < self->numOfTeachers; i++) {
self->teachers[i].printTeacher(&self->teachers[i]);

}
write("Students:\n");
for (int i = 0; i < self->numOfStudents; i++) {
self->students[i].printStudent(&self->students[i]);

}

}

const University ctor_University = { .setUniversity=setUniversity,.addTeacher=addTeacher,.addStudent=addStudent,.printUniversityInfo=printUniversityInfo  , .teachers = {[0 ... 10 - 1] = ctor_Teacher},.students = {[0 ... 50 - 1] = ctor_Student} };
#undef SELF

int main () {

University u = ctor_University;

u.setUniversity(&u,"TUC", "Chania City");

Teacher t1 = ctor_Teacher;

Teacher t2 = ctor_Teacher;

t1.setTeacher(&t1,"Alice", "Smith", "Computer Science");
u.addTeacher(&u,t1);
t2.setTeacher(&t2,"John", "Doe", "Mathematics");
u.addTeacher(&u,t2);

Student s[2];
for (int i = 0; i < 2; i++) 
{ s[i] = ctor_Student; }
s[0].setStudent(&s[0],"Alex", "Doe", 12221, "Computer Science");
s[1].setStudent(&s[1],"Ariel", "Doe", 11111, "Physics");
u.addStudent(&u,s[0]);
u.addStudent(&u,s[1]);

Student s1 = ctor_Student;

s1.setStudent(&s1,"Bob", "Doe", 12345, "Computer Science");
u.addStudent(&u,s1);

Student s2 = ctor_Student;

s2.setStudent(&s2,"Daisy", "Maximus", 67890, "Mathematics");
u.addStudent(&u,s2);
u.printUniversityInfo(&u);

}
