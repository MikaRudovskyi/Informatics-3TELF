// Developer - m1rskiy
// Date: 30.05.2024
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

class Item 
{
	public:
	    string name;
	    float weight;
	    int healthPt;
	    int damagePt;
	    float price;
	    
	    Item(string n, float w, int h, int d, float p) 
		{
	        name = n;
	        weight = w;
	        healthPt = h;
	        damagePt = d;
	        price = p;
	    }
	    
	    Item() 
		{
	        name = "";
	        weight = 0;
	        healthPt = 0;
	        damagePt = 0;
	        price = 0;
	    }
	    
	    void showInfo() 
		{
	        cout << name << endl;
	        cout << "  Weight: " << weight << endl;
	        cout << "  Health Points: " << healthPt << endl;
	        cout << "  Damage Points: " << damagePt << endl;
	        cout << "  Price: " << price << endl;
	    }
};

class Player 
{
	public:
	    string nick;
	    vector<Item> backpack;
	    int lifePt;
	    int manaPt;
	    int coins;
	    
	    Player(string n, int c) 
		{
	        nick = n;
	        coins = c;
	        lifePt = 100;
	        manaPt = 100;
	    }
	    
	    void showInfo() 
		{
			cout << "====================" << endl;
	        cout << "| " << nick << endl;
	        cout << "| Life: " << lifePt << endl;
	        cout << "| Mana: " << manaPt << endl;
	        cout << "| Coins: " << coins << endl;
	        cout << "====================" << endl;
	        
	        for (int i = 0; i < backpack.size(); i++) {
	        	
	            backpack[i].showInfo();
	        }
	    }
	    
	    void addToBackpack(Item newItem) 
		{
	        backpack.push_back(newItem);
	    }
};

class Dungeon 
{
	public:
	    int room1(Player &p) 
		{
	        cout << "You are at the entrance, and you find two items: a sword and a medkit. Do you take them? [y/n]" << endl;
	        char choice;
	        cin >> choice;
	        
	        if (choice == 'y') 
			{
	            Item o1("Sword", 5, 4, 3, 2);
	            Item o2("Medkit", 50, 40, 30, 20);	
	            p.addToBackpack(o1);
	            p.addToBackpack(o2);
	            cout << "Items added to your backpack" << endl;			
	        }
	        
	        cout << "You see a corridor ahead..." << endl;
	        system("pause");
	        
	        return 2;
	    }
	    
	    int room2(Player &p) 
		{
	        cout << "You are in a long corridor and you see 2 doors. CHOOSE:" << endl;
	        cout << "1. Door to your left" << endl;
	        cout << "2. Door in front of you" << endl;
	        
	        int door;
	        cin >> door;
	        
	        if (door == 1) 
			{
	            cout << "The door to your left starts to open..." << endl;
	            return 3; // riddle
	        } else if (door == 2) {
	            cout << "The door in front of you slowly opens..." << endl;
	            return 5; // dragon
	        }
	        
	        return 0;
	    }
	    
	    int room3(Player &p) 
		{
	        cout << "You are in a dark room and hear a voice..." << endl;
	        cout << "What color is Napoleon's white horse?" << endl;
	        string solution;
	        cin >> solution;
	        
	        while (solution != "white") 
			{
	            cout << "You're wrong. Drop 10 coins on the ground" << endl;
	            p.coins -= 10;
	            cout << "Try again" << endl;	
	            cin >> solution;
	        }
	        
	        cout << "You answered correctly. You can proceed to the next room." << endl;
	        return 4;
	    }
	    
	    int room4(Player &p) 
		{
	        cout << "You enter the room and see a small goblin in front of you" << endl;
	        int goblinLife = 20;
	        
	        srand(time(0));
	        
	        int probability;
	        
	        while (goblinLife > 0) 
			{
	            cout << "Choose: " << endl;
	            cout << "1. Attack" << endl;
	            cout << "2. Heal" << endl;
	            
	            int choice;
	            cin >> choice;
	            
	            if (choice == 1) 
				{
	                probability = rand() % 100;
	                
	                if (probability < 90) 
					{
	                    goblinLife -= 5;
	                    cout << "You hit" << endl;
	                    cout << "Your enemy has " << goblinLife << " HP left" << endl;
	                } else 
					{
	                    cout << "You missed the target" << endl;
	                }
	            } 
				else if (choice == 2) 
				{
	                p.lifePt += 40;
	                cout << "You healed yourself, now your life is: " << p.lifePt << " HP" << endl;
	            }
	            
	            cout << "Your enemy's turn" << endl;
	            probability = rand() % 100;
	            
	            if (probability > 50) 
				{
	                cout << "The enemy hits you" << endl;
	                p.lifePt -= 15;
	                cout << "Now your life is: " << p.lifePt << " HP" << endl;
	            } 
				else 
				{
	                cout << "The enemy missed you" << endl;
	            }
	        }
	        
	        cout << "You defeated your enemy and open the door in front of you" << endl;
	        
	        return 5;
	    }
	    
