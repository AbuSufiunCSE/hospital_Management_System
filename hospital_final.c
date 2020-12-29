#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<unistd.h>
#include<dos.h>
#include<ctype.h>
#include<windows.h>
#include<time.h>
#define NULL 0
struct address
{
    char hno[40];
    char street[40];
    char city[40];
};
struct patient
{
    char faname[40];
    char laname[40];
    char fname[40];
    int age;
    char bg[5];
    char gender[5];
    char regn[15];
    struct address a;
    char ph[15];
    char disease[60];
    char doc_name[40];
    struct patient *next;
} ;
struct staff
{
    char faname[40];
    char laname[40];
    char bg[5];
    char gender[5];
    char uid[10];
    char address[60];
    char ph[15];
    struct staff *next1;
};

struct doctor
{
    char faname[40];
    char laname[40];
    char bg[5];
    char gender[5];
    char specialist[100];
    char address[60];
    char ph[15];
    char schedule[30];
    struct doctor *next2;
};
struct inventory
{
    int sno;
    char name[30];
    char dop[20];
    int qnty;
    float price;
    float amount;
    struct inventory *next3;
};
typedef struct patient node;
typedef struct staff node1;
typedef struct doctor node2;
typedef struct inventory node3;

FILE *patient, *staff, *doct, *inven, *temppatient, *tempstaff;

void top_design();
void menu();

void pat();
void listing_pat();
void searching_pat();
void remove_pat();

void emp();
void listing_emp();
void searching_emp();
void remove_emp();

void doc();
void listing_doc();
void searching_doc();


void inv();
void modify_inv();
void searching_inv();
void listing_inv();

void password();
void about();



void top_design()
{

    system("color 30");
    printf("\n\n\n\n\n                CSE-235 Project..(  Introduction to Bio- Informatics  )\n\n\n");
    printf("                 Submitted By:");
    Sleep(300);
    printf("\n                          Abu Sufiun & 3 other group member...");
    Sleep(2000);
    printf("\n\n");
    printf("\n\t\t*************************************************");
    printf("\n\t\t  *** WELCOME TO HOSPITAL MANAGEMENT SYSTEM ***");
    printf("\n\t\t*************************************************");
    Sleep(2000);
}

void menu()
{
    system("color E0");
    int r,q;
    char choice;
    system("cls");
    printf("\n\n\n\n\n\n\n\t\t\tLoading");
    for(r=1; r<=5; r++)
    {
        for(q=0; q<=100000000; q++);
        printf(".");
    }
    printf("\n\t\t\t");
    for(r=1; r<=15; r++)
    {
        for(q=0; q<=100000000; q++);
        printf("%c",178);
    }
    Sleep(300);
    system("cls");

    printf("\n\t\t\tDaffodil Hospital");
    printf("\n\n\n\n\t\tEnter your choice:");
    printf("\n\n\n");
    printf("\t\t1.PATIENT of Daffodil Hospital...");
    printf("\n\t\t2.STAFF of Daffodil Hospital...");
    printf("\n\t\t3.DOCTOR of Daffodil Hospital...");
    printf("\n\t\t4.INVENTORY In Daffodil Hospital...");
    printf("\n\t\t5.PASSWORD of This Application...");
    printf("\n\t\t6.ABOUT DAFFODIL HOSPITAL");
    printf("\n\t\t0.Close the Program");
    printf("\n\n\tPlease Enter your choice: ");

    fflush(stdin);
    choice=getche();

    switch(choice)
    {
    case '1':
        pat();
        break;
    case '2':
        emp();
        break;
    case '3':
        doc();
        break;
    case '4':
        inv();
        break;
    case '5':
        password();
        printf("\nType any key to return to main menu.");
        getche();
        menu();
        break;
    case '6':
        system("cls");
        about();
        printf("\nType any key to return to main menu.");
        getche();
        menu();
        break;
    case '0':
        exit(1);
    }
}


