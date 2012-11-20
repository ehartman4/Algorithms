

///WHERE I STAND NOW: probably a problem with root assignemt. check the various places roots are referenced.
//                    i hope to god the whole passnode thign makes sense in the morning.
#include<iostream>
#include<assert.h>

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

        i=-1;
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
                    {cout<<"helloagain"<<endl;break;}
                else if (a < checkNode->dataLeft)
                {
                    cout<<"helloagain2"<<endl;
                    checkNode = checkNode->left;
                }
                else if (a > checkNode->dataLeft)
                {
                    cout<<"helloagain3"<<endl;
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
                    checkNode = checkNode->middle;
                }
                else if (a > checkNode->dataRight)
                {
                    checkNode = checkNode->right;
                }
            }
        }//end while loop finding where to insert node. checkNode should now be the node in which the new value is inserted.

        //now to insert.
        nodeType <elemType> *templeftNode = new nodeType<elemType>;
        nodeType <elemType> *temprightNode = new nodeType<elemType>;
        nodeType <elemType> *tempmidNode = new nodeType<elemType>;
        nodeType <elemType> *passNode = new nodeType<elemType>;
        templeftNode->left = NULL, templeftNode->middle = NULL, templeftNode->right = NULL, templeftNode->numData = 1;
        temprightNode->left = NULL, temprightNode->middle = NULL, temprightNode->right = NULL,temprightNode->numData = 1;
        tempmidNode->left = NULL, tempmidNode->middle = NULL, tempmidNode->right = NULL,tempmidNode->numData = 1;
        passNode->left = NULL, passNode->middle = NULL, passNode->right = NULL,passNode->numData = 1;
        
        passNode->dataLeft = a;
        int temppos = 0;
        //checkNode->left = NULL;
        //checkNode->numData = 1;
        cout<<"holla"<<endl;
        /*
        if(checkNode->left)
        {
            cout<<"hello80"<<endl;
        }
        else{cout<<"poop"<<endl;}
        */
        //cout<<"hello4"<<checkNode->left<<endl;

        if (checkNode != root)
        {
            cout<<"hello6"<<endl;
        }
        else
        {
            cout<<"hello7"<<endl;
        }

        while (checkNode->numData == 2 and checkNode != root)
        {
            cout<<"hello5"<<endl;
            if (passNode->dataLeft < checkNode->dataLeft)
            {
                //middle val/new parent is left val
                cout<<"whoopayyy"<<endl;
                templeftNode->dataLeft = passNode->dataLeft;
                templeftNode->left = passNode->left;
                templeftNode->right = passNode->right;
                if (passNode->left and passNode->right)
                {
                    passNode->left->parent = templeftNode;
                    passNode->right->parent = templeftNode;
                }
                tempmidNode->dataLeft = checkNode->dataLeft;
                temprightNode->dataLeft = checkNode->dataRight;
                temprightNode->left = checkNode->left;
                temprightNode->right = checkNode->right;
                if (checkNode->left and checkNode->right)
                {
                    checkNode->left->parent = temprightNode;
                    checkNode->right->parent = temprightNode;
                }
                
            }
            else if (passNode->dataLeft > checkNode->dataLeft and passNode->dataLeft < checkNode->dataRight)
            {
                //middle val/new parent is left val
                cout<<"whoopayyy2"<<endl;
                templeftNode->dataLeft = checkNode->dataLeft;
                templeftNode->left = checkNode->left;
                templeftNode->right = passNode->left;
                
                tempmidNode->dataLeft = passNode->dataLeft;
                temprightNode->dataLeft = checkNode->dataRight;
                temprightNode->left = passNode->right;
                temprightNode->right = checkNode->right;
                if (passNode->left and passNode->right)
                {
                    passNode->left->parent = templeftNode;
                    passNode->right->parent = temprightNode;
                }
                if (checkNode->left and checkNode->right)
                {
                    checkNode->left->parent = templeftNode;
                    checkNode->right->parent = temprightNode;
                }
                
            }
            else if (passNode->dataLeft > checkNode->dataRight)
            {
                //middle val/new parent is left val
                cout<<"whoopayyy3"<<endl;
                templeftNode->dataLeft = checkNode->dataLeft;
                templeftNode->left = checkNode->left;
                templeftNode->right = checkNode->right;
                if (checkNode->left and checkNode->right)
                {
                    checkNode->left->parent = templeftNode;
                    checkNode->right->parent = templeftNode;
                }
                tempmidNode->dataLeft = checkNode->dataRight;
                temprightNode->dataLeft = passNode->dataLeft;
                temprightNode->left = passNode->left;
                temprightNode->right = passNode->right;
                if (passNode->left and passNode->right)
                {
                    passNode->left->parent = temprightNode;
                    passNode->right->parent = temprightNode;
                }
            }
            tempmidNode->left = templeftNode;
            tempmidNode->right = temprightNode;
            templeftNode->parent = tempmidNode;
            temprightNode->parent = tempmidNode;
            passNode = tempmidNode;
            /* SAME THING NOW DONE OUTSIDE OF WHILE LOOP BELOW
            if (checkNode->parent->numData == 1)
            {
                //NOW TO CHANGE PARENT:
                if (tempmidNode->dataLeft < checkNode->parent->dataLeft)
                {
                    checkNode->parent->dataRight = checkNode->parent->dataLeft;
                    checkNode->parent->dataLeft = tempmidNode->dataLeft;
                    checkNode->parent->left = templeftNode;
                    checkNode->parent->middle = temprightNode;
                }
                else if (tempmidNode->dataLeft > checkNode->parent->dataLeft)
                {
                    checkNode->parent->dataRight = tempmidNode->dataLeft;
                    checkNode->parent->middle = templeftNode;
                    checkNode->parent->right = temprightNode;
                }
                checkNode->parent->numData = 2;
                //END CHANGE PARENT
            }
            */
            /*
            else if (checkNode->parent->numData == 2)
            {
                tempmidNode->left = templeftNode;
                tempmidNode->right = temprightNode;
                if (tempmidNode->dataLeft < checkNode->parent->dataLeft)
                {

                }
                else if (tempmidNode->dataLeft > checkNode->parent->dataLeft and tempmidNode->dataLeft < checkNode->parent->dataRight)
                {
                    
                }
                else if (tempmidNode->dataLeft > checkNode->parent->dataRight)
                {

                }
            }
            */
            //passNode = tempmidNode;
            checkNode = checkNode->parent;

        }
        cout<<"huh?"<<endl;
        //FOR THIS TO WORK: MUST MAKE MID NODE POINT TO LEFT AND RIGHT, MUST MAKE INITLA A = MIDNODE
        if (checkNode->numData == 1)
        {
            cout<<"hey there buddy"<<endl;
            if (passNode->dataLeft < checkNode->dataLeft)
            {
                cout<<"morehellos"<<endl;
                checkNode->dataRight = checkNode->dataLeft;
                checkNode->dataLeft = passNode->dataLeft;
                checkNode->left = passNode->left;
                checkNode->middle = passNode->right;
                if (passNode->left and passNode->right)
                {
                    passNode->left->parent = checkNode;
                    passNode->right->parent = checkNode;
                }
                cout<<"morehellos2"<<endl;


            }
            else
            {
                cout<<"morehellos3"<<endl;
                checkNode->dataRight = passNode->dataLeft;
                checkNode->middle = passNode->left;
                checkNode->right = passNode->right;
                if (passNode->left and passNode->right)
                {
                    passNode->left->parent = checkNode;
                    cout<<"morehellos7"<<endl;
                    passNode->right->parent = checkNode;
                    cout<<"morehellos4"<<endl;
                }
                else{cout<<"how's it going?"<<endl;}

            }
            checkNode->numData = 2;       
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
                cout<<"ohyeahalright"<<endl;
                if (passNode->dataLeft < checkNode->dataLeft)
                {
                    //middle val/new parent is left val
                    templeftNode->dataLeft = passNode->dataLeft;
                    templeftNode->left = passNode->left;
                    templeftNode->right = passNode->right;
                    if (passNode->left and passNode->right)
                    {
                        passNode->left->parent = templeftNode;
                        passNode->right->parent = templeftNode;
                    }
                    tempmidNode->dataLeft = checkNode->dataLeft;
                    temprightNode->dataLeft = checkNode->dataRight;
                    temprightNode->left = checkNode->left;
                    temprightNode->right = checkNode->right;
                    if (checkNode->left and checkNode->right)
                    {
                        checkNode->left->parent = temprightNode;
                        checkNode->right->parent = temprightNode;
                    }       
                    
                }
                else if (passNode->dataLeft > checkNode->dataLeft and passNode->dataLeft < checkNode->dataRight)
                {
                    //middle val/new parent is left val
                    templeftNode->dataLeft = checkNode->dataLeft;
                    templeftNode->left = checkNode->left;
                    templeftNode->right = passNode->left;
                    tempmidNode->dataLeft = passNode->dataLeft;
                    temprightNode->dataLeft = checkNode->dataRight;
                    temprightNode->left = passNode->right;
                    temprightNode->right = checkNode->right;
                    if (passNode->left and passNode->right)
                    {
                        passNode->left->parent = templeftNode;
                        passNode->right->parent = temprightNode;
                    }
                    
                    if (checkNode->left and checkNode->right)
                    {
                        checkNode->left->parent = templeftNode;
                        checkNode->right->parent = temprightNode;
                    }
                }
                else if (passNode->dataLeft > checkNode->dataRight)
                {
                    //middle val/new parent is left val
                    cout<<"whoopayyy4"<<endl;
                    templeftNode->dataLeft = checkNode->dataLeft;
                    templeftNode->left = checkNode->left;
                    templeftNode->right = checkNode->right;
                    if (checkNode->left and checkNode->right)
                    {
                        checkNode->left->parent = templeftNode;
                        checkNode->right->parent = templeftNode;
                    }
                    
                    tempmidNode->dataLeft = checkNode->dataRight;
                    temprightNode->dataLeft = passNode->dataLeft;
                    temprightNode->left = passNode->left;
                    temprightNode->right = passNode->right;
                    cout<<"whoopayyy6"<<endl;
                    if (passNode->left and passNode->right)
                    {
                        passNode->left->parent = temprightNode;
                        passNode->right->parent = temprightNode;
                    }
                    
                    cout<<"whoopayyy7"<<endl;
                    
                }
                tempmidNode->left = templeftNode;
                tempmidNode->right = temprightNode;
                templeftNode->parent = tempmidNode;
                temprightNode->parent = tempmidNode;
                root = tempmidNode;
            }
        }
    }
    cout<<"ROOT NUMDATA"<<root->numData<<endl;

}


    /*
    ////////////////////////////////
    else if (checkNode->left == NULL and checkNode->middle == NULL and checkNode->right == NULL)
    {
        //no children and 1 data value inside
        if (checkNode->numData==1)
        {
            if (a < checkNode->dataLeft)
            {
                checkNode->dataRight = checkNode->dataLeft;
                checkNode->dataLeft = a;
            }
            else{checkNode->dataRight = a;}
            checkNode->numData=2;
        }
        //no children and 2 data values inside (move something up)
        else if (checkNode->numData==2)
        {
            if (a < checkNode->dataLeft)
            {
                //middle val/new parent is left val
                insert(PAPANODE = checkNode->dataLeft);
                nodeType <elemType> leftNode = new nodeType<elemType>;
                leftNode->left = checkNode->left;
                leftNode->right = checkNode->middle;
                checkNode->left = leftNode;
                nodeType <elemType> rightNode = new nodeType<elemType>;
                rightNode->right = checkNode->right;
                checkNode->right = rightNode;
            }
            else if (a > checkNode->dataLeft and a < checkNode->dataRight)
            {
                //middle val/new parent is new val
                PAPANODE = checkNode->a;
            }
            else if (a > checkNode->dataRight)
            {
                //middle val/new parent is right val
                PAPANODE = checkNode->dataRight;
            }
        }
    }
    //if a 2-node
    else if (checkNode->numData==1)
    {
        if (a < checkNode->dataLeft)
        {
            //now look at left child
            NEWCHECKNODE = checkNode->left;
        }
        else if (a > checkNode->dataLeft)
        {
            //now look at right child
            NEWCHECKNODE = checkNode->right;
        }
    }
    //if a 3-node
    else if (checkNode->numData==2)
    {
        if (a < checkNode->dataLeft)
        {
            //now look at left child
            NEWCHECKNODE = checkNode->left;
        }
        else if (a > checkNode->dataLeft and a < checkNode->dataRight)
        {
            //now look at middle child
            NEWCHECKNODE = checkNode->middle;
        }
        else if (a > checkNode->dataRight)
        {
            //now look at right child
            NEWCHECKNODE = checkNode->right;
        }
    }
    */

//

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

    cout << "Inorder traversal: " << endl;
    //myTree.inorder ();

    cout << "Display tree: " << endl;
    //myTree.display ();

    return 0;
}
