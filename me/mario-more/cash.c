#include <stdio.h>

int main(void)
{
    int cents;

    // Prompt user for valid input (cents > 0)
    do
    {
        printf("Change owed: ");
        scanf("%d", &cents);
    }
    while (cents <= 0);

    int coins = 0;

    // quarters (25 cents)
    coins += cents / 25;
    cents %= 25;

    // dimes (10 cents)
    coins += cents / 10;
    cents %= 10;

    // nickels (5 cents)
    coins += cents / 5;
    cents %= 5;

    // pennies (1 cent)
    coins += cents / 1;
    cents %= 1;

    // total number of coins needed
    printf("%d\n", coins);

    return 0;
}
