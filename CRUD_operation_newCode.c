#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef struct
{
    int user_id;
    char name[50];
    int age;
} user;
FILE *open_file(){
    FILE *fp=fopen("users.txt","a+");
    if(!fp){
        printf("File opening fail");
        return NULL;
    }
    return fp;
}
bool checkId(FILE *file, int userid)
{
    fseek(file, 0, SEEK_SET);
    int uid, age;
    char n[50];
    while (fscanf(file, "%d\t%49[^\t]\t%d\n", &uid, n, &age) != EOF)
    {
        if (uid == userid)
        {

            return false;
        }
    }

    return true;
}
void add_users()
{
    FILE *file=open_file();
    user u;
    int n;
    printf("Enter the number of user you want to enter:");
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++)
    {
        do
        {
            printf("Enter the User ID:");
            scanf("%d", &u.user_id);
            getchar();
            if (!checkId(file, u.user_id))
            {
                printf("Error: User Id %d already exists. Please enter a unique ID.\n", u.user_id);
            }
            else
            {
                break;
            }
        } while (1);

        printf("enter user name:");
        scanf("%[^\n]", &u.name);
        getchar();
        printf("Enter user age:");
        scanf("%d", &u.age);
        getchar();
        printf("Data Stored");
        fprintf(file, "%d\t%s\t%d\n", u.user_id, u.name, u.age);
        //fflush(file); .
       
    }
     fclose(file);
}

void update()
{
    FILE *file=open_file();
    FILE *temp = fopen("temp.txt", "w");
    fseek(file, 0, SEEK_SET);
    int uid, age;
    bool f = false;
    char name[50];
    user upd_usr;
    printf("Enter the User ID for update:");
    scanf("%d", &upd_usr.user_id);
    getchar(); 
    printf("Enter the New Username:");
    scanf("%[^\n]", &upd_usr.name); 
    getchar();
    printf("Enter the age:");
    scanf("%d", &upd_usr.age);
    while (fscanf(file, "%d\t%49[^\t]\t%d\n", &uid, name, &age) != EOF)
    {
        if (uid == upd_usr.user_id)
        {
            fprintf(temp, "%d\t%s\t%d\n", upd_usr.user_id, upd_usr.name, upd_usr.age);
            f = true;
        }
        else
        {
            fprintf(temp, "%d\t%s\t%d\n", uid, name, age);
        }
    }
    fclose(file);
    fclose(temp);
    if (f)
    {
        
        remove("users.txt");
        rename("temp.txt", "users.txt");
        printf("Record updated successfully");
    }
    else
    {
        remove("temp.txt");
        printf("Record might not exist for that ID");
    }
}

void delete()
{
    FILE *file=open_file();
    fseek(file, 0, SEEK_SET);
    FILE *tmp = fopen("temp.txt", "w");
    printf("DELETE OPERATION PERFORMING");
    int u_delid, uid, age;
    char uname[50];
    bool f = false;
    user u;
    printf("\nEnter user id to be deleted");
    scanf("%d", &u_delid);
    getchar();

    while (fscanf(file, "%d\t%49[^\t]\t%d\n", &uid, uname, &age) != EOF)
    {
        if (uid == u_delid)
        {

            f = true;
        }
        else
        {
            fprintf(tmp, "%d\t%s\t%d\n", uid, uname, age);
        }
    }
    fclose(file);
    fclose(tmp);
    if (f)
    {
        
        remove("users.txt");
        rename("temp.txt", "users.txt");
        printf("user deleted succesfully");
    }
    else
    {
        remove("temp.txt");
        printf("Record doesn't exit.");
    }
}

void display()
{
    FILE *file=open_file();
    fseek(file, 0, SEEK_SET);

    int uid, age;
    char name[50];
    while (fscanf(file, "%d\t%49[^\t]\t%d\n", &uid, name, &age) != EOF)
    {
        printf("User Id :%d\n", uid);
        printf("Name:%s\n", name);
        printf("Age:%d\n", age);
     
    }
    fclose(file);
}

int main()
{
    
    int choice;
    do
    {
        printf("Enter your choice: \n1. Add\n2. Update\n3. Delete\n4. Display\n0. Exit");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            add_users();
            break;
        case 2:
            update();
            break;
        case 3:
            delete ();
            break;
        case 4:
            display();
            break;
        case 0:
            printf("Thanks !");
        default:
            printf("Invalid Choice");
        }
    } while (choice != 0);

    return 0;
}