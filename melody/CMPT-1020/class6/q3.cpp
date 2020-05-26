#include <iostream>
#include <string.h>
using namespace std;
class Student{
    private:
        string firstName;
        string lastName;
        string studentID;
        string phoneNumber;
        double gpa;
    public:
        Student(){
            firstName=" ";
            lastName=" ";
            studentID=" ";
            phoneNumber=" ";
            gpa=0;
        }
        Student(string tfirstName, string tlastName, string tstudentID, string tphoneNumber, double tgpa){
            firstName=tfirstName;
            lastName=tlastName;
            studentID=tstudentID;
            phoneNumber=tphoneNumber;
            gpa=tgpa;
        }

        string getFirstName(){
            return firstName;
        }

        string getLastName(){
            return lastName;
        }

        string getStudentID(){
            return studentID;
        }
        string getPhoneNumber(){
            return phoneNumber;
        }

        double getGPA(){
            return gpa;
        }
        void setFirstName(string tfirstName){
            firstName=tfirstName;
        }
        void setLastName(string tlastName){
            lastName=tlastName;
        }
        void setStudentID(string tstudentID){
            studentID=tstudentID;
        }
        void setPhoneNumber(string tphoneNumber){
            phoneNumber=tphoneNumber;
        }
        void setGPA(double tgpa){
            gpa=tgpa;
        }

        void input(){
            cout<<"Enter the Student ID: ";
            cin>>studentID;
            cout<<"Enter the Student First Name: ";
            cin>>firstName;
            cout<<"Enter the Student Last Name: ";
            cin>>lastName;
            cout<<"Enter the Student Phone Number: ";
            cin>>phoneNumber;
            cout<<"Enter the Student GPA: ";
            cin>>gpa;
        }
        friend ostream& operator<<(ostream& os, Student *student);
};

ostream& operator<<(ostream& os, Student *student)
{
    os << "Student ID: "<<student->getStudentID()<<endl;
    os << "Student First Name: "<<student->getFirstName()<<endl;
    os << "Student Last Name: "<<student->getLastName()<<endl;
    os << "Student Phone Number: "<<student->getPhoneNumber()<<endl;
    os << "Student GPA: "<<student->getGPA()<<endl;

    return os;
}

class Course{
    private:
        string code;
        int section;
        int capacity;
        int numStudents;
        Student **list;

    public:
        Course(){
            code="CMPT1020";
            section=1;
            capacity=35;
            numStudents=0;
            list = new Student*[capacity];
            for (int i = 0; i<capacity; i++){
                list[i] = new Student();
            }
        }
        void operator=(const Course& existing)
        {
            delete[] this->list;
            this->code= existing.code;
            this->capacity = existing.capacity;
            this->section = existing.section;
            this-> list= new Student*[this->capacity];
            this->numStudents = existing.numStudents;
            for (int i = 0; i < numStudents; i++)
                list[i] = existing.list[i];
        }
                Course(const Course& existing)
        {
            this->code= existing.code;
            this->capacity = existing.capacity;
            this->section = existing.section;
            this-> list= new Student*[this->capacity];
            this->numStudents = existing.numStudents;
            for (int i = 0; i < numStudents; i++)
                list[i] = existing.list[i];
        }

        Course(string tcode, int tsection, int tcapacity){
            code=tcode;
            section=tsection;
            capacity=tcapacity;
            numStudents=0;
            list = new Student*[capacity];
            for (int i = 0; i<capacity; i++){
                list[i] = new Student();
            }
        }

        string getCode(){
            return code;
        }
        int getSection(){
            return section;
        }
        int getCapacity(){
            return capacity;
        }

        int getNumStudents(){
            return numStudents;
        }

        void setCode(string tcode){
            code=tcode;
        }

        void setSection(int tsection){
            section=tsection;
        }

        void add(){
            if(numStudents<capacity){
                cout<<"Enter Student "<<(numStudents+1)<<" Details: "<<endl;
                list[numStudents]->input();
                numStudents++;
            }
            else{
                cout<<"Student List already Full";
            }
        }

        void display(){
            for(int i=0;i<numStudents;i++){
                cout<<list[i];
                cout<<endl;
            }
        }

        void display(string data, int key){
            cout<<"Search Results: ";

            bool found=false;
            if(key==1){
                for(int i=0;i<numStudents;i++){
                    if(list[i]->getFirstName().compare(data)==0){
                        found=true;
                        cout<<list[i]<<endl;
                    }
                }
            }
            else if(key==2){
                for(int i=0;i<numStudents;i++){
                    if(list[i]->getLastName().compare(data)==0){
                        found=true;
                        cout<<list[i]<<endl;
                    }
                }
            }
            else if(key==3){
                for(int i=0;i<numStudents;i++){
                    if(list[i]->getStudentID().compare(data)==0){
                        found=true;
                        cout<<list[i]<<endl;
                    }
                }
            }
            else if(key==4){
                for(int i=0;i<numStudents;i++){
                    if(list[i]->getPhoneNumber().compare(data)==0){
                        found=true;
                        cout<<list[i]<<endl;
                    }
                }
            }
            else{
                cout<<"Invalid Key. ";
            }
            if (!found){
                cout<< "Nil.";
            }
        }

