#include<stdio.h>

void main() {
    // int a=2, b=3, c;

    // printf("\nEnter a and b: ");
    // scanf("%d %d", &a, &b);

    // printf("\n\nArithmetic Operators: ");
    // printf("\n%d + %d = %d", a, b, a+b);
    // printf("\n%d - %d = %d", a, b, a-b);
    // printf("\n%d * %d = %d", a, b, a*b);
    // printf("\n%d / %d = %d", a, b, a/b);    //quotient
    // printf("\n%d (mod) %d = %d", a, b, a%b);    //remainder

    // printf("\n\nAssignment Operators: ");   //a += b; <---> a = a+b
    // printf("\n%d + %d = %d", a, b, a += b);
    // printf("\n%d - %d = %d", a, b, a -= b);
    // printf("\n%d * %d = %d", a, b, a *= b);
    // printf("\n%d / %d = %d", a, b, a /= b);    //quotient
    // printf("\n%d (mod) %d = %d", a, b, a %= b);    //remainder

    // printf("\n\nRelational/Comparision Operators: ");   //return boolean values (true-1 -- false-0)
    // printf("\n%d < %d = %d", a, b, a < b);
    // printf("\n%d > %d = %d", a, b, a > b);
    // printf("\n%d <= %d = %d", a, b, a <= b);
    // printf("\n%d >= %d = %d", a, b, a >= b);
    // printf("\n%d == %d = %d", a, b, a == b);
    // printf("\n%d != %d = %d", a, b, a != b);


    // printf("\n\nLogical Operators: ");
    // printf("\nLogical AND: %d", ((a>b) && (a<=b)));
    // printf("\nMix: %d", (a>b) || (a<=b) && (a==b));
    // printf("\nLogical NOT: %d", !(a<b));

    // printf("\n\nTernary Operator: ");
    // c = (a>b)?a:b;
    // printf("\nMax: %d", c);
    // printf("\nMax: %d", (a>b)?a:b);

    //Increment/Decrement Operator:
    //pre - first inc/dec then assignment
    // printf("\na = %d\t\tb = %d", a, b);
    // printf("\n++a = %d\t++b = %d", ++a, ++b);
    // printf("\na = %d\t\tb = %d", a, b);
    // printf("\n--a = %d\t--b = %d", --a, --b);
    // printf("\na = %d\t\tb = %d", a, b);

    //post - first assignment then inc/dec
    // printf("\na = %d\t\tb = %d", a, b);
    // printf("\na++ = %d\tb++ = %d", a++, b++);
    // printf("\na = %d\t\tb = %d", a, b);
    // printf("\na-- = %d\tb-- = %d", a--, b--);
    // printf("\na = %d\t\tb = %d", a, b);

    int a = 37, b = 26, d = 0;
    printf("\na = %d\t\tb = %d", a, b);
    
    d = (++a + --b + --a - ++b - --a + b-- + a-- + --a - --b - a-- + b-- + --a + --b + --a + --b + ++a - ++b - b-- + a-- + --a + --b + a-- - b--);
    printf("d = %d", d);

    printf("\na = %d\t\tb = %d", a, b);
}

/*
Operators are used to perform certain operations.

There are 7 types of Operators:
1. Arithmetic Operators             - Binary    --  +, -, *, /, %
2. Assignment Operators             - Binary    --  =, +=, -=, *=, /=, %=
3. Relational Operators             - Binary    --  >, <, >=, <=, ==, !=
4. Logical Operators                - Binary    --  &&(AND), ||(OR), !(NOT) - Unary
5. Increment/Decrement Operators    - Unary     --  (post/pre)++, (post/pre)--
6. Bitwise Operators                - Binary    --  &(and), |(or), ^(xor), <<(left shift), >>(right shift)
7. Ternary Operators                - Ternary   --  ?: [(condition)?true:false]



divided in 3 categories:
1. Unary    - works using only one operand
2. Binary   - works using two operand
3. Ternary  - works using three operand

Logical Operators: &&, ||, !

Logical AND (&&):

cond1 cond2 answers
0       0       0
0       1       0
1       0       0
1       1       1

Logical OR (||):

cond1 cond2 answers
0       0       0
0       1       1
1       0       1
1       1       1


Logical NOT (!):

input   output
0       1
1       0

*/