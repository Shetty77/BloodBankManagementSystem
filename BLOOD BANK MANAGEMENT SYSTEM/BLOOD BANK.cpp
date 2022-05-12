#include<iostream>
#include<conio.h>
#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<sstream>



using namespace std;


class user 
{
    public:
         string userName;
         string userPassword;
         string userpassword1;
         string userpassword2;
         string fullname;
         string bloodgroup;
         string age;
         string city;
         string state;
         string mobno;
         string buffer;
         string name_list[100];
         int address_list[100];
         int count;
         char ch;
         const char ENTER = 13;
	     user(){count=-1;}
         int loginAttempt = 0;
         void er(){buffer.erase();}
         void adminlogin();
         void add_user();
         void write_to_file_donor();
         void write_to_file_seeker();
         void pack(); 
         int logincheckdonor(string user, string pass);
         void displaydonor();
         void displayseeker();
         void disp();
         void remove(string);
	     void delete_from_file(int);
	     void search(string);
         void read_from_file(int);
         int search_index(string);
         void sort_index();
      
};
   

 void user::adminlogin()
    {
       while (loginAttempt < 5)
       {
             cout << "Please enter your user name: ";
             cin >> userName;
             cout << "Please enter your user password: ";
              while((ch = _getch()) != ENTER)
             {
              userPassword += ch;
              std::cout << '*';
             }
             if (userName == "swastik" && userPassword == "swastik123")
             {
             cout << "\n"<< "Welcome Swastik!\n";
             break;
             }
             else if (userName == "simi" && userPassword == "simi123")
             {
             cout << "Welcome Simi!\n";
             break;     
             }
             else     
             {
             cout << "Invalid login attempt. Please try again.\n" << '\n';
             loginAttempt++;  
             }
        }
        if (loginAttempt == 5)
        {
        cout << "Too many login attempts! The program will now terminate.";
        }
        cout << "Thank you for logging in.\n";
    }


 void user::add_user()
    {
    	cout<<"*********** REGISTRATION FORM ************"<<endl;
        cout<<"\n"<<"Enter Full Name of Donor/Seeker: ";cin>>fullname;
        cout<<"Enter Blood Group: ";cin>>bloodgroup;
        cout<<"Enter Age: ";cin>>age;
        cout<<"Enter City: ";cin>>city;
        cout<<"Enter State: ";cin>>state;
        cout<<"Enter Mobile No.: ";cin>>mobno;
        cout<<"Enter User Name: ";cin>>userName;
      
		rev1:cout<<"\n"<<"Enter Password: ";
		    while((ch = _getch()) != ENTER)
    {
        userpassword1 += ch;
        std::cout << '*';
    }
			  
        cout<<"\n"<<"Enter Password again: ";
        while((ch = _getch()) != ENTER)
    {
        userpassword2 += ch;
        std::cout << '*';
    }
        while (userpassword1!=userpassword2)
        {
          cout<<"\n"<<"Password doesn't match!!!!!!!";
          userpassword1='\0';
          userpassword2='\0';
		  goto rev1;
        }
      cout<<"\n"<<"************Registered Successfully*************";
    }
 
 void user::pack()
    {
 	    buffer.erase();
 	    buffer+=userName+"|"+bloodgroup+"|"+age+"|"+city+"|"+state+"|"+mobno+"|"+fullname+"|"+userpassword1+"$"+"\n";
    }

 void user::write_to_file_donor()
    {
	    int pos;
        fstream file;
        file.open("bloodonor.txt",ios::out|ios::app);
        pos=file.tellp();
	    file<<buffer;
        file.close();
		name_list[++count]=userName;
        address_list[count]=pos;
        sort_index();	
    }

 void user::write_to_file_seeker()
    {
        ofstream file;
        file.open("bloodseeker.txt",ios::out|ios::app);
        file<<buffer;
        file.close();	
    }
 
 

int user:: logincheckdonor(string userName, string userpassword1)
{
    ifstream file;
    string username, password,buffer;
    int pos=0,cnt=0,n=0,i=0;
    file.open("bloodonor.txt");
    file>>buffer;
    
      if (!file.is_open())
    {
        cout << "file not open" << endl;
    }
    
    if (file.is_open())
    
    {
    	 
		 
		 size_t pos = buffer.find(userName, 0);
        while(pos != string::npos)
 { 
        cnt++;
        pos = buffer.find(userName, pos+1);
        cout<<cnt;
 }


    }
    
      if (file.is_open())
    {
	 size_t pos = buffer.find(userpassword1, 0);
        while(pos != string::npos)
 { 
        cnt++;
        pos = buffer.find(userpassword1, pos+1);
     
}
}
if(cnt==2|3)
{
	return cnt;
}
else
return 0;
}

 
 
void user::displaydonor()
{ 

 string buff;
 fstream f3;
 f3.open("bloodonor.txt",ios::in); 
 
               while(!f3.eof())
              {
		           buff.erase();
	               getline(f3,buff);
		           cout<<buff<<"\n";
	          }
	             
}
			  
