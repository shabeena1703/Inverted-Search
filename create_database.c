#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "main.h"

void hash_table(hash_t *arr)
{
    for(int i=0;i<27;i++)
    {
        arr[i].index=i;
        arr[i].link=NULL;
    }
}



int create_database(hash_t *arr,fileNode_t **head)
{
    fileNode_t *temp=*head;
    while(temp!=NULL)
    {
        FILE *fp=fopen(temp->fname,"r");
        if(fp==NULL)
        {
            printf(RED "ERROR : Cannot open %s\n"RESET,temp->fname);
            temp=temp->link;
            continue;
        }

        char word[25];
        while(fscanf(fp,"%s",word)==1)
        {
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

            //if index doesnt contain any word,create main node and subnode and directly copy
            if(arr[index].link==NULL)
            {
                mainNode_t *newMain=malloc(sizeof(mainNode_t));
                strcpy(newMain->word,word);
                newMain->file_count=1;
                newMain->link=NULL;

                subNode_t *newSub=malloc(sizeof(subNode_t));
                strcpy(newSub->fname,temp->fname);
                newSub->word_count=1;
                newSub->link=NULL;
                //main node link should be updated with subnode address
                newMain->sub_link=newSub;
               
                //hashtable index should be update with main node address
                arr[index].link=newMain;
            }
            //if index already contains a word,check if that word and our word same or not if same,found=1
            else
            {
                mainNode_t *mainTemp=arr[index].link;
                int wordFound=0;
                while(mainTemp!=NULL)
                {
                    if(strcmp(mainTemp->word,word)==0)
                    {
                        wordFound=1;
                        break;
                    }
                    mainTemp=mainTemp->link;
                }

                //if same word is found,check it it is present in same file or not..if present,found=1
                if(wordFound==1)
                {
                    subNode_t *subTemp=mainTemp->sub_link;
                    int fileFound=0;

                    while(subTemp!=NULL)
                    {
                        if(strcmp(subTemp->fname,temp->fname)==0)
                        {
                            fileFound=1;
                            break;
                        }
                        subTemp=subTemp->link;
                    }
                    //if word is present in same file,just increment the file count
                    if(fileFound==1)
                    {
                        subTemp->word_count++;
                    }
                    //if not present in same file,create another subnode and update the contents
                    else
                    {
                        subNode_t *newSub=malloc(sizeof(subNode_t));
                        strcpy(newSub->fname,temp->fname);
                        newSub->word_count = 1;
                        newSub->link=NULL;
                        //insert last
                        subTemp=mainTemp->sub_link;

                        while(subTemp->link!=NULL)
                        {
                            subTemp=subTemp->link;
                        }
                        subTemp->link=newSub;
                        mainTemp->file_count++;
                    }
                }
                //same word not is found so again create seperate main and subnode for that word
                else
                {
                    mainNode_t *newMain=malloc(sizeof(mainNode_t));
                    strcpy(newMain->word,word);
                    newMain->file_count=1;
                    newMain->link=NULL;

                    subNode_t *newSub=malloc(sizeof(subNode_t));
                    strcpy(newSub->fname,temp->fname);
                    newSub->word_count = 1;
                    newSub->link=NULL;

                    newMain->sub_link=newSub;

                    mainNode_t *mtemp=arr[index].link;
                    while(mtemp->link!=NULL)
                    {
                        mtemp=mtemp->link;
                    }
                    mtemp->link=newMain;
                }

            }
        }
        fclose(fp);
        temp=temp->link;
    }
    return SUCCESS;
}
