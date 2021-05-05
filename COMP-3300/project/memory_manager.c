#include <stdio.h>
#include <stdlib.h>

#define PAGE_ENTRIES 256
#define PAGE_SIZE 256
#define FRAME_SIZE 256
#define FRAMES 256
#define MEMORY_SPACE FRAMES*FRAME_SIZE

int main(int argc, char *argv[])
{
  // Checks if argument 1 after execution file is present
  if(argc != 2)
  {
    printf("Needs exactly 1 argument...exiting\n");
    exit(EXIT_FAILURE);
  }

  // File Discriptors 
  FILE *fp_backing, *fp_addresses, *fp_output;

  // IF statements for checking if all three files can be opened/created/read
  if( !(fp_backing = fopen("BACKING_STORE.bin","rb")) )
  {
    printf("<BACKING_STORE.bin> was not found... exiting\n");
    exit(EXIT_FAILURE);
  }
  if ( !(fp_addresses = fopen(argv[1], "r")) )
  {
    fclose(fp_backing);
    printf("could not access or create <%s>...exiting\n", argv[1]);
    exit(EXIT_FAILURE);
  }
  if ( !(fp_output = fopen("output.txt", "w")) )
  {
    fclose(fp_backing);
    fclose(fp_addresses);
    printf("could not access or create <output.txt>...exiting\n");
    exit(EXIT_FAILURE);
  }

  // Variables
  char physical_mem[MEMORY_SPACE];    // Represent the Physical Memory
  char backing_store[MEMORY_SPACE];   // Represents the BACKING_STORE.bin raw data
  int page_table[PAGE_ENTRIES];            // Our page table
  char address[8];                    // Size litle over the # of chars per address because need to account for \0 in fgets
  int fault_count = 0, free_frame = 0, addr_counter = 0;;

  // Setting each value in page_table to -1
  // This is used to state that a page is not in use
  for(int i = 0 ; i < PAGE_ENTRIES; ++i)
    page_table[i] = -1;

  fread(backing_store, MEMORY_SPACE,1, fp_backing);   // Read all RAW data from backing_store.bin and store into char arr

  // using fgets over fread because fgets stops after a \n so no need to use fseeks and stuff :)
  // Also note the use of "8" instead of "5" is it account for \0 and extra white spaces
  while( fgets(address,8, fp_addresses) )
  {   
    // if line read with fgets was just a newline, skip.
    if(address[0] != '\n')
    {
      // Address Conversions [16_bit] -> [8_bit][8_bit]
      int logical_addr = atoi(address);
      int offset = logical_addr & 255;          // grab rightmost 8 bits
      int page_num = (logical_addr >> 8) & 255; // grab leftmost 8 bits (the & 255 is redundent since there shouldn't be any more bits to the left (given that address only contains 16 bits). Tho for extra percaution we will still mask the value)

      // Handling Page Faults (Demand Paging)
      if(page_table[page_num] == -1)
      {
        // Read 256 byte page from an array (backing_store) that contains raw data from 
        // backing_store.bin and store in our "physical" memory array
        for(int i = 0 ; i < PAGE_SIZE ; ++i)
          physical_mem[i+(free_frame*PAGE_SIZE)] = backing_store[i+(page_num*PAGE_SIZE)];
        
        page_table[page_num] = free_frame;   // update the page table
        free_frame++;                        // increment to next avaiable free page
        fault_count++;                      // increment fault count
      }

      // Get the physical address based on mapped page # and then adding the offset
      int physical_addr = (page_table[page_num] << 8) | offset; // [frame_number | offset]

      // Write output into a file
      fprintf(fp_output,"Virtual address: %d Physical address: %d Value: %d\n", logical_addr, physical_addr, physical_mem[physical_addr]);
      addr_counter++;
    }
  }
  // Write results of translations into file
  fprintf(fp_output,"Number of Translated Addresses = %d\n", addr_counter);
  fprintf(fp_output,"Page Faults = %d\n", fault_count);
  fprintf(fp_output,"Page Fault Rate = %g\n", ((double)fault_count)/addr_counter);  //using %g == shorter %f (remove trailing 0's)

  // Write results of translations into stdout
  printf("Number of Translated Addresses = %d\n", addr_counter);
  printf("Page Faults = %d\n", fault_count);
  printf("Page Fault Rate = %g\n", ((double)fault_count)/addr_counter);

  // Close file descriptors
  fclose(fp_backing);
  fclose(fp_addresses);
  fclose(fp_output);

  return 0;
}