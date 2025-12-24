#include <stdio.h>
#include <stdlib.h>

void createNote();
void viewNote();
void editNote();

int main() {
    int choice;

    while (1) {
        printf("\n===== NOTES APPLICATION =====\n");
        printf("1. Create Note\n");
        printf("2. View Notes\n");
        printf("3. Edit Notes\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // clear buffer

        switch (choice) {
            case 1:
                createNote();
                break;
            case 2:
                viewNote();
                break;
            case 3:
                editNote();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

void createNote() {
    FILE *fp;
    char note[500];

    fp = fopen("notes.txt", "a");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter your note (end with #):\n");
    while ((note[0] = getchar()) != '#') {
        fputc(note[0], fp);
    }
    fputc('\n', fp);

    fclose(fp);
    printf("Note saved successfully!\n");
}

void viewNote() {
    FILE *fp;
    char ch;

    fp = fopen("notes.txt", "r");
    if (fp == NULL) {
        printf("No notes found!\n");
        return;
    }

    printf("\n----- Your Notes -----\n");
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    fclose(fp);
}

void editNote() {
    FILE *fp;
    char note[500];

    fp = fopen("notes.txt", "w");  // overwrite file
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter new notes (end with #):\n");
    while ((note[0] = getchar()) != '#') {
        fputc(note[0], fp);
    }
    fputc('\n', fp);

    fclose(fp);
    printf("Notes edited successfully!\n");
}