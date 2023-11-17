#ifndef BINARY_H
#define BINARY_H
#include <string>
#include <sstream>

template <class t>
struct binaryNode
{
    t *data;
    binaryNode<t> *left;
    binaryNode<t> *right;
    ~binaryNode() { delete data; };
};

template <class t>
class binaryTree
{
public:
    const binaryTree<t> &operator=(const binaryTree<t> &otherTree);
    binaryTree(const binaryTree<t> &otherTree);
    binaryTree();
    std::string inorderTraversal() const;
    std::string preorderTraversal() const;
    std::string postOrderTraversal() const;
    bool isEmpty() const;
    int treeheight() const;
    int treeNodeCount(const t &searchItem) const;
    int treeLeavesCount(const t &searchItem) const;
    ~binaryTree();
    virtual void insert(const t &insertItem) = 0;
    virtual bool search(const t &searchItem) const = 0;
    virtual void deleteNode(const t &deleteItem) = 0;

protected:
    binaryNode<t> *&getRoot();

private:
    binaryNode<t> *root;
    void copyTree(binaryNode<t> *&copiedTreeRoot, binaryNode<t> *otherTreeRoot);
    void destroy(binaryNode<t> *&p);
    void inorder(binaryNode<t> *p, std::ostringstream &out) const;
    void preorder(binaryNode<t> *p, std::ostringstream &out) const;
    void postorder(binaryNode<t> *p, std::ostringstream &out) const;
    int height(binaryNode<t> *p) const;
    int nodeCount(const t &searchItem, binaryNode<t> *p, int count = 0) const;   // implemented as lecture activity
    int leavesCount(const t &searchItem, binaryNode<t> *p, int count = 0) const; // implemented as lecture activity
    int max(int x, int y) const;
};

template <class t>
const binaryTree<t> &binaryTree<t>::operator=(const binaryTree<t> &otherTree)
{
    if (this != &otherTree)
    {
        if (root != nullptr)
            destroy(root);
        if (otherTree.root == nullptr)
            root = nullptr;
        else
            copyTree(root, otherTree.root);
    }
    return *this;
}

template <class t>
binaryTree<t>::binaryTree(const binaryTree<t> &otherTree)
{
    this->root = nullptr;
    copyTree(this->root, otherTree.root);
}

template <class t>
binaryTree<t>::binaryTree()
{
    root = nullptr;
}

template <class t>
std::string binaryTree<t>::inorderTraversal() const
{
    std::ostringstream out;
    inorder(root, out);
    return out.str();
}

template <class t>
std::string binaryTree<t>::preorderTraversal() const
{
    std::ostringstream out;
    preorder(root, out);
    return out.str();
}

template <class t>
std::string binaryTree<t>::postOrderTraversal() const
{
    std::ostringstream out;
    postorder(root, out);
    return out.str();
}

template <class t>
bool binaryTree<t>::isEmpty() const
{
    return root == nullptr;
}

template <class t>
int binaryTree<t>::treeheight() const
{
    return height(root);
}

template <class t>
int binaryTree<t>::treeNodeCount(const t &searchItem) const
{
    return nodeCount(searchItem, root);
}

template <class t>
int binaryTree<t>::treeLeavesCount(const t &searchItem) const
{
    return leavesCount(searchItem, root);
}

template <class t>
binaryTree<t>::~binaryTree()
{
    destroy(root);
}

template <class t>
binaryNode<t> *&binaryTree<t>::getRoot()
{
    return root;
}

template <class t>
void binaryTree<t>::copyTree(binaryNode<t> *&copiedTreeRoot, binaryNode<t> *otherTreeRoot)
{
    if (otherTreeRoot == nullptr)
        copiedTreeRoot = nullptr;
    else
    {
        copiedTreeRoot = new binaryNode<t>;
        copiedTreeRoot->data = new t(otherTreeRoot->data);
        copyTree(copiedTreeRoot->left, otherTreeRoot->left);
        copyTree(copiedTreeRoot->right, otherTreeRoot->right);
    }
}

template <class t>
void binaryTree<t>::destroy(binaryNode<t> *&p)
{
    if (p != nullptr)
    {
        destroy(p->left);
        destroy(p->right);
        delete p;
        p = nullptr;
    }
}

template <class t>
void binaryTree<t>::inorder(binaryNode<t> *p, std::ostringstream &out) const
{
    if (p != nullptr)
    {
        inorder(p->left, out);
        out << *(p->data) << "\n\n";
        inorder(p->right, out);
    }
}

template <class t>
void binaryTree<t>::preorder(binaryNode<t> *p, std::ostringstream &out) const
{
    if (p != nullptr)
    {
        out << *(p->data) << "\n\n";
        preorder(p->left, out);
        preorder(p->right, out);
    }
}

template <class t>
void binaryTree<t>::postorder(binaryNode<t> *p, std::ostringstream &out) const
{
    if (p != nullptr)
    {
        postorder(p->left, out);
        postorder(p->right, out);
        out << *(p->data) << "\n\n";
    }
}

template <class t>
int binaryTree<t>::height(binaryNode<t> *p) const
{
    if (p != nullptr)
        return max(height(p->left), height(p->right)) + 1;
    return 0;
}

template <class t>
int binaryTree<t>::nodeCount(const t &searchItem, binaryNode<t> *p, int count) const
{
    return 0;
}

template <class t>
int binaryTree<t>::leavesCount(const t &searchItem, binaryNode<t> *p, int count) const
{
    return 0;
}

template <class t>
int binaryTree<t>::max(int x, int y) const
{
    if (x >= y)
        return x;
    return y;
}

#endif