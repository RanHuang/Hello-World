#include <stdio.h>
int main()
{
	int n;
	int tmp;
	while(scanf("%d",&n) != EOF)
	{
		tmp = -1;
		if(n<1 || n > 1000000000) continue;
		tmp = n % 8;
		switch(tmp){
			case 1:
				printf("%d\n", 1);
				break;
			case 2:
			case 0:
				printf("%d\n", 2);
				break;
			case 3:
			case 7:
				printf("%d\n", 3);
				break;
			case 4:
			case 6:
				printf("%d\n", 4);
				break;
			case 5:
				printf("%d\n", 5);
				break;
			default:
				break;
		}	
	}
	return 0;
}
