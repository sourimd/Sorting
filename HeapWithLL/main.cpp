#include <iostream>
#include <cstdlib>
#include <vector>
#include "TreeNode.h"

void insert( TreeNode ** rt, TreeNode ** preg, TreeNode ** last, int v){
	if( *rt == NULL){
		*rt = new TreeNode(v);
		*preg = *rt;
		*last = *rt;
	}
	else{
		(*last)->setNext( new TreeNode(v));
		TreeNode * temp = *last;
		*last = (*last)->getNext();
		(*last)->setPrev( temp);

		if( (*preg)->getLeft() == NULL){
			(*preg)->setLeft( *last);
			(*last)->setParent( *preg);
		}
		else{
			(*preg)->setRight( *last);
			(*last)->setParent( *preg);
			*preg = (*preg)->getNext();
		}
	}
}

void disp( TreeNode * rt){
	while( rt != NULL){
		std::cout << rt->getValue() << "->";
		rt = rt->getNext();
	}
	std::cout << "end" << std::endl;
}

void dispRev( TreeNode * rt){
	while( rt != NULL){
		std::cout << rt->getValue() << "->";
		rt = rt->getPrev();
	}
	std::cout << "end" << std::endl;
}

void siftDown( TreeNode ** p){
	TreeNode * q = *p;
	while( q != NULL){
		if( q->getLeft() == NULL and q->getRight() == NULL){
			return;
		}
		else if( q->getLeft() != NULL and q->getRight() == NULL){
			if( q->getValue() > q->getLeft()->getValue() ){
				int temp = q->getValue();
				q->setValue( q->getLeft()->getValue());
				q->getLeft()->setValue( temp);
				q = q->getLeft();
				continue;
			}
			else{
				return;
			}
		}
		else{
			if( q->getValue() < q->getLeft()->getValue() and q->getValue() < q->getRight()->getValue()){
				return;
			}
			else if( q->getValue() > q->getLeft()->getValue() and q->getValue() < q->getRight()->getValue() ){
				// swap with left
				int temp = q->getValue();
				q->setValue( q->getLeft()->getValue());
				q->getLeft()->setValue( temp);
				q = q->getLeft();
				continue;
			}
			else if( q->getValue() < q->getLeft()->getValue() and q->getValue() > q->getRight()->getValue() ){
				// swap with right
				int temp = q->getValue();
				q->setValue( q->getRight()->getValue());
				q->getRight()->setValue( temp);
				q = q->getRight();
				continue;
			}
			else{
				if( q->getLeft()->getValue() < q->getRight()->getValue()){
					// swap with left
					int temp = q->getValue();
					q->setValue( q->getLeft()->getValue());
					q->getLeft()->setValue( temp);
					q = q->getLeft();
					continue;
				}
				else{
					// swap with right
					int temp = q->getValue();
					q->setValue( q->getRight()->getValue());
					q->getRight()->setValue( temp);
					q = q->getRight();
					continue;
				}
			}
		}
	}
}

void heapify( TreeNode ** node){
	TreeNode * p = *node;
	while( p != NULL){
		siftDown( &p);
		p=p->getPrev();
	}
}

void heapSort( TreeNode ** rt, TreeNode ** lt, std::vector<int> & vec){
	TreeNode * temp = *lt;
	TreeNode * tempParent;
	//TreeNode * temp2;

	while( temp != NULL){
		if( temp == *rt){
			vec.push_back( (*rt)->getValue() );
			break;
		}
		vec.push_back( (*rt)->getValue() );
		(*rt)->setValue( temp->getValue() );
		tempParent = temp->getParent();
		if( tempParent->getRight() == temp){
			tempParent->setRight(NULL);
		}
		if( tempParent->getLeft() == temp){
			tempParent->setLeft(NULL);
		}
		temp = temp->getPrev();
		if( temp!=NULL){
			temp->setNext( NULL);
		}
		
		//delete temp1;
		//temp1 = NULL;
		siftDown( rt);
	}
}

std::ostream & operator<<( std::ostream & out, const std::vector<int> & vec){
	int max = vec.size();
	for(int i=0; i< max; i++){
		out << vec[i] << "=>";
	}
	out << "end";
	return out;
}

int main(int argc, char * argv[]){
	TreeNode * root = NULL;
	TreeNode * pregnant = NULL;
	TreeNode * lastOneInserted = NULL;

	std::vector<int> vec;

	for( int i=1; i<argc; i++){
		insert( &root, &pregnant, &lastOneInserted, atoi(argv[i]));
	}

	disp( root);
	dispRev( lastOneInserted);

	heapify( &lastOneInserted);

	std::cout << root->getValue() <<" "<< lastOneInserted->getValue() << std::endl;

	disp( root);

	heapSort( &root, &lastOneInserted, vec);

	std::cout << vec << std::endl;
}