#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

int count; ///global variable
typedef struct record* record_pointer;  ///here we will rename struct pointer

struct record
{
    long int account_number;
    char first_name[20];
    char last_name[20];
    float current_balence;
    record_pointer next;
};


void sleep(int time)
{
    for(int i=0;i<time*7500;i++)
    {
        for(int j=0;j<7500;j++)
        {
            //just time delay function
        }
    }
}

void add_balence(record_pointer* head,long int acc_number,float balence)
{
    record_pointer acc=(record_pointer)malloc(sizeof(struct record));
    acc=*head;
    int flag=0;
    for(int i=0;i<count;i++)
    {
        if(acc->account_number==acc_number)
        {
            flag=1;
            cout<<"----------------Record found--------------------------------------\n";
            acc->current_balence+=balence;
            cout<<"Current balence updated successfully..........\n";
            break;
        }
    }
    if(flag==0)
    {
        cout<<"----------------Record not found-----------------------------------\n";
        sleep(7);
    }
}

void add_record(record_pointer* head)
{
    record_pointer new_record=(record_pointer)malloc(sizeof(struct record));
    cout<<"Enter record data:\n";
    cout<<"Account number: ";
    cin>>new_record->account_number;
    cout<<"First name: ";
    cin>>new_record->first_name;
    cout<<"Last name: ";
    cin>>new_record->last_name;
    new_record->current_balence=0;
    new_record->next=NULL;
    if(count==0)
    {
        *head=new_record;
    }else{
        record_pointer last_record=(record_pointer)malloc(sizeof(struct record));
        last_record=*head;
        while(last_record->next!=NULL)
        {
            last_record=last_record->next;
        }
        last_record->next=new_record;
    }
    count++;
    cout<<"Adding record completed....\n";
    sleep(7);
    cout<<"Triggering database....\n";
    sleep(7);
}

void show_record(record_pointer* head)
{
    record_pointer acc=(record_pointer)malloc(sizeof(struct record));
    acc=*head;
    cout<<"Account number       First name      Last name       Current Balence\n";
    for(int i=0;i<count;i++)
    {
        printf("    %ld                %s                %s                %f\n",acc->account_number,acc->first_name,acc->last_name,acc->current_balence);
        acc=acc->next;
    }
    cout<<"------------------------------------------------------------------\n";
    cout<<"---------------Total record count: "<<count<<"-----------------------------\n";
    sleep(7);
}

void search_record(record_pointer* head,long int acc_number)
{
    record_pointer acc=(record_pointer)malloc(sizeof(struct record));
    acc=*head;
    int flag=0;
    for(int i=0;i<count;i++)
    {
        if(acc->account_number==acc_number)
        {
            printf("    %ld                %s                %s                %f\n",acc->account_number,acc->first_name,acc->last_name,acc->current_balence);
            flag=1;
            cout<<"----------------Record found--------------------------------------\n";
            break;
        }
    }
    if(flag==0)
    {
        cout<<"----------------Record not found-----------------------------------\n";
        sleep(7);
    }
}

void edit_record(record_pointer* head,long int acc_number)
{
    record_pointer acc=(record_pointer)malloc(sizeof(struct record));
    acc=*head;
    int flag=0;
    for(int i=0;i<count;i++)
    {
        if(acc->account_number==acc_number)
        {
            flag=1;
            cout<<"----------------Record found--------------------------------------\n\n";
            cout<<"Renter to record data:\n";
            cout<<"First name: ";
            cin>>acc->first_name;
            cout<<"Last name: ";
            cin>>acc->last_name;
            cout<<"You cannot change Account Balence from here....\n";
            cout<<"For that you need special permission\n";
            cout<<"CONTACT MANAGER\n\n";
            cout<<"Record updated successfully....\n";
            break;
        }
    }
    if(flag==0)
    {
        cout<<"----------------Record not found-----------------------------------\n";
        cout<<"Need to create new account. Try \"Add record\" option....\n";
        cout<<"Else contact manager to recover account...\n";
    }
    sleep(7);
}

