BEGIN
Display “= = = = == = = = = = = = = = = = = = = = = = = = = = = = = = = = = =”
Display “HOSTEL ROOM ALLOCATION SYSTEM”
Display “= = = = == = = = = = = = = = = = = = = = = = = = = = = = = = = = = =”

Declare totalStudents
Declare successfulAllocations ←0
Declare rejectedAllocations ←0

Open file
“hostel_allocation_report.txt” for writing

Prompt user to enter number of students
Input totalStudents

FOR student = 1 TO totalStudents DO

Display “Enter Student Details”

Input studentName

Input indexNumber

Input gender

Input programme

Input roomNumber

Input roomType

Input roomCapacity

Input currentOccupants

IF studentName is empty OR roomNumber is empty THEN

allocationStatus ← “Invalid Student or Room Entry”

rejectedAllocations ← rejectedAllocations +1

ELSE IF roomCapacity ←0 THEN

allocationStatus ← “Invalid Room Capacity”

rejectedAllocations ← rejectedAllocations +1

ELSE IF currentOccupants ←0 THEN

allocationStatus ← “Invalid Number of Occupants”

rejectedAllocations ← rejectedAllocations +1

ELSE IF currentOccupants > roomCapacity THEN

allocationStatus ← “Invalid Room Record”

rejectedAllocations ← rejectedAllocations +1

ELSE IF currentOccupants = roomCapacity THEN

allocationStatus ← “Room Full – Allocation Rejected”

rejectedAllocations ← rejectedAllocations +1

ELSE

allocationStatus ← “Allocated Successfully”

currentOccupants ← currentOccupants +1

successfulAllocations ← successfulAllocations +1

END IF 

Display “Allocation Status:”,
allocationStatus

Write the following to hostel_allocation_report.txt

Student Name

Index Number

Gender

Programme

Room Number

Room Type

Room Capacity

Current Occupants

Allocation Status

END FOR

Display “= = = = == = = = = = = = = = = = = = = = = = = = = = = = = = = = = =”
Display “TOTAL STUDENTS PROCESSED:”, totalStudents
Display “SUCCESSFUL ALLOCATIONS:”, successfulAllocations
Display “REJECTED ALLOCATIONS:”, rejectedAllocations
Display “= = = = == = = = = = = = = = = = = = = = = = = = = = = = = = = = = =”

Write summary to hostel_allocation_report.txt

Close hostel_allocation_report.txt
Display “Report saved to hostel_allocation_report.txt”

END
