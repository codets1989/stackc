#include "util.h"

boolean is_open(char c) {
    if ((c == '(') || (c == '{') || (c == '['))
        return TRUE;
    else
        return FALSE;
}

boolean is_close(char c) {
    return ((c == ')') || (c == '}') || (c == ']'));
}

boolean is_brother(char o, char c) {
    return ((o == '(' && c == ')') || (o == '{' && c == '}') || (o == '[' && c == ']'));
}
