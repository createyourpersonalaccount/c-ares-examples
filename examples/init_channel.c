/* How to initialize a channel.
 *
 * Nothing special here, initialize the library and then initialize a
 * channel with default options.
 */
#include <ares.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int ret = 0;
  ares_channel_t *channel;
  printf("Initializing the c-ares library...\n");
  if ((ret = ares_library_init(ARES_LIB_INIT_ALL)) != ARES_SUCCESS) {
    fprintf(stderr, "ares_library_init(): %s\n", ares_strerror(ret));
    return EXIT_FAILURE;
  }
  printf("Initializing a channel with default options...\n");
  if ((ret = ares_init_options(&channel, NULL, 0)) != ARES_SUCCESS) {
    fprintf(stderr, "ares_init_options(): %s\n", ares_strerror(ret));
    ret = EXIT_FAILURE;
    goto library_cleanup;
  }
  printf("Reloading the system configuration in the channel...\n");
  ares_reinit(channel);
  printf("Destroying the channel...\n");
  ares_destroy(channel);
  ret = 0;
library_cleanup:
  printf("Cleaning up the c-ares library...\n");
  ares_library_cleanup();
  return ret;
}
