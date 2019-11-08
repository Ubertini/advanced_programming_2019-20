#include<iostream>

int primes(int *&);

int main(){
	int* prime = NULL;
	std::cout<<prime<<std::endl;
	int n=primes(prime);
	std::cout<<prime<<std::endl;
	//std::cout<<n<<std::endl;
	for(std::size_t i{0};i<n;i++){
		std::cout<<prime[i]<<std::endl;
	}
}

int primes(int *&primes){
		std::size_t n;
		n=1;
		int static_primes[50]; //for sure there will be less than 50 prime numbers 
		static_primes[0]=2;		  //in this way I'm exluding all the even numbers and at the end of the 
		unsigned int remainder=0;   //function the array will be cancelled since it is initalized on the stack
		for(std::size_t i{1};i<50;i++){
			int number_to_check=2*i+1;
			int temp=0;
			for(std::size_t i{0};i<n;i++){
				remainder = number_to_check%static_primes[i];
				if(remainder!=0) temp+=1;
				else break;
			}
			if(temp==n){
				n+=1;			
				static_primes[n-1]=number_to_check;
				//std::cout<<static_primes[n-1]<<std::endl;
			}

		}
		primes=new int[n];
		for(std::size_t i{0};i<n;i++){
			primes[i]=static_primes[i];
			//std::cout<<primes[i]<<std::endl;
	}
	return n;
}