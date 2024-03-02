#include<iostream>
#include<cstdlib>
#include <time.h>
using namespace std;

class Hanguman{
    private:
    
    string rword;
    string msplaywords[15];

    public:
    int life,n;
    void mainmenu();
    void help();
    void starthangu();
    int level();
    int lettercheck(char, string&);
    Hanguman();
    

};

Hanguman::Hanguman(){
    msplaywords[1] = "flue";
    msplaywords[2] = "cubsprout";
    msplaywords[3] = "prawnjaw";
    msplaywords[4] = "whik";
    msplaywords[5] = "bubbles";
    msplaywords[6] = "weevern";
    msplaywords[7] = "eclipso";
    msplaywords[8] = "valentino";
    msplaywords[9] = "rudy";
    msplaywords[10] = "casanova";
    msplaywords[11] = "caldbunny";
    msplaywords[12] = "saiyam";
    msplaywords[13] = "kiloray";
    msplaywords[14] = "blazebit";
    msplaywords[15] = "bloombat";
}

void Hanguman::mainmenu(){
    system("cls");
    cout << "-_-_-_-_-_-_-_-_--_-_-_-_-_-_-_HANGMAN_-_-_-_-_--_-_-_-_-_-_-_-_-" << endl;
    cout << endl << "1. Start game" << endl;
    cout << "2. Help" << endl;
    cout << "3. Quit" << endl;
            cout << "     +---+" << endl;
            cout << "     |   |" << endl;
            cout << "         |" << endl;
            cout << "         |" << endl;
            cout << "         |" << endl;
            cout << "         |" << endl;
            cout << "   =========" << endl;
    
}

void Hanguman::help(){
    system("cls");
    cout << " -_-_-_-_-_-_-_-_--_-_-_-_-_HELP-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-" << endl;
    cout << endl << endl;
    cout << " Hangman is a minigame where you have to find out the name of the miscrit" << endl;
    cout << " (miscrits are magical creatures similar to pokemons)" << endl;
    cout << " before your life runs out. You play the game by entering letter you think" << endl;
    cout << " is on the name of the miscrit. If you guess the correct letter , the number" << endl;
    cout << " of that letter and position in the word will be revealed. In this way you" << endl;
    cout << " keep on guessing until you run out of life and be hanged or find out the name." << endl;
    cout << endl << "Good luck! , you'll need it ;)";
}

int Hanguman::level() {
    system("cls");
    life = 10;
    cout << "Choose difficulty level" << endl;
    cout << "1> Easy (9 lives, Meow...)" << endl;
    cout << "2> Medium (4 lives, lucky?)" << endl;
    cout << "3> Hard (One miss ,game finish)" << endl;
    cout << "4> Custom (Choose your own fate)";
    cout << endl;
    top:
    cout << "The choice is yours: ";
    int lc;
    cin >> lc;

    if(lc==1)
    {
    life = 9;
    }
    else if(lc==2)
    {
    life = 4;
    }
    else if(lc==3)
    {
    life = 1;
    }
    else if(lc==4)
    {   
        cout << endl << "How many lives you wish to have? > " << endl;
        int custom_life;
        cin >> custom_life;
        life = custom_life;
    }
    else
    {
        cout << endl << "Out of option" << endl ;
        goto top;
    }
    return life;
}

void Hanguman::starthangu(){
    system("cls");
    int attempts = 0;
    char iguess;
    cout << "You have been accused of being a fake Miscrit Master," << endl; 
    cout << "Uncover the name of the miscrit to prove your innocence." << endl;
    cout << "You have " << life << " attempts to uncover the miscrits name." << endl;
    
    // Random word generator

    srand(time(NULL));
	int n = rand() % 15;
	rword = msplaywords[n];

    string unknown = string(rword.length(), '*');

    while(attempts < life)
    {   cout << unknown << endl;
        cout << "What letter will you put your fate in? > ";
        cin >> iguess;

        if(lettercheck(iguess,unknown) == 0)
        {
            cout << endl << "Wrong letter!" << endl;
            attempts++;
        } 
        else 
        {
            cout << endl << "This letter is in the name!" << endl;
        }
        int counter = life - attempts;
        cout << endl << "You have " << counter << " attempts remaining." << endl;
        
        if (unknown == rword)
        {    
            cout << rword;
            cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
            cout << endl << "||You have chanted the name of the miscrit.||";
            cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            break;
        }

        if(attempts == life)
        {
    cout << endl << "You are guilty and shall be hanged!!!" << endl;
    cout << "  +---+" << endl;
    cout << "  |   |" << endl;
    cout << "  O   |" << endl;
    cout << " /|`  |" << endl;
    cout << " / `  |" << endl;
    cout << "      |" << endl;
    cout << "=========" << endl;
        }
        
    }

}

int Hanguman::lettercheck(char guess,string &guessword){
	int i;
	int matches = 0;
	int len = rword.length();
	for (i = 0; i < len; i++)
	{
		// Did we already match this letter in a previous guess?
		if (guess == guessword[i])
			matches++;
		// Is the guess in the secret word?
		if (guess == rword[i])
		{
			guessword[i] = guess;
			matches++;
		}
	}
	return matches;
}


int main(){


 Hanguman hang;

 int choice;

    do
    {
        system("cls");
        hang.mainmenu();
        cout<<"Enter your choice (1/2/3): ";
        cin>>choice;

        if (choice == 1)
        {
            char ch;
            hang.level();
            do {
                hang.starthangu();
                cout<<"Want to play again? (y/n): ";
                cin>>ch;
            } while (ch == 'y' or ch == 'Y');
        }
        else if (choice == 2)
        {
            hang.help();
            cout << endl;
                char cc;
        cout << "(Enter any letter to continue)";
        cin >> cc;
        hang.mainmenu();
        ;
        }
        else if (choice == 3)
        {
            cout<<"Bye bye"<<endl;
        }
        else
        {
            cout<<"Invalid choice"<<endl;
        }
    } while (choice != 3);

    return 0;
}
