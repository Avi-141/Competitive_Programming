#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct stack {
    char c;
    struct stack *next;
} stack;

void push(stack **top, char c) {
    stack *ele = NULL;

    ele = (stack*)malloc(sizeof(stack));
    ele->c = c;
    ele->next = *top;
    *top = ele;
}

char pop(stack **top) {
    stack *ret = NULL;
    char res = 0;

    ret = *top;
    res = ret->c;
    *top = ret->next;
    free(ret);

    return res;
}

int emptyStack(stack *s) {
    if (s == NULL) {
        return 1;
    }
    return 0;
}

int checkMatch(char m, char n) {
    if ((m == '{' && n == '}') ||
        (m == '[' && n == ']') ||
        (m == '(' && n == ')')) {
        return 1;
    }
    return 0;
}

int main() {
    int n = 0;
    char str[1000] = {0};
    size_t j = 0;
    stack *s = NULL;
    int flag = 0;
    size_t i = 0;

    //scanf("%d", &n);

   // for (i=0; i<n; i++) {
        s = NULL;
        memset(str, 0, 1000);
        printf("Enter the bracket expr");

        scanf("%s", str);
        flag = 0;
        j = 0;
        while(str[j] != '\0') {
            if (str[j] == '{' ||
                str[j] == '[' ||
                str[j] == '(') {
                push(&s, str[j]);
            } else {
                if (str[j] == '}' ||
                    str[j] == ']' ||
                    str[j] == ')') {
                        if (emptyStack(s)) {
                            printf("NO\n");
                            flag = 1;
                            break;
                        } else {
                            if (!checkMatch(pop(&s), str[j])) {
                                printf("NO\n");
                                flag = 1;
                                break;
                            }
                        }
                }
            }
            j++;
        } //end while
        if (!flag) {
            if (!emptyStack(s)) {
                printf("NO\n");
            } else {
                printf("YES\n");
            }
        }
     //end for
    return 0;
}
