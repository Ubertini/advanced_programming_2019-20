#include<iostream>
#include<cmath>

int main(){
	int n;
	std::cout<<"Enter N: the number of the below which you want to find prime numbers"<<std::endl;
	std::cin >> n;
	double nn=double(n);
	int* A=new int[n];
	A[0]=0;
	A[1]=0;
	for(int i=2;i<n;i++){
		A[i]=1;
	}	
	for(int i=2;i<std::sqrt(nn);i++){
		if(A[i]==1){
			int j=0;
			int appo=i*i+j*i;
			while(appo < n){
				A[i*i+j*i]=0;
				j+=1;
				appo = (i*i+j*i);
			}
		}
	}

	int number_of_primes=0;
	for(int i=0;i<n;i++){
		if(A[i]==1) number_of_primes+=1;
	}

	int* primes=new int[number_of_primes];
	int temp=0;
	for(int i{2};i<n;i++){
		if(A[i]==1) {
		primes[temp]=i;
		std::cout<<primes[temp]<<std::endl;
		temp+=1;
		}
	}
}