/*Student Record Management project*/
#include<iostream>
using namespace std;
class student{ 
    public :
    string name;
    int roll;
    int marks[5];
    int total =0;
    float avg;
    char grade;
    string Result;
    //INPUT FUNCTION
    void input(){
        total =0;
        cout<<"Name : ";
        getline(cin,name);
        cout<<"Roll no : ";
        cin>>roll;
        cout<<"Please enter subject wise mark - \n";
        for(int i=0 ;i<5;i++){
            cout<<"Mark of subject  "<<i+1<<" : " ;
            cin>>marks[i];
            //Mark must be between 0 - 100
            while (marks[i] < 0 || marks[i] > 100) {
                cout << "Invalid mark! Enter again: ";
                cin >> marks[i];
            }
            total+=marks[i];
        }
        avg =total /5.0;
        calculategrade();
        showresult();
}
//GRADE CALCULATE FUNCTION
void calculategrade(){
    if(avg>=90) grade ='O';
    else if(avg>=80) grade ='A';
    else if(avg>=70) grade ='B';
    else if(avg>=60) grade ='C';
    else if(avg>=50) grade ='D';
    else grade ='F';
}
//FUNCTION TO SHOW STUDENT IS PASSED OR NOT
void showresult(){
    if(avg<50) Result="Fail";
    else Result ="Pass";
}
//FUNCTION TO DISPLAY STUDENT INFORMATION
void display(){
    cout<<"\n=======================\n";
    cout<<"Name :"<<name<<endl;
    cout<<"Roll :"<<roll<<endl;
    cout<<"Total marks :"<<total<<endl;
    cout<<"Average mark :"<<avg<<endl;
    cout<<"Grade :"<<grade<<endl;
    cout<<"Result  :"<<Result<<endl;
    
}
};

int main(){
student s1[50];
int n;
cout<<"Enter number of student : \n";
cin>>n;
while(n>50){
    cout<<"Student capacity is less than or equal to 50  please re-enter \n";
    cin>>n;
}
cin.ignore();
for(int i=0;i<n;i++){
    cout<<"Enter details of student "<<i+1<<endl;
s1[i].input();
cin.ignore();
};
cout<<"===========================STUDENT INFORMATION=========================\n";
for(int i=0;i<n;i++){
    cout<<endl<<i+1<<"th  Student  information :\n";
s1[i].display();
};

return 0;
}

