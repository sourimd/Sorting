#include <iostream>
#include <vector>
#include <cstdlib>

void swap( int & a, int & b){
	int temp = a;
	a = b;
	b = temp;
}

void siftDown( std::vector<int> & vec, int curIndex, int vecSize){
	// no child
	if( 2*curIndex + 1 > vecSize-1 and 2*curIndex+2 > vecSize-1){
		return;
	}
	//one child
	else if( 2*curIndex+1 <= vecSize-1 and 2*curIndex + 2 > vecSize-1 ){
		if( vec[curIndex] > vec[2*curIndex+1]){
			swap( vec[curIndex], vec[2*curIndex+1]);
		}
	}
	// two children
	else{
		// both less
		if( vec[curIndex] > vec[2*curIndex+1] and vec[curIndex] > vec[2*curIndex+2] ){
			if( vec[2*curIndex+1] > vec[2*curIndex+2] ){
				swap( vec[curIndex], vec[2*curIndex+2]);
				siftDown( vec, 2*curIndex+2, vecSize);
			}
			else{
				swap( vec[curIndex], vec[2*curIndex+1]);
				siftDown( vec, 2*curIndex+1, vecSize);
			}

		}
		// only right less
		else if( vec[curIndex] < vec[2*curIndex+1] and vec[curIndex] > vec[2*curIndex+2] ){
			swap( vec[curIndex], vec[2*curIndex+2]);
			siftDown( vec, 2*curIndex+2, vecSize);

		}
		//only left less
		else if( vec[curIndex] > vec[2*curIndex+1] and vec[curIndex] < vec[2*curIndex+2] ){
			swap( vec[curIndex], vec[2*curIndex+1]);
			siftDown( vec, 2*curIndex+1, vecSize);
		}
		else{
			return;
		}
	}
}

void heapify( std::vector<int> & vec, int size){
	int i = size-1;
	while(i>=0){
		siftDown( vec, i, size);
		--i;
	}
}

std::ostream & operator<<( std::ostream & out, const std::vector<int> & vec){
	int size = vec.size();
	for( int i=0; i<size; i++){
		out << vec[i] << "->";
	}
	out << "end" ;
	return out;
}

int main(int argc, char * argv[]){
	std::vector<int> vec;
	vec.reserve(argc-1);
	for(int i=1; i<argc; i++){
		vec.push_back( atoi(argv[i]));
	}

	heapify( vec, argc-1);

	std::cout << vec << std::endl;

	// heap sort

	int sz = argc-2;
	while( sz > 0){
		swap( vec[0], vec[sz]);
		siftDown( vec, 0, --sz);
	}

	std::cout << vec << std::endl;
}