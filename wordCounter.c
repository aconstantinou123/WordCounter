#include <stdio.h>
#include <stdbool.h>

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

int main()
{
    int c, nl, nw, nc, state;
    bool writeNewLine;
    state = OUT;
    nl = nw = nc = 0;
    writeNewLine = true;
    while((c = getchar()) != EOF) {
        ++nc;
        if(writeNewLine == true){
            printf("\n");
            writeNewLine = false;
        }
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t') {
            printf("\n");
            state = OUT;
        }
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
        if (c != ' ' && c != '\n' && c != '\t') {
            putchar(c);
        }
    }
    printf("\nl %d w %d c %d\n", nl, nw, nc);
    return 0;
}