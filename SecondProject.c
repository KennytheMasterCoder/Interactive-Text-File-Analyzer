#include <stdio.h>
#include <stdlib.h>
#include "SecondProject.h"

int main(int argc, char** argv) {

    char fileName[100];
    int flag = 0; // flag is false
    int pFlag = 0; // punctuation flag, pFlag is false
    int nFlag = 0; // number flag, nFlag is false
    int num = 0;
    FILE* file;

    // processing the file
    int c;
    int wordLen[MAXWORDLEN];
    int alphabetCount[ALPHABETMAX];
    int repeatedLetters[ALPHABETMAX];
    
    int wordCount = 0; // to count total number of words
    int numCount = 0; // to count total number of numbers
    int punCount = 0; // to count total number of punctuation characters
    
    
    while(!flag) {
        printf("\nEnter in file name to perform functionalities of your choosing: \n");
        scanf("%s", fileName);
        
        // open the file 
        // if the file is available
        if((file = fopen(fileName, "r")) != NULL) {
            flag = 1; // file is available
            printf("Typed in %s file \n", fileName);
            printf("Current file name: %s \n", fileName);
            printf("File exists. Please choose an option below. \n\n");
        } 
        // if the file is not available
        else {
            printf("Typed in %s file \n", fileName);
            // Ask for the file name again until the file name is spelled correctly
            printf("File Name Incorrect. Try again. \n");
            continue;
        }

        
        while(flag) {
            printf("Please enter a number, 1 to 5: \n");
            printf("1. Change filename to process.\n");
            printf("2. Set -p flag to ignore punctuation.\n");
            printf("3. Set -n flag to count numbers.\n");
            printf("4. Process file.\n");
            printf("5. Display Options 1-4 again.\n");
            printf("6. Exit program completely.\n\n");
            
            scanf("%d", &num);

            // changing the filename
            if(num == 1) {
                flag = 0;
                printf("Now changing the filename. \n");
                printf("Choose Option 4 to process the file. \n\n");
                break;
            // setting the -p flag to true
            } else if(num == 2) {
                pFlag = 1;
                printf("-p flag enabled to ignore punctuation. \n");
                printf("Choose Option 4 to process the file. \n\n");
                continue;
            // setting -n flag to true
            } else if(num == 3) {
                nFlag = 1;
                printf("-n flag enabled to count numbers. \n");
                printf("Choose Option 4 to process the file. \n\n");
                continue;
            // processing file
            } else if(num == 4) {
                printf("Processing file... \n\n");
                break;
            // display options again
            } else if(num == 5) {
                printf("Exiting. Displaying options 1 to 5 again. \n");
                printf("Choose Option 4 to process the file. \n\n");
                continue;
            // exit
            } else if(num == 6) {
                printf("Exiting completely out of program. \n\n");
                return EXIT_SUCCESS;
            // if user chooses a different option that is not there
            } else {
                printf("Incorrect input. Please enter a number between 1 to 6 \n");
                printf("Choose Option 4 to process the file. \n\n");
                continue;
            }
        } // end of little while loop

        // code for processing file for Option #4
        if(num == 4) {

            // Checking that the file processed successfully
            if(!processFile(file, wordLen, alphabetCount, repeatedLetters, 
                            c, pFlag, nFlag, &punCount, &numCount, &wordCount)) {
                printf("Unable to process the file. Exiting out of the program. \n");
                return 0;
            }
            // for Option #4 variables
            int lflag = 1;
            int number = 0;
            int optionNumber = 0;
            char letter;
            int digit = 0;

            printf("File name processed. \n");
                
            while(lflag == 1) {
                printf("Please choose an option below: \n");
                printf("Please enter a number, 1 to 8 \n\n");

                printf("1. Display word count. \n");
                printf("2. Display starting letter counts. \n");
                printf("3. Display word length counts. \n");
                printf("4. Display number counts. \n");
                printf("5. Display punctuation count. \n");
                printf("6. Number of repeated letters. \n");
                printf("7. Process another file. \n");
                printf("8. Display Options 1-8 again. \n");
                printf("9. Exit completely out of program. \n\n");

                scanf("%d", &number);
            
                // word count
                if(number == 1) {
                    printf("Word Count for text file: %d \n", wordCount);
                    wordCount = 0;
                    printf("Reset word count to zero, reprocess again. \n");
                    continue;

                // starting letter counts
                } else if(number == 2) {
                    printf("Please choose an option below, 1 or 2 \n\n");
                    printf("1. Display a certain letter count. \n");
                    printf("2. Display all letter counts. \n\n");

                    scanf("%d", &optionNumber);
                    if(optionNumber == 1) {
                        printf("Which single letter would you like to see the count of? \n");
                        scanf(" %c", &letter);
                        // just in case user enters in either capital or lowercase letter
                        if((letter >= 'A') && (letter <= 'Z')) {
                            printf("Number of words that start with %c: %d \n", letter, alphabetCount[letter - 'A']);
                        } else if((letter >= 'a') && (letter <= 'z')) {
                            printf("Number of words that start with %c: %d \n", letter, alphabetCount[letter - 'a']);
                        } else {
                            printf("Character %c is not a letter \n", letter);
                        }
                    } else if(optionNumber == 2) {
                        printf("Printing all letter counts: \n");
                        for(int i = 0; i < ALPHABETMAX; i++) {
                            printf("Number of words that start with %c: %d \n", i + 'A', alphabetCount[i]);   
                        }
                    // if user did not enter in 1 or 2
                    } else {
                        printf("Did not enter in 1 or 2 as options. Try again. \n");
                    }
                    // continue;

                // word length counts
                } else if(number == 3) {
                    printf("Please choose an option below, 1 or 2 \n\n");
                    printf("1. Display a certain letter length. \n");
                    printf("2. Display all word length counts. \n\n");
                    
                    scanf("%d", &optionNumber);

                    if(optionNumber == 1) {
                        printf("How many number of words would you like to see that have ___ characters? \n");
                        scanf("%d", &digit);
                        printf("Number of words that have %d characters: %d \n", digit, wordLen[digit]); 
                    } else if(optionNumber == 2) {
                        printf("Printing all size counts: \n");
                        for(int i = 1; i <= MAXWORDLEN; i++) {
                            printf("Number of words that have %d character(s) in them: %d \n", i, wordLen[i]);
                        }
                    // if user did not enter in a number
                    } else {
                        printf("Did not enter in 1 or 2 as options. Try again. \n");
                    }
                    continue;

                // number counts
                } else if(number == 4) {
                    printf("Total number of digits: %d \n", numCount);
                    numCount = 0;
                    printf("Reset number of digits to zero, reprocess again. \n");
                    continue;
                // punctuation counts
                } else if(number == 5) {
                    printf("Total number of punctuation characters: %d \n", punCount);
                    punCount = 0;
                    printf("Reset number of punctuation characters to zero, reprocess again. \n");
                    continue;
                // repeated letters
                } else if(number == 6) {
                    printf("Printing all repeated letters that are adjacent: \n");
                    for(int i = 0; i < ALPHABETMAX; i++) {
                        printf("Number count of repeated letters for letter %c: %d\n", i + 'A', repeatedLetters[i]);
                    }
                    continue;
                // processing another file.
                } else if(number == 7) {
                    flag = 0;
                    printf("Processing another file: \n\n ");
                    break;
                // exit
                } else if(number == 8) {
                    printf("Displaying options 1 to 8 again. \n");
                    continue;
                // exit
                } else if(number == 9) {
                    printf("Exiting program. \n\n");
                    return EXIT_SUCCESS;
                // if user chooses a different option that is not there
                } else {
                    printf("Incorrect input. Please enter a number between 1 to 9 \n");
                    continue;
                }
            } // end of little while loop


        } // end of 'if' check
    
     

    } // end of big while loop
    

    fclose(file);
    return 0;
}