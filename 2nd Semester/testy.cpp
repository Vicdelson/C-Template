#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <algorithm>
#include <chrono>
#include <ctime>
#include <iomanip>

// Struct to represent a sign-in/sign-out event
struct Event {
    std::string type; // "sign-in" or "sign-out"
    std::time_t time; // Unix timestamp
};

// Struct to represent a workday of an employee
struct Workday {
    std::time_t start_time; // Unix timestamp of the first sign-in event
    std::time_t end_time; // Unix timestamp of the last sign-out event
};

// Helper function to parse a timestamp string into a Unix timestamp
std::time_t parse_timestamp(const std::string& timestamp_str) {
    std::tm tm = {};
    std::istringstream ss(timestamp_str);
    ss >> std::get_time(&tm, "%Y%m%d%H%M");
    return std::mktime(&tm);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <csv_file_path>\n";
        return 1;
    }

    // Open the input file
    std::ifstream input_file(argv[1]);
    if (!input_file) {
        std::cerr << "Error: failed to open input file " << argv[1] << "\n";
        return 1;
    }
// Read the sign-in/sign-out events from the input file and group them by employee id
    std::unordered_map<std::string, std::vector<Event>> events_by_employee;
    std::string line;
    while (std::getline(input_file, line)) {
        std::istringstream ss(line);
        std::string employee_id_str, event_type, timestamp_str;
        std::getline(ss, employee_id_str, ',');
        std::getline(ss, event_type, ',');
        std::getline(ss, timestamp_str, ',');
        std::string employee_id = employee_id_str;
        std::time_t timestamp = parse_timestamp(timestamp_str);
        events_by_employee[employee_id].push_back({event_type, timestamp});
    }

    // Compute the workdays of each employee
    std::unordered_map<std::string, std::vector<Workday>> workdays_by_employee;
    for (const auto& [employee_id, events] : events_by_employee) {
        // Sort the events in chronological order
        std::sort(events.begin(), events.end(), [](const Event& e1, const Event& e2) {
            return e1.time < e2.time;
        });
// Compute the workdays based on the sign-in/sign-out events
        std::vector<Workday> workdays;
        std::time_t start_time = 0;
        bool on_workday = false;
        for (const Event& event : events) {
            if (event.type == "sign-in") {
                if (!on_workday) {
                    start_time = event.time;
                    on_workday = true;
                }
            } else { // event.type == "sign-out"
                if (on_workday) {
                    workdays.push_back({start_time, event.time});
                    on_workday = false;
                }
            }
        }
        if (on_workday) {
            // The last workday ends today (assume the company stops working after 18:00)
            workdays.push_back({start_time, parse_timestamp("202304260000")});
        }
        workdays_by_employee[employee_id] = workdays;
    }
}
    // Compute the longest continuous