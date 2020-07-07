#include "stdafx.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>


#pragma warning(disable:4996)

#define SYMBOL '.'

#define min(x,y) ((x)<(y)?(x):(y))

int main() {

	const char *SCREEN_0 = "\n"\
		"     _____      \n"\
		"     |   |      \n"\
		"     O   |      \n"\
		"    /|\\  |      \n"\
		"     |   |      \n"\
		"    / \\  |      \n"\
		"         |      \n"\
		" ---------------\n"\
		;

	const char *SCREEN_1 = "\n"\
		"     _____      \n"\
		"     |   |      \n"\
		"     O   |      \n"\
		"    /|\\  |      \n"\
		"     |   |      \n"\
		"      \\  |      \n"\
		"         |      \n"\
		" ---------------\n"\
		;
	const char *SCREEN_2 = "\n"\
		"     _____      \n"\
		"     |   |      \n"\
		"     O   |      \n"\
		"    /|\\  |      \n"\
		"     |   |      \n"\
		"         |      \n"\
		"         |      \n"\
		" ---------------\n"\
		;
	const char *SCREEN_3 = "\n"\
		"     _____      \n"\
		"     |   |      \n"\
		"     O   |      \n"\
		"    /|\\  |      \n"\
		"         |      \n"\
		"         |      \n"\
		"         |      \n"\
		" ---------------\n"\
		;
	const char *SCREEN_4 = "\n"\
		"     _____      \n"\
		"     |   |      \n"\
		"     O   |      \n"\
		"    /|   |      \n"\
		"         |      \n"\
		"         |      \n"\
		"         |      \n"\
		" ---------------\n"\
		;
	const char *SCREEN_5 = "\n"\
		"     _____      \n"\
		"     |   |      \n"\
		"     O   |      \n"\
		"     |   |      \n"\
		"         |      \n"\
		"         |      \n"\
		"         |      \n"\
		" ---------------\n"\
		;
	const char *SCREEN_6 = "\n"\
		"     _____      \n"\
		"     |   |      \n"\
		"     O   |      \n"\
		"         |      \n"\
		"         |      \n"\
		"         |      \n"\
		"         |      \n"\
		" ---------------\n"\
		;
	const char *SCREEN_7 = "\n"\
		"     _____      \n"\
		"     |   |      \n"\
		"         |      \n"\
		"         |      \n"\
		"         |      \n"\
		"         |      \n"\
		"         |      \n"\
		" ---------------\n"\
		;
	const char *SCREEN_8 = "\n"\
		"     _____      \n"\
		"         |      \n"\
		"         |      \n"\
		"         |      \n"\
		"         |      \n"\
		"         |      \n"\
		"         |      \n"\
		" ---------------\n"\
		;
	const char *SCREEN_9 = "\n"\
		"                \n"\
		"         |      \n"\
		"         |      \n"\
		"         |      \n"\
		"         |      \n"\
		"         |      \n"\
		"         |      \n"\
		" ---------------\n"\
		;
	const char *SCREEN_10 = "\n"\
		"                \n"\
		"                \n"\
		"                \n"\
		"                \n"\
		"                \n"\
		"                \n"\
		"                \n"\
		" ---------------\n"\
		;


	const char *all[11] = {SCREEN_10, SCREEN_9, SCREEN_8, SCREEN_7, SCREEN_6, SCREEN_5, SCREEN_4, SCREEN_3, SCREEN_2, SCREEN_1, SCREEN_0 };
	
	char message[23] = "You have got 10 lives.";
	printf("%s", message);
	printf("%s", SCREEN_0);

	char words[10][10];
	strcpy(words[0], "mere");
	strcpy(words[1], "pere");
	strcpy(words[2], "cirese");
	strcpy(words[3], "gutui");
	strcpy(words[4], "banane");
	strcpy(words[5], "piersici");
	strcpy(words[6], "portocale");
	strcpy(words[7], "mandarine");
	strcpy(words[8], "clementine");
	strcpy(words[9], "fragi");

	time_t currentTime = time(nullptr);
	srand((unsigned int)currentTime);
	int index = rand() % 10;
	// printf("index = %d ---> %s\n", index, words[index]);
	const char *toGuess = words[index];
	int length = strlen(toGuess);

	bool isEnd = false;
	char userWord[10];
	
	int i;
	for (i = 0; i < length; ++i) {
		userWord[i] = SYMBOL;
	}
	userWord[i] = '\0';
	int wrongChoises = 0;

	do {
//		clrscr();
		printf("Word %s\n\n", userWord);
		printf("Your char: ");
		int ch = getch();
		printf("%c\n", ch);
		
		bool isOk = false;
		for (i = 0; i < length; ++i) {
			if (toGuess[i] == ch) {
				userWord[i] = ch;
				isOk = true;
			}
		}

		isEnd = (strchr(userWord, SYMBOL) == nullptr);
		if (!isOk) {
			++wrongChoises;
			int index = min(wrongChoises, 11);
			const char *scene = all[index];
			printf("%s\n", scene);
			if (wrongChoises >= 10) {
				printf("You are in big trouble ...\n");
				printf("___you died___\n");
				printf("The word was %s\n", toGuess);
				isEnd = true;
			}
		}
		

	} while (!isEnd);

	printf("Word %s\n\n", userWord);
	printf("Wrong choises: %u\n", wrongChoises);
	
	return 0;
}

