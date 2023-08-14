#include <stdio.h>
#include <stdlib.h>
#define m 10

typedef struct nodetype
{
    int key;
    struct nodetype *next;
}nodeT;

//1
nodeT* create(int givenkey)
{
    nodeT *p = (nodeT*)malloc(sizeof(nodeT));
    p->next = NULL;
    p->key= givenkey;
    return p;
}

//2
int hash(int givenkey) //calculam pozitia unde trebuie pus nodul
{
    int h = givenkey % m;
    return h;
}

//3
void insert(nodeT* hashmap[m], int givenkey)
{
    nodeT* p= create(givenkey);
    int h = hash(givenkey); //pozitia unde trebe pus

    if(hashmap[h] ==NULL){ //daca nu exista nod pe pozitie
        hashmap[h]= p;
    }
    else
    {
        p->next = hashmap[h]; //daca exista nod pe pozitie
        hashmap[h] = p;
    }
}

//4
int stergere(nodeT* hashmap[m], int givenkey)
{
    int h=hash(givenkey);
    nodeT* p =hashmap[h];
    nodeT* q =NULL;

    while(p!=NULL)
    {
        if(p->key == givenkey) break;
        q = p; //ca sa retinem nodul  dinainte ca sa facem legatura
        p=p->next;
    }
    int val = p->key;

    if(q!=NULL){ //facem legatura si stergem nodul p, daca exista nodul de dinainte
        q->next = p->next;
        free(p);
    }
    else //daca nu exista nodul de dinainte
    {
        hashmap[h] =hashmap[h]->next;
        free(p);
    }
    return val;
}

//5
void afisare(nodeT* hashmap[m])
{
    for(int i =0; i<m; i++)
    {
        nodeT* p = hashmap[i];
        while(p!=NULL)
        {
            printf("%d ", p ->key);
            p=p->next;
        }
        printf("\n");
    }
}

int main()
{
    nodeT* hashmap[m]={NULL}; //m=10

    insert(hashmap, 3);
    insert(hashmap, 5);
    insert(hashmap, 7);
    insert(hashmap, 13);
    insert(hashmap, 1);
    insert(hashmap, 24);
    insert(hashmap, 25);
    insert(hashmap, 71);
    afisare(hashmap);
    stergere(hashmap, 13);
    afisare(hashmap);
    return 0;
}
