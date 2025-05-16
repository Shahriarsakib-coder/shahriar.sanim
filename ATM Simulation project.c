#include <stdio.h>

int main() {
    int pin, enteredPin;
    int attempts = 0;
    float balance = 1000.0;
    int choice;
    float amount;

    pin = 1234;
    printf("Welcome to the ATM Simulator\n");


    while (attempts < 3) {
        printf("Enter your PIN: ");
        scanf("%d", &enteredPin);

        if (enteredPin == pin) {
            break;
        } else {
            attempts++;
            printf("Incorrect PIN. Try again.\n");
        }

        if (attempts == 3) {
            printf("Too many wrong attempts. Exiting...\n");
            return 0;
        }
    }


    do {
        printf("\n------ ATM Menu ------\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Your current balance is: %.2f\n", balance);
                break;

            case 2:
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                if (amount > 0) {
                    balance += amount;
                    printf("Deposit successful! New balance: %.2f\n", balance);
                } else {
                    printf("Invalid amount.\n");
                }
                break;

            case 3:
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                if (amount > 0 && amount <= balance) {
                    balance -= amount;
                    printf("Withdrawal successful! New balance: %.2f\n", balance);
                } else {
                    printf("Invalid or insufficient funds.\n");
                }
                break;

            case 4:
                printf("Thank you for using the ATM. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while(choice != 4);

return 0;
}
