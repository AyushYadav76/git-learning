import os
class LMS:
    def __init__(self):
        self.students = []  
        
    def add_student(self, Eno, name):
        student = {
            'Eno': Eno,
            'name': name,
            'course': "",
            'fee': 0.0,
            'book': "",
            'date': ""
        }
        self.students.append(student)
        print(f"Student added: {Eno}, {name}")

    def enroll_course(self, Eno, course, fee):
        for student in self.students:
            if student['Eno'] == Eno:
                student['course'] = course
                student['fee'] = fee
                print(f"Course enrolled: {course} with fee {fee}")
                return
        print("Student not found.")

    def issue_book(self, Eno, book, date):
        for student in self.students:
            if student['Eno'] == Eno:
                student['book'] = book
                student['date'] = date
                print(f"Book issued: {book} on {date}")
                return
        print("Student not found.")

    def search_by_enrollment(self, Eno):
        
        for student in self.students:
            if student['Eno'] == Eno:
                print(f"\n--- All Details ---")
                print(f"Enrollment No: {student['Eno']}")
                print(f"Name: {student['name']}")
                print(f"Course: {student['course']}")
                print(f"Fee: {student['fee']}")
                print(f"Book Issued: {student['book']}")
                print(f"Issue Date: {student['date']}")
                return
        print("Enrollment number not found.")

    def search_by_name(self, name):
        
        for student in self.students:
            if student['name'].lower() == name.lower():
                print(f"\n--- Name Search Result ---")
                print(f"Enrollment No: {student['Eno']}")
                return
        print("Name not found.")

    def search_by_course(self, course):
        
        for student in self.students:
            if student['course'].lower() == course.lower():
                print(f"\n--- Course Search Result ---")
                print(f"Enrollment No: {student['Eno']}")
                print(f"Course: {student['course']}")
                print(f"Fee: {student['fee']}")
                return
        print("Course not found.")

    def search_by_book(self, book):
        for student in self.students:
            if student['book'].lower() == book.lower():
                print(f"\n--- Book Search Result ---")
                print(f"Enrollment No: {student['Eno']}")
                print(f"Issue Date: {student['date']}")
                return
        print("Book not found.")

if __name__ == "__main__":
    lms = LMS()
    
    lms.add_student(1, "Alice")
    lms.enroll_course(1, "Python Programming", 500.0)
    lms.issue_book(1, "Learn Python", "2024-06-01")
    
    lms.add_student(2, "Bob")
    lms.enroll_course(2, "Data Science", 700.0)
    lms.issue_book(2, "Data Science Handbook", "2024-06-02")
    
    lms.add_student(3, "Charlie")
    lms.enroll_course(3, "Web Development", 600.0)  
    lms.issue_book(3, "HTML & CSS", "2024-06-03")
    
    while True:
        print("\n=== LMS Search Menu ===")
        print("1. Search by Enrollment Number")
        print("2. Search by Name")
        print("3. Search by Course Name")
        print("4. Search by Book")
        print("5. Exit")
        
        choice = input("\nEnter your choice (1-5): ").strip()
        
        if choice == "1":
            try:
                eno = int(input("Enter Enrollment Number: "))
                lms.search_by_enrollment(eno)
                input("\nPress Enter to continue...")
            except ValueError:
                print("Invalid input. Please enter a number.")
                input("\nPress Enter to continue...")
        
        elif choice == "2":
            name = input("Enter Student Name: ").strip()
            lms.search_by_name(name)
            input("\nPress Enter to continue...")
        
        elif choice == "3":
            course = input("Enter Course Name: ").strip()
            lms.search_by_course(course)
            input("\nPress Enter to continue...")
        
        elif choice == "4":
            book = input("Enter Book Name: ").strip()
            lms.search_by_book(book)
            input("\nPress Enter to continue...")
        
        elif choice == "5":
            print("Exiting... Goodbye!")
            break
        
        else:
            print("Invalid choice. Please enter 1-5.")
            input("\nPress Enter to continue...")  

                                          