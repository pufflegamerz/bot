#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10
#define MAX_LENGTH 30

int hasChar(char *string, char c) {
	while (*string != '\0') {
		if (*string == c) {return 1;}
		string++;
	}

	return 0;
}

// Check if min is in max
int hasWords(char max[MAX_WORDS][MAX_LENGTH], char min[MAX_WORDS][MAX_LENGTH]) {
	int matched = 0;
	for (size_t i = 0; max[i][0] != '\0'; i++) { // max
		for (size_t x = 0; min[x][0] != '\0'; x++) { // min
			if (!strcmp(min[x], max[i])) {
				matched++;
			}
		}
	}
	
	return matched;
}

void answerQuestion(char string[]) {
	char buffer[MAX_WORDS][MAX_LENGTH];
	
	// Parse the words
	size_t currentWord = 0;
	size_t currentC = 0;
	for (size_t c = 0; string[c] != '\0';) {
		if (string[c] >= 'a' && string[c] <= 'z') {
			buffer[currentWord][currentC] = string[c];
			currentC++;
			c++;
		} else if (string[c] >= 'A' && string[c] <= 'Z') {
			// Lowercase capital chars
			buffer[currentWord][currentC] = string[c] + 32;
			currentC++;
			c++;
		} else {
			// punctuation chars
			while (hasChar(". '!?,\n", string[c])) {
				c++;
			}
			
			buffer[currentWord][currentC] = '\0';
			currentWord++;
			currentC = 0;
		}
	}
	
	// Signal for checker to stop
	buffer[currentWord][0] = '\0';
	
	char MG1[MAX_WORDS][MAX_LENGTH] = {"how", "are", "you", "\0"};
	if (hasWords(MG1, buffer) >= 3) {
		puts("I'm doing fine. How about you?");
		return;
	}
	
	char MG2[MAX_WORDS][MAX_LENGTH] = {"what", "your", "name", "\0"};
	if (hasWords(MG2, buffer) >= 3) {
		puts("My name is Daniel.");
		return;
	}

	char MG0[MAX_WORDS][MAX_LENGTH] = {"hey", "hello", "hi", "\0"};
	if (hasWords(MG0, buffer) == 1) {
		puts("Hey.");
		return;
	}

	char MG3[MAX_WORDS][MAX_LENGTH] = {"good", "fine", "\0"};
	if (hasWords(MG3, buffer) == 1) {
		puts("That's good.");
		return;
	}

	puts("I am not permitted to provide a response.");
}

int main() {
	puts("Talk to me.");
	while (1) {
		char string[50];
		fgets(string, 50, stdin);

		putchar(' ');
		answerQuestion(string);
	}
	
	return 0;
}