void user::displayseeker()
{
 string buff;
 fstream f3;
        f3.open("bloodseeker.txt",ios::in); 
	               while(!f3.eof())
	              {
		           buff.erase();
		           getline(f3,buff);
		           cout<<buff<<"\n";
	              }
		
 }
 
   
void user::disp()
{
    int i;
    cout<<endl<<"INDEX FILE"<<endl;
    for(i=0;i<=count;i++)
    cout<<endl<<name_list[i]<<""<<address_list[i];
    cout<<"\n";
    system("more bloodonor.txt");
}
 
void user::sort_index()
{
    int i,j,temp_address;
    string temp_name;
    for(int i=0;i<=count;i++)
    {
    for(int j=i+1;j<=count;j++)
    {
    if(name_list[i]>name_list[j])
    {
    temp_name=name_list[i];
    name_list[i]=name_list[j];
    name_list[j]=temp_name;
    temp_address=address_list[i];   
    address_list[i]=address_list[j];
    address_list[j]=temp_address;
    }
    }
    }
   // for(i=0;i<=count;i++)
    //cout<<name_list[i]<<"\t"<<address_list[i]<<"\n";
}   
 
int user::search_index(string key)
{
    int low=0, mid=0, high=count, flag=0,pos;
    while(low<=high)
    {
    mid=(low+high)/2;
    if(name_list[mid]==key)
    {
    flag=1;
    break;
    }
    if(name_list[mid]>key)
    high=mid-1;
    if(name_list[mid]<key)
    low=mid+1;
    }
    if(flag)
    return mid;
    else
    return -1;
}

void user::search(string key)
{
    int pos=0,t;
    string buffer;
    buffer.erase();
    pos=search_index(key);
    if(pos==-1)
    cout<<endl<<"record not found"<<endl;
    else if(pos>=0)
    {
     read_from_file(pos);
     t=pos;
     while(name_list[++t]==key&&t<=count)
     read_from_file(t);
     t=pos;
     while(name_list[--t]==key&&t>=0)
     read_from_file(t);
     }
} 
 
void user::read_from_file(int pos)
{
	int address,i;
	fstream file;
	file.open("bloodonor.txt",ios::in|ios::app);
	address=address_list[pos];
	file.seekp(address,ios::beg);
	buffer.erase();
	getline(file,buffer);
	cout<<"\n Found the record:"<<buffer;
	file.close();
} 
 
 void user::remove(string key)
{
	int pos=0,t,choice;
        string buffer;
        buffer.erase();
        pos=search_index(key);
        if(pos==-1)
	cout<<endl<<"not possible to remove";
	else if(pos>=0)
	{
	read_from_file(pos);
	cout<<"\ndelete?(1/0):";
	cin>>choice;
	if(choice) 
	delete_from_file(pos);
	t=pos;
	while(name_list[++t]==key)
	{
	read_from_file(t);
	cout<<"\ndelete?";
	cin>>choice;
	if(choice)
	delete_from_file(t);
	}
	t=pos;
	while(name_list[--t]==key)
	{
	read_from_file(t);
	cout<<"\ndelete?";
	cin>>choice;
	if(choice)
	delete_from_file(t);
	}
	}
}

