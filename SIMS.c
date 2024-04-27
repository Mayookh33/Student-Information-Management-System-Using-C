//Student Information Management System (SIMS) using C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void coursename();

//Variable to keep track of number of students
int i = 0;

//Structure to store the student information
struct stinfo {
	char name[50];
	int roll;
	int age;
	float gpa;
	int cid[10];
} st[50];

//Function to add the student
void add_student()
{
	FILE *file = fopen("students.txt", "a");
    if (file == NULL)
    {
        printf("Unable to open the file\n");
        return;
    }

	printf("Add the Students Details\n");
	printf("Enter the Full Name of student\n");
	scanf(" %[^\n]s", st[i].name);
	printf("Enter the Roll Number\n");
	scanf("%d", &st[i].roll);
	printf("Enter the Age\n");
	scanf("%d", &st[i].age);
	printf("Enter the GPA obtained\n");
	scanf("%f", &st[i].gpa);
	printf("Enter the course ID of each course\n");
	for (int j = 0; j < 5; j++) {
		scanf("%d", &st[i].cid[j]);
		}

	 fprintf(file, "Name: %s\nRoll: %d\nAge: %d\nGPA: %.2f\nCourse IDs: ", st[i].name, st[i].roll, st[i].age, st[i].gpa);
    for (int j = 0; j < 5; j++) {
        fprintf(file, "%d ", st[i].cid[j]);
    }
    fprintf(file, "\n");

	printf("The Student Details are added successfully\n");
	i = i + 1;

	fclose(file);
}

//Function to find the student by the roll number
void find_rl()
{
    FILE *file = fopen("students.txt", "r");
    if (file == NULL)
    {
        printf("Unable to open the file\n");
        return;
    }

    int x;
    printf("Enter the Roll Number of the student\n");
    scanf("%d", &x);

    char name[50];
    int roll, age, cid[5];
    float gpa;

    while (fscanf(file, "Name: %[^\n]\nRoll: %d\nAge: %d\nGPA: %f\nCourse IDs: %d %d %d %d %d\n", name, &roll, &age, &gpa, &cid[0], &cid[1], &cid[2], &cid[3], &cid[4]) != EOF)
    {
        if (x == roll) {
            printf("The Students Details are\n\n");
            printf("Full Name: %s\n", name);
            printf("Roll Number: %d\n", roll);
            printf("Age: %d\n", age);
            printf("GPA: %.2f\n", gpa);
            coursename(cid);
            fclose(file);
            return;
        }
    }

    printf("The Roll Number not Found\n");
    fclose(file);
}

//Function to find the student by the full name
void find_fn()
{
    FILE *file = fopen("students.txt", "r");
    if (file == NULL)
    {
        printf("Unable to open the file\n");
        return;
    }

    char a[50];
    printf("Enter the Full Name of the student\n");
    scanf(" %[^\n]s", a);

    char name[50];
    int roll, age, cid[5];
    float gpa;

    while (fscanf(file, "Name: %[^\n]\nRoll: %d\nAge: %d\nGPA: %f\nCourse IDs: %d %d %d %d %d\n", name, &roll, &age, &gpa, &cid[0], &cid[1], &cid[2], &cid[3], &cid[4]) != EOF)
    {
        if (!strcmp(name, a)) {
            printf("The Students Details are\n\n");
            printf("Full Name: %s\n", name);
            printf("Roll Number: %d\n", roll);
            printf("Age: %d\n", age);
            printf("GPA: %.2f\n", gpa);
            coursename(cid);
            fclose(file);
            return;
        }
    }

    printf("Name not Found\n");
    fclose(file);
}

//Function to print the course name
void coursename(int cid[5])
{
    printf("Courses Enrolled: \n");
    for (int k = 0; k < 5; k++) {
        switch (cid[k]) {
            case 101:
                printf("Mathematics\n");
                break;
            case 102:
                printf("Physics\n");
                break;
            case 103:
                printf("Chemistry\n");
                break;
            case 104:
                printf("Computer\n");
                break;
            case 105:
                printf("English\n");
                break;
            case 106:
                printf("Biology\n");
                break;
            case 107:
                printf("History\n");
                break;
            case 108:
                printf("Geography\n");
                break;
            case 109:
                printf("Economics\n");
                break;
            case 110:
                printf("Statistics\n");
                break;       
            default:
                printf("Unknown\n");
                break;
        }
    }
}

//Function to find the number of students enrolled in a particular course
void find_c()
{
    FILE *file = fopen("students.txt", "r");
    if (file == NULL)
    {
        printf("Unable to open the file\n");
        return;
    }

    int id;
    printf("Enter the course ID \n");
    scanf("%d", &id);
    int c = 0;

    char name[50];
    int roll, age, cid[5];
    float gpa;

    while (fscanf(file, "Name: %[^\n]\nRoll: %d\nAge: %d\nGPA: %f\nCourse IDs: %d %d %d %d %d\n", name, &roll, &age, &gpa, &cid[0], &cid[1], &cid[2], &cid[3], &cid[4]) != EOF)
    {
        for (int d = 0; d < 5; d++) {
            if (id == cid[d]) {
                c++;
                break;
            }
        }
    }

    if (c > 0) {
        printf("The number of students enrolled in course ID %d are %d\n", id, c);
    } else {
        printf("No students are enrolled in course ID %d\n", id);
    }

    fclose(file);
}

