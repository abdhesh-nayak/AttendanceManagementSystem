#include<iostream>
#include<string.h>
#include<conio.h>
#include<fstream>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<windows.h>
#define clrscr() system("cls");

using namespace std;


//Function Declaration

void file();
void front();
int password();
int mainstart();
void Delay(int x=2);


void setcolor(int ForgC) //function to change setcolor
 {
	WORD wColor;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 	{
  		wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
		SetConsoleTextAttribute(hStdOut, wColor);
	}
	return;
}


int exporting(int x,int y){
setcolor(x);
char a=177,b=219;
cout<<"\n\t\t\t\t\t Exporting......";
cout<<"\n\n";
cout<<"\t\t\t\t\t ";
setcolor(y);
for(int i=0;i<=30;i++)
	cout<<a;
	Sleep(100);
	cout<<"\r";
	cout<<"\t\t\t\t\t ";
	for(int i=0;i<=30;i++)
	{
		cout<<b;
		Sleep((i-i/2)*(i/2));
	}
//	system("pause>0");
	return 0;
	
}


int loading(int x,int y){
setcolor(x);
char a=177,b=219;
cout<<"\n\t\t\t\t\t Loading......";
cout<<"\n\n";
cout<<"\t\t\t\t\t ";
setcolor(y);
for(int i=0;i<=25;i++)
	cout<<a;
	Sleep(100);
	cout<<"\r";
	cout<<"\t\t\t\t\t ";
	for(int i=0;i<=25;i++)
	{
		cout<<b;
		Sleep((i-i/2)*(i/2));
	}
//	system("pause>0");
	return 0;
	
}

class PassStore //To Store The Password
{
	public:
		int Fileswitch;
		char password[10];
}ob8;






int password()   /*Password*/
{
	char temp3[2000];
	fstream t1;
	ob8.Fileswitch=5;
	t1.open("Studata/BasicData.txt",ios::in);
	t1.seekg(0);
	while(t1.read((char*)&ob8,sizeof(ob8)))
	{}
	t1.close();
	char password[10],ch,temp[10],temp2[10]={"close"};
	strcpy(temp,ob8.password);
	int i;
	start:

	printf("\nTo Open Admin Portion Enter The Password: \n");
	char dumm[]={"************"};
	int j;
	for(i=0;i <5;i++)
	{
		ch = getch();
		password[i] = ch;
		cout<<dumm[i];
		int a =	ch;
		if(a==8)
		{
			cout<<"\b\b  \b\b";
			if(0<i)
				i=i-2;
			else if(0==i)
				i=i-1;
		}
	}

	if((temp[0]==password[0])&&(temp[1]==password[1])&&(temp[2]==password[2])&&(temp[3]==password[3])&&(temp[4]==password[4]))
	{
		
		strcpy(temp3,"\n\n\t+++++++++++++++++++++++++++++++++++++++\n\tPASSWORD RIGHT....ACCESS GRANTED\n\t+++++++++++++++++++++++++++++++++++++++\n");
		int l=strlen(temp3);
		for(int i=0;i<l;i++)
		{
			cout<<temp3[i];
			Delay();
		}
		
		loading(5,10);
		return 1;
	}
	else if ((temp2[0]==password[0])&&(temp2[1]==password[1])&&(temp2[2]==password[2])&&(temp2[3]==password[3])&&(temp2[4]==password[4]))
	{
		return 0;
	}
	else
	{
		{
			strcpy(temp3,"\n\n\t+++++++++++++++++++++++++++++++++++++++\n\tPASSWORD WRONG....ACCESS DENIED\n\t+++++++++++++++++++++++++++++++++++++++\n");
		int l=strlen(temp3);
		for(int i=0;i<l;i++)
		{
			cout<<temp3[i];
			Delay();
		}
			cout<<"\n\nPassword is WRONG Try Again Or Type ( close ) To Close";
			goto start;
		}
	}
}



//File Function to Creat File in Folder
void file()
{
	fstream t1;
	ob8.Fileswitch=5;
	t1.open("Studata/BasicData.txt",ios::in);
	t1.seekg(0);
	while(t1.read((char*)&ob8,sizeof(ob8)))
	{

	}
	t1.close();
	if(ob8.Fileswitch==5)
	{
        mkdir("Studata");			//Directary Creat
    //	mkdir("classrecord/BasicData");
		 //File creations
	    ofstream filetest("Studata/BasicData.txt"),expdataex("Studata/AttendanceList.csv"),alldata("Studata/studata.txt");
		
		t1.open("Studata/BasicData.txt",ios::in|ios::out|ios::ate);
		ob8.Fileswitch=1;
		char fscreen[200]="\n\t This is The First Time You Opening The Program\n\n\t\tTo Secure Your Data Enter A Five Digit Password :";
		int l=strlen(fscreen);
		for(int i=0;i<l;i++)
		{
			cout<<fscreen[i];
			Delay(5);
		}
		fgets(ob8.password,6,stdin);
		strcpy(fscreen,"\n\t\tYour Password is...: ");
		l=strlen(fscreen);
		for(int i=0;i<l;i++)
		{
			cout<<fscreen[i];
			Delay(5);
		}
		cout<<ob8.password;
		strcpy(fscreen," \n\t\tNext Time You Will  Need This Password To Open The Program");
		l=strlen(fscreen);
		for(int i=0;i<l;i++)
		{
			cout<<fscreen[i];
			Delay(5);
		}
		getch();
		t1.write((char*)&ob8,sizeof(ob8));
		t1.close();	
	}

}
void front()      /*Front page display*/
{
	clrscr();
	char temp[2000]="\t++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n\t\t\t    WELCOME TO PROGRAM\n\n\t++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n\t\t\t Attendance Management System\n\t\t\t Created Date: 2018-12-07\n\n\n\n\n\n\n\n\n\n\nSUBMITED TO:\t\t\t\t\t\tSUBMITED BY:\n     \t\t\t\t\t\t   1.Ripunjay Yadav\n     \t\t\t\t\t\t   2.Subash Gole\n     \t\t\t\t\t\t   3.Puja Bista\n";
	int l=strlen(temp);
		for(int i=0;i<l;i++)
	{
		cout<<temp[i];
		Sleep(5);
	}
}

void Delay(int x)
{ int m=0,s=0,ms=0,mms=0,h=0;
while(h<2)
{
	mms++;

	if(mms==5){
		mms=0;
		ms++;
	if(ms==59){
		ms=0;
		s++;
		if(s==59){
			s=0;
			m++;
			if(m==59){
				m=0;
				h++;
			}
		}
	}
	}
}
}


