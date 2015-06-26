#include <iostream>
#include <vector>
#include <cstdlib>

std::vector<int> sort( std::vector<int> vec, int startIndex, int endIndex){
	if( startIndex == endIndex ){
		std::vector<int> baby;
		baby.push_back( vec[startIndex]);
		return baby;
	}
	if( startIndex+1 == endIndex){
		std::vector<int> baby;
		if( vec[startIndex] > vec[endIndex] ){
			baby.push_back( vec[endIndex]);
			baby.push_back( vec[startIndex]);
		}
		else{
			baby.push_back( vec[startIndex]);
			baby.push_back( vec[endIndex]);
		}
		return baby;
	}

	int middle = (endIndex+startIndex)/2;
	std::vector<int> leftSorted = sort( vec, startIndex, middle);
	std::vector<int> rightSorted = sort( vec, middle+1, endIndex);

	int leftCount = leftSorted.size();
	int rightCount = rightSorted.size();

	std::vector<int> combined ;

	int lsi=0, rsi=0;

	while( lsi<leftCount and rsi<rightCount){
		if( leftSorted[lsi] < rightSorted[rsi]){
			combined.push_back( leftSorted[lsi]) ;
			++lsi;
		}
		else{
			combined.push_back( rightSorted[rsi]) ;
			++rsi;
		}
	}
	if( lsi == leftCount ){
		while( rsi < rightCount ){
			combined.push_back(rightSorted[rsi]) ;
			++rsi;
		}

	}
	if( rsi == rightCount){
		while( lsi < leftCount ){
			combined.push_back(leftSorted[lsi]);
			++lsi;
		}
	}
	return combined;
}

int main(int argc, char * argv[]){
	std::vector<int> vec;

	for(int i=1; i<argc; i++){
		vec.push_back( atoi(argv[i]));
	}

	vec = sort(vec, 0, vec.size()-1);

	for(int i=0; i<(vec.size()-1) ; i++){
		std::cout << vec[i] << "=>" ;
	}
	std::cout << "end" << std::endl;
}