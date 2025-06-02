#include <stdio.h>

int main(){

	char *a[100];
	a[0] = "jack";
	a[1] = "rose";
//	a[1][0] = 100;
//	a[2][0] = "rose";

	printf("%s", a[1]);
}