//Function to print the total number of students
void tot_s()
{
    FILE *file = fopen("students.txt", "r");
    if (file == NULL)
    {
        printf("Unable to open the file\n");
        return;
    }

    int count = 0;
    char name[50];
    int roll, age, cid[5];
    float gpa;

    while (fscanf(file, "Name: %[^\n]\nRoll: %d\nAge: %d\nGPA: %f\nCourse IDs: %d %d %d %d %d\n", name, &roll, &age, &gpa, &cid[0], &cid[1], &cid[2], &cid[3], &cid[4]) != EOF)
    {
        count++;
    }

    printf("The total number of students are %d\n", count);

    fclose(file);
}

//Function to delete a student by the roll number
void del_s()
{
    FILE *file = fopen("students.txt", "r");
    if (file == NULL)
    {
        printf("Unable to open the file\n");
        return;
    }

    int a;
    printf("Enter the Roll Number which you want to delete\n");
    scanf("%d", &a);

    FILE *tempfile = fopen("temp.txt", "w");
    if (tempfile == NULL)
    {
        printf("Unable to open the temporary file\n");
        fclose(file);
        return;
    }

    char name[50];
    int roll, age, cid[5];
    float gpa;
    int found = 0;

    while (fscanf(file, "Name: %[^\n]\nRoll: %d\nAge: %d\nGPA: %f\nCourse IDs: %d %d %d %d %d\n", name, &roll, &age, &gpa, &cid[0], &cid[1], &cid[2], &cid[3], &cid[4]) != EOF)
    {
        if (a == roll) {
            found = 1;
        } else {
            fprintf(tempfile, "Name: %s\nRoll: %d\nAge: %d\nGPA: %.2f\nCourse IDs: ", name, roll, age, gpa);
            for (int j = 0; j < 5; j++) {
                fprintf(tempfile, "%d ", cid[j]);
            }
            fprintf(tempfile, "\n");
        }
    }

    fclose(file);
    fclose(tempfile);

    if (found) {
        remove("students.txt");
        rename("temp.txt", "students.txt");
        printf("The Student Details are deleted successfully\n");
    } else {
        remove("temp.txt");
        printf("The Roll Number not Found\n");
    }
}

//Function to update a student's data
void up_s()
{
    FILE *file = fopen("students.txt", "r");
    if (file == NULL)
    {
        printf("Unable to open the file\n");
        return;
    }

    int a;
    printf("Enter the Roll Number which you want to update\n");
    scanf("%d", &a);

    FILE *tempfile = fopen("temp.txt", "w");
    if (tempfile == NULL)
    {
        printf("Unable to open the temporary file\n");
        fclose(file);
        return;
    }

    char name[50];
    int roll, age, cid[5];
    float gpa;
    int found = 0;

    while (fscanf(file, "Name: %[^\n]\nRoll: %d\nAge: %d\nGPA: %f\nCourse IDs: %d %d %d %d %d\n", name, &roll, &age, &gpa, &cid[0], &cid[1], &cid[2], &cid[3], &cid[4]) != EOF)
    {
        if (a == roll) {
            printf("Enter the Full Name of student\n");
            scanf(" %[^\n]s", name);
            printf("Enter the Roll Number\n");
            scanf("%d", &roll);
            printf("Enter the Age\n");
            scanf("%d", &age);
            printf("Enter the GPA obtained\n");
            scanf("%f", &gpa);
            printf("Enter the course ID of each course\n");
            for (int k = 0; k < 5; k++) {
                scanf("%d", &cid[k]);
            }
            printf("The Student Details are updated successfully\n");
            found = 1;
        }

        fprintf(tempfile, "Name: %s\nRoll: %d\nAge: %d\nGPA: %.2f\nCourse IDs: ", name, roll, age, gpa);
        for (int j = 0; j < 5; j++) {
            fprintf(tempfile, "%d ", cid[j]);
        }
        fprintf(tempfile, "\n");
    }

    fclose(file);
    fclose(tempfile);

    if (found) {
        remove("students.txt");
        rename("temp.txt", "students.txt");
    } else {
        remove("temp.txt");
        printf("The Roll Number not Found\n");
    }
}

//Main menu
void main()
{
	int choice;
	while (i=1) {
		printf("\nStudent Information Management System\n\n");
		printf("1. Add the Student Details\n");
		printf("2. Find the Student Details by Roll Number\n");
		printf("3. Find the Student Details by Full Name\n");
		printf("4. Find the Number of Students in a Course\n");
		printf("5. Find the Total number of Students\n");
		printf("6. Delete the Students Details by Roll Number\n");
		printf("7. Update the Students Details by Roll Number\n");
		printf("8. To Exit\n\n");
		printf("Enter your choice to find the task\n");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			add_student();
			break;
		case 2:
			find_rl();
			break;
		case 3:
			find_fn();
			break;
		case 4:
			find_c();
			break;
		case 5:
			tot_s();
			break;
		case 6:
			del_s();
			break;
		case 7:
			up_s();
			break;
		case 8:
			exit(0);
			break;
		default:
			printf("Invalid Choice\n");
			break;	
		}
	}
}