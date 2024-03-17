#include <iostream>
#include <algorithm>
using namespace std; 

//排序 
void QuickSort(int array[], int low, int high) 
{
    int i = low; //i=0
    int j = high; //j=n-1
    if(i >= j) 
	{
        return;
    }
 
    int temp = array[low]; //temp=a[0]
    while(i != j) 
	{
        while(array[j] >= temp && i < j) 
		{
            j--;
        }
	    while(array[i] <= temp && i < j) 
		{
            i++;
        }
        
		if(i < j) 
		{
            swap(array[i], array[j]);
        }
    }
 
    //将基准temp放于自己的位置，（第i个位置）
    swap(array[low], array[i]);
    QuickSort(array, low, i - 1);
    QuickSort(array, i + 1, high);
}

//求最大公约数
int gcd(int x,int y) 
{
	int r=0;
	if(x==y)
	{
		return y;
	}
	else if(x>y)
	{
		r=x%y;
		while(r!=0)
		{
			int temp=x;
			x=y;
			y=r;
			r=x%y;
		}
		return y;
	}
	else
	{
		int s=x;
		x=y;
		y=s;
		gcd(x,y);
	}
}

int main()
{
	int n,N,d;
	cin>>n;
	int a[100000];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	//排序 
	QuickSort(a,0,n-1);
	
	int b[100000];
	
	for(int i=0;i<(n-1);i++)
	{
		b[i]=a[i+1]-a[i];
	}
	int x=b[0];
	//求公差（即最大公约数）
	for(int i=1;i<(n-1);i++)
	{
		int y=b[i];
		x=gcd(x,y);
	} 
	
	if(x==0)
	cout<<n<<endl;
	else
	{
		cout<<((a[n-1]-a[0])/x)+1<<endl;
	}
	
	return 0;
}
