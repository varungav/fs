#include<stdio.h> 
#include<stdlib.h> 
#include<conio.h> 
#include<iostream> 
#include<fstream> 
#include<string.h> 
#include<iomanip>
using namespace std;
class student
{
public: char name[10];
char usn[10]; char age[5]; char sem[5]; char branch[5];
char buffer[100];
};
fstream file; 
student s;
void writerecord()
{
file.open("program_3.txt",ios::app); if(!file)
{
cout<<"cannot open the file in append mode"; getch();
exit(1);
}
cout<<"\nenter the student name = "; cin>>s.name;
cout<<"\nenter the usn = "; cin>>s.usn; cout<<"\nenter the age = "; cin>>s.age;
cout<<"\nenter the sem = "; cin>>s.sem;
cout<<"\nenter the branch = "; cin>>s.branch;
strcpy(s.buffer,s.name); strcat(s.buffer,"|"); strcat(s.buffer,s.usn); strcat(s.buffer,"|"); strcat(s.buffer,s.age); strcat(s.buffer,"|"); strcat(s.buffer,s.sem); strcat(s.buffer,"|");
strcat(s.buffer,s.branch);
strcat(s.buffer,"\n"); file<<s.buffer; file.close();
}
void search()
{
char usn[10]; char extra[45];
file.open("program_3.txt",ios::in); if(!file)
{
cout<<"\nunable to open the file in read mode"; getch();
exit(0);
}
cout<<"\nenter the record's usn you want to search = "; cin>>usn;
while(!file.eof())
{
file.getline(s.name,10,'|');
file.getline(s.usn,10,'|');
file.getline(s.age,5,'|');
file.getline(s.sem,5,'|'); file.getline(s.branch,5,'\n');
if(strcmp(s.usn,usn)==0)
{
cout<<"\nrecord found"; cout<<"\nname\tusn\tage\tsem\tbranch";
cout<<"\n"<<s.name<<"\t"<<s.usn<<"\t"; cout<<s.age<<"\t"<<s.sem<<"\t"<<s.branch;
file.close();
getch(); return;
}
}
cout<<"\nrecord not found"; file.close();
getch(); return;
}
void displayFile()
{
int i; file.open("program_3.txt",ios::in);
if(!file)
{
}
cout<<"\ncannot open the file in read mode"; getch();
exit(1);
i=0;
printf("\n\nNAME\t\tUSN\t\tAGE\t\tSEM\t\tBRANCH\n");
while(!file.eof())
{
file.getline(s.name,15,'|');
file.getline(s.usn,15,'|');
file.getline(s.age,5,'|');
file.getline(s.sem,5,'|'); file.getline(s.branch,5,'\n');
printf("\n%s\t\t%s\t\t%s\t\t%s\t\t%s",s.name,s.usn,s.age,s.sem,s.branch); i++;
}
file.close();
getch();
}
void modify()
{
char usn[10];
int i; int j;
student s[100];
file.open("program_3.txt",ios::in); if(!file)
{
cout<<"\nunable to open the file in input mode"; getch();
exit(1);
}
cout<<"\nenter the usn "; cin>>usn;
i=0;
while(!file.eof())
{
file.getline(s[i].name,15,'|');
file.getline(s[i].usn,15,'|');
file.getline(s[i].age,5,'|');
file.getline(s[i].sem,5,'|');
file.getline(s[i].branch,5,'\n'); i++;
}
i--;
for(j=0;j<i;j++)
{
if(strcmp(usn,s[j].usn)==0)
{
cout<<"\nthe old values of the record with usn"<<usn<<"are"; cout<<"\nname = "<<s[j].name;
cout<<"\nusn = "<<s[j].usn; cout<<"\nage = "<<s[j].age; cout<<"\nsem = "<<s[j].sem; cout<<"\nbranch = "<<s[j].branch;
cout<<"\nenter the new values\n"; cout<<"\nname = "; cin>>s[j].name;
cout<<"\nusn = "; cin>>s[j].usn; cout<<"\nage = "; cin>>s[j].age; cout<<"\nsem = "; cin>>s[j].sem; cout<<"\nbranch = "; cin>>s[j].branch; break;
}
}
if(j==i)
{
}
cout<<"\nthe record with usn " <<usn<< "is not present "; getch();
return;
file.close();
file.open("program_3.txt",ios::out); if(!file)
{
cout<<"\nunable to open the file in output mode"; getch();
return;
}
for(j=0;j<i;j++)
{
file<<s[j].name<<'|'<<s[j].usn<<'|'<<s[j].age
<<'|'<<s[j].sem<<'|'<<s[j].branch<<'\n';
}
file.close();
}
int main()
{
int choice; while(1)
{
//clrscr(n);
cout<<"\n 0 : exit"; cout<<"\n 1 : write to file";
cout<<"\n 2 : display the file"; cout<<"\n 3 : modify the file"; cout<<"\n 4 : search"; cout<<"\n\n enter the choice : "; cin>>choice;
switch(choice)
{
case 1: writerecord(); break;
case 2: displayFile(); break;
case 3: modify();
break;
case 4: search();
break; case 0: exit(0);
default: cout<<"\ninvalid input..."; break;
}
}
}
