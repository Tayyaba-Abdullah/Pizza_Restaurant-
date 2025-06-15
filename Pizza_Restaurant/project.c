#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void admin_user();
void admin_signin_function();
void admin_menu();
void after_admin();
void admin_menu_option();
void user_signin_function();
void user_signup();
void user_signin();
void after_user();
void user_menu();
void user_menu_option();
void place_order();
void pick_up_order();
void table_reservation();
void feedback();

int main() {
    admin_user();
    return 0;
}

void admin_user() {
    char role[10];  
    printf("========================================\n");
    printf("  Welcome to Online Pizza restaurants!!\n");
    printf("========================================\n");
    printf("Can you kindly Fill this Information for\n");
    printf("        Further Procedation\n");
    printf("========================================\n");
    printf("Are you admin or user? (Admin/User): ");
    scanf("%s", role);
    system("cls");
    if (strcmp(role, "Admin") == 0 || strcmp(role, "admin") == 0) {
        printf("========================================\n");
        printf("Admin mode activated.\n");
        admin_signin_function();
    }
    else if (strcmp(role, "User") == 0 || strcmp(role, "user") == 0) {
        system("cls");
        printf("========================================\n");
        printf("User mode activated.\n");
        user_signin_function();
    }
    else {
        system("cls");
        printf("========================================\n");
        printf("Invalid input.\n");
        admin_user();
    }
}

void admin_signin_function() {
    char choice;
    char email[40];
    char password[10];

    printf("========================================\n");
    printf("1. Do you want to Sign in\n");
    printf("2. Do you want to Exit\n");
    printf("========================================\n");
    printf("Enter Your Choice (1 or 2): ");
    scanf("%s", &choice);  

    if (choice == '1') {
        system("cls");
        printf("========================================\n");
        printf("Sign in mode activated.\n");
        printf("========================================\n");
        printf("Enter Your Username: ");
        scanf("%s", email);

        if (strcmp(email, "Admin") == 0 || strcmp(email, "admin") == 0 || strcmp(email, "Tayyaba") == 0 || strcmp(email, "tayyaba") == 0) {
            printf("========================================\n");
            printf("Enter Your password: ");
            scanf("%s", password);

            if (strcmp(password, "123") == 0) {
                system("cls");
                printf("========================================\n");
                printf("Welcome %s\n", email);
                admin_menu();
            }
            else {
                system("cls");
                printf("========================================\n");
                printf("Invalid Input\n");
                admin_signin_function();
            }
        }
        else {
            system("cls");
            printf("========================================\n");
            printf("Invalid input.\n");
            admin_signin_function();
        }
    }
    else if (choice == '2') {
        system("cls");
        printf("========================================\n");
        printf("Exit mode activated.\n");
        admin_user();
    }
    else {
        system("cls");
        printf("========================================\n");
        printf("Invalid input.\n");
        admin_signin_function();
    }
}

void admin_menu() {
    char functions[10];

    printf("========================================\n");
    printf("Do you want to check Admin Functions (yes/no): ");
    scanf("%s", functions);

    if (strcmp(functions, "yes") == 0 || strcmp(functions, "YES") == 0) {
        system("cls");
        printf("========================================\n");
        printf("Admin_menu\n");
        printf("========================================\n");
        printf("1. Table_Reservation\n");
        printf("2. Pickup Order\n");
        printf("3. Customer_Feedback\n");
        printf("4. Exit\n");
        printf("========================================\n");
        admin_menu_option();
          
    }
    else if (strcmp(functions, "no") == 0 || strcmp(functions, "NO") == 0) {
        after_admin();  
    }
    else {
        system("cls");
        printf("========================================\n");
        printf("Invalid choice!!\n");
        admin_menu();
    }
}
void after_admin() {
    char choice[10];

    printf("========================================\n");
    printf("Do you want to SIGN OUT (yes/no): ");
    scanf("%s", choice);

    if (strcmp(choice, "yes") == 0 || strcmp(choice, "Yes") == 0) {
        system("cls");
        printf("========================================\n");
        printf("Sign out mode activated\n");
        admin_user();  
        
    }
    else if (strcmp(choice, "no") == 0 || strcmp(choice, "NO") == 0) {
        admin_menu();     
    }
    else {
        system("cls");
        printf("========================================\n");
        printf("Invalid choice!!\n");
        after_admin();
    }
}
void admin_menu_option() {
    int choice;
    FILE *file;
    char line[200];

    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        system("cls");
        printf("========================================\n");
        printf("Table Reservations:\n");
        printf("========================================\n");

        file = fopen("reservations.txt", "r");
        if (file == NULL) {
            printf("No reservations found.\n");
        } else {
            while (fgets(line, sizeof(line), file)) {
                printf("%s", line);
            }
            fclose(file);
        }
        admin_menu();
    }
    else if (choice == 2) {
        system("cls");
        printf("========================================\n");
        printf("Pickup Orders:\n");
        printf("========================================\n");

        file = fopen("pickup_orders.txt", "r");
        if (file == NULL) {
            printf("No pickup orders found.\n");
        } else {
            while (fgets(line, sizeof(line), file)) {
                printf("%s", line);
            }
            fclose(file);
        }
        admin_menu();
    }
    else if (choice == 3) {
        system("cls");
        printf("========================================\n");
        printf("User Feedbacks:\n");
        printf("========================================\n");

        file = fopen("feedback.txt", "r");
        if (file == NULL) {
            printf("No feedback found.\n");
        } else {
            while (fgets(line, sizeof(line), file)) {
                printf("%s", line);
            }
            fclose(file);
        }
        admin_menu();
    }
    else if (choice == 4) {
        system("cls");
        printf("========================================\n");
        printf("Exit mode activated\n");
        after_admin();
    }
    else {
        printf("========================================\n");
        printf("Invalid input!\n");
        admin_menu();
    }
}

