package com.anthony.assignment2;

import java.util.*;


import java.io.*;

public class testerAssign2 {
	
	public static void main(String[] args) throws IOException, ClassNotFoundException
	{
		//Exit boolean used to exit while loop
		boolean exit = false;
		
		//User input variable string
		String input = "void";
		
		//The capacity of the inventory 
		int inventoryCapacity = 15;
		
		//Instantiates a scanner
		Scanner sc = new Scanner(System.in);
		
		//Item array called inventory 
		item [] inventory = new item[inventoryCapacity];
		
		//prints a header
		System.out.println("YOUR INVENTORY");
		
		//Counts the number of item in the inventory 
		int itemCounter = 0;
		
		//Do loop used to keep prompting the user until they have pressed exit
		do {
					
			//prompts user
			System.out.print("\n\nadd, purchase, display, remove, save, load or exit? ");
			input = sc.next();
			
			//Adds to inventory
			if( input.toLowerCase().equals("add"))
			{
				if(itemCounter < inventoryCapacity)
				{
					System.out.print("add a book or gift? ");
					input = sc.next();
					System.out.println();
					
					
					if(input.compareToIgnoreCase("book") == 0)
					{
						addBook(inventory,itemCounter);
						itemCounter++;
						
					}
					else if(input.compareToIgnoreCase("gift") == 0)
					{
						addGift(inventory,itemCounter);
						itemCounter++;
					}
					else
						System.out.println("Invalid Command");
				}
				else
					System.out.println("inventory is full (15 items reached) ");
			}
			
			//purchases all of the quantity in the item
			else if ( input.compareToIgnoreCase("purchase") == 0 && itemCounter != 0)
			{
				System.out.print("purchase item (enter id): ");
				int idChosen = sc.nextInt();
				sc.nextLine();
				
				if (purchaseItem(inventory, itemCounter, idChosen) ) 
				{
					System.out.print("\nSuccesfuly Purchased");
				}
				else
					System.out.print("\nItem is out of stock or inputed invalid id entered");
				
			}
			
			//removes a specified item by id the user inputed
			else if (input.compareToIgnoreCase("remove") == 0 && itemCounter != 0)
			{
				System.out.print("remove item (enter id): ");
				int idChosen = sc.nextInt();
				sc.nextLine();
				
				if( removeItem(inventory, itemCounter,idChosen ))
				{
					System.out.print("\nItem Succesfuly Removed");
					itemCounter--;
				}
				else
					System.out.print("\nThis item has already been removed or invalid id entered");
			}
			
			//displays the inventory
			else if ( input.compareToIgnoreCase("display") == 0)
			{	
				System.out.print("All, Books, Gifts: ");
				input = sc.next();
				sc.nextLine();
				System.out.println();
				
				//if user enters all it displays it all
				if(input.compareToIgnoreCase("all") == 0)
				{
					displayItems(inventory, itemCounter);
				}
				//if user inputs books it displays the books in order by author name
				else if(input.compareToIgnoreCase("books") == 0)
				{
					displayBooks(inventory, itemCounter);
				}
				//if the user inputed gifts it displays all the gifts by label
				else if(input.compareToIgnoreCase("gifts") == 0)
				{
					displayGifts(inventory, itemCounter);
				}
				//prompts user inputed invalid command
				else
				{
					System.out.println("Invalid Command");
				}
					
			}
			
			//checks if user inputed exit, if so it will exit the loop
			else if (input.compareToIgnoreCase("exit") == 0)
			{
				exit = true;
			}
			
			//if user wants to save there inventory in file it will save it to a file
			else if(input.compareToIgnoreCase("save") == 0 && itemCounter != 0)
			{
				FileOutputStream fos = new FileOutputStream("test.txt");
				ObjectOutputStream oos = new ObjectOutputStream(fos);
				oos.writeObject(inventory);
				oos.close();
				fos.close();
				
			}
			
			//if user wants to load on a previous saved file then it will load from files
			else if(input.compareToIgnoreCase("load") == 0 )
			{
				FileInputStream fis = new FileInputStream("test.txt");
				ObjectInputStream ois = new ObjectInputStream(fis);	
				inventory =  (item[]) ois.readObject();			
				ois.close();
				fis.close();
				
				//loop used to count the number of items because it will not load that from file
				for(int i = 0 ; i < inventoryCapacity; i++)
				{
					if( inventory[i] != null)
							itemCounter++;
				}
				
				//this is just an arbitrary set for the counter since counter is static it changes for all classes
				inventory[0].setCounter(itemCounter);
			}		
			else
				System.out.print("\nInvalid Command or attempt to remove,purchase, or save when inventory is empty");
			
			
		}while( !exit );
		
		System.out.println("\nSuccesfully exited inventory");
		
		sc.close();
	}
	
