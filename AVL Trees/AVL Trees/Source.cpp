#include <iostream>
#include <string>

struct Node {
	Node(int keyPassed = 0, std::string infoPassed = "") : key(keyPassed) , info(infoPassed) { height = 1; right = nullptr; left = nullptr; }
	std::string info;
	int key;
	char height;		//here we will keep the max height of the subTree at this node
	Node *right;
	Node *left;
};

int bfactor(Node* node);
char height(Node* node);
void fixheight(Node* &node);
Node* rotateright(Node* &node);			
Node* rotateleft(Node* &node);
Node* balance(Node* &curRoot);
Node* insert(Node* &root,const int &key,const std::string &info);
Node* findmin(Node* p);
Node* removemin(Node* &p);
Node* remove(Node* &p, int key);

void mergeArrToTree(Node* &root);
void addToTheTree(Node* &root);
int askForKey();
void findInformationByKey(Node *root,int &key);
void printTree(Node *node, int spaces);
int task(Node *node, int &numberOfLeaves);
bool removeAllTree(Node* &node);


int main()
{
	Node * root = nullptr;	
	int choise;
	do
	{
		std::cout << "\nPlease, enter what would you like to do?\n"
			<< "1. Merge info from array to Tree\n"
			<< "2. Add new info to the Tree\n"
			<< "3. Balance Tree\n"
			<< "4. Find the information by key\n"
			<< "5. Print Tree\n"
			<< "6. Number of Leaves on the left part of Tree(TASK)\n"
			<< "7. Delete Node from Tree\n"
			<< "8. Delete Tree\n"
			<< "0. Go away\n"
			<< "so, kid, your choise: ";
		if (!(std::cin >> choise))
			choise = 0;		std::cout << '\n';		//by default

		switch (choise)
		{
		case 0: break;
		case 1: mergeArrToTree(root); break;
		case 2: addToTheTree(root); 
			std::cout << "element added to the tree!\n"; break;
		case 3: root = balance(root);	//this function is useless because my Tree is always balanced and call this function implicitly)
			std::cout << "tree balanced!\n"; break;
		case 4: 
			if (root != nullptr)
			{
				int key = askForKey();
				findInformationByKey(root, key);
			} else
				std::cout << "Tree is empty!\n";
			break;
		case 5: 
			{
				int spaces = 0;
				printTree(root, spaces);
				break;
			}
		case 6: 
			if (root != nullptr)
			{
				int numberOfLeaves = 0;
				numberOfLeaves = task(root->left, numberOfLeaves);
				std::cout << "number of Leaves in the left part: " << numberOfLeaves << '\n';
			}	else 
				std::cout << "Tree is empty!\n"; 
			break;
		case 7: 
			if (root != nullptr)
			{
				int key = askForKey();
				root = remove(root, key);
			}
				else
					std::cout << "Tree is empty!\n"; 
			break;
		case 8: 
			if (removeAllTree(root))
				std::cout << "Tree deleted!\n";
			else
				std::cout << "Tree is empty!\n";
			break;
		default: choise = 0; break;
		}
	} while (choise);
	removeAllTree(root);
	system("pause");
	return 0;
}

//////////////////////////////////////////////////////functions///////////////////////////////////////////////////////
char height(Node* node)		//returns max height of subtree at tris node
{
	return node != nullptr ? node->height : 0;
}

int bfactor(Node* node)		//returns the result of subtraction of the heights of the left and right subTrees 
{
	return height(node->right) - height(node->left);
}

void fixheight(Node* &node)
{
	char hl = height(node->left);
	char hr = height(node->right);
	node->height = (hl>hr ? hl : hr) + 1;
}

Node* rotateright(Node* &node) //right rotation around the node
{
	Node* q = node->left;
	node->left = q->right;
	q->right = node;
	fixheight(node);
	fixheight(q);
	return q;
}

Node* rotateleft(Node* &node) //left rotation around the node
{
	Node* p = node->right;
	node->right = p->left;
	p->left = node;
	fixheight(node);
	fixheight(p);
	return p;
}

Node* balance(Node* &curRoot) // balance node by curRoot
{
	if (curRoot == nullptr)
	{
		std::cout << "empty root\n";
		return nullptr;
	}

	fixheight(curRoot);
	
	if (bfactor(curRoot) == 2)
	{
		if (bfactor(curRoot->right) < 0)
			curRoot->right = rotateright(curRoot->right);
		return rotateleft(curRoot);
	}
	if (bfactor(curRoot) == -2)
	{
		if (bfactor(curRoot->left) > 0)
			curRoot->left = rotateleft(curRoot->left);
		return rotateright(curRoot);
	}
	return curRoot; // do not need balance
}

