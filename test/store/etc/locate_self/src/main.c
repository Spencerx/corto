/* This is a managed file. Do not delete this comment. */

#include <locate_self/locate_self.h>

/* Enter code outside of main here. */

int cortomain(int argc, char *argv[]) {

    const char *str = corto_locate("locate_self", NULL, CORTO_LOCATE_LIB);
    if (!str) {
        goto error;
    }

    return 0;
error:
    return -1;
}