void pat()
{

    system("color A0");
    system("cls");
    int r,q;
    char ch;
    while(1)
    {
        system("cls");
        printf("\n\n\n\n\n\n\n\t\t\tLoading");
        for(r=1; r<=3; r++)
        {
            for(q=0; q<=100000000; q++);
            printf(".");
        }
        printf("\n\t\t\t");
        for(r=1; r<=10; r++)
        {
            for(q=0; q<=40000000; q++);
            printf("%c",178);
        }
        system("cls");


        printf("\n\n\t\t\tPATIENT");
        printf("\n\t\t1.Enter a New Entry");
        printf("\n\t\t2.Search an Entry");
        printf("\n\t\t3.Listing of records");
        printf("\n\t\t4.Delete an Entry");
        printf("\n\t\t5.Main Menu");
        printf("\n\n\t\tEnter your choice here: ");
        fflush(stdin);
        ch=getche();
        fflush(stdin);

        switch(ch)
        {
        case '1':


            system("cls");
            printf("\n\n\n\n\n\n\n\t\t\tLoading");
            for(r=1; r<=3; r++)
            {
                for(q=0; q<=100000000; q++);
                printf(".");
            }
            printf("\n\t\t\t");
            for(r=1; r<=10; r++)
            {
                for(q=0; q<=50000000; q++);
                printf("%c",178);
            }
            system("cls");

            FILE *output;
            node*p;
            p=(node*)malloc(sizeof(node));
            fflush(stdin);
            printf("Type *end* To finish \nEnter Patient's first name:\n");
            gets(p->faname);
            if (strcmp(p->faname,"end")==NULL  || strcmp(p->faname,"END")==NULL)
            {
                p->next=NULL;
                pat();
            }
            else
            {
                patient=fopen("pat.txt", "a");
                fputs(p->faname,patient);
                fputs("\n",patient);
                printf("Enter patient's last name:\n");
                gets(p->laname);
                fputs(p->laname,patient);
                fputs("\n",patient);
                fflush(stdin);
                printf("Enter attendant name:\n");
                gets(p->fname);
                fputs(p->fname,patient);
                fputs("\n",patient);
                printf("Age of patient:\n");
                scanf("%d", &p->age);
                fprintf(patient,"%d", p->age);
                fputs("\n",patient);
                fflush(stdin);
                printf("Blood group:\n");
                gets(p->bg);
                fputs(p->bg,patient);
                fputs("\n",patient);
x:
                printf("Gender(M/F):\n");
                gets(p->gender);
                fflush(stdin);

                if((*p->gender)=='M' || (*p->gender)=='m' || (*p->gender)=='F' || (*p->gender)=='f')
                {
                    fputs(p->gender,patient);
                    fputs("\n",patient);
                }
                else
                {
                    printf("Wrong input. TRY AGAIN\n");
                    goto x;
                }

                if(ch=='1')
                {

                    output=fopen("plus.txt","r");
                    fscanf(output,"%s", &p->regn);
                    fprintf(patient,"%s", p->regn);
                    *p->regn=*p->regn+1;
                    fclose(output);
                    output=fopen("plus.txt","w");
                    fprintf(output,"%s",p->regn);
                    fputs("\n",patient);
                    fclose(output);
               }
                printf("Enter address:\n");
                printf("\tHouse no:");
                gets(p->a.hno);
                fputs(p->a.hno,patient);
                fputs("\n",patient);
                printf("\tStreet:");
                gets(p->a.street);
                fputs(p->a.street,patient);
                fputs("\n",patient);
                printf("\tCity:");
                gets(p->a.city);
                fputs(p->a.city,patient);
                fputs("\n",patient);
                printf("Enter phone no:\n");
                gets(p->ph);
                fputs(p->ph,patient);
                fputs("\n",patient);
                printf("Disease:\n");
                gets(p->disease);
                fputs(p->disease,patient);
                fputs("\n",patient);
                printf("Recommended Doctor Name:\n");
                gets(p->doc_name);
                fputs(p->doc_name,patient);
                fputs("\n",patient);
                fflush(stdin);
                fclose(patient);

                p->next=(node*)malloc(sizeof(node));
                pat(p->next);

            }


            break;





        case '2':

            system("cls");
            printf("\n\n\n\n\n\n\n\t\t\tLoading");
            for(r=1; r<=3; r++)
            {
                for(q=0; q<=100000000; q++);
                printf(".");
            }
            printf("\n\t\t\t");
            for(r=1; r<=10; r++)
            {
                for(q=0; q<=50000000; q++);
                printf("%c",178);
            }
            system("cls");
            fflush(stdin);

            searching_pat();
            printf("\nType any key to return to patient menu.");
            getche();
            pat();
            break;



        case '3':

            system("cls");
            printf("\n\n\n\n\n\n\n\t\t\tLoading");
            for(r=1; r<=3; r++)
            {
                for(q=0; q<=100000000; q++);
                printf(".");
            }
            printf("\n\t\t\t");
            for(r=1; r<=10; r++)
            {
                for(q=0; q<=50000000; q++);
                printf("%c",178);
            }
            system("cls");
            fflush(stdin);

            listing_pat();
            printf("\nType any key to return to patient menu.");
            getche();
            pat();
            break;


        case '4':

            system("cls");
            printf("\n\n\n\n\n\n\n\t\t\tLoading");
            for(r=1; r<=3; r++)
            {
                for(q=0; q<=100000000; q++);
                printf(".");
            }
            printf("\n\t\t\t");
            for(r=1; r<=10; r++)
            {
                for(q=0; q<=50000000; q++);
                printf("%c",178);
            }
            system("cls");
            fflush(stdin);

            remove_pat();
            printf("\nType any key to return to patient menu.");
            getche();
            pat();
            break;



        case '5':
            menu();
            break;





        }
    }
}



