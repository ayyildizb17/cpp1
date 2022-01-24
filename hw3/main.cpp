//Buse AYYILDIZ 150170099

#include <queue>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
#include<bits/stdc++.h>
using namespace std;



struct VideoGames{
    string name;
    string publisher;
    string platform;
    int releaseYear;
    double naSales;
    double euSales;
    double otherSales;
    VideoGames(){
        naSales = 0;
        otherSales = 0;
        euSales = 0;
        releaseYear = 0;
    }
};

class Node {
public:
    VideoGames data;
    string color;
    Node *left;
    Node* right;
    Node* parent;

    Node(VideoGames data) : data(data) {
        parent = NULL;
        left = NULL;
        right = NULL;
        color = "RED"; //new inserted node will be red
    }

    Node *uncle() {
        if (parent == NULL or parent->parent == NULL)
            return NULL;

        if (parent->isOnLeft())
            return parent->parent->right;
        else
            return parent->parent->left;
    }
    //the function which returns a boolean value according to node is left child of parent or not
    bool isOnLeft() { return this == parent->left; }



    // moves node down and moves given node in its place
    void moveDown(Node *Parent) {
        if (parent != NULL) {
            if (isOnLeft()) {
                parent->left = Parent;
            } else {
                parent->right = Parent;
            }
        }
        Parent->parent = parent;
        parent = Parent;
    }


};

class RBTree {
    Node *root;

    // left rotates the given node
    void leftRotate(Node *x) {
        // new parent will be node's right child
        Node *nParent = x->right;

        // update root if current node is root
        if (x == root)
            root = nParent;

        x->moveDown(nParent);

        // connect x with new parent's left element
        x->right = nParent->left;
        // connect new parent's left element with node
        // if it is not null
        if (nParent->left != NULL)
            nParent->left->parent = x;

        // connect new parent with x
        nParent->left = x;
    }

    void rightRotate(Node *x) {
        // new parent will be node's left child
        Node *nParent = x->left;

        // update root if current node is root
        if (x == root)
            root = nParent;

        x->moveDown(nParent);

        // connect x with new parent's right element
        x->left = nParent->right;
        // connect new parent's right element with node
        // if it is not null
        if (nParent->right != NULL)
            nParent->right->parent = x;

        // connect new parent with x
        nParent->right = x;
    }

    void swapColors(Node *x1, Node *x2) {
        string colour;
        colour = x1->color;
        x1->color = x2->color;
        x2->color = colour;
    }


    // fix red red at given node
    void fixViolation(Node *x) {
        // if x is root color it black and return
        if (x == root) {
            x->color = "BLACK";
            return;
        }

        // initialize parent, grandparent, uncle
        Node *parent = x->parent, *grandparent = parent->parent,
                *uncle = x->uncle();

        if (parent->color != "BLACK") {
            if (uncle != NULL && uncle->color == "RED") {
                // uncle red, perform recoloring and recurse
                parent->color = "BLACK";
                uncle->color = "BLACK";
                grandparent->color = "RED";
                fixViolation(grandparent);
            } else {
                // Else perform LR, LL, RL, RR
                if (parent->isOnLeft()) {
                    if (x->isOnLeft()) {
                        // for left right
                        swapColors(parent, grandparent);
                    } else {
                        leftRotate(parent);
                        swapColors(x, grandparent);
                    }
                    // for left left and left right
                    rightRotate(grandparent);
                } else {
                    if (x->isOnLeft()) {
                        // for right left
                        rightRotate(parent);
                        swapColors(x, grandparent);
                    } else {
                        swapColors(parent, grandparent);
                    }

                    // for right right and right left
                    leftRotate(grandparent);
                }
            }
        }
    }

    // find node that do not have a left child
    // in the subtree of the given node




    // prints level order for given node
    void printHelper(Node *root) {
        if (root == NULL)
            // return if node is null
            return;

        cout<<"("<<root->color<<")"<<" "<<root->data.publisher<<endl;
        printHelper(root->left);
        printHelper(root->right);

    }




public:
    //constructor
    RBTree() { root = NULL; }
    Node* getRoot(){return root;}

