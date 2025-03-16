#include <stdio.h>

int main(void)
{
    int height;

    // Prompt user for height (1-8 range)
    do
    {
        printf("Height: ");
        scanf("%d", &height);
    }
    while (height < 1 || height > 8);

    // Loop to print pyramids
    for (int i = 1; i <= height; i++)
    {
        for (int j = 0; j < height - i; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < i; k++)
        {
            printf("#");
        }
        // Print gap
        printf("  ");
        for (int k = 0; k < i; k++)
        {
            printf("#");
        }
        // Move to the next line
        printf("\n");
    }
}
