int fun(int a,int b)
{
	return 67;
}
int abc()
{
	int z = 10*2+9/3;
	return z;
}
main()
{
	int x=2;
	if(x>0)
	{
		x=x++;
	}
	else
	{
		x=2;
		fun(x,3);
	}
	while(x)
	{
		abc();
		int y = x--;
	}
}
