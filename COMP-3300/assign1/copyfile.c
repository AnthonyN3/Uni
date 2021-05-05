// Anthony Nguyen
// 2021-01-22
// Assignment_01 - Operating Systems
// Copies content of existinh file into another file

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define SIZE 100

// Removes trailing newline caused by fgets
void RemoveNL(char *string);

int main()
{
  // Variable Declaration
  char src_file[SIZE], dest_file[SIZE];
  char c;
  FILE *fp_src, *fp_des;

  // Get souce file name
  printf("Enter input file name: ");
  fgets(src_file, SIZE, stdin); // fgets() leaves '\n' but is safer than gets()
  RemoveNL(src_file);           // Removes trailing '\n'

  // Get destination file name
  printf("Enter destination file name: ");
  fgets(dest_file, SIZE, stdin);
  RemoveNL(dest_file);

  // Checks if source file exists and opens for reading
  if ( (fp_src = fopen(src_file, "r")) )
  {
    printf("\n<%s> succesfully opened\n", src_file);

    // Checks if destination file exists
    if ( access(dest_file, F_OK) == 0 )
    {
      // abort
      printf("\n<%s> already exists... exiting\n", dest_file);
      fclose(fp_src);
      exit(EXIT_FAILURE);
    }

    // creates destination file for writing..
    if ( (fp_des = fopen(dest_file, "w")) )
    {
      printf("<%s> succesfully created\n", dest_file);

      // src -> dest character by character.
      while((c = fgetc(fp_src)) != EOF)
        fputc(c, fp_des);
      printf("\n<%s> contents succesfully copied into <%s>\n", src_file, dest_file);
    }
    else
    {
      printf("Could not access or create <%s>\nexited...\n", dest_file);
      fclose(fp_src);
      exit(EXIT_FAILURE);
    }
    fclose(fp_des);
    fclose(fp_src);
  }
  else
  {
    printf("\n<%s> was not found... exiting\n", src_file);
    exit(EXIT_FAILURE);
  }

  return 0;
}

// Removes trailing newline caused by fgets
void RemoveNL(char *string)
{
  char *ptr;
  if ((ptr = strchr(string, '\n')) != NULL)
    *ptr = '\0';       // dereferencing ptr to set '\n' to '\0'
}
