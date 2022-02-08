#include<stdio.h>
#include<string.h>

void cover_page();
void password_admin();
void password_user();
void admin_mode();
void add_books();
void user_mode();
void select_mode();
void search_books();
void view_books();
void deposite_books();
void book_list();
void borrow_book();
void search_book();

struct add_book
{
    int id;
    char name [20];
    char author [20];
    int quantity;
};
FILE *file;
FILE *file2;
void cover_page()
{
    system("color f0");
    printf("\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

    printf("\n\t\t\t*-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-*");

    printf("\n\t\t\t############                                                   ############");

    printf("\n\t\t\t############              LIBRARY MANAGEMENT                   ############");

    printf("\n\t\t\t############                                                   ############");

    printf("\n\t\t\t*-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-*");

    printf("\n\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");


    printf("\n");
    printf("\n");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printf("\n\t\t\t---------------------------------------------------------------------------");

    printf("\n\t\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$");

    printf("\n\t\t\t$$$$$$$$$$$$                                                   $$$$$$$$$$$$");

    printf("\n\t\t\t$$$$$$$$$$$$               Welcome to Library                  $$$$$$$$$$$$");

    printf("\n\t\t\t$$$$$$$$$$$$                                                   $$$$$$$$$$$$");

    printf("\n\t\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$");

    printf("\n\t\t\t---------------------------------------------------------------------------\n");

    printf("\n\t\t\t----------------------------------------------------------------------------\n\n");

    printf("\n");


}

void password_admin()
{
    char pass1[20] = "1234";
    char pass2[20];

    printf("\n\t\tEnter password : ");
    fflush(stdin);
    gets(pass2);

    if(strcmp(pass1, pass2) == 0)
    {
        admin_mode();
    }
    else
    {
        printf("\n\t\t Wrong Password");
        printf("\n\t\t Try again....");
        password_admin();
    }


    fflush(stdin);

}
void password_user()
{
    char pass1[20] = "123";
    char pass2[20];

    printf("\n\t\tEnter password : ");
    fflush(stdin);
    gets(pass2);

    if(strcmp(pass1, pass2) == 0)
    {
        user_mode();
    }
    else
    {
        printf("\n\t\t Wrong Password");
        printf("\n\t\t Try again....");
        password_user();
    }


    fflush(stdin);

}

void admin_mode()
{
    system("cls");
    printf("\n\t\t1) Add Book\n");
    printf("\n\t\t2) View Book\n");
    printf("\n\t\t3) Search Book By ID\n");
    printf("\n\t\t4) Exit\n");

    printf("\t\t\t\n\n\t\t**********************************************\n");

    printf("\t\tEnter your choice :");
    int n;
    scanf("%d",&n);

    if(n==1)
    {
        system("cls");
        add_books();
    }
    else if(n==2)
    {
        view_books();
    }
    else if(n==3)
    {
        search_books();
    }
    else if(n==4)
    {
        exit(0);
    }
    else
    {
        printf("\n\t\tWrong choice");
        printf("\n\t\tTry again :");
    }
    fflush(stdin);
    getchar();
    system("cls");
    admin_mode();
}

void add_books()
{
    printf("\n\n \t\t****************** Add Book ******************\n\n");
    int d,count=0;
    printf("\n\t\tBook ID:");
    scanf("%d",&d);
    struct add_book a;
    file = fopen("book.txt","ab+");
    rewind(file);


    while(fread(&a, sizeof(a),1,file)==1)
    {
        if(d==a.id)
        {
            count=1;
        }
    }

    if(count==1)
    {
        printf("\n\t\tThe book id is already exist");
    }
    else
    {

        printf("\n\t\tYou can add this book");
        printf("\n\t\tBook ID:");
        scanf("%d",&a.id);
        printf("\t\tBook Name : ");
        fflush(stdin);
        scanf("%s",a.name);
        printf("\t\tAuthor : ");
        fflush(stdin);
        scanf("%s",a.author);
        printf("\t\tQuantity : ");
        fflush(stdin);
        scanf("%d",&a.quantity);
        fseek(file,0,SEEK_END);
        fwrite(&a,sizeof(a),1,file);
        fclose(file);
        printf("\n\t\tBooks is added successfully...");
    }
    printf("\n\t\tPress any key...");
    fflush(stdin);
    int select;
    printf("\n\t\t1)Admin mode");
    printf("\n\t\t=>Press Any key For Exit : ");
    scanf("%d",&select);
    if(select == 1)
    {
        system("cls");
        admin_mode();
    }
    else
    {
        exit(0);
    }

}
void view_books()
{
    struct add_book a;

    system("cls");
    int count=0;

    printf("\n\n\t\t********* View Book List *********\n\n");
    printf("\tID\tName\tAuthor\tQunt\n\n");

    file = fopen("book.txt","rb");

    while( fread(&a,sizeof(a),1,file)==1)
    {
        printf("\t%d",a.id);
        printf("\t%s",a.name);
        printf("\t%s",a.author);
        printf("\t%d\n",a.quantity);

        count=count + a.quantity;

    }
    printf("\n\n\n\t\t Total Book: %d",count);
    fflush(stdin);

    int select;
    printf("\n\t\t1)Admin mode");
    printf("\n\t\t=>Press Any key For Exit : ");
    scanf("%d",&select);
    if(select == 1)
    {
        system("cls");
        admin_mode();
    }
    else
    {
        exit(0);
    }
}

void search_books()
{

    struct add_book a;
    int d,count=0;
    system("cls");

    printf("\n\n\t\t ************ Search Book ************");
    printf("\n\t\t searching.....\n\n");

    file = fopen("book.txt","rb");

    printf("\n\t\t Enter ID: ");
    scanf("%d",&d);

    while(fread(&a,sizeof(a),1,file)==1)
    {
        if(d==a.id)
        {

            printf("\n\n\t\t Book is Found\n");
            printf("\t\t ID: %d",a.id);
            printf("\n\t\t Name: %s",a.name);
            printf("\n\t\t Author: %s",a.author);
            printf("\n\t\t Quantity: %d",a.quantity);


            count=1;
        }
    }
    if(count==0)
    {
        printf("\n\n\t\t Book is Not Found");
    }
    printf("\n\n\t\t press any key....");
    fflush(stdin);

    int select;
    printf("\n\t\t1)Admin mode");
    printf("\n\t\t=>Press Any key For Exit : ");
    scanf("%d",&select);
    if(select == 1)
    {
        system("cls");
        admin_mode();
    }
    else
    {
        exit(0);
    }
}

void user_mode()
{
    system("cls");
    printf("\n\t\t1) Search Book by ID");
    printf("\n\t\t2) Book list");
    printf("\n\t\t3) Borrow Book");
    printf("\n\t\t4) Deposit Book");
    printf("\n\t\t5) Exit\n");

    printf("\t\t\t\n\n\t\t**********************************************\n");

    printf("\n\t\tEnter your choice : ");
    int t;
    scanf("%d",&t);

    if(t==1)
    {
        search_book();
    }
    else if(t==2)
    {
        book_list();
    }
    else if(t==3)
    {
        borrow_book();
    }
    else if(t==4)
    {
        deposite_books();
    }
    else if(t==5)
    {
        search_books();
    }
    else if(t==6)
    {
        exit(0);
    }
    else
    {
        printf("\n\t\tWrong choice");
        printf("\n\t\tTry again");
    }
    fflush(stdin);
    getchar();
    system("cls");
    user_mode();


}
void borrow_book()
{
    struct add_book a;
    system("cls");
    int d, count = 0 ;
    printf("\n\n\t\t ************* Borrow book *************\n\n");
    printf("\n\n\t\t Enter ID for Borrow Book : ");
    scanf("%d", &d);
    file = fopen("book.txt", "rb+");
    rewind (file);
    while(fread(&a, sizeof(a), 1, file) == 1)
    {
        if(d == a.id)
        {
            count = 1;
        }
    }

    if(count == 0)
    {
        printf("\n\t\t-Book is not Available");
    }
    else
    {
        printf("\n\t\t Book is Available!");
        file2 = fopen("text.txt", "wb");
        rewind(file);
        while(fread(&a, sizeof(a), 1, file) ==1)
        {

            if(d != a.id)
            {
                fseek(file2, ftell(file2)-sizeof(a), 0);
                fwrite(&a, sizeof(a), 1, file2);

            }
        }
        fclose(file);
        fclose(file2);
        remove("book.txt");
        rename("text.txt", "book.txt");;
        file = fopen("book.txt", "rb");
        fclose(file);
        printf("The book is Borrowed successfully");
    }
        printf("\n\t\tPress any key...");
    fflush(stdin);
    int select;
    printf("\n\t\t1)User mode");
    printf("\n\t\t=>Press Any key For Exit : ");
    scanf("%d",&select);
    if(select == 1)
    {
        system("cls");
        user_mode();
    }
    else
    {
        exit(0);
    }

}
void deposite_books()
{
    system("cls");
    printf("\n\n\t\t****************** Deposit Book ******************\n\n");
    int d,count=0;
    printf("\n\t\tBook ID:");
    scanf("%d",&d);
    struct add_book a;
    file = fopen("book.txt","ab+");
    rewind(file);


    while(fread(&a, sizeof(a),1,file)==1)
    {
        if(d==a.id)
        {
            count=1;
        }
    }

    if(count==1)
    {
        printf("\n\t\tWrong Book ID");
    }
    else
    {

        printf("\n\t\tYou can add this book");
        printf("\n\t\tBook ID:");
        scanf("%d",&a.id);
        printf("\t\tBook Name : ");
        fflush(stdin);
        scanf("%s",a.name);
        printf("\t\tAuthor : ");
        fflush(stdin);
        scanf("%s",a.author);
        printf("\t\tQuantity : ");
        fflush(stdin);
        scanf("%d",&a.quantity);
        fseek(file,0,SEEK_END);
        fwrite(&a,sizeof(a),1,file);
        fclose(file);
        printf("\n\t\tBooks is added successfully...");
    }
    printf("\n\t\tPress any key...");
    fflush(stdin);
    int select;
    printf("\n\t\t1)User mode");
    printf("\n\t\t=>Press Any key For Exit : ");
    scanf("%d",&select);
    if(select == 1)
    {
        system("cls");
        user_mode();
    }
    else
    {
        exit(0);
    }
}
void select_mode()
{

    int a;
    printf("\n\t\t->> Press 1 for Admin Mode");
    printf("\n\t\t->> Press 2 for User Mode\n\t\t");
    scanf("%d",&a);
    if(a==1)
    {

        password_admin();
    }
    else if (a==2)
    {
        system("cls");
        password_user();
    }
    else
    {
        printf("\n\t\tINVAILD INPUT");
        printf("\n\t\tTry Again\n");
        select_mode();
    }


}
void book_list()
{

    struct add_book a;

    system("cls");
    int count=0;

    printf("\n\n\t\t********* Book List *********\n\n");
    printf("\tID\tName\tAuthor\tQunt\n\n");

    file = fopen("book.txt","rb");

    while( fread(&a,sizeof(a),1,file)==1)
    {
        printf("\t%d",a.id);
        printf("\t%s",a.name);
        printf("\t%s",a.author);
        printf("\t%d\n",a.quantity);

        count=count + a.quantity;

    }
    printf("\n\n\n\t\t Total Book: %d",count);
    fflush(stdin);

    int select;
    printf("\n\t\t1)User mode");
    printf("\n\t\t=>Press Any key For Exit : ");
    scanf("%d",&select);
    if(select == 1)
    {
        system("cls");
        user_mode();
    }
    else
    {
        exit(0);
    }
}
void search_book()
{
  struct add_book a;
    int d,count=0;
    system("cls");

    printf("\n\n\t\t ************ Search Book ************");
    printf("\n\t\t searching.....\n\n");

    file = fopen("book.txt","rb");

    printf("\n\t\t Enter Book ID: ");
    scanf("%d",&d);

    while(fread(&a,sizeof(a),1,file)==1)
    {
        if(d==a.id)
        {

            printf("\n\n\t\t Book is Found\n");
            printf("\t\t ID: %d",a.id);
            printf("\n\t\t Name: %s",a.name);
            printf("\n\t\t Author: %s",a.author);
            printf("\n\t\t Quantity: %d",a.quantity);


            count=1;
        }
    }
    if(count==0)
    {
        printf("\n\n\t\t Book is Not Found");
    }
    printf("\n\n\t\t press any key....");
    fflush(stdin);

    int select;
    printf("\n\t\t1)User mode");
    printf("\n\t\t=>Press Any key For Exit : ");
    scanf("%d",&select);
    if(select == 1)
    {
        system("cls");
        user_mode();
    }
    else
    {
        exit(0);
    }
}
int main()
{
    cover_page();
    select_mode();
}


