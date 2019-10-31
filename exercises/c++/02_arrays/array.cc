#include<iostream>

template <typename T>  /* typename or class is the same*/
T* initialize(const std::size_t);

template <typename T>  /* typename or class is the same*/
void print(const std::size_t, T*);

int main(){
	std::size_t n;
	std::cout << "Enter the length of the array\n";
	std::cin >> n;
	int* vec;
	vec = initialize<int>(n);
	print(n,vec);
	
}


template <typename T>  /* typename or class is the same*/
T* initialize(const std::size_t n){
	T temp{0};
	T* da{new T[n]};
	for(std::size_t i{0}; i < n; i++){
		std::cout << "Enter the value of the "<<i<<"th component\n";
		std::cin >> temp;
		da[i]=temp;	
	}
	return da;
}

template <typename T>
void print(const std::size_t n, T* vec){
	for(std::size_t i{0};i<n;i++){
		std::cout<<vec[n-1-i]<<std::endl;
	}
}