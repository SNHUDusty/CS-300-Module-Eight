#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <limits>

using namespace std;

struct Course {
    string courseNumber;
    string courseName;
    vector<string> prerequisites;
};

void displayMenu() {
    cout << "\n====== COURSE PLANNER ======\n"
         << "1. Load Data Structure\n"
         << "2. Print Course List\n"
         << "3. Print Course\n"
         << "9. Exit\n"
         << "Enter choice: ";
}

int getValidatedChoice() {
    int choice;
    while (!(cin >> choice)) {
        cout << "Invalid input. Enter a number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return choice;
}

void loadCourses(const string& filename, vector<Course>& courses) {
    ifstream file(filename);
    string line;
    courses.clear();

    if (!file.is_open()) {
        cout << "Error: Could not open file.\n";
        return;
    }

    while (getline(file, line)) {
        vector<string> tokens;
        stringstream ss(line);
        string token;

        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        if (tokens.size() >= 2) {
            Course c{tokens[0], tokens[1], {}};
            c.prerequisites.assign(tokens.begin() + 2, tokens.end());
            courses.push_back(c);
        }
    }

    file.close();
    cout << "Data loaded. Total courses: " << courses.size() << endl;
}

void printCourseList(const vector<Course>& courses) {
    cout << "\nCourse List:\n";
    for (const auto& c : courses)
        cout << c.courseNumber << ": " << c.courseName << endl;
}

void printCourseInfo(const vector<Course>& courses, const string& id) {
    auto it = find_if(courses.begin(), courses.end(),
                      [&](const Course& c) { return c.courseNumber == id; });

    if (it == courses.end()) {
        cout << "Course not found.\n";
        return;
    }

    cout << it->courseNumber << ": " << it->courseName << endl;

    if (!it->prerequisites.empty()) {
        cout << "Prerequisites: ";
        for (size_t i = 0; i < it->prerequisites.size(); ++i) {
            string prereqID = it->prerequisites[i];
            auto prereq = find_if(courses.begin(), courses.end(),
                                  [&](const Course& c) { return c.courseNumber == prereqID; });

            if (prereq != courses.end())
                cout << prereq->courseNumber << " (" << prereq->courseName << ")";
            else
                cout << prereqID << " (Unknown)";

            if (i < it->prerequisites.size() - 1)
                cout << ", ";
        }
        cout << endl;
    } else {
        cout << "Prerequisites: None\n";
    }
}

int main() {
    vector<Course> courses;
    int choice;
    string filename, courseID;

    do {
        displayMenu();
        choice = getValidatedChoice();

        switch (choice) {
            case 1:
                cout << "Enter filename: ";
                cin >> filename;
                loadCourses(filename, courses);
                break;

            case 2:
                if (courses.empty()) {
                    cout << "No data loaded.\n";
                } else {
                    sort(courses.begin(), courses.end(),
                         [](const Course& a, const Course& b) {
                             return a.courseNumber < b.courseNumber;
                         });
                    printCourseList(courses);
                }
                break;

            case 3:
                if (courses.empty()) {
                    cout << "No data loaded.\n";
                } else {
                    cout << "Enter course number: ";
                    cin >> courseID;
                    printCourseInfo(courses, courseID);
                }
                break;

            case 9:
                cout << "Exiting.\n";
                break;

            default:
                cout << "Invalid option.\n";
        }
    } while (choice != 9);

    return 0;
}