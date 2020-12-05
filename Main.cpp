#include <iostream>
#include <cstdlib>
#include <ctime>
#include<windows.h>


struct Character { //character stats
    int hp;
    int atk;
    int warpstk;
    int heal;
    int mana;
};

struct Enemy { //enemy stats
    int mhp;
    int matk;
    int mwarpstk;
    int mheal;
};

Character Noctis =
{
    50, //Noctis.hp
    10, //Noctis.atk
    18, //Noctis.warpstk
    12,  //Noctis.heal
    20, //Noctis.mana
};



Enemy Ardyn =
{
    60, //Ardyn.mhp
    10, //Ardyn.matk
    18, //Ardyn.mwarpstk
    8, //Ardyn.heal
};

int choice, eChoice, cDamage, eDamage;


void mainMenu() {
    std::cout << "\n";
    std::cout << "You have " << Noctis.hp << " health and " << Noctis.mana << " mana. Ardyn has " << Ardyn.mhp << " health.\n";
        std::cout << "What do you want to do?\n";
    std::cout << "0: Quit Game\n";
    std::cout << "1: Attack\n"; //regular attack.
    std::cout << "2: Warp Strike (-10 Mana)\n"; //stronger attack, yet risking mana due to the RNG.
    std::cout << "3: Heal\n"; 
    std::cout << "\n";

}
void backStory() {
    std::cout << "You, Noctis Lucis Caelem, have been usurped of your throne by Ardyn Izunia, the king of evil!\n";
    std::cout << "In order to return peace to the land of Lucis, you must take back your position as king from the madman!\n";
    std::cout << "Only you are able to take back what is rightfully yours.\n";
    std::cout << "Entering battle. ";
    Sleep(4000);
    std::cout << ". ";
    Sleep(2000);
    std::cout << ". ";
    Sleep(2000);
    std::cout << "You may not survive... \n";
    Sleep(4000);
}




int main() {

    srand(time(NULL)); //allows for a better RNG system, despite only being pseudo-random.



    backStory();

    while (Noctis.hp > 0 || Ardyn.mhp > 0) {

        mainMenu();

        std::cin >> choice;

        //The following switch statement allows the player to type out the number corresponding to their choice of action.
        //(see mainMenu(); function to understand each case)
        switch (choice) {
        case 0:
            std::cout << "The Kingdom of Lucis condemn your actions.";
            Sleep(500);
            return 0;
        case 1:
            Noctis.atk = rand() % 10;
            break;
        case 2:
            if (Noctis.mana < 10) {
                Noctis.atk = 0;
                std::cout << "You are unable to use warp strike, losing your chance of striking back!\n";
                break;
            }
            else if (Noctis.mana >= 10) {
                Noctis.atk = rand() % Noctis.warpstk;
                Noctis.mana = Noctis.mana - 10;
                break;
            }
        case 3:
            Noctis.heal = rand() % 10;
            Noctis.atk = 0;
            Noctis.hp = Noctis.heal + Noctis.hp;
            if (Noctis.hp > 50) {
                Noctis.hp = 50;
            }
            std::cout << "You were healed! " << Noctis.heal << " of your health was given back!\n";
            break;
        default:
            std::cout << "You hesistated, losing your chance of striking back!\n";
            Noctis.atk = 0;
            break;
        }

        //The following switch statement allows the computer to randomly pick a number from 1 to 3; that number will thus be the enemy's choice.
        eChoice = rand() % 4;

        switch (eChoice) {
        case 1:
            Ardyn.matk = rand() % 10;
            break;
        case 2:
            Ardyn.matk = rand() % Ardyn.mwarpstk;
            break;
        case 3:
            Ardyn.mheal = rand() % 10;
            Ardyn.matk = 0;
            Ardyn.mhp = Ardyn.mheal + Ardyn.mhp;
            if (Ardyn.mhp > 65) {
                Ardyn.mhp = 65;
            }
            std::cout << "Ardyn healed himself! " << Ardyn.mheal << " of his health was given back!\n";
            break;
        }

        //The following lines will dictate the outcome of both characters. I defined eDamage and cDamage as the amount of damage that came from the opponent.

        eDamage = Noctis.atk;

        Ardyn.mhp = Ardyn.mhp - eDamage;

        if (Ardyn.mhp < 1) {
            std::cout << ". ";
            Sleep(800);
            std::cout << ". ";
            Sleep(800);
            std::cout << ". ";
            Sleep(800);
            std::cout << "You have killed Ardyn. Hurrah!\n";
            return 0;
        }
        else {
            std::cout << "You did " << eDamage << " damage against Ardyn. He now has " << Ardyn.mhp << " health.\n";
        }

        cDamage = Ardyn.matk;

        Noctis.hp = Noctis.hp - cDamage;

        if (Noctis.hp < 1) {
            std::cout << ". ";
            Sleep(800);
            std::cout << ". ";
            Sleep(800);
            std::cout << ". ";
            Sleep(800);
            std::cout << "Ardyn dealt " << cDamage << " damage. You have been killed.\n";
            return 0;

        }
        else {
            std::cout << "On the other hand, Ardyn dealt " << cDamage << " damage against you! You now have " << Noctis.hp << " health.\n";
        }
    }
}
