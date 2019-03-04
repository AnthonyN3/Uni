package com.iofile;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

/**
 * Reads a a record file and prints,sorts,edits and creates new records
 * @author Anthony
 *
 */

public class lab_9_tester {
	
	public static void main(String[] args) throws IOException
	{
		//Variables
		String hold;
		int choose = 0;
		
		//Creates an instance of Scanner
		Scanner sc = new Scanner(System.in);
		
		//Creates an instance of Record
		Record rec = new Record();
		
		//Loops until the user wants to exit
		do {
			//promts user
			System.out.println("\n1.Enter a record   2.Read file and display  3.Navigate 0.Exit");
			System.out.println();
			choose = sc.nextInt();
			sc.nextLine(); //clears the \n in the sc
			
			//Switch used as if statement depending on the users input based on the method 
			switch(choose)
			{
				//Creates a record
				case 1:
					System.out.println("Creating a record...." );
					
					System.out.println("First name: ");
					rec.first_name = sc.next();
					
					System.out.println("Last name: ");
					rec.last_name = sc.next();
					
					System.out.println("DOB (mm/dd/yyyy): ");
					rec.date = sc.next();
					
					
					writeToFile(rec.toString());
					
					break;
				//Displays the file 	
				case 2:
					System.out.println("1. Display Exactly as in file  2. Display in descending order (by last name): ");
					choose = sc.nextInt();
					sc.nextLine();
					
					if( choose == 1)
					{
						displayFile();
					}else{
						displayFileOrdered();
					}

					break;
				//Edits the record
				case 3:
					editRecords();
					break;
				//Prints out the exit
				case 0: 
					System.out.println("BYE");
					break;
				//if the switch does not recognize any of the cases it will promt the invalid key
				default: 
					System.out.println("Invalid key");
					break;
			}
			
		}while (choose != 0);
		
		
	}
	
	/**
	 * method that writes the records to a file
	 * @param input
	 * @throws IOException
	 */
	static private void writeToFile(String input) throws IOException{
        
		//Creates or appends in the existing text file .txt
		File f = new File("C:\\Users\\Anthony\\eclipse-workspace\\60_210_Lab_9_FIle_IO\\record.txt");
        FileWriter fw = new FileWriter(f,true);			//instance a FileWriter and makes it so that it appends
        try{
            BufferedWriter bw = new BufferedWriter(fw);	//creates an instance of the BufferWriter to write
            bw.write(input);		//write into the file the input from parameters
            bw.flush();				//Flushes the BufferWRiter
            bw.close();		
        }
        catch(Exception e){
            System.out.println(e);
        }
	}
	
	/**
	 * Display the contents of the file
	 */
	static private void displayFile()
	{
		//Creates the path of the file and the text of the file if it does not exist in the path
		File f = new File("C:\\Users\\Anthony\\eclipse-workspace\\60_210_Lab_9_FIle_IO\\record.txt");
		
		try {
			//Used to read from file 
			FileReader fr = new FileReader(f);
			BufferedReader br = new BufferedReader(fr);
			
			//Loops until br reaches a point where its not read(last input)
			while(br.ready())
			{
				//prints the line of the file
				System.out.println(br.readLine());
			}
			
		}catch(Exception e)
		{
			System.out.println(e);
		}
	}
	
	/**
	 * Reads the file 
	 */
	static private void displayFileOrdered()
	{	
		//Creates the path or makes the text if its not in the path
		File f = new File("C:\\Users\\Anthony\\eclipse-workspace\\60_210_Lab_9_FIle_IO\\record.txt");
		
		//Counts the amount of record there are
		int recordCount = 0;
		
		try {
			//Used to read from the file
			FileReader fr = new FileReader(f);
			BufferedReader br = new BufferedReader(fr);
			
			//This is used to read how many records are in the file
			while(br.ready())
			{
				br.readLine();
				recordCount++;
			}
			
			//makes the instance again to refresh its buffers
			fr = new FileReader(f);
			br = new BufferedReader(fr);
			
			//Instance of a record array
			Record [] list = new Record[recordCount];
			String lineRead; //temp to store the lines read in the file 
			
			//Loops through the list and inputs each record into a new index of the array list
			for(int i = 0 ; br.ready() ; i++)
			{
				lineRead = br.readLine();
				list[i] = new Record(lineRead);

			}		
			
			//Sorts the array
			Arrays.sort(list);
			
			//Loops through the sorted array and prints it
			for(int i = 0 ; i < recordCount ; i++)
			{
				System.out.print(list[i]);
			}
			
			//Deletes everything in the file
			PrintWriter pr = new PrintWriter("C:\\Users\\Anthony\\eclipse-workspace\\60_210_Lab_9_FIle_IO\\record.txt"); 
			pr.print("");
			pr.close();
			
			//This overwrites the old file and puts in the newly sorted list of records
			for(int i = 0 ; i < recordCount ; i++)
			{
				writeToFile(list[i].toString());
			}
			
			
		}catch(Exception e)
		{
			System.out.println(e);
		}
	}
	
	/**
	 * Edits the record based off the line the user entered
	 */
	static private void editRecords()
	{
		//creates the path
		File f = new File("C:\\Users\\Anthony\\eclipse-workspace\\60_210_Lab_9_FIle_IO\\record.txt");
		
		//Variables
		int recordCount = 0;
		int choose;
		
		//Creates the scanner
		Scanner scan = new Scanner(System.in);
		
		try {
			//Reads the file to count the number of records in the file
			FileReader fr = new FileReader(f);
			BufferedReader br = new BufferedReader(fr);
			while(br.ready())
			{
				br.readLine();
				recordCount++;
			}
			
			//Creates a file reader
			fr = new FileReader(f);
			br = new BufferedReader(fr);
			
			//Creates a record array 
			Record [] list = new Record[recordCount];
			String lineRead;
			
			//Adds the records from file into the record list
			for(int x = 0 ; br.ready() ; ++x)
			{
				lineRead = br.readLine();
				list[x] = new Record(lineRead);
			}
			
			//THIS WHOLE THING PROMTS FOR THE USER WHICH PART THEY'D LIKE TO CHANGE FROM THE RECORD
			System.out.println("Which record would you like to change? ");
			choose = scan.nextInt();
			
			System.out.println("Editing....." + list[choose-1]);
			
			System.out.println("First name: ");
			list[choose-1].first_name = scan.next();
			
			System.out.println("Last name: ");
			list[choose-1].last_name = scan.next();
		
			System.out.println("DOB (mm/dd/yyyy): ");
			list[choose-1].date = scan.next();
			
			PrintWriter pr = new PrintWriter("C:\\Users\\Anthony\\eclipse-workspace\\60_210_Lab_9_FIle_IO\\record.txt"); 
			pr.print("");
			pr.close();
			
			//Writes to the file the newly edited record list
			for(int i = 0 ; i < recordCount ; i++)
			{
				writeToFile(list[i].toString());
			}
			
		}catch(Exception e)
		{
			System.out.println(e);
		}
		
		
	}		
	
}
