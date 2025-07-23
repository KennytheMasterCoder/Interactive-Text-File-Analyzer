# Interactive Command-Line Text File Processor

A C-based, interactive, menu-driven file analyzer that processes large text files and computes detailed statistics about their contents. <br>
Designed with a modular structure and flexible runtime options, the program supports configurable features such as punctuation filtering, number counting, and adjacent repeated letter detection. <br>
It demonstrates structured input handling, modular programming practices, and clean terminal-based CLI design for real-time file analysis.

## Project Structure
```
SecondProject.c      # command line interface + menu logic
ProcessFile.c        # file reading + character analysis
SecondProject.h      # constants and function signatures
Makefile             # to compile easier
MobyDick.txt         # sample larger input file to test
input.txt            # alternate smaller input file to test
```

## Features 

- Interactive command-line menu with 9 selectable runtime options
- Processes any `.txt` file (tested on 200,000+ word files like *Moby Dick*)
- Tracks:
  - Total word count
  - Number of words by length (1–20+ characters)
  - Number of words that start with each letter (A–Z)
  - Total punctuation characters (`-p` flag)
  - Total digit characters (`-n` flag)
  - Adjacent repeated letter patterns (e.g. “letter” → `T`)
- Supports multi-file sessions: you can analyze another file WITHOUT restarting the program
- Modular design: separates logic into `SecondProject.c`, `ProcessFile.c`, and `SecondProject.h`
- Clean resets of counters (word, digit, punctuation) between runs

<br>

## Sample Output
```
$ make
$ ./processMake

Enter in file name to perform functionalities of your choosing: 
MobyDick.txt
Typed in MobyDick.txt file 
Current file name: MobyDick.txt 
File exists. Please choose an option below. 

Please enter a number, 1 to 5: 
1. Change filename to process.
2. Set -p flag to ignore punctuation.
3. Set -n flag to count numbers.
4. Process file.
5. Display Options 1-4 again.
6. Exit program completely.

> 3
-n flag enabled to count numbers. 
Choose Option 4 to process the file. 

Please enter a number, 1 to 5: 
1. Change filename to process.
2. Set -p flag to ignore punctuation.
...
6. Exit program completely.

> 4
Processing file... 

File name processed. 
Please choose an option below: 
Please enter a number, 1 to 8 

1. Display word count. 
2. Display starting letter counts. 
3. Display word length counts. 
4. Display number counts. 
5. Display punctuation count. 
6. Number of repeated letters. 
7. Process another file. 
8. Display Options 1-8 again. 
9. Exit completely out of program. 

> 6
Printing all repeated letters that are adjacent: 
Number count of repeated letters for letter A: 5
Number count of repeated letters for letter B: 420
...
Number count of repeated letters for letter Z: 43
Please choose an option below: 
Please enter a number, 1 to 8 

1. Display word count. 
2. Display starting letter counts. 
...
9. Exit completely out of program. 

> 7
Processing another file: 

 
Enter in file name to perform functionalities of your choosing: 
input.txt
Typed in input.txt file 
Current file name: input.txt 
File exists. Please choose an option below. 

Please enter a number, 1 to 5: 
1. Change filename to process.
2. Set -p flag to ignore punctuation.
...
6. Exit program completely.

2
-p flag enabled to ignore punctuation. 
Choose Option 4 to process the file. 

Please enter a number, 1 to 5: 
1. Change filename to process.
2. Set -p flag to ignore punctuation.
...
6. Exit program completely.

> 4
Processing file... 

File name processed. 
Please choose an option below: 
Please enter a number, 1 to 8 

1. Display word count. 
2. Display starting letter counts. 
3. Display word length counts. 
4. Display number counts. 
5. Display punctuation count. 
6. Number of repeated letters. 
7. Process another file. 
8. Display Options 1-8 again. 
9. Exit completely out of program. 

> 4
Total number of digits: 777 
Reset number of digits to zero, reprocess again. 
Please choose an option below: 
Please enter a number, 1 to 8 

1. Display word count. 
2. Display starting letter counts. 
...
9. Exit completely out of program. 

> 9
Exiting program.
```

<br>

## How to Compile and Run
1. Compile using Makefile: `make`

OR manually:

`gcc -o processMake SecondProject.c ProcessFile.c`

2. Run: ```./processMake```

Then follow the command line prompts to:
- load a `.txt` file
- enable/disable flags
- display analysis results

<br>

## How It Works

The program is structured as an interactive, menu-driven loop that allows users to analyze large text files with flexible configurations. Here is how it works:

1. **User Input (Interactive Command Line Interface)**
   - Prompts the user to enter a valid filename.
   - Displays a runtime menu (Options 1–6) to:
     - Set flags to set flags: punctuation (`-p`) and number (`-n`) 
     - Change or reprocess files
     - Exit the program

2. **File Processing via `processFile() function`**
   - Reads characters one-by-one from the file using `fgetc()`.
   - Tracks the following:
     - Total word count
     - Word lengths (up to 20+ characters, into `wordLen[]`)
     - First letters of words (A–Z), into `alphabetCount[]`
     - Number of repeated letters (`repeatedLetters[]`)
     - Punctuation (`-p` flag)
     - Digit frequency (`-n` flag)

3. **Runtime Reporting**
   - After processing, users can choose from 9 output options:
     - Query specific letter counts, word lengths, total digits, or punctuation
     - View repeated letters
     - Process a new file without restarting


<br>


## Design Notes

- **Modular File Structure**
  - `SecondProject.c` – user interface, menu flow, control logic
  - `ProcessFile.c` – handles file parsing and character-level analysis
  - `SecondProject.h` – stores shared constants and function declarations

- **Fixed-Size Arrays for Simplicity**
  - Uses pre-defined arrays for word length, alphabet counts, repeated letters,...
  - Avoids dynamic memory allocation and handles EOF gracefully

- **Interactive Flexibility**
  - All flags (`-p`, `-n`) and filenames are managed during runtime
  - Users can switch files and view stats without restarting or recompiling

<br>


## About This Project

This was built as a **second iteration** of a previous word analysis program written in C. It introduces:
- A cleaner user experience by a command line interface menu
- Support for runtime toggling of features
- Expanded functionality (repeated letters, file swapping)
- Stronger error-checking and modularity

<br>

## 💡 Ideas for Future Improvement

- Add histogram/graph to visualize word or letter distributions
- Export analysis results to `.csv` or `.json` files
- Refactor to use `structs` or dynamic memory for more extensibility
