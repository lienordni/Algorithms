namespace tree_functions {

	template <class T>
		struct node {

		public:

			T key;
			unsigned char height;
			node* left;
			node* right;

			node (T);

		};

	template <class T>
	node<T>::node(T k) {
		key=k;
		height=1;
		left=NULL;
		right=NULL;
	}

	template <typename T>
		unsigned char height(node<T>* p)
		{
			return p?p->height:0;
		}

	template <typename T>
		int bfactor(node<T>* p)
		{
			return height(p->right)-height(p->left);
		}

	template <typename T>
		void fixheight(node<T>* p)
		{
			unsigned char hl=height(p->left);
			unsigned char hr=height(p->right);
			p->height=(hl>hr?hl:hr)+1;
		}

	template <typename T>
		node<T>* rotateright(node<T>* p)
		{
			node<T>* q=p->left;
			p->left=q->right;
			q->right=p;
			fixheight(p);
			fixheight(q);
			return q;
		}

	template <typename T>
		node<T>* rotateleft(node<T>* q)
		{
			node<T>* p=q->right;
			q->right=p->left;
			p->left=q;
			fixheight(q);
			fixheight(p);
			return p;
		}

	template <typename T>
		node<T>* balance(node<T>* p) // balancing the p node
		{
			fixheight(p);
			if(bfactor(p)==2)
			{
				if(bfactor(p->right)<0)
					p->right=rotateright(p->right);
				return rotateleft(p);
			}
			if(bfactor(p)==-2)
			{
				if(bfactor(p->left)>0 )
					p->left=rotateleft(p->left);
				return rotateright(p);
			}
			return p; // balancing is not required
		}

	template <typename T>
		node<T>* insert(node<T>* p, T k) // insert k key in a tree with p root
		{
			if(!p)
				return new node<T>(k);
			if(k<p->key)
				p->left=insert(p->left,k);
			else
				p->right=insert(p->right,k);
			return balance(p);
		}

	template <typename T>
		node<T>* findmin(node<T>* p) // find a node with minimal key in a p tree 
		{
			return p->left?findmin(p->left):p;
		}

	template <typename T>
		node<T>* removemin(node<T>* p) // deleting a node with minimal key from a p tree
		{
			if(p->left==0)
				return p->right;
			p->left=removemin(p->left);
			return balance(p);
		}


	template <typename T>
		node<T>* remove(node<T>* p, T k) {
			if(!p)
				return 0;

			else if(k<p->key)
				p->left=remove(p->left,k);

			else if(k>p->key)
				p->right=remove(p->right,k);

			else {
				node<T>* q=p->left;
				node<T>* r=p->right;
				delete p;
				if(!r)
					return q;

				node<T>* min=findmin(r);
				min->right=removemin(r);
				min->left=q;
				return balance(min);
			}

			return balance(p);
		}

	template <typename T>
		bool search(node<T>* p, T k) {
			if(!p)
				return false;

			if(p->key<k)
				return search(p->right,k);

			else if(p->key>k)
				return search(p->left,k);

			return true;
		}

	template <typename T>
		void print(node<T>* p) {
			if(!p)
				return;

			std::cout<<p->key<<"  ";
			print(p->left);
			print(p->right);
		}
}

