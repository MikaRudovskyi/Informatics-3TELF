// Developer m1rskiy - 04.06.2024

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

#define UNSOLD 0
#define SOLD 1
#define HOME 2
#define HOTEL 3

#define N_PLAYERS 3

#define N_PROPERTIES 16

using namespace std;

class Dice 
{
    public:
        int throW()
		{
            srand(time(0));
            return rand() % 6 +1;
        }
};

class Plot 
{
    public:
        string name;
        string color;
        int buyPrice;
        int homePrice;
        int hotelPrice;
        int baseGain;
        int homeGain;
        int hotelGain;
        int property;
        int ownerID;
        
        Plot(string n, string c, int bp, int hmp, int hlp, int bg, int hmg, int hlg) 
		{
            name = n;
            color = c;
            buyPrice = bp;
            homePrice = hmp;
            hotelPrice = hlp;
            baseGain = bg;
            homeGain = hmg;
            hotelGain = hlg;
            property = UNSOLD;
            ownerID = -1;
        }
        
        void showInfo() 
		{
            cout << "+---------------------------------------------+" << endl;
            cout << "| Name: " << name << endl;
            cout << "| Color: " << color << endl;
            cout << "| Buy price: " << buyPrice << endl;
            cout << "| Price for home: " << homePrice << endl;
            cout << "| Price for hotel: " << hotelPrice << endl;
            cout << "| Base gain: " << baseGain << endl;
            cout << "| Gain for home: " << homeGain << endl;
            cout << "| Gain for hotel: " << hotelGain << endl;
            cout << "| Status: " << property << endl;
            
            if(property != UNSOLD) 
			{
                cout << "| Owner ID: " << ownerID << endl;
            }
            
            cout << "+---------------------------------------------+" << endl;
        }
        
        int getGain() 
		{
            switch(property) 
			{
                case SOLD: 
				{
                    return baseGain;
                }
                case HOME: 
				{
                    return homeGain;
                }
                case HOTEL: 
				{
                    return hotelGain;
                }
            }
            return 0;
        }
        
        int getUpgradeCost() 
		{
            switch(property) 
			{
                case SOLD: 
				{
                    return homePrice;
                }
                case HOME: 
				{
                    return hotelPrice;
                }
            }
            return 0;
        }
        
        void upgrade() 
		{
            switch(property) 
			{
                case SOLD: 
				{
                    property = HOME;
                    break;
                }
                case HOME: 
				{
                    property = HOTEL;
                    break;
                }
            }
        }
};

class Player 
{
    private:
        vector<Plot> _properties;
        int _money;
        bool _isPlaying;
    
    public:
        string nick;
        char symbol;
        
        Player(string n, char s) 
		{
            nick = n;
            symbol = s;
            _money = 500;
            _isPlaying = true;
        }
        
        void addMoney(int toAdd) 
		{
            _money += toAdd;
        }
        
        void subMoney(int toSubtract) 
		{
            _money -= toSubtract;
        }
        
        void addProperty(Plot &newProperty) 
		{
            newProperty.property = SOLD;
            _properties.push_back(newProperty);
        }

        int getMoney() 
		{
            return _money;
        }
};

class City
{
    private:
        void _createField() 
		{
            Plot plot1("Go", "Null", 0, 0, 0, 0, 0, 0);

            Plot plot2("Via_Malignani", "red", 100, 200, 300, 50, 100, 150);
            Plot plot3("Via_Sello", "red", 100, 200, 300, 50, 100, 150);
            Plot plot4("Via_Copernico", "red", 100, 200, 300, 50, 100, 150);

            Plot plot5("Jail", "Null", 0, 0, 0, 0, 0, 0);

            Plot plot6("Via_Marte", "green", 100, 200, 300, 50, 100, 150);
            Plot plot7("Via_Giove", "green", 100, 200, 300, 50, 100, 150);
            Plot plot8("Via_Saturno", "green", 100, 200, 300, 50, 100, 150);

            Plot plot9("Chance", "Null", 0, 0, 0, 0, 0, 0);

            Plot plot10("Via_Cielo", "blue", 100, 200, 300, 50, 100, 150);
            Plot plot11("Via_Mare", "blue", 100, 200, 300, 50, 100, 150);
            Plot plot12("Via_Terra", "blue", 100, 200, 300, 50, 100, 150);

            Plot plot13("Go_to_Jail", "Null", 0, 0, 0, 0, 0, 0);

            Plot plot14("Via_OnePiece", "yellow", 100, 200, 300, 50, 100, 150);
            Plot plot15("Chance", "Null", 0, 0, 0, 0, 0, 0);
            Plot plot16("Via_Malignani", "yellow", 100, 200, 300, 50, 100, 150);

            field.push_back(plot1);
            field.push_back(plot2);
            field.push_back(plot3);
            field.push_back(plot4);
            field.push_back(plot5);
            field.push_back(plot6);
            field.push_back(plot7);
            field.push_back(plot8);
            field.push_back(plot9);
            field.push_back(plot10);
            field.push_back(plot11);
            field.push_back(plot12);
            field.push_back(plot13);
            field.push_back(plot14);
            field.push_back(plot15);
            field.push_back(plot16);
        }

