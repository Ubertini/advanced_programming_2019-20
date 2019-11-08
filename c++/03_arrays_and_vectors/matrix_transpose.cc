#include<iostream>
#include<utility>
#include<array>
#include<string>


template <std::size_t N>
void transpose(std::array<double,N>& a,int row, int col){
		std::array<double,N> appo_matrix;
		for(int i=0;i<N;i++){
			appo_matrix[i]=a[i];
		}
		for(int j=0;j<col;j++){
			for(int i=0;i<row;i++){
				a[j*row+i]=appo_matrix[i*col+j];
			}
		}
}

int main(){
	const int col=3;
	const int row=2;
	const std::size_t tot_element=col*row;
	std::array<double, tot_element> matrix;
	for(int i=0;i<row*col;i++){
		matrix[i]=i;
	}
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
		std::cout<<matrix[i*col+j]<< "\t";
		}
		std::cout<<std::endl;
	}
	std::cout<<std::endl;
	transpose(matrix,row,col);
		for(int j=0;j<col;j++){
			for(int i=0;i<row;i++){
				std::cout<<matrix[j*row+i]<< "\t";
			}
			std::cout<<std::endl;
		}
}


