#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 30
int compar(const void *pa, const void *pb);      //compare function for comparing strings
void fileCopy(FILE *fp);
struct person_struct                             //Data-type structure for declaring 3 char arrays
   {
	char lastName[N];
	char firstName[N];
	char cityName[N];
   };

typedef struct person_struct person_t;            //variable declaration of type structure
person_t dBasePeople[100];                        //array of type structure

int main() {
	FILE *fp = fopen("myTextFile.txt", "r");      //Opening the text file to read

	fileCopy(fp);
	size_t L = sizeof(dBasePeople) / sizeof(person_t);       //Getting the size of array of structure
	size_t M = sizeof(person_t);                             //Getting the size of Structure
	qsort(dBasePeople, L, M, compar);


	printf(" The sorted records are \n");
	printf("\nLastName  FirstName  CityName \n");
	for (int i = 0; i < 100; i++)
	{
       //printing with formatted spaces
		printf("\n %-13s %-13s %s ", dBasePeople[i].lastName,dBasePeople[i].firstName, dBasePeople[i].cityName);
	}
	return 0;
}

void fileCopy(FILE *fp) {
	size_t ctr = 0;
	char str_1[N], str_2[N], str_3[N];
	while (fscanf(fp, "%s%s%s", str_1, str_2, str_3) != EOF)   //reading 3-words from file
	   {
		strcpy(dBasePeople[ctr].lastName, str_1);             //storing first-word in lastName array
		strcpy(dBasePeople[ctr].firstName, str_2);            //storing second-word in firstName array
		strcpy(dBasePeople[ctr].cityName, str_3);             //storing third-word in cityName array
		++ctr;
	   }
	fclose(fp);                                               //closing the Text-file
}

int compar(const void *pa, const void *pb) {
	char *str_a = ((person_t*) pa)->lastName;        //pointer to a structure member last-name
	char *str_b = ((person_t*) pb)->lastName;
	return strcmp(str_a, str_b);                     //returns -1 or 1 or 0 as if (str_a<str_b) or (str_a>str_b) or (str_a=str_b)
}
