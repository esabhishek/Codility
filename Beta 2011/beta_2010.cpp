//Codility Beta 2010 Solution

// you can use includes, for example:
#include <algorithm>
#include <vector>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
using namespace std;
int binary_search(long long *A, long long val, int N)
{
    int start = 0;
    int end = N -1;
    int mid = (start + end)/2;
   
    while (end >= start && end >= 0 && start < N)
    {
         mid = (start + end)/2;
         //cout<<"\nStart:"<<start<<" Mid:"<<mid<<" End:"<<end;
         if (A[mid] == val)
             return mid;
         else if (A[mid] > val)
             end =  mid - 1;
         else
             start = mid + 1;
    }
    
    return mid;
}
int solution(vector<int> &A) {
    // write your code in C++11
   
    int N = A.size();
    long long starting_pos[N];
    long long ending_pos[N];
 
    
    long total_intersections  = 0;
    for (long long i = 0 ; i < N ; i++)
    {
        long long start = i - A[i];
        long long end = i + A[i];
        starting_pos[i] = start;
        ending_pos[i] = end;
    }
   
    std::sort(starting_pos, starting_pos+N);
    std::sort(ending_pos, ending_pos + N);

    for (long long i = 0 ; i < N ; i++)
    {
        //cout<<endl<<"Index : "<<i;
        //Eliminate all disks whose ending point is before my starting point
        int return_index = binary_search(ending_pos,  i - A[i], N );
        
        int j = return_index;
       
        if ((i - A[i]) == ending_pos[return_index])
        {
            while( j >= 0 && ((i - A[i]) == ending_pos[j]))
            {
                j--;
            }

        }
        else if (ending_pos[return_index] > (i - A[i]))
        {
           j--;
        }
        long subtract = 0;
        if (j >= 0 )
            subtract += j+1;
        //cout<<" j : "<<j<<" Subtract 1 : "<<subtract;

        //Eliminate all disks whose starting point is after my ending point
        return_index = binary_search(starting_pos,  i + A[i], N );
        //cout<<" Starting after my ending "<<return_index;
        j = return_index;
        
        if ((i + A[i]) == starting_pos[return_index])
        {
            while( j < N && ((i + A[i]) == starting_pos[j]))
            {
                j++;
            }

        }
        else if (starting_pos[return_index] < (i + A[i]))
        {
           j++;
        }
        
        if (j < N )
            {
                subtract+= (N - j);
                //cout<<" Subtract 2:"<<N-j;
            }
        //cout<<" Effective"<<subtract;
        total_intersections += N - 1 - subtract;
        
        if (total_intersections/2 > 10000000)
            return -1;
      
    }
    
    return total_intersections/2;
   
}

