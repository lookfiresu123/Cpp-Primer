/**
 * 创建并利用dot和graphviz打印二叉查找树
 */

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>

/**
 * 结点类
 */
struct node
{
  int key_value;
  std::string name;
  node *left;
  node *right;
};

/**
 * 树类
 */
class btree
{
    public:
        btree();
        ~btree();

        void insert(int index, int key);
        node *search(int key);
        void destroy_tree();
        node *ret_root() {
            return root;
        }

    private:
        void destroy_tree(node *leaf);
        void insert(int index, int key, node *leaf);
        // node *search(int key, node *leaf);

        node *root;
};

/**
 * 树类的构造函数，初识时根结点为NULL
 */
btree::btree()
{
    root=NULL;
}

/**
 * 插入结点（不为根节点时）
 * @index：结点的索引
 * @key：结点中保存的值
 */
void btree::insert(int index, int key, node *leaf)
{
    if(key< leaf->key_value)
    {
        if(leaf->left!=NULL)
        insert(index, key, leaf->left);
        else
        {
            leaf->left=new node;
            leaf->left->key_value=key;
            leaf->left->name = "node" + std::to_string(index);
            leaf->left->left=NULL;    //Sets the left child of the child node to null
            leaf->left->right=NULL;   //Sets the right child of the child node to null
        }
    }
    else if(key>=leaf->key_value)
    {
        if(leaf->right!=NULL)
        insert(index, key, leaf->right);
        else
        {
            leaf->right=new node;
            leaf->right->key_value=key;
            leaf->right->name = "node" + std::to_string(index);
            leaf->right->left=NULL;  //Sets the left child of the child node to null
            leaf->right->right=NULL; //Sets the right child of the child node to null
        }
    }
}

/**
 * 销毁树对象（private）
 * @leaf：指向结点的指针
 */
void btree::destroy_tree(node *leaf)
{
    if(leaf!=NULL)
    {
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        delete leaf;
    }
}

/**
 * 插入结点
 * @index：结点的索引
 * @key：结点中保存的值
 */
void btree::insert(int index, int key)
{
    if(root!=NULL)
        insert(index, key, root);
    else
    {
        root=new node;
        root->key_value=key;
        root->name = "node" + std::to_string(index);            root->left=NULL;
        root->right=NULL;
    }
}

/**
 * 销毁树对象（public）
 */
void btree::destroy_tree()
{
    destroy_tree(root);
}

/**
 * 析构函数
 */
btree::~btree()
{
    destroy_tree();
}

/**
 * 打印结点
 * @current：当前结点
 */
void print_node(node *current) {
    std::ofstream output;
    output.open("test.dot", std::ofstream::app);
    if (current) {
        output << current->name << " " << "[label = \"<f0> |<f1> " << current->key_value << "|<f2> \"];" << std::endl;
        print_node(current->left);
        print_node(current->right);
    }
    output.close();
}

/**
 * 打印结点直接的链接边
 * @current：当前结点（边的起点）
 */
void print_link(node *current) {
    std::ofstream output;
    output.open("test.dot", std::ofstream::app);
    if (current) {
        if (current->left)
            output << "\"" << current->name << "\":f0 -> \"" << current->left->name << "\"" << ":f1;" << std::endl;
        if (current->right)
            output << "\"" << current->name << "\":f2 -> \"" << current->right->name << "\"" << ":f1;" << std::endl;
        print_link(current->left);
        print_link(current->right);
    }
    output.close();
}

/**
 * 打印该二叉查找树
 * @root：需要打印的树类对象
 */
void graphviz_tree(btree root) {
    std::ofstream output;
    output.open("test.dot", std::ofstream::app);
    output << "digraph g {" << std::endl;
    output << "node [shape = record,height=.1];" << std::endl;
    // 遍历整棵树
    print_node(root.ret_root());
    print_link(root.ret_root());
    output << "}" << std::endl;
    output.close();
}

int main (void) {
    btree root;
    std::srand(time(NULL));
    for (int i = 0 ; i < 10 ; ++i) {
        root.insert(i, std::rand() % 100);
    }
    graphviz_tree(root);
	return 0;
}
