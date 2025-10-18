#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
private:
    int id;
    std::string name;
    std::string email;
    double gpa;

public:
    // Constructors and Destructor
    Student();
    Student(int id, const std::string& name, const std::string& email, double gpa);
    Student(const Student& other);
    Student& operator=(const Student& other);
    ~Student();
    
    // Getter methods
    int getId() const;
    std::string getName() const;
    std::string getEmail() const;
    double getGpa() const;
    
    // Setter methods
    void setId(int newId);
    void setName(const std::string& newName);
    void setEmail(const std::string& newEmail);
    void setGpa(double newGpa);
    
    // Display and update methods
    void display() const;
    void update();
    
    // File operations
    std::string toString() const;
    static Student fromString(const std::string& data);
    
    // Operators
    bool operator==(const Student& other) const;
    bool operator<(const Student& other) const;
};

#endif // STUDENT_H