        void remove(string data, int key){
            bool found=false;
            int index=-1;

            if(key==1){
                for(int i=0;i<numStudents;i++){
                    if(list[i]->getFirstName().compare(data)==0){
                        found=true;
                        index=i;
                    }
                }
            }
            else if(key==2){
                for(int i=0;i<numStudents;i++){
                    if(list[i]->getLastName().compare(data)==0){
                        found=true;
                        index=i;
                    }
                }
            }
            else if(key==3){
                for(int i=0;i<numStudents;i++){
                    if(list[i]->getStudentID().compare(data)==0){
                        found=true;
                        index=i;
                    }
                }
            }
            else if(key==4){
                for(int i=0;i<numStudents;i++){
                    if(list[i]->getPhoneNumber().compare(data)==0){
                        found=true;
                        index=i;
                    }
                }
            }
            else{
                cout<<"Invalid Key. ";
            }
            if (found){
                for(int i=index;i<numStudents-1;i++){
                    list[i]=list[i+1];
                }
                list[numStudents-1]=NULL;
                numStudents--;
                cout<<"Student data is deleted Successfully";
            }
        }

        void sort_the_list(int sortingMember, int order){
            if(sortingMember==1){
                if(order==0){
                    for(int i=0;i<numStudents;i++){
                        for(int j=i+1;j<numStudents;j++){
                            if(list[i]->getFirstName().compare(list[j]->getFirstName())>0){
                                Student *temp=list[i];
                                list[i]=list[j];
                                list[j]=temp;
                            }
                        }
                    }
                }
                else{
                    for(int i=0;i<numStudents;i++){
                        for(int j=i+1;j<numStudents;j++){
                            if(list[i]->getFirstName().compare(list[j]->getFirstName())<0){
                                Student *temp=list[i];
                                list[i]=list[j];
                                list[j]=temp;
                            }
                        }
                    }
                }
            }
            else if(sortingMember==2){
                if(order==0){
                    for(int i=0;i<numStudents;i++){
                        for(int j=i+1;j<numStudents;j++){
                            if(list[i]->getLastName().compare(list[j]->getLastName())>0){
                                Student *temp=list[i];
                                list[i]=list[j];
                                list[j]=temp;
                            }
                        }
                    }
                }
                else{
                    for(int i=0;i<numStudents;i++){
                        for(int j=i+1;j<numStudents;j++){
                            if(list[i]->getLastName().compare(list[j]->getLastName())<0){
                                Student *temp=list[i];
                                list[i]=list[j];
                                list[j]=temp;
                            }
                        }
                    }
                }
            }
            else if(sortingMember==3){
                if(order==0){
                    for(int i=0;i<numStudents;i++){
                        for(int j=i+1;j<numStudents;j++){
                            if(list[i]->getStudentID().compare(list[j]->getStudentID())>0){
                                Student *temp=list[i];
                                list[i]=list[j];
                                list[j]=temp;
                            }
                        }
                    }
                }
                else{
                    for(int i=0;i<numStudents;i++){
                        for(int j=i+1;j<numStudents;j++){
                            if(list[i]->getStudentID().compare(list[j]->getStudentID())<0){
                                Student *temp=list[i];
                                list[i]=list[j];
                                list[j]=temp;
                            }
                        }
                    }
                }
            }
            else if(sortingMember==4){
                if(order==0){
                    for(int i=0;i<numStudents;i++){
                        for(int j=i+1;j<numStudents;j++){
                            if(list[i]->getPhoneNumber().compare(list[j]->getPhoneNumber())>0){
                                Student *temp=list[i];
                                list[i]=list[j];
                                list[j]=temp;
                            }
                        }
                    }
                }
                else{
                    for(int i=0;i<numStudents;i++){
                        for(int j=i+1;j<numStudents;j++){
                            if(list[i]->getPhoneNumber().compare(list[j]->getPhoneNumber())<0){
                                Student *temp=list[i];
                                list[i]=list[j];
                                list[j]=temp;
                            }
                        }
                    }
                }
            }
            else if(sortingMember==5){
                if(order==0){
                    for(int i=0;i<numStudents;i++){
                        for(int j=i+1;j<numStudents;j++){
                            if(list[i]->getGPA()> list[j]->getGPA()){
                                Student *temp=list[i];
                                list[i]=list[j];
                                list[j]=temp;
                            }
                        }
                    }
                }
                else{
                    for(int i=0;i<numStudents;i++){
                        for(int j=i+1;j<numStudents;j++){
                            if(list[i]->getGPA()< list[j]->getGPA()){
                                Student *temp=list[i];
                                list[i]=list[j];
                                list[j]=temp;
                            }
                        }
                    }
                }
            }
        }

        ~Course(){
            for (int i = 0; i<capacity; i++){
                delete list[i];
            }
            delete[] list;
        }


};




int main()
{
    cout<<"Enter Course Code: ";
    string code;
    cin>>code;

    cout<<"Enter Course Section: ";
    int section;
    cin>>section;

    cout<<"Enter Course Capacity: ";
    int capacity;
    cin>>capacity;

    Course course(code,section,capacity);

    cout<<"\nEnter the number of student details to add now: ";
    int studentCount;
    cin>>studentCount;

    for(int i=0;i<studentCount;i++){
        course.add();
        cout<<endl;
    }

    cout<<"\nDetails of all the Student of the Course: "<<endl;
    course.display();

    Course g;
    g = course;
    g.display();

    return 0;
}
