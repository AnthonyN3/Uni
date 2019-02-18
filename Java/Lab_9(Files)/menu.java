package com.iofile;
import javax.swing.*;

import java.awt.Container;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.*;

public class menu extends JFrame {
	private JButton tempButton;
	private JButton[][] menuArray= new JButton[4][1];
	private Container pane = new Container();
	private final static String[] wordList = {"Enter a record","Read file and display","Navigate","Exit"};
	
	public menu() {
		pane=getContentPane();
		pane.setLayout(new GridLayout(4,1));
		setSize(400,400);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setResizable(false);
		setVisible(true);
		
		for(int i=0;i<4;i++) {
			tempButton = new JButton();
			tempButton.setFont(new Font("SANS_SERIF",Font.PLAIN, 24));
			tempButton.setForeground(Color.RED);
			menuArray[i][0]= tempButton;
			tempButton.setText(wordList[i]);
			pane.add(tempButton);
		}
		
		menuArray[0][0].addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent e) {
				System.out.println("Hello");
			
					}
				}	
				
		);

		menuArray[1][0].addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
			System.out.println("Dude");
		
				}
			}	
			
		);
		
		menuArray[2][0].addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
			System.out.println("World");
		
				}
			}	
			
		);
		
		menuArray[3][0].addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
			System.out.println("Okai");
		
				}
			}	
			
		);



		
	}
	

	
	public static void main(String[] args) {
		new menu();
		
	}
}
