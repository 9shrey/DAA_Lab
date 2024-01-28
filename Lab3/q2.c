#include <stdio.h>
#include <string.h>

int opcount = 0;

void main() {
	char s1[100], s2[100];
	int i, j, ind, flag = 0;
	printf("Enter string 1: ");
	fgets(s1, sizeof(s1), stdin);
	printf("Enter string 2: ");
	fgets(s2, sizeof(s2), stdin);
	s1[strcspn(s1, "\n")] = '\0'; 
	s2[strcspn(s2, "\n")] = '\0';
	for (i = 0; i < strlen(s1) - strlen(s2) + 1; i++) {
		for (ind = 0; ind < strlen(s2); ind++) {
			opcount++;
			if (s2[ind] != s1[i + ind])
				break;
		}
		if (ind == strlen(s2))
			break;
	}
	printf("Operation count = %d\n", opcount);
	if (ind == strlen(s2))
		printf("Substring is at index %d. Count : %d", i, i + ind);
	else
		printf("String 1 does not have substring 2. Count : %d", i);
}