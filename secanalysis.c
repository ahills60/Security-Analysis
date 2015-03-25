/* Main function for security analysis */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "secalgorithms.h"

void printchars(char*, int);
void printints(uint8_t*, int);

void printchars(char *msg, int len)
{
    int n;
    
    for (n = 0; n < len; n++)
        printf("%X ", msg[n] & 0xFF);
    printf("\n");
}

void printints(uint8_t *msg, int len)
{
    int n;
    
    for (n = 0; n < len; n++)
        printf("%X ", msg[n] & 0xFF);
    printf("\n");
}

void main(void)
{
    unsigned char state[] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 
                             0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff};
    uint8_t msg[] =         {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 
                             0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff};
    unsigned char key1[]  = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
                             0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f};
    unsigned char key2[]  = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
                             0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f};
    
    uint32_t cntStart = 0;
    uint8_t len = 16;
    int n;
    
    
    // Initialise counters
    initialiseCounters();
    
    
    printf("\n\n");
    printf("Testing XTEA first\n");
    printf("==================\n\n");
    
    nwk_securityInit();
    printf("Input: ");
    printints(msg, len);
    msg_encipher(msg, len, &cntStart);
    printf("\n\nEncrypted: ");
    printints(msg, len);
    
    cntStart = 0;
    msg_decipher(msg, len, &cntStart);
    printf("\n\nDecrypted: ");
    printints(msg, len);
    printf("\n\n");
    
    for (n = 0; n < len; n++)
    {
        if ((uint8_t) state[n] != msg[n])
        {
            printf("XTEA mismatch in character %i. Got %u instead of %u.\n", n, msg[n], state[n]);
        }
    }
    printf("\n");
    
    // Finally, print results
    printCounters();
    
    // Reset counters
    initialiseCounters();
    
    printf("\n\n");
    printf("Now testing AES\n");
    printf("===============\n\n");
    
    printf("Input: ");
    printchars(state, len);
    
    aes_enc_dec(state,key1,0);
    
    printf("\n\nEncrypted: ");
    printchars(state, len);
    
    aes_enc_dec(state,key2,1);
    printf("\n\nDecrypted: ");
    printchars(state, len);
    
    printf("\n\n");
    
    // Print counters:
    printCounters();
    
    exit(0);
}

