#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main (int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: ./tests nStudents nTests");
        return 1;
    }
    
    //get number of students
    int nStudents = atoi(argv[1]);

    //get number of tests
    int nTests = atoi(argv[2]);
    
    char names[nStudents][16];
    int testScores[nStudents][nTests];
    int averageScores[nStudents];
    //prompt for each test score for each student from user
    for (int i = 0; i < nStudents; i++)
    {
        int totalScore = 0;
        printf("Name of student %i\n", i + 1);
        scanf("%s", names[i]);
        
        char *rights = malloc(sizeof(char) * 3);
        char *right = rights;
        for (int j = 0; j < nTests; j++)
        {
            printf("Test score %i\n", j + 1);
            scanf("%i", &testScores[i][j]);

            totalScore += testScores[i][j];
        }
        //print average score after all test scores are entered,
        printf("Average score: %i\n", totalScore / nTests);
        printf("Does this look right to you?\n");
        int tempC = 0;
        do
        {
            if ((strcmp (rights, "no") != 0 || strcmp(rights, "yes") != 0) && tempC > 0)
            {
                printf("Enter yes or no!\n");
            }
            scanf("%s", rights);
            tempC++;
            
        } while(strcmp (rights, "no") != 0 && strcmp(rights, "yes") != 0);
        if (strcmp(rights, "no") == 0)
        {
            i--;
            continue;
        }
        averageScores[i] = totalScore / nTests;
    }
    printf("\n\n");
    //print average score aat the end of all students
    for (int i = 0; i < nStudents; i++)
    {
        printf("Name: %s\n", names[i]);
        printf("Average Score: %i\n", averageScores[i]);
    }
    
    
    //exit
    
    
    
}