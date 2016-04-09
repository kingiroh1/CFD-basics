#include<stdio.h>

int main()
{
	// declaration of no. of grid points and time steps	
	float nx = 20;
	float nt = 50;
	float dt = 0.01;
	float dx;
	float c=1;
	dx = 2/(nx-1);
	printf("%f\n", dx);
	printf("\n");
	
	//domain discretization
	int i = 0;
	float x[20] = {0};
	for (i = 0; i<nx; i++)
	{
		if (i == 0)
		{
			x[i] = 0;
		}
		else
		{
		x[i] = x[i-1] + dx; 
		}
	}
	
	for (i = 0; i<nx; i++)
	{
		printf("%f\n", x[i]);
	}
	printf("\n");
	// imposing initial conditions
	float u[20] = {0};
	for (i = 0; i<nx; i++)
	{
		if (x[i]== 0)
		{
			u[i] = 1;
		}
		else if (x[i] == 2)
		{
			u[i] = 1;
		}
		else if (x[i] >= 0.5 && x[i] <= 1 )
		{
			u[i] = 2;
		}
		else 
		{
			u[i] = 1;
		}
	}
	for (i = 0; i<nx; i++)
	{
		printf("%f\n",u[i]);
	}
	
	// time marching step
	float un[20] = {0};
	// initializing 
	for (i=0;i<nx;i++)
	{
		un[i] = u[i];
	}
	
	printf("Before the time marching step, values of un are\n");
	
	for (i = 0; i<nx; i++)
	{
		printf("%f\n",un[i]);
	}
	
	int it = 0;
	int j;
	for (it=0;it<nt;it++)
	{
		for(j=0;j<nx;j++)
		{
			un[j] = u[j];	
		} 
		
		for (i=1;i<nx-1;i++)
		{
			u[i] = un[i] - c*(dt/dx)*(un[i] - un[i-1]);
		}
	}
	
	printf("The values of u(i) after 50 time steps are\n");
	for (i=0;i<nx;i++)
	{
		printf("%f\n", u[i]);
	}
	
	
return 0;
}
	
	
