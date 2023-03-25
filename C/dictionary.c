#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

#define SIZE 20

struct Data {
    char *name;
    char *number;
    int key;
};

struct Data *phoneBook[SIZE];

int hashCode(int key) {
    return key % SIZE;
}

void insert(char *name,char *number, int key) {

   struct Data *item = (struct Data*) malloc(sizeof(struct Data));
   item->name = name;
   item->number = number;

   //get the hash
   int hashIndex = hashCode(key);

   //move in array until an empty or deleted cell
   while(phoneBook[hashIndex] != NULL && phoneBook[hashIndex]->key != -1) {
      //go to next cell
      ++hashIndex;

      //wrap around the table
      hashIndex %= SIZE;
   }

   phoneBook[hashIndex] = item;
}

void display() {
   int i = 0;

   for(i = 0; i<SIZE; i++) {

      if(phoneBook[i] != NULL)
         printf("%*s %s\n", 10, phoneBook[i]->name, phoneBook[i]->number);
   }

   printf("\n");
}

int main() {
   struct Data *yellowPages = (struct Data*) malloc(sizeof(struct Data));
   yellowPages->name = "Jane Doe";
   yellowPages->number = "1234567890";

   insert("Jane Doe", "1234567890", 0);
   insert("Jane Smith", "0987654321", 0);

   display();

}
