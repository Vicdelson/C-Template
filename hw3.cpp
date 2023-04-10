#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <ctime>

using namespace std;

class Sign {
public:
    string type;
    time_t time;
    string employee_id;

    Sign(string type, time_t time, string employee_id) {
        this->type = type;
        this->time = time;
        this->employee_id = employee_id;
    }
};

class Employee {
public:
    string id;
    vector<Sign> signs;
    int overloading_days = 0;
    int sign_forget_days = 0;

    Employee(string id) {
        this->id = id;
    }

    void add_sign(Sign sign) {
        this->signs.push_back(sign);
    }

    void calculate_days() {
        unordered_map<string, int> day_counts;
        for (Sign sign : this->signs) {
            string day = get_day(sign.time);
            if (day_counts.find(day) == day_counts.end()) {
                day_counts[day] = 0;
            }
            day_counts[day]++;
        }
        for (auto it : day_counts) {
            if (it.second >= 2) {
                this->overloading_days++;
            }
            if (it.second < 2) {
                this->sign_forget_days++;
            }
        }
    }

private:
    string get_day(time_t time) {
        struct tm* t = localtime(&time);
        char buf[11];
        strftime(buf, sizeof(buf), "%Y-%m-%d", t);
        return string(buf);
    }
};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " csv_file" << endl;
        return 1;
    }

    string filename = argv[1];

    vector<Employee> employees;

    ifstream input(filename);
    string line;
    while (getline(input, line)) {
        string employee_id, type, time_str;
        getline(line, employee_id, ',');
        getline(line, type, ',');
        getline(line, time_str, ',');

        time_t time = get_time(time_str);

        Employee* employee = nullptr;
        for (Employee& e : employees) {
            if (e.id == employee_id) {
                employee = &e;
                break;
            }
        }
        if (employee == nullptr) {
            employees.emplace_back(Employee(employee_id));
            employee = &employees.back();
        }
        employee->add_sign(Sign(type, time, employee_id));
    }

    input.close();

    for (Employee& e : employees) {
        e.calculate_days();
    }

    sort(employees.begin(), employees.end(), [](const Employee& a, const Employee& b) {
        return a.id < b.id;
    });

    for (Employee& e : employees) {
        cout << e.id << "," << e.overloading_days << "," << e.sign_forget_days << endl;
    }

    return 0;
}

time_t get_time(string time_str) {
    struct tm t;
    strptime(time_str.c_str(), "%Y%m%d%H%M", &t);
    return mktime(&t);
}