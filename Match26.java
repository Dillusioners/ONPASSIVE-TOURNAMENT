/*
 * Author - debaf
 * purpose - contact manager
 * date - 27 - 05 - 2023
 * 
 * NB - sorry I couldnt finish code due to technical difficulties
 */

import java.io.*;
import java.util.*;
import java.util.ArrayList;

public class Match26 {

    ArrayList<String> contactList;

    Match26() throws IOException {
        File contact_File = new File("contact.txt");
        contactList = new ArrayList<String>();
        if (!contact_File.exists()) {
            contact_File.createNewFile();
        }

        try {
            File myObj = new File("contact.txt");
            Scanner myReader = new Scanner(myObj);
            while (myReader.hasNextLine()) {
                String data = myReader.nextLine();
                contactList.add(data);
            }
            myReader.close();
        } catch (FileNotFoundException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
    }

    void display_functions() {
        System.out.println("====================CONTACT MANAGER====================\n");
        System.out.println("1. Add Contact\n2. Edit Contact\n3. Delete Contact\n4. Exit\nEnter your purpose => ");
    }

    private void addContact() throws FileNotFoundException {
        PrintWriter out = new PrintWriter("contact.txt");
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter name of contact holder: ");
        String name = sc.nextLine();

        System.out.println("Enter the associated contact info of user: ");
        String ct = sc.next();

        contactList.add(name + "+" + ct);
        for(int i = 0; i < contactList.size(); i++) {
            out.println(contactList.get(i));
        }

        sc.close();
        out.close();
    }

    private void editContact() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter contact number or user to be edited : ");
        String editContact = sc.next();
        String holdEdit = "";
        for(int i = 0; i < contactList.size(); i++)
        {
            String[] arr = contactList.get(i).split("+");
            if(arr[0] == editContact || arr[1] == editContact)
            {
                System.out.println("Enter new contact name : ");
                holdEdit += sc.next() + "+";
                System.out.println("Enter new contact : ");
                holdEdit += sc.next();
                contactList.add(i, holdEdit);
                return;
            }
            
        }
        System.out.println("Contact not found!");
        

    }

    private void deleteContact() {
        System.out.println("not implemented yet !stay tuned");
    }

    public static void main(String[] args) throws IOException {
        Match26 obj = new Match26();
        Scanner sc = new Scanner(System.in);
        obj.display_functions();
        try {
            int user_function = sc.nextInt();
            if (user_function == 4)
                System.out.println("OK Terminating program.....");
            else if (user_function == 1)
                obj.addContact();
            else if (user_function == 2)
                obj.editContact();
            else if (user_function == 3)
                obj.deleteContact();
            else
                System.err.println("Invalid Input!");
        } catch (Exception NumberFormatException) {
            System.out.println("Please enter valid input!");
        }

        sc.close();
    }
}
