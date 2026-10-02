#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "main.h"
int save_database(hash_t *arr)
{
    char fname[50];
    printf("Enter a file name: ");
    scanf("%s",fname);

    //check if it is .txt ot not
    char *ptr=strstr(fname,".txt");
    if(ptr==NULL)
    {
        printf(RED "ERROR : It is not .txt file"RESET);
        return FAILURE;
    }
    
    FILE *fptr=fopen(fname,"w"); 
    if(fptr==NULL)
    {
        printf(RED "ERROR : Cannot open the %s"RESET,fname);
        return FAILURE;
    }

     
    for(int i=0;i<27;i++)
    {
        mainNode_t *mtemp=arr[i].link;
        while(mtemp!=NULL)
        {
            //total word count
            int total_word_count=0;
            subNode_t *stemp=mtemp->sub_link;
            while(stemp!=NULL)
            {
                total_word_count+=stemp->word_count;
                stemp=stemp->link;
            }
            //print index,word,file count and total word count
            fprintf(fptr,"#%d;%s;%d;%d;",i,mtemp->word,mtemp->file_count,total_word_count);
                
            //print files
            stemp=mtemp->sub_link;
            while(stemp!=NULL)
            {
                fprintf(fptr,"%s;",stemp->fname);
                if(stemp->link!=NULL)
                {
                     //printf("->");
                }
                stemp=stemp->link;
            }
            

            //no of times word present in each file
            stemp = mtemp->sub_link;
            while (stemp != NULL)
            {
                fprintf(fptr,"%d;", stemp->word_count);
                
                stemp = stemp->link;
            }
            fprintf(fptr,"#\n");
            mtemp = mtemp->link;
        }
    }

    fclose(fptr);
    return SUCCESS;
    
}