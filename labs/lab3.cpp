#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

enum Grade {
    F = 0, D, C, B, A
};

struct Subject {
    string name;
    string teacher;
};

struct Student {
    string firstName;
    string lastName;
    string groupName;
    map<string, Grade> grades;
};

struct Teacher {
    string firstName;
    string lastName;
    vector<string> groups;
    vector<string> subjects;
};

struct Group {
    string name;
    vector<Student> students;
};

struct SchoolSystem {
    vector<Group> groups;
    vector<Teacher> teachers;
    vector<Subject> subjects;

    void addGroup(Group g) {
        groups.push_back(g);
    }

    void addTeacher(Teacher t) {
        teachers.push_back(t);
    }

    void addSubject(Subject s) {
        subjects.push_back(s);
    }

    Student* findStudent(string lastName) {
        for (auto& group : groups)
            for (auto& student : group.students)
                if (student.lastName == lastName)
                    return &student;
        return nullptr;
    }

    Teacher* findTeacher(string lastName) {
        for (auto& teacher : teachers)
            if (teacher.lastName == lastName)
                return &teacher;
        return nullptr;
    }

    void showGroupReport(string groupName) {
        for (auto& group : groups) {
            if (group.name == groupName) {
                cout << "Report for group: " << groupName << endl;
                for (auto& student : group.students) {
                    cout << student.firstName << " " << student.lastName << ":\n";
                    for (auto& [subject, grade] : student.grades) {
                        cout << "  " << subject << ": " << char('A' - grade) << endl;
                    }
                }
                return;
            }
        }
        cout << "Group not found\n";
    }

    void showTeacherReport(string lastName) {
        for (auto& teacher : teachers) {
            if (teacher.lastName == lastName) {
                cout << "Teacher: " << teacher.firstName << " " << teacher.lastName << endl;
                cout << "Groups: ";
                for (auto& group : teacher.groups) cout << group << " ";
                cout << "\nSubjects: ";
                for (auto& subject : teacher.subjects) cout << subject << " ";
                cout << endl;
                return;
            }
        }
        cout << "Teacher not found\n";
    }
};

int main() {
    SchoolSystem school;

    school.addSubject({"Math", "Ivanenko"});
    school.addTeacher({"Ivan", "Ivanenko", {"CS-101"}, {"Math"}});
    Student s1 = {"Oleh", "Petrenko", "CS-101", {{"Math", Grade::B}}};
    Group g1 = {"CS-101", {s1}};
    school.addGroup(g1);

    school.showGroupReport("CS-101");
    school.showTeacherReport("Ivanenko");

    return 0;
}

