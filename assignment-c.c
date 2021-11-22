#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char firstname[10];
    char middlename[10];
    char lastname[10];
    char company[10];
    char phone[20];
    char email[100];
    char address[100];
    char birthday[20];
    char website[100];
    char note[100];
    int favourites;
} Contact;

void menu(Contact contact[], int count);
int search(Contact contact[], int count);
int addContact(Contact contact[], int count);
Contact getContact();
void getstring(char *str, int length);
void displayFavouritesContact(Contact contact[], int count);
int displayAllContact(Contact contact[], int count);
int displayDetails(Contact contact[], int count, int id);
void updateContact(Contact contact[], int count, int id);
int deleteContact(Contact contact[], int count, int id);
int AddToFavorites(Contact contact[], int count);
int main(int argc, char const *args[])
{
    system("color 0B");
    Contact contact[1000];
    int count = 0;
    while (1)
    {
        menu(contact, count);
        return 0;
    }
}
int logo()
{
    printf("                                                                                       ========================================\n");
    printf("                                                                                       | ---VTC ACADEMY CONTACT MANAGEMENT--- |\n");
    printf("                                                                                       ========================================\n");
}
int logo2()
{
    printf("                                                                                            ===============================\n");
    printf("                                                                                            |         ALL CONTACT         |\n");
    printf("                                                                                            ===============================\n");
}
int logo3()
{
    printf("                                                                                            ===============================\n");
    printf("                                                                                            |        CONTACT DETAIL       |\n");
    printf("                                                                                            ===============================\n");
}
int logo4()
{
    printf("                                                                                            ===============================\n");
    printf("                                                                                            |        SEARCH CONTACT       |\n");
    printf("                                                                                            ===============================\n");
}
int logo5()
{
    printf("                                                                                            ===============================\n");
    printf("                                                                                            |        DELETE CONTACT       |\n");
    printf("                                                                                            ===============================\n");
}
int logo6()
{
    printf("                                                                                       ========================================\n");
    printf("                                                                                       |           CREATE NEW CONTACT         |\n");
    printf("                                                                                       ========================================\n");
}
int logo7()
{
    printf("                                                                                       ========================================\n");
    printf("                                                                                       |            ADD TO FAVORITES          |\n");
    printf("                                                                                       ========================================\n");
}
int logo8()
{
    printf("                                                                                            ===============================\n");
    printf("                                                                                            |        UPDATE CONTACT       |\n");
    printf("                                                                                            ===============================\n");
}
int logo9()
{
    printf("                                                                                            ===============================\n");
    printf("                                                                                            |       FAVORITES CONTACT     |\n");
    printf("                                                                                            ===============================\n");
}
void menu(Contact contact[], int count)
{
    char choice;
    do
    {
        system("cls");
        printf("                                                                                      ========================================\n");
        printf("                                                                                      | ---VTC ACADEMY CONTACT MANAGEMENT--- |\n");
        printf("                                                                                      ========================================\n");
        printf("                                                                                         ==================================\n");
        printf("                                                                                         |  1. SEARCH YOUR CONTACT        |\n");
        printf("                                                                                         ==================================\n");
        printf("                                                                                         |  2. ADD CONTACT                |\n");
        printf("                                                                                         ==================================\n");
        printf("                                                                                         |  3. DISPLAY FAVOURITES CONTACT |\n");
        printf("                                                                                         ==================================\n");
        printf("                                                                                         |  4. DISPLAY ALL CONTACT        |\n");
        printf("                                                                                         ==================================\n");
        printf("                                                                                         |  5. EXIT APPLICATION           |\n");
        printf("                                                                                         ==================================\n");
        printf("                                                                                             #YOUR CHOICE: ");
        // printf("======================================\n");
        scanf("%c", &choice);
        choice = (int)choice - 48;
        switch (choice)
        {
        case 1:
            search(contact, count);
            break;
        case 2:
            count = addContact(contact, count);
            fflush(stdin);
            getchar();
            break;
        case 3:
            displayFavouritesContact(contact, count);
            break;
        case 4:
            count = displayAllContact(contact, count);
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Please select options [1-5]: ");
            break;
        }
    } while (choice != 5);
    // printf("Please select options [1-5]: ");
}

