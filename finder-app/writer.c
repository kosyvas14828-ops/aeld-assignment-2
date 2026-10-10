#include <stdio.h>
#include <syslog.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

	openlog("writer", LOG_PID, LOG_USER);

	if (argc < 3)
	{
		syslog(LOG_ERR, "Usage: <file> <str>");
		fprintf(stderr, "error 2 arguments needed");
		closelog();
		return 1;
	}
	char *writeFile = argv[1];
	char *writeStr = argv[2];

	FILE *fp = fopen(writeFile, "w+");
	if (fp == NULL)
	{
		syslog(LOG_ERR, "Could not open %s: %s", writeFile, strerror(errno));
		closelog();
		return 1;
	}
	size_t len = strlen(writeStr);
	size_t written = fwrite(writeStr, 1, len, fp);

	if (written != len)
	{
		syslog(LOG_ERR, "Failed to write full string to %s", writeFile);
		fclose(fp);
		closelog();
		return 1;
	}
	syslog(LOG_DEBUG, "Writing %s to %s", writeStr, writeFile);

	fclose(fp);
	closelog();
	return 0;
}
