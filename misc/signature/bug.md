## Logical flaw
Prepending contents to a file in C is particularly convoluted since it requires a few preliminary steps.
When a file is created and then saved the number of bytes allocated to that file remain fixed since it is not changed right away.
This means that trying to change it with functions such as fprintf with the stream set to the file stream returned by fopen leads to some issues.

1. The file will result truncated losing the final characters which have been replaced by those prepended at the beginning of the file
2. The remaining file will therefore be corrupted and will not be equivalent to the original one.

## Updated approach
The revised approach revolves around creating a temporary file where the contents from the original file are appended after inserting the needed lines at the beginning.

1. Create a temporary file in write mode to rewrite the contents of the original file.
2. Open the original file in read-only mode and copy its contents to a buffer.
