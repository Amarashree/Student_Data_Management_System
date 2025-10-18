#ifndef DATABASE_H
#define DATABASE_H

#include "Student.h"
#include <vector>
#include <string>

class Database {
private:
    std::vector<Student> students;

public:
    // Constructor and Destructor
    Database();
    ~Database();
    
    // Basic CRUD operations
    bool addStudent(const Student& student);
    void displayAllStudents() const;
    bool searchStudent(int id) const;
    bool updateStudent(int id);
    bool deleteStudent(int id);
    
    // File operations
    bool saveToFile(const std::string& filename) const;
    bool loadFromFile(const std::string& filename);
    
    // Utility methods
    size_t getStudentCount() const;
    void clearDatabase();
    
    // Sorting methods
    void sortById();
    void sortByName();
    void sortByGpa();
    
    // Advanced search methods
    std::vector<Student> searchByName(const std::string& name) const;
    std::vector<Student> getStudentsAboveGpa(double threshold) const;
};

#endif // DATABASE_H