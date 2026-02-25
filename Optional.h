#ifndef Optional_H
#define Optional_H

#include "ErrorCode.h"

typedef struct Optional
{
    int data; 
    ErrorCode errorCode;
} Optional;

static inline Optional new_optional(int value, ErrorCode ErrorCode)
{
    Optional returnOptional = {.data = value, .errorCode = ErrorCode};
    return returnOptional;
}

#endif