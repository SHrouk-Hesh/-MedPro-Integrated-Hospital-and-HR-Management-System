#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
#include<ctime>
#include<windows.h>

using namespace std;
class Reception
{
    public:
            static int bill;static string name;static string phone ;static string address;static string age;
    void getinfo( )
    {
    cout<<"==================================================="<<endl;
   
    cout<<"ENTER THE NAME OF PATIENT    :    ";cin>>name;
    cout<<"ENTER THE AGE OF PATIENT    :    ";cin>>age;
    cout<<"ENTER THE ADDRESS OF PATIENT    :    ";cin>>address;
    cout<<"ENTER THE PHONE OF PATIENT    :    ";cin>>phone;
    cout<<"==================================================="<<endl;
    cout<<"\n\n";

}

    int getproblem()
    {
        char p;
        cout<<"SELECT DEPARTMENT : 1.HEART  2.BONES  3.TEETH  4.STOMACH 5.EMERGENCY    :    ";cin>>p;
   
       
        return p;
    }
};
int Reception::bill=0;
string Reception::name;
string Reception::phone;
string Reception::address;
string Reception::age;

class Teeth:public Reception
{
    private:
        int fillings=5000;int washings = 7000;int teethremovals = 5000;int brace = 35000;
    public:
        int gettreat()
        {
        char t;
        cout<<"ENTER TREATEMENT YOU WANT TO GO :    1.FILLING    2.WASHING    3.TEETHREMOVAL    4.BRACES    ";cin>>t;
        return t;
        }   
        void filling()
        {
                int a;
                cout<<"AMOUNT OF SELECTED TREATEMENT IS : "<<fillings<<"  \n DO YOU WANT TO ACCEPT IT ? : 1.YES , 2.NO \n    ";cin>>a;
                if (a==1)
                {
                bill=bill+fillings ;
            }
            else cout<<"\n\nTHANKS FOR COMING\n\n";
        }
        void washing()
        {
                int a;
                cout<<"AMOUNT OF SELECTED TREATEMENT IS : "<<washings<<" \n DO  WANT TO ACCEPT IT ? : 1.YES , 2.NO \n    ";cin>>a;
                if (a==1)
                {
                bill=bill+washings;
            }
            else cout<<"\n\nTHANKS FOR COMING\n\n";
        }
        void teethremoval()
        {
                int a;
                cout<<"AMOUNT OF SELECTED TREATEMENT IS : "<<teethremovals<<" \n DO  WANT TO ACCEPT IT ? : 1.YES , 2.NO \n    ";cin>>a;
                if (a==1)
                {
                bill=bill+teethremovals;
            }
            else cout<<"\n\nTHANKS FOR COMING\n\n";
        }
        void braces()
        {
                int a;
                cout<<"AMOUNT OF SELECTED TREATEMENT IS : "<<brace<<"  \n DO  WANT TO ACCEPT IT ? : 1.YES , 2.NO \n    ";cin>>a;
                if (a==1)
                {
                bill=bill+brace;
            }
            else cout<<"\n\nTHANKS FOR COMING\n\n";
        }
};
class Heart:public Reception
{
    private:
        int bypss=250000;int cg=5000;

    public:
   
    char c;
    int gettreats()
    {
       
    cout<<"SELECT WHAT YOU WANT TO DO : \n    ";
    cout<<"1:FOR BYPASS  ";
    cout<<"    2:FOR ECG  ";
    cin>>c;
    return c;
}

    void bypass()
    {
        int a;
        cout<<"AMOUNT OF BYPASS IS :"<<bypss<<"DO YOU AGREE 1: YES , 2: NO    \n    ";cin>>a;
        if(a==1)
        {
        bill=bill+bypss;
        }
        else
        cout<<"THANKS FOR COMING";
}
void ecg()
    {
         int b;
        cout<<"AMOUNT OF ECG IS :"<<cg<<"DO YOU AGREE 1: YES , 2: NO \n    ";cin>>b;
        if(b==1){
        bill=bill+cg;}
        else
        cout<<"THANKS FOR COMING";
}};
class Bones:public Reception
{
    private:
        int factre=7000;int b=12000;int bne=5000000;
    public:
        char s;
    int bone()
   {
       cout<<"SELECT WHAT YOU WANT TO DO :\n";
    cout<<"1:FOR FACTURE";
    cout<<"        2:FOR BONE BREAK";
    cout<<"        3:FOR BONE MARROW PLANT";cin>>s;return s;}
   
