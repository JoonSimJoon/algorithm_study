#include <stdio.h>
#include <string.h>

int i, c;
char s[111];

int main() {
	scanf("%s", s);
	while (i < strlen(s)) {
		if (s[i] == 'c' && (s[i+1] == '=' || s[i+1] == '-')) i++;
		else if (s[i] == 'd') {
			if (s[i+1] == '-') i++;
			else if (s[i+1] == 'z' && s[i+2] == '=') i+=2;
		}
		else if ((s[i] == 'l' || s[i] == 'n') && s[i+1] == 'j') i++;
		else if ((s[i] == 's' || s[i] == 'z') && s[i+1] == '=') i++;
		i++, c++;
	}
	printf("%d", c);

	return 0;
}