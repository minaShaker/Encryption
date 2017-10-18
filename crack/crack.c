#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>

bool check (int argc);

int main (int argc,string argv[])
{
    if (check(argc))
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }
    
    char salt[3]={argv[1][0],argv[1][1],'\0'};
    
    char text[5];
    text[4]='\0';
    

    for (text[0]= 'A';text[0]<='z';text[0]++)
    {
        text[0] = (text[0]=='Z'+1)?('a'):(text[0]);
        
        text[1]='\0';
        
        if (!strcmp(argv[1],crypt(text,salt)))
        {
            printf("%s\n",text);
            return 0;
        }
        for (text[1] = 'A';text[1]<='z';text[1]++)
        {
            text[1] = (text[1]=='Z'+1)?('a'):(text[1]);
            
            text[2]='\0';
            
            if (!strcmp(argv[1],crypt(text,salt)))
            {
                printf("%s\n",text);
                return 0;
            }
            for (text[2] = 'A';text[2]<='z';text[2]++)
            {
                text[2] = (text[2]=='Z'+1)?('a'):(text[2]);
                
                text[3]='\0';
                    
                if (!strcmp(argv[1],crypt(text,salt)))
                    {
                        printf("%s\n",text);
                        return 0;
                    }
                for (text[3] = 'A';text[3]<='z';text[3]++)
                {
                    text[3] = (text[3]=='Z'+1)?('a'):(text[3]);


                    if (!strcmp(argv[1],crypt(text,salt)))
                    {
                        printf("%s\n",text);
                        return 0;
                    }
                }
            }
        }
    }
}


bool check (int argc)
{
    if (argc!=2)
        return 1;
    return 0;
}