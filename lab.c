#include <stdio.h>
#include <string.h>

struct persalary {
    int month;
    long salary;
};

struct employee {
    int empnr;
    char name[12];
    struct persalary salaries[3];
    long total;
    float average;
};

void displayEmployees(struct employee employees[4]) {
    char *months[] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	int i,j;
    printf("Employee Nr Name Month Salary\n");
    for (i = 0; i < 4; i++) {
        printf("%d %s\n", employees[i].empnr, employees[i].name);

        for (j = 0; j < 3; j++) {
            printf("%s %ld\n", months[employees[i].salaries[j].month], employees[i].salaries[j].salary);
        }
    }
}

void computeAverageAndSum(struct employee employees[4]) {
    printf("Employee Nr Name Average Sum\n");
    int i,j;
    for (i = 0; i < 4; i++) {
        long sum = 0;
        for (j = 0; j < 3; j++) {
            sum += employees[i].salaries[j].salary;
        }
        float average = (float)sum / 3;

        printf("%d %s %.2f %ld\n", employees[i].empnr, employees[i].name, average, sum);
    }
}

int main() {
    struct employee employees[4];
	int i,j;
    FILE *file = fopen("emp.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    for (i = 0; i < 4; i++) {
        fscanf(file, "%d %s", &employees[i].empnr, employees[i].name);

        for (j = 0; j < 3; j++) {
            fscanf(file, "%d %ld", &employees[i].salaries[j].month, &employees[i].salaries[j].salary);
        }
    }

    fclose(file);

    // Display the initialized values
    displayEmployees(employees);
	printf("############################################################\n\n");
    // Compute and display average and sum
    computeAverageAndSum(employees);
	printf("############################################################\n\n");
    return 0;
}
void exp2()
{
	float arr[3][4]={
	{13.5,24.88,66.28,30.0},
	{2.84,412.15,13.2,9.9},
	{15.5,38.89,12.5,16.18}
	};  
	int i,j;
	for(i=0;i<3;i++)
		for(j=0;j<4;j++)
			printf("%.2f",arr[i][j]);	
}


/*
each employee structure contains an integer, a character array, an array of three persalary structures,a long, and a float. 
The size of the employee structure will depend on the size of the individual elements and padding added by the compiler.
*/
