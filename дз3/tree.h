#include <stdio.h>
#include <stdlib.h>

struct Tree_node{
    int value[5];
    struct Tree_node* left;
    struct Tree_node* right;
};

// struct intTree {
//     struct Tree_node* root;
// }

int search_node(struct Tree_node* root, int data){
    while (1){
        if(root == NULL){
            return 0;
        } else if(root->value == data){
            return 1;
        } else if(root->value < data){
            root = root->right;
        } else{
            root = root->left;
        }
    }
}

static struct Tree_node* create_node(int data){
    struct Tree_node* node = calloc(1, sizeof(struct Tree_node));
    if(!node){
        fprintf(stderr, "Create ERROR\n");
        return NULL;
    }
    node->value = data;
    node->left = node->right = NULL;
    return node;
}

struct Tree_node* insert_node(struct Tree_node* root, int data){
    if(root == NULL){
        root = create_node(data);
        return root;
    } else if(root->value < data){
        root->right = insert_node(root->right, data);
    } else{
        root->left = insert_node(root->left, data);
    }
    return root;
}

struct Tree_node* find_min(struct Tree_node* root){
    if(root == NULL){
        return root;
    }
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

struct Tree_node* delete_node(struct Tree_node* root, int data){
    if (root == NULL){
        return root;
    } else if(root->value > data){
        root->left = delete_node(root->left, data);
    } else if(root->value < data){
        root->right = delete_node(root->right, data);
    } else{ //Удаление
        if(root->left == NULL && root->right == NULL){
            free(root);
            root = NULL;
        } else if(root->left == NULL){
            struct Tree_node* buf = root;
            root = root->right;
            free(buf);
        } else if(root->right == NULL){
            struct Tree_node* buf = root;
            root = root->left;
            free(buf);
        } else{
            struct Tree_node* buf = find_min(root->right);
            root->value = buf->value;
            root->right = delete_node(root->right, buf->value);
        }
    }
return root;
}

void inorder(struct Tree_node* root) {
	if(root == NULL){
        return;
    }
	inorder(root->left);
	printf("%d ", root->value);
    free(root);
	inorder(root->right);
}

int convert(int* number, char str[]){
    str[0] = ' ';
    return (*number = atoi(str));
}
