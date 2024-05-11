#include <stdlib.h>

enum HuffNodeType {
    LEAF_NODE,
    INTERNAL_NODE
};

struct HuffNode {
    char element;
    int weight;
    enum HuffNodeType type;
    struct HuffNode * left;
    struct HuffNode * right;
};

struct HuffNode * new_leaf_node(char el, int wt) {
    struct HuffNode * node = (struct HuffNode *) malloc(sizeof(struct HuffNode));

    node->element = el;
    node->weight = wt;
    node->left = NULL;
    node->right = NULL;
    node->type = LEAF_NODE;

    return node;
}

struct HuffNode * new_internal_node(struct HuffNode * left, struct HuffNode * right, int wt) {
    struct HuffNode * node = (struct HuffNode *) malloc(sizeof(struct HuffNode));

    // node->element = el;
    node->weight = wt;
    node->left = left;
    node->right = right;
    node->type = INTERNAL_NODE;

    return node;
}


struct HuffTree {
    struct HuffNode * root;
};

struct HuffTree * new_leaf_tree(char el, int wt) {
    struct HuffTree * tree = (struct HuffTree *) malloc(sizeof(struct HuffTree));

    tree->root = new_leaf_node(el, wt);

    return tree;
}

struct HuffTree * new_internal_tree(struct HuffNode * left, struct HuffNode * right, int wt) {
    struct HuffTree * tree = (struct HuffTree *) malloc(sizeof(struct HuffTree));

    tree->root = new_internal_node(left, right, wt);

    return tree;
}
