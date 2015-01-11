#include "stdio.h"
#include "string"
#include "stdlib.h"
#include "iostream"
using namespace std;
int calculate_palindromes(int * arr, int len)
{   
    int i;	
    int total = 0;
    for (i = 0 ; i < len;  i++)
    {
        total += arr[i]/2;
        if (total > 100000000)
            return -1;
    }
    
    return total;
}
string interleave_string_special_character(string &s)
{
    
    string new_string = "";
    int i, j;

    for (i = 0, j = 0 ; i < s.length(); i++ )
    {
        new_string.insert(j, 1 , '*');
	j++;
        new_string.insert(j, 1 , s[i]);
	j++;
    }
    
     new_string.insert(j, 1 , '*');
    
    return new_string;
}


// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

int solution(string &s) 
{
    // write your code in C99
    string new_string = interleave_string_special_character(s);
    cout<<new_string;
    int mirror_point = 0;
    int centre = 0;
    int right = 0;
    int mid = 0;
    int *counts = new int[new_string.length()]; 
    int temp = 0;
    int temp1 = 0;
    //Loop through center characters
    for (centre = 0; centre < new_string.length(); centre++)
    {
        counts[centre] = 0;

	//Find point of symmetry
	mirror_point = mid - (centre - mid); 
        if (right > centre)
	{
            temp = counts[mirror_point];
            temp1 = right - centre;
            counts[centre] = (temp < temp1) ? temp : temp1 ;
        } 
        
        while((centre - counts[centre] - 1 >= 0 ) 
	       && (centre + counts[centre] + 1 < new_string.length()) 
	       &&  new_string[centre + counts[centre] + 1] == new_string[centre - counts[centre] - 1] )
          counts[centre]++;
	
        if (right < centre + counts[centre])
	{
	    mid = centre;
	    right = centre + counts[centre];
	}	  
	    	
    }

    int ans = calculate_palindromes(counts, new_string.length());
    return ans;
    
}


int main()
{
    string s = "XXX";	    
    printf(" \n Ans = %d \n", solution(s));
}
