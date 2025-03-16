#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <cs50.h>

// Define Scrabble letter values
int letter_values[] = {
    1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3,
    1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10
};

// Function to compute score
int compute_score(char word[]) {
    int score = 0;
    for (int i = 0; i < strlen(word); i++) {
        if (isalpha(word[i])) { // Ensure it's a letter
            char upper = toupper(word[i]); // Convert to uppercase
            score += letter_values[upper - 'A']; // Get corresponding value
        }
    }
    return score;
}

int main() {
    // Prompt players for input
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Calculate scores
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Determine the winner
    if (score1 > score2) {
        printf("Player 1 wins!\n");
    } else if (score2 > score1) {
        printf("Player 2 wins!\n");
    } else {
        printf("Tie!\n");
    }

    return 0;
}
