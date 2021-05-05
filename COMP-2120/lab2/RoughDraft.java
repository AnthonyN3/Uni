package com.anthony;

public class RoughDraft {
	
/*	public static void main(String[] args)
	{
		Item i1 = new Item();
		Item i2 = new Item();
		Item i3 = new Item();
		
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Input name of item 1:");
		i1.setName(sc.nextLine());
		System.out.println("Input quantity of item 1:" );
		i1.setQuantity(sc.nextInt());
		System.out.println("Input price of item 1:");
		i1.setPrice(sc.nextDouble());
		
		sc.nextLine();
		System.out.println("Input name of item 2:");
		i2.setName(sc.nextLine());
		System.out.println("Input quantity of item 2:" );
		i2.setQuantity(sc.nextInt());
		System.out.println("Input price of item 2:");
		i2.setPrice(sc.nextDouble());
		
		sc.nextLine();
		System.out.println("Input name of item 3:");
		i3.setName(sc.nextLine());
		System.out.println("Input quantity of item 3:" );
		i3.setQuantity(sc.nextInt());
		System.out.println("Input price of item 3:");
		i3.setPrice(sc.nextDouble());
		
		Invoice myInvoice = new Invoice();
		myInvoice.addItem(i1);
		myInvoice.addItem(i2);
		myInvoice.addItem(i3);
		
		System.out.println("\nYour bill:");
		System.out.println(String.format( "%-30s%10s%10s", "Item", "Quantity","Total" ));
		
		System.out.println(String.format( "%-30s%10s%10s", i1.getName(), i1.getQuantity(),i1.getPrice()));
		System.out.println(String.format( "%-30s%10s%10s", i2.getName(), i2.getQuantity(),i2.getPrice()));
		System.out.println(String.format( "%-30s%10s%10s", i3.getName(), i3.getQuantity(),i3.getPrice()));
		
		System.out.println(myInvoice);
		
		sc.close();
	}*/
}
	
/*
package com.anthony;

import java.util.*;

public class CashRegister {
	
	public static void main(String[] args)
	{
		Item []itmList= new Item[3];
		Invoice myInvoice = new Invoice();
		
		Scanner sc = new Scanner(System.in);
		
		for(int i = 0; i < 3; i++)
		{
			System.out.printf("Input name of item %d:\n", i+1);
			itmList[i].setName(sc.nextLine());
			System.out.printf("Input quantity of item %d:\n", i+1 );
			itmList[i].setQuantity(sc.nextInt());
			System.out.printf("Input price of item %d:\n", i+1);
			itmList[i].setPrice(sc.nextDouble());
			myInvoice.addItem(itmList[i]);
		}
		
		sc.close();
	}
}
*/
