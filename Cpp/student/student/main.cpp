#include <iostream>
#include <cstring>
using namespace std;

class Student {
public:
    Student() {
        strcpy(name, "default");
        strcpy(no, "0001");
        disc = "cpp";
    }
    Student(char* name, char* no, char* disc) {
        strcpy(this->name, name);
        strcpy(this->no, no);
        this->disc = disc;
    }
    Student(Student& s) {
        strcpy(name, s.name);
        strcpy(no, s.no);
        disc = s.disc;
    }
    ~Student() {
        delete []name;
        delete []no;
        delete disc;
    }
    &Student operator = (Student& s);
    char* getName() {
        return name;
    }
    void setName(char* name) {
        strcpy(this->name, name);
    }
private:
    char name[20];
    char no[20];
    char* disc;
};