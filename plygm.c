#include<stdio.h>
#include<stdlib.h>

typedef struct node{
        int child;
        struct node *next;
      }Node;

int main() 
{
           Node *linkCircular(int);
           Node *playGame(Node *,int,int);
           Node *curr;
           int m,n;
        
        do {
             printf("Enter number of child's: ");
             scanf("%d",&n);
             printf("\nEnter the count: ");
             scanf("%d",&m);
          }while(n <= 0 || m <= 0);
        
         curr = linkCircular(n); //maked nodes for children 
         curr = playGame(curr,n-1,m);
         printf("\n\t-- Winner: %d --\n\n",curr->child);
     
 } //end main
   
     Node *linkCircular(int n) {
    
     Node *np,*first,*makeNewNode(int);
    
     np = makeNewNode(1); //First node
    
     first = np;
     
    for(int h = 2; h <= n; h++) {
    
       np->next = makeNewNode(h);
       np = np->next;
  }

     np->next = first;
     //last node point back to first node in the list
    
     return first;
    
} //end linkCircular 


     Node *makeNewNode(int n) {
     
     Node *np = (Node *)malloc(sizeof(Node));
    
     if(np == NULL) exit(1);
    
     np->child = n;
     np->next = NULL;
     return np;
    
  } //end makeNewNode

    Node *playGame(Node *top,int x,int m) {
     
    Node *prev,*curr;
    
    curr = top;
    
    for(int h = 1; h <= x; h++) {
     
     for(int i = 1; i < m; i++) {
    
      prev = curr;
      curr = curr->next;
  } 
      prev->next = curr->next;
    
      free(curr);
    
      curr = prev->next;
    
  } //end for
   
      return curr;
    
 } //end playGame 
    