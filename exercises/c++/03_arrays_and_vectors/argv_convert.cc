#include<iostream>
#include<utility>
#include<array>
#include<string>
#include <sstream>
#include<vector>

void transpose(std::vector<double>& a,int row, int col){
		std::vector<double> appo_matrix;
		for(int i=0;i<row*col;i++){
			appo_matrix.push_back(a[i]);
		}
		for(int j=0;j<col;j++){
			for(int i=0;i<row;i++){
				a[j*row+i]=appo_matrix[i*col+j];
			}
		}
}

int main(int argc, char* argv[]){
	std::size_t row;
	{
 	std::istringstream is{argv[1]};
 	is >> row;
	}
	std::size_t col;
	{
 	std::istringstream is{argv[2]};
 	is >> col;
	}
	std::vector<double> matrix;
	for(int i=0;i<row*col;i++){
		matrix.push_back(i);
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


