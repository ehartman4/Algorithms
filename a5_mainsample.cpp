

///WHERE I STAND NOW: probably a problem with root assignemt. check the various places roots are referenced.
//                    i hope to god the whole passnode thign makes sense in the morning.
#include <iostream>
#include <assert.h>
#include <math.h>
#include <list>

using namespace std;

// 2-3 tree node (complete)
template <class elemType>
struct nodeType {
    elemType dataLeft;             // data item on "left" side of node
    elemType dataRight;            // data item on "right" side of node
    short numData;                 // number of data items (1 or 2)
    nodeType<elemType> *left;      // pointer to left subtree
    nodeType<elemType> *middle;    // pointer to middle subtree
    nodeType<elemType> *right;     // pointer to right subtree
    nodeType<elemType> *parent;    // pointer to parent (may not need)
};

// 2-3 tree class (start)
template <class elemType>
class twoThreeTree {
    nodeType<elemType> *root;
    void doInorder (nodeType<elemType> *) const;

    // add in other methods here, if needed

public:
    twoThreeTree () {root = NULL;};              // constructor
    void insert (const elemType);                // insert an item
    void inorder () const {doInorder (root);     // inorder traversal
                            cout << endl;};
    void display () const;                       // display the tree
};

template<class elemType>
void twoThreeTree<elemType>::display() const{
    nodeType <elemType> *checkNode = root;
    list< elemType > toPrint;
    int height = 0;
    while (checkNode->left)
    {
        height++;
        checkNode = checkNode->left;
    }
    int wid = pow(3,height);
    nodeType <elemType> *showNode = root;

    for (int i = 0; i <= height; ++i)
    {
        for (int j = 0; j < 3*(i+1); ++j)
        {
            int count = 0;
            if (showNode!=NULL)
            {
                toPrint.push_back(showNode->dataLeft);
                cout<<toPrint.back()<<endl;
                if (showNode->numData==2)
                {
                    toPrint.push_back(showNode->dataRight);
                    cout<<toPrint.back()<<endl;
                }
            }
            
            //to determine next show node:
            if (showNode->parent == NULL)
            {
                showNode = showNode->left;
            }
            else if (showNode == showNode->parent->left)
            {
                if (showNode->parent->numData==2)
                {
                    showNode = showNode->parent->middle;
                }
                else
                {
                    j++;
                    showNode = showNode->parent->right;
                }
                
            }
            else if (showNode == showNode->parent->middle)
            {
                showNode = showNode->parent->right;
            }
            else if (showNode == showNode->parent->right)
            {
                if (showNode->parent->parent != NULL)
                {
                    
                    if (count<3*(i+1)-1)
                    {
                        if (showNode->parent == showNode->parent->parent->left)
                        {
                            if (showNode->parent->parent->numData==2)
                            {
                                showNode = showNode->parent->parent->middle->left;
                            }
                            else
                            {
                                j++;
                                showNode = showNode->parent->parent->right->left;
                            }
                        }
                        else if (showNode->parent == showNode->parent->parent->middle)
                        {
                            showNode = showNode->parent->parent->right->left;
                        }
                        else if (showNode->parent == showNode->parent->parent->right)
                        {
                            if (showNode->parent != NULL)
                            {
                                showNode = showNode->parent->parent->parent->middle;
                            }
                        }
                    }
                }
                else
                {
                    showNode = showNode->parent->left->left;
                }
            }
        }


        cout<<endl;
        /*
        if (root->numData==2)
        {
            cout<<setw(wid/2 - 2)<<root->dataLeft<<setw(2)<<root->dataRight<endl;
        }
        else
        {
            cout<<setw(wid/2)<<root->dataLeft<<endl;
        }
        */
    }
    elemType a;
    for (int i = 0; i < toPrint.size(); ++i)
    {
        if (toPrint.front())
        {
            //a = toPrint.pop_front();
            //cout<<a<<endl;
        }
        
    }
    
}

