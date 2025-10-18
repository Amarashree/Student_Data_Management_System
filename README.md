# Student Database Management System

A console-based C++ application for managing student records with CRUD operations, file persistence, and advanced search capabilities.

## Features

- **Student Management**
  - Add new students with ID, name, email, and GPA
  - Display all students in a formatted table
  - Search students by ID
  - Update existing student information
  - Delete students from the database

- **File Operations**
  - Save student data to text files
  - Load student data from text files
  - Persistent storage between sessions

- **Advanced Features**
  - Sort students by ID, name, or GPA
  - Search students by name (partial matching)
  - Filter students by GPA threshold
  - Input validation and error handling

## Project Structure

```
student-database-system/
├── src/
│   ├── main.cpp           # Main application entry point
│   ├── Student.cpp        # Student class implementation
│   └── Database.cpp       # Database class implementation
├── include/
│   ├── Student.h          # Student class header
│   └── Database.h         # Database class header
├── build/                 # Build directory (created during compilation)
├── bin/                   # Executable output directory
├── tests/                 # Test files (future use)
├── docs/                  # Documentation
├── CMakeLists.txt         # CMake build configuration
├── .gitignore             # Git ignore rules
└── README.md              # This file
```

## Prerequisites

- C++17 compatible compiler (GCC 7+, Clang 5+, MSVC 2017+)
- CMake 3.10 or higher
- Git (for version control)

### On macOS
```bash
# Install Xcode command line tools (includes clang++)
xcode-select --install

# Install CMake using Homebrew
brew install cmake
```

### On Ubuntu/Debian
```bash
sudo apt update
sudo apt install build-essential cmake git
```

### On Windows
- Install Visual Studio 2017+ with C++ support, or
- Install MinGW-w64 and CMake

## Building the Project

1. **Clone or navigate to the project directory**
   ```bash
   cd student-database-system
   ```

2. **Create a build directory**
   ```bash
   mkdir build
   cd build
   ```

3. **Configure the project with CMake**
   ```bash
   cmake ..
   ```

4. **Build the project**
   ```bash
   make
   ```
   
   On Windows with Visual Studio:
   ```bash
   cmake --build .
   ```

5. **Run the executable**
   ```bash
   ./bin/StudentDatabaseSystem
   ```

## Alternative Build Methods

### Direct Compilation (without CMake)
```bash
# From the project root directory
g++ -std=c++17 -Wall -Wextra -I include src/*.cpp -o StudentDatabaseSystem
```

### Debug Build
```bash
# In build directory
cmake -DCMAKE_BUILD_TYPE=Debug ..
make
```

### Release Build
```bash
# In build directory
cmake -DCMAKE_BUILD_TYPE=Release ..
make
```

## Usage

### Main Menu Options

1. **Add Student** - Enter student details (ID, name, email, GPA)
2. **Display All Students** - Show all students in a formatted table
3. **Search Student by ID** - Find and display a specific student
4. **Update Student** - Modify existing student information
5. **Delete Student** - Remove a student from the database
6. **Save to File** - Save current data to students.txt
7. **Load from File** - Load data from students.txt
8. **Exit** - Close the application

### Sample Usage Flow

```
=== Student Database Management System ===
1. Add Student
2. Display All Students
...
Enter your choice: 1

Enter Student ID: 101
Enter Student Name: John Doe
Enter Student Email: john.doe@email.com
Enter Student GPA: 3.75
Student added successfully!
```

### File Format

Student data is saved in CSV format:
```
ID,Name,Email,GPA
101,John Doe,john.doe@email.com,3.75
102,Jane Smith,jane.smith@email.com,3.90
```

## Class Documentation

### Student Class
- **Attributes**: ID (int), Name (string), Email (string), GPA (double)
- **Key Methods**: 
  - Constructors and destructor
  - Getters and setters with validation
  - Display and update methods
  - File serialization methods
  - Comparison operators

### Database Class
- **Attributes**: Vector of Student objects
- **Key Methods**:
  - CRUD operations (Create, Read, Update, Delete)
  - File I/O operations
  - Sorting methods
  - Search and filter methods

## Development Guidelines

### Code Style
- Use consistent indentation (4 spaces)
- Follow C++ naming conventions
- Include proper header guards
- Add meaningful comments
- Handle exceptions appropriately

### Adding New Features

1. **Add Tests** - Create test cases in the `tests/` directory
2. **Update Documentation** - Modify this README as needed
3. **Follow SOLID Principles** - Keep classes focused and extensible

## Testing

Currently, the project includes basic validation and error handling. Future versions will include:
- Unit tests for Student and Database classes
- Integration tests for file operations
- Performance tests for large datasets

## Troubleshooting

### Common Issues

1. **Compilation Errors**
   - Ensure C++17 support is available
   - Check that all source files are included
   - Verify include paths are correct

2. **File Access Issues**
   - Check file permissions for students.txt
   - Ensure the application has write access to the directory
   - Verify file path is correct

3. **Runtime Errors**
   - Validate input data formats
   - Check for duplicate student IDs
   - Ensure GPA values are within valid range (0.0-4.0)

## Future Enhancements

- [ ] Graphical User Interface (GUI)
- [ ] Database integration (SQLite/MySQL)
- [ ] Advanced search and filtering options
- [ ] Data export to different formats (CSV, JSON, XML)
- [ ] Student photo management
- [ ] Grade tracking and transcript generation
- [ ] Network-based multi-user support
- [ ] Data encryption for sensitive information

## Contributing

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/new-feature`)
3. Commit your changes (`git commit -am 'Add new feature'`)
4. Push to the branch (`git push origin feature/new-feature`)
5. Create a Pull Request

## License

This project is open source and available under the [MIT License](LICENSE).

## Contact

For questions or suggestions, please open an issue on the GitHub repository.

---

**Version**: 1.0.0  
**Last Updated**: October 2024  
**Compatibility**: C++17, CMake 3.10+

