#include<iostream>
#include<fstream>
#include<stdio.h>
#include<iomanip>
using namespace std;


class Car
{
    private :
    int id;
    char name[20];
    char fuel[10];
    char colour[15];
    int price;
    char status;

    public :
    void get_data();
    void disp_data();
    void update_status(char s)
    {
        status= s;
    }

    int get_id()
    {
        return id;
    }

    int get_price()
    {
        return price;
    }

    char get_status()
    {
        return status;
    }
};

//Function to store data of a car 
void Car:: get_data()
{
    cout<<"\nEnter ID for Car : ";
    cin>>id;
    fflush(stdin);
    cout<<"Enter Car Name : ";
    cin.getline(name, 19);
    cout<<"Enter Fuel Type : ";
    cin>>fuel;
    cout<<"Enter Colour Of Car : ";
    cin>>colour;
    cout<<"Enter Price Per Hour : Rs. ";
    cin>>price;
    cout<<"Enter Availability : ";
    cin>>status;
}

//function to display data of car
void Car:: disp_data()
{
    cout<<setw(6)<<id<<setw(20)<<name<<setw(8)<<fuel<<setw(8)<<colour<<setw(20)<<price<<setw(15)<<status<<endl;
}

//function prototypes
void add_car();     //to add car data to file
void show_car();   //to show data of a particular car
void show_all();    //to show data of all cars
void delete_car();  //to delete car data from file
void car_select();  //for selecting car in customer menu
void update();
void car_rented();
void delete_rented();

int flag=0;
int Flag=0;


//global decalaration
Car c;  //create object of car
fstream file;   // create stream object

class admin
{
    private :
    string username;
    string password;

    public :
    void set_data();
};

void admin:: set_data()
{
    fstream file1;
    file1.open("admin.dat", ios::out | ios:: binary);
    file1<<"Admin123"<<endl;
    file1<<"AdminPass"<<endl;
    file1.close();
}

//main function