    // searches for given value
    // if found returns the node (used for update sales)
    // else returns the last node while traversing (used in insert)
    Node *search(VideoGames n) {
        Node *temp = root;
        while (temp != NULL) {
            if (n.publisher < temp->data.publisher) {
                if (temp->left == NULL) {break;}
                else {temp = temp->left;}
            }
            else if (n.publisher == temp->data.publisher) {break;}

            else {
                if (temp->right == NULL) {break;}
                else {temp = temp->right;}
            }
        }

        return temp;
    }
    // inserts the given value to tree
    void insert(VideoGames n) {
        Node *newNode = new Node(n);
        if (root == NULL) {
            // when root is null
            // insert value as root
            newNode->color = "BLACK";
            root = newNode;
        } else {
            Node *temp = search(n);
            if (temp->data.publisher == n.publisher) {
                //if same publisher is inserted before update sales amount and return
                temp->data.euSales += n.euSales;
                temp->data.naSales += n.naSales;
                temp->data.otherSales += n.otherSales;
                return;
            }

            // if value is not found, search returns the node
            // where the value is to be inserted

            // connect new node to correct node
            newNode->parent = temp;

            if (n.publisher < temp->data.publisher)
                temp->left = newNode;
            else
                temp->right = newNode;

            // fix red red voilaton if exists
            fixViolation(newNode);
        }
    }
    VideoGames findMaxNa(Node *root){
        VideoGames n1;

        Node* temp = root;

        while(temp != NULL) {
            if (n1.naSales < temp->data.naSales) {
                n1 = temp->data;
                if (temp->left == NULL) { break; }
                else {
                    temp = temp->left;
                }
            } else if (n1.naSales == temp->data.naSales) { break; }
            else {
                if (temp->right == NULL) { break; }
                else { temp = temp->right; }
            }
        }

        return n1;
    }
    VideoGames findMaxEu(Node *root){
        VideoGames n1;

        Node* temp = root;

        while(temp != NULL) {
            if (n1.euSales < temp->data.euSales) {
                n1 = temp->data;
                if (temp->left == NULL) { break; }
                else {
                    temp = temp->left;
                }
            } else if (n1.euSales == temp->data.euSales) { break; }
            else {
                if (temp->right == NULL) { break; }
                else { temp = temp->right; }
            }
        }

        return n1;
    }
    VideoGames findMaxOther(Node *root){
        VideoGames n1;

        Node* temp = root;

        while(temp != NULL) {
            if (n1.otherSales < temp->data.otherSales) {
                n1 = temp->data;
                if (temp->left == NULL) { break; }
                else {
                    temp = temp->left;
                }
            } else if (n1.otherSales == temp->data.otherSales) { break; }
            else {
                if (temp->right == NULL) { break; }
                else { temp = temp->right; }
            }
        }

        return n1;
    }




    // prints the tree
    void printTree() {
        if (root == NULL)
            cout << "Tree is empty" << endl;
        else
            printHelper(root);

    }
};


