Start

Display project title “HOSTEL ROOM ALLOCATION SYSTEM” and welcome system text interface

Initialize totalStudents

Set successfulAllocations=0

Set rejectedAllocations=0

Open file “hostel_allocation_report.txt” in write mode

Prompt user for totalStudents 

Read Input

Loop for each student from 1 to totalStudents

Input studentName

Input gender

Input programme

Input roomNumber

Input roomType

Input roomCapacity

Input cuurrentOccupants

IF studentName = 0, roomNumber=0

Display “Invalid student or Room entry”

ELSE IF roomCapacity≤0, 

Display “Invalid Room Capacity”

ELSE IF currentOccupants = roomCapacity,

Display “Room Full”

ELSE,

Display “Allocated Successfully”

Display allocation status to screen

Write student details, room details, and allocation status to “hostel_allocation_report.txt”

Close “hostel_allocation_report.txt”

Display confirmation message “Report saved to hostel_allocation_report.txt”

Stop
