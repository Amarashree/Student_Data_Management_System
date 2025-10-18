#include "../include/Database.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>

// Constructor
Database::Database() {}

// Destructor
Database::~Database() {}

// Add a student to the database
bool Database::addStudent(const Student& student) {
    // Check if student with same ID already exists
    for (const auto& existingStudent : students) {
        if (existingStudent.getId() == student.getId()) {
            std::cout << "Error: Student with ID " << student.getId() << " already exists!" << std::endl;
            return false;
        }
    }
    
    students.push_back(student);
    std::cout << "Student added successfully!" << std::endl;
    return true;
}

// Display all students
void Database::displayAllStudents() const {
    if (students.empty()) {
        std::cout << "No students found in the database." << std::endl;
        return;
    }
    
    std::cout << "\n=== All Students ===" << std::endl;
    std::cout << std::left << std::setw(5) << "ID" 
              << std::setw(20) << "Name" 
              << std::setw(25) << "Email" 
              << "GPA" << std::endl;
    std::cout << std::string(55, '-') << std::endl;
    
    for (const auto& student : students) {
        student.display();
    }
    std::cout << "\nTotal students: " << students.size() << std::endl;
}

// Search for a student by ID
bool Database::searchStudent(int id) const {
    for (const auto& student : students) {
        if (student.getId() == id) {
            std::cout << "\nStudent found:" << std::endl;
            std::cout << std::left << std::setw(5) << "ID" 
                      << std::setw(20) << "Name" 
                      << std::setw(25) << "Email" 
                      << "GPA" << std::endl;
            std::cout << std::string(55, '-') << std::endl;
            student.display();
            return true;
        }
    }
    
    std::cout << "Student with ID " << id << " not found." << std::endl;
    return false;
}

// Update a student's information
bool Database::updateStudent(int id) {
    for (auto& student : students) {
        if (student.getId() == id) {
            student.update();
            return true;
        }
    }
    
    std::cout << "Student with ID " << id << " not found." << std::endl;
    return false;
}

// Delete a student from the database
bool Database::deleteStudent(int id) {
    auto it = std::find_if(students.begin(), students.end(),
                          [id](const Student& student) {
                              return student.getId() == id;
                          });
    
    if (it != students.end()) {
        std::cout << "Deleting student: ";
        it->display();
        students.erase(it);
        std::cout << "Student deleted successfully!" << std::endl;
        return true;
    }
    
    std::cout << "Student with ID " << id << " not found." << std::endl;
    return false;
}

// Save students to a file
bool Database::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error: Could not open file " << filename << " for writing." << std::endl;
        return false;
    }
    
    for (const auto& student : students) {
        file << student.toString() << std::endl;
    }
    
    file.close();
    std::cout << "Successfully saved " << students.size() << " students to " << filename << std::endl;
    return true;
}

// Load students from a file
bool Database::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error: Could not open file " << filename << " for reading." << std::endl;
        return false;
    }
    
    students.clear(); // Clear existing data
    std::string line;
    int loadedCount = 0;
    
    while (std::getline(file, line)) {
        if (!line.empty()) {
            Student student = Student::fromString(line);
            if (student.getId() != 0) { // Valid student (assuming ID 0 is invalid)
                students.push_back(student);
                loadedCount++;
            }
        }
    }
    
    file.close();
    std::cout << "Successfully loaded " << loadedCount << " students from " << filename << std::endl;
    return true;
}

// Get the number of students in the database
size_t Database::getStudentCount() const {
    return students.size();
}

// Sort students by ID
void Database::sortById() {
    std::sort(students.begin(), students.end(),
              [](const Student& a, const Student& b) {
                  return a.getId() < b.getId();
              });
    std::cout << "Students sorted by ID." << std::endl;
}

// Sort students by name
void Database::sortByName() {
    std::sort(students.begin(), students.end(),
              [](const Student& a, const Student& b) {
                  return a.getName() < b.getName();
              });
    std::cout << "Students sorted by name." << std::endl;
}

// Sort students by GPA (descending order)
void Database::sortByGpa() {
    std::sort(students.begin(), students.end(),
              [](const Student& a, const Student& b) {
                  return a.getGpa() > b.getGpa(); // Descending order
              });
    std::cout << "Students sorted by GPA (highest first)." << std::endl;
}

// Search students by name (partial match)
std::vector<Student> Database::searchByName(const std::string& name) const {
    std::vector<Student> results;
    std::string searchName = name;
    std::transform(searchName.begin(), searchName.end(), searchName.begin(), ::tolower);
    
    for (const auto& student : students) {
        std::string studentName = student.getName();
        std::transform(studentName.begin(), studentName.end(), studentName.begin(), ::tolower);
        
        if (studentName.find(searchName) != std::string::npos) {
            results.push_back(student);
        }
    }
    
    return results;
}

// Get students with GPA above threshold
std::vector<Student> Database::getStudentsAboveGpa(double threshold) const {
    std::vector<Student> results;
    
    for (const auto& student : students) {
        if (student.getGpa() >= threshold) {
            results.push_back(student);
        }
    }
    
    return results;
}

// Clear all students from the database
void Database::clearDatabase() {
    students.clear();
    std::cout << "Database cleared successfully!" << std::endl;
}