template<class elemType>
void twoThreeTree<elemType>::doInorder(nodeType<elemType>* rooter) const{
    nodeType <elemType> *checkNode = rooter;
    if (checkNode->left)
    {
        doInorder(checkNode->left);
    }
    cout<<checkNode->dataLeft<<endl;
    if (checkNode->numData==2)
    {
        if (checkNode->middle)
        {
            doInorder(checkNode->middle);
        }
        cout<<checkNode->dataRight<<endl;
    }
    if (checkNode->right)
    {
        doInorder(checkNode->right);
    }
}

template<class elemType>
void twoThreeTree<elemType>::insert(const elemType a){
    //check if root is empty
    //traverse to appropriate leaf
    //THEN worry about inserting.
    int i = 0;

    if (root==NULL)
    {
        root = new nodeType <elemType>;
        root->numData = 1;
        root->dataLeft = a;
        root->left = NULL;
        root->right = NULL;
        root->middle = NULL;

    }
    else
    {
        nodeType <elemType> *checkNode = root;
        //this loop breaks when it finds where to insert new node
        while (i != -1)
        {
            if (checkNode == NULL){
                nodeType <elemType> *checkNode = new nodeType <elemType>;
                break;
            }
            else if (checkNode->numData==1)
            {
                if (checkNode->left == NULL and checkNode->right == NULL)
                    {break;}
                else if (a < checkNode->dataLeft)
                {
                    checkNode = checkNode->left;
                }
                else if (a > checkNode->dataLeft)
                {
                    checkNode = checkNode->right;
                }
            }
            else if (checkNode->numData==2)
            {
                if (checkNode->left == NULL and checkNode->middle == NULL and checkNode->right == NULL)
                    {
                        break;
                    }
                else if (a < checkNode->dataLeft)
                {
                    checkNode = checkNode->left;
                }
                else if (a > checkNode->dataLeft and a < checkNode->dataRight)
                {
                    checkNode = checkNode->middle;
                }
                else if (a > checkNode->dataRight)
                {
                    checkNode = checkNode->right;
                }
            }
        }//end while loop finding where to insert node. checkNode should now be the node in which the new value is inserted.

        //now to insert.
        
        
        nodeType <elemType> *tempmidNode = new nodeType<elemType>;
        tempmidNode->left = new nodeType<elemType>;
        tempmidNode->right = new nodeType<elemType>;
        nodeType <elemType> *passNode = new nodeType<elemType>;
        tempmidNode->middle = NULL,tempmidNode->numData = 1;
        tempmidNode->left->left = NULL, tempmidNode->left->middle = NULL, tempmidNode->left->right = NULL, tempmidNode->left->numData = 1;
        tempmidNode->right->left = NULL, tempmidNode->right->middle = NULL, tempmidNode->right->right = NULL, tempmidNode->right->numData = 1;
        passNode->left = NULL, passNode->middle = NULL, passNode->right = NULL,passNode->numData = 1;
        passNode->dataLeft = a;

        while (checkNode->numData == 2 and checkNode != root)
        {
            nodeType <elemType> *tempmidNode = new nodeType<elemType>;
            tempmidNode->left = new nodeType<elemType>;
            tempmidNode->right = new nodeType<elemType>;
            tempmidNode->middle = NULL,tempmidNode->numData = 1;
            tempmidNode->left->left = NULL, tempmidNode->left->middle = NULL, tempmidNode->left->right = NULL, tempmidNode->left->numData = 1;
            tempmidNode->right->left = NULL, tempmidNode->right->middle = NULL, tempmidNode->right->right = NULL, tempmidNode->right->numData = 1;

            if (passNode->dataLeft < checkNode->dataLeft)
            {
                //middle val/new parent is left val

                tempmidNode->left->dataLeft = passNode->dataLeft;
                tempmidNode->left->left = passNode->left;
                tempmidNode->left->right = passNode->right;
                if (passNode->left and passNode->right)
                {
                    passNode->left->parent = tempmidNode->left;
                    passNode->right->parent = tempmidNode->left;
                }
                tempmidNode->dataLeft = checkNode->dataLeft;

                tempmidNode->right->dataLeft = checkNode->dataRight;
                tempmidNode->right->left = checkNode->middle;
                tempmidNode->right->right = checkNode->right;
                if (checkNode->left and checkNode->right)
                {
                    checkNode->middle->parent = tempmidNode->right;
                    checkNode->right->parent = tempmidNode->right;
                }
                
            }
            else if (passNode->dataLeft > checkNode->dataLeft and passNode->dataLeft < checkNode->dataRight)
            {
                //middle val/new parent is left val
                tempmidNode->left->dataLeft = checkNode->dataLeft;
                tempmidNode->left->left = checkNode->left;
                tempmidNode->left->right = passNode->left;

                tempmidNode->dataLeft = passNode->dataLeft;
                tempmidNode->right->dataLeft = checkNode->dataRight;
                tempmidNode->right->left = passNode->right;
                tempmidNode->right->right = checkNode->right;
                if (passNode->left and passNode->right)
                {
                    passNode->left->parent = tempmidNode->left;
                    passNode->right->parent = tempmidNode->right;
                }
                if (checkNode->left and checkNode->right)
                {
                    checkNode->left->parent = tempmidNode->left;
                    checkNode->right->parent = tempmidNode->right;
                }
                
            }
            else if (passNode->dataLeft > checkNode->dataRight)
            {
                //middle val/new parent is left val
                tempmidNode->left->dataLeft = checkNode->dataLeft;
                tempmidNode->left->left = checkNode->left;
                tempmidNode->left->right = checkNode->middle;
                if (checkNode->left and checkNode->right)
                {
                    checkNode->left->parent = tempmidNode->left;
                    checkNode->middle->parent = tempmidNode->left;
                }
                tempmidNode->dataLeft = checkNode->dataRight;
                tempmidNode->right->dataLeft = passNode->dataLeft;
                tempmidNode->right->left = passNode->left;
                tempmidNode->right->right = passNode->right;
                if (passNode->left and passNode->right)
                {
                    passNode->left->parent = tempmidNode->right;
                    passNode->right->parent = tempmidNode->right;
                }
            }
            tempmidNode->left->parent = tempmidNode;
            tempmidNode->right->parent = tempmidNode;
            passNode = tempmidNode;
            checkNode = checkNode->parent;
            
        }

        //old temp and new temp, new temp is parent, then at end have old temp = new temp
        //FOR THIS TO WORK: MUST MAKE MID NODE POINT TO LEFT AND RIGHT, MUST MAKE INITLA A = MIDNODE
        if (checkNode->numData == 1)
        {
            if (passNode->dataLeft < checkNode->dataLeft)
            {
                checkNode->dataRight = checkNode->dataLeft;
                checkNode->dataLeft = passNode->dataLeft;
                checkNode->left = passNode->left;
                checkNode->middle = passNode->right;                
                if (passNode->left and passNode->right)
                {
                    passNode->left->parent = checkNode;
                    passNode->right->parent = checkNode;
                }
            }
            else
            {
                checkNode->dataRight = passNode->dataLeft;
                checkNode->middle = passNode->left;
                checkNode->right = passNode->right;
                if (passNode->left and passNode->right)
                {
                    checkNode->middle->parent = checkNode;
                    checkNode->right->parent = checkNode;
                }

            }
            checkNode->numData = 2;
        }

        else if (checkNode == root)
        {
            if (root == NULL)
            {
                root = passNode;
                root->numData == 1;
            }
            else if (root->numData == 2)
            {
                if (passNode->dataLeft < checkNode->dataLeft)
                {
                    //middle val/new parent is left val
                    tempmidNode->left->dataLeft = passNode->dataLeft;
                    tempmidNode->left->left = passNode->left;
                    tempmidNode->left->right = passNode->right;
                    if (passNode->left and passNode->right)
                    {
                        passNode->left->parent = tempmidNode->left;
                        passNode->right->parent = tempmidNode->left;
                    }
                    tempmidNode->dataLeft = checkNode->dataLeft;
                    tempmidNode->right->dataLeft = checkNode->dataRight;
                    tempmidNode->right->left = checkNode->middle;
                    tempmidNode->right->right = checkNode->right;
                    if (checkNode->left and checkNode->right)
                    {
                        checkNode->middle->parent = tempmidNode->right;
                        checkNode->right->parent = tempmidNode->right;
                    }       
                }
                else if (passNode->dataLeft > checkNode->dataLeft and passNode->dataLeft < checkNode->dataRight)
                {
                    tempmidNode->left->dataLeft = checkNode->dataLeft;
                    tempmidNode->left->left = checkNode->left;
                    tempmidNode->left->right = passNode->left;
                    tempmidNode->dataLeft = passNode->dataLeft;
                    tempmidNode->right->dataLeft = checkNode->dataRight;
                    tempmidNode->right->left = passNode->right;
                    tempmidNode->right->right = checkNode->right;
                    if (passNode->left and passNode->right)
                    {
                        passNode->left->parent = tempmidNode->left;
                        passNode->right->parent = tempmidNode->right;
                    }
                    
                    if (checkNode->left and checkNode->right)
                    {
                        checkNode->left->parent = tempmidNode->left;
                        checkNode->right->parent = tempmidNode->right;
                    }
                }
                else if (passNode->dataLeft > checkNode->dataRight)
                {
                    //middle val/new parent is left val
                    tempmidNode->left->dataLeft = checkNode->dataLeft;
                    tempmidNode->left->left = checkNode->left;
                    tempmidNode->left->right = checkNode->middle;
                    if (checkNode->left and checkNode->right)
                    {
                        checkNode->left->parent = tempmidNode->left;
                        checkNode->middle->parent = tempmidNode->left;
                    }
                    
                    tempmidNode->dataLeft = checkNode->dataRight;
                    tempmidNode->right->dataLeft = passNode->dataLeft;
                    tempmidNode->right->left = passNode->left;
                    tempmidNode->right->right = passNode->right;
                    if (passNode->left and passNode->right)
                    {
                        passNode->left->parent = tempmidNode->right;
                        passNode->right->parent = tempmidNode->right;
                    }
                }
                tempmidNode->left->parent = tempmidNode;
                tempmidNode->right->parent = tempmidNode;
                root = tempmidNode;
            }
        }
    }
}

