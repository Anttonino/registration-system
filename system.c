#include <stdio.h>
#include <string.h>
#define max 50

// Record 
typedef struct {
    char name [50], gender [10];
    float grade [3], average;
    int age, registration, active;
} record; 

record Student [max];

// Global variables
int total = 0;
char arq_name [15];

int main () {
    show_menu ();
}

// Procedure
void show_menu () {
    int command;

    do {
        system ("cls");
        printf ("Student Registration\n");
        printf ("-----------------------------");

        printf ("\n1 - Student Register");
        printf ("\n2 - Student Search");
        printf ("\n3 - list student");
        printf ("\n4 - Save/Open External Register\n");

        printf ("\n0 - Close Program\n\n>> ");
        scanf ("%d", &command);
        getchar ();

        switch (command) {
            case 0:
                exit (0);
            break;

            case 1:
                register_student ();
            break;

            default:
            printf ("Error! invalid command\n");
            system ("pause");
            show_menu ();
            break;
        }

    } while (command != 0);
}

void register_student () {
    char name [50], gender [10];
    float grade [3], average;
    int age, registration, on, command = 1;

    do {
        system ("cls");
        printf ("Student Registration\n");
	    printf ("-----------------------------\n");
        printf ("Type your name: "); fgets (name, sizeof(name),stdin);
        printf ("\nType your registration: "); scanf ("%d", & registration);
        printf ("\nType your age: "); scanf ("%d", & age); getchar ();
        printf ("\nType your gender: "); fgets (gender, sizeof(gender),stdin);
        printf ("\ninsert your first grade: "); scanf ("%f", & grade [0]);
        printf ("\ninsert your second grade: "); scanf ("%f", & grade [1]);
        printf ("\ninsert your third grade: "); scanf ("%f", & grade [2]);

        for (int index = 0; index < max; index++){
            if (Student[index].active == 0) {
                
                Student[index].grade[0] = grade[0];
                Student[index].grade[1] = grade[1];
                Student[index].grade[2] = grade[2];
                Student[index].registration = registration;
                Student[index].age = age;
				strcpy (Student[index].name, name);
				strcpy (Student[index].gender, gender);
				Student[index].active = 1;
				total ++;
				break;	
			}
        }
        system ("cls");
        printf ("Congratulations, you registered the student %s", name);
        printf ("\n1 - New Register\n");
        printf ("0 - Main Menu\n");
        printf ("\n>> "); scanf ("%d", &command);
        getchar ();
        
        switch (command) {
            case 0:
                show_menu ();
            break;

            case 1:
                register_student ();
            break;
    
            default:
            printf ("Error! invalid command\n");
            system ("pause");
            show_menu ();
            break;
        }
    } while (command != 0);
}
