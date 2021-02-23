#include <iostream>
#include <string>
#include <random>
#include <vector>
#include <iomanip>
#include <stdlib.h>
using namespace std;

static string legendaryPotentialList[] = {
	"STR 12%", "DEX 12%", "INT 12%", "LUK 12%", "Max HP 12%", "Max MP 12%", "DEF 12%",
	"ATT 12%", "Magic ATT 12%", "Damage 12%", "Critical Rate 12%", "All Stats 9%", "Critical Damage 8%",
	"All Skill +2", "All Skill +3", "Elemental Resistance Increase 10%", "Abnormal Status Resistance 10",
	"Ignore Enemy Defense 35%" , "Ignore Enemy Defense 40%", "10% Chance to ignore 20% of Damage",
	"10% Chance to ignore 40% of Damage", "Invinciblity Time 3 Seconds", "4% Chance to be Invincible for 7 sec",
	"30% Chance to Reflect 50% Damage", "30% Chance to Reflect 70% Damage", "MP Cost Reduction 15%",
	"MP Cost Reduction 30%", "HP Recovery Skill 40%", "Skill Cooldown -1 Second", "Skill Cooldown -2 Seconds",
	"Damage to Boss Monsters 30%", "Damage to Boss Monsters 35%", "Damage to Boss Monsters 40%",
	"Meso from Monster 20%", "Item Drop Rate 20%", "3% Auto Steal Chance", "5% Auto Steal Chance",
	"7% Auto Steal Chance", "Decent Combat Orders enabled", "Decent Advanced Bless enabled", "Decent Speed Infusion enabled",
	"Weapon ATT +1 per 10 levels", "Magic ATT +1 per 10 levels"
};

static string uniquePotentialList[] = {
	"STR 9%", "DEX 9%", "INT 9%", "LUK 9%", "Max HP 9%", "Max MP 9%", "DEF 9%",
	"ATT 9%", "Magic ATT 9%", "Damage 9%", "Critical Rate 9%", "All Stats 6%",
	"All Skill +1", "All Skill +2", "Ignore Enemy Defense 30%" , "5% Chance to ignore 20% of Damage",
	"5% Chance to ignore 40% of Damage", "Invinciblity Time 2 Seconds", "2% Chance to be Invincible for 7 sec",
	"HP Recovery Skill 30%", "Damage to Boss Monsters 20%", "Damage to Boss Monsters 30%", 
	"1% Auto Steal Chance", "2% Auto Steal Chance", "Decent Haste enabled", "Decent Mystic Door enabled",
	"Decent Sharp Eyes enabled", "Decent Hyper Body enabled", "STR per 10 Character level +1",
	"DEX per 10 Character level +1", "INT per 10 Character level +1", "LUK per 10 Character level +1"
};

static string potential[3] = { " ", " ", " " };
static int idealLine[3] = { 0, 0, 0 };

static vector<string> legendList
{ "STR 12%", "DEX 12%", "INT 12%", "LUK 12%", "All Stats 9%",
"STR 12%", "DEX 12%", "INT 12%", "LUK 12%", "All Stats 9%",
"STR 12%", "DEX 12%", "INT 12%", "LUK 12%" };
static vector<string> uniqueList
{ "STR 9%", "DEX 9%", "INT 9%", "LUK 9%", "All Stats 6%",
"STR 9%", "DEX 9%", "INT 9%", "LUK 9%", "All Stats 6%",
"STR 9%", "DEX 9%", "INT 9%", "LUK 9%" };
static vector<string> primeLines{
	"STR 12%", "DEX 12%", "INT 12%", "LUK 12%", "All Stats 9%"
};
static vector<string> secondLines{
	"STR 12%", "DEX 12%", "INT 12%", "LUK 12%", "All Stats 9%", 
	"STR 9%", "DEX 9%", "INT 9%", "LUK 9%", "All Stats 6%"
};

static uniform_int_distribution<int> red(0, 19);
static uniform_int_distribution<int> black(0, 3);
static default_random_engine random(unsigned(time(0)));

static string numWord[] = { "first" , "second" , "third", "fourth" };

