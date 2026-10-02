#include<stdio.h>
#include "main.h"


int display_database(hash_t *arr)
{
    printf(MAGENTA "------------------------------------------------------------------------------------------------\n"RESET);
    printf(MAGENTA "INDEX       WORD        FILE COUNT      TOTAL_WORD_COUNT        FILES       WORD_COUNT_FILE\n"RESET);
    printf(MAGENTA "------------------------------------------------------------------------------------------------\n"RESET);   
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
            //print index,eord,file count and total word count
            printf(BLUE "%-10d "RESET GREEN"%-12s" RESET CYAN"%-15d "RESET BLUE "%-20d"RESET,i,mtemp->word,mtemp->file_count,total_word_count);
            
            //print files
            stemp=mtemp->sub_link;
            while(stemp!=NULL)
            {
                printf(MAGENTA "%s"RESET,stemp->fname);
                if(stemp->link!=NULL)
                {
                    printf(MAGENTA "->"RESET);
                }
                stemp=stemp->link;
            }
            printf("            ");

            //no of times word present in each file
            stemp = mtemp->sub_link;
            while (stemp != NULL)
            {
                printf(GREEN "%d"RESET, stemp->word_count);
                if (stemp->link != NULL)
                    printf(GREEN "->"RESET);
                stemp = stemp->link;
            }

            printf("\n");

            mtemp = mtemp->link;
        }
    }
    printf(MAGENTA "------------------------------------------------------------------------------------------------\n"RESET);
    return SUCCESS;
}
