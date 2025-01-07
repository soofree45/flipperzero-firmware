#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <fcntl.h>

int main() {
    // Replace "path_to_file" with the actual file path
    const char *file_path = "path_to_file";

    int fd = _open(file_path, _O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    // Get the file size using _filelength
    long file_size = _filelength(fd);
    if (file_size == -1L) {
        perror("filelength");
        _close(fd);
        return 1;
    }

    printf("File size: %ld bytes\n", file_size);

    _close(fd);
    return 0;
}