int main()
{
    
    Main_menu :
    int choice;
    while(1)
    {
        system("clear");
        cout<<"----------------------------------------------"<<endl;
        cout<<"***********  WELCOME TO MAIN MENU  ***********"<<endl;
        cout<<"----------------------------------------------\n"<<endl;
        cout<<"You Have the Following Options : "<<endl<<endl;
        cout<<"1. Administrator Menu"<<endl<<endl;
        cout<<"2. Customer Menu"<<endl<<endl;
        cout<<"3. Exit "<<endl<<endl;
        cout<<"----------------------------------------------\n"<<endl;
        cout<<"Please Enter Your Choice : ";
        cin>>choice;

        switch(choice)
        {
            case 1:
            {
                fflush(stdin);
                goto Admin_login;
                break;
            }

            case 2 :
            {
                goto Customer_menu;
                break;
            }

            case 3 :
            {
                exit(0);
            }

            default :
            {
                cout<<"INVALID. PRESS ANY KEY TO TRY AGAIN";
                fflush(stdin);
                getchar();
                system("clear");
                break;
            }
        }//swithcase

        
    }



    Customer_menu:
    int opt;
    while(1)
    {
        system("clear");
        cout<<"----------------------------------------------"<<endl<<endl;
        cout<<"***********  WELCOME CUSTOMER  ***********"<<endl<<endl;
        cout<<"----------------------------------------------"<<endl<<endl;
        cout<<"1. Car Selection"<<endl<<endl;
        cout<<"2. Exit To Main Menu"<<endl<<endl;
        cout<<"----------------------------------------------"<<endl<<endl;
        cout<<"Please Enter Your Choice : ";
        cin>>opt;
        fflush(stdin);
        switch(opt)
        {

            case 1 :
            {
                Car_Select:
                int days;
                string Date;
                string loc, Time;
                system("clear");
                cout<<"Here is our Car List : "<<endl<<endl;
                cout<<"--------------------------------------------------------------------------------\n";
                cout<<setw(6)<<"ID"<<setw(20)<<"Name"<<setw(8)<<"Fuel"<<setw(8)<<"Colour"<<setw(20)<<"Price Per Hour"<<setw(15)<<"Available"<<endl;
                cout<<"--------------------------------------------------------------------------------\n";
                show_all();
                cout<<"--------------------------------------------------------------------------------\n";
                cout<<"Car Selection : \n"<<endl;
                car_select();
                if(Flag==1)
                {
                cout<<"\nEnter Date For Pickup : ";
                getline(cin, Date);
                fflush(stdin);
                cout<<"\nEnter Time For Pickup : ";
                getline(cin, Time);
                cout<<"\nEnter Location for Car Pickup: ";
                getline(cin, loc);
                //getchar();
                fflush(stdin);
                system("clear");
                cout<<"----------------------------------------------"<<endl<<endl;
                cout<<"Thank Your for working with us Today!"<<endl<<endl;
                cout<<"----------------------------------------------"<<endl<<endl;
                cout<<"\nYour Car Will be dropped for pickup at : "<<endl<<endl;
                cout<<loc<<" on "<<Date<<" at "<<Time<<endl<<endl;
                cout<<"Press Any Key To Go Back to Menu....";
                getchar();
                }

                else if(Flag==0)
                {
                    system("clear");
                    cout<<"\nInvalid ID!!"<<endl;
                    cout<<"Press Any Key to Try Again...."<<endl;
                    fflush(stdin);
                    getchar();
                    goto Car_Select;
                }

                else if(Flag==2)
                {
                    system("clear");
                    cout<<"\nCar Not Avaialable"<<endl;
                    cout<<"Press Any Key to Try Again...."<<endl;
                    fflush(stdin);
                    getchar();
                    goto Car_Select;
                }
                break;
            }//case 1

            case 2 :
            {     
                goto Main_menu;
                break;
            }

            default :
            {
                cout<<"INVALID. PRESS ANY KEY TO TRY AGAIN";
                getchar();
                system("clear");
                break;
            }
        }//switchcase  
    
    }//main while loop

    
    Admin_login :
    admin a;
    a.set_data();
    fstream file2;
    file2.open("admin.dat", ios::in | ios::binary);
    string f_user, f_pass;
    file2>>f_user;
    file2>>f_pass;
    file2.close();
    string user, pass;

    while(1)
    {
        system("clear");
        cout<<"Enter Username : ";
        getline(cin, user);
        fflush(stdin);
        if(user==f_user)
        {
            cout<<"Enter Password : ";
            getline(cin, pass);
            if(pass==f_pass)
            {
                goto Admin_menu;
                break;
            }//pass word if
            else 
            {
                fflush(stdin);
                cout<<"Wrong Password! Press Any Key to Try again..";
                getchar();
                
            }//password else    
        }// username if
        else
        {
            fflush(stdin);
            cout<<"Wrong Username! Press any key to try again";
            getchar();

        }
   }


    Admin_menu :
    int option;
    while(1)
    {
        system("clear");
        cout<<"----------------------------------------------"<<endl<<endl;
        cout<<"******* MENU *******"<<endl<<endl;
        cout<<"----------------------------------------------"<<endl<<endl;
        cout<<"1. Add New Car"<<endl<<endl;
        cout<<"2. Display All Cars"<<endl<<endl;
        cout<<"3. Display Particular Car"<<endl<<endl;
        cout<<"4. Delete Car"<<endl<<endl;
        cout<<"5. Update Car Availability"<<endl<<endl;
        cout<<"6. Show car rented currently"<<endl<<endl;
        cout<<"7. Exit to Main Menu"<<endl<<endl;
        cout<<"----------------------------------------------"<<endl<<endl;
        cout<<"Enter Option : "; cin>>option;
        switch(option)
        {
            case 1 :
             {
                 getchar();
                 system("clear");
                 add_car();
                 cout<<"Press Any Key for Main Menu......";
                 fflush(stdin);
                 getchar();
                 break;
             }

             case 2 :
             {
                 getchar();
                 system("clear");
                 //function call to display all records
                 cout<<"--------------------------------------------------------------------------------\n";
                 cout<<setw(6)<<"ID"<<setw(20)<<"Name"<<setw(8)<<"Fuel"<<setw(8)<<"Colour"<<setw(20)<<"Price Per Hour"<<setw(15)<<"Available"<<endl;
                 cout<<"--------------------------------------------------------------------------------\n";
                 show_all();
                 cout<<"--------------------------------------------------------------------------------\n";
                 cout<<"Press Any Key for Admin Menu......";
                 getchar();
                 break;
             }

             case 3 :
             {
                 Show_Car:
                 show_car();
                 if(flag==1)
                 {
                 cout<<"Press Any Key for Admin Menu......";
                 getchar();
                 }
                 else if(flag==0)
                 {
                     system("clear");
                     cout<<"Car Not Found"<<endl;
                     cout<<"Press Any Key to Try Again....."<<endl;
                     fflush(stdin);
                     getchar();
                     goto Show_Car;
                 }   

                 break;
             }

             case 4 :
             {
                 delete_car();
                 cout<<"Press Any Key for Admin Menu......";
                 getchar();
                 break;
             }

            case 5 :
            {
                
                update();
                cout<<"Press Any Key for Admin Menu";
                fflush(stdin);
                getchar();
                break;
            }

            case 6 :
            {
                getchar();
                 system("clear");
                 cout<<"--------------------------------------------------------------------------------\n";
                 cout<<setw(6)<<"ID"<<setw(20)<<"Name"<<setw(8)<<"Fuel"<<setw(8)<<"Colour"<<setw(20)<<"Price Per Hour"<<setw(15)<<"Available"<<endl;
                 cout<<"--------------------------------------------------------------------------------\n";
                 car_rented();
                 cout<<"--------------------------------------------------------------------------------\n";
                 fflush(stdin);
                 char remove_opt;
                 cout<<"Do you want to remove a car from this list? (y/n) : ";
                 cin>>remove_opt;

                 if(remove_opt == 'Y' || remove_opt =='y')
                 {
                     delete_rented();
                     cout<<"\nPress Any Key for Admin Menu......";
                     fflush(stdin);
                     getchar();
                 }
                else
                {
                 cout<<"Press Any Key for Admin Menu......";
                 getchar();
                }
                 break;
            }

             case 7 :
             {
                goto Main_menu;
             }

             default :
             {
                fflush(stdin);
                cout<<"Invalid option! Press Any Key for Main Menu......";
                getchar();
                break;
             }


        }//switch case

    }//while loop for menu

    return 0;
}

