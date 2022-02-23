#include <iostream>

using namespace std;

class node{
    public:
        int data;
        node *left;
        node *right;

       node(int d){
              data = d;
              left = NULL;
              right = NULL;

       }

};
  class BST{
   public :
        node* s;
        int c = 0;
        int f = 0;
        node* temp;
    node *insert(node *tree , int i){
        if(tree == NULL){
            s = new node(i);
            tree =s;
        }

        else if(i< tree->data){
            tree->left = insert(tree->left,i);
        }
        else
            tree->right = insert(tree->right,i);

        return tree;

     }


     void inorder(node *root){
            if(root!=NULL){
                inorder(root->left);
                cout<<root->data<<"  ";
                inorder(root->right);
            }
     }

      void postorder(node *root){
            if(root!=NULL){
                inorder(root->left);
                inorder(root->right);
                cout<<root->data<<"  ";

            }
     }

     void preorder(node *root){
            if(root!=NULL){
                cout<<root->data<<"  ";
                inorder(root->left);
                inorder(root->right);
            }
     }


     node *Delete(node *root , int data){


          if(root==NULL)
                return root;
          else if(data < root->data)
             root->left = Delete(root->left,data);
          else if(data > root->data)
             root->right = Delete(root->right,data);
          else{
             if(root->left==NULL && root->right==NULL){
                temp = root;
                delete temp;
                root = NULL;
                return root;
             }
             else if(root->left == NULL){
                temp = root;
                root = root->right;
                delete temp;
                return root;
             }
              else if(root->right == NULL){
                temp = root;
                root = root->left;
                delete temp;
                return root;
             }

             else{
                temp = findMin(root->right);
                root->data = temp->data;
                root->right = Delete(root->right,temp->data);
                return root;
             }
          }

           return root;
     }
      node *findMin(node* root){
            if(root->left==NULL)
                return root;
            return findMin(root->left);

     }


     node *deleteLeaf(node *L, node *P){
          if(L!=NULL){
                if(L->left==NULL && L->right==NULL)
                    Delete(P,L->data);


                deleteLeaf(L->left,P);
                deleteLeaf(L->right,P);
            }
          return L;
     }


     node *search(node *root , int s){

           if(root!=NULL){
                if(s==root->data)
                      return root;
                if(s>root->data)
                      return search(root->right,s);
                if(s<root->data)
                      return search(root->left,s);

             }
     }

  };

   int main(){
         node *t = NULL;
         node *r = NULL;
         node *P = NULL;
         BST *b = new BST();

         r = b->insert(r,15);
        r =  b->insert(r,10);
         r = b->insert(r,20);
         r =  b->insert(r,8);
         r =  b->insert(r,17);
          r=  b->insert(r,30);
         r =  b->insert(r,33);

         b->inorder(r);

          b->Delete(r,1);
          b->inorder(r);


          b->deleteLeaf(r,r);
          b->inorder(r);

     }



