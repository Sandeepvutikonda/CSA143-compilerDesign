 #include <stdio.h>

typedef enum {
    ADD,
    SUB,
    MUL,
    DIV,
    LOAD,
    STORE,
    HALT
} OpCode;

typedef struct {
    OpCode opCode;
    int operand1;
    int operand2;
    int result;
} Instruction;

void generateCode(Instruction* instructions, int count) {
    printf("Generated Code:\n");

    for (int i = 0; i < count; i++) {
        switch (instructions[i].opCode) {
            case ADD:
                printf("ADD R%d, R%d, R%d\n", instructions[i].result, instructions[i].operand1, instructions[i].operand2);
                break;
            case SUB:
                printf("SUB R%d, R%d, R%d\n", instructions[i].result, instructions[i].operand1, instructions[i].operand2);
                break;
            case MUL:
                printf("MUL R%d, R%d, R%d\n", instructions[i].result, instructions[i].operand1, instructions[i].operand2);
                break;
            case DIV:
                printf("DIV R%d, R%d, R%d\n", instructions[i].result, instructions[i].operand1, instructions[i].operand2);
                break;
            case LOAD:
                printf("LOAD R%d, %d\n", instructions[i].result, instructions[i].operand1);
                break;
            case STORE:
                printf("STORE R%d, %d\n", instructions[i].operand1, instructions[i].result);
                break;
            case HALT:
                printf("HALT\n");
                break;
            default:
                printf("Unknown OpCode\n");
                break;
        }
    }
}

int main() {
    Instruction instructions[] = {
        {LOAD, 1, 0, 1},
        {LOAD, 2, 0, 2},
        {ADD, 1, 2, 3},
        {STORE, 3, 0, 0},
        {HALT, 0, 0, 0}
    };

    int instructionCount = sizeof(instructions) / sizeof(Instruction);

    generateCode(instructions, instructionCount);

    return 0;
}