	/**
	 * purchases an item by user input (id), when purchased I assumed that it zero's out the quantity of that item
	 * @param inventory	
	 * @param itemAmount
	 * @param idChosen
	 * @return	true if something was purchased, false if not
	 */
	private static boolean purchaseItem(item inventory[], int itemAmount, int idChosen)
	{
		//boolean variable used to check if purchased was use or not
		boolean isPurchased = false;
		
		//for loop, loops through inventory to check for user inputs id
		for(int i = 0 ; i < itemAmount; i++)
		{
			//if the input matches one of the inventory id then it will run the purchase function
			if( (inventory[i].getId() == idChosen) && (inventory[i].getQuantity() != 0)  )
			{
				inventory[i].Purchased();
				isPurchased = true;
				break;
			}
		}
		
		//returns if a purchased was used or not
		return isPurchased;
	}
	
	
	/**
	 * removes an item via ID user input, once remove it will shift the item array one over so there isnt a empty sace
	 * @param inventory
	 * @param itemAmount
	 * @param idChosen
	 * @return true if an item was removed and false otherwise
	 */
	private static boolean removeItem(item inventory[], int itemAmount, int idChosen)
	{
		boolean isRemoved = false;
		int i;
		
		//Loops to find desired id correspond to the item to be removed
		for(i = 0 ; i < itemAmount; i++)
		{
			if(inventory[i].getId() == idChosen)
			{
				inventory[i] = null;	
				isRemoved = true;
				break;
			}
		}
		
		//Shifts all element on the right of the removed item in the  array one element to the left iff item was removed
		if(isRemoved)
		{
			for(int y = 0 ; y < itemAmount - (i+1); y++)
			{
				inventory[i + y] = inventory[i + y +1];
			}
		}
		
		//returns true if removed and false if not
		return isRemoved;
	}
	
	/**
	 * Adds a book 
	 * @param inventory
	 * @param i
	 */
	private static void addBook(item inventory[], int i)
	{
		//Variables
		String itemName;
		String itemCreator;
		int bookYear;
		int qtty;
		double price;
		
		Scanner sc = new Scanner(System.in);
		
		//USER PROMPTS
		
		System.out.print("Enter book title: ");
		itemName = sc.nextLine();
		
		System.out.print("Enter book Author: ");
		itemCreator = sc.nextLine();
		
		System.out.print("Enter book year: ");
		bookYear = sc.nextInt();
		sc.nextLine();	//consumes the \n from line prior
		
		System.out.print("Price of this item: ");
		price = sc.nextDouble();
		sc.nextLine();	//consumes the \n
		
		System.out.print("Quantity of this item: ");
		qtty = sc.nextInt();
		sc.nextLine();	//consumes the \n
		
		//Uses book overloaded constructor 
		inventory[i] = new book(itemName, itemCreator, bookYear, qtty, price);
	}
	
