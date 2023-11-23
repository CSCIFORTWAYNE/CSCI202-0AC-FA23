#ifndef BINARY_H
#define BINARY_H
#include <string>
#include <sstream>

template <class T>
struct binaryNode
{
    T *data;
    int height;
    int bfactor;
    binaryNode<T> *lTree;
    binaryNode<T> *rTree;
    ~binaryNode() { delete data; };
};

template <class T>
class binaryTree
{
public:
    const binaryTree<T> &operator=(const binaryTree<T> &otherTree);
    binaryTree(const binaryTree<T> &otherTree);
    binaryTree();
    void destroyTree();
    std::string inorderTraversal() const;
    std::string preorderTraversal() const;
    std::string postorderTraversal() const;
    bool isEmpty() const;
    int treeheight() const;
    int treeNodeCount() const;
    int treeLeavesCount() const;
    ~binaryTree();
    virtual bool search(const T &searchItem) const = 0;
    virtual void insert(const T &insertItem) = 0;
    virtual void deleteNode(const T &deleteItem) = 0;

protected:
    binaryNode<T> *root;
    int max(int x, int y) const;
    int height(binaryNode<T> *p) const;

private:
    void copyTree(binaryNode<T> *&copiedTreeRoot, binaryNode<T> *otherTreeRoot);
    void destroy(binaryNode<T> *&p);
    void inorder(binaryNode<T> *p, std::ostringstream &out) const;
    void preorder(binaryNode<T> *p, std::ostringstream &out) const;
    void postorder(binaryNode<T> *p, std::ostringstream &out) const;

    int nodeCount(binaryNode<T> *p, int count = 0) const;   // implemented as lecture activity
    int leavesCount(binaryNode<T> *p, int count = 0) const; // implemented as lecture activity
};

template <class T>
const binaryTree<T> &binaryTree<T>::operator=(const binaryTree<T> &otherTree)
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

template <class T>
binaryTree<T>::binaryTree(const binaryTree<T> &otherTree)
{
    if (otherTree.root == nullptr)
        root = nullptr;
    else
        copyTree(root, otherTree.root);
}

template <class T>
binaryTree<T>::binaryTree()
{
    root = nullptr;
}

template <class T>
void binaryTree<T>::destroyTree()
{
    destroy(root);
}

template <class T>
std::string binaryTree<T>::inorderTraversal() const
{
    std::ostringstream out;
    inorder(root, out);
    return out.str();
}
template <class T>
std::string binaryTree<T>::preorderTraversal() const
{
    std::ostringstream out;
    preorder(root, out);
    return out.str();
}
template <class T>
std::string binaryTree<T>::postorderTraversal() const
{
    std::ostringstream out;
    postorder(root, out);
    return out.str();
}

template <class T>
inline bool binaryTree<T>::isEmpty() const
{
    return root == nullptr;
}

template <class T>
inline int binaryTree<T>::treeheight() const
{
    return height(root);
}

template <class T>
inline int binaryTree<T>::treeNodeCount() const
{
    return nodeCount(root);
}

template <class T>
inline int binaryTree<T>::treeLeavesCount() const
{
    return leavesCount(root);
}

template <class T>
inline binaryTree<T>::~binaryTree()
{
    destroy(root);
}

template <class T>
void binaryTree<T>::copyTree(binaryNode<T> *&copiedTreeRoot, binaryNode<T> *otherTreeRoot)
{
    if (otherTreeRoot == nullptr)
        copiedTreeRoot = nullptr;
    else
    {
        copiedTreeRoot = new binaryNode<T>;
        copiedTreeRoot->data = new T(otherTreeRoot->data);
        copyTree(copiedTreeRoot->lTree, otherTreeRoot->lTree);
        copyTree(copiedTreeRoot->rTree, otherTreeRoot->rTree);
    }
}
template <class T>
void binaryTree<T>::destroy(binaryNode<T> *&p)
{
    if (p != nullptr)
    {
        destroy(p->lTree);
        destroy(p->rTree);
        delete p;
        p = nullptr;
    }
}
template <class T>
void binaryTree<T>::inorder(binaryNode<T> *p, std::ostringstream &out) const
{
    if (p != nullptr)
    {
        inorder(p->lTree, out);
        out << *(p->data) << "\n\n";
        inorder(p->rTree, out);
    }
}
template <class T>
void binaryTree<T>::preorder(binaryNode<T> *p, std::ostringstream &out) const
{
    if (p != nullptr)
    {
        out << *(p->data) << "\n\n";
        preorder(p->lTree, out);
        preorder(p->rTree, out);
    }
}
template <class T>
void binaryTree<T>::postorder(binaryNode<T> *p, std::ostringstream &out) const
{
    if (p != nullptr)
    {
        postorder(p->lTree, out);
        postorder(p->rTree, out);
        out << *(p->data) << "\n\n";
    }
}
template <class T>
inline int binaryTree<T>::nodeCount(binaryNode<T> *p, int count) const
{
    if (p == nullptr)
        return 0;
    else
        return 1 + nodeCount(p->lTree) + nodeCount(p->rTree);
}
template <class T>
inline int binaryTree<T>::leavesCount(binaryNode<T> *p, int count) const
{
    if (p->lTree == nullptr && p->rTree == nullptr)
    {
        return 1;
    }
    else if (p->lTree == nullptr)
    {
        return leavesCount(p->rTree);
    }
    else if (p->rTree == nullptr)
    {
        return leavesCount(p->lTree);
    }
    else
        return leavesCount(p->lTree) + leavesCount(p->rTree);
}
template <class T>
int binaryTree<T>::height(binaryNode<T> *p) const
{
    if (p == nullptr)
        return 0;
    else
        return 1 + max(height(p->lTree), height(p->rTree));
}
template <class T>
inline int binaryTree<T>::max(int x, int y) const
{
    if (x >= y)
        return x;
    else
        return y;
}
#endif