void listing_pat()
{
    struct patient pa;

    char reg[15];
    if(patient=("pat.txt","r")==NULL)
    {
        printf("No list to show.");
        pat();

    }
    else
    {
        patient=fopen("pat.txt","r");
        while(fscanf(patient,"%[^\n]\n%[^\n]\n%[^\n]\n%d\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%[^\n]\n%[^\n]\n",pa.faname,pa.laname,pa.fname,&pa.age,pa.bg,pa.gender,pa.regn,pa.a.hno,pa.a.street,pa.a.city,pa.ph,pa.disease,pa.doc_name)!=EOF)
        {
            printf("Patient name: ");
            printf("%s %s", pa.faname,pa.laname);
            printf("\nAttendant name: ");
            puts(pa.fname);
            printf("Age of patient: ");
            printf("%d", pa.age);
            printf("\nBlood group: ");
            puts(pa.bg);
            printf("Gender: ");
            puts(pa.gender);

            printf("Registration number: ");
            puts(pa.regn);
            printf("Address: ");
            printf("%s,%s,%s.", pa.a.hno,pa.a.street,pa.a.city);
            printf("\nPhone no: ");
            puts(pa.ph);
            printf("Disease: ");
            puts(pa.disease);
            printf("Recommended Doctor name: ");
            puts(pa.doc_name);

            printf("\n----------------------------------------------------\n");



        }

    }
    fclose(patient);
}


void searching_pat()
{
    struct patient pa;

    char pname[40];
    if(patient=("pat.txt","r")==NULL)
    {
        printf("No list to show.");
        pat();

    }
    else
    {
        printf("\nEnter name to search: ");
        gets(pname);

        printf("\nPATIENT INFO: \n\n\n");

        patient=fopen("pat.txt","r");
        while(fscanf(patient,"%[^\n]\n%[^\n]\n%[^\n]\n%d\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%[^\n]\n%[^\n]\n",pa.faname,pa.laname,pa.fname,&pa.age,pa.bg,pa.gender,pa.regn,pa.a.hno,pa.a.street,pa.a.city,pa.ph,pa.disease,pa.doc_name)!=EOF)
        {
            if(strcmp(pa.faname,pname)==0 || strcmp(pa.laname,pname)==0)
            {
                printf("Patient name: ");
                printf("%s %s", pa.faname,pa.laname);
                printf("\nAttendant name: ");
                puts(pa.fname);
                printf("Age of patient: ");
                printf("%d", pa.age);
                printf("\nBlood group: ");
                puts(pa.bg);
                printf("Gender: ");
                puts(pa.gender);
                printf("Registration number: ");
                puts(pa.regn);
                printf("Address: ");
                printf("%s,%s,%s.", pa.a.hno,pa.a.street,pa.a.city);
                printf("\nPhone no: ");
                puts(pa.ph);
                printf("Disease: ");
                puts(pa.disease);
                printf("Recommended Doctor name: ");
                puts(pa.doc_name);

                printf("\n----------------------------------------------------\n");

            }
        }
        printf("\n----------------------------------------------------");
    }



}

void remove_pat()
{

    char faname[40],laname[40],fname[40],bg[5],gender[5],regn[15],hno[40],street[40],city[40],disease[60],ph[15],doc_name[40];
    int age;


    char preg[40];
    if(patient=("pat.txt","r")==NULL)
    {
        printf("No list to show.");
        pat();

    }
    else
    {
        printf("\nEnter Registration No.to Delete: ");
        gets(preg);

        patient=fopen("pat.txt","r");
        temppatient=fopen("temp.txt","w");
        fflush(stdin);
        while(fscanf(patient,"%[^\n]\n%[^\n]\n%[^\n]\n%d\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%[^\n]\n%[^\n]\n",faname,laname,fname,&age,bg,gender,regn,hno,street,city,ph,disease,doc_name)!=EOF)


        {
            if(strcmp(preg,regn)!=0)
                fprintf(temppatient,"%s\n%s\n%s\n%d\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",faname,laname,fname,age,bg,gender,regn,hno,street,city,ph,disease,doc_name);
                else continue;
          }

       fclose(patient);
       fclose(temppatient);
       fflush(stdin);
       remove("pat.txt");
       rename("temp.txt","pat.txt");


    }
  }

void remove_emp()
{

    char faname[40],laname[40],bg[5],gender[5],uid[15],address[60],ph[15];

    char euid[40];
    if(staff=("emp.txt","r")==NULL)
    {
        printf("No list to show.");
        emp();

    }
    else
    {
        printf("\nEnter ID No.to Delete: ");
        gets(euid);

        staff=fopen("emp.txt","r");
        tempstaff=fopen("temp1.txt","w");
        fflush(stdin);
        while(fscanf(staff,"%[^\n]\n%[^\n]\n%s\n%s\n%s\n%s\n%s\n",faname,laname,bg,gender,uid,address,ph)!=EOF)


        {
            if(strcmp(euid,uid)!=0)
                fprintf(tempstaff,"%s\n%s\n%s\n%s\n%s\n%s\n%s\n",faname,laname,bg,gender,uid,address,ph);
                else continue;
          }

       fclose(staff);
       fclose(tempstaff);
       fflush(stdin);
       remove("emp.txt");
       rename("temp1.txt","emp.txt");


    }
  }



