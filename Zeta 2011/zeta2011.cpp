#include <iostream> 
#include <vector>

using namespace std; 

class state 
{ 

	public: 
		long from_left; 
		long from_top; 
		long to_bottom; 
		long to_right; 

		state() 
		{ 
	        	from_left = 0; 
			from_top = 0; 
			to_bottom = 0; 
			to_right = 0; 
		} 

		void compute_current_state(state *prev_state, state *curr_state, int this_row, int this_col, vector< vector<int> > &A) 

		{ 
			from_top = prev_state[this_col].to_bottom; 
			if (this_col > 0) 
				from_left = curr_state[this_col - 1].to_right; 

			if (A[this_row][this_col] == 0) 
			{ 
				to_right = from_left; 
				to_bottom = from_top; 
			} 

			else   
			{ 
				to_right = to_bottom = (from_left + from_top)/2; 
				if((from_left + from_top) % 2) 
				{ 

					if (A[this_row][this_col] == 1) 
					{ 

						to_right++; 
		
					} 

					else 

					{ 

						to_bottom++; 
					} 

				} 
			} 

		} 
		 

}; 

 

int solution(vector< vector<int> > &A, int K) 
{ 
	int N = A.size(); 
	int M = A[0].size(); 
	class state *prev = new state[M]; 
	class state *curr = new state[M]; 

	 

	//Initialize the prev_state 
        
	 for (int i = 0; i < M; i++) 
	 { 
	 	if (i == 0) 
	 	{ 
	 		prev[0].to_bottom = K; 
	        	prev[0].to_right = 0; 
	 	} 
	  
	        else 
		{ 
	
	       		prev[i].to_bottom = 0; 
		        prev[i].to_right = 0; 
	
	  	} 

	  } 
	
	
	  for (int i = 0 ; i < N; i++) 
	  { 
	  	for(int j = 0; j < M ; j++) 
		{ 
		
			curr[j].compute_current_state(prev, curr, i , j , A); 
	
		} 
		prev = curr; 
	
	  } 
	  
	  cout<<curr[M-1].to_bottom; 
	  return curr[M-1].to_bottom; 
}

int main()
{
	cout<<"Hello World";
	return 0;
}
	
	        
