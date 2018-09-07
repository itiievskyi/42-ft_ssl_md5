/* File       : SHA256.c
 * Description: C implementation of SHA-256 (256-bit Secure Hash Algorithm).
 *              
 * Author     : AugFJTan
 * Last Modified 18 Feb 2018 06:50 PM
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

int derive_k(uint64_t l);
uint32_t right_rotate(uint32_t x, int n) { return (x >> n) | (x << (32-n)); }
uint32_t s0(uint32_t x) { return right_rotate(x, 7) ^ right_rotate(x, 18) ^ (x >> 3); }
uint32_t s1(uint32_t x) { return right_rotate(x, 17) ^ right_rotate(x, 19) ^ (x >> 10); }
uint32_t S0(uint32_t x) { return right_rotate(x, 2) ^ right_rotate(x, 13) ^ right_rotate(x, 22); }
uint32_t S1(uint32_t x) { return right_rotate(x, 6) ^ right_rotate(x, 11) ^ right_rotate(x, 25); }
uint32_t ch(uint32_t x, uint32_t y, uint32_t z) { return (x & y) ^ (~x & z); }
uint32_t maj(uint32_t x, uint32_t y, uint32_t z) { return (x & y) ^ (x & z) ^ (y & z); }

int main(int argc, char *argv[])
{
	/* Hex constants */
	uint32_t H[8] = {0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a, 0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19};
	
	uint32_t K[64] = {
	0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
	0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
	0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
	0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
	0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
	0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
	0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
	0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2};
	
	/* Variables */
	char *raw_message, *default_message = "Hello World!";
	int chunks, i, j, m, n, k;
	uint64_t l, message_length;
	uint32_t temp1, temp2;
	uint32_t a, b, c, d, e, f, g, h;
	uint32_t **bit_array, w[64];
	
	raw_message = (argc == 1) ? default_message : argv[1];
	
	/* Pre-processing */
	l = strlen(raw_message) * sizeof(char) * 8;  /* Assuming ASCII encoding */
	k = derive_k(l);
	
	/* Allocate memory for each 512-bit chunk (16 32-bit values) */
	message_length = l + 1 + k + 64;
	chunks = message_length / 512;
	
	bit_array = (uint32_t**)calloc(chunks, sizeof(uint32_t*));
	
	for(i=0; i < chunks; i++)
		bit_array[i] = (uint32_t*)calloc(16, sizeof(uint32_t));
	
	/* Assign values */
	i = j = n = 0;
	m = 3;
	
	while(raw_message[n] != '\0')
	{
		bit_array[i][j] |= raw_message[n] << m * 8;
		
		printf(" ");
		n++;
		if(m > 0)
			m--;
		else
		{
			m = 3;
		
			if(j < 16)
				j++;
			else
			{
				j = 0;
				i++;
			}
		}

	}
	/* Append '1'-bit */
	bit_array[i][j] |= 0x80 << m * 8;
	
	/* Append length as 64-bit big endian value */
	bit_array[chunks-1][14] = (uint32_t)(l >> 32);
	bit_array[chunks-1][15] = (uint32_t)(l & 0xffffffff);
/*	
	int y;
	size_t z = -1;
	while (++z < message_length + 8) {
		for (y = 0; y < 8; y++) {
			printf("%d", !!((bit_array[z] << y) & 0x80));
		}
		printf(" ");
	}
	printf("\n");
*/
	/* Process message */
	for(j=0; j<chunks; j++)
	{
		for(i=0; i<16; i++)
			w[i] = bit_array[j][i];
		
		for(i=16; i<64; i++)
			w[i] = w[i-16] + s0(w[i-15]) + w[i-7] + s1(w[i-2]);

		a = H[0];
		b = H[1];
		c = H[2];
		d = H[3];
		e = H[4];
		f = H[5];
		g = H[6];
		h = H[7];
		printf("ctx->b = %x\n", b);
		for(i=0; i<64; i++)
		{
			temp1 = h + S1(e) + ch(e, f, g) + K[i] + w[i];
			temp2 = S0(a) + maj(a, b, c);
			
			h = g;
			g = f;
			f = e;
			e = d + temp1;
			d = c;
			c = b;
			b = a;
			a = temp1 + temp2;
		}
		printf("w[i] = %x\n", w[63]);
		H[0] += a;
		H[1] += b;
		H[2] += c;
		H[3] += d;
		H[4] += e;
		H[5] += f;
		H[6] += g;
		H[7] += h;
		printf("H[0] = %x\n", H[0]);
	}
	
	/* Free memory */
	for(i=0; i < chunks; i++)
		free(bit_array[i]);
	
	free(bit_array);
	
	/* Display the final hash */
	printf("Message: \"%s\"\n", raw_message);
	printf("Hash: ");
	
	for(i=0; i<8; i++)
		printf("%08x", H[i]);
	
	printf("\n");
	
	return 0;
}

int derive_k(uint64_t l)
{
	int remainder = (l + 1 + 64) % 512;
	
	if(remainder == 0) /* Total message length is a multiple of 512 */
		return 0;
	else
		return 512 - remainder;
}
