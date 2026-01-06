/* OOP program */
#include <iostream>
#include <iomanip> // Added for formatting output

class Student {
private:
    int roll;
    std::string name;
    std::string department;
    int maths;
    int physics;
    int chemistry;

public:
Student()
{
        roll=0;
        name="";
        department="";
        maths=0;
        physics=0;
        chemistry=0;
}
    Student(int a)
     {
        std::cout << "Enter student details (Roll, Name, Department, Maths marks, Physics marks, Chemistry marks): ";
        std::cin >> roll >> name >> department >> maths >> physics >> chemistry;
    }

    void calculateAverage() {
        int total = maths + physics + chemistry;
        avg = static_cast<float>(total) / 3;
    }

    void display() const {
        std::cout << "\nStudent Details:\n";
        std::cout << "Roll Number: " << roll << '\n';
        std::cout << "Name: " << name << '\n';
        std::cout << "Department: " << department << '\n';
        std::cout << "Maths Marks: " << maths << '\n';
        std::cout << "Physics Marks: " << physics << '\n';
        std::cout << "Chemistry Marks: " << chemistry << '\n';
        std::cout << "Total: " << maths + physics + chemistry << '\n';
        std::cout << "Average: " << std::fixed << std::setprecision(2) << avg << '\n';
    }

private:
    float avg;
};

int main() {
    Student s1,s2,s3; // Changed from 'S' to 's1'
    
    s1.calculateAverage();
    s1.display();
    s2.display();
    s3.display();
    return 0;
}