int main(int argc, char **argv) {
    vector<VideoGames> games; //vector which keeps data
    RBTree tree;
    string line,name,publisher,platform,data;
    int year_of_release;
    int counter = 0,i=0;
    double NA_Sales,EU_Sales,Other_Sales;

    string filename = argv[1]; //filename as a argument
    // opening file
    fstream file;
    file.open(filename);
    while(!file.eof())
    {
        while (getline(file, line, '\n')) {
            i++;
            stringstream str(line);
            games.push_back(VideoGames());
            while (getline(str, data, ',')) {
                counter++;
                if (counter > 7) {

                    if (counter % 7 == 1) {
                        if (data != "Name") {
                            games[i - 2].name = data;
                        }
                    } else if (counter % 7 == 2) {
                        if (data != "Platform") {
                            games[i - 2].platform = data;
                        }
                    } else if (counter % 7 == 3) {
                        if (data != "Year_of_Release") {
                            year_of_release = stoi(data);
                            games[i - 2].releaseYear = year_of_release;
                        }
                    } else if (counter % 7 == 4) {
                        if (data != "Publisher") { games[i - 2].publisher = data; }
                    } else if (counter % 7 == 5) {
                        if (data != "NA_Sales") {
                            NA_Sales = stod(data);
                            games[i - 2].naSales = NA_Sales;
                        }
                    } else if (counter % 7 == 6) {
                        if (data != "EU_Sales") {
                            EU_Sales = stod(data);
                            games[i - 2].euSales = EU_Sales;
                        }
                    } else {
                        if (data != "Other_Sales") {
                            Other_Sales = stod(data);
                            games[i - 2].otherSales = Other_Sales;
                        }
                    }
                }
            }
        }
    }
    file.close();
    
    int j1 = 0;
    while(games[j1].releaseYear<=1990){
        tree.insert(games[j1]);
        j1++;

    }


    VideoGames maxNa1 = tree.findMaxNa(tree.getRoot());
    VideoGames maxEu1 = tree.findMaxEu(tree.getRoot());
    VideoGames maxOther1 = tree.findMaxOther(tree.getRoot());

    cout<<"1st decade - (1980 - end of 1990)"<<endl;
    cout<<"Best seller in North America: "<<maxNa1.publisher<<" - "<<maxNa1.naSales<<" million"<<endl;
    cout<<"Best seller in Europe: "<<maxEu1.publisher<<" - "<<maxEu1.euSales<<" million"<<endl;
    cout<<"Best seller rest of the World: "<<maxOther1.publisher<<" - "<<maxOther1.otherSales<<" million"<<endl;



    int j2 = 0;
    while(games[j2].releaseYear<=2000){
        tree.insert(games[j2]);
        j2++;

    }


    VideoGames maxNa2 = tree.findMaxNa(tree.getRoot());
    VideoGames maxEu2 = tree.findMaxEu(tree.getRoot());
    VideoGames maxOther2 = tree.findMaxOther(tree.getRoot());

    cout<<"2nd decade - (1990 - end of 2000)"<<endl;
    cout<<"Best seller in North America: "<<maxNa2.publisher<<" - "<<maxNa2.naSales<<" million"<<endl;
    cout<<"Best seller in Europe: "<<maxEu2.publisher<<" - "<<maxEu2.euSales<<" million"<<endl;
    cout<<"Best seller rest of the World: "<<maxOther2.publisher<<" - "<<maxOther2.otherSales<<" million"<<endl;



    int j3 = 0;
    while(games[j3].releaseYear<=2010){
        tree.insert(games[j3]);
        j3++;

    }


    VideoGames maxNa3 = tree.findMaxNa(tree.getRoot());
    VideoGames maxEu3 = tree.findMaxEu(tree.getRoot());
    VideoGames maxOther3 = tree.findMaxOther(tree.getRoot());

    cout<<"3rd decade - (2000 - end of 2010)"<<endl;
    cout<<"Best seller in North America: "<<maxNa3.publisher<<" - "<<maxNa3.naSales<<" million"<<endl;
    cout<<"Best seller in Europe: "<<maxEu3.publisher<<" - "<<maxEu3.euSales<<" million"<<endl;
    cout<<"Best seller rest of the World: "<<maxOther3.publisher<<" - "<<maxOther3.otherSales<<" million"<<endl;



    int j4 = 0;
    while(games[j4].releaseYear<=2020){
        tree.insert(games[j4]);
        j4++;

    }


    VideoGames maxNa4 = tree.findMaxNa(tree.getRoot());
    VideoGames maxEu4 = tree.findMaxEu(tree.getRoot());
    VideoGames maxOther4 = tree.findMaxOther(tree.getRoot());

    cout<<"4th decade - (2010 - end of 2020)"<<endl;
    cout<<"Best seller in North America: "<<maxNa4.publisher<<" - "<<maxNa4.naSales<<" million"<<endl;
    cout<<"Best seller in Europe: "<<maxEu4.publisher<<" - "<<maxEu4.euSales<<" million"<<endl;
    cout<<"Best seller rest of the World: "<<maxOther4.publisher<<" - "<<maxOther4.otherSales<<" million"<<endl;

    tree.printTree();


    return 0;
}
