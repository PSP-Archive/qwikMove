qwikMove v2

This app will quickly move large files and directories.
It does not use the copy and paste method which takes a long time to move big files and directories.
Thanks to Total_Noob for his find on this function.

I have modified the source code to read two files from the root of the memory stick, called MOVESOURCE.TXT and MOVEDEST.TXT.

MOVESOURCE.TXT should contain the path to the file/directory that you want to move.

MOVEDEST.TXT should contain the path that you want to move the file/directory to.

Example usage for files:

MOVESOURCE.TXT entry:
/PSP/COMMON/BIGFILE.ISO

MOVEDEST.TXT entry:
/ISO/BIGFILE.ISO


Example usage for directories:

MOVESOURCE.TXT entry:
/PSP/COMMON/FOLDER

MOVEDEST.TXT entry:
/PSP/GAME/FOLDER


Note:
The entries must not end with a new line, otherwise the function will not work.

The modified source code has been included.

Thanks to Total_Noob for his find. :)