void secondMenu();
void menu();
void simulator();
void display();
int validation(int);
void statistic(bool);
bool runCube(int, int[]);
void armorHat();
void armorGlove();
void armorTop();
void armorBottom();
void armorShoes();
void accessory();
void accessoryBelt();
void weapon();
void secondary();
void emblem();

int main() {
	menu();
	return 0;
}

void menu() {
	int option;
	do {
		cout << "*------------------------------------------*" << endl;
		cout << "|                                          |" << endl;
		cout << "|     Cube Statistic for End Game User     |" << endl;
		cout << "|               by Sage Han                |" << endl;
		cout << "|                                          |" << endl;
		cout << "|        (1) Hat                           |" << endl;
		cout << "|        (2) Glove                         |" << endl;
		cout << "|        (3) Top or Overall                |" << endl;
		cout << "|        (4) Bottom                        |" << endl;
		cout << "|        (5) Shoes                         |" << endl;
		cout << "|        (6) Accessory                     |" << endl;
		cout << "|        (7) Belt                          |" << endl;
		cout << "|        (8) Weapon                        |" << endl;
		cout << "|        (9) Secondary                     |" << endl;
		cout << "|        (10) Emblem                       |" << endl;
		cout << "|        (0) Exit                          |" << endl;
		cout << "|                                          |" << endl;
		cout << "*------------------------------------------*" << endl;
		
		//RESET STATIC VECTORS AND ARRAYS
		legendList =
		{ "STR 12%", "DEX 12%", "INT 12%", "LUK 12%", "All Stats 9%",
		"STR 12%", "DEX 12%", "INT 12%", "LUK 12%", "All Stats 9%",
		"STR 12%", "DEX 12%", "INT 12%", "LUK 12%" };
		uniqueList =
		{ "STR 9%", "DEX 9%", "INT 9%", "LUK 9%", "All Stats 6%",
		"STR 9%", "DEX 9%", "INT 9%", "LUK 9%", "All Stats 6%",
		"STR 9%", "DEX 9%", "INT 9%", "LUK 9%" };

		primeLines = { "STR 12%", "DEX 12%", "INT 12%", "LUK 12%", "All Stats 9%" };
		secondLines = { "STR 12%", "DEX 12%", "INT 12%", "LUK 12%", "All Stats 9%",
		"STR 9%", "DEX 9%", "INT 9%", "LUK 9%", "All Stats 6%"};

		option = validation(0);
		system("cls");
		switch (option) {
		case 1:
			armorHat(); secondMenu(); break;
		case 2:
			armorGlove(); secondMenu(); break;
		case 3:
			armorTop(); secondMenu(); break;
		case 4:
			armorBottom(); secondMenu(); break;
		case 5:
			armorShoes(); secondMenu(); break;
		case 6:
			accessory(); secondMenu(); break;
		case 7:
			accessoryBelt(); secondMenu(); break;
		case 8:
			weapon(); secondMenu(); break;
		case 9:
			secondary(); secondMenu(); break;
		case 10:
			emblem(); secondMenu(); break;
		case 0:
			break;
		default:		
			cout << "Not a valid option. Type again." << endl;
		}
	} while (option != 0);
}

void secondMenu() {
	int option;
	do {
		cout << "*------------------------------------------*" << endl;
		cout << "|                                          |" << endl;
		cout << "|        (1) Simulator                     |" << endl;
		cout << "|        (2) Statistic                     |" << endl;
		cout << "|        (3) Advanced Statistic            |" << endl;
		cout << "|        (0) Back to Menu                  |" << endl;
		cout << "|                                          |" << endl;
		cout << "*------------------------------------------*" << endl;

		option = validation(0);
		system("cls");
		switch (option) {
		case 1:
			simulator();
			break;
		case 2:
			statistic(false);
			break;
		case 3:
			statistic(true);
			break;
		case 0:
			break;
		default:
			system("cls");
			cout << "Not a valid option. Type again." << endl;
		}
	} while (option != 0);
}

