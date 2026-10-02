/*NAME: SHAIK SHABEENA
REGISTRATION NO: 25048_004

DESCRIPTION:
    This project implements an inverted search engine that reads multiple text files, extracts words, stores them in a
hash table, and allows the user to:
 ->Create a database
 ->Display the database
 ->Search for any word
 ->Save the database to a file
 ->Update the database with new files
The project uses linked lists + hashing to efficiently store and retrieve word occurrences.
Below is the simple description of what we are doing in each file.

                                 //main.c
1. This file controls the entire project and acts as the main driver.
2. It first reads all file names given by the user through command‑line arguments.
3. Each file is sent for validation to check if it is a proper .txt file, exists, has content, and is not duplicate.
4. All valid files are stored in a linked list.
5. A hash table with 27 indexes is created to store the inverted index.
6. A menu is displayed to the user with options like create, display, search, save, and update database.
7. Based on the user’s choice, the corresponding function is called.
8. It prevents creating or updating the database more than once.
9. All user interaction and project flow happens through this file.

                              //main.h
1. This header file contains all structure definitions used in the project.
2. It defines the fileNode, mainNode, subNode, and hash table structures.
3. It contains color codes for formatted output.
4. It stores constants like SUCCESS, FAILURE, and DUPLICATE.
5. It declares all functions used across different files.
6. It acts as the central header for the entire project.

                           //validations.c
* This file checks whether the input file is suitable for processing.
* It verifies if the file has a .txt extension.
* It checks whether the file exists in the system.
* It ensures the file is not empty.
* It checks whether the file is already inserted to avoid duplicates.
* If all checks pass, the file is inserted into a linked list.
* After insertion, the updated list of files is printed.
* This file ensures only valid, readable, non‑duplicate files enter the project.

                        hash_table function()
* This function initializes the hash table used for storing the inverted index.
* It creates 27 buckets:
    -> 0–25 for words starting with A–Z.
    -> 26 for words starting with digits or special characters
* Each bucket is set to NULL.
* This file prepares the basic structure where all words will be stored later.

                            //create_database.c
* This file reads each file from the linked list word‑by‑word.
* For every word, it calculates the hash index based on the first character.
* If the bucket is empty, it creates a new main node and a subnode for that file.
* If the bucket already contains words, it checks whether the word already exists.
* If the word exists in the same file, its count is increased.
* If the word exists in a different file, a new subnode is added.
* If the word does not exist at all, a new main node is created.
* This file builds the complete inverted index linking words to the files in which they appear.

                        //display_database.c
* This file prints the entire inverted index in a neat table format.
* It shows the index, word, number of files containing the word, and total occurrences.
* It prints all filenames where the word appears.
* It prints how many times the word appears in each file.
* This file helps the user clearly understand how words are distributed across files.

                        //search_database.c
* This file allows the user to search for any word in the database.
* It calculates the hash index from the first letter of the word.
* It checks the corresponding bucket for the word.
* If the word is found, it prints the number of files containing the word and the count in each file.
* If the word is not found, it prints an error message.
* This file provides fast searching using hashing.

                        //save_database.c
* This file saves the entire inverted index into a .txt file.
* It writes the index, word, file count, total word count, filenames, and individual counts.
* The saved file can be used later for updating the database.
* It ensures the database is stored permanently.
* It prints success or error messages based on file operations.

                        //update_database.c
* This file updates the existing database using a previously saved database file.
* It reads the saved database and extracts all filenames already present.
* Those filenames are removed from the linked list, leaving only new files.
* Only the remaining new files are processed again to create new database entries.
* These new entries are merged with the existing database.
* This allows the database to grow without losing old data.
* It ensures only new files are processed during update.

                    // about .txt files
* The .txt files are the input files for the entire project.
* Each .txt file contains normal text written by the user (words, sentences, etc.).
* Our project reads these .txt files word‑by‑word.
* Every word from these files is stored inside the hash table.
* For each word, we also store:
  - which file it came from
  - how many times it appears in that file
* These .txt files help us build the inverted index, which is the main goal of the project.
* When the user searches for a word, the project checks the hash table and tells:
  - in which .txt files the word is present
  - how many times it appears in each file
* When saving the database, the information extracted from .txt files is written into a single database file.
* During updating, the project reads the old database and removes .txt files that are already processed, so only new .txt 
  files are scanned again.
* Without .txt files, the project has no data to build the inverted index — they are the foundation of the entire project.



*/#include<stdio.h>
#include "main.h"

