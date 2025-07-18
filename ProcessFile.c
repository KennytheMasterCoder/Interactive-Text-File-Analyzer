#include <stdio.h>
#include "SecondProject.h"

int processFile(FILE* file, int wordLen[], int alphabetCount[], int repeatedLetters[], 
                int c, int pFlag, int nFlag, int* punCount, int* numCount, int* wordCount) {

    // initializing all arrays
    for(int i = 0; i <= MAXWORDLEN; i++) {
        wordLen[i] = 0; // initializing wordLen array to all zeros
    }
    for(int i = 0; i < ALPHABETMAX; i++) {
        alphabetCount[i] = 0; // initializing alphabetCount array to all zeros
    }
    for(int i = 0; i < ALPHABETMAX; i++) {
        repeatedLetters[i] = 0; // initializing repeatedLetters array to all zeros
    }

    char prevChar = '#';
    char currChar;
    int currLen = 0; // current word length

    // • Loop over our input file (character by character)
    while((c = fgetc(file)) != EOF) {
        currChar = c;
        
        // // Checking if currChar and prevChar are letters AND equal to each other
        // for uppercase letters
        if((currChar == prevChar) && ((currChar >= 'A') && (currChar <= 'Z'))) {
            repeatedLetters[currChar - 'A']++;
        // for lowercase letters
        } else if((currChar == prevChar) && ((currChar >= 'a') && (currChar <= 'z'))) {
            repeatedLetters[currChar - 'a']++;
        }
        // update previous character equal to the current character
        prevChar = currChar;
        
        // finished word indicators
        if((currChar == ' ') || (currChar == '\n') || (currChar == '\t')) {
            // just ended a word
            if(currLen > 0) {
                // check if word is longer than 20 characters
                if(currLen <= MAXWORDLEN) {
                    // store size of word in wordLen array
                    wordLen[currLen]++;
                }
                // word is longer than 20 characters 
                else {
                    // Increment overFlow count by 1 at index 0
                    wordLen[0]++;
                }
                // reset wordLen array back to index 0 to reuse
                currLen = 0;   
            }
            // else if currLen = 0, nothing happens b/c 
            // that means there is more whitespace

        } // end of "big" if branch

        // beginning of a new word, assuming it is a character
        else {
            // checking the punctuation flag and punctuation
            if((pFlag == 0) && (((currChar >= 33) && (currChar <= 47)) || ((currChar >= 58) && (currChar <= 64)))) {
                (*punCount)++;
                continue;  
            // checking the number flag and if the current character is a number
            } else if((nFlag == 1) && (currChar >= '0' && currChar <= '9')) {
                (*numCount)++;
                continue;
            }

            // already inside a word
            if(currLen > 0) {
                if((pFlag == 0) && (((currChar >= 33) && (currChar <= 47)) || ((currChar >= 58) && (currChar <= 64)))) {
                    (*punCount)++;
                    continue;  
                } else if((nFlag == 1) && (currChar >= '0' && currChar <= '9')) {
                    (*numCount)++;
                    continue;
                }
                currLen++;
            }
            // store starting letter in alphabetCount array
            // currLen = 0
            else {

                (*wordCount)++; // increment word count

                if((pFlag == 0) && (((currChar >= 33) && (currChar <= 47)) || ((currChar >= 58) && (currChar <= 64)))) {
                    (*punCount)++;
                    continue;  
                } else if((nFlag == 1) && (currChar >= '0' && currChar <= '9')) {
                    //numDigit[currChar - '0']++;
                    (*numCount)++;
                    continue;
                }
                // Number of words that start with each letter of the alphabet
                // Check if starting letter is capital case or lower case
                if((currChar >= 'A') && (currChar <= 'Z')) {
                    alphabetCount[currChar - 'A']++;
                } else {
                    alphabetCount[currChar - 'a']++;
                }
                currLen++; 
            }
        } // end of "big" else branch
        
    } // end of while loop

    // When file hits EOF and doesn't store the last word
    if(currLen > 0) {
        // store size of last word in wordLen array
        // check if word is longer than 20 characters
            if(currLen <= MAXWORDLEN) {
                // store size of word in wordLen array
                wordLen[currLen]++;
            }
            // word is longer than 20 characters 
            else {
                // Increment overFlow count by 1 at index 0
                wordLen[0]++;
            }
    }
    return 1; // processed file successfully
}