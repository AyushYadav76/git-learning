#!/usr/bin/env bash
mkdir -p attendance/{raw,processed,backup}
cat > attendance/raw/attendance.csv <<'CSV'
Name,RollNo,Status
Ayush,101,Present
Neha,102,Absent
Ravi,103,Present
Simran,104,Absent
Ankit,105,Present
CSV
awk -F',' 'NR==1 || tolower($3)=="present"{print $0}' attendance/raw/attendance.csv > attendance/processed/present.txt
cp attendance/processed/present.txt attendance/backup/present_$(date +%F).txt
echo "Attendance processing complete."
