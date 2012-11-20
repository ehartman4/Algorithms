

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
    int i = 2;
    nodeType <elemType> *checkNode = root;
    //this loop breaks when it find where to insert new node
    while (i != 1)
    {
        
        if (checkNode == NULL){
            nodeType <elemType> *checkNode = new nodeType <elemType>;
            //checkNode->numData = 1;
            //checkNode->dataLeft = a;
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
                {break;}
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
    passNode->numData = 1;
    passNode->dataLeft = a;
    int temppos = 0;
    while (checkNode->numData == 2 and checkNode != root)
    {

        if (passNode->dataLeft < checkNode->dataLeft)
        {
            //middle val/new parent is left val
            templeftNode->dataLeft = passNode->dataLeft;
            templeftNode->left = passNode->left;
            templeftNode->right = passNode->right;
            passNode->left->parent = templeftNode;
            passNode->right->parent = templeftNode;
            tempmidNode->dataLeft = checkNode->dataLeft;
            temprightNode->dataLeft = checkNode->dataRight;
            temprightNode->left = checkNode->left;
            temprightNode->right = checkNode->right;
            checkNode->left->parent = temprightNode;
            checkNode->right->parent = temprightNode;
            
        }
        else if (passNode->dataLeft > checkNode->dataLeft and passNode->dataLeft < checkNode->dataRight)
        {
            //middle val/new parent is left val
            templeftNode->dataLeft = checkNode->dataLeft;
            templeftNode->left = checkNode->left;
            templeftNode->right = passNode->left;
            checkNode->left->parent = templeftNode;
            passNode->left->parent = templeftNode;
            tempmidNode->dataLeft = passNode->dataLeft;
            temprightNode->dataLeft = checkNode->dataRight;
            temprightNode->left = passNode->right;
            temprightNode->right = checkNode->right;
            passNode->right->parent = temprightNode;
            checkNode->right->parent = temprightNode;
            
        }
        else if (passNode->dataLeft > checkNode->dataRight)
        {
            //middle val/new parent is left val
            templeftNode->dataLeft = checkNode->dataLeft;
            templeftNode->left = checkNode->left;
            templeftNode->right = checkNode->right;
            checkNode->left->parent = templeftNode;
            checkNode->right->parent = templeftNode;
            tempmidNode->dataLeft = checkNode->dataRight;
            temprightNode->dataLeft = passNode->dataLeft;
            temprightNode->left = passNode->left;
            temprightNode->right = passNode->right;
            passNode->left->parent = temprightNode;
            passNode->right->parent = temprightNode;
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
    //FOR THIS TO WORK: MUST MAKE MID NODE POINT TO LEFT AND RIGHT, MUST MAKE INITLA A = MIDNODE
    if (checkNode->numData == 1)
    {
        if (passNode->dataLeft < checkNode->dataLeft)
        {
            checkNode->dataRight = checkNode->dataLeft;
            checkNode->dataLeft = passNode->dataLeft;
            checkNode->left = passNode->left;
            passNode->left->parent = checkNode;
            checkNode->middle = passNode->right;
            passNode->right->parent = checkNode;

        }
        else
        {
            checkNode->dataRight = passNode->dataLeft;
            checkNode->middle = passNode->left;
            passNode->left->parent = checkNode;
            checkNode->right = passNode->right;
            passNode->right->parent = checkNode;
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
                templeftNode->dataLeft = passNode->dataLeft;
                templeftNode->left = passNode->left;
                templeftNode->right = passNode->right;
                passNode->left->parent = templeftNode;
                passNode->right->parent = templeftNode;
                tempmidNode->dataLeft = checkNode->dataLeft;
                temprightNode->dataLeft = checkNode->dataRight;
                temprightNode->left = checkNode->left;
                temprightNode->right = checkNode->right;
                checkNode->left->parent = temprightNode;
                checkNode->right->parent = temprightNode;
                
            }
            else if (passNode->dataLeft > checkNode->dataLeft and passNode->dataLeft < checkNode->dataRight)
            {
                //middle val/new parent is left val
                templeftNode->dataLeft = checkNode->dataLeft;
                templeftNode->left = checkNode->left;
                templeftNode->right = passNode->left;
                checkNode->left->parent = templeftNode;
                passNode->left->parent = templeftNode;
                tempmidNode->dataLeft = passNode->dataLeft;
                temprightNode->dataLeft = checkNode->dataRight;
                temprightNode->left = passNode->right;
                temprightNode->right = checkNode->right;
                passNode->right->parent = temprightNode;
                checkNode->right->parent = temprightNode;
                
            }
            else if (passNode->dataLeft > checkNode->dataRight)
            {
                //middle val/new parent is left val
                templeftNode->dataLeft = checkNode->dataLeft;
                templeftNode->left = checkNode->left;
                templeftNode->right = checkNode->right;
                checkNode->left->parent = templeftNode;
                checkNode->right->parent = templeftNode;
                tempmidNode->dataLeft = checkNode->dataRight;
                temprightNode->dataLeft = passNode->dataLeft;
                temprightNode->left = passNode->left;
                temprightNode->right = passNode->right;
                passNode->left->parent = temprightNode;
                passNode->right->parent = temprightNode;
                
            }
            tempmidNode->left = templeftNode;
            tempmidNode->right = temprightNode;
            templeftNode->parent = tempmidNode;
            temprightNode->parent = tempmidNode;
            root = tempmidNode;
        }
    }

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
    myTree.insert ('b');
    myTree.insert ('g');
    myTree.insert ('k');
    myTree.insert ('p');
    myTree.insert ('d');
    myTree.insert ('i');

    cout << "Inorder traversal: " << endl;
    //myTree.inorder ();

    cout << "Display tree: " << endl;
    //myTree.display ();

    return 0;
}
