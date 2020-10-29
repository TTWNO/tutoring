#include <stdio.h>
#include <string.h>

struct Person {
	char name[32];
	int miss;
	struct Person *SO;
};

int DAYS_TO_SEE = 33;

int main()
{
	char buffer_char;
	struct Person tait, melody;
	strcpy(tait.name, "Tait Hoyem");
	strcpy(melody.name, "Melody Shih");
	tait.miss = 0;
	melody.miss = 0;
	tait.SO = &melody;
	melody.SO = &tait;

	while (DAYS_TO_SEE > 0)
	{
		melody.miss++;
		tait.miss++;
		DAYS_TO_SEE--;
		printf("I will see you in %d days!\n", DAYS_TO_SEE);
		printf("%s misses %s = %d\n", tait.name, tait.SO->name, tait.miss);
		printf("%s misses %s = %d\n", melody.name, melody.SO->name, melody.miss);
		scanf("%c", &buffer_char);
	}
	printf("%s sees %s in Vancouver!\n", tait.name, melody.name);
	return 0;
}
