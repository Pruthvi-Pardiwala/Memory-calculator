#include <iostream>
#include <vector>
using namespace std;

template <class T1, class T2>
class MemoryCalculate
{
    T1 id;
    T2 name;

public:
    MemoryCalculate(T1 i, T2 n)
    {
        id = i;
        name = n;
    }

    void display() const
    {
        cout << "ID: " << id << " | Name: " << name << endl;
    }

    T1 getId() const
    {
        return id;
    }
};

class StudentManagement
{
    vector<MemoryCalculate<int, string>> students;

public:
    void addStudent(int id, string name)
    {
        students.push_back(MemoryCalculate<int, string>(id, name));
    }

    void displayAll()
    {
        if (students.empty())
        {
            cout << "No students available." << endl;
            return;
        }
        cout << endl
             << "List of Students: " << endl;
        for (size_t i = 0; i < students.size(); i++)
        {
            students[i].display();
        }
    }

    void removeStudent(int id)
    {
        bool found = false;
        for (auto it = students.begin(); it != students.end(); ++it)
        {
            if (it->getId() == id)
            {
                students.erase(it);
                cout << "Student with ID " << id << " removed." << endl;
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "Student with ID " << id << " not found." << endl;
        }
    }

    void searchStudent(int id)
    {
        bool found = false;
        for (size_t i = 0; i < students.size(); i++)
        {
            if (students[i].getId() == id)
            {
                cout << "Student Found: ";
                students[i].display();
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "Student with ID " << id << " not found." << endl;
        }
    }
};

int main()
{
    StudentManagement sm;
    int choice, id;
    string name;

    do
    {
        cout << endl
             << "--- Student Management System ---" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display All Students" << endl;
        cout << "3. Remove Student by ID" << endl;
        cout << "4. Search Student by ID" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin >> name;
            sm.addStudent(id, name);
            break;
        case 2:
            sm.displayAll();    
            break;
        case 3:
            cout << "Enter ID to remove: ";
            cin >> id;
            sm.removeStudent(id);
            break;
        case 4:
            cout << "Enter ID to search: ";
            cin >> id;
            sm.searchStudent(id);
            break;
        case 0:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 0);

    return 0;
}

// output


// --- Student Management System ---
// 1. Add Student
// 2. Display All Students
// 3. Remove Student by ID
// 4. Search Student by ID
// 0. Exit
// Enter your choice: 1
// Enter ID: 1
// Enter Name: po

// --- Student Management System ---
// 1. Add Student
// 2. Display All Students
// 3. Remove Student by ID
// 4. Search Student by ID
// 0. Exit
// Enter your choice: 1
// Enter ID: 2
// Enter Name: ko

// --- Student Management System ---
// 1. Add Student
// 2. Display All Students
// 3. Remove Student by ID
// 4. Search Student by ID
// 0. Exit
// Enter your choice: 1
// Enter ID: 3
// Enter Name: lo

// --- Student Management System ---
// 1. Add Student
// 2. Display All Students
// 3. Remove Student by ID
// 4. Search Student by ID
// 0. Exit
// Enter your choice: 2

// List of Students: 
// ID: 1 | Name: po
// ID: 2 | Name: ko
// ID: 3 | Name: lo

// --- Student Management System ---
// 1. Add Student
// 2. Display All Students
// 3. Remove Student by ID
// 4. Search Student by ID
// 0. Exit
// Enter your choice: 4
// Enter ID to search: 3
// Student Found: ID: 3 | Name: lo

// --- Student Management System ---
// 1. Add Student
// 2. Display All Students
// 3. Remove Student by ID
// 4. Search Student by ID
// 0. Exit
// Enter your choice: 3
// Enter ID to remove: 3
// Student with ID 3 removed.

// --- Student Management System ---
// 1. Add Student
// 2. Display All Students
// 3. Remove Student by ID
// 4. Search Student by ID
// 0. Exit
// Enter your choice: 2

// List of Students: 
// ID: 1 | Name: po
// ID: 2 | Name: ko

// --- Student Management System ---
// 1. Add Student
// 2. Display All Students
// 3. Remove Student by ID
// 4. Search Student by ID
// 0. Exit
// Enter your choice: 