void emp()
{     system("color 57");
    system("cls");
    int r,q;
    char c;
    while(1)
    {
        system("cls");
        printf("\n\n\n\n\n\n\n\t\t\tLoading");
        for(r=1; r<=3; r++)
        {
            for(q=0; q<=100000000; q++);
            printf(".");
        }
        printf("\n\t\t\t");
        for(r=1; r<=10; r++)
        {
            for(q=0; q<=40000000; q++);
            printf("%c",178);
        }
        system("cls");


        printf("\n\t\t\tEMPLOYEE");
        printf("\n\t\t1.Add an Entry");
        printf("\n\t\t2.Search an Entry");
        printf("\n\t\t3.Listing of all records");
        printf("\n\t\t4.Delete an Entry");
        printf("\n\t\t5.Main Menu");
        printf("\n\n\t\tEnter your choice here: ");
        fflush(stdin);
        c=getche();

        switch(c)
        {


        case '1':

            system("cls");
            printf("\n\n\n\n\n\n\n\t\t\tLoading");
            for(r=1; r<=3; r++)
            {
                for(q=0; q<=100000000; q++);
                printf(".");
            }
            printf("\n\t\t\t");
            for(r=1; r<=10; r++)
            {
                for(q=0; q<=50000000; q++);
                printf("%c",178);
            }
            system("cls");

            FILE *output_emp;
            node1*p;
            p=(node1*)malloc(sizeof(node1));
            fflush(stdin);
            printf("Type *end* To finish \nEnter Employee's First name:\n");
            gets(p->faname);
            if (strcmp(p->faname,"end")==NULL || strcmp(p->faname,"END")==NULL)
            {
                p->next1=NULL;
                emp();
            }
            else
            {
                staff=fopen("emp.txt", "a");
                fputs(p->faname,staff);
                fputs("\n",staff);
                printf("Enter Employee's last name:\n");
                gets(p->laname);
                fputs(p->laname,staff);
                fputs("\n",staff);
                fflush(stdin);
                printf("Blood group:\n");
                gets(p->bg);
                fputs(p->bg,staff);
                fputs("\n",staff);
x:
                printf("Gender(M/F):\n");
                gets(p->gender);
                fflush(stdin);
                if((*p->gender)=='M' || (*p->gender)=='m' || (*p->gender)=='F' || (*p->gender)=='f')
                {
                    fputs(p->gender,staff);
                    fputs("\n",staff);
                }
                else
                {
                    printf("Wrong input. TRY AGAIN\n");
                    goto x;
                }
                output_emp=fopen("plus_emp.txt","r");
                fscanf(output_emp,"%s", &p->uid);
                fprintf(staff,"%s", p->uid);
                *p->uid=*p->uid+1;
                fclose(output_emp);
                output_emp=fopen("plus_emp.txt","w");
                fprintf(output_emp,"%s",p->uid);
                fputs("\n",staff);
                fclose(output_emp);
                printf("Enter address:\n");
                gets(p->address);
                fputs(p->address,staff);
                fputs("\n",staff);
                printf("Enter phone no:\n");
                gets(p->ph);
                fputs(p->ph,staff);
                fputs("\n",staff);
                fflush(stdin);
                fclose(staff);
                p->next1=(node1*)malloc(sizeof(node1));
                emp(p->next1);

            }


            break;

        case '2':

            system("cls");
            printf("\n\n\n\n\n\n\n\t\t\tLoading");
            for(r=1; r<=3; r++)
            {
                for(q=0; q<=100000000; q++);
                printf(".");
            }
            printf("\n\t\t\t");
            for(r=1; r<=10; r++)
            {
                for(q=0; q<=50000000; q++);
                printf("%c",178);
            }
            system("cls");

            fflush(stdin);

            searching_emp();
            printf("\nType any key to return to employee menu.");
            getche();
            emp();
            break;



        case '3':
            system("cls");
            printf("\n\n\n\n\n\n\n\t\t\tLoading");
            for(r=1; r<=3; r++)
            {
                for(q=0; q<=100000000; q++);
                printf(".");
            }
            printf("\n\t\t\t");
            for(r=1; r<=10; r++)
            {
                for(q=0; q<=50000000; q++);
                printf("%c",178);
            }
            system("cls");

            fflush(stdin);

            listing_emp();
            printf("\nType any key to return to employee menu.");
            getche();
            emp();
            break;


        case '4':

            system("cls");
            printf("\n\n\n\n\n\n\n\t\t\tLoading");
            for(r=1; r<=3; r++)
            {
                for(q=0; q<=100000000; q++);
                printf(".");
            }
            printf("\n\t\t\t");
            for(r=1; r<=10; r++)
            {
                for(q=0; q<=50000000; q++);
                printf("%c",178);
            }
            system("cls");

            fflush(stdin);

            remove_emp();
            printf("\nType any key to return to employee menu.");
            getche();
            emp();
            break;


        case '5':
            menu();
            break;


        }
    }
}

