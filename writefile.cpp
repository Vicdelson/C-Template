#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class Employee {
private:
    string id;
    int overloadingDays;
    int signForgetDays;
public:
    Employee(string id) {
        this->id = id;
        this->overloadingDays = 0;
        this->signForgetDays = 0;
    }
    void incrementOverloadingDays() {
        this->overloadingDays++;
    }
    void incrementSignForgetDays() {
        this->signForgetDays++;
    }
    string getId() {
        return this->id;
    }
    int getOverloadingDays() {
        return this->overloadingDays;
    }
    int getSignForgetDays() {
        return this->signForgetDays;
    }
};
unordered_map<string, Employee> employees;

bool compareEmployees(const Employee emp1, const Employee* emp2) {
    return emp1->getId() < emp2->getId();
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cerr << "Error: Please provide the input file name." << endl;
        return 1;
    }
    ifstream file(argv[1]);
    if (!file.is_open()) {
        cerr << "Error: Could not open the input file." << endl;
        return 1;
    }
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string id, type, time;
        getline(iss, id, ',');
        getline(iss, type, ',');
        getline(iss, time, ',');
        if (employees.find(id) == employees.end()) {
            employees[id] = new Employee(id);
        }
        if (type == "sign-in") {
            employees[id]->incrementSignForgetDays();
        } else {
            employees[id]->incrementSignForgetDays();
            string prevTime = time;
            getline(iss, time, ',');
            int timeDiff = stoi(time) - stoi(prevTime);
            if (timeDiff > 800) {
                employees[id]->getOverloadingDays();
            }
        }
    }
file.close();
    vector<Employee> sortedEmployees;
    for (auto const& pair : employees) {
        sortedEmployees.push_back(pair.second);
    }
    sort(sortedEmployees.begin(), sortedEmployees.end(), compareEmployees);
    for (Employee emp : sortedEmployees) {
        cout << emp->getId() << "," << emp->getOverloadingDays() << "," << emp->getSignForgetDays() << endl;
    }
    for (auto const& pair : employees) {
        delete pair.second;
    }
    return 0;
}