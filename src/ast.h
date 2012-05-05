//==============================================================================
//
// Definitions
//
//==============================================================================

// Defines the types of expressions available.
typedef enum kal_ast_node_type_e {
    KAL_AST_TYPE_NUMBER,
    KAL_AST_TYPE_VARIABLE,
    KAL_AST_TYPE_BINARY_EXPR,
    KAL_AST_TYPE_CALL,
    KAL_AST_TYPE_PROTOTYPE,
    KAL_AST_TYPE_FUNCTION,
} kal_ast_node_type_e;

struct kal_ast_node;

// Represents a number in the AST.
typedef struct kal_ast_number {
    double value;
} kal_ast_number;

// Represents a variable in the AST.
typedef struct kal_ast_variable {
    char *name;
} kal_ast_variable;

// Represents a binary expression in the AST.
typedef struct kal_ast_binary_expr {
    char op;
    struct kal_ast_node *lhs;
    struct kal_ast_node *rhs;
} kal_ast_binary_expr;

// Represents a function call in the AST.
typedef struct kal_ast_call {
    char *callee;
    struct kal_ast_node **args;
    int arg_count;
} kal_ast_call;

// Represents a function prototype in the AST.
typedef struct kal_ast_prototype {
    char *name;
    char **args;
    int arg_count;
} kal_ast_prototype;

// Represents a function in the AST.
typedef struct kal_ast_function {
    struct kal_ast_node *prototype;
    struct kal_ast_node *body;
} kal_ast_function;

// Represents an expression in the AST.
typedef struct kal_ast_node {
    kal_ast_node_type_e type;
    union {
        kal_ast_number number;
        kal_ast_variable variable;
        kal_ast_binary_expr binary_expr;
        kal_ast_call call;
        kal_ast_prototype prototype;
        kal_ast_function function;
    };
} kal_ast_node;



//==============================================================================
//
// Functions
//
//==============================================================================

kal_ast_node *kal_ast_number_create(double value);

kal_ast_node *kal_ast_variable_create(char *name);

kal_ast_node *kal_ast_binary_expr_create(char op, kal_ast_node *lhs,
    kal_ast_node *rhs);

kal_ast_node *kal_ast_call_create(char *callee, kal_ast_node **args,
    int arg_count);

kal_ast_node *kal_ast_prototype_create(char *name, char **args,
    int arg_count);

kal_ast_node *kal_ast_function_create(kal_ast_node *prototype,
    kal_ast_node *body);

void kal_ast_node_free(kal_ast_node *node);