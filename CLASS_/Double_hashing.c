#include<stdio.h>
#include<string.h>
#define max 10
int hashtable[max];
int f1(int hashkey)
{
    return ((2*hashkey)+1)%max;
}

int f2(int hashkey)
{
    return ((3*hashkey)+2)%max;
}

int Doublehashing(int hashkey,int operationvalue)
{
    for(int i=0;i<max;i++)
    {
        if(hashtable[(f1(hashkey)+i*f2(hashkey))%max]==operationvalue)
            return (f1(hashkey)+i*f2(hashkey))%max;
    }
    return -1;
}

void insert(int hashvalue)
{
    int hashtableindex=Doublehashing(hashvalue,0);
    if(hashtableindex==-1)
        printf("Element can't be inserted");
    else
        hashtable[hashtableindex]=hashvalue;
}

void Search(int hashvalue)
{
    int hashkey=hashvalue%max;
    int hashtableindex=Doublehashing(hashkey,hashvalue);
    if(hashtableindex==-1)
        printf("Element not found:");
    else
        printf("Element found");
}

void Delete(int hashvalue)
{
    int hashkey=hashvalue%max;
    int hashtableindex=Doublehashing(hashkey,hashvalue);
    if(hashtableindex==-1)
        printf("Element not found:");
    else
        hashtable[hashtableindex]=0;
}
void Display()
{
    for(int i=0;i<max;i++){
        if(hashtable[i]!=0)
            printf("%d\n",hashtable[i]);
        else
            printf("NUll\n");
    }
}


int main()
{
    int choose,value;
    do
    {
        printf("1.Insert 2.delete 3. search 4,Dislpay 0.exit");
        scanf("%d",&choose);
        switch (choose)
        {
        case 1:
            printf("Enter data to be inserted:");
            scanf("%d",&value);
            insert(value);
            break;
        case 2:
            printf("Enter data to be deleted:");
            scanf("%d",&value);
            Delete(value);
            break;
        case 3:
            printf("enter data to search:");
            scanf("%d",&value);
            Search(value);
            break;
        case 4:
            Display();
            break;
        }
    } while(choose);
}