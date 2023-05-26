import java.util.Scanner;
import java.io.*;

public class Match19 {
	//Member variables
	String Story; // The story line
	Scanner sc ;

	Match19() {
		sc = new Scanner(System.in);
		//Writing down the story
		Story = "You are a human who falls into the underground, a world of monsters that was sealed away from the human world long ago.\n As you explore this strange new world, you find out that the monsters are not as wicked as you had been led to believe. \nAlong the way, you meet different monsters who can either be friendly or hostile to you, depending on how you want to play the game. You can choose to fight the monsters or show them mercy, and your actions will affect the relationships you build throughout the game. ";
	}

	//Just a method to slowly print strings to give the code that old gaming vibes
	void slowPrint(String text, int speed) throws InterruptedException, IOException{
      Writer w = new PrintWriter(System.out);
      for(int t = 0; t < text.length(); t++) {
      	System.out.print(text.charAt(t));
        w.flush();
        Thread.sleep(speed);
      }
    }

    // Header kinda
    void display() {
    	System.out.println("\n================UNDEGROUND BIZZARE ADVENTURE================\n");
    }

    //Thep pacifist story line
    void Pacifist()throws InterruptedException, IOException {
    	slowPrint("\n\nYou spend time with the monsters and come to like their nature. But you seem to have suddenly remembered about your own world of humans !\n",40);
    	System.out.println("1.Stay with the monsters for the end of your life ?\n2.Try to go back to the human world\nEnter your choice = ");
    	while(true) {
    		int choice = sc.nextInt();
    		if(choice == 1){
    			// Pacifist choice : peaceful
    			slowPrint("\nYou lived your life with the monsters till your death !",40);
    			break;
    		}
    		else if(choice == 2) {
    			//Pacifist choice : escape
    			slowPrint("\nYou wander through the realm to find your way back but fall in a pond\nWhen you wake up, you seem to be sleeping in your bed\nIT WAS ALL A DREAM !!!!!",40);
    			break;
    		}else {
    			// Invalid choice
    			System.out.println("Invalid Choice !!");
    		}
    	}
    }

    void Neutralist()throws InterruptedException, IOException {
    	// Neutralist single action : become the others
    	slowPrint("\n\nYou live in silence and slowly become one of their own kind,a monster !!!",40);
    }

    void Assertive()throws InterruptedException, IOException {

    	slowPrint("\n\nYou keep on slaying the demons, the strong, the weak, the old....You finally meet papyrus who slays you down\nAs you pass away he gives you two choices ....\n",40);
    	System.out.println("1.Become a monster yourself and spend your days in subtlety?\n2.Die peacefully...\nEnter your choice = ");
    	while(true) {
    		int choice = sc.nextInt();
    		if(choice == 1){
    			//Assertive choice : submission
    			slowPrint("\nYou became a monster priest and now worship the monster god !",40);
    			break;
    		}
    		else if(choice == 2) {
    			// Assertive choice : realization
    			slowPrint("\nYou die...As you die you see the visions of the kind monsters and realize your grave mistake...",40);
    			break;
    		}else {
    			System.out.println("Invalid Choice !!");
    		}
    	}
    }

    // Game starts here

    void startingPivot()throws InterruptedException, IOException{
    	
    	slowPrint(Story,40);
    	//General story and user choice to 3 main sub stories
    	System.out.println("\n\n\nYou have 3 choices : "
    					  + "\n1.Pacifist : You deal with the monsters with a feeling of empathy...."
    					  + "\n2.Neutral : You dont seem to care at all about anything and want to spend your life in the pit, living in pure ignorance and loneliness...." 
    					  + "\n3.Assertive : Even after meddling with the well behaved \'demons\' you still hold your beliefs back from the human realm and wish to slay the demons and get back to your world"
    					  +"Enter your choice => ");
    	int choice = 0;
    	while(choice < 1 || choice > 3) {
    		choice = sc.nextInt();
    		if(choice < 1 || choice > 3)
    			System.out.println("Not an option !");
    	}
    	if(choice == 1) {
    		Pacifist();
    	}else if(choice == 2) {
    		Neutralist();
    	}else {
    		Assertive();
    	}
    }
    //Main method
	public static void main(String[] args)throws InterruptedException, IOException {
		Match19 obj = new Match19();
		//Displays story header/ title
		obj.display();
		//Starts the game
		obj.startingPivot();
	}
}