    void facture()
    {
        int a;
        cout<<"AMOUNT OF FACTURE IS :"<<factre<<"DO YOU AGREE 1: YES , 2: NO\n     ";cin>>a;
        if(a==1){
        bill=bill+factre;}
         else
         cout<<"THANKS FOR COMING";
    }
     void bonebreak()
    {
         int c;
    cout<<"AMOUNT OF BONE BREAK IS :"<<b<<"DO YOU AGREE 1: YES , 2: NO \n    ";cin>>c;
         if(c==1){
         bill=bill+b;}
    else
    cout<<"THANKS FOR COMING";
    }

void bone_marrow_plant()
    {
        int d;
        cout<<"AMOUNT OF BONE MARROW PLANT IS :"<<bne<<"DO YOU AGREE 1: YES , 2: NO \n    ";cin>>d;
        if(d==1){
        bill=bill+bne;}
        else
        cout<<"THANKS FOR COMING";
    }};
class stomach:public Reception
{
    private:
        int che=1000;int b=3000;
    public:
        char st;
    int sto(){
   
   cout<<"SELECT WHAT YOU WANT TO DO :\n";
    cout<<"1:FOR STOMACH CHECKUP";
    cout<<"    2:FOR STOMACH WASH";
    cin>>st;return st;}

    void stomach_checkup()
{
        int a;
        cout<<"AMOUNT OF THIS TREATMENT IS :"<<che<<"DO YOU AGREE 1: YES , 2: NO \n    ";cin>>a;
        if(a==1){
        bill=bill+che;}
         else
         cout<<"THANKS FOR COMING";
}

void stomach_wash()
    {
         int c;
    cout<<"AMOUNT OF STOMACH WASH IS :"<<b<<"DO YOU AGREE 1: YES , 2: NO\n    ";cin>>c;
         if(c==1){
         bill=bill+b;}
    else
    cout<<"THANKS FOR COMING";
    }
};