void simulator() {
	int option, dummy2[3] = {1,1,1};
	bool dummy1;

	cout << "*------------------------------------------*" << endl;
	cout << "|    (1)Red Cube (2)Black Cube (0)Exit     |" << endl;
	cout << "*------------------------------------------*" << endl;
	do {	
		option = validation(0);
		system("cls");
		switch (option) {
		case 1:
			dummy1 = runCube(1, dummy2);
			display();
			break;
		case 2:
			dummy1 = runCube(2, dummy2);
			display();
			break;
		case 0:
			break;
		default:
			cout << "Not a valid option. Type again." << endl;
		}		
	} while (option != 0);
}

bool runCube(int option, int idealLine[]) {
	uniform_int_distribution<int> legendNum(0, legendList.size() - 1);
	uniform_int_distribution<int> uniqueNum(0, uniqueList.size() - 1);
	potential[0] = legendList[legendNum(random)];
	switch (option) {
	case 1: 
		if (red(random) == 0) {
			potential[1] = legendList[legendNum(random)];}
		else {
			potential[1] = uniqueList[uniqueNum(random)];}
		if (red(random) == 0) {
			potential[2] = legendList[legendNum(random)];}
		else {
			potential[2] = uniqueList[uniqueNum(random)];}
		break;
	case 2:
		potential[0] = legendList[legendNum(random)];
		if (black(random) == 0) {
			potential[1] = legendList[legendNum(random)];}
		else {
			potential[1] = uniqueList[uniqueNum(random)];}
		if (black(random) == 0) {
			potential[2] = legendList[legendNum(random)];}
		else {
			potential[2] = uniqueList[uniqueNum(random)];}
		break;
	default:
		potential[1] = uniqueList[uniqueNum(random)];
		potential[2] = uniqueList[uniqueNum(random)];
	}
	
	if (potential[0] == primeLines[idealLine[0]] && potential[1] == secondLines[idealLine[1]]
		&& potential[2] == secondLines[idealLine[2]]) {
		return true;
	}
	return false;
}

void statistic(bool advanced) {
	int count, option, num, total;
	bool success;

	for (int i = 0; i < 3; i++) {
		count = 0;
		cout << "*------------------------------------------*" << endl;
		cout << "|                                          |" << endl;
		cout << "|      Pick your " << left << setw(7) << numWord[i] << " ideal line.       |" << endl;
		cout << "|                                          |" << endl;	
		switch (i) {
		case 0:
			for (string i : primeLines) {
				count++;
				cout << "| (" << left << setw(2) << count << ") " << setw(35) << i << " |" << endl;
			}
			cout << "|                                          |" << endl;
			cout << "*------------------------------------------*" << endl;
			idealLine[0] = validation(1) - 1;
			break;
		case 1:
			for (string i : secondLines) {
				count++;
				cout << "| (" << left << setw(2) << count << ") " << setw(35) << i << " |" << endl;
			}
			cout << "|                                          |" << endl;
			cout << "*------------------------------------------*" << endl;
			idealLine[1] = validation(2) - 1;
			break;
		case 2:
			for (string i : secondLines) {
				count++;
				cout << "| (" << left << setw(2) << count << ") " << setw(35) << i << " |" << endl;
			}
			cout << "|                                          |" << endl;
			cout << "*------------------------------------------*" << endl;
			idealLine[2] = validation(2) - 1;
			break;
		}
		system("cls");
	}

	if (advanced) {
		bool fail;
		cout << "*------------------------------------------*" << endl;
		cout << "|  Type in the amount of success as 3L.    |" << endl;
		cout << "|      (1~100 for the sake of time.)       |" << endl;
		cout << "*------------------------------------------*" << endl;
		do {
			fail = false;
			num = validation(0);
			if (num > 100 || num < 1) {
				fail = true;
				cout << "Out of range. Type again." << endl;
			}
		} while (fail);		
	}
	else {
		num = 1;
	}

	cout << "*------------------------------------------*" << endl;
	cout << "|          Would you like to use           |" << endl;
	cout << "|    (1) Red Cube? or (2) Black Cube?      |" << endl;
	cout << "*------------------------------------------*" << endl;

	do {
		count = 0;
		total = 0;
		option = validation(0);
		switch (option) {
		case 1:
			cout << "Calculating..." << endl;
			for (int i = 0; i < num; i++) {
				do {
					success = runCube(1, idealLine);
					count++;
				} while (!success);
				cout << count << ".. ";
				total += count;
				count = 0;
			}			
			break;
		case 2:
			cout << "Calculating..." << endl;
			for (int i = 0; i < num; i++) {
				do {
					success = runCube(2, idealLine);
					count++;
				} while (!success);
				cout << count << ".. ";
				total += count;
				count = 0;
			}
			break;
		default:
			cout << "Not a valid option. Type again." << endl;
		}
	} while (option != 1 && option != 2);

	count = total / num;

	cout << "\n*------------------------------------------*" << endl;
	cout << "|   Avrg # of cubes to get ideal lines :   |" << endl;
	cout << "|                 " << left << setw(9) << count << "                |" << endl;
	cout << "*------------------------------------------*" << endl;
	display();
	system("pause");
	system("cls");
}

