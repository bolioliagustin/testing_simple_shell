#include "lib.h"

char **concPath(char **p, char *s)
{
	int i = 0, lenp = 0, lens = 0;
	char *tmp;

	lens = strlen(s);

	
	for (; p[i]; i++)
	{

		lenp = strlen(p[i]);
		printf("lenP: %d\n", lenp);
		lenp = lenp + lens;
		printf("lenP + lenS: %d\n", lenp);
		//tmp = str_concat(p[i], s);
		//printf("tmp: %s\n", tmp);
		p[i] = malloc(sizeof(char) * (lenp + 1));
		if (!p[i])
			return (NULL);

		//strcpy(p[i], tmp);
		tmp = string_nconcat(p[i], s);
		//free(p[i]);
		p[i] = tmp;
		p[lenp] = '\0';
		printf("p[%d]: %s\n", i, p[i]);
		lenp = 0;
		free(tmp);
	}
	return(p);
}

int main(void)
{
		char *s1 = "Rata ";
		char *s2 = "Malvada";
		char *s3 = string_nconcat(s1, s2);

		printf("S3 AHORA DICE: %s\n", s3);
                char *simp = compEnv("PATH");
                int qq = qStrtokPath(simp);

                printf("EL PATH TIENE %d TOKENS\n", qq);

                char **simpD = strD2Path(simp);

                for (int gg = 0; simpD[gg]; gg++)
                         printf("DP [%d]: %s\n", gg, simpD[gg]);
                //----

                char *slash = str_concat("/", "perro");

                concPath(simpD, slash);

                 //printf("SLASH: %s\n", slash);
                for (int kk = 0; simpD[kk]; kk++)
                {
                //      str_concat(simpD[kk], slash);
                         printf("simpD[%d]: %s\n", kk, simpD[kk]);
                }
                //printf("%s\n", strD2Path(getPath())[2]);
                // printf("%s\n", doub[0]);
                //printf("Array: %s\n", str_concat(simpD[2], slash));
                //printf("%s\n", str_concat(strD2Path(getPath())[2], doub[0]));

		return (0);
}
