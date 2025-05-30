#include <stdio.h>

int main(){
	char a = 'x';
	char b = 'v';
	char c = 'c';
	char *t;


	// copy a b c  to t
	
//	*t = a;

	t[0] = a;

	t[1] = b;
//	*t++ = b;
//	*t++ = c;

	char *s = "teacher";

//	printf("%s", *s);

	char ss[10] = "teacher";

	printf("%s", ss);

	printf("%c\n", *t);

	printf("%c\n", *(t + 1));

	printf("%c\n",a);

//	for ( int n = 0; *t != '\0'; t++){
//		printf("aaaaa\n");
//		printf("%c\n", *t);
//	}
	
		

}
