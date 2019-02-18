/**
 * @author Anthony Nguyen
 */

package com.anthony;

import java.util.Scanner;

public class Exercise3 {
	
	public static void main(String[] Args) {
		
		Scanner input = new Scanner(System.in);
		
		int number, FH;
		char chara ; 
		System.out.println("Enter int 1-20:");
		number = input.nextInt();
		input.nextLine();				//Do this so it consumes the "\n"
		
		if (number <1 || number >20) {
			System.out.println("Error::");
		}
		
		
		
		System.out.println("Enter character :" );
		chara = input.nextLine().charAt(0);						//IF I HAD JUST PUT input.next().charAt(0), 
																//THEN I WOULDNT NEED THAT "input.nextLine();" 
		System.out.println("fill or nah? 1, 0");				// AT LINE 19 (FYI)
		FH = input.nextInt();
		
		if (FH == 1) {
		//fill
			for(int i = 0; i<number; i++) {
				for(int x = 0; x <number ; x++) {
					System.out.print(chara);
				}
				System.out.println();
			}
			
		}
		
		else if (FH ==0) {
			for (int i = 0; i <number; i++) {
				if(i == 0 || i ==(number-1)) {
					for (int x = 0; x <number; x++) {
						System.out.print(chara);
					}
				}
				else {
					for (int x = 0 ; x <number ; x++) {
						if (x ==0 || x == (number-1)) {
							System.out.print(chara);
						}
						else {
							System.out.print(" ");
						}
					}
				}
				System.out.print ("\n");
			}
			input.close();
		}	
	}
}
