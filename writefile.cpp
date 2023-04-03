#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

class Employee {
public:
int id;
int age;
char gender;
int salary;

Employee(int id, int age, char gender, int salary) : id(id), age(age), gender(gender), salary(salary) {}

bool operator<(const Employee& other) const {
if (salary != other.salary) {
return salary < other.salary;
}
if (age != other.age) {
return age < other.age;
}
if (gender == 'f' && other.gender == 'm') {
return true;
}
return false;
}
};

int main(int argc, char** argv) {
if (argc != 2) {
cout << "Usage: " << argv[0] << " input_file" << endl;
return 1;
}
string input_file(argv[1]);
ifstream input(input_file);
if (!input.is_open()) {
cout << "Failed to open " << input_file << endl;
return 1;
}
vector<Employee> employees;
string line;
while (getline(input, line)) {
stringstream ss(line);
string id_str, age_str, gender_str, salary_str;
getline(ss, id_str, ',');
getline(ss, age_str, ',');
getline(ss, gender_str, ',');
getline(ss, salary_str, ',');
int id = stoi(id_str);
int age = stoi(age_str);
char gender = gender_str[0];
int salary = stoi(salary_str);
Employee employee(id, age, gender, salary);
employees.push_back(employee);
}
sort(employees.begin(), employees.end());
int current_salary = -1;
vector<int> current_ids;
for (Employee& employee : employees) {
if (employee.salary != current_salary) {
if (current_salary != -1) {




sort(current_ids.begin(), current_ids.end(), [&employees](int id1, int id2) {
const Employee& e1 = employees[id1 - 1];
const Employee& e2 = employees[id2 - 1];
if (e1.age != e2.age) {
return e1.age < e2.age;
}


if (e1.gender == 'f' && e2.gender == 'm') {
return true;
}
return false;
});
for (int id : current_ids) {
cout << id << ",";
}
cout << endl;
}


cout << employee.salary << ",";
current_salary = employee.salary;
current_ids.clear();
}
current_ids.push_back(employee.id);
}
if (current_salary != -1) {
sort(current_ids.begin(), current_ids.end(), [&employees](int id1, int id2)) {
const Employee& e1 = employees[id1 - 1];
const Employee& e2 = employees[id2 - 1];
}
}
if (e1.age != e2.age) {
return e1.age < e2.age;
}
if (e1.gender == 'f')

sort(employees.begin(), employees.end());

int current_salary = -1;

for (Employee& employee : employees) {
if (employee.salary != current_salary) {

    if (current_salary != -1) {

        cout << endl;

    }

    cout << employee.salary << ",";

    current_salary = employee.salary;

}

cout << employee.id << ",";
}

cout << endl;

return 0;

}