int search(Contact contact[], int count)
{
    char search[50];
    char fullName[100];
    system("cls");
    logo();
    logo4();
    // printf("======================================\n");
    printf("                                                                                                  Input your search: ");
    getstring(search, 50);
    printf("                                                                                                  Search Results: \n");
    for (int i = 0; i < count; i++)
    {
        if ((strcmp(search, contact[i].firstname) == 0) || (strcmp(search, contact[i].lastname) == 0) || (strcmp(search, contact[i].middlename) == 0))
        {
            strcpy(fullName, "");
            strcat(fullName, contact[i].firstname);
            strcat(fullName, " ");
            strcat(fullName, contact[i].middlename);
            strcat(fullName, " ");
            strcat(fullName, contact[i].lastname);
            printf("                                                                                            +-----------------------------+\n");
            printf("                                                                                            | No | Fullname               |\n");
            printf("                                                                                            +-----------------------------+\n");
            printf("                                                                                            | %-2d | %-22s |\n", i + 1, fullName);
            printf("                                                                                            +-----------------------------+\n");
            printf("                                                                                               Press enter to continue...");
            fflush(stdin);
            getchar();
        }
        // else
        // {
        //     printf("                                                                                            Don't found name");
        //     printf("                                                                                               Press enter to continue...");
        //     fflush(stdin);
        //     getchar();
        // }
    }
    // return 0;
}
int addContact(Contact contact[], int count)
{
    system("cls");
    Contact c;
    logo();
    logo6();
    // printf("======================================\n");
    // printf("          CREATE NEW CONTACT\n");
    // printf(" ========================================\n");
    contact[count] = getContact();
    count++;
    // printf(" ========================================\n");
    system("cls");
    logo();
    logo6();
    printf("                                                                                               Create conntact complete!\n");
    printf("                                                                                             Press enter key to continue...");
    return count;
}
Contact getContact()
{
    Contact c;
    printf("                                                                                                First Name:  ");
    getstring(c.firstname, 10);
    printf("                                                                                                Middle Name: ");
    getstring(c.middlename, 10);
    printf("                                                                                                Last Name:   ");
    getstring(c.lastname, 10);
    printf("                                                                                                Company:     ");
    getstring(c.company, 10);
    printf("                                                                                                Phone:       ");
    getstring(c.phone, 20);
    printf("                                                                                                Email:       ");
    getstring(c.email, 100);
    printf("                                                                                                Address:     ");
    getstring(c.address, 100);
    printf("                                                                                                Birthday:    ");
    getstring(c.birthday, 20);
    printf("                                                                                                Website:     ");
    getstring(c.website, 100);
    printf("                                                                                                Note:        ");
    getstring(c.note, 100);

    return c;
}
void getstring(char *str, int length)
{
    fflush(stdin);
    fgets(str, length, stdin);
    str[strlen(str) - 1] = '\0';
    fflush(stdin);
}