void user::delete_from_file(int pos)
{
	int i,address;
	fstream file;
	file.open("bloodonor.txt");
	address=address_list[pos];
	file.seekp(address,ios::beg);
	file.put('*');
	cout<<"\n record deleted:";
	for(i=pos;i<count;i++)
	{
	name_list[i]=name_list[i+1];
	address_list[i]=address_list[i+1];
	}
	count--;
}

 
int main()
{
	int ch,count,i;
	user user1;
	ifstream file;
	string key;
	int loginattempts=0;
    const char ENTER = 13;
	string userName,userpassword1;
	 while(1)
    {
        cout<<"\n\t\t===========================================";
        cout<<"\n\t\t   |   BLOOD BANK MANAGEMENT SYSYTEM   |"<<endl;
        cout<<"\t\t===========================================";
        cout<<"\n\t \t \t=============== MAIN MENU================="<<endl;
        cout<<"\n\t\t\t1. BLOOD DONATION INFO\n\t\t\t2. ADMINISTRATOR\n\t\t\t3. USER LOGIN\n\t\t\t4. REGISTER\n\t\t\t5. TO EXIT \t\t"<<endl;
        cout<<"\t\t\t: ";
        cin>>ch;
        switch(ch)
        {
        	case 1:
			       break;
        	case 2:cout<<"\n\t \t \t=============== ADMIN MENU================="<<endl;
                   cout<<"\n\t\t\t1. ADMIN LOGIN\n\t\t\t2. TO EXIT \t\t"<<endl;
                   cout<<"\t\t\t: ";
                   cin>>ch;
                   switch(ch)
                   {
                   	
        	        case 1:user1.adminlogin();
        	               while(1)
        	               {
				            cout<<"\n\t \t \t=============== ADMIN PAGE================="<<endl;
                            cout<<"\n\t\t\t1. ADD USER\n\t\t\t2. DISPLAY REGISTERED USERS\n\t\t\t3. SEARCH\n\t\t\t4. MODIFY\n\t\t\t5. DELETE\n\t\t\t6. TO EXIT\t\t"<<endl;
                            cout<<"\t\t\t: ";
                            cin>>ch;
                            switch(ch)
                            {
                          	case 1:cout<<"\n\t \t \t=============== ADD USER================="<<endl;
                                   cout<<"\n\t\t\t1. BLOOD DONOR\n\t\t\t2. BLOOD SEEKER\n\t\t\t3. TO EXIT\t\t"<<endl;
                                   cout<<"\t\t\t: ";
                                   cin>>ch;
                                   switch(ch)
                                  {
                          	       case 1:user1.add_user();
							              user1.pack();
							              user1.write_to_file_donor();
							              break;
                          	       case 2:user1.add_user();
							              user1.pack();
							              user1.write_to_file_seeker();
								          break;
                          	       case 3:return 0;
			                       default:cout<<"\n Wrong Choice \n";
                                   break; 
						          }
							 
                            case 2: while(1)
									  {
								       cout<<"\n\t \t \tEnter the file to display registered names"<<endl;
                                       cout<<"\n\t\t\t1. BLOOD DONOR\n\t\t\t2. BLOOD SEEKER\t\t"<<endl;
                                       cin>>ch;
                                  
                                       switch(ch)
                                       {
                                 	    case 1:user1.displaydonor();
							                   break;
							            case 2: user1.displayseeker();
							                   break;
                                       }
							          }
                            case 3:system("cls");
							       user1.disp();
                                   cout<<"enter the name\n";
                                   cin>>key;
                                   user1.search(key);
                                   break;
	
                            case 4:break;
                            case 5:cout<<"enter the name:";
                                   cin>>key;
                                   user1.remove(key);
                                   break;
                            case 6:return 0;
			                default:cout<<"\n Wrong Choice \n";
                            break;  
                          }
					}
                    case 2:return 0;
			        default:cout<<"\n Wrong Choice \n";
                    break; 
		           }
		    case 3:cout<<"\n\t \t \t=============== LOGIN PAGE================="<<endl;
                   cout<<"\n\t\t\t1. BLOOD DONOR\n\t\t\t2. BLOOD SEEKER\n\t\t\t3. TO EXIT \t\t"<<endl;
                   cout<<"\t\t\t: ";
                   cin>>ch;
                   switch(ch)
                   {
                   	case 1:file.open("bloodonor.txt");
                           if (!file.is_open())
                           {
                            cout << "file not found" << endl;
                           }
                           else
                           {
				           cout << "1.Login " << endl;
                           int option;
                           cin >> option;
                           if (option==1)
                            {
                             while(true)
                             {
                             loginattempts++;
                             cout << "Username: ";
                             cin >> userName;
                             cout << "Password: ";
                              while((ch = _getch()) != ENTER)
                             {
                              userpassword1 += ch;
                              std::cout << '*';
                             }
                             if (user1.logincheckdonor(userName, userpassword1)!=0)
                             {
                             	cout<<"\n"<< "Welcome " << userName << "." << endl;
                             	break;
							 }
                             
                             else if (loginattempts==3)
                            {
                            cout << "Maximum login attempts exceeded." << endl;
                            break;
                            }
                           else
                           {
                           cout << "Invalid username/password combination" << endl;
                           }
                           }
                           file.close();
		                   }
	                       }
			               break;
			       case 2:file.open("bloodseeker.txt");
                           if (!file.is_open())
                           {
                            cout << "file not found" << endl;
                           }
                           else
                           {
				           cout << "1.Login " << endl;
                           int option;
                           cin >> option;
                           if (option==1)
                            {
                             while(user1.logincheckdonor(userName, userpassword1)==0)
                             {
                             loginattempts++;
                             cout << "Username: ";
                             cin >> userName;
                             cout << "Password: ";
                             cin >> userpassword1;
                             if (user1.logincheckdonor(userName, userpassword1)!=0)
                             cout << "Welcome " << userName << "." << endl;
                             else if (loginattempts==3)
                            {
                            cout << "Maximum login attempts exceeded." << endl;
                            break;
                            }
                           else
                           {
                           cout << "Invalid username/password combination" << endl;
                           }
                           }
                           file.close();
		                   }
	                       }
				          break;
				   case 3:return 0;
			              default:cout<<"\n Wrong Choice \n";
                          break; 
		                 }
		           
		    case 4:while(1)
		           {
			       cout<<"\n\t \t \t=============== REGISTER PAGE================="<<endl;
			       cout<<"\n\t\t\t1. BLOOD DONOR REGISTRATION\n\t\t\t2. BLOOD SEEKER REGISTRATION\n\t\t\t3. TO EXIT \t\t"<<endl;
                   cout<<"\t\t\t: ";
                   cin>>ch;
                   switch(ch)
                  {
                	case 1:user1.add_user();
						   user1.pack();
						   user1.write_to_file_donor();
						   break;
                    case 2:user1.add_user();
						   user1.pack();
						   user1.write_to_file_seeker();
						   break;
					case 3:return 0;
                	default:cout<<"\n Wrong Choice \n";
                    break;
		           }
                  }
            case 5:return 0;
			default:cout<<"\n Wrong Choice \n";
                    break;      
        
   }
}
}

