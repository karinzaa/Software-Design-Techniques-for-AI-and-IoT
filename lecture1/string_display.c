#include <stdio.h>
#include <string.h>

void main()
{
	char text[12];
	int i;
	strcpy(text, "Hello World");
	printf("text = %s \n",text);
	for (i=0;i<12;i++)
	{
		printf("text['%d'] = '%c' (val = %d) \n",i,text[i], text[i]);

	}
	strcpy(text, "World!");
	printf("text = %s \n",text);
	for (i=0;i<12;i++)
	{
		printf("text['%d'] = '%c' (val = %d) \n",i,text[i], text[i]);

	}

}
