#include <pspsdk.h>
#include <pspkernel.h>

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <sys/stat.h>

PSP_MODULE_INFO("qwikMove v2", 0, 1, 0);

#define printf pspDebugScreenPrintf

int sceIoMove(char *src, char *dest)
{
	printf("Moving %s -> %s...", src, dest);

	u32 data[2];
	data[0] = (u32)src;
	data[1] = (u32)dest;
	int res = sceIoDevctl("ms0:", 0x02415830, &data, sizeof(data), NULL, 0);
	printf("0x%08X\n", res);
	return res;
}

int main(int argc, char *argv[])
{
	pspDebugScreenInit();

	printf("qwikMove v2\n");
	printf("IO Move sample by Total_Noob\n");
	printf("Modded by qwikrazor87\n\n");
	sceKernelDelayThread(1 * 1000 * 1000);

	FILE *src, *dest;
	char *buffersrc, *bufferdest;
	int sizesrc, sizedest;

	src = fopen("/MOVESOURCE.TXT", "r");
	if (src == NULL)
	{
		printf("Error\nms0:/MOVESOURCE.TXT could not be located\n\n");
		printf("Exiting...\n");
		sceKernelDelayThread(5 * 1000 * 1000);
		sceKernelExitGame();
	}

	fseek(src,0,SEEK_END);
	sizesrc = ftell(src);
	rewind(src);
	buffersrc = malloc(sizesrc);
	fread(buffersrc,1,sizesrc,src);
	fclose(src);

	dest = fopen("/MOVEDEST.TXT", "r");
	if (dest == NULL)
	{
		printf("Error\nms0:/MOVEDEST.TXT could not be located\n\n");
		printf("Exiting...\n");
		sceKernelDelayThread(5 * 1000 * 1000);
		sceKernelExitGame();
	}

	fseek(dest,0,SEEK_END);
	sizedest = ftell(dest);
	rewind(dest);
	bufferdest = malloc(sizedest);
	fread(bufferdest,1,sizedest,dest);
	fclose(dest);

	struct stat srcentry;
	struct stat destentry;

	if (stat(buffersrc, &srcentry) == 0)
	{
		char *dof;
		if (S_ISDIR(srcentry.st_mode))
		{
			dof = "directory";
		} else {
			dof = "file";
		}

		printf("%s\n is a %s.\n\n", buffersrc, dof);

		sceIoMove(buffersrc, bufferdest);

		if (stat(bufferdest, &destentry) == 0)
		{
			printf("Successfully moved %s.\n\nExiting...", dof);
			sceKernelDelayThread(5 * 1000 * 1000);
			sceKernelExitGame();
		} else {
			printf("Error\ncould not move %s\n\nExiting...",dof);
			sceKernelDelayThread(5 * 1000 * 1000);
			sceKernelExitGame();
		}
	} else {
		printf("%s could not be located.\n", buffersrc);
		printf("\nExiting...\n");
		sceKernelDelayThread(5 * 1000 * 1000);
		sceKernelExitGame();
	}

    return 0;
}