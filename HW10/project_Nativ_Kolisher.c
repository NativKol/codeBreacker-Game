/**************
* פרויקט מחצית*
**************/

//library
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

//global mishtanim
int t = 0, t1 = 1, victory = 0, t2 = 0;
int miss = 0, hits = 0;

//list
enum difficulty { none, easy, moderate, hard, crazy };

//the functions
void printRules();
int chooseDifficulty(int diff);
int randomNum();
int randomNumCheck(int rnd);
void printGuess();
//int guessNum();
int checkNum(int num1, int num2, int num3, int num4, int rnd, int trys);
void end(int saveTrys, int rnd);
//void run();

//actually the main but in function so you can make it work more then one time
void run()
{
	int rnd = 0, guess = 0, trys = 0, num = 0, saveTrys = 0;
	int num1 = 0, num2 = 0, num3 = 0, num4 = 0;
	t = 0, t1 = 1, victory = 0, t2 = 0;
	miss = 0, hits = 0;
	
	srand(time(NULL));        						  //importmant
	
	while (t1 == 1)								//loop that make the random number
	{
		rnd = randomNum();
		t1 = randomNumCheck(rnd);
	}
	//printf("random = %d \n", rnd);				//if you want to see the random number
	
	printRules();									//print the rules
	enum difficulty diff;							//list of difficulty
	diff = 0;
	while (diff < 1 || diff > 4)					// make sure that the input available
	{
		printf("Make a choice: ");
		scanf("%d", &diff);
		getchar();
	}
	trys = chooseDifficulty(diff);
	while (trys > 0)
	{
		printGuess(trys);								
		printf("%c", num1 = getch());					//print with no enter use
		printf("%c", num2 = getch());
		printf("%c", num3 = getch());
		printf("%c\n", num4 = getch());
		num1 = num1 - 48;								//ascii		
		num2 = num2 - 48;
		num3 = num3 - 48;
		num4 = num4 - 48;
		saveTrys = saveTrys + 1;									//count trys
		trys = 	checkNum(num1, num2, num3, num4, rnd, trys);
		if (hits == 4)
		{
			printf("\n   4 HITS YOU WON!!!");
		}
		else
		{
			printf("You got    %d HITS    %d MISSES.\n", hits, miss);
		}
	}
	end(saveTrys, rnd);
		
}

//main
//print if you want to play again and run the program
int main()
{
	char again = ' ';
	run();
	while (again != 'n')
	{
		printf("Would you like to play again? (y/n): ");
		printf("%c\n", again = getch());
		if (again == 'y')
		{
			run();
		}
		if (again == 'n')
		{
			printf("\nBye Bye!");
		}
	}
	return 0;
}

//printing rules
void printRules()
{
	printf("\nWelcome to ""MAGSHIMIM CODE-BREAKER""!!!\n\n");
	printf("A secret password was chosen to protect the credit card of Pancratius,\nthe descendant of Antiochus.\nYour mission is to stop Pancratius by revealing his secret password.\n\n");
	printf("The rules are as follows:\n1. In each round you try to guess the secret password (4 distinct digits)\n");
	printf("2. After every guess you'll receive two hints about the password\n   HITS:   The number of digits in your guess which were exactly right.\n   MISSES: The number of digits in your guess which belongs to\n           the password but were miss-placed.\n");
	printf("3. If you'll fail to guess the password after a certain number of rounds\n   Pancratius will buy all the gifts for Hanukkah!!!\n\n");
	printf("Please choose the game level:\n1 - Easy (20 rounds)\n2 - Moderate (15 rounds)\n3 - Hard (10 rounds)\n4 - Crazy (random number of rounds 5-25)\n");
}

//calc how many trys tou have from the difficulty you choose
int chooseDifficulty(int diff)
{
	int trys = 0, die = 0;
	die = rand() % 25 + 5;
	switch(diff) 
	{
		  case 1:
			{
				trys = 20;
				break;
			}
		  case 2:
			{
				trys = 15;
				break;
			}
		  case 3: 						
			{
				trys = 10;
				break;
			}
		  case 4:						
			{
				t = 1;
				trys = die;
				break;
			}
		}
	
	return trys;
}

//pritn how many guesses left
void printGuess(int trys)
{
	printf("Write your guess (only 1-6, no ENTER is needed)\n");
	if (t == 0)
	{
		printf("%d guesses left\n", trys);
	}
}

//make random number
int randomNum()
{
	int rnd = 0;
	rnd = rand() % 6666 + 1000;
	
	return rnd;	
}	

// make sure that the input available
int randomNumCheck(int rnd)
{
	int i = 0, count = 0, num = 0;
	int save = rnd;
	t1 = 0;
	for (i = 1; i <= 6; i++)
	{
		save = rnd;
		count = 0;
		while (save != 0)
		{
			num = save % 10;
			save = (save - num)/10;
			if (num == i)
			{
				count += 1;
			}
			if (num > 6 || num < 1)
			{
				count = 2;
			}
			
		}
		if (count > 1)
		{
			t1 = 1;
			break;
		}

	}
	return t1;
}

//checking how many misses and hits there are
int checkNum(int num1, int num2, int num3, int num4, int rnd, int trys)
{
	int n1 = 0, n2 = 0, n3 = 0, n4 = 0, save = 0;
	hits = 0, miss = 0;
	save = rnd;
	//מפצל את המספרים לספרות
	n4 = save % 10;
	save = (save - n4)/10;
	n3 = save % 10;
	save = (save - n3)/10;
	n2 = save % 10;
	save = (save - n2)/10;
	n1 = save % 10;
		
	if (n1 == num1 || n1 == num2 || n1 == num3 || n1 == num4)
	{
		if (n1 == num1)
		{
			hits += 1;
		}
		else
		{
			miss += 1;
		}
	}
	if (n2 == num1 || n2 == num2 || n2 == num3 || n2 == num4)
	{
		if (n2 == num2)
		{
			hits += 1;
		}
		else
		{
			miss += 1;
		}
	}
	if (n3 == num1 || n3 == num2 || n3 == num3 || n3 == num4)
	{
		if (n3 == num3)
		{
			hits += 1;
		}
		else
		{
			miss += 1;
		}
	}
	if (n4 == num1 || n4 == num2 || n4 == num3 || n4 == num4)
	{
		if (n4 == num4)
		{
			hits += 1;
		}
		else
		{
			miss += 1;
		}
	}
		
	if (hits == 4)
	{
		trys = 0;
		victory = 1;
	}
	else
	{
		trys = trys - 1;
		victory = 0;
	}
	return trys;
		
}

//print end screen
void end(int saveTrys, int rnd)
{
	if (victory == 0)
	{
		printf("\nOOOOHHHH!!! Pancratius won and bought all of Hanukkah's gifts.\n");
		printf("Nothing left for you...\n");
		printf("The secret password was %d\n\n", rnd);
	}
	else 
	{
		printf("\n\nIt took you only %d guesses, you are a professional code breaker!\n\n", saveTrys);
	}

}






