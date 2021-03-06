#include <stdint.h>

#define TIMING_TABLE_SIZE 1536

#define PARSE_META_RUN  0 // meta command, exit the parser and run the program
#define PARSE_COMMAND	1 // line parsed as valid command
#define PARSE_COMMENT	2 // line parsed as (only) comment
#define PARSE_WSPACE	3 // line parsed as (only) whitespace	
#define PARSE_META	4 // line contained meta command (except 'run')

#define PARSE_UNKNOWN  -1 // unknown command
#define PARSE_ARGRANGE -2 // argument out of range
#define PARSE_LEVELERR -3 // nesting level wrong
#define PARSE_LFULL    -8 // no loops left
#define PARSE_NOOPCODE -9 // unknown opcode

uint8_t _term_echo ;

typedef struct {
    uint8_t size;
    uint8_t cmd[4];
} parsed_cmd ; 

int16_t parse_line(char * line);

parsed_cmd ret_last_cmd();

void parser_init( volatile uint8_t * command_table );
void parser_echo_result(int16_t res);
void parser_setverbosity(int8_t verb);
void print_listing();


int16_t find_opcode_bycode(uint8_t code);
int16_t find_opcode_bynm( const char *nmemonic);

