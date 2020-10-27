#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define RESET "\033[0m"
#define RED "\033[31m"
#define BOLDBLACK "\033[1m\033[30m"

void welcome();
void login();
void code_exit();

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