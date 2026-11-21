#include <stdio.h>
#include <string.h>


void clear_input(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

int main(void) {

    char search_term[256];
    char path[256];
    char line[256];
    int count = 1;

    printf("You are using Sift \n");
    printf("Enter the search term: "); // Input search term
    fgets(search_term, sizeof(search_term), stdin);
    if (strchr(search_term, '\n') == NULL) { // If leftover, clear
        clear_input();
    }

    printf("Enter the path: "); // Input path
    fgets(path, sizeof(path), stdin);

    search_term[strcspn(search_term, "\n")] = '\0'; // Get rid of trail
    path[strcspn(path,"\n")] = '\0';

    FILE *p_file;
    p_file = fopen(path, "r");

    if (p_file == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(line, sizeof(line), p_file) != NULL) {
        if (strstr(line, search_term) != NULL) {
            printf("%d %s", count, line);
        }
        count++;
    }
    fclose(p_file);
    return 0;
} 