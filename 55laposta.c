#include "lib.h"

int qStrtok(char *c)
{
 	char *copy;
	char *tok;
       int i = 0, j = 0, k = 0;

	for (; c[j]; j++)
		;

	copy = malloc(sizeof(char) * j);
	
	strcpy(copy, c);
       if (c)
       {
       		tok = strtok(copy, " ");
       		if (tok)
       		{
                	while (tok)
                	{
                        	i++; 
				tok = strtok(NULL, " ");
                	}
       		}
       }
	free(tok);
       free (copy);
        return (i);
}


int main(int ac, char **av)
{
	char *buf;
	size_t bufsize, chara;
	int q;
	char *tok;
	int len = 0;
	char *strMal, *bufCpy;
	int i = 0, j = 0;
	char **strD;

	int p = 1;

	while (p == 1)
	{
		buf = malloc(sizeof(char) * bufsize);
		if(!buf)
			return (-1);

		printf("$ ");
		chara = getline(&buf, &bufsize, stdin);
		
		if(buf[chara - 1] == '\n')
			buf[chara - 1] = 0;

		q = qStrtok(buf);
		printf("qStrtok: %d\n", q);
		
		strD = malloc(sizeof(char *) * q);
		if (!strD)
			return (0);
		
		tok = strtok(buf, " ");

		while (tok)
                {
			len = strlen(tok);
			strMal = (char *)malloc(sizeof(char) * len);
			if (!strMal)
				return (0);
			
			//strMal = tok;

			strcpy(strMal, tok);
			
			int comp = strcmp(strMal, "exit");
			printf("strcmp dio: %d\n", comp);
			
			if(comp == 0)
			{
				printf("( ^_^)/\n");
				exit (-1);
			}

			strD[j] = strMal;
			
			printf("el largo de la palabra es: %d\n", len);
			printf("palabra: %s\n", tok);
			for (i = 0; i < len; i++)
			{
				printf("StrMal[%d] es %c\n", i, strMal[i]);
			}
			
			j++;
			i = 0;

//		liberar memoria de strMal	

			tok = strtok(NULL, " ");
			free(strMal);
                }	
	
		j = 0;
		printf("El puntero doble tiene: ");
		for(int k = 0; k < q; k++)
			printf("%s, ", strD[k]);
		
		printf("\n");
		printf("cantidad caracteres: %zu\n", chara);
	}
	for (int g = 0 ; g < q ; g++)
	{
		free(strD[g]);
	}
	free(strD);

	free(tok);
	free(buf);
	//free(strMal);
	//free(strD);
	
	return (0);
}

