#include "error.h"

#include <stdio.h>
#include <stdlib.h>

void
no_memory_error()
{
  printf("ERROR: No memory available");
  exit(1);
}
