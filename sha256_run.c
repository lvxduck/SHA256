#include <stdio.h>
#include <memory.h>
#include <string.h>
#include "sha256.h"
#include "sha256.c"

//_______________________ ĐỊNH NGHĨA HÀM _______________________/
void sha256(BYTE text[])
{
	static BYTE buf[SHA256_BLOCK_SIZE];
	SHA256_CTX ctx;
	int idx;

	sha256_init(&ctx);
	sha256_update(&ctx, text, strlen(text));
	sha256_final(&ctx, buf);

	printf("\n4. Ket qua:");
	printf("\nSHA256: ");
	for (int i = 0; i < sizeof(buf); i++)
	{
		printf("%x", buf[i]);
	}
}

int main()
{
	BYTE text[20];
	printf("Enter text: ");
	gets(text);
	sha256(text);
	// sha256_test();
	return (0);
}