int main()
{
    getch();
   
    system("color 4F");
   
    cout<<"**    **    **********    **********    **********    **    *************    **********    **\n";
    Sleep(300);
    system("color F4");
    cout<<"**    **    **    **    **        **    **    **       **        **    **    **\n";
    Sleep(300);
    system("color 4F");
    cout<<"**    **    **    **    **        **    **    **       **        **    **    **\n";
    Sleep(300);
    system("color F4");
    cout<<"**********    **    **    **********    **********    **       **        **********    **\n";
    Sleep(300);
    system("color 4F");
    cout<<"**    **    **    **        **    **        **       **        **    **    **\n";
    Sleep(300);
    system("color F4");
    cout<<"**    **    **    **        **    **        **       **        **    **    **\n";
    Sleep(300);
    system("color 4F");
    cout<<"**    **    **********    **********    **        **       **        **    **    ***********\n";
    Sleep(300);
    system("color F4");
   
    int pat;int f;int heart=0;string l;int n;
    Sleep(300);
    system("color 4F");
   
    cout<<"\n\n";
    cout<<"ENTER THE PATIENT NUMBER\n    ";cin>>n;
    pat=n;
   
    fstream list;
    time_t now = time(0);

   char* dt = ctime(&now);

        while(f!=-1)
    {
       
        list.open("list.txt",ios::app);list<<endl<<endl;
        list << "THE DATE AND TIME IS WHEN PATIENT CAME: " << dt << endl;

   
    char b;char a; int tea=0;char e;char d;string c;
    fstream patient;
   
    patient.open("patient.txt",ios::out);
   
    patient << "THE DATE AND TIME IS WHEN PATIENT CAME: " << dt << endl;
    patient<<"PATIENT NUMBER IS : "<<pat<<'\n';
    patient<<"PATIENT TOKEN NUMBER IS : "<<pat<<'\n';
   

    Teeth r;
    Heart h;
    Bones on;
    stomach om;
    r.getinfo();
    {
        b=r.getproblem();
       
                patient<<"Mr./Mrs./Miss."<<r.name<<"'S AGE IS : "<<r.age<<"\n";
                patient<<"Mr./Mrs./Miss."<<r.name<<"'S PHONE IS : "<<r.phone<<"\n";
                patient<<"Mr./Mrs./Miss."<<r.name<<"'S ADDRESS IS : "<<r.address<<"\n";
           
                list<<"Mr./Mrs./Miss."<<r.name<<"'S AGE IS : "<<r.age<<"\n";
                list<<"Mr./Mrs./Miss."<<r.name<<"'S PHONE IS : "<<r.phone<<"\n";
                list<<"Mr./Mrs./Miss."<<r.name<<"'S ADDRESS IS : "<<r.address<<"\n";
       
    switch(b)
    {
            case '1':
            {
               
                cout<<"WELCOME TO HEART DEPARTMENT"<<endl;
                e=h.gettreats();
                patient<<"Mr./Mrs./Miss."<<r.name<<" HAS HEART PROBLEM\n";
           
               
               
           
                list<<"Mr./Mrs./Miss."<<r.name<<" HAS HEART PROBLEM\n";
               
               
                switch (e)
                {
                    case '1':
                        {
                            cout<<"WELCOME TO BYPASS SECTION"<<endl<<endl;
                            h.bypass();
                            patient<<"Mr./Mrs./Miss."<<r.name<<" WANTS BYPASS \n";
                            list<<"Mr./Mrs./Miss."<<r.name<<" WANTS BYPASS \n";
                            break;
                        }
                        case '2':
                        {
                            cout<<"WELCOME TO ECG SECTION"<<endl<<endl;
                            h.ecg();
                            patient<<"Mr./Mrs./Miss."<<r.name<<" WANTS ECG \n";
                            list<<"Mr./Mrs./Miss."<<r.name<<" WANTS ECG \n";
                            break;
                        }        }
           
            break;}
           
            case '2':
            {
                cout<<"WELCOME TO BONE DEPARTMENT"<<endl;
                d=on.bone();
                patient<<"Mr./Mrs./Miss."<<r.name<<" HAS BONE PROBLEM\n";
                list<<"Mr./Mrs./Miss."<<r.name<<" HAS BONE PROBLEM\n";
                switch(d)
                {
                    case '1':
                        {
                            cout<<"WELCOME TO FACTURE SECTION"<<endl<<endl;
                            on.facture();
                            patient<<"Mr./Mrs./Miss."<<r.name<<" WANTS BONE FIT \n";
                            list<<"Mr./Mrs./Miss."<<r.name<<" WANTS BONE FIT \n";
                            break;
                        }
                        case '2':
                        {
                            cout<<"WELCOME TO BONE BREAK SECTION"<<endl<<endl;
                            on.bonebreak();
                            patient<<"Mr./Mrs./Miss."<<r.name<<" WANTS BONE JOIN \n";
                            list<<"Mr./Mrs./Miss."<<r.name<<" WANTS BONE JOIN \n";
                       
                            break;
                        }
                        case '3':
                        {
                            cout<<"WELCOME TO BONE MARROW PLANT SECTION"<<endl<<endl;
                            on.bone_marrow_plant();
                            patient<<"Mr./Mrs./Miss."<<r.name<<" WANTS BONE MARROW \n";
                            list<<"Mr./Mrs./Miss."<<r.name<<" WANTS BONE MARROW \n";
                            break;
                        }
                       
                }
               
                break;
            }
            case '3':
            {
                cout<<"WELCOME TO TEETH DEPARTMENT"<<endl;
                a=r.gettreat();
                patient<<"Mr./Mrs./Miss."<<r.name<<" HAS TEETH PROBLEM  \n";
                list<<"Mr./Mrs./Miss."<<r.name<<" HAS TEETH PROBLEM  \n";
                switch (a)
                {
                    case '1':
                        {
                            cout<<"WELCOME TO FILLING SECTION"<<endl<<endl;
                            r.filling();
                            patient<<"Mr./Mrs./Miss."<<r.name<<" WANTS FILLING \n";
                            list<<"Mr./Mrs./Miss."<<r.name<<" WANTS FILLING \n";
                            break;
                        }
                        case '2':
                        {
                            cout<<"WELCOME TO WASHING SECTION"<<endl<<endl;
                            r.washing();
                            patient<<"Mr./Mrs./Miss."<<r.name<<" WANTS WASHING \n";
                            list<<"Mr./Mrs./Miss."<<r.name<<" wants WASHING \n";
                            break;
                        }
                        case '3':
                        {
                            cout<<"WELCOME TO TEETHREMOVAL SECTION"<<endl<<endl;
                            r.teethremoval();
                            patient<<"Mr./Mrs./Miss."<<r.name<<" WANTS TEETH REMOVAL \n";
                            list<<"Mr./Mrs./Miss."<<r.name<<" WANTS TEETH REMOVAL \n";
                            break;
                        }
                        case '4':
                        {
                            cout<<"WELCOME TO BRACES SECTION"<<endl;
                            r.braces();
                            patient<<"Mr./Mrs./Miss."<<r.name<<" WANTS BRACES \n";
                            list<<"Mr./Mrs./Miss."<<r.name<<" wWANTS BRACES \n";
                            break;
                        }        }   break; }
            case '4':
            {
                cout<<"WELCOME TO STOMACH DEPARTMENT"<<endl;
                d=om.sto();
                patient<<"Mr./Mrs./Miss."<<r.name<<" HAS STOMACH PROBLEM \n ";
                list<<"Mr./Mrs./Miss."<<r.name<<" HAS STOMACH PROBLEM \n ";
                switch(d)
                {
                        case '1':
                        {
                            cout<<"WELCOME TO Stomach check up SECTION"<<endl<<endl;
                            om.stomach_checkup();
                            patient<<"Mr./Mrs./Miss."<<r.name<<" WANTS STOMACH CHECKUP \n";
                            list<<"Mr./Mrs./Miss."<<r.name<<" WANTS STOMACH CHECKUP \n";
                            break;
                        }
                        case '2':
                        {
                            cout<<"WELCOME TO Stomach Wash SECTION"<<endl;
                            om.stomach_wash();
                            patient<<"Mr./Mrs./Miss."<<r.name<<" WANTS STOMACH WASH \n";
                            list<<"Mr./Mrs./Miss."<<r.name<<" WANTS STOMACH WASH \n";
                            break;
                        }    }    
                break;       
                }
                case '5':
                    {
                        cout<<"\aTHE BILL WILL BE GENERATED ACCORDINGLY\n";
                    break;
                    }
               
            }
            pat++;
}
   
    cout<<"YOUR BILL IS : "<<r.bill;
    patient<<r.name<<"`S BILL IS : "<<r.bill;
    list<<r.name<<"`S BILL IS : "<<r.bill;
    getch();
    patient.close();
    list.close();
    system("cls");
    patient.open("patient.txt");
    while(getline(patient,c))
    {
        cout<<c<<'\n';
    }
   
    getch();
    system("cls");
    r.bill=0;
    cout<<"DO YOU WANT TO ENTER MORE PATIENTS ? 1.YES   -1.NO    ";cin>>f;}
    system("cls");
    cout<<"LIST OF TOTAL PATIENTS CAME TODAY IS ::::\n\n\n\n\n";
    list.open("list.txt");
    while(getline(list,l))
    {
        cout<<l<<'\n';cout<<endl;
    }
    getch();
}