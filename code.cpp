#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<malloc.h>
#include<limits.h>
#include<stdbool.h>
#include<Stdlib.h>
struct node { 
    char *data; 
    struct node* next; 
    struct node* prev; 
	char *key;
}*head,*last;
void insert(char* data)
{
    struct node * newNode;
    if(last==NULL)
    {
    	head=(struct node *)malloc(sizeof(struct node));
        head->data=data;
        head->prev=NULL;
        head->next=NULL;
        last=head;
    }
    else
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = data;
        newNode->prev = last;
        newNode->next = NULL;
        last->next = newNode;
        last = newNode;
    }
}
int search(char *item)  
{ 
        int flag=0;
        struct node* temp=head;
        if(temp==NULL)
           printf("Empty");
        else
        {
        	while(temp!=NULL)  
        	{  
            	if(strcmp(temp->data,item)==0)  
            	{	  
               		flag=1;
               		break;
            	}  
            	temp=temp->next;  
       	 	}
		}
		return flag;
} 

void display()
{
	struct node* temp;
    if(head==NULL)
    {
    	printf("empty");
	}
    else
    {
    	temp=head;
    	while(temp!=NULL)
    	{
	       printf("%s\t",temp->data);
	       temp=temp->next;
        }
    }
}

int main()
{
	char query[1000];
	int i,h=0;
	char s[3][100]={"C:/Users/vobhi/Desktop/file1.txt",
"C:/Users/vobhi/Desktop/file2.txt",
"C:/Users/vobhi/Desktop/file3.txt"};
	printf("Enter query to search for:");
	scanf("%s",query);
	for(i=0;i<3;i++)
	{
               {
		struct node *head=NULL;
		struct node *last=NULL;
		char line[10000];
		FILE *fp;
		fp=fopen(s[i],"r");
		char* token;
    	while(fgets(line,sizeof(line),fp))
    	{
        	token=strtok(line,"!,.- ");
        	while (token != NULL)
        	{
            	if(token!=" ")
                    insert(token);
            	token=strtok(NULL,"!,.- ");
        	}
		}
		//display();
		int j=search(query);
		if(j==1) 
		{
		    if(h==1)
		    	printf(", %s",s[i]);
		    else
		    {
           		printf("Yes present in %s\n",s[i]);
           		h=1;
           	}
        }
}
        else if(i==2&&h==0)
        {	
           printf("Not present in any of the file");
           //exit(0);
        }
     	fclose(fp);
	}
    return 0;
}

