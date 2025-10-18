#include <iostream>
#include <string>
#include "../include/Database.h"
#include "../include/Student.h"

void displayMenu() {
    std::cout << "\n=== Student Database Management System ===" << std::endl;
    std::cout << "1. Add Student" << std::endl;
    std::cout << "2. Display All Students" << std::endl;
    std::cout << "3. Search Student by ID" << std::endl;
    std::cout << "4. Update Student" << std::endl;
    std::cout << "5. Delete Student" << std::endl;
    std::cout << "6. Save to File" << std::endl;
    std::cout << "7. Load from File" << std::endl;
    std::cout << "8. Exit" << std::endl;
    std::cout << "Enter your choice: ";
}

int main() {
    Database db;
    int choice;
    
    std::cout << "Welcome to Student Database Management System!" << std::endl;
    
    while (true) {
        displayMenu();
        std::cin >> choice;
        
        switch (choice) {
            case 1: {
                int id;
                std::string name, email;
                double gpa;
                
                std::cout << "Enter Student ID: ";
                std::cin >> id;
                std::cin.ignore(); // Clear the newline character
                
                std::cout << "Enter Student Name: ";
                std::getline(std::cin, name);
                
                std::cout << "Enter Student Email: ";
                std::getline(std::cin, email);
                
                std::cout << "Enter Student GPA: ";
                std::cin >> gpa;
                
                Student student(id, name, email, gpa);
                db.addStudent(student);
                std::cout << "Student added successfully!" << std::endl;
                break;
            }
            case 2:
                db.displayAllStudents();
                break;
                
            case 3: {
                int id;
                std::cout << "Enter Student ID to search: ";
                std::cin >> id;
                db.searchStudent(id);
                break;
            }
            case 4: {
                int id;
                std::cout << "Enter Student ID to update: ";
                std::cin >> id;
                db.updateStudent(id);
                break;
            }
            case 5: {
                int id;
                std::cout << "Enter Student ID to delete: ";
                std::cin >> id;
                db.deleteStudent(id);
                break;
            }
            case 6:
                db.saveToFile("students.txt");
                std::cout << "Data saved to file successfully!" << std::endl;
                break;
                
            case 7:
                db.loadFromFile("students.txt");
                std::cout << "Data loaded from file successfully!" << std::endl;
                break;
                
            case 8:
                std::cout << "Thank you for using Student Database Management System!" << std::endl;
                return 0;
                
            default:
                std::cout << "Invalid choice! Please try again." << std::endl;
                break;
        }
    }
    
    return 0;
}