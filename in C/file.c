#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void binarySearch(char nameList[][100], char str[], int count, int lb, int ub)
{
while(lb <= ub)
{
int compare;
int mid = (lb+ub)/2;
compare = strcmp(str, nameList[mid]);
if(compare == 0)
{
printf("The name is found in the file\n%s has been found.\n", str);
exit(0);
}
else if(compare > 0)
lb = mid+1;
else
ub = mid-1;

}
printf("The name, %s is not present in the file\n", str);
}
void sort(char nameList[][100], int count)
{
int compare;
char temp[100];
//Sorting
for(int i = 0 ; i < count-1 ; i++)
{ for(int j = 0 ; j < count - 1 - i ; j++)
{
compare = strcmp(nameList[j], nameList[j+1]);
if(compare > 0)
{
strcpy(temp, nameList[j]);
strcpy(nameList[j], nameList[j+1]);
strcpy(nameList[j+1], temp);
}
}
}
//Dipslaying the names in the list
printf("The name list after sorting (you can check the original list by visiting the file): \n");
for(int i = 0 ; i < count ; i++)
{
printf("%s\n", nameList[i]);
}
}
int main()
{
char nameList[100][100];
int count = 0; //Kepps count of the number of students in the list
char str[100]; //Storing the name of the student to checked
char filename[100];
printf("Enter the file name\n");
scanf("%s", filename);
FILE *fptr = fopen(filename, "r");
if(fptr == NULL)
{
printf("Error: The file doesn't exist!!!\n");
return 1;
}
char line[100];
while((fgets(line, sizeof(line), fptr)) != NULL){
line[strcspn(line, "\n")] = '\0';
strcpy(nameList[count], line);
count ++;
}
fclose(fptr);

//Sorting the names we read out from the file
sort(nameList, count);
printf("Enter the name to be searched\n");
scanf("\n");
gets(str);
binarySearch(nameList, str, count, 0, (count-1));
return 0;
}