#include <stdio.h>
#include <stdlib.h>

typedef enum {
    ADD,
    SUB,
    MUL,
    DIV,
    ASSIGN,
    PRINT,
} Opcode;

typedef struct ASTNode {
    Opcode opcode;
    int value; 
    char* identifier; 
    struct ASTNode* left;
    struct ASTNode* right;
} ASTNode;

void generate_code(ASTNode* node) {
    if (node == NULL) {
        return;
    }

    switch (node->opcode) {
        case ADD:
            printf("ADD\n");
            break;
        case SUB:
            printf("SUB\n");
            break;
        case MUL:
            printf("MUL\n");
            break;
        case DIV:
            printf("DIV\n");
            break;
        case ASSIGN:
            printf("ASSIGN %s\n", node->identifier);
            break;
        case PRINT:
            printf("PRINT\n");
            break;
        default:
            fprintf(stderr, "Invalid opcode\n");
            exit(EXIT_FAILURE);
    }

    generate_code(node->left);
    generate_code(node->right);
}

int main() {
    ASTNode* ast = (ASTNode*)malloc(sizeof(ASTNode));
    ast->opcode = ADD;
    ast->left = (ASTNode*)malloc(sizeof(ASTNode));
    ast->left->opcode = ASSIGN;
    ast->left->identifier = "x";
    ast->left->left = NULL;
    ast->left->right = NULL;
    ast->right = (ASTNode*)malloc(sizeof(ASTNode));
    ast->right->opcode = PRINT;
    ast->right->left = NULL;
    ast->right->right = NULL;

    generate_code(ast);

    free(ast->left);
    free(ast->right);
    free(ast);

    return 0;
}