void listing_emp()
{
    struct staff st;

    char reg[15];
    if(staff=("emp.txt","r")==NULL)
    {
        printf("No list to show.");
        emp();

    }
    else
    {
        staff=fopen("emp.txt","r");
        while(fscanf(staff,"%[^\n]\n%[^\n]\n%s\n%s\n%s\n%[^\n]\n%s\n",st.faname,st.laname,st.bg,st.gender,st.uid,st.address,st.ph)!=EOF)
        {
            printf("Employye's name: ");
            printf("%s %s", st.faname,st.laname);
            printf("\nBlood group: ");
            puts(st.bg);
            printf("Gender: ");
            puts(st.gender);
            printf("ID number: ");
            puts(st.uid);
            printf("Address: ");
            puts(st.address);
            printf("Phone no: ");
            puts(st.ph);

            printf("\n----------------------------------------------------\n");



        }

    }
    fclose(staff);
}

void searching_emp()
{
    struct staff st;

    char ename[40];
    if(staff=("emp.txt","r")==NULL)
    {
        printf("No list to show.");
        emp();

    }
    else
    {
        printf("\nEnter name to search: ");
        gets(ename);

        printf("\nEmployee INFO: \n\n\n");
        staff=fopen("emp.txt","r");
        while(fscanf(staff,"%[^\n]\n%[^\n]\n%s\n%s\n%s\n%[^\n]\n%s\n",st.faname,st.laname,st.bg,st.gender,st.uid,st.address,st.ph)!=EOF)
        {
            if(strcmp(st.faname,ename)==0 || strcmp(st.laname,ename)==0)
            {
                printf("Employye's name: ");
                printf("%s %s", st.faname,st.laname);
                printf("\nBlood group: ");
                puts(st.bg);
                printf("Gender: ");
                puts(st.gender);
                printf("ID number: ");
                puts(st.uid);
                printf("Address: ");
                puts(st.address);
                printf("Phone no: ");
                puts(st.ph);

                printf("\n----------------------------------------------------\n");


            }
        }
        printf("\n----------------------------------------------------");
    }



}

