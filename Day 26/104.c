#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Structure to hold a quiz question
typedef struct {
    char question[256];
    char options[4][128];
    char correctOption; // 'A', 'B', 'C', or 'D'
} QuizQuestion;

// Function to trim newline from fgets input
void trimNewline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

// Function to run the quiz
void runQuiz(QuizQuestion quiz[], int totalQuestions) {
    int score = 0;
    char answer[10];

    printf("\n===== Welcome to the Quiz =====\n");
    for (int i = 0; i < totalQuestions; i++) {
        printf("\nQ%d: %s\n", i + 1, quiz[i].question);
        printf("A. %s\n", quiz[i].options[0]);
        printf("B. %s\n", quiz[i].options[1]);
        printf("C. %s\n", quiz[i].options[2]);
        printf("D. %s\n", quiz[i].options[3]);

        // Input validation loop
        while (1) {
            printf("Your answer (A/B/C/D): ");
            if (fgets(answer, sizeof(answer), stdin) == NULL) {
                printf("Error reading input. Try again.\n");
                continue;
            }
            trimNewline(answer);

            if (strlen(answer) == 1 && strchr("ABCDabcd", answer[0])) {
                break; // valid input
            } else {
                printf("Invalid choice. Please enter A, B, C, or D.\n");
            }
        }

        // Convert to uppercase for comparison
        char userChoice = toupper(answer[0]);
        if (userChoice == quiz[i].correctOption) {
            printf("✅ Correct!\n");
            score++;
        } else {
            printf("❌ Wrong! Correct answer: %c\n", quiz[i].correctOption);
        }
    }

    printf("\n===== Quiz Finished =====\n");
    printf("Your Score: %d / %d\n", score, totalQuestions);
}

int main() {
    // Define quiz questions
    QuizQuestion quiz[] = {
        {
            "What is the capital of India?",
            {"New Delhi", "Mumbai", "Kolkata", "Chennai"},
            'A'
        },
        {
            "Which language is used to write operating systems like Linux?",
            {"Python", "C", "Java", "Ruby"},
            'B'
        },
        {
            "Which planet is known as the Red Planet?",
            {"Earth", "Mars", "Jupiter", "Saturn"},
            'B'
        },
        {
            "What is the value of Pi (approx)?",
            {"2.14", "3.14", "4.13", "3.41"},
            'B'
        }
    };

    int totalQuestions = sizeof(quiz) / sizeof(quiz[0]);
    runQuiz(quiz, totalQuestions);

    return 0;
}
