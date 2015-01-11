#include "stdio.h"
#include "string.h"
#include "stdlib.h"
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
char* interleave_string_special_character(char *s, int str_len)
{
    int new_length = (2 * str_len ) + 1;
    char* new_string = (char *) malloc(sizeof(char) * new_length);
    int i, j;

    for (i = 0, j = 0 ; i < str_len; i++ )
    {
        new_string[j++] = '*';
        new_string[j++] = s[i];
    }
    
    new_string[j++] = '*';
    new_string[j] = 0;
    return new_string;
}


// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

int solution(char *s) {
    // write your code in C99
    char *new = interleave_string_special_character(s, strlen(s));
    int mirror_point = 0;
    int centre = 0;
    int right = 0;
    int mid = 0;
    int *counts = (int *) malloc(sizeof(int) * strlen(new));
    int temp = 0;
    int temp1 = 0;
    //Loop through center characters
    for (centre = 0; centre < strlen(new); centre++)
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
        
        /*if (counts[centre] > 0)
	    printf(" \n Reuse at %d", centre);*/
            
        while((centre - counts[centre] - 1 >= 0 ) 
	       && (centre + counts[centre] + 1 < strlen(new)) 
	       &&  new[centre + counts[centre] + 1] == new[centre - counts[centre] - 1] )
          counts[centre]++;
	
        if (right < centre + counts[centre])
	{
	    mid = centre;
	    right = centre + counts[centre];
	}	  
	    	
    }

    int ans = calculate_palindromes(counts, strlen(new));
    //printf(" \nAns = %d \n", ans);
    return ans;
    
}


int main()
{
    char *s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
";
    printf(" \n Ans = %d \n", solution(s));
}