Node* insert(Node* &root,const int &key,const std::string &info) // вставка ключа k в дерево с корнем p
{
	if (root == nullptr) return new Node(key, info);
	if (key<root->key)
		root->left = insert(root->left, key, info);
	else
		root->right = insert(root->right, key, info);
	return balance(root);
}

Node* findmin(Node* p) // find node with min key in the subTree(p)
{
	return p->left != nullptr ? findmin(p->left) : p;
}

Node* removemin(Node* &p) // delete node with min key from subTree(p)
{
	if (p->left == nullptr)
		return p->right;
	p->left = removemin(p->left);
	return balance(p);
}

Node* remove(Node* &p, int key) // delete key from node p
{
	if (p == nullptr) return nullptr;
	if (key < p->key)
		p->left = remove(p->left, key);
	else if (key > p->key)
		p->right = remove(p->right, key);
	else //  k == p->key 
	{
		Node* q = p->left;
		Node* r = p->right;
		delete p;
		std::cout << "element deleted from Tree!\n";
		if (r == nullptr) return q;			
		Node* min = findmin(r);
		min->right = removemin(r);
		min->left = q;
		return balance(min);
	}
	return balance(p);
}

void addToTheTree(Node* &root)
{
	Node *temp = new Node;
	while (true)
	{
		std::cout << "key of element: ";
		if (!(std::cin >> temp->key))
		{
			std::cout << "kid, be more precisely while working at keyboard! try again!\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		}
		else break;
	}

	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');		//ignore \n for getline()

	while (true)
	{
		std::cout << "string of element: ";
		if (!(std::getline(std::cin,temp->info)))	//read whole string(returns void * stream, but compiler convert to bool implicitly
		{
			std::cout << "kid, be more precisely while working at keyboard! try again!\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else break;
	}

	root = insert(root, temp->key, temp->info);
}

void mergeArrToTree(Node* &root)
{
	unsigned int numberOfEl = 0;
	while (true)
	{
		std::cout << "print the number of elements in array(0-to quit): ";
		if (!(std::cin >> numberOfEl))
		{
			std::cout << "invalid numbers entered! Try again!\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
			if (numberOfEl == 0)
				return;
			else
				break;
	}

	for (unsigned int i = 0; i < numberOfEl; i++)
	{
		std::cout << i + 1<<' ';
		addToTheTree(root);
	}
	std::cout << "array Merged!\n";
}

int askForKey()
{
	int key;
	while (true)
	{
		std::cout << "Please, enter key to find information: ";
		if (!(std::cin >> key))
		{
			std::cout << "Invalid input! Try again!\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
			break;
	}
	return key;
}

void findInformationByKey(Node *root,int &key)
{
	if (root->key == key)
	{
		std::cout << "finded element by key " << key << " is string = " << root->info << '\n';
	}

	if (root->left != nullptr) findInformationByKey(root->left, key);
	if (root->right != nullptr) findInformationByKey(root->right, key);
}
//here piece of shit//
void printTree(Node *node, int spaces)
{
	if (node == nullptr)
	{
		std::cout << "empty tree!\n";
		return;
	}
	spaces++;

	if (node->right != nullptr)
		printTree(node->right, spaces);

	for (int i = 0; i < spaces; i++)
		std::cout << "  ";
	std::cout << node->key << '\n';

	if (node->left != nullptr)
		printTree(node->left, spaces);
}

int task(Node *node, int &numberOfLeaves)
{
	bool isLeave = true;
	if (node == nullptr)
		return 0;
	else
	{
		if (node->left != nullptr)
		{
			task(node->left, numberOfLeaves);
			isLeave = false;
		}

		if (node->right != nullptr)
		{
			task(node->right, numberOfLeaves);
			isLeave = false;
		}

		if (isLeave) numberOfLeaves++;
		return numberOfLeaves;
	}
}

bool removeAllTree(Node* &node)
{
	if (node == nullptr)
		return false;

	if (node->left != nullptr) removeAllTree(node->left);
	if (node->right != nullptr) removeAllTree(node->right);

	delete node;
	node = nullptr;
	return true;
}