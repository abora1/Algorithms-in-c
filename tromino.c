#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//termino number
int tromino=0;

//declaring array for board
int tiles[10000][10000];

int trominoTile(int dim, int rsp, int csp)
{
	//declare variables
	int x,y;

	//trivial case if size is 2*2
	if(dim==2)
		{
			//increase termino number
			tromino=tromino+1;

			//placing termino
			for(int i=rsp;i<rsp+dim;i++)
			{
				for (int j=csp; j<csp+dim ; j++)
				{
					//check if it is the initial hole
					if(tiles[i][j]==-1001)
					{
						tiles[i][j]=-1001;
					}
					//if blank space then place termino
					else if(tiles[i][j]==0)
					{
						tiles[i][j]=tromino;

					}
				}
			}
			return 0;
		}
		else
		{
			//finding quadrant of the hole
			for(int i=rsp;i<rsp+dim;i++)
			{
				for (int j=csp; j<csp+dim ; j++)
				{
					if(tiles[i][j]!=0)
					{
						x=i;
						y=j;
					}
				}
			}

			/*if hole is in 1st quadrant
			 *place one termino in remaining three quadrants.
			 *this will act as a hole for remaining quadrants
			 */
			if(x<(dim/2)+rsp && y<(dim/2)+csp)
			{
				tromino = tromino +1;
				tiles[(dim/2)+rsp-1][(dim/2)+csp]=tromino;
				tiles[(dim/2)+rsp][(dim/2)+csp-1]=tromino;
				tiles[(dim/2)+rsp][(dim/2)+csp]=tromino;

			}
			/*if hole is in 2nd quadrant
			 *place one termino in remaining three quadrants.
			 *this will act as a hole for remaining quadrants
			 */
			else if(x>=(dim/2)+rsp && y<(dim/2)+csp)
			{
				tromino = tromino +1;
				tiles[(dim/2)+rsp-1][(dim/2)+csp-1]=tromino;
				tiles[(dim/2)+rsp-1][(dim/2)+csp]=tromino;
				tiles[(dim/2)+rsp][(dim/2)+csp]=tromino;
			}
			/*if hole is in 3rd quadrant
			 *place one termino in remaining three quadrants.
			 *this will act as a hole for remaining quadrants
			 */
			else if(x<(dim/2)+rsp&& y>=(dim/2)+csp)
			{
				tromino = tromino +1;
				tiles[(dim/2)+rsp-1][(dim/2)+csp-1]=tromino;
				tiles[(dim/2)+rsp][(dim/2)+csp-1]=tromino;
				tiles[(dim/2)+rsp][(dim/2)+csp]=tromino;
			}
			/*if hole is in 4th quadrant
			 *place one termino in remaining three quadrants.
			 *this will act as a hole for remaining quadrants
			 */
			else
			{
				tromino = tromino +1;
				tiles[(dim/2)+rsp-1][(dim/2)-1+csp]=tromino;
				tiles[(dim/2)+rsp][(dim/2)-1+csp]=tromino;
				tiles[(dim/2)+rsp-1][(dim/2)+csp]=tromino;
			}

			//calling the trominoTile function recursively to find holes and put terminos
			trominoTile(dim/2, rsp, csp);
			trominoTile(dim/2, rsp, (csp+(dim/2)));
			trominoTile(dim/2, (rsp+(dim/2)), csp);
			trominoTile(dim/2, (rsp+(dim/2)), (csp+(dim/2)));

		}
	return 0;
}


int main(int argc, char *args[])
{
	//taking input for size
	double dim1= atof(args[1]);

	//check if size is not less than one
	while(dim1>0)
	{
		//calculating size of board
		int dim =pow(2,dim1);

		//position of hole
		int hrow=atoi(args[2]);
		int hcol=atoi(args[3]);

		//check if hole is not outside board
		if(hrow>=dim || hcol>=dim)
		{
			printf("hole is out of board\n");
			break;
		}
		else
		{
			//initializing board
			for(int i=0;i<dim;i++)
			{
				for (int j=0; j<dim ; j++)
				{
					tiles[i][j]=0;
				}
			}
			//place of hole
			tiles[hrow][hcol]=-1001;

			//calling termino tile function
			trominoTile(dim, 0, 0);

			//displaying board with trominos
			for(int i = 0; i < dim; i++)
			{
				for(int j = 0; j <dim; j++)
				{
					if(tiles[i][j]==-1001)
					{
						 printf("%-3s|","X");
					}
					else
					{
						 printf("%-3d|", tiles[i][j]);
					}
				}
				printf("\n");
				for(int j = 0; j <dim; j++)
				{
					printf("----");				
				}
				printf("\n");
			}
			break;
		}
	}
}
