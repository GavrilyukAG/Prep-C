#include "tree.h"

int main(int argc, char* argv[]){

    if (argc-1 < 1) {
        printf("Not enough arguments\n");
        return -1;
    }

    FILE* f = fopen(argv[1], "r");
    if (!f) {
        printf("File is not found");
        return -1;
    }

    struct Tree_node* root = NULL;

    while(!feof(f)) { /*fscanf(f, "%s", str) != EOF*/
        int i = -1;
        char str[10] = "\0";
        unsigned int number = 0;
        do{
            if(i == sizeof(str)){
                break;
            }
            i++;
            str[i] = fgetc(f);
        }while(!isspace(str[i]));
        if((str[0] != '?' || str[0] != '+' || str[0] != '-') &&
        (str[1] < 48 || str[1] > 57)){
            printf("Wrong data format in file: %s\n", str);
            continue;
        }
        switch(str[0]) {
            case '+':
                convert(&number, str);
                if(!search_node(root, number)){
                    root = insert_node(root, number);
                }
                break;

            case '?':
                convert(&number, str);
                if(search_node(root, number)){
                    printf("%d-YES\n", number);
                } else {
                    printf("%d-NO\n", number);
                }
                break;

            case '-':
                convert(&number, str);
                if(search_node(root, number)){
                    root = delete_node(root, number);
                } else{
                    printf("%d-is not a node of the tree\n", number);
                }
                break;

            default:
                break;
        }
    }
    fclose(f);
    inorder(root);

    return 0;
}
