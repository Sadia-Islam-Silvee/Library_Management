#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define RESET "\033[0m"
#define RED "\033[31m"
#define BOLDBLACK "\033[1m\033[30m"

void welcome();
void login();
void code_exit();
void serve_menu();
int search_book(int);
void lend_book(int);

int check_login(int, int);

int main()
{
    welcome();
    int i;
    printf("Enter 1 to login, 0 to exit.\n: ");
    scanf("%d", &i);
    if (i)
    {
        login();
    }
    // code_exit();
    return 0;
}

void welcome()
{
    system("cls");
    printf("       .--.                   .---.\n");
    printf("   .---|__|           .-.     |~~~|\n");
    printf(".--|===|--|_          |_|     |~~~|--.\n");
    printf("|  |===|  |'\\     .---!~|  .--|   |--|\n");
    printf("|%%%%|   |  |.'\\    |===| |--|%%%%|   |  |\n");
    printf("|%%%%|   |  |\\.'\\   |   | |__|  |   |  |\n");
    printf("|  |   |  | \\  \\  |===| |==|  |   |  |\n");
    printf("|  |   |__|  \\.'\\ |   |_|__|  |~~~|__|\n");
    printf("|  |===|--|   \\.'\\|===|~|--|%%%%|~~~|--|\n");
    printf("^--^---'--^    `-'`---^-^--^--^---'--'\n");
    printf("\n\nWelcome to\n");
    puts(BOLDBLACK "     __  __       __  __      __    " RESET);
    puts(BOLDBLACK " /\\ |__)/    |  ||__)|__) /\\ |__)\\_/" RESET);
    puts(BOLDBLACK "/--\\|__)\\__  |__||__)| \\ /--\\| \\  | " RESET);
    printf("\n");
}

void login()
{
    system("cls");
    printf("Enter your login info\n\n");
    int id, password, login_success;
    printf("ID: ");
    scanf("%d", &id);
    printf("PASSWORD: ");
    scanf("%d", &password);
    login_success = check_login(id, password);
    if (login_success)
    {
        printf("Successfully Logged In.\n");
        serve_menu();
    }
    else
    {
        printf(RED "Check username & password.\n" RESET);
    }
}

void code_exit()
{
    system("cls");
}

int check_login(int i, int p)
{
    FILE *file = fopen("user.txt", "r");
    char line[1000];
    int id, pass;
    while (fgets(line, sizeof(line), file))
    {
        sscanf(line, "%d %d", &id, &pass);
        if (id == i && pass == p)
        {
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0;
}

void serve_menu()
{
    int choice;
    int isbn;
    int check_ok;
    puts("Enter 1 to search book.");
    puts("Enter 2 to lend book");
    puts("Enter 3 to deposit book");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("Enter ISBN: ");
        scanf("%d", &isbn);
        check_ok = search_book(isbn);
        if (check_ok)
        {
            printf("Do You want to Lend it? (1. Yes; 2. No): ");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                lend_book(isbn);
                break;
            case 2:
                break;
            default:
                puts("Wrong Choice");
                break;
            }
        }
        break;
    case 2:
        printf("Enter ISBN: ");
        scanf("%d", &isbn);
        lend_book(isbn);
        break;
    case 3:
        puts("DEPOSIT");
        break;
    default:
        puts("Wrong Input");
        break;
    }
}

int search_book(int isbn)
{
    FILE *file;
    char line[1000];
    int dbisbn;
    file = fopen("book.txt", "r");
    if (file == NULL)
    {
        printf(RED "ERROR: File Cannot be accessed." RESET);
        return 0;
    }
    while (fgets(line, 1000, file))
    {
        sscanf(line, "%d", &dbisbn);
        if (isbn == dbisbn)
        {
            puts(line);
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    puts("Book Not Found");
    return 0;
}

void lend_book(int isbn)
{
    int check_ok = search_book(isbn);
    if (check_ok)
    {
        printf("You've got the book #%d\n", isbn);
    }
    else
    {
        printf("Book #%d is not available.\n", isbn);
    }
}