#ifndef SHA256_H
#define SHA256_H
#include <stddef.h>

#define SHA256_BLOCK_SIZE 32 // SHA256 outputs a 32 byte digest

//___________________________ KHAI BÁO ___________________________*/
typedef unsigned char BYTE; // 8-bit byte
typedef unsigned int WORD;	// 32-bit word

typedef struct
{
	//Mảng chứa 64 phần tử = 64 ký tự (64x8 = 512bits)/CHUNK
	BYTE data[64];
	//Biến chứa số lượng phần tử data đã gán, nếu datalen == 64 thì sang CHUNK khác
	WORD datalen;
	//Biến chứa số lượng bit data đã xử lí, để thêm vào 64bit độ dài cuối cùng
	unsigned long long bitlen;
	//Mảng chứa 8 phần tử khởi tạo hash ban đầu
	WORD state[8];
} SHA256_CTX;

//_______________________ KHAI BÁO NGUYÊN MẪU HÀM _______________________/
void sha256_init(SHA256_CTX *ctx);
void sha256_update(SHA256_CTX *ctx, const BYTE data[], size_t len);
void sha256_final(SHA256_CTX *ctx, BYTE hash[]);

#endif // SHA256_H
