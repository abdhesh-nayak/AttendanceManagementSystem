

#include"help.cpp"

class dataOfStudent
{
	public:
	int attend[32][7];
//	int total;
}ob1;
class Data
{
	public:
	int monthLength;
	Data()
	{
		monthLength=30;
	}
	dataOfStudent stu[200];
};

class st
{
	public:
	int StudentNum;
	char Stu_Name[200][50];
	Data date[20][12];	
	
	void getStudent()
	{
		cout<<"\nEnter The Number of Student :";
		cin>>StudentNum;
		for(int i=0;i<StudentNum;i++)
		{
			cout<<"\nEnter The Name Of Student NO."<<i+1<<" :";
					char ch='\0';
		char temp[5];
		Stu_Name[i][0]='\0';
	//	cout<<"\nEnter the Name of the New Student:";
		do{
				ch=getch();
				if(ch==8)
				{
					cout<<"\b \b";
					Stu_Name[i][strlen(Stu_Name[i])-1]='\0';
				}
				else if(ch!=13)
				{
				cout<<ch;
				sprintf(temp,"%c",ch);
				strcat(Stu_Name[i],temp);
				}
		}while(ch!=13);
		//cout<<Stu_Name[StudentNum];
	//	getch();
	//	fgets(,50,stdin);
	//	StudentNum=StudentNum+1;
		}
	}
	
	mkAttendance_a(int year,int month,int day,int lect)
	{
	//	cout<<StudentNum;
		setcolor(4);
		cout<<"\n\n\tEnter 1 if Student is Prsent else Enter 0\n";
		setcolor(0);
	//	cout<<StudentNum;
		for(int i=0;i<StudentNum;i++)
		{
			cout<<"Enter For "<<Stu_Name[i]<<" : ";
			cin>>date[year][month].stu[i].attend[day][lect];
		}
		getch();
	}
	mkAttendance()
	{
		int year,month,day,lect;
		start:
		cout<<"\nSelect Present Year";
		int j=0;
		for(int i=2075;i<=2080;i++)
		{
			j++;
			cout<<"\n\t"<<j<<"."<<i;		
		}		
		cout<<"\n\t\tEnter Year(1-6) :";
		cin>>year;
		if(year<1||year>6)
		{
			cout<"You Entered Wrong Try Again";
			goto start;
		}
		start2:
		cout<<"Enter Current Month(1-12)";
		cin>>month;
		if(month<1||month>12)
		{
			cout<"You Entered Wrong Try Again";
			goto start2;
		}
		start3:
		cout<<"Enter Present Day(1-31)";
		cin>>day;
		if(day<1||day>31)
		{
			cout<"You Entered Wrong Try Again";
			goto start3;
		}
		
		start4:
		cout<<"Enter the current Lecture(1-7)";
		cin>>lect;
		if(lect<1||lect>7)
		{
			cout<"You Entered Wrong Try Again";
			goto start4;
		}
		mkAttendance_a(year-1,month-1,day-1,lect-1);
	}
	mkAttendanceone(int sn)
	{
		if(sn<=StudentNum)
		{
		int year,month,day,lect;
		start:
		cout<<"\nSelect Present Year";
		int j=0;
		for(int i=2075;i<=2080;i++)
		{
			j++;
			cout<<"\n\t"<<j<<"."<<i;		
		}		
		cout<<"\n\t\tEnter Year(1-6) :";
		cin>>year;
		if(year<1||year>6)
		{
			cout<"You Entered Wrong Try Again";
			goto start;
		}
		start2:
		cout<<"Enter Current Month(1-12)";
		cin>>month;
		if(month<1||month>12)
		{
			cout<"You Entered Wrong Try Again";
			goto start2;
		}
		start3:
		cout<<"Enter Present Day(1-31)";
		cin>>day;
		if(day<1||day>31)
		{
			cout<"You Entered Wrong Try Again";
			goto start3;
		}
		
		start4:
		cout<<"Enter the current Lecture(1-7)";
		cin>>lect;
		if(lect<1||lect>7)
		{
			cout<"You Entered Wrong Try Again";
			goto start4;
		}
		cout<<"\n\nEnter Attendance of "<<Stu_Name[sn-1]<<" : ";
		cin>>date[year-1][month-1].stu[sn-1].attend[day-1][lect-1];
		}
		else
		{
			cout<<"Wrong Serial Number..";
			return 0;
		}
	}
	void GetSingleStu()
	{
		char ch='\0';
		char temp[5];
		Stu_Name[StudentNum][0]='\0';
		cout<<"\nEnter the Name of the New Student:";
		do{
				ch=getch();
				if(ch==8)
				{
					cout<<"\b \b";
					Stu_Name[StudentNum][strlen(Stu_Name[StudentNum])-1]='\0';
				}
				else if(ch!=13)
				{
				cout<<ch;
				sprintf(temp,"%c",ch);
				strcat(Stu_Name[StudentNum],temp);
				}
		}while(ch!=13);
		//cout<<Stu_Name[StudentNum];
		getch();
	//	fgets(,50,stdin);
		StudentNum=StudentNum+1;
	}
}ob;

