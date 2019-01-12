#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;

};
void addatB(struct node **h,int data){
    struct node *nn = (struct node*)malloc(sizeof(struct node));
    nn->data = data;
    nn->next = *h;
    *h = nn;

}
void addatE(struct node **h, int data){
   struct node *nn = (struct node*)malloc(sizeof(struct node));
    if(*h == 0){
        addatB(h,data);
        return;
    }
   nn->data = data;
   nn->next = NULL;

   struct node *current;
   current = *h;

   while(current->next){
    current = current->next;
   }
   current->next = nn;



}
void addatM(struct node **h, int data){
    struct node *nn = (struct node *)malloc(sizeof(struct node *));
    nn->data = data;
    struct node *p,*c,*l;
    p = c = l = *h;
    while(l && l->next){
        if(c == *h){
            c = c->next;
            l = l->next->next;
            continue;
        }
        c = c->next;
        l = l->next->next;
        p = p->next;
    }
    nn->next = c;
    p->next = nn;
}
void addatP(struct node **h,int data,int p){
    struct node *t = *h;
    struct node *nn = (struct node *)malloc(sizeof(struct node *));
    nn->data = data;
    if(p == 1){
        nn->next = *h;
        *h = nn;
        return;
    }
    while(p-- >2){

            t = t->next;
             if(t == NULL){
                printf("Insertion not possible.\n");
                return;
            }

    }
    //printf("Data at p-1 is: %d", t->data);

    nn->next = t->next;
    t->next = nn;


}
void print(struct node **h){
    struct node *current = (*h);
    while(current){
        printf("%d\n", current->data);
        current = current->next;

    }

}
void deleteatB(struct node **h){
    struct node *t = *h;
    t = t->next;
    *h = t;


}
void deleteatL(struct node **h){
    struct node *t = *h;
    while(t->next->next){
        t = t->next;
    }
    t->next = NULL;


}
void deleteatM(struct node **h){
    struct node *p,*c,*l;
    p = *h;
    c = *h;
    l = *h;
    while(l && l->next){
           if(c == *h){
               c = c->next;
               l = l->next->next;
               continue;
           }
            c = c->next;
            l = l->next->next;
            p = p->next;

    }
    p->next = c->next;

}
void deleteatP(struct node **h, int ps){
    struct node *p,*c;
    p = c = *h;
    if(ps == 1){
        *h = c->next;
        free(c);
        return;
    }
    while(ps-- > 2){
        if(c == NULL){
            printf("Deletion not possible.\n");
            return;
        }
        c = c->next;

    }
    p = c->next;

    c->next = c->next->next;
    free(p);



}
void reverse(struct node **h){
   struct node *p= NULL;
    struct node *c = *h,*t;
    while(c!=NULL){
        t = c->next;
        c->next = p;
        p = c;
        c = t;
    }
    *h = p;

}
int main()
{
    struct node *head;
    head = NULL;
    int i,j,d;
    printf("Enter the number of elements:\n");
    scanf("%d", &i);
    for(j = 0; j<i; j++){
        printf("Enter the data:");
        scanf("%d", &d);
        addatE(&head,d);
    }

    /*printf("Data in the list is: \n");
    print(&head);
    printf("Data in list after deleting first element is: \n");
    deleteatB(&head);
    printf("\n");
    print(&head);
    printf("\n");
    printf("After deleting last node of the linked list:\n");
    deleteatL(&head);
    print(&head);

    deleteatM(&head);

    addatM(&head,80);

    print(&head);

    addatP(&head,55,4); */
    //deleteatP(&head,2);
    reverse(&head);
    print(&head);



    return 0;

}
