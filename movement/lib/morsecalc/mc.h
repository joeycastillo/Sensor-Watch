/* mc Morse code reading methods
*/
#include "stdint.h"

#define BUFFLEN 5
typedef struct {
    char b[BUFFLEN];
    uint8_t bidx;
} mc_state_t;

// MC_DEC_KEY represents a binary tree of International Morse Code. 
// where '.' = 0 and '-' = 1. Levels of the tree are concatenated.
static const char MC_DEC_KEY[] = " etianmsurwdkgohvf\0l\0pjbxcyzq\0\0\x35\x34U\x33\0\0\0\x32W\0+\0\0\0\0\x31\x36=/\0\0S(\0\x37\0\0\0\x38\0\x39\x30\0\0\0\0\0E\0\0\0\0\0\0?\0\0\0\0\0\"\0\0.\0\0\0\0@\0\0\0'\0\0-\0\0\0\0\0\0\0\0\0\0\0)\0\0\0\0\0,\0\0\0\0:\0\0\0\0\0\0"; 
    
void mc_reset(mc_state_t * mcb);
void mc_input(mc_state_t * mc, char c);
char mc_dec(char b[BUFFLEN]);

