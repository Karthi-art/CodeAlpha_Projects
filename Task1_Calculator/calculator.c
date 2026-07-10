#include <stdio.h>

int main() {
    float num1, num2, result;
    char operation;
    char choice;
    
    do {
        printf("\n===== Simple Calculator =====\n");
        
        printf("Enter first number: ");
        scanf("%f", &num1);
        
        printf("Enter operation (+, -, *, /): ");
        scanf(" %c", &operation);
        
        printf("Enter second number: ");
        scanf("%f", &num2);
        
        switch(operation) {
            case '+':
                result = num1 + num2;
                printf("%.2f + %.2f = %.2f\n", num1, num2, result);
                break;
            case '-':
                result = num1 - num2;
                printf("%.2f - %.2f = %.2f\n", num1, num2, result);
                break;
            case '*':
                result = num1 * num2;
                printf("%.2f * %.2f = %.2f\n", num1, num2, result);
                break;
            case '/':
                if(num2 == 0)
                    printf("Error: Cannot divide by zero!\n");
                else {
                    result = num1 / num2;
                    printf("%.2f / %.2f = %.2f\n", num1, num2, result);
                }
                break;
            default:
                printf("Invalid operation!\n");
        }
        
        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &choice);
        
    } while(choice == 'y' || choice == 'Y');
    
    printf("Thank you for using Calculator!\n");
    return 0;
}
