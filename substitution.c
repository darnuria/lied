#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char substitution (char cipher[], char key1[27], char key2[27], char decipher[])
  {
    int a, b, c;

    for (a=0; cipher[a] != 0; a++)
      {
      	c = 0;
        for(b=0; key1[b] != 0 && c == 0; b++)
          {
            if(cipher[a] == key1[b])
              {
                decipher[a] = key2[b];
              }
             if(cipher[a] < 'a' || cipher[a] > 'z' || c == 0)
             	{
             		decipher[a] = cipher[a];
             	}
            /*else if(tolower(cipher[a]) == key1[b])
            	{
								decipher[a] == toupper(key2[b]);
            	}*/
          }
      }
    decipher[a] = '\0';
  }


int main(int argc, char *argv[])
  {

		if(argc == 3 && strlen(argv[2]) == 26)
			{
    		char output[strlen(argv[1])+1];
    		substitution(argv[1], argv[2], "abcdefghijklmnopqrstuvwxyz", output);
    		printf("%s\n", output);
    		return 0;
			}
		else if(argc == 4 && strlen(argv[2]) == strlen(argv[3]))
			{
    		char output[strlen(argv[1])+1];
    		substitution(argv[1], argv[2], argv[3], output);
    		printf("%s\n", output);
    		return 0;
    	}
    else
    	{
				printf("Wrong input !\n");
				return 1;
    	}

  }
