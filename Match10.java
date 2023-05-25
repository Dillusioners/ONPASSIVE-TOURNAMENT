/*
 * Author - Tommyshe;by
 * Date - 25 - 5 - 2023
 * purpose - user finds words in grid
 */

//imports
import java.util.Scanner;
import java.util.Arrays;
import java.io.BufferedReader;
import java.io.FileReader;

public class Match10 {
	// input obj
	Scanner in;

	Match10() {
		in = new Scanner(System.in);
	}

	void putToArray(Scanner obj) {
		// Gets grid rows
		System.out.println("Enter rows in grid : ");
		int rows = in.nextInt();

		// Gets grid coloumns
		System.out.println("Enter coloumns : ");
		int coloumns = in.nextInt();

		// Gets grid into array
		String[][] grid = new String[rows][coloumns];
		while (obj.hasNextLine()) {
			for (int i = 0; i < grid.length; i++) {
				String[] line = obj.nextLine().trim().split(" ");
				for (int j = 0; j < line.length; j++) {
					grid[i][j] = line[j];
				}
			}
		}
		// Prints array
		System.out.println(Arrays.deepToString(grid));
	}

	public static void main(String[] args) {
		Match10 obj = new Match10();

		// Get path file
		System.out.println("Enter the path of file containing grid : ");
		String path = obj.in.nextLine();

		try {
			// Try catch for file not found condition
			Scanner sc = new Scanner(new BufferedReader(new FileReader(path)));
			obj.putToArray(sc);
		} catch (Exception FileNotFoundException) {
			System.out.println("File not found !");
		}
		// Please idk bfs or dfs
		System.out.println("Come on find the words yourself!!!I support you!");

	}
}