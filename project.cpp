#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Employee {
private:
    string name;
    int id;
    double hourlyRate;
    double hoursWorked;

public:
    Employee(string name, int id, double hourlyRate)
        : name(name), id(id), hourlyRate(hourlyRate), hoursWorked(0) {}

    void addHoursWorked(double hours) {
        hoursWorked += hours;
    }

    double calculateSalary() {
        return hoursWorked * hourlyRate;
    }

    void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Hourly Rate: $" << hourlyRate << endl;
        cout << "Hours Worked: " << hoursWorked << endl;
        cout << "Salary: $" << calculateSalary() << endl;
    }
};

class PayrollSystem {
private:
    vector<Employee> employees;

public:
    void addEmployee(Employee employee) {
        employees.push_back(employee);
    }

    void displayPayroll() {
        for (const auto& employee : employees) {
            employee.displayInfo();
            cout << "--------------------------" << endl;
        }
    }
};

int main() {
    PayrollSystem payrollSystem;

    // Adding employees
    Employee emp1("John Doe", 1, 20.0);
    Employee emp2("Jane Smith", 2, 25.0);

    payrollSystem.addEmployee(emp1);
    payrollSystem.addEmployee(emp2);

    // Simulating work hours
    emp1.addHoursWorked(40);
    emp2.addHoursWorked(35);

    // Displaying payroll information
    payrollSystem.displayPayroll();

    return 0;
}
