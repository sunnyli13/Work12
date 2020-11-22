#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {

	DIR *d = opendir(".");
	struct dirent *entry;
	entry = readdir(d);
	struct stat file;
	int total = 0;

	printf("Statistics for directory: .\n");

	while (entry) {
		if (entry->d_type == DT_REG) {
			stat(entry->d_name, &file);
			total += file.st_size;
		}

		entry = readdir(d);
	}

	printf("Total Directory Size: %d Bytes\n", total);

	printf("Directories: \n");

	rewinddir(d);
	entry = readdir(d);

	while (entry) {
		if (entry->d_type == DT_DIR) {
			printf("\t%s\n", entry->d_name);
		}

		entry = readdir(d);
	}

	printf("Regular files: \n");

	rewinddir(d);
	entry = readdir(d);

	while (entry) {
		if (entry->d_type == DT_REG) {
			printf("\t%s\n", entry->d_name);
		}
		
		entry = readdir(d);
	}

	closedir(d);

	return 0;
}