void display() {
	cout << "*------------------------------------------*" << endl;
	cout << "| " << left << setw(40) << potential[0] << " |" << endl;
	cout << "| " << left << setw(40) << potential[1] << " |" << endl;
	cout << "| " << left << setw(40) << potential[2] << " |" << endl;
	cout << "*------------------------------------------*" << endl;
}

int validation(int option) {
	string input; bool fail; unsigned num;
	do {
		fail = false;
		getline(cin, input);
		if (input.length() == 0) {
			fail = true;
		}
		else {
			for (unsigned i = 0; i < input.length(); i++) {
				if (!isdigit(input[i])) {
					fail = true;
				}
			}
		}
		if (fail) {
			cout << "Digit only. Type again." << endl;
		}
		else {
			num = stoi(input);
			if (option == 1) {
				if (num < 1 || num > primeLines.size()) {
					fail = true;
					cout << "Not a valid option. Type again." << endl;
				}
			}
			else if (option == 2) {
				if (num < 1 || num > secondLines.size()) {
					fail = true;
					cout << "Not a valid option. Type again." << endl;
				}
			}
		}
	} while (fail);
	return num;
}

void armorHat() { 
	//legend : 4,5,6,13,14,19,20,27,28,29,39
	//unique : 4,5,6,12,13,15,16,19,25
	for (int i = 0; i < 2; i++) {
		legendList.push_back(legendaryPotentialList[13]);
		legendList.push_back(legendaryPotentialList[14]);

		uniqueList.push_back(uniquePotentialList[12]);
		uniqueList.push_back(uniquePotentialList[13]);
	}
	for (int i = 0; i < 3; i++) {
		legendList.push_back(legendaryPotentialList[4]);
		legendList.push_back(legendaryPotentialList[5]);
		legendList.push_back(legendaryPotentialList[28]);
		legendList.push_back(legendaryPotentialList[29]);

		uniqueList.push_back(uniquePotentialList[4]);
		uniqueList.push_back(uniquePotentialList[5]);
	}
	for (int i = 0; i < 5; i++) {
		legendList.push_back(legendaryPotentialList[6]);
		legendList.push_back(legendaryPotentialList[19]);
		legendList.push_back(legendaryPotentialList[20]);
		legendList.push_back(legendaryPotentialList[27]);
		legendList.push_back(legendaryPotentialList[39]);
		
		uniqueList.push_back(uniquePotentialList[6]);
		uniqueList.push_back(uniquePotentialList[15]);
		uniqueList.push_back(uniquePotentialList[16]);
		uniqueList.push_back(uniquePotentialList[19]);
		uniqueList.push_back(uniquePotentialList[25]);
	}
	int armorHatLegend[] = { 4,5,6,13,14,19,20,27,28,29,39 };
	int armorHatUnique[] = { 4,5,6,12,13,15,16,19,25 };
	for (int i = 0; i < 11; i++) {
		primeLines.push_back(legendaryPotentialList[armorHatLegend[i]]);
		secondLines.push_back(legendaryPotentialList[armorHatLegend[i]]);
	}
	for (int i = 0; i < 9; i++) {
		secondLines.push_back(uniquePotentialList[armorHatUnique[i]]);
	}
}
void armorGlove() {
	//legend : 4,5,6,12,19,20,27,35,36,37,40
	//unique : 4,5,6,15,16,19,22,23,26,28,29,30,31
	for (int i = 0; i < 3; i++) {
		legendList.push_back(legendaryPotentialList[4]);
		legendList.push_back(legendaryPotentialList[5]);
		legendList.push_back(legendaryPotentialList[12]);		

		uniqueList.push_back(uniquePotentialList[4]);
		uniqueList.push_back(uniquePotentialList[5]);
	}
	for (int i = 0; i < 5; i++) {
		legendList.push_back(legendaryPotentialList[6]);
		legendList.push_back(legendaryPotentialList[19]);
		legendList.push_back(legendaryPotentialList[20]);
		legendList.push_back(legendaryPotentialList[27]);
		legendList.push_back(legendaryPotentialList[35]);
		legendList.push_back(legendaryPotentialList[36]);
		legendList.push_back(legendaryPotentialList[37]);
		legendList.push_back(legendaryPotentialList[40]);

		uniqueList.push_back(uniquePotentialList[6]);
		uniqueList.push_back(uniquePotentialList[15]);
		uniqueList.push_back(uniquePotentialList[16]);
		uniqueList.push_back(uniquePotentialList[19]);
		uniqueList.push_back(uniquePotentialList[22]);
		uniqueList.push_back(uniquePotentialList[23]);
		uniqueList.push_back(uniquePotentialList[26]);
		uniqueList.push_back(uniquePotentialList[28]);
		uniqueList.push_back(uniquePotentialList[29]);
		uniqueList.push_back(uniquePotentialList[30]);
		uniqueList.push_back(uniquePotentialList[31]);
	}
	int armorGloveLegend[] = { 4,5,6,12,19,20,27,35,36,37,40 };
	int armorGloveUnique[] = { 4,5,6,15,16,19,22,23,26,28,29,30,31 };
	for (int i = 0; i < 11; i++) {
		primeLines.push_back(legendaryPotentialList[armorGloveLegend[i]]);
		secondLines.push_back(legendaryPotentialList[armorGloveLegend[i]]);
	}
	for (int i = 0; i < 13; i++) {
		secondLines.push_back(uniquePotentialList[armorGloveUnique[i]]);
	}
}
void armorTop() {
	//legend : 4,5,6,15,19,20,21,22,27
	//unique : 4,5,6,15,16,17,18,19
	for (int i = 0; i < 3; i++) {
		legendList.push_back(legendaryPotentialList[4]);
		legendList.push_back(legendaryPotentialList[5]);
		legendList.push_back(legendaryPotentialList[15]);

		uniqueList.push_back(uniquePotentialList[4]);
		uniqueList.push_back(uniquePotentialList[5]);
	}
	for (int i = 0; i < 5; i++) {
		legendList.push_back(legendaryPotentialList[6]);
		legendList.push_back(legendaryPotentialList[19]);
		legendList.push_back(legendaryPotentialList[20]);
		legendList.push_back(legendaryPotentialList[21]);
		legendList.push_back(legendaryPotentialList[22]);
		legendList.push_back(legendaryPotentialList[27]);

		uniqueList.push_back(uniquePotentialList[6]);
		uniqueList.push_back(uniquePotentialList[15]);
		uniqueList.push_back(uniquePotentialList[16]);
		uniqueList.push_back(uniquePotentialList[17]);
		uniqueList.push_back(uniquePotentialList[18]);
		uniqueList.push_back(uniquePotentialList[19]);
	}
	int armorTopLegend[] = { 4,5,6,15,19,20,21,22,27 };
	int armorTopUnique[] = { 4,5,6,15,16,17,18,19 };
	for (int i = 0; i < 9; i++) {
		primeLines.push_back(legendaryPotentialList[armorTopLegend[i]]);
		secondLines.push_back(legendaryPotentialList[armorTopLegend[i]]);
	}
	for (int i = 0; i < 8; i++) {
		secondLines.push_back(uniquePotentialList[armorTopUnique[i]]);
	}
}
void armorBottom() {

}
void armorShoes() {

}
void accessory() {

}
void accessoryBelt() {

}
void weapon() {
	
}
void secondary() {

}
void emblem() {

}