void doc()
{
    system("cls");
    int r,q;
    char ch;
    while(1)
    {
        system("cls");
        printf("\n\n\n\n\n\n\n\t\t\tLoading");
        for(r=1; r<=3; r++)
        {
            for(q=0; q<=100000000; q++);
            printf(".");
        }
        printf("\n\t\t\t");
        for(r=1; r<=10; r++)
        {
            for(q=0; q<=40000000; q++);
            printf("%c",178);
        }
        system("cls");


        printf("\n\n\t\t\tDOCTOR");
        printf("\n\t\t1.Enter a New Entry");
        printf("\n\t\t2.Search an Entry");
        printf("\n\t\t3.Listing of records");
        printf("\n\t\t4.Main Menu");
        printf("\n\n\t\tEnter your choice here: ");
        fflush(stdin);
        ch=getche();
        fflush(stdin);

        switch(ch)
        {
        case '1':


            system("cls");
            printf("\n\n\n\n\n\n\n\t\t\tLoading");
            for(r=1; r<=3; r++)
            {
                for(q=0; q<=100000000; q++);
                printf(".");
            }
            printf("\n\t\t\t");
            for(r=1; r<=10; r++)
            {
                for(q=0; q<=50000000; q++);
                printf("%c",178);
            }
            system("cls");
            FILE *output;
            int a,sum;
            node2*p;
            p=(node2*)malloc(sizeof(node2));
            fflush(stdin);
            printf("Type *end* To finish \nEnter Doctor's first name:\n");
            gets(p->faname);
            if (strcmp(p->faname,"end")==NULL || strcmp(p->faname,"END")==NULL)
            {
                p->next2=NULL;
                doc();
            }
            else
            {
                doct=fopen("doc.txt", "a");
                fputs(p->faname,doct);
                fputs("\n",doct);
                fflush(stdin);
                printf("Enter Doctor's last name:\n");
                gets(p->laname);
                fflush(stdout);
                fputs(p->laname,doct);
                fputs("\n",doct);
                fflush(stdin);
                printf("Blood group:\n");
                gets(p->bg);
                fputs(p->bg,doct);
                fputs("\n",doct);
                x:
                printf("Gender(M/F):\n");
                gets(p->gender);
                fflush(stdin);
                if((*p->gender)=='M' || (*p->gender)=='m' || (*p->gender)=='F' || (*p->gender)=='f')
                {
                    fputs(p->gender,doct);
                    fputs("\n",doct);
                }
                else
                {
                    printf("Wrong input. TRY AGAIN\n");
                    goto x;
                }
                printf("Specialized on:\n");
                printf("\n\t\t1.Child Specialist");
                printf("\n\t\t2.Skin Specialist");
                printf("\n\t\t3.Dentist");
                printf("\n\t\t4.ENT Specialist(ear-nose-throat)");
                printf("\n\t\t5.Eye Specialist");
                printf("\n\t\t6.Psychologist");
                printf("\n\t\t7.Medical Officer");
                printf("\n\t\t8.Cardiac Surgeon");
                printf("\n\t\t9.Liver and Gastroenterology");
                printf("\n\t\t10.Orthopedic Surgeon");
                printf("\n\t\t11.Diabetics Specialist");
                printf("\n\t\t12.Cancer Specialist");
                printf("\n\tEnter to choice:");
                gets(p->specialist);
                if((*p->specialist)=='1')
                {
                    fputs("Child Specialist",doct);
                    fputs("\n",doct);
                }
                if((*p->specialist)=='2')
                {
                    fputs("Skin Specialist",doct);
                    fputs("\n",doct);
                }
                if((*p->specialist)=='3')
                {
                    fputs("Dentist",doct);
                    fputs("\n",doct);
                }
                if((*p->specialist)=='4')
                {
                    fputs("ENT Specialist(ear-nose-throat)",doct);
                    fputs("\n",doct);
                }
                if((*p->specialist)=='5')
                {
                    fputs("Eye Specialist",doct);
                    fputs("\n",doct);
                }
                if((*p->specialist)=='6')
                {
                    fputs("Psychologist",doct);
                    fputs("\n",doct);
                }
                if((*p->specialist)=='7')
                {
                    fputs("Medical Officer",doct);
                    fputs("\n",doct);
                }
                 if((*p->specialist)=='8')
                {
                    fputs("Cardiac Surgeon",doct);
                    fputs("\n",doct);
                }
                if((*p->specialist)=='9')
                {
                    fputs("Liver and Gastroenterology",doct);
                    fputs("\n",doct);
                }
                if((*p->specialist)=='10')
                {
                    fputs("Orthopedic Surgeon",doct);
                    fputs("\n",doct);
                }
                if((*p->specialist)=='11')
                {
                    fputs("Diabetics Specialist",doct);
                    fputs("\n",doct);
                }
                if((*p->specialist)=='12')
                {
                    fputs("Cancer Specialist",doct);
                    fputs("\n",doct);
                }

                printf("Enter address:\n");
                gets(p->address);
                fputs(p->address,doct);
                fputs("\n",doct);
                printf("Enter phone number:\n");
                gets(p->ph);
                fputs(p->ph,doct);
                fputs("\n",doct);
                printf("Enter schedule:\n");
                gets(p->schedule);
                fputs(p->schedule,doct);
                fputs("\n",doct);

                fflush(stdin);
                fclose(doct);
                p->next2=(node2*)malloc(sizeof(node2));
                doc(p->next2);

            }


            break;

        case '2':

            system("cls");
            printf("\n\n\n\n\n\n\n\t\t\tLoading");
            for(r=1; r<=3; r++)
            {
                for(q=0; q<=100000000; q++);
                printf(".");
            }
            printf("\n\t\t\t");
            for(r=1; r<=10; r++)
            {
                for(q=0; q<=50000000; q++);
                printf("%c",178);
            }
            system("cls");
            fflush(stdin);

            searching_doc();
            printf("\nType any key to return to doctor menu.");
            getche();
            doc();
            break;


        case '3':

            system("cls");
            printf("\n\n\n\n\n\n\n\t\t\tLoading");
            for(r=1; r<=3; r++)
            {
                for(q=0; q<=100000000; q++);
                printf(".");
            }
            printf("\n\t\t\t");
            for(r=1; r<=10; r++)
            {
                for(q=0; q<=50000000; q++);
                printf("%c",178);
            }
            system("cls");

            fflush(stdin);

            listing_doc();
            printf("\nType any key to return to doctor menu.");
            getche();
            doc();
            break;

        case '4':

            menu();
            break;

        }
    }
}



void listing_doc()
{
    struct doctor d;

    char reg[15];
    if(doct=("doc.txt","r")==NULL)
    {
        printf("No list to show.");
        doc();

    }
    else
    {
        doct=fopen("doc.txt","r");
        while(fscanf(doct,"%[^\n]\n%[^\n]\n", d.faname,d.laname)!=EOF && fgets(d.bg,5,doct)!='\0' && fgets(d.gender,5,doct)!='\0' && fgets(d.specialist,100,doct)!='\0' && fgets(d.address,100,doct)!='\0' && fgets(d.ph,100,doct)!='\0' && fgets(d.schedule,30,doct)!='\0')

        {
            printf("Doctor's name: ");
            printf("%s %s", d.faname,d.laname);
            printf("\n");
            printf("\nBlood group: ");
            puts(d.bg);
            printf("Gender: ");
            puts(d.gender);
            printf("Specialized on: ");
            puts(d.specialist);
            printf("Address: ");
            puts(d.address);
            printf("Phone no: ");
            puts(d.ph);
            printf("Checking time: ");
            puts(d.schedule);

            printf("\n----------------------------------------------------\n");



        }

    }
    fclose(doct);
}

