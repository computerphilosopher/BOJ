#include <iostream>
#include <algorithm>
#include <cstddef>

using namespace std;

template <typename T> 
class Node{
    private:
        T data;
        Node *left;
        Node *right;
    public:

        Node(){}

        Node(T data){
            this->data = data;
        }

        T get_data(){
            return data;
        }

        void lset(Node* left){
            this -> left = left;
        }
        void rset(Node* right){
            this -> right = right;
        }

        Node* get_left(){
            return left;
        }

        Node* get_right(){
            return right;
        }
};


template <typename T> 
class Tree{
    private:
        Node <T> root;

        void pre_order(Node<T>* root){

            if(root == nullptr){
                return;
            }

            cout << root->get_data();

            pre_order(root->get_left());
            pre_order(root->get_right());
        }

        void in_order(Node<T>* root){

            if(root == nullptr){
                return;
            }

            in_order(root->get_left());
            cout << root->get_data();
            in_order(root->get_right());
        }

        void post_order(Node<T>* root){

            if(root == nullptr){
                return;
            }

            post_order(root->get_left());
            post_order(root->get_right());
            cout << root->get_data();
        }

        Node<T>* search(Node<T> *root, T data){
            if(root == nullptr){
                return nullptr;
            }

            if(data == root->get_data()){
                return root;
            }

            Node<T>* left = search(root->get_left(), data);
            Node<T>* right = search(root->get_right(), data);

            return left ? left : right;
        }


    public:
        Tree(){}

        Tree(const T data){
            root = Node <T> (data);
        }

        void add_level(const T r, const T lc, const T rc){

            Node<T>* left = nullptr; 
            Node<T>* right = nullptr;

            Node<T>& node = root;

            if(lc != '.'){
                left = new Node<T> (lc);
            }

            if(rc != '.'){
                right= new Node<T> (rc);
            }

            if(node.get_data() == r){
                node.lset(left);
                node.rset(right);
            }

            else{
                Node <T>* temp = search(r);

                if(temp){
                    temp->lset(left);
                    temp->rset(right);
                }
            }
        }

        Node<T>* search(T data){
            return search(&root, data);
        }


        Node<T>* get_root(){
            return &root;
        }

        void pre_order(){
            pre_order(&root);
        }

        void in_order(){
            in_order(&root);
        }

        void post_order(){
            post_order(&root);
        }

};

int main(){

    Tree<char> tree('A');
    int n = 0;

    cin.sync_with_stdio(false);
    cin >> n;
     
    for(int i=0; i<n; i++){
        char r, lc, rc;
        cin >> r >> lc >> rc;

        tree.add_level(r, lc, rc);
    }

    tree.pre_order();
    cout<<endl;

    tree.in_order();
    cout<<endl;

    tree.post_order();
    cout<<endl;

    return 0;
}
