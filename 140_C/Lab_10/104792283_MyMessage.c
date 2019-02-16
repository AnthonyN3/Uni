#include <stdio.h>
#include <stdlib.h>

int main(int argc , char *argv[]){

 FILE *fp;

 if(argc != 2) {
   printf("Error using the arrgument is: ouda_MyMessage filename\n" );
   exit(EXIT_FAILURE);

 }

 fp = fopen(argv[1], "r");
 if ( fp == NULL){
   printf("Can't open the %s\n", argv[1]);
   exit(EXIT_FAILURE);

 }

 char ch = getc(fp);
 while(ch != EOF) {
   putchar(ch);
   ch = getc(fp);
 }
 fclose(fp);
 return 0;
}