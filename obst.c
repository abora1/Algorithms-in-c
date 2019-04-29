#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//structure for tree levels
struct level
{
	int root;
	int start;
	int end;
};


//function to find roots and constructing a tree
//takes number of keys and respective probabilities as an input
int obst(int keys, const float p[])
{
	//declarations
	float A[keys+1][keys+1];
	int root[keys+1][keys+1];
	int a,b,diag,i,j,rt;
	float temp1, temp2;

	//initializing root and cost matrix
	for(a=0;a<=keys+1;a++)
	{
		for(b=0;b<=keys+1;b++)
		{
			if(a==b)
			{
				A[a][b]=p[b];
				root[a][b]=a;
			}
			else
			{
				root[a][b]=0;
				A[a][b]=0;
			}
		}
	}

	//finding root
	//calculating root and cost matrix
	for(diag=1;diag<=keys-1;diag++)
	{
		for(i= 1; i<=keys-diag; i++)
		{
			j=i+diag;

			//temporary min value
			temp1=9035415;

			for(int x=i; x<=j;x++)
			{
				float prob=0;
				for(int x=i; x<=j;x++)
				{
					prob=prob+p[x];
				}

				//calculating min value
				temp2= A[i][x-1]+ A[x+1][j]+prob;
				if(temp1>temp2)
				{
					temp1=temp2;
					rt=x;
				}
				A[i][j]=temp1;
				root[i][j]=rt;
			}
		}
	}


	//function to find nodes at different level of tree
	void tree(int start, int end, int level)
	{
		int visited=0;
		int node;
		int total=pow(2,keys);
		
		//initializing structure
		struct level lev[total];

		int c=0;
		int i=1;
		printf("\nTree:");
		do
		{
			//i==1 denotes the initial root node at depths 0
			if(i==1)
			{
				printf("\ndepth %d:",c);
				c++;
			}
			else
			{
				int c3=pow(2,c);
				if(i==c3)
				{
					printf("\ndepth %d:",c);
					c++;
				}

			}	
			//other depths are considered after the root.
			if(i!= 1)
			{
				//dividing tree into two parts
				if(i%2 != 0)
				{
					start =  lev[i/2].root+1;
					end = lev[i/2].end;
				}
				else
				{
					start= lev[i/2].start;
					end= lev[i/2].root-1;
				}
			}

			//visit nodes
			if(start > end)
			{
				node = 0;		
			}
			else if(lev[i/2].root == 0 && i!=1)
			{
				node = 0;
			}
			else
			{
				node = root[start][end];
				visited++;
			}

			//exit if all nodes are visited
			if(visited == keys)
			{
				printf("%d",node);
				i=total+1;
			}
			else
			{
				printf("%d,",node);
			}

			lev[i].root= node;
			lev[i].start=start;
			lev[i].end=end;
			i++;
		}while(i<total);
		printf("\n");

	}

	//calling tree function to find nodes
	tree(1,keys,0);

 return 0;
}


int main(int argc,char *argv[])
{
	//taking number of keys as an input from user
	int keys = atoi(argv[1]);
	//initialization
	float sum= 0.0;
	float p[keys];

	//taking probabilities from user
	for(int i=1; i<=keys; i++)
	{
		p[i]= atof(argv[i+1]);
		sum= sum+ p[i];
	}
	//check if total probabilty is 1
	if(sum!=1.000000)
	{
		printf("Total Probability is not 1\n");
	}
	else
	{
		//calling the optimal binary search tree function
		obst(keys,p);
	}

	return 0;
}


