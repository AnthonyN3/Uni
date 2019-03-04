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


public class lab_9_testTwo {
	
	public static void main(String[] args) throws IOException
	{
	
		menu m = new menu();
		
		String hold;
		int choose = 0;
		
		Scanner sc = new Scanner(System.in);
		Record rec = new Record();
		
		do {
			System.out.println("\n1.Enter a record   2.Read file and display  3.Navigate 0.Exit");
			System.out.println();
			choose = sc.nextInt();
			sc.nextLine(); //clears the \n in the sc
			
			switch(choose)
			{
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
				case 2:
					System.out.println("1. Display Exactly as in file  2. Display in descending order (by last name): ");
					choose = sc.nextInt();
					sc.nextLine();
					
					if( choose == 1)
					{
						displayFile();
					}else{
						readFile();
					}

					break;
				case 3:
					editRecords();
					break;
				case 4:
					
					break;
				case 0: 
					System.out.println("BYE");
					break;
				default: 
					System.out.println("Invalid key");
					break;
			}
			
			
		}while (choose != 0);
		
		
	}
	
	static private void writeToFile(String input) throws IOException{
        File f = new File("C:\\Users\\Anthony\\eclipse-workspace\\60_210_Lab_9_FIle_IO\\record.txt");
        FileWriter fw = new FileWriter(f,true);
        try{
            BufferedWriter bw = new BufferedWriter(fw);
            bw.write(input);
            bw.flush();
            bw.close();
        }
        catch(Exception e){
            System.out.println(e);
        }
	}
	
	static private void displayFile()
	{
		File f = new File("C:\\Users\\Anthony\\eclipse-workspace\\60_210_Lab_9_FIle_IO\\record.txt");
		
		try {
			FileReader fr = new FileReader(f);
			BufferedReader br = new BufferedReader(fr);
			//br.mark(1);
			while(br.ready())
			{
				System.out.println(br.readLine());
			}
			
		}catch(Exception e)
		{
			System.out.println(e);
		}
	}
	
	static private void readFile()
	{	
		File f = new File("C:\\Users\\Anthony\\eclipse-workspace\\60_210_Lab_9_FIle_IO\\record.txt");
		
		int recordCount = 0;
		
		try {
			FileReader fr = new FileReader(f);
			BufferedReader br = new BufferedReader(fr);
			while(br.ready())
			{
				br.readLine();
				recordCount++;
			}
			
			fr = new FileReader(f);
			br = new BufferedReader(fr);
			
			Record [] list = new Record[recordCount];
			String lineRead;
			
			for(int i = 0 ; br.ready() ; i++)
			{
				lineRead = br.readLine();
				list[i] = new Record(lineRead);

			}		
			
			Arrays.sort(list);
			
			for(int i = 0 ; i < recordCount ; i++)
			{
				System.out.print(list[i]);
			}
			
			PrintWriter pr = new PrintWriter("C:\\Users\\Anthony\\eclipse-workspace\\60_210_Lab_9_FIle_IO\\record.txt"); 
			pr.print("");
			pr.close();
			
			for(int i = 0 ; i < recordCount ; i++)
			{
				writeToFile(list[i].toString());
			}
			
			
		}catch(Exception e)
		{
			System.out.println(e);
		}
	}
	
	static private void editRecords()
	{
		File f = new File("C:\\Users\\Anthony\\eclipse-workspace\\60_210_Lab_9_FIle_IO\\record.txt");
		
		int recordCount = 0;
		int choose;
		
		Scanner scan = new Scanner(System.in);
		
		try {
			
			FileReader fr = new FileReader(f);
			BufferedReader br = new BufferedReader(fr);
			while(br.ready())
			{
				br.readLine();
				recordCount++;
			}
			
			fr = new FileReader(f);
			br = new BufferedReader(fr);
			
			Record [] list = new Record[recordCount];
			String lineRead;
			
			for(int x = 0 ; br.ready() ; ++x)
			{
				lineRead = br.readLine();
				list[x] = new Record(lineRead);
			}
			
			
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