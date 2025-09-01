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
        int index = -1;

        for (size_t i = 0; i < students.size(); ++i)
        {
            if (students[i].getId() == id)
            {
                index = static_cast<int>(i);
                break;
            }
        }

        if (index != -1)
        {
            students.erase(students.begin() + index);
            cout << "Student with ID " << id << " removed." << endl;
        }
        else
        {
            cout << "Student with ID " << id << " not found." << endl;
        }
    }

    void searchStudent(int id)
    {
        int index = -1;

        for (size_t i = 0; i < students.size(); ++i)
        {
            if (students[i].getId() == id)
            {
                index = static_cast<int>(i);
                break;
            }
        }

        if (index != -1)
        {
            cout << "Student Found: ";
            students[index].display();
        }
        else
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
