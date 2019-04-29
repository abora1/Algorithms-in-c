#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFERSIZE 1024
int findpath(int x,int y);
int arr[100][100]; //Distance array
int p[100][100];	//Path array
int counter=0;
int count=0;

int main(int argc,char *args[])
{
//declarations and initialization
char buffer[BUFFERSIZE];
const char *del=",";
char *token;
int i=0;
FILE *f = fopen(args[1], "r"); 
int a=1;
int b=1;

//Taking inputs from the csv file
while(fgets(buffer,BUFFERSIZE,f)!=NULL)
{
	count++;
	token=strtok(buffer,del);//converting a line into tokens
	while(token!=NULL)
	{
		counter=b;
		int c=atoi(token);
		arr[a][b]=c;//using two dimensional array to store distance between nodes.
		b++;
		token=strtok(NULL,del);
	}
	a++;
	b=1;
}
int k;
int x;
int y;
int arr2[1000];
//Floyd Algorithm..
for(k=1;k<=count;k++)
{
	for(x=1;x<=count;x++)
		{
			for(y=1;y<=count;y++)
				{
					
					if(arr[x][y]>(arr[x][k]+arr[k][y]))
						{
							arr[x][y]=(arr[x][k]+arr[k][y]);
							p[x][y]=k;
						}
				}
		}
}
//Shortest path Calculation and Display
printf("Shortest path between each pair of nodes:\n");
for(int i=1;i<=count;i++)
{
	for(int j=1;j<=counter;j++)
		{
			printf("(V%d,V%d) : ",i,j);
			printf("V%d -",i );
			if(p[i][j]!=0)
				{	
					//calling findpath function to find shortest path between nodes.
					findpath(i,j);
				}
			printf(" V%d",j );
			printf("\n");
		}
}	

//formatting and displaying distance matrix
printf("\n");
printf("The Distance matrix is:\n");
printf("	");
for(int u=1;u<=count;u++)
{
	printf("%d	",u);
}

printf("\n--------------------------------------------------------------------------\n");
	
for(int u=1;u<=count;u++)
{
	printf("%d|	",u);

	for(int i=1;i<=count;i++)
	{
		printf("%d	",arr[u][i]);
	}
printf("\n");
}	
fclose(f);
return 0;
}

//Function to find shortest path between nodes.
int findpath(int x,int y)
{
int q=p[x][y];
if(p[x][q]!=0)
	{
		findpath(x,q);
	}
printf(" V%d -",p[x][y]);
if(p[q][y]!=0)
	{
		findpath(q,y);
	}
return 0;
}
