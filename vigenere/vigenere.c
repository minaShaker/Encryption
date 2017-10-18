#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


#define letters 26


bool check (int argc,char argv[]);
void cyphering (string text,int key[],int n);


int main (int argc,string argv[])
{
    if (check(argc,argv[1]))//check the correctness of the input
        return 1;
    
    int n=strlen(argv[1]);    
    int key [n];
    
    for (int x=0;x<n;x++)
    {
        if(isupper(argv[1][x]))
            argv[1][x]-='A';
        else if (islower(argv[1][x]))
            argv[1][x]-='a';
        
        key[x]=(int)argv[1][x];
    }

    

    printf("plaintext: ");
    string text =get_string();

    cyphering(text,key,n);//take the text and print the cyphered text

    return 0;
}



bool check (int argc,string argv)//check the correctness of the input
{
    if (argc !=2)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }else
        for (int x=0,n=strlen(argv);x<n;x++)
            if (!(isalpha( argv[x])))
            {
                printf("Usage: ./caesar k\n");
                return 1;
            }
    
    return 0;
}



void cyphering (string text,int key[],int n)//take the text and print the cyphered text
{
    for (int x =0,v=0,z=strlen(text); x<z; x++)
        if (islower(text[x]))
        {
            text[x]-='a';
            text[x]=(text[x]+key[v%n])%letters;
            text[x]+='a';
            v++;
        }else if (isupper(text[x]))
        {
            text[x]-='A';
            text[x]=(text[x]+key[v%n])%letters;
            text[x]+='A';
            v++;
        }
        
    printf("ciphertext: %s\n",text);
}