    public:
        int playerPositions[N_PLAYERS];
        vector<Plot> field;

        City() 
		{
            // All players start from position 0
            for(int i = 0; i < N_PLAYERS; i++) 
			{
                playerPositions[i] = 0;
            } 

            _createField();
        }
};

void showPositions(City monopoly, vector<Player> players) 
{
    system("cls");
    cout << "Player positions:" << endl;

    for(int i = 0; i < N_PLAYERS; i++) 
	{
        cout << " " << players[i].nick << "; Position no. " << monopoly.playerPositions[i] << endl;
    }
}

int main() 
{
    Player p1("Franky", '$');
    Player p2("Jimmy", '?');
    Player p3("Trevor", '0');

    vector<Player> players;
    players.push_back(p1);
    players.push_back(p2);
    players.push_back(p3);
    
    City monopoly;

    int turn = 0;

    Dice d6;

    while(true) 
	{
        showPositions(monopoly, players);

        cout << "Player's turn " << players[turn].nick << endl;
        cout << " Money: " << players[turn].getMoney() << endl;
        
        int actualPosition = monopoly.playerPositions[turn];
        
        if(monopoly.field[actualPosition].name == "Jail") 
		{
            cout << "You are in jail, throw 2 dice" << endl;
            
            int dice1 = d6.throW();
            int dice2 = d6.throW();
            
            cout << "Result: " << dice1 << "-" << dice2 << endl;
            
            if(dice1 != dice2) 
			{
                cout << "Stay in jail" << endl;
                continue;
            } 
			else 
			{
                cout << "Get out of jail! Continue your turn..." << endl;
            }
        }
        
        int jump = d6.throW();
        int newPosition = (actualPosition + jump) % N_PROPERTIES;
        
        cout << "You have landed on position number " << newPosition << ":" << endl;
        monopoly.field[newPosition].showInfo();
        
        if(monopoly.field[newPosition].color == "NULL") 
		{
            // Special Plot
            if(monopoly.field[newPosition].name == "Chance") 
			{
                int accidentID = rand() % 3;
                
                if(accidentID == 0) 
				{
                    cout << "Chance! You earn 50 euros!" << endl;
                    players[turn].addMoney(50);
                } 
				else if(accidentID == 1) 
				{
                    cout << "Chance! You lose 100 euros!" << endl;
                    players[turn].subMoney(100);
                } 
				else if(accidentID == 2) 
				{
                    cout << "Chance! Go back 2 positions" << endl;
                    newPosition = newPosition - 2;
                }
            } 
			else if(monopoly.field[newPosition].name == "Go") 
			{
                cout << "You are back at the start, you earn 200 euros" << endl;
                players[turn].addMoney(200);
            } 
			else if(monopoly.field[newPosition].name == "Go_to_Jail") 
			{
                cout << "Go to jail!" << endl;
                newPosition = 4; // position of the jail
            } 
			else if(monopoly.field[newPosition].name == "Jail") 
			{
                cout << "You have landed in jail!" << endl;
                cout << "From the next turn, throw 2 equal dice to get out." << endl;
            }
        } 
		else 
		{
            // Property Plot
            if(monopoly.field[newPosition].property == UNSOLD) 
			{
                cout << "The plot is free, do you want to buy it [Y/N]" << endl;
                
                char choice;
                cin >> choice;
                
                if(choice == 'Y') 
				{
                    int cost = monopoly.field[newPosition].buyPrice;
                    
                    if(players[turn].getMoney() >= cost) 
					{
                        players[turn].addProperty(monopoly.field[newPosition]);
                        players[turn].subMoney(cost);
                        monopoly.field[newPosition].ownerID = turn;
                        cout << "The property is yours" << endl;
                    }
                }
            } 
			else 
			{
                int ownerID = monopoly.field[newPosition].ownerID;
                cout << "The plot belongs to " << players[ownerID].nick << endl;
                
                if(turn == ownerID) 
				{
                    // The plot belongs to the current player
                    if(monopoly.field[newPosition].property != HOTEL) 
					{
                        // The player can upgrade the building
                        cout << "You can upgrade your building." << endl;
                        int cost = monopoly.field[newPosition].getUpgradeCost();
                        
                        cout << "The cost is euros " << cost << endl;
                        cout << "Do you want to proceed? [Y/N]" << endl;
                        
                        char choice;
                        cin >> choice;
                        
                        if(choice == 'Y') 
						{
                            monopoly.field[newPosition].upgrade();
                            players[turn].subMoney(cost);
                            cout << "You have upgraded your building" << endl;
                        }
                    } 
					else 
					{
                        cout << "You have already built a Hotel, you cannot do more" << endl;
                    }
                } 
				else 
				{
                    // The plot belongs to another player
                    int cost = monopoly.field[newPosition].getGain();
                    players[turn].subMoney(cost);
                    players[ownerID].addMoney(cost);
                    cout << "You have to pay " << cost << " euros to " << players[ownerID].nick << endl;
                }
            }
        }
        
        monopoly.playerPositions[turn] = newPosition;
        
        turn = (turn + 1) % N_PLAYERS;

        system("pause");
    }

    return 0;
}