int main(int argc,char *argv[])
{

    if(argc < 2)
    {
        printf(RED "ERROR: File usage should be ./a.out <file1name> file2name>.....<filenname>\n"RESET);
        return 0;
    }
    fileNode_t *head=NULL;
    for(int i=1;i<argc;i++)
    {
        int ret=validate_and_insert(&head,argv[i]);
        {
            if(ret==SUCCESS)
            {
                printf(GREEN "Validation success for %s\n"RESET,argv[i]);
            
                printf(GREEN "insertion of %s is done\n"RESET,argv[i]);
                print_file(head);
                
            }
            else if(ret==FAILURE)
            {
                printf(RED "validation failed for %s\n"RESET,argv[i]);
                return 0;
            }
            else if(ret==DUPLICATE)
            {
                printf(RED"Duplicate file is skipped: %s\n"RESET,argv[i]);
            }
        }
    }


    hash_t arr[27];
    hash_table(arr);

    int created=0;
    int updated=0;
    int choice;
    while(1)
    {
        printf(CYAN "=====================================MENU===================================\n"RESET);
        printf(YELLOW "1. Create Database\n"RESET);
        printf(YELLOW "2. Display Database\n"RESET);
        printf(YELLOW "3.Search Word\n"RESET);
        printf(YELLOW "4. Save Database\n"RESET);
        printf(YELLOW "5. Update Database\n"RESET);
        printf(YELLOW "6. Exit\n");
        printf(CYAN "===========================================================================\n"RESET);
        scanf("%d",&choice);

        switch(choice)
        {
            int ret;
            case 1:
                if(created==1)
                {
                    printf(RED "ERROR: DATABASE IS ALREADY CREATED. CAN'T CREATE AGAIN\n"RESET);
                    break;

                }
                
                ret=create_database(arr,&head);
                if(ret==SUCCESS)
                {
                    printf(GREEN "INFO : DATABASE IS CREATED SUCCESSFULLY\n"RESET);
                    created=1;
                }
                else 
                {
                    printf(RED "ERROR : CREATION OF DATABASE IS FAILED\n"RESET);
                }
            break;

            case 2:
                
                ret=display_database(arr);
                if(ret==SUCCESS)
                {
                    printf(GREEN "SUCCESS : DATABASE IS DISPLAYED SUCCESSFULLY\n"RESET);
                }
                else
                {
                    printf(RED"ERROR : DISPLAY DATABASE IS FAILED\n"RESET);
                }
            break;

            case 3:
                
                search_database(arr);
            break;

            case 4:
                
                ret=save_database(arr);
                if(ret==SUCCESS)
                {
                    printf(GREEN "INFO : DATABASE IS SAVED SUCCESSFULLY\n"RESET);
                }
                else
                {
                    printf(RED "ERROR : UNABLE TO SAVE THE DATABASE\n"RESET);
                }

            break;

            case 5:
                if(updated==1)
                {
                    printf(RED "ERROR : DATABASE IS ALREADY UPDATED.CAN'T UPDATE AGAIN\n"RESET );
                    break;
                }
                ret=update_database(arr,&head);
                if(ret==SUCCESS)
                {
                    printf(GREEN "DATABASE IS UPDATED SUCCESSFULLY\n"RESET);
                    print_file(head);
                    created=0;
                    updated=1;
                }
                else
                {
                    printf(RED "ERROR : DATABASE UPDATE IS FAILED\n"RESET);
                }
            break;

            case 6:
                printf(BLUE "EXITED FORM THE PROGRAM....\n"RESET);
                return 0;
            default:
                printf(RED "ERROR : Invalid choice. Try again\n"RESET);
        }
    }

}