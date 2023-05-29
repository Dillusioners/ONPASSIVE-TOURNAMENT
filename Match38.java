/**
 * Author - Debag101
 * Purpose - Hotel reservation
 * Date - 29 - 5 - 2023
 * */

import java.util.Scanner;
import java.util.Random;
import java.util.ArrayList;

public class Match38 {

	ArrayList<Integer> available_tables = new ArrayList<Integer>();// Stores available tables
	ArrayList<Integer> reserved_tables = new ArrayList<Integer>(); // Stores reserved tables
	int price; // Stores total purchase by user

	Match38() {
		//Initialising price to 0 and getting random available tables
		price = 0;
		table_generator();
	}

	//Generates random table numbers
	void table_generator() {
		Random rand = new Random();
		for(int i = 1; i < 51; ++i) {
			if(rand.nextBoolean()) // Uses the random boolean generator method from the util package
				available_tables.add(i);
		}
	}


	// Displays context to user
	void display_available_tables() {
		System.out.println("=================AVAILABLE TABLES=================\n");
		System.out.println(available_tables);
		System.out.println("\nRate for each table is 50$/hour.");
	}


	// Gets the tables user wants to reserve
	void reserve_tables() {
		Scanner sc = new Scanner(System.in);
		while(true) {
			System.out.println("\nEnter the table number you want or 0 to exit!");
			try {
				int table_num = sc.nextInt();
				if(table_num == 0) // 0 to exit reservation
					break;
				else if(!reserved_tables.contains(table_num) && available_tables.contains(table_num)) {
					System.out.println("Enter time for which you want reservation in hours : ");
					int time = sc.nextInt();
					if(time < 0) 
					{
						System.out.println("Request not possible ");
					}else {
						reserved_tables.add(table_num);
						price += 50 * time;
					}
				}else {
					System.out.println("Table has already been reserved or doesnt exist !");
				}
			}catch(Exception NumberFormatException) {
				System.out.println("Such a table is not available !");
			}
		}
		sc.close();

	}


	// Displaying users bills
	void display_bill() {
		System.out.println("Your total bill is " +price + "$ for reserving following tables");
		System.out.println(reserved_tables);
	}

	// Calling all methods in main
	public static void main(String[] args) {
		Match38 obj = new Match38();
		obj.display_available_tables();
		obj.reserve_tables();
		obj.display_bill();
	}

}