#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>
using namespace std;
class HostelAllocation
{
private:
    string studentName;
    string indexNumber;
    string gender;
    string programme;
    string roomNumber;
    string roomType;
    int roomCapacity;
    int currentOccupants;
    string allocationStatus;
public:
    HostelAllocation()
    {
        studentName = "";
        indexNumber = "";
        gender = "";
        programme = "";
        roomNumber = "";
        roomType = "";
        roomCapacity = 0;
        currentOccupants = 0;
        allocationStatus = "";
    }
    void setStudentDetails()
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\n------------------------------------------";
        cout << "\nENTER STUDENT DETAILS";
        cout << "\n------------------------------------------";
        cout << "\nStudent Name: ";
        getline(cin, studentName);
        cout << "Index Number: ";
        getline(cin, indexNumber);
        cout << "Gender: ";
        getline(cin, gender);
        cout << "Programme: ";
        getline(cin, programme);
        cout << "\nENTER ROOM DETAILS";
        cout << "\nRoom Number: ";
        getline(cin, roomNumber);
        cout << "Room Type: ";
        getline(cin, roomType);
        cout << "Room Capacity: ";
        cin >> roomCapacity;
        cout << "Current Occupants: ";
        cin >> currentOccupants;
    }
    bool validateDetails()
    {
        if (studentName.empty() || roomNumber.empty())
        {
            allocationStatus = "Invalid student or room entry";
            return false;
        }
        if (roomCapacity <= 0)
        {
            allocationStatus = "Invalid room capacity";
            return false;
        }
        if (currentOccupants < 0)
        {
            allocationStatus = "Invalid current occupants";
            return false;
        }
        return true;
    }
    bool checkRoomAvailability()
    {
        if (!validateDetails())
            return false;
        if (currentOccupants > roomCapacity)
        {
            allocationStatus = "Invalid room record";
            return false;
        }
        if (currentOccupants == roomCapacity)
        {
            allocationStatus = "Room Full - Allocation Rejected";
            return false;
        }
        allocationStatus = "Allocated Successfully";
        currentOccupants++;
        return true;
    }
    void displayAllocationReport()
    {
        cout << "\n====================================";
        cout << "\nHOSTEL ALLOCATION REPORT";
        cout << "\n====================================";
        cout << "\nStudent Name : " << studentName;
        cout << "\nIndex Number : " << indexNumber;
        cout << "\nGender       : " << gender;
        cout << "\nProgramme    : " << programme;
        cout << "\nRoom Number  : " << roomNumber;
        cout << "\nRoom Type    : " << roomType;
        cout << "\nCapacity     : " << roomCapacity;
        cout << "\nOccupants    : " << currentOccupants;
        cout << "\nStatus       : " << allocationStatus << endl;
    }
    void saveReportToFile(ofstream &file)
    {
        file << "======================================" << endl;
        file << "HOSTEL ROOM ALLOCATION REPORT" << endl;
        file << "======================================" << endl;
        file << "Student Name : " << studentName << endl;
        file << "Index Number : " << indexNumber << endl;
        file << "Gender       : " << gender << endl;
        file << "Programme    : " << programme << endl;
        file << "Room Number  : " << roomNumber << endl;
        file << "Room Type    : " << roomType << endl;
        file << "Room Capacity: " << roomCapacity << endl;
        file << "Occupants    : " << currentOccupants << endl;
        file << "Status       : " << allocationStatus << endl;
        file << endl;
    }
};
//======================================================
// MAIN FUNCTION
//======================================================
int main()
{
    cout << "==========================================" << endl;
    cout << "     HOSTEL ROOM ALLOCATION SYSTEM" << endl;
    cout << "==========================================" << endl;
    int numberOfStudents;
    int successfulAllocations = 0;
    int rejectedAllocations = 0;
    cout << "\nEnter number of students to allocate: ";
    cin >> numberOfStudents;
    while (numberOfStudents <= 0)
    {
        cout << "Invalid number. Please enter a value greater than 0: ";
        cin >> numberOfStudents;
    }
    vector<HostelAllocation> students;
    ofstream reportFile("hostel_allocation_report.txt");
    if (!reportFile)
    {
        cout << "Error creating report file!" << endl;
        return 1;
    }
    reportFile << "==============================================" << endl;
    reportFile << "     HOSTEL ROOM ALLOCATION REPORT" << endl;
    reportFile << "==============================================" << endl << endl;
    for (int i = 0; i < numberOfStudents; i++)
    {
        cout << "\n==========================================" << endl;
        cout << "Student " << i + 1 << " of " << numberOfStudents << endl;
        cout << "==========================================" << endl;
        HostelAllocation student;
        student.setStudentDetails();
        bool allocated = student.checkRoomAvailability();
        if (allocated)
        {
            successfulAllocations++;
        }
        else
        {
            rejectedAllocations++;
        }
        student.displayAllocationReport();
        student.saveReportToFile(reportFile);
        students.push_back(student);
    }
    reportFile << "==============================================" << endl;
    reportFile << "SUMMARY" << endl;
    reportFile << "==============================================" << endl;
    reportFile << "Total Students Processed : "
               << numberOfStudents << endl;
    reportFile << "Successful Allocations   : "
               << successfulAllocations << endl;
    reportFile << "Rejected Allocations     : "
               << rejectedAllocations << endl;
    reportFile.close();
    cout << "\n==========================================" << endl;
    cout << "FINAL SUMMARY" << endl;
    cout << "==========================================" << endl;
    cout << "Total Students Processed : "
         << numberOfStudents << endl;
    cout << "Successful Allocations   : "
         << successfulAllocations << endl;
    cout << "Rejected Allocations     : "
         << rejectedAllocations << endl;
    cout << "\nReport saved successfully to hostel_allocation_report.txt" << endl;
    cout << "\nThank you for using the Hostel Room Allocation System." << endl;
    return 0;
}
