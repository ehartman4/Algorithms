

///WHERE I STAND NOW: probably a problem with root assignemt. check the various places roots are referenced.
//                    i hope to god the whole passnode thign makes sense in the morning.
#include <iostream>
#include <assert.h>
#include <math.h>

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
        for (int j = 0; j <= i; ++j)
        {
            cout<<showNode->dataLeft;
            if (showNode->numData==2)
            {
                cout<<showNode->dataRight;
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
                    showNode = showNode->parent->right;
                }
            }
            else if (showNode == showNode->parent->middle)
            {
                showNode = showNode->parent->right;
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
}

template<class elemType>
void twoThreeTree<elemType>::doInorder(nodeType<elemType>* rooter) const{
    //if (rooter==NULL)
    //{
        
        //cout<<"The tree is empty."<<endl;
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
    cout<<"hey k"<<endl;

    if (root==NULL)
    {
        cout<<"hello, nonexistent tree!"<<endl;
        root = new nodeType <elemType>;
        root->numData = 1;
        root->dataLeft = a;
        root->left = NULL;
        root->right = NULL;
        root->middle = NULL;

        //i=-1;
    }
    //cout<<root->dataLeft<<endl;
    else
    {
        cout<<"hey k2"<<endl;

        nodeType <elemType> *checkNode = root;
        cout<<checkNode->dataLeft<<endl;
        cout<<checkNode->numData<<endl;
        cout<<root->numData<<endl;


        //this loop breaks when it finds where to insert new node
        while (i != -1)
        {
            //cout<<"hey k3"<<endl;
            cout<<"check"<<checkNode->dataLeft<<endl;
            if (checkNode->numData==2)
            {
                cout<<"checkright"<<checkNode->dataRight<<endl;
            }

            if (checkNode == NULL){
                nodeType <elemType> *checkNode = new nodeType <elemType>;
                cout<<"hello"<<endl;
                //checkNode->numData = 1;
                //checkNode->dataLeft = a;
                break;
            }
            else if (checkNode->numData==1)
            {
                cout<<"hello2"<<endl;
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
                cout<<"hello3"<<endl;
                if (checkNode->left == NULL and checkNode->middle == NULL and checkNode->right == NULL)
                    {
                        cout<<"oh yeahhhh"<<endl;
                        break;}
                else if (a < checkNode->dataLeft)
                {
                    checkNode = checkNode->left;
                }
                else if (a > checkNode->dataLeft and a < checkNode->dataRight)
                {
                    cout<<"i see you d"<<endl;
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
        int temppos = 0;

        cout<<"holla"<<endl;

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
                    /*passNode->left->parent = templeftNode;
                    passNode->right->parent = templeftNode;*/
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
                cout<<"whoopayyy2"<<endl;
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
                cout<<"whoopayyy3"<<endl;
                tempmidNode->left->dataLeft = checkNode->dataLeft;
                tempmidNode->left->left = checkNode->left;
                tempmidNode->left->right = checkNode->middle;
                if (checkNode->left and checkNode->right)
                {
                    cout<<"it happened"<<endl;

                    checkNode->left->parent = tempmidNode->left;
                    checkNode->middle->parent = tempmidNode->left;
                }
                tempmidNode->dataLeft = checkNode->dataRight;
                tempmidNode->right->dataLeft = passNode->dataLeft;
                tempmidNode->right->left = passNode->left;
                tempmidNode->right->right = passNode->right;
                if (passNode->left and passNode->right)
                {
                    cout<<"it also happened"<<endl;
                    passNode->left->parent = tempmidNode->right;
                    passNode->right->parent = tempmidNode->right;
                }
                cout<<"hrrrm"<<endl;
            }
            tempmidNode->left->parent = tempmidNode;
            tempmidNode->right->parent = tempmidNode;
            passNode = tempmidNode;
            checkNode = checkNode->parent;
            cout<<"makes it to here"<<endl;
            if(checkNode->parent)
            {
                cout<<checkNode->parent->dataLeft<<endl;
                if (checkNode->parent->numData==2)
                {
                    cout<<checkNode->parent->dataRight<<endl;
                }
            }
        }
        cout<<"huh?"<<endl;

        //old temp and new temp, new temp is parent, then at end have old temp = new temp
        //FOR THIS TO WORK: MUST MAKE MID NODE POINT TO LEFT AND RIGHT, MUST MAKE INITLA A = MIDNODE
        if (checkNode->numData == 1)
        {
            cout<<"hey there buddy"<<endl;
            if (passNode->dataLeft < checkNode->dataLeft)
            {
                cout<<passNode->dataLeft<<endl;
                cout<<"morehellos"<<endl;
                checkNode->dataRight = checkNode->dataLeft;
                checkNode->dataLeft = passNode->dataLeft;
                checkNode->left = passNode->left;
                checkNode->middle = passNode->right;
                if (checkNode->middle)
                {
                    cout<<"here"<<checkNode->middle->dataLeft<<endl;
                }
                
                if (passNode->left and passNode->right)
                {
                    passNode->left->parent = checkNode;
                    passNode->right->parent = checkNode;
                }
            }
            else
            {
                cout<<"morehellos3"<<endl;
                checkNode->dataRight = passNode->dataLeft;
                checkNode->middle = passNode->left;
                checkNode->right = passNode->right;
                if (passNode->left and passNode->right)
                {
                    //passNode->left->parent = checkNode;
                    checkNode->middle->parent = checkNode;
                    cout<<"morehellos7"<<endl;
                    //passNode->right->parent = checkNode;
                    checkNode->right->parent = checkNode;
                    cout<<"morehellos4"<<endl;
                }
                else{cout<<"how's it going?"<<endl;}

            }
            checkNode->numData = 2;
            if (checkNode != root)
            {
                cout<<"checkNode parent "<<checkNode->parent->dataLeft<<endl;
                if (checkNode->parent->parent==NULL)
                {
                    cout<<"huh."<<endl;
                }
                cout<<"check root"<<root->dataLeft<<endl;
            }
        }

        else if (checkNode == root)
        {
            cout<<"badaba"<<endl;
            if (root == NULL)
            {
                root = passNode;
                root->numData == 1;
            }
            else if (root->numData == 2)
            {
                cout<<"ohyeahalright "<<passNode->dataLeft<<endl;
                if (passNode->dataLeft < checkNode->dataLeft)
                {
                    cout<<"craycray1"<<endl;
                    //middle val/new parent is left val
                    tempmidNode->left->dataLeft = passNode->dataLeft;
                    tempmidNode->left->left = passNode->left;
                    tempmidNode->left->right = passNode->right;
                    if (passNode->left and passNode->right)
                    {
                        cout<<"craycray3"<<endl;
                        passNode->left->parent = tempmidNode->left;
                        passNode->right->parent = tempmidNode->left;
                    }
                    tempmidNode->dataLeft = checkNode->dataLeft;
                    tempmidNode->right->dataLeft = checkNode->dataRight;
                    tempmidNode->right->left = checkNode->middle;
                    tempmidNode->right->right = checkNode->right;
                    if (checkNode->left and checkNode->right)
                    {
                        cout<<"craycray4"<<endl;
                        checkNode->middle->parent = tempmidNode->right;
                        checkNode->right->parent = tempmidNode->right;
                    }       
                    
                }
                else if (passNode->dataLeft > checkNode->dataLeft and passNode->dataLeft < checkNode->dataRight)
                {
                    cout<<"craycray2"<<tempmidNode->left->dataLeft<<endl;
                    tempmidNode->left->dataLeft = checkNode->dataLeft;
                    tempmidNode->left->left = checkNode->left;
                    cout<<"checkie this out "<<passNode->left->dataLeft<<endl;
                    tempmidNode->left->right = passNode->left;
                    tempmidNode->dataLeft = passNode->dataLeft;
                    tempmidNode->right->dataLeft = checkNode->dataRight;
                    tempmidNode->right->left = passNode->right;
                    tempmidNode->right->right = checkNode->right;
                    if (passNode->left and passNode->right)
                    {
                        cout<<"craycray5"<<endl;
                        passNode->left->parent = tempmidNode->left;
                        passNode->right->parent = tempmidNode->right;
                    }
                    
                    if (checkNode->left and checkNode->right)
                    {
                        cout<<"craycray6"<<endl;
                        checkNode->left->parent = tempmidNode->left;
                        checkNode->right->parent = tempmidNode->right;
                    }
                }
                else if (passNode->dataLeft > checkNode->dataRight)
                {
                    //middle val/new parent is left val
                    cout<<"whoopayyy4"<<endl;
                    tempmidNode->left->dataLeft = checkNode->dataLeft;
                    tempmidNode->left->left = checkNode->left;
                    tempmidNode->left->right = checkNode->middle;
                    if (checkNode->left and checkNode->right)
                    {
                        cout<<"craycray7"<<endl;
                        checkNode->left->parent = tempmidNode->left;
                        checkNode->middle->parent = tempmidNode->left;
                    }
                    
                    tempmidNode->dataLeft = checkNode->dataRight;
                    tempmidNode->right->dataLeft = passNode->dataLeft;
                    tempmidNode->right->left = passNode->left;
                    tempmidNode->right->right = passNode->right;
                    cout<<"whoopayyy6"<<endl;
                    if (passNode->left and passNode->right)
                    {
                        cout<<"craycray8"<<endl;

                        passNode->left->parent = tempmidNode->right;
                        passNode->right->parent = tempmidNode->right;
                    }
                    
                    cout<<"whoopayyy7"<<endl;
                    
                }
                tempmidNode->left->parent = tempmidNode;
                tempmidNode->right->parent = tempmidNode;
                root = tempmidNode;
            }
        }
    }
    cout<<"ROOT NUMDATA"<<root->numData<<endl;

    if (a == 'i')
    {
        cout<<root->dataLeft<<endl;
        cout<<root->left->dataLeft<<endl;
        cout<<root->left->left->dataLeft<<endl;
        cout<<root->left->right->dataLeft<<endl;
        cout<<root->right->dataLeft<<endl;
        cout<<root->right->left->dataLeft<<endl;
        cout<<root->right->right->dataLeft<<endl;
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
