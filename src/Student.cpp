#include "../include/Student.h"
#include <iostream>
#include <iomanip>

// Default constructor
Student::Student() : id(0), name(""), email(""), gpa(0.0) {}

// Parameterized constructor
Student::Student(int id, const std::string& name, const std::string& email, double gpa)
    : id(id), name(name), email(email), gpa(gpa) {}

// Copy constructor
Student::Student(const Student& other)
    : id(other.id), name(other.name), email(other.email), gpa(other.gpa) {}

// Assignment operator
Student& Student::operator=(const Student& other) {
    if (this != &other) {
        id = other.id;
        name = other.name;
        email = other.email;
        gpa = other.gpa;
    }
    return *this;
}

// Destructor
Student::~Student() {}

// Getter methods
int Student::getId() const {
    return id;
}

std::string Student::getName() const {
    return name;
}

std::string Student::getEmail() const {
    return email;
}

double Student::getGpa() const {
    return gpa;
}

// Setter methods
void Student::setId(int newId) {
    id = newId;
}

void Student::setName(const std::string& newName) {
    name = newName;
}

void Student::setEmail(const std::string& newEmail) {
    email = newEmail;
}

void Student::setGpa(double newGpa) {
    if (newGpa >= 0.0 && newGpa <= 4.0) {
        gpa = newGpa;
    } else {
        std::cout << "Warning: GPA should be between 0.0 and 4.0" << std::endl;
    }
}

// Display student information
void Student::display() const {
    std::cout << std::left << std::setw(5) << id 
              << std::setw(20) << name 
              << std::setw(25) << email 
              << std::fixed << std::setprecision(2) << gpa << std::endl;
}

// Update student information
void Student::update() {
    std::cout << "Current student information:" << std::endl;
    display();
    
    std::cout << "\nEnter new information (press Enter to keep current value):" << std::endl;
    
    std::string input;
    std::cin.ignore(); // Clear the input buffer
    
    // Update name
    std::cout << "Name (" << name << "): ";
    std::getline(std::cin, input);
    if (!input.empty()) {
        name = input;
    }
    
    // Update email
    std::cout << "Email (" << email << "): ";
    std::getline(std::cin, input);
    if (!input.empty()) {
        email = input;
    }
    
    // Update GPA
    std::cout << "GPA (" << gpa << "): ";
    std::getline(std::cin, input);
    if (!input.empty()) {
        try {
            double newGpa = std::stod(input);
            setGpa(newGpa);
        } catch (const std::exception& e) {
            std::cout << "Invalid GPA format. Keeping current value." << std::endl;
        }
    }
    
    std::cout << "Student information updated successfully!" << std::endl;
}

// Serialize student data to string (for file operations)
std::string Student::toString() const {
    return std::to_string(id) + "," + name + "," + email + "," + std::to_string(gpa);
}

// Create student from string data (for file operations)
Student Student::fromString(const std::string& data) {
    size_t pos1 = data.find(',');
    size_t pos2 = data.find(',', pos1 + 1);
    size_t pos3 = data.find(',', pos2 + 1);
    
    if (pos1 == std::string::npos || pos2 == std::string::npos || pos3 == std::string::npos) {
        return Student(); // Return default student if parsing fails
    }
    
    try {
        int id = std::stoi(data.substr(0, pos1));
        std::string name = data.substr(pos1 + 1, pos2 - pos1 - 1);
        std::string email = data.substr(pos2 + 1, pos3 - pos2 - 1);
        double gpa = std::stod(data.substr(pos3 + 1));
        
        return Student(id, name, email, gpa);
    } catch (const std::exception& e) {
        std::cout << "Error parsing student data: " << e.what() << std::endl;
        return Student();
    }
}

// Equality operator
bool Student::operator==(const Student& other) const {
    return id == other.id;
}

// Less than operator (for sorting)
bool Student::operator<(const Student& other) const {
    return id < other.id;
}