void add_car()
{
    char ch='y';
    file.open("Car.dat", ios:: app | ios:: binary);
    while(ch == 'y' || ch == 'Y')
    {
        c.get_data();
        //write object to file
        file.write((char*)&c, sizeof(c));
        cout<<"Add More Cars   (y/n)?.... ";
        cin>>ch;
        fflush(stdin);
    }//while loop

    file.close();

}

void show_all()
{
    file.open("Car.dat", ios::in | ios:: binary);
    if(! file)  //if file opening fails
    {
        cout<<"File Not Found";
        exit(0);
    }

    else
    {
        //read car from file into object
        file.read((char*)&c, sizeof(c));
        while(! file.eof()) //till end of file
        {
            c.disp_data();  //display object
            file.read((char*)&c, sizeof(c));
        }//while loop
    }//else loop

    file.close();
}

void show_car()
{
    int no;

    file.open("Car.dat", ios:: in | ios:: binary);
    if(! file)
    {
        cout<<"File Not Found";
        exit(0);
    }

    else
    {
        cout<<"Enter Car ID : ";
        cin>>no;
        //read car from file into object
        file.read((char*)&c, sizeof(c));
        while( ! file.eof())
        {
            if(no==c.get_id())
            {
                flag=1;
                cout<<"--------------------------------------------------------------------------------\n";
                 cout<<setw(6)<<"ID"<<setw(20)<<"Name"<<setw(8)<<"Fuel"<<setw(8)<<"Colour"<<setw(20)<<"Price Per Hour"<<setw(15)<<"Available"<<endl;
                 cout<<"--------------------------------------------------------------------------------\n";
                 c.disp_data(); //display car data
                 cout<<"--------------------------------------------------------------------------------\n";
                 getchar();
                 break;
            }//if loop
            file.read((char*)&c, sizeof(c));
        }//while loop
        
    }//else loop

    file.close();
}

void delete_car()
{
    cout<<"--------------------------------------------------------------------------------\n";
    cout<<setw(6)<<"ID"<<setw(20)<<"Name"<<setw(8)<<"Fuel"<<setw(8)<<"Colour"<<setw(20)<<"Price Per Hour"<<setw(15)<<"Available"<<endl;
    cout<<"--------------------------------------------------------------------------------\n";
    show_all();
    cout<<"--------------------------------------------------------------------------------\n";
    
    int no;
    cout<<"Enter Car ID for Car To be Deleted : ";
    cin>>no;
    fflush(stdin);

    ofstream file2;
    //openening new.dat for writing
    file2.open("new.dat", ios::out | ios::binary);
    //opening car file for reading
    file.open("Car.dat", ios::in | ios::binary);
    if(! file)
    {
        cout<<"File Not Found";
        exit(0);
    }
    else
    {
        file.read((char*)&c, sizeof(c));
        while(! file.eof())
        {
            if(no != c.get_id())
            {
                file2.write((char*)&c, sizeof(c));
            }//if loop
            file.read((char*)&c, sizeof(c));
        }//while
    }//else
    file2.close();
    file.close();
    remove("Car.dat");
    rename("new.dat", "Car.dat");

}

