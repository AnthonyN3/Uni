package com.anthony;
import java.util.*;

/**
 * This is the main for the whole entire program, it instantiates the invoice which insantiates the items
 * @author Anthony Nguyen
 * @version 1.8
 */


public class CashRegister {
	
	public static void main(String[] args)
	{
		int itemMax = 3;
		
		//instantiates an array of size three to hold three item objects
		Item itm= new Item();
		Invoice myInvoice = new Invoice();
		
		//Instantiates the scanner sc
		Scanner sc = new Scanner(System.in);
		
		//temporary variables used to scan user input in order to set into the object of "Item"
		String name;
		int qtty;
		double price;
		
		//loops used to loop the three items
		for(int i = 0; i < itemMax; i++)
		{
			System.out.printf("Input name of item %d:\n", i+1);	//prompts the user input a item name
			name = sc.nextLine();	//scans the name
			System.out.printf("Input quantity of item %d:\n", i+1); //prompts the user input the item quantity
			qtty = sc.nextInt();	//scans the quantity (integer)
			System.out.printf("Input price of item %d:\n", i+1); //prompts the user for the price of the item
			price = sc.nextDouble();	//scans the price (double)
			
			//This instantiates the object item into the spot of the array (uses overloaded constructor)
			itm.setName(name);
			itm.setQuantity(qtty);
			itm.setPrice(price);
			
			//Adds the item that was just instantiated into the invoice
			myInvoice.addItem(itm);
			
			sc.nextLine();	//clears the "\n" in the buffer 
		}
		
		//prints the entire table/chart of the invoice!
		System.out.println(myInvoice);
		
		//closes the scanner object
		sc.close();
	}
}