int main () {
    twoThreeTree<char> myTree;

    myTree.insert ('a');
    cout<<"starting 'b'"<<endl;
    myTree.insert ('b');
    cout<<"starting 'g'"<<endl;
    myTree.insert ('g');
    cout<<"starting 'k'"<<endl;
    myTree.insert ('k');
    cout<<"starting 'p'"<<endl;
    myTree.insert ('p');
    cout<<"starting 'd'"<<endl;
    myTree.insert ('d');
    cout<<"starting 'i'"<<endl;
    myTree.insert ('i');
    cout<<"starting 'l'"<<endl;
    myTree.insert ('l');
    cout<<"starting 'm'"<<endl;
    myTree.insert ('m');
    cout<<"starting 'n'"<<endl;
    myTree.insert ('n');
    cout<<"starting 'q'"<<endl;
    myTree.insert ('q');
    
    cout<<"starting 'r'"<<endl;
    myTree.insert ('r');

    cout<<"starting 'h'"<<endl;
    myTree.insert ('h');
    cout<<"starting 'f'"<<endl;
    myTree.insert ('f');
    cout<<"starting 'c'"<<endl;
    myTree.insert ('c');
    cout<<"starting 'j'"<<endl;
    myTree.insert ('j');
    cout<<"starting 'z'"<<endl;
    myTree.insert ('z');
    cout<<"starting 'x'"<<endl;
    myTree.insert ('x');
    cout<<"starting 'e'"<<endl;
    myTree.insert ('e');
    
    cout<<"starting 'y'"<<endl;
    myTree.insert ('y');
    cout<<"starting 'o'"<<endl;
    myTree.insert ('o');
    cout<<"starting 's'"<<endl;
    myTree.insert ('s');
    cout<<"starting 't'"<<endl;
    myTree.insert ('t');
    cout<<"starting 'u'"<<endl;
    myTree.insert ('u');
    


    cout << "Inorder traversal: " << endl;
    myTree.inorder ();

    cout << "Display tree: " << endl;
    myTree.display ();

    return 0;
}