void car_select()
{
    int No;
    int days;

    file.open("Car.dat", ios:: in | ios:: binary);
    if(! file)
    {
        cout<<"File Not Found";
        exit(0);
    }

    else
    {
        cout<<"Enter Car ID : ";
        cin>>No;
        //read car from file into object
        file.read((char*)&c, sizeof(c));
        while( ! file.eof())
        {
            if(No==c.get_id() && c.get_status()=='Y')
            {
                Flag=1;
                system("clear");
                cout<<"--------------------------------------------------------------------------------\n";
                 cout<<setw(6)<<"ID"<<setw(20)<<"Name"<<setw(8)<<"Fuel"<<setw(8)<<"Colour"<<setw(20)<<"Price Per Hour"<<setw(15)<<"Available"<<endl;
                 cout<<"--------------------------------------------------------------------------------\n";
                 c.disp_data(); //display car data
                 cout<<"--------------------------------------------------------------------------------\n\n";

                 ofstream file_r;
                 file_r.open("rented.dat", ios::app | ios:: binary);
                 file_r.write((char*)&c, sizeof(c));
                 file_r.close();

                 cout<<"Enter Number of days Car needed for : ";
                 cin>>days;
                 fflush(stdin);
                 int hours;
                 hours=24*days;
                 int total_price;
                 total_price= hours*(c.get_price());
                 cout<<"Total Price for Renting : Rs. "<<total_price<<endl;
                 break;
            }//if loop

            else if (No==c.get_id() && c.get_status()=='N')
            {
                Flag=2;
            }
            file.read((char*)&c, sizeof(c));
        }//while loop
        
    }//else loop

    file.close();
}

void update()
{
    int no;
    char stat;
    cout<<"Enter Car ID : ";
    cin>>no;
    fflush(stdin);
    cout<<"Enter Availabilty Status : ";
    cin>>stat;

    file.open("Car.dat", ios::in | ios:: out | ios::binary);
    if(!file)
    {
        cout<<"File not Found";
        exit(0);
    }

    while(file.read((char*)&c, sizeof(c)))
    {
        if(c.get_id() == no)
        {
            c.update_status(stat);  
            int pos = sizeof(c);
            file.seekp(-pos, ios::cur);
            file.write((char*)&c, sizeof(c));
            
        }//if
    }//while
    file.close();
}

void car_rented()
{
    file.open("rented.dat", ios::in | ios::binary);
    if(! file)  //if file opening fails
    {
        cout<<"File Not Found";
        exit(0);
    }

    else
    {
        //read car from file into object
        file.read((char*)&c, sizeof(c));
        while(! file.eof()) //till end of file
        {
            c.disp_data();  //display object
            file.read((char*)&c, sizeof(c));
        }//while loop
    }//else loop

    file.close();
}

void delete_rented()
{
    char choice ='y';
    while(choice=='y' || choice=='Y')
    {
    system("clear");
    cout<<"--------------------------------------------------------------------------------\n";
    cout<<setw(6)<<"ID"<<setw(20)<<"Name"<<setw(8)<<"Fuel"<<setw(8)<<"Colour"<<setw(20)<<"Price Per Hour"<<setw(15)<<"Available"<<endl;
    cout<<"--------------------------------------------------------------------------------\n";
    car_rented();
    cout<<"--------------------------------------------------------------------------------\n";
    
    int no;
    cout<<"\nEnter Car ID for Car To be Deleted : ";
    cin>>no;
    fflush(stdin);

    ofstream file3;
    //openening new.dat for writing
    file3.open("new.dat", ios::out | ios::binary);
    //opening car file for reading
    file.open("rented.dat", ios::in | ios::binary);
    if(! file)
    {
        cout<<"File Not Found";
        exit(0);
    }
    else
    {
        file.read((char*)&c, sizeof(c));
        while(! file.eof())
        {
            if(no != c.get_id())
            {
                file3.write((char*)&c, sizeof(c));
            }//if loop
            file.read((char*)&c, sizeof(c));
        }//while
    }//else
    file3.close();
    file.close();
    remove("rented.dat");
    rename("new.dat", "rented.dat");

    cout<<"Do you want to delete more cars ? (y/n) : ";
    cin>>choice;
    fflush(stdin);
    }

}
