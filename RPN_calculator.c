#include <stdio.h>
#include <stdlib.h>

//RPN CALCULATOR USING STACKS   

double rpn(char *postfix){
    float pilha[50];
    int topo = -1;
    int i;
    for (i=0; i<strlen(postfix); i++){
        if (postfix[i]>='0' && postfix[i]<='9'){
            pilha[++topo]= postfix[i]-'0';
        }else{
            double B = pilha[topo--];
            double A = pilha[topo--];

            if (postfix[i]=='+')
                pilha[++topo] = A+B;
            if (postfix[i]=='-')
                pilha[++topo] = A-B;
            if (postfix[i]=='*')
                pilha[++topo] = A*B;
            if (postfix[i]=='/')
                pilha[++topo] = A/B;
        }
    }
    return pilha[topo];
}
int main()
{
    char postfix[50];
    scanf("%s", &postfix);
    printf("Operacoes: %lf\n", rpn(postfix));
    return 0;
}
