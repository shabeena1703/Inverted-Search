#include<stdio.h>
#include<string.h>
#include<stdlib.h>


#include "main.h"

int is_txt(char *fname)
{
    char *ptr=strstr(fname,".txt");
    if(ptr==NULL)
    {
        printf(RED "The file is not .txt\n"RESET);
        return FAILURE;
    }
    return SUCCESS;
}


int is_file_exist(char *fname)
{
    FILE *fptr=fopen(fname,"r");
    if(fptr==NULL)
    {
        printf(RED "File is not present\n"RESET);
        return FAILURE;
    }
    fclose(fptr);
    return SUCCESS;
}


int file_has_content(char *fname)
{
    FILE *ffptr=fopen(fname,"r");
    if(ffptr==NULL)
    {
        return FAILURE;
    }
    fseek(ffptr,0,SEEK_END);
    long size=ftell(ffptr);
    if(size==0)
    {
        printf(RED "No content present in file\n"RESET);
        return FAILURE;
    }
    return SUCCESS;
    
}


int is_duplicate(fileNode_t *head,char *fname)
{
    fileNode_t *temp=head;
    while(temp!=NULL)
    {
        if(strcmp(temp->fname,fname)==0)
        {
            printf(RED "It is duplicate file\n"RESET);
            return DUPLICATE;
        }
        temp=temp->link;
    }
    return SUCCESS;
}


int insert(fileNode_t **head,char *fname)
{
    fileNode_t *newNode=malloc(sizeof(fileNode_t));
    {
        if(newNode==NULL)
        {
            return FAILURE;
        }
        strcpy(newNode->fname,fname);
        newNode->link=NULL;
        if(*head==NULL)
        {
           *head=newNode; 
           return SUCCESS;
        }

        fileNode_t *temp=*head;
        while(temp->link!=NULL)
        {
           temp=temp->link; 
        }
        temp->link=newNode;
        return SUCCESS;
    }
}


void print_file(fileNode_t *head)
{
    if(head==NULL)
    {
        printf(RED "file is not present"RESET);
        return ;
    }
    fileNode_t *temp=head;
    printf(MAGENTA "Head -> "RESET);
    while(temp!=NULL)
    {
        printf(CYAN "%s"RESET,temp->fname);
        if(temp->link!=NULL)
        {
            printf(MAGENTA "-> "RESET);
        }
        temp=temp->link;
    }
    printf(MAGENTA" -> NULL\n"RESET);
}


int validate_and_insert(fileNode_t **head,char *fname)
{
    if(is_txt(fname)==FAILURE)
    {
        return FAILURE;
    }
    if(is_file_exist(fname)==FAILURE)
    {
        return FAILURE;
    }
    if(file_has_content(fname)==FAILURE)
    {
        return FAILURE;
    }
    if(is_duplicate(*head,fname)==DUPLICATE)
    {
        return DUPLICATE;
    }
    insert(head,fname);
    return SUCCESS;
}