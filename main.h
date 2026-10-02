#ifndef MAIN_H
#define MAIN_H

#define SUCCESS   1
#define FAILURE   0
#define DUPLICATE 2

#define RESET   "\033[0m"

#define RED     "\033[91m"   
#define GREEN   "\033[92m"   
#define YELLOW  "\033[93m"   
#define BLUE    "\033[94m"   
#define MAGENTA "\033[95m"   
#define CYAN    "\033[96m"   
#define WHITE   "\033[97m"   

//file
typedef struct fileNode
{
    char fname[50];
    struct fileNode *link;
} fileNode_t;

//subnode
typedef struct subnode
{
    char fname[50];
    int word_count;
    struct subnode *link;
}subNode_t;

//main node
typedef struct mainnode
{
    int file_count;
    char word[25];
    subNode_t *sub_link;
    struct mainnode *link;
}mainNode_t;


typedef struct hash
{
    int index;
    mainNode_t*link;
}hash_t;



int is_txt(char *fname);
int is_file_exist(char *fname);
int file_has_content(char *fname);
int is_duplicate(fileNode_t *head,char *fname);
int insert(fileNode_t **head,char *fname);
void print_file(fileNode_t *head);

int validate_and_insert(fileNode_t **head,char *fname);
void hash_table(hash_t *arr);
int create_database(hash_t *arr,fileNode_t **head);
int display_database(hash_t *arr);
int search_database(hash_t *arr);
int save_database(hash_t *arr);
int update_database(hash_t *arr,fileNode_t **head);



#endif