#include<stdio.h>
#include<string.h>
#include "main.h"

int search_database(hash_t *arr)
{
    char word[25];
    printf("Enter a word to search: ");
    scanf("%s",word);
    int index;
    if(word[0]>='A' && word[0]<='Z')
    {
        index=word[0]-'A';
    }
    else if(word[0]>='a' && word[0]<='z')
    {
        index=word[0]-'a';
    }
    else
    {
        index=26;
    }

    mainNode_t *mtemp=arr[index].link;
    if(mtemp==NULL)
    {
        printf(RED "ERROR : Word is not present\n"RESET);
        return FAILURE;
    }
    if(arr[index].link!=NULL)
    {
        //check if if given word is present in file or not throuch traversal
        
        while(mtemp!=NULL)
        {
            if(strcmp(mtemp->word,word)==0)
            {
                printf(MAGENTA "Word %s is present in %d files\n"RESET,word,mtemp->file_count);  
                subNode_t *stemp=mtemp->sub_link;
                while(stemp!=NULL)
                {
                    printf(CYAN "In %s =>" RESET GREEN "%d times\n"RESET,stemp->fname,stemp->word_count);
                    stemp=stemp->link;
                }
                return SUCCESS;
                
            }
            mtemp=mtemp->link;
        }
    }
    
    printf(RED "%s is not present in database\n"RESET,word);
    return FAILURE;
    
}