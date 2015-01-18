// you can use includes, for example:
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int printSumPossibility(vector<int> A)
{
    cout<<endl<<endl;
    for(int i = 0 ; i < A.size(); i++)
        cout<< i <<"  ";
    cout<<endl;
    for(int ele : A)
        cout<< ele <<"  ";

}
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
//
int solution(vector<int> &A) {

	if (A.size() == 0)
		return 0;
	int maxElement = A[0];
        int totalSum = 0;	
	vector<int> elementCounts(101); 

	for (int i = 0 ; i < 101; i++)
	{
		elementCounts[i] = 0; 
	}
	for (int i = 0 ; i < A.size(); i++)
  	{
  	    if (A[i] < 0)
	    {
	        A[i] = -A[i];
	    }
	    
	    if (A[i] > maxElement)
		    maxElement = A[i];
	    
	    elementCounts[A[i]]++;
	    totalSum += A[i];
	}

	//cout<<"Counts : ";
	//printSumPossibility(elementCounts);
        
	int midPoint = totalSum/2;
	int maxSum = midPoint + maxElement + 1;
	
	vector<int> sumPossibility(maxSum);
	//cout<<endl<<" MaxSum : "<<maxSum<<endl;
	for (int i = 0 ; i < maxSum; i++)
	{

		sumPossibility[i]= -2;
	}

	for (int i = 1; i <= maxElement; i++)
	{
	    //cout<<endl<<"============================================"<<endl<<i<<endl<<"==============================================";
	    if (elementCounts[i] == 0)
		    continue;
	    sumPossibility[0] = elementCounts[i];
	    //printSumPossibility(sumPossibility);
	    for (int j = i ; j < maxSum; j++)
	    {
	           if (sumPossibility[j] == -2)
		   {
	               if (sumPossibility[j-i] == -1)
		       {
		           sumPossibility[j] = elementCounts[i] - 1;
		       }
		       else if (sumPossibility[j - i] > 0)
		       {
		           sumPossibility[j] = sumPossibility[j-i] - 1;
		       }
		   } 
	    }
	    //printSumPossibility(sumPossibility);
	    for (int j = 0 ; j < maxSum; j++)
	    {
	        sumPossibility[j] = ((sumPossibility[j] >= -1) ? -1 : -2); 
	    }
	    //printSumPossibility(sumPossibility);
        }
        int i;
	int ans = 0;
	for (i = midPoint + maxElement; i >= 0 ; i-- )
	{
		if (sumPossibility[i] == -1)
		{
			if (i > midPoint)
			    ans = 2*i - totalSum;
			else 
			{
			    if ((totalSum - 2*i) < ans)
				    ans = totalSum - 2*i;
			    break;
			}
		}

	}
        //cout<<endl<<endl<<"i after returning : "<<i<<" Answer : "<<ans;
	return (ans);
	   
}

int main(int argc, char *argv[])
{
    vector<int> A;
    A.push_back(2);
    A.push_back(3);
    A.push_back(4);
    A.push_back(100);
    //A.push_back(1);
    
    //A.push_back(10);
    //A.push_back(1);
    int ans = solution(A);
    cout<<"Answer : "<<ans<<endl; 
}

