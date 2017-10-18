#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


#define letters 26


bool check (int argc);
void cyphering (string text,int key);


int main (int argc,string argv[])
{
    if (check(argc))//check the correctness of the input
        return 1;

    int key = atoi(argv[argc-1]);

    key%=letters;//decrease the number of the key cause key 1 has the same effect as key 27
    

    printf("plaintext: ");
    string text =get_string();

    cyphering(text,key);//take the text and print the cyphered text

    return 0;
}



bool check (int argc)//check the correctness of the input
{
    if (argc !=2)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }
    return 0;
}



void cyphering (string text,int key)//take the text and print the cyphered text
{
    for (int x =0,n=strlen(text); x<n; x++)
        if (islower(text[x]))
        {
            text[x]-='a';
            text[x]=(text[x]+key)%letters;
            text[x]+='a';
        }else if (isupper(text[x]))
        {
            text[x]-='A';
            text[x]=(text[x]+key)%letters;
            text[x]+='A';
        }

    printf("ciphertext: %s\n",text);
}