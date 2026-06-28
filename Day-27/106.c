#include <stdio.h>

struct Employee{
    int id;
    char name[50];
    char department[30];
    float salary;
};

void addEmployee();
void viewEmployees();
void searchEmployee();
void updateEmployee();
void deleteEmployee();

int main(){

    int choice;

    do{
        printf("\n===== EMPLOYEE MANAGEMENT SYSTEM =====\n");
        printf("1. Add Employee\n");
        printf("2. View Employees\n");
        printf("3. Search Employee\n");
        printf("4. Update Employee\n");
        printf("5. Delete Employee\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){

            case 1:
                addEmployee();
                break;

            case 2:
                viewEmployees();
                break;

            case 3:
                searchEmployee();
                break;

            case 4:
                updateEmployee();
                break;

            case 5:
                deleteEmployee();
                break;

            case 6:
                printf("Thank You!\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    }while(choice!=6);

    return 0;
}

void addEmployee(){

    struct Employee e;
    FILE *fp=fopen("employees.txt","a");

    printf("Enter Employee ID: ");
    scanf("%d",&e.id);

    printf("Enter Name: ");
    scanf("%s",e.name);

    printf("Enter Department: ");
    scanf("%s",e.department);

    printf("Enter Salary: ");
    scanf("%f",&e.salary);

    fprintf(fp,"%d %s %s %.2f\n",e.id,e.name,e.department,e.salary);

    fclose(fp);

    printf("Employee Added Successfully!\n");
}

void viewEmployees(){

    struct Employee e;
    FILE *fp=fopen("employees.txt","r");

    if(fp==NULL){
        printf("No Records Found!\n");
        return;
    }

    printf("\nID\tName\tDepartment\tSalary\n");

    while(fscanf(fp,"%d %s %s %f",&e.id,e.name,e.department,&e.salary)!=EOF){

        printf("%d\t%s\t%s\t\t%.2f\n",
               e.id,e.name,e.department,e.salary);
    }

    fclose(fp);
}

void searchEmployee(){

    struct Employee e;
    int id,found=0;

    FILE *fp=fopen("employees.txt","r");

    if(fp==NULL){
        printf("No Records Found!\n");
        return;
    }

    printf("Enter Employee ID: ");
    scanf("%d",&id);

    while(fscanf(fp,"%d %s %s %f",&e.id,e.name,e.department,&e.salary)!=EOF){

        if(e.id==id){

            printf("\nEmployee Found\n");
            printf("ID         : %d\n",e.id);
            printf("Name       : %s\n",e.name);
            printf("Department : %s\n",e.department);
            printf("Salary     : %.2f\n",e.salary);

            found=1;
            break;
        }
    }

    if(found==0)
        printf("Employee Not Found!\n");

    fclose(fp);
}

void updateEmployee(){

    struct Employee e;
    int id,found=0;

    FILE *fp=fopen("employees.txt","r");
    FILE *temp=fopen("temp.txt","w");

    if(fp==NULL){
        printf("No Records Found!\n");
        return;
    }

    printf("Enter Employee ID to Update: ");
    scanf("%d",&id);

    while(fscanf(fp,"%d %s %s %f",&e.id,e.name,e.department,&e.salary)!=EOF){

        if(e.id==id){

            printf("Enter New Name: ");
            scanf("%s",e.name);

            printf("Enter New Department: ");
            scanf("%s",e.department);

            printf("Enter New Salary: ");
            scanf("%f",&e.salary);

            found=1;
        }

        fprintf(temp,"%d %s %s %.2f\n",
                e.id,e.name,e.department,e.salary);
    }

    fclose(fp);
    fclose(temp);

    remove("employees.txt");
    rename("temp.txt","employees.txt");

    if(found)
        printf("Record Updated Successfully!\n");
    else
        printf("Employee Not Found!\n");
}

void deleteEmployee(){

    struct Employee e;
    int id,found=0;

    FILE *fp=fopen("employees.txt","r");
    FILE *temp=fopen("temp.txt","w");

    if(fp==NULL){
        printf("No Records Found!\n");
        return;
    }

    printf("Enter Employee ID to Delete: ");
    scanf("%d",&id);

    while(fscanf(fp,"%d %s %s %f",&e.id,e.name,e.department,&e.salary)!=EOF){

        if(e.id==id){
            found=1;
            continue;
        }

        fprintf(temp,"%d %s %s %.2f\n",
                e.id,e.name,e.department,e.salary);
    }

    fclose(fp);
    fclose(temp);

    remove("employees.txt");
    rename("temp.txt","employees.txt");

    if(found)
        printf("Record Deleted Successfully!\n");
    else
        printf("Employee Not Found!\n");
}