class TreeNode{
private:
	int value;
	TreeNode * left;
	TreeNode * right;
	TreeNode * next;
	TreeNode * prev;
	TreeNode * parent;
public:
	TreeNode(int v):value(v),left(NULL),right(NULL),next(NULL),prev(NULL),parent(NULL){}
	~TreeNode(){
		if( left != NULL){
			delete left;
			left = NULL;
		}
		if( right != NULL){
			delete right;
			right = NULL;
		}

	}

	int getValue(){ return value; }
	TreeNode * getLeft(){ return left; }
	TreeNode * getRight(){ return right; }
	TreeNode * getNext(){ return next; }
	TreeNode * getPrev(){ return prev; }
	TreeNode * getParent(){ return parent; }

	void setValue(int v){ value = v; }
	void setLeft(TreeNode * l){ left = l; }
	void setRight(TreeNode * r){ right = r; }
	void setNext(TreeNode * n){ next = n; }
	void setPrev(TreeNode * p){ prev = p; }
	void setParent(TreeNode * p){ parent = p; }

};