shwodata(int year,int month,int lect)
{
	char temp[50],temp2[2],temp5[100];
	char str[20000];
	strcpy(str,",,,,,,,Attendance List,,,,,,,,\n\nDate(YY/MM):");
	sprintf(temp,"%d",year+2075);
	strcat(str,temp);
	strcat(str,"/");
	sprintf(temp,"%d",month+1);
	strcat(str,temp);
	strcat(str,",,,,,,,,\n\nP for Present & A for Absent,,,,,,\n");
	strcat(str,"S.N,Students Name,,");
	for(int i=1;i<=31;i++)
	{
		strcpy(temp,temp2);
		sprintf(temp,"%d",i);
		strcat(str,temp);
		strcat(str,",");			
	}
	strcat(str,"\n");
	for(int i=1;i<=ob.StudentNum;i++)
	{
		
		sprintf(temp,"%d",i);
		strcat(str,temp);
		strcat(str,",");
		strcat(str,ob.Stu_Name[i-1]);
		strcat(str,",,");
		for(int j=0;j<31;j++)
		{
			if(ob.date[year][month].stu[i-1].attend[j][lect]==1)
			{
				strcat(str,"P,");
			}
			else
			{
				strcat(str,"A,");
			}
		}
		strcat(str,"\n");
	}	ofstream t1;
		remove("Studata/AttendanceList.csv");
		t1.open("Studata/AttendanceList.csv");
	//	cout<<str;
		t1.write((char*)&str,strlen(str));
		t1.close();
		system("start Studata/AttendanceList.csv");
		exporting(5,10);
		setcolor(0);
				strcpy(temp5,"\n\n\t+++++++++++++++++++++++++++++++++++++++\n\t\tEXPORTING COMPLETE\n\t+++++++++++++++++++++++++++++++++++++++\n");
		int l=strlen(temp5);
		for(int i=0;i<l;i++)
		{
			cout<<temp5[i];
			Delay();
		}
		cout<<"\n\tOpen The AttendanceList File Which is In the Studata Directory of The Application(exe) To See The Exported List\n";

}

ShowAttendance()
{
	cout<<"\n\n\tTo See The Result :\n";
	
		int year,month,day,lect;
		start:
		cout<<"\nSelect the Year";
		int j=0;
		for(int i=2075;i<=2080;i++)
		{
			j++;
			cout<<"\n\t"<<j<<"."<<i;		
		}		
		cout<<"\n\t\tEnter the Year(1-6) :";
		cin>>year;
		if(year<1||year>6)
		{
			cout<"You Entered Wrong Try Again";
			goto start;
		}
		start2:
		cout<<"Enter the Month(1-12)";
		cin>>month;
		if(month<1||month>12)
		{
			cout<"You Entered Wrong Try Again";
			goto start2;
		}
		start3:
		cout<<"Enter the lecture(1-7)";
		cin>>lect;
		if(lect<1||lect>7)
		{
			cout<"You Entered Wrong Try Again";
			goto start3;
		}
		shwodata(year-1,month-1,lect-1);
}

