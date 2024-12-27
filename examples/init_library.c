/* How to initialize the c-ares library.
 *
 * Every program that uses c-ares should initialize the library prior
 * to using it. See the documentation of ares_library_init(3) for
 * restrictions on Windows.
 */
#include <ares.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int ret;
  printf("Initializing the c-ares library...\n");
  if ((ret = ares_library_init(ARES_LIB_INIT_ALL)) != ARES_SUCCESS) {
    fprintf(stderr, "ares_library_init(): %s\n", ares_strerror(ret));
    return EXIT_FAILURE;
  }
  printf("ares_initialized() = %s.\n",
         ares_library_initialized() == ARES_SUCCESS ? "ARES_SUCCESS"
                                                    : "ARES_ENOTINITIALIZED");
  printf("Cleaning up the c-ares library...\n");
  ares_library_cleanup();
  return 0;
}