int displayAllContact(Contact contact[], int count)
{
    system("cls");
    logo();
    logo2();
    int choice, id, i;
    char fullName[1000];
    int dem = 1;
    if (count == 0)
    {
        printf("                                                                                              List contact is empty!\n");
        printf("                                                                                              Press Enter to continue...");
        fflush(stdin);
        getchar();
        menu(contact, count);
    }
    printf("                                                                                            +-----------------------------+\n");
    printf("                                                                                            | No | Fullname               |\n");
    printf("                                                                                            +-----------------------------+\n");
    for (i = 0; i < count; i++)
    {
        strcpy(fullName, "");
        strcat(fullName, contact[i].firstname);
        strcat(fullName, " ");
        strcat(fullName, contact[i].middlename);
        strcat(fullName, " ");
        strcat(fullName, contact[i].lastname);
        printf("                                                                                            | %-2d | %-22s |\n", i + 1, fullName);
        printf("                                                                                            +-----------------------------+\n");
    }
    // printf("+-----------------------------+\n");
    printf("                                                                                INPUT CONTACT NO TO VIEW DETAILS OR INPUT 0 TO BACK MAIN MENU: ");
    scanf("%d", &choice);
    id = choice - 1;
    if (choice == 0)
    {
        menu(contact, count);
    }
    else
    {
        count = displayDetails(contact, count, id);
    }
}
int displayDetails(Contact contact[], int count, int id)
{
    int choice, i, t;

    system("cls");
    logo();
    logo3();
    printf("                                                                                                 +--------------------+\n");
    // printf("                                                                                                 |                    |\n");
    printf("                                                                                                  First Name : %s\n", contact[id].firstname);
    printf("                                                                                                  Middle Name : %s\n", contact[id].middlename);
    printf("                                                                                                  Last Name : %s\n", contact[id].lastname);
    printf("                                                                                                  Company : %s\n", contact[id].company);
    printf("                                                                                                  Phone : %s\n", contact[id].phone);
    printf("                                                                                                  Email : %s\n", contact[id].email);
    printf("                                                                                                  Address : %s\n", contact[id].address);
    printf("                                                                                                  Birthday : %s\n", contact[id].birthday);
    printf("                                                                                                  Website : %s\n", contact[id].website);
    printf("                                                                                                  Note : %s\n", contact[id].note);
    // printf("                                                                                                 |                    |\n");
    printf("                                                                                                 +--------------------+\n");
    printf("                                                                                           Press enter to see more functions...");
    fflush(stdin);
    getchar();
    system("cls");
    logo();
    // printf( "          =======================\n");
    do
    {
        printf("                                                                                                ========================\n");
        printf("                                                                                                | 1. ADD TO FAVOURITES |\n");
        printf("                                                                                                ========================\n");
        printf("                                                                                                | 2. UPDATE            |\n");
        printf("                                                                                                ========================\n");
        printf("                                                                                                | 3. DELETE            |\n");
        printf("                                                                                                ========================\n");
        printf("                                                                                                | 4. ADD FIELD         |\n");
        printf("                                                                                                ========================\n");
        printf("                                                                                                | 5. BACK TO MAIN MENU |\n");
        printf("                                                                                                ========================\n");
        printf("                                                                                                  #YOUR CHOICE: ");
        fflush(stdin);
        scanf("%d", &choice);
        fflush(stdin);
        switch (choice)
        {
        case 1:
            AddToFavorites(contact, count);
            break;
        case 2:
            updateContact(contact, count, id);
            fflush(stdin);
            getchar();
            break;
        case 3:
            count = deleteContact(contact, count, id);
            break;
        case 4:
            break;
        case 5:
            menu(contact, count);
            break;
        default:
            // system("color 07");
            system("cls");
            logo();
            printf("                                                                                          Invalid choice, Please choose again\n");
            // system("color 04");
            // system("color 0B");
            break;
            // system("color 0B");
        }
        // system("color 0B");
    } while (choice != 5);
    return count;
}
void displayFavouritesContact(Contact contact[], int count)
{
    system("cls");
    int choice, id, t;
    char fullName[1000];
    logo();
    logo9();
    printf("                                                                                            +-----------------------------+\n");
    printf("                                                                                            | No | Fullname               |\n");
    printf("                                                                                            +-----------------------------+\n");
    for (t = 0; t < count; t++)
    {
        //assignment-c.c
        strcpy(fullName, "");
        strcat(fullName, contact[t].firstname);
        // strcat(fullName, " ");
        // strcat(fullName, contact[t].middlename);
        strcat(fullName, " ");
        strcat(fullName, contact[t].lastname);
        printf("                                                                                            | %-2d | %-22s |\n", t + 1, fullName);
    }
    printf("                                                                                            +-----------------------------+\n");
    printf("                                                                                               Input 0 to back main menu: ");
    scanf("%d", &choice);
    // id = choice - 1;
    if (choice == 0)
    {
        return;
    }
    // else
    // {
    //     displayDetails(contact, count, id);
    //     count++;
    // }
}
void updateContact(Contact contact[], int count, int id)
{
    addContact(contact, id);
    count++;
    // printf("                                                                                                 Press enter to back main menu...\n");
    fflush(stdin);
    getchar();
    menu(contact, count);
}
int deleteContact(Contact contact[], int count, int id)
{
    for (int i = id; i < count - 1; i++)
    {
        contact[i] = contact[i + 1];
    }
    count--;
    system("cls");
    logo();
    logo5();
    printf("                                                                                             Contact deleted successfully!\n");
    printf("                                                                                             Press enter to back main menu...");
    fflush(stdin);
    getchar();
    menu(contact, count);
    // displayAllContact(contact, count);
    return count;
}
int AddToFavorites(Contact contact[], int count)
{
    system("cls");
    logo();
    logo7();
    printf("                                                                                                   Added to favorites\n");
    printf("                                                                                             Press enter to back main menu...");
    fflush(stdin);
    getchar();
    menu(contact, count);
}