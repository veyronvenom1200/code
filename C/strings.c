#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* substring(char*, int, int);

int main()
{
   char string[100], *pointer;
   int position = 1, length = 1, temp, string_length;

   printf("Enter a string: ");
   scanf("%s", string);

   temp = string_length = strlen(string);

   printf("Substring of \"%s\" are:\n", string); //backslash is used for quotation

   while (position <= string_length)
   {
      while (length <= temp)
      {
         pointer = substring(string, position, length);
         printf("%s\n", pointer);
         free(pointer);
         length++;
      }
      temp--;
      position++;
      length = 1;
   }

   return 0;
}

char *substring(char *string, int position, int length)
{
   char *pointer;
   int c;

   pointer = malloc(length + 1);

   if (pointer == NULL)
   {
      printf("Unable to allocate memory.\n");
      exit(1);
   }

   for (c = 0 ; c < length ; c++)
   {
      *(pointer+c) = *(string+position-1);
      string++;
   }

   *(pointer+c) = '\0';

   return pointer;
}
