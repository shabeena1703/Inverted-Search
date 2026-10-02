#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "main.h"

int update_database(hash_t *arr, fileNode_t **head)
{
    char databasefile[50];
    printf("Enter the database file name: ");
    scanf("%s", databasefile);

    // check .txt
    char *ptr = strstr(databasefile, ".txt");
    if(ptr == NULL)
    {
        printf(RED " ERROR : It is not .txt file\n"RESET);
        return FAILURE;
    }

    FILE *fp = fopen(databasefile, "r");
    if(fp == NULL)
    {
        printf(RED "Cannot open %s\n"RESET, databasefile);
        return FAILURE;
    }

    // check first and last character '#'
    char first = fgetc(fp);
    fseek(fp, -2, SEEK_END);
    char last = fgetc(fp);

    if(first != '#' || last != '#')
    {
        printf(RED "It is not a database file\n"RESET);
        fclose(fp);
        return FAILURE;
    }

    rewind(fp);

    // HASH TABLE RECREATION 

    char line[300];

    while(fgets(line, sizeof(line), fp))
    {
        int index;
        int file_count;
        int total_count;

        char word[25];
        char filenames[20][50];
        int counts[20];

        char *token = strtok(line, ";");

        sscanf(token, "#%d", &index);

        token = strtok(NULL, ";");
        strcpy(word, token);

        token = strtok(NULL, ";");
        file_count = atoi(token);

        token = strtok(NULL, ";");
        total_count = atoi(token);

        // Read all filenames
        for(int i = 0; i < file_count; i++)
        {
            token = strtok(NULL, ";");
            strcpy(filenames[i], token);
        }

        // Read all word counts
        for(int i = 0; i < file_count; i++)
        {
            token = strtok(NULL, ";");
            counts[i] = atoi(token);
        }

        // Create Main Node
        mainNode_t *newMain = malloc(sizeof(mainNode_t));

        strcpy(newMain->word, word);
        newMain->file_count = file_count;
        newMain->sub_link = NULL;
        newMain->link = NULL;

        subNode_t *last = NULL;

        // Create Sub Nodes
        for(int i = 0; i < file_count; i++)
        {
            subNode_t *newSub = malloc(sizeof(subNode_t));

            strcpy(newSub->fname, filenames[i]);
            newSub->word_count = counts[i];
            newSub->link = NULL;

            if(newMain->sub_link == NULL)
            {
                newMain->sub_link = newSub;
            }
            else
            {
                last->link = newSub;
            }

            last = newSub;
        }

        // Insert Main Node into Hash Table
        if(arr[index].link == NULL)
        {
            arr[index].link = newMain;
        }
        else
        {
            mainNode_t *mtemp = arr[index].link;

            while(mtemp->link != NULL)
            {
                mtemp = mtemp->link;
            }

            mtemp->link = newMain;
        }
    }


    rewind(fp);

    // read all filenames already present in database
    char file_in_db[50];

    while(fgets(line, sizeof(line), fp))
    {
        char *tok = strtok(line, ";");

        while(tok != NULL)
        {
            if(strstr(tok, ".txt"))
            {
                strcpy(file_in_db, tok);

                fileNode_t *prev = NULL;
                fileNode_t *temp = *head;

                while(temp != NULL)
                {
                    if(strcmp(temp->fname, file_in_db) == 0)
                    {
                        if(prev == NULL)
                            *head = temp->link;
                        else
                            prev->link = temp->link;

                        free(temp);
                        break;
                    }

                    prev = temp;
                    temp = temp->link;
                }
            }

            tok = strtok(NULL, ";");
        }
    }

    fclose(fp);

    if(*head == NULL)
    {
        printf(RED "No new files to update\n"RESET);
        return FAILURE;
    }

    printf(GREEN "INFO : Database updated successfully\n"RESET);

    return SUCCESS;
}



