#include <iostream>
#include "cstring.h"

using namespace mystring;

// string copy
char *mystring::strcpy(char *dest, const char *src) {
    char *ogDest = dest;

    while(*src != '\0') {
        *dest = *src;
        *dest++;
        src++;
    }

    *dest = '\0';

    return ogDest;
}

// string concatenation
char *mystring::strcat(char *dest, const char *src) {
    char *temp = dest;

    int destLen = strlen(dest);
    dest = dest + destLen;

    strcpy(dest, src);

    return temp;
}

// string comparison
int mystring::strcmp(const char *str1, const char *str2) {
    int i = 0, len = 0;

    while(len == 0) {
        if(str1[i] > str2[i]) len = 1;
        else if (str1[i] < str2[i]) len = -1;

        if(str1[i] == '\0') break;

        i++;
    }

    return len;
}

// character finder
char *mystring::strchr(char *str, int c) {
    while(*str != '\0') {
        if(*str == c) return str;
        str++;
    }

    return NULL;
}

// last location of character finder
char *mystring::strrchr(char *str, int c) {
    char *ogStr = NULL;

    if(*str == '\0') return NULL;

    while(*str != '\0') {
        if(*str == c) ogStr = str;
        str++;
    }

    return ogStr;
}

// string length
int mystring::strlen(char const *str) {
    int count = 0;

    while(*str != '\0') {
        count++;
        str++;
    }

    return count;
}