	    int room5(Player &p) 
		{
	        cout << "You enter a room filled with treasure chests. There are three chests in front of you. Choose one:" << endl;
		    cout << "1. Golden chest" << endl;
		    cout << "2. Silver chest" << endl;
		    cout << "3. Wooden chest" << endl;
		
		    int choice;
		    cin >> choice;
		
		    if (choice == 1) 
			{
		        cout << "You open the golden chest and find a heap of coins. You gain 100 coins!" << endl;
		        p.coins += 100;
		    } 
			else if (choice == 2) 
			{
		        cout << "You open the silver chest and find a valuable gem. You gain 50 coins!" << endl;
		        p.coins += 50;
		    } 
			else if (choice == 3) 
			{
		        cout << "You open the wooden chest and find some useful supplies. You gain a medkit!" << endl;
		        Item o("medkit", 50, 40, 30, 20);
		        p.addToBackpack(o);
		    }
		
		    return 6;	
	    }
	    
	    int room6(Player &p) 
		{
	        cout << "You have reached the final room. Before you stands a powerful wizard guarding the exit." << endl;
		    cout << "Prepare for the ultimate battle!" << endl;
		
		    int wizardLife = 100;
		    srand(time(0));
		
		    while (wizardLife > 0 && p.lifePt > 0) 
			{
		        cout << "Choose: " << endl;
		        cout << "1. Attack" << endl;
		        cout << "2. Use magic" << endl;
		
		        int choice;
		        cin >> choice;
		
		        if (choice == 1) 
				{
		            int damage = rand() % 20 + 10;
		            wizardLife -= damage;
		            cout << "You strike the wizard with your weapon dealing " << damage << " damage!" << endl;
		        } 
				else if (choice == 2) 
				{
		            if (p.manaPt >= 20) 
					{
		                int damage = rand() % 30 + 20;
		                wizardLife -= damage;
		                p.manaPt -= 20;
		                cout << "You cast a powerful spell and deal " << damage << " damage to the wizard!" << endl;
		            } 
					else 
					{
		                cout << "You don't have enough mana to cast a spell!" << endl;
		            }
		        }
		
		        if (wizardLife > 0) 
				{
		            int wizardAttack = rand() % 30 + 10;
		            p.lifePt -= wizardAttack;
		            cout << "The wizard retaliates and hits you with a powerful spell dealing " << wizardAttack << " damage!" << endl;
		        }
		    }
		
		    if (p.lifePt <= 0) 
			{
		        cout << "You have been defeated by the powerful wizard. Game Over!" << endl;
		        
		        return 7; // Game Over
		    } else 
			{
		        cout << "Congratulations! You have defeated the wizard and completed the game!" << endl;
		        return 7; // Victory
		    }	
	    }
};

int main() 
{
    Player p("MartyMcFly", 33);
    
    cout << "**************************************************" << endl;
	cout << "                                                  " << endl;
    cout << "               Welcome to my Game!                " << endl;
    cout << "                                                  " << endl;
    cout << "**************************************************" << endl << endl;
    
    p.showInfo();
    
    Dungeon d;
    
    int actualRoom = d.room1(p);
        
    while (actualRoom != 7) 
	{
        system("pause");
        system("cls");
        p.showInfo();
        
        cout << "You are in room " << actualRoom << endl;
        
        system("pause");
        switch (actualRoom) 
		{
            case 2: 
			{
                actualRoom = d.room2(p);
                break;
            }
            case 3: 
			{
                actualRoom = d.room3(p);
                break;
            }
            case 4: 
			{
                actualRoom = d.room4(p);
                break;
            }
            case 5: 
			{
                actualRoom = d.room5(p);
                break;
            }
            case 6: 
			{
                actualRoom = d.room6(p);
                break;
            }
        }
    }
}
