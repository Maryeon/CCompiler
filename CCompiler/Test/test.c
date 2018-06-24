//int d=1+1;

int f(int n)
{
	if(n == 1)
	{
		return 1;
	}
	else if(n == 2)
	{
		return 1;
	}	
	else
	{
		return f(n - 1) + f(n - 2);
	}
}
int main(){
	int a = f(5);
	return  0;
}