MakeAttendece()
{
	char ch;
	do{
		start:
			clrscr()
			cout<<"\nSelect An Operation\n\n\t1.Make Attendance Of A Day\n\t2.Update Attendance Of A Student\n\t3.Exit\n\tEnter Your Choice : ";
			cin>>ch;
			switch(ch)
			{
				case '1':
					ob.mkAttendance();					
					break;
				case '2':
					{
						int temp;
						cout<<"Enter Students Serial Number To Update Attendance of a Student";
						cin>>temp;
						ob.mkAttendanceone(temp);
						remove("Studata/studata.txt");
						ofstream wr;
						wr.open("Studata/studata.txt");
						wr.seekp(0);		
						wr.write((char*)&ob,sizeof(ob));
						wr.close();
				
						getch();
					}
					break;
				case '3':
				{
					cout<<"\n Exited";
				//	getch();
					return 0;
				}
			default:
				{
					setcolor(4);
					cout<<"\n\n\tWrong Choice Please Try Again\n";
					setcolor(0);
					getch();
					goto start;
				}
		}
	}while(ch!='3');
}


AddStudent()
{
	char ch;
	do{
		start:
			clrscr()
			cout<<"\nSelect An Operation\n\n\t1.Initialize All Students(First Time Compulsory)\n\t2.Add A New Student\n\t3.Exit\n\tEnter Your Choice : ";
			cin>>ch;
			switch(ch)
			{
				case '1':
					ob.getStudent();
					getch();	
					break;
				case '2':
					{
						ob.GetSingleStu();
					}
					break;
				case '3':
				{
					cout<<"\n Exited";
					return 0;
				}
			default:
				{
					setcolor(4);
					cout<<"\n\n\tWrong Choice Please Try Again\n";
					setcolor(0);
					getch();
					goto start;
				}
			}
	}while(ch!='3');
}

int mainStart()
{
	char ch;
	do{	
		ifstream rd;
		rd.open("Studata/studata.txt");
		rd.seekg(0);		
		rd.read((char*)&ob,sizeof(ob));
		rd.close();
		clrscr();
		start:
		cout<<"\nSelect An Operation\n\n\t1.See Attendance List\n\t2.Make Attendance of a day\n\t3.Add Students\n\t4.Exit\n\n\tEnter a Choice : ";
		cin>>ch;
		switch(ch)
		{
			case '1':	
			{
				ShowAttendance();
				rd.close();
				getch();
			}
				break;
			case '2':
			{
				MakeAttendece();
				remove("Studata/studata.txt");
				ofstream wr;
				wr.open("Studata/studata.txt");
				wr.seekp(0);		
				wr.write((char*)&ob,sizeof(ob));
				wr.close();
				getch();
			}	break;
			case '3':
			{
				AddStudent();
				remove("Studata/studata.txt");
				ofstream wr;
				wr.open("Studata/studata.txt");
				wr.seekp(0);		
				wr.write((char*)&ob,sizeof(ob));
				wr.close();
				getch();
			}	break;
			case '4':
				{
					cout<<"\n Exited";
					return 0;
				}
			default:
				{
					setcolor(4);
					cout<<"\n\n\tWrong Choice Please Try Again\n";
					setcolor(0);
					goto start;
				}
		}
	}while(ch!='4');
}






int main()
{
	system("color f2");
	file();	//to create files abn initialize password  if there is not preasent ¦	
	front();	//for intro of program
//	loading(5,10);	//for loading animation 
	system("color f0");
	password();
	system("color f0");
	clrscr();
	setcolor(0);
	mainStart();	//for start main part of the program
}

