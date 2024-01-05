#include<stdio.h>
#include<string.h>

void main() {
    // string way 1 - array of chars
    char str[] = {'R', 'a', 'm', 'a', 'n', '\0'};
    // string way 2 - using string literal
    char str1[] = "Raman using double quote";

    printf("\nstr = %s", str);
    printf("\tstr1 = %s", str1);

    //strlen - string length
    // printf("\nstrlen(%s) = %d", str, strlen(str));
    //strcpy() - string copy
    // strcpy(str, str1);
    // printf("\nstrcpy(dest, src) = %s", str);
    //strcat() - string concatenation
    // strcat(str, str1);
    // printf("\nstrcat(dest, src) = %s", str);
    //strcmp() - string compare
    /*strcmp(first string, second string)
    returns <0 if the first string is smaller than the second string
    returns =0 if the first string and the second string are same
    returns >0 if the first string is greater than the second string
    */
    // printf("\nstrcmp(%s, %s) = %d", str, str1, strcmp("aa", "aA"));
    //strrev() - string reverse
    // printf("\nstrrev(%s) = %s", str, strrev(str));
    //strlwr() - string lower
    printf("\nstrlwr(%s) = %s", str, strlwr(str));
    printf("\nstrupr(%s) = %s", str, strupr(str));
}