void delete_record(record_pointer* head,long int acc_number)
{
    record_pointer acc=(record_pointer)malloc(sizeof(struct record));
    acc=*head;
    int flag=0;
    record_pointer deleted=(record_pointer)malloc(sizeof(struct record));
    for(int i=0;i<count;i++)
    {
        if(acc->account_number==acc_number)
        {
            flag=1;
            count--;
            cout<<"----------------Record found--------------------------------------\n";
            (deleted->next)=(deleted->next)->next;
            cout<<"----------------Record deleted successfully---------------------\n";
            break;
        }
        deleted=acc;
    }
    if(flag==0)
    {
        cout<<"----------------Record not found-----------------------------------\n";
    }
    sleep(7);
} 

void save_data(record_pointer* head)
{
    record_pointer acc=(record_pointer)malloc(sizeof(struct record));
    acc=*head;
    FILE *f=fopen("count.txt","w");
    fprintf(f,"%d",count);
    fclose(f);

    FILE *fp=fopen("record.txt","w");
    for(int i=0;i<count;i++)
    {
        fprintf(fp,"    %ld                %s                %s                %f\n",acc->account_number,acc->first_name,acc->last_name,acc->current_balence);
        acc=acc->next;
    }
    fclose(fp);
}

int main(void)
{
    //Struct declaration
    record_pointer head=(record_pointer)malloc(sizeof(struct record));
    record_pointer acc=(record_pointer)malloc(sizeof(struct record));
    cout<<"\t\t\tWelcome to Bank Management System!!!\n\n\n";
    sleep(7);
    cout<<"Featching data from database...\n";
    sleep(7);
    FILE *count_pointer=fopen("count.txt","r");    //here we will get count of record
    fscanf(count_pointer,"%d",&count);
    fclose(count_pointer);
    int less_count=0;
    FILE *fp=fopen("record.txt","r");
    for(int i=0;i<count;i++)
    {
        if(less_count==0)
        {
            fscanf(fp,"    %ld                %s                %s                %f\n",&head->account_number,&head->first_name,&head->last_name,&head->current_balence);
            head->next=NULL;
        }else{
            record_pointer new_record=(record_pointer)malloc(sizeof(struct record));
            fscanf(fp,"    %ld                %s                %s                %f\n",&new_record->account_number,&new_record->first_name,&new_record->last_name,&new_record->current_balence);
            new_record->next=NULL;
            record_pointer last_record=(record_pointer)malloc(sizeof(struct record));
            last_record=head;
            while(last_record->next!=NULL)
            {
                last_record=last_record->next;
            }
            last_record->next=new_record;
        }
        less_count++;
    }
    fclose(fp);
    cout<<"Data fetch successfull....\n";
    sleep(7);
    cout<<"Regaining Bank management system......\n";
    sleep(7);
    cout<<"-----------------------Started!!!---------------------\n";
    while(1)
    {
        int choice;
        cout<<"--------------------------------------------------\n";
        cout<<"Select one option below\n";
        cout<<"         1-->Add record\n";
        cout<<"         2-->Show record\n";
        cout<<"         3-->Update record\n";
        cout<<"         4-->Search record\n";
        cout<<"         5-->Add Account Balence(MANAGER MODE)\n";
        cout<<"         6-->Delete record\n";
        cout<<"         7-->Quit\n\n";
        cout<<"----------------------------------------------------\n";
        cout<<"Enter Your choice:  ";
        cin>>choice;
        long int acc_number;
        switch (choice)
        {
            case 1:
                add_record(&head);
                break;
            case 2:
                show_record(&head);
                break;
            case 3:
                cout<<"Enter account number: ";
                cin>>acc_number;
                edit_record(&head,acc_number);
                break;
            case 4:
                cout<<"Enter account number: ";
                cin>>acc_number;
                search_record(&head,acc_number);
                break;
            case 5:
                cout<<"Enter account number: ";
                cin>>acc_number;
                float account_balence;
                cout<<"Enter Balence to add: ";
                cin>>account_balence;
                add_balence(&head,acc_number,account_balence);
                break;
            case 6:
                cout<<"Enter account number: ";
                cin>>acc_number;
                delete_record(&head,acc_number);
                break;
            case 7:
                cout<<"Thank you for using Bank Management System!!!\n";
                cout<<"System saving all account information....\n";
                save_data(&head);
                sleep(4);
                cout<<"Logging out....Shutting down system....\n";
                exit(0);
                break;
            default:
                cout<<"Ooops...You selected wrong option!!\nPlease go through above options and select accordingly.\n";
                break;
        }
    }
}