	/**
	 * Adds a gift
	 * @param inventory
	 * @param i
	 */
	private static void addGift(item inventory[], int i)
	{
		//Variables
		String label;
		String manufacturer;
		int qtty;
		double price;
		
		Scanner sc = new Scanner(System.in);
			
		//USER PROMPT
		
		System.out.print("Enter gift label: ");
		label = sc.nextLine();
		
		System.out.print("Enter gift manufacturer: ");
		manufacturer = sc.nextLine();
	
		System.out.print("Price of this item: ");
		price = sc.nextDouble();
		sc.nextLine();	//consumes the \n
		
		System.out.print("Quantity of this item: ");
		qtty = sc.nextInt();
		sc.nextLine();	//consumes the \n
		
		//Uses the gift overloaded to create an instance of gift to be stored inside a item array
		inventory[i] = new gift(label, manufacturer, qtty, price);
	}
	
	/**
	 * Displays all the item onto the screen
	 * @param inventory
	 * @param itemCounter
	 */
	private static void displayItems(item inventory[], int itemCounter)
	{
		//prints a header first
		System.out.printf("%-5s%-11s%-15s%s", "ID", "PRICE($)" ,"QTTY", "ITEM");
		
		//loop displays items
		for(int i = 0; i < itemCounter; i++)
		{
				inventory[i].Displayed();
		}
	}
	
	/**
	 * Displays all the books in order by authors name
	 * @param inventory
	 * @param itemAmount
	 */
	private static void displayBooks(item inventory[], int itemAmount)
	{
		//creates a new instance of a book array to store all the instance of book from the item array
		book bookList[] = new book[itemAmount];		
		int numBooks = 0;
		
		//Loops through all of the items and puts the instances of books into the temporary bookList array
		for(int i = 0 ; i < itemAmount; i++)
		{
			if(inventory[i] instanceof book)
			{
				bookList[numBooks] = (book) inventory[i];
				numBooks++;
			}
		}
		
		//Sorts the BookList via bubble sort (by author name)
		for (int x = 0; x < numBooks-1; x++)
		{
			
			for(int y = 0 ; y < numBooks-x-1; y++)
			{
				if(bookList[y].getAuthor().compareToIgnoreCase(bookList[y+1].getAuthor()) > 0  )	
				{
					book temp = bookList[y];
					bookList[y] = bookList[y+1];
					bookList[y+1] = temp;
				}
			}
		}
		
		//Displays the sorted book array
		System.out.printf("%-5s%-11s%-15s%s", "ID", "PRICE($)" ,"QTTY", "ITEM");
		for (int i = 0 ; i < numBooks ; i++)
		{
			bookList[i].Displayed();
		}
		
	}
	
	/**
	 * displays all the gifts by label
	 * @param inventory
	 * @param itemAmount
	 */
	private static void displayGifts(item inventory[], int itemAmount)
	{
		//creates a new instance of a gift array to store all the instance of gift from the item array
		gift giftList[] = new gift[itemAmount];
		int numGifts = 0;
		
		//Loops through all of the items and puts the instances of gifts into the temporary giftList array
		for(int i = 0 ; i < itemAmount; i++)
		{
			if(inventory[i] instanceof gift)
			{
				giftList[numGifts] = (gift) inventory[i];
				numGifts++;
			}
		}
		
		//Sorts the temporary giftList array via bubble sort by labels
		for (int x = 0; x < numGifts-1; x++)
		{
			
			for(int y = 0 ; y < numGifts-x-1; y++)
			{
				if(giftList[y].getLabel().compareToIgnoreCase(giftList[y+1].getLabel()) > 0  )	
				{
					gift temp = giftList[y];
					giftList[y] = giftList[y+1];
					giftList[y+1] = temp;
				}
			}
		}
		
		//displays all sorted gifts
		System.out.printf("%-5s%-11s%-15s%s", "ID", "PRICE($)" ,"QTTY", "ITEM");
		for (int i = 0 ; i < numGifts ; i++)
		{
			giftList[i].Displayed();
		}
	}
}