void searching_doc()
{
    struct doctor d;

    char dname[40];
    if(doct=("doc.txt","r")==NULL)
    {
        printf("No list to show.");
        doc();

    }
    else
    {
        printf("\nSearch doctor specialized on:\n\n");
                printf("Specialized on:\n");
                printf("\n\t\t1.Child Specialist");
                printf("\n\t\t2.Skin Specialist");
                printf("\n\t\t3.Dentist");
                printf("\n\t\t4.ENT Specialist(ear-nose-throat)");
                printf("\n\t\t5.Eye Specialist");
                printf("\n\t\t6.Psychologist");
                printf("\n\t\t7.Medical Officer");
                printf("\n\t\t8.Cardiac Surgeon");
                printf("\n\t\t9.Liver and Gastroenterology");
                printf("\n\t\t10.Orthopedic Surgeon");
                printf("\n\t\t11.Diabetics Specialist");
                printf("\n\t\t12.Cancer Specialist");
                printf("\n");

        printf("Specialized On:");
        gets(dname);


        printf("\nDoctot INFO: \n\n\n");
        doct=fopen("doc.txt","r");
        system("cls");

        while(fscanf(doct,"%s\n%s\n%s\n%s\n%[^\n]\n%s\n%s\n%[^\n]\n",d.faname,d.laname,d.bg,d.gender,d.specialist,d.address,d.ph,d.schedule)!=EOF)

        {

            if(strcmp(d.specialist,dname)==0)
            {
                printf("Doctor's name: ");
                printf("%s %s", d.faname,d.laname);
                printf("\nBlood group: ");
                puts(d.bg);
                printf("Gender: ");
                puts(d.gender);
                printf("Specialized on: ");
                puts(d.specialist);
                printf("Address: ");
                puts(d.address);
                printf("Phone no: ");
                puts(d.ph);
                printf("Checking time: ");
                puts(d.schedule);

                printf("\n----------------------------------------------------\n");



            }
        }
        printf("\n----------------------------------------------------");
    }
    fclose(doct);
}




void inv()
{    system("color C0");
    system("cls");
    int r,q;
    char ch;
    while(1)
    {
        system("cls");
        printf("\n\n\n\n\n\n\n\t\t\tLoading");
        for(r=1; r<=3; r++)
        {
            for(q=0; q<=100000000; q++);
            printf(".");
        }
        printf("\n\t\t\t");
        for(r=1; r<=10; r++)
        {
            for(q=0; q<=40000000; q++);
            printf("%c",178);
        }
        system("cls");


        printf("\n\t\t\tINVENTORY");
        printf("\n\t\t1.Add an Entry for Item");
        printf("\n\t\t2.Search an Entry");
        printf("\n\t\t3.Listing of all Entries");
        printf("\n\t\t4.Main Menu");
        printf("\n\n\t\tEnter your choice here: ");
        fflush(stdin);
        ch=getche();
        fflush(stdin);

        switch(ch)
        {

        case '1':

            system("cls");
            printf("\n\n\n\n\n\n\n\t\t\tLoading");
            for(r=1; r<=3; r++)
            {
                for(q=0; q<=100000000; q++);
                printf(".");
            }
            printf("\n\t\t\t");
            for(r=1; r<=10; r++)
            {
                for(q=0; q<=50000000; q++);
                printf("%c",178);
            }
            system("cls");
            FILE *output;
            int a,sum;
            node3*p;
            p=(node3*)malloc(sizeof(node3));
            fflush(stdin);
            printf("Type *end* To finish \nEnter Item's name:\n");
            gets(p->name);
            if (strcmp(p->name,"end")==NULL || strcmp(p->name,"END")==NULL)
            {
                p->next3=NULL;
                inv();
            }
            else
            {
                inven=fopen("inv.txt", "a");
                fputs(p->name,inven);
                fputs("\n",inven);
                fflush(stdin);
                printf("Date of purchase:\n");
                gets(p->dop);


                fputs(p->dop,inven);
                fputs("\n",inven);
                printf("Enter Quantity:\n");
                scanf("%d", &p->qnty);
                fprintf(inven,"%d",p->qnty);
                fputs("\n",inven);
                printf("Enter Price of One Item:\n");
                scanf("%f", &p->price);
                fprintf(inven,"%f",p->price);
                fputs("\n",inven);
                p->amount=(p->price)*(p->qnty);
                fprintf(inven,"%f",p->amount);
                fputs("\n",inven);

                fflush(stdin);
                fclose(inven);
                p->next3=(node3*)malloc(sizeof(node3));
                inv(p->next3);

            }


            break;




        case '2':

            system("cls");
            printf("\n\n\n\n\n\n\n\t\t\tLoading");
            for(r=1; r<=3; r++)
            {
                for(q=0; q<=100000000; q++);
                printf(".");
            }
            printf("\n\t\t\t");
            for(r=1; r<=10; r++)
            {
                for(q=0; q<=50000000; q++);
                printf("%c",178);
            }
            system("cls");

            fflush(stdin);

            searching_inv();
            printf("\nType any key to return to inventory menu.");
            getche();
            inv();
            break;

        case '3':

            system("cls");
            printf("\n\n\n\n\n\n\n\t\t\tLoading");
            for(r=1; r<=3; r++)
            {
                for(q=0; q<=100000000; q++);
                printf(".");
            }
            printf("\n\t\t\t");
            for(r=1; r<=10; r++)
            {
                for(q=0; q<=50000000; q++);
                printf("%c",178);
            }
            system("cls");

            fflush(stdin);

            listing_inv();
            printf("\nType any key to return to inventory menu.");
            getche();
            inv();
            break;

           case '4':

            menu();
            break;




        }
    }
}

