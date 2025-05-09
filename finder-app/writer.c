#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>

int main(int argc, char *argv[]) {
  openlog(NULL, LOG_CONS | LOG_PID | LOG_NDELAY, LOG_USER);

  if (argc < 3) {
    return EXIT_FAILURE;
  }

  char *filename = argv[1];
  char *string = argv[2];

  FILE *output_file = fopen(filename, "w");
  if (!output_file) {
    syslog(LOG_ERR, "Failed to open file %s, errno %d", filename, errno);
    return EXIT_FAILURE;
  } else {
    int result = fprintf(output_file, "%s", string);
    if (result < 0) {
      syslog(LOG_ERR, "Failed to write to file %s, errno %d", filename, errno);
      fclose(output_file);
      return EXIT_FAILURE;
    }

    syslog(LOG_DEBUG, "Writing %s to %s", string, filename);
    fclose(output_file);
    return EXIT_SUCCESS;
  }
}
