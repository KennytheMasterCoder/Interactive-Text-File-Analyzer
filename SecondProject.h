#define MAXWORDLEN 20 // max number of characters for a word in wordLen array
#define ALPHABETMAX 26 // max number of characters for alphabet


int processFile(FILE* file, int wordLen[], int alphabetCount[], int repeatedLetters[], 
                int c, int pFlag, int nFlag, int* punCount, int* numCount, int* wordCount);