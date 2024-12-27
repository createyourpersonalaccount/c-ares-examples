/* How to create a channel with options.
 *
 * Note that the ares_options struct is filled out with the desired
 * option values but an options mask must also be passed to
 * ares_init_options(), specifying which fields of the ares_options
 * struct must be taken into account; those not specified are ignored.
 */
#include <ares.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int ret = 0;
  ares_channel_t *channel;
  struct ares_options options = {0};
  printf("Initializing the c-ares library...\n");
  if ((ret = ares_library_init(ARES_LIB_INIT_ALL)) != ARES_SUCCESS) {
    fprintf(stderr, "ares_library_init(): %s\n", ares_strerror(ret));
    return EXIT_FAILURE;
  }
  printf("Initializing a channel with"
         " maxtimeout & qcache max TTL options...\n");
  /* Cap the increase of timeouts to 500ms. */
  options.maxtimeout = 500;
  /* Disable query cache. */
  options.qcache_max_ttl = 0;  
  if ((ret = ares_init_options(&channel, &options,
                               ARES_OPT_MAXTIMEOUTMS | ARES_OPT_QUERY_CACHE)) !=
      ARES_SUCCESS) {
    fprintf(stderr, "ares_init_options(): %s\n", ares_strerror(ret));
    ret = EXIT_FAILURE;
    goto library_cleanup;
  }
  /* Set the list of servers using an option-setter function. Note
     that the setter function is called after channel is initialized
     in this instance, but it also may be called prior to
     initialization if desired.*/
  if ((ret = ares_set_servers_csv(channel, "1.1.1.1, 8.8.8.8")) !=
      ARES_SUCCESS) {
    fprintf(stderr, "ares_set_servers_csv(): %s\n", ares_strerror(ret));
    ret = EXIT_FAILURE;
    ares_destroy(channel);
    goto library_cleanup;
  }
  printf("Destroying the channel...\n");
  ares_destroy(channel);
  ret = 0;
library_cleanup:
  printf("Cleaning up the c-ares library...\n");
  ares_library_cleanup();
  return ret;
}