void user_signin_function() {
    int user_choice;

    printf("========================================\n");
    printf("1. Do you want to Sign in:\n");
    printf("2. Do you want to Sign Up:\n");
    printf("3. Exit\n");
    printf("========================================\n");
    printf("Enter your choice (1 / 2 / 3): ");
    scanf("%d", &user_choice);

    switch (user_choice) {
        case 1:
            user_signin();
            break;
        case 2:
            user_signup();
            break;
        case 3:
            system("cls");
            printf("========================================\n");
            printf("Exit mode activated\n");
            admin_user();
            break;
        default:
            printf("========================================\n");
            printf("Invalid choice!\n");
            admin_user();
            break;
    }
}
void user_signup() {
    FILE *file = fopen("users.txt", "a");
    if (file == NULL) {
        printf("========================================\n");
        printf("Error opening file!\n");
        return;
    }

    char username[30];
    char password[30];
    system("cls");
    printf("========================================\n");
    printf("Sign up mode activated\n");
    printf("========================================\n");
    printf("Enter new username: ");
    scanf("%s", username);
    printf("========================================\n");
    printf("Enter new password: ");
    scanf("%s", password);

    fprintf(file, "%s %s\n", username, password);
    fclose(file);
    system("cls");
    printf("========================================\n");
    printf("Registration successful!\n");
    printf("========================================\n");
    printf("User registered as: %s\n", username);
    
    user_menu(); 
}
void user_signin() {
    char sign_up[10];
    FILE *file = fopen("users.txt", "r");
    if (file == NULL) {
        printf("========================================\n");
        printf("Error no account found! Please sign up first.\n");
        printf("========================================\n");
        printf("Would you like to sign up (yes/no):");
        scanf("%s",&sign_up);
        if (strcmp(sign_up, "yes") == 0 || strcmp(sign_up, "Yes") == 0)
        {
            system("cls");
            user_signup();
        }
        else if (strcmp(sign_up, "no") == 0 || strcmp(sign_up, "No") == 0)
        {
            system("cls");
            admin_user();
        }
        else
        {
            system("cls");
            printf("========================================\n");
            printf("Invalid choice!!\n");
            user_signin_function();
        }
        
        return;
    }

    char username[30], password[30];
    char input_username[30], input_password[30];
    int found = 0;
    system("cls");
    printf("========================================\n");
    printf("Sign in mode activated\n");
    printf("========================================\n");
    printf("Enter your username: ");
    scanf("%s", input_username);
    printf("========================================\n");
    printf("Enter your password: ");
    scanf("%s", input_password);

    while (fscanf(file, "%s %s", username, password) != EOF) {
        if (strcmp(username, input_username) == 0 && strcmp(password, input_password) == 0) {
            found = 1;
            break;
        }
    }

    fclose(file);

    if (found) {
        system("cls");
        printf("========================================\n");
        printf("Login successful! Welcome %s\n", input_username);
        
        user_menu();
    } else {
        system("cls");
        printf("========================================\n");
        printf("Incorrect username or password.\n");
        user_signin_function();  
    }
}
void after_user(){
    char choice[10];

    printf("========================================\n");
    printf("Do you want to SIGN OUT (yes/no): ");
    scanf("%s", choice);

    if (strcmp(choice, "yes") == 0 || strcmp(choice, "Yes") == 0) {
        system("cls");
        printf("========================================\n");
        printf("Sign out mode activated\n");
        admin_user();  
        
    }
    else if (strcmp(choice, "no") == 0 || strcmp(choice, "NO") == 0) {
        system("cls");
        user_menu();     
    }
    else {
        system("cls");
        printf("========================================\n");
        printf("Invalid choice!!\n");
        after_user();
    }

}
void user_menu() {
    printf("========================================\n");
    printf("Welcome to user_menu\n");
    printf("========================================\n");
    printf("What you want to do?\n");
    printf("========================================\n");
    printf("1. Place_Order\n");
    printf("2. Table_Reservation\n");
    printf("3. Pickup_Order\n");
    printf("4. Customer_Feedback\n");
    printf("5. Exit\n");
    printf("========================================\n");
    user_menu_option();
}
void user_menu_option() {
    char choice;

    printf("Enter your choice (1-5): ");
    scanf(" %c", &choice);

    if (choice == '1') {
        place_order();
    }
    else if (choice == '2') {
        table_reservation();
    }
    else if (choice == '3') {
        pick_up_order();
    }
    else if (choice == '4') {
        feedback();
    }
    else if (choice == '5') {
        after_user();
    }
    else {
        system("cls");
        printf("========================================\n");
        printf("Invalid input! Please choose 1 to 5.\n");
        user_menu();
    }
}
void place_order() {
    char name[30], size[10], flavor[20], topping[5], want_bottle[5], bottle[20], again[5],address[30];
    int total_price = 0, pizza_quantity;

    do {
        system("cls");

        printf("========================================\n");
        printf("Welcome to place order section\n");
        printf("========================================\n");
        printf("Enter your address (without space): ");
        scanf("%s", address);
        printf("========================================\n");
        printf("Enter your name: ");
        scanf("%s", name);
        

        while (1) {
            printf("========================================\n");
            printf("Choose pizza size (small / medium / large): ");
            scanf("%s", size);
            if (strcmp(size, "small") == 0 || strcmp(size, "medium") == 0 || strcmp(size, "large") == 0)
            {    break;}
            printf("========================================\n");
            printf("Invalid size! Please try again.\n");
        }

        while (1) {
            printf("========================================\n");
            printf("Enter quantity of pizzas: ");
            if (scanf("%d", &pizza_quantity) == 1 && pizza_quantity > 0)
                break;
            printf("========================================\n");
            printf("Invalid quantity! Please enter a valid number.\n");
            while (getchar() != '\n'); 
        }

        while (1) {
            printf("========================================\n");
            printf("Enter pizza flavor (fajita / tikka / malaiboti): ");
            scanf("%s", flavor);
            if (strcmp(flavor, "fajita") == 0 || strcmp(flavor, "tikka") == 0 || strcmp(flavor, "malaiboti") == 0)
                break;
            printf("========================================\n");
            printf("Invalid flavor! Please try again.\n");
        }

        while (1) {
            printf("========================================\n");
            printf("Do you want extra topping? (yes / no): ");
            scanf("%s", topping);
            if (strcmp(topping, "yes") == 0 || strcmp(topping, "no") == 0)
                break;
            printf("========================================\n");
            printf("Invalid input! Please enter yes or no.\n");
        }

        while (1) {
            printf("========================================\n");
            printf("Do you want bottle? (yes / no): ");
            scanf("%s", want_bottle);
            if (strcmp(want_bottle, "yes") == 0 || strcmp(want_bottle, "no") == 0)
                break;
            printf("========================================\n");
            printf("Invalid input! Please enter yes or no.\n");
        }

        if (strcmp(want_bottle, "yes") == 0) {
            while (1) {
                printf("========================================\n");
                printf("Choose bottle (mint / cola / fizzup / none): ");
                scanf("%s", bottle);
                if (strcmp(bottle, "mint") == 0 || strcmp(bottle, "cola") == 0 || strcmp(bottle, "fizzup") == 0 || strcmp(bottle, "none") == 0)
                    break;
                printf("========================================\n");
                printf("Invalid bottle! Please try again.\n");
            }
        }

        if (strcmp(size, "small") == 0)
            total_price += 500 * pizza_quantity;
        else if (strcmp(size, "medium") == 0)
            total_price += 800 * pizza_quantity;
        else if (strcmp(size, "large") == 0)
            total_price += 1200 * pizza_quantity;

        if (strcmp(topping, "yes") == 0)
            total_price += 200 * pizza_quantity;

        if (strcmp(want_bottle, "yes") == 0 && strcmp(bottle, "None") != 0)
            total_price += 100;

        system("cls");
        printf("========================================\n");
        printf("Order Summary:\n");
        printf("Customer: %s\n", name);
        printf("Address: %s\n", address);
        printf("Pizza Size: %s\n", size);
        printf("Flavor: %s\n", flavor);
        printf("Quantity: %d\n", pizza_quantity);
        printf("Extra Topping: %s\n", topping);
        if (strcmp(want_bottle, "yes") == 0)
            printf("Bottle: %s\n", bottle);
        else
            printf("Bottle: None\n");
        printf("========================================\n");
        printf("Total Price: Rs. %d\n", total_price);
        printf("========================================\n");
        printf("Thank you for your order!\n");
        printf("========================================\n");

        printf("Do you want to order again? (yes / no): ");
        scanf("%s", again);

        total_price = 0;

    } while (strcmp(again, "yes") == 0 || strcmp(again, "Yes") == 0);
    system("cls");
    printf("========================================\n");
    printf("Returning to main menu...\n");
    user_menu();
}
void pick_up_order() {
    char name[30], size[10], flavor[20], topping[5], want_bottle[5], bottle[20], again[5];
    int total_price = 0, pizza_quantity;

    do {
        system("cls");
        printf("========================================\n");
        printf("Welcome to pick up order section\n");
        printf("========================================\n");
        printf("Enter your name: ");
        scanf("%s", name);

        while (1) {
            printf("========================================\n");
            printf("Choose pizza size (small / medium / large): ");
            scanf("%s", size);
            if (strcmp(size, "small") == 0 || strcmp(size, "medium") == 0 || strcmp(size, "large") == 0)
                break;
            printf("========================================\n");
            printf("Invalid size! Please try again.\n");
        }

        while (1) {
            printf("========================================\n");
            printf("Enter quantity of pizzas: ");
            if (scanf("%d", &pizza_quantity) == 1 && pizza_quantity > 0)
                break;
            printf("========================================\n");
            printf("Invalid quantity! Please enter a valid number.\n");
            while (getchar() != '\n');
        }

        while (1) {
            printf("========================================\n");
            printf("Enter pizza flavor (fajita / tikka / malaiboti): ");
            scanf("%s", flavor);
            if (strcmp(flavor, "fajita") == 0 || strcmp(flavor, "tikka") == 0 || strcmp(flavor, "malaiboti") == 0)
                break;
            printf("========================================\n");
            printf("Invalid flavor! Please try again.\n");
        }

        while (1) {
            printf("========================================\n");
            printf("Do you want extra topping? (yes / no): ");
            scanf("%s", topping);
            if (strcmp(topping, "yes") == 0 || strcmp(topping, "no") == 0)
                break;
            printf("========================================\n");
            printf("Invalid input! Please enter yes or no.\n");
        }

        while (1) {
            printf("========================================\n");
            printf("Do you want bottle? (yes / no): ");
            scanf("%s", want_bottle);
            if (strcmp(want_bottle, "yes") == 0 || strcmp(want_bottle, "no") == 0)
                break;
            printf("========================================\n");
            printf("Invalid input! Please enter yes or no.\n");
        }

        if (strcmp(want_bottle, "yes") == 0) {
            while (1) {
                printf("========================================\n");
                printf("Choose bottle (mint / cola / fizzup / none): ");
                scanf("%s", bottle);
                if (strcmp(bottle, "mint") == 0 || strcmp(bottle, "cola") == 0 || strcmp(bottle, "fizzup") == 0 || strcmp(bottle, "none") == 0)
                    break;
                printf("========================================\n");
                printf("Invalid bottle! Please try again.\n");
            }
        }

        if (strcmp(size, "small") == 0)
            total_price += 500 * pizza_quantity;
        else if (strcmp(size, "medium") == 0)
            total_price += 800 * pizza_quantity;
        else if (strcmp(size, "large") == 0)
            total_price += 1200 * pizza_quantity;

        if (strcmp(topping, "yes") == 0)
            total_price += 200 * pizza_quantity;

        if (strcmp(want_bottle, "yes") == 0 && strcmp(bottle, "none") != 0)
            total_price += 100;

        FILE *file = fopen("pickup_orders.txt", "a");
        if (file != NULL) {
            fprintf(file, "Customer: %s | Size: %s | Flavor: %s | Quantity: %d | Topping: %s | Bottle: %s | Total: Rs. %d\n", 
                    name, size, flavor, pizza_quantity, topping, 
                    (strcmp(want_bottle, "yes") == 0 ? bottle : "None"), total_price);
            fclose(file);
        }

        system("cls");
        printf("========================================\n");
        printf("Order Summary:\n");
        printf("Customer: %s\n", name);
        printf("Pizza Size: %s\n", size);
        printf("Flavor: %s\n", flavor);
        printf("Quantity: %d\n", pizza_quantity);
        printf("Extra Topping: %s\n", topping);
        if (strcmp(want_bottle, "yes") == 0)
            printf("Bottle: %s\n", bottle);
        else
            printf("Bottle: None\n");
        printf("========================================\n");
        printf("Total Price: Rs. %d\n", total_price);
        printf("========================================\n");
        printf("Thank you for your order!\n");
        printf("========================================\n");

        printf("Do you want to order again? (yes / no): ");
        scanf("%s", again);

        total_price = 0;

    } while (strcmp(again, "yes") == 0 || strcmp(again, "Yes") == 0);
    system("cls");
    printf("========================================\n");
    printf("Returning to main menu...\n");
    user_menu();
}
void table_reservation() {
    char name[30];
    int people;
    char table_type[10];
    char confirm[5],again[5];

    FILE *file = fopen("reservations.txt", "a");
    if (file == NULL) {
        printf("========================================\n");
        printf("Error opening reservation file!\n");
        return;
    }

    system("cls");
    printf("========================================\n");
    printf("Welcome to table reservation section\n");
    printf("========================================\n");
    printf("Enter your name: ");
    scanf("%s", name);

    while (1) {
        printf("========================================\n");
        printf("Enter number of people: ");
        if (scanf("%d", &people) == 1 && people > 0) break;
        printf("========================================\n");
        printf("Invalid input! Please enter a number.\n");
        while (getchar() != '\n');
    }

    while (1) {
        printf("========================================\n");
        printf("Choose table type (vip / normal): ");
        scanf("%s", table_type);
        if (strcmp(table_type, "vip") == 0 || strcmp(table_type, "normal") == 0) break;
        printf("========================================\n");
        printf("Invalid table type! Please try again.\n");
    }

    system("cls");
    printf("========================================\n");
    printf("Reservation Summary:\n");
    printf("Name: %s\n", name);
    printf("Number of People: %d\n", people);
    printf("Table Type: %s\n", table_type);
    printf("========================================\n");
    printf("Thank you! Your reservation is confirmed.\n");
    printf("========================================\n");

    fprintf(file, "Name: %s | People: %d | Table Type: %s\n", name, people, table_type);
    fclose(file);
    printf("Do you want another reservation? (yes / no): ");
    scanf("%s", again);
    if (strcmp(again, "yes") == 0 || strcmp(again, "Yes") == 0)
    {
        table_reservation();
    }
    else if (strcmp(again, "no") == 0 || strcmp(again, "No") == 0)
    {
        system("cls");
        printf("========================================\n");
        printf("Returning to main menu...\n");
        user_menu();
    }
    else {
        system("cls");
        printf("========================================\n");
        printf("Invalid option\n");
        printf("========================================\n");
        printf("Returning to main menu...\n");
        user_menu();
    }
    
    
}
void feedback() {
    char name[30],again[5];
    char feedback_text[500];
    FILE *file;

    system("cls");
    printf("========================================\n");
    printf("Feedback Section\n");
    printf("========================================\n");
    printf("Enter your name: ");
    scanf("%s", name);
    printf("========================================\n");
    printf("Write your feedback below:\n");
    getchar(); 
    fgets(feedback_text, sizeof(feedback_text), stdin);

    file = fopen("feedback.txt", "a");
    if (file == NULL) {
        printf("Error opening feedback file!\n");
        return;
    }

    fprintf(file, "Name: %s\nFeedback: %s\n--------------------------\n", name, feedback_text);
    fclose(file);

    printf("========================================\n");
    printf("Thank you for your feedback!\n");
    printf("========================================\n");
    printf("Your response has been saved.\n");
    printf("========================================\n");
    printf("Do you want to give another feedback? (yes / no): ");
    scanf("%s", again);
    if (strcmp(again, "yes") == 0 || strcmp(again, "Yes") == 0)
    {
        feedback();
    }
    else if (strcmp(again, "no") == 0 || strcmp(again, "No") == 0)
    {
        system("cls");
        printf("========================================\n");
        printf("Returning to main menu...\n");
        user_menu();
    }
    else {
        system("cls");
        printf("========================================\n");
        printf("Invalid option\n");
        printf("========================================\n");
        printf("Returning to main menu...\n");
        user_menu();
    }
    
}