void searching_inv()
{
   struct inventory i;

    char iname[40];
    if(inven=("inv.txt","r")==NULL)
    {
        printf("No list to show.");
        inv();

    }
    else
    {
        printf("\nEnter name to search: ");
        gets(iname);

        printf("\nItem INFO: \n\n\n");
        inven=fopen("inv.txt","r");
        while(fscanf(inven,"%[^\n]\n%[^\n]\n%d\n%f\n%f\n",i.name,i.dop,&i.qnty,&i.price,&i.amount)!=EOF)
        {
            if(strcmp(i.name,iname)==0)
            {
                printf("Item's name: ");
                puts(i.name);
                printf("Date of purchase: ");
                puts(i.dop);
                printf("Quantity: ");
                printf("%d", i.qnty);
                printf("\nPrice of One Item: ");
                printf("%f",i.price);
                printf("\nTotal Amount: ");
                printf("%f tk",i.amount);

                printf("\n----------------------------------------------------\n");


            }
        }
        printf("\n----------------------------------------------------");
    }
}

void listing_inv()
{
     struct inventory i;

    if(inven=("inv.txt","r")==NULL)
    {
        printf("No list to show.");
        inv();

    }
    else
    {

        inven=fopen("inv.txt","r");
        int j=1;
        while(fscanf(inven,"%[^\n]\n%[^\n]\n%d\n%f\n%f\n",i.name,i.dop,&i.qnty,&i.price,&i.amount)!=EOF)
        {
                printf("SL.No: %d\n", j);
                printf("Item's name: ");
                puts(i.name);
                printf("Date of purchase: ");
                puts(i.dop);
                printf("Quantity: ");
                printf("%d", i.qnty);
                printf("\nPrice of One Item: ");
                printf("%f",i.price);
                printf("\nTotal Amount: ");
                printf("%f tk",i.amount);

                printf("\n----------------------------------------------------\n");

                j++;



        }
    }
    fclose(inven);
}

void password()
{    system("color 84");
    system("cls");
    char ch,p[80],password[80];
    int i=0;
    FILE *fp;
    printf("\n\n\t\tEnter password:");
    while((ch=getch())!=13)
    {
        password[i]=ch;
        i++;
        printf("*");
        fflush(stdin);
    }
   password[i]='\0';
   fp=fopen("pass.txt","r");
   fscanf(fp,"%[^\n]",p);
   fclose(fp);
   if(strcmp(password,p)==0)
   {
       system("cls");
       fp=fopen("pass.txt","w");
       printf("Enter New Password:");
       gets(p);
       fputs(p,fp);
       fclose(fp);
   }

}

void about()
{

    printf("\n\t\t*************************************************");
    printf("\n\t\t  *** Daffodil Hospital ***");
    printf("\n\t\t*************************************************");
    printf("\n");
    printf("\n");
    printf("\n");
    printf(".........................The fundamental strength of Daffodil Hospital is its two teams - one of cardiologists and other surgery. The teams are composed of highly skilled, experienced and eminent cardiologists, surgeons and anaesthesiologists. Besides, a band of qualified and experienced nurses, technicians and other support personnel garnered from home and abroad are providing constant care to the patients. There exists an unprecedented amount of amity, understanding and cooperation among the members of the teams which are sine-qua-non for successful treatment out come of ailments........................");

}

main()
{

    system("color 54");
    top_design();

    system("cls");
    char ch,p[80],password[80];

    int i=0;
    FILE *fp;
    printf("\n\n\t\tEnter password:");
    while((ch=getch())!=13)
    {
        password[i]=ch;
        i++;
        printf("*");
        fflush(stdin);
    }
   password[i]='\0';
   fp=fopen("pass.txt","r");
   fscanf(fp,"%[^\n]",p);
   fclose(fp);
   if(strcmp(password,p)==0)
   {
    menu();
   }

}
