#include <stdio.h>
#define max 50

// Record 
typedef struct {
    char name [50], gender [10];
    float notas [3], average;
    int age, registration, on;
} record; 

record alunos [max];

// Global variables
int total = 0, cmd;
char arq_name [15];

main () {
    show_menu ();
}

// Procedure
void show_menu () {
    int cmd;

    do {
        system ("cls");
        printf ("Student Registration\n");
        printf ("-----------------------------");

        printf ("\n1 - Student Register");
        printf ("\n2 - Student Search");
        printf ("\n3 - list student");
        printf ("\n4 - Save/Open External Register\n");

        printf ("\n0 - Close Program\n\n>> ");
        scanf ("%d", &cmd);
        getchar ();

        switch (cmd) {
            case 0:
                exit (0);
            break;

            default:
            printf ("Error! invalid command\n");
            system ("pause");
            show_menu ();
            break;
        }

    } while (cmd != 0);
}
