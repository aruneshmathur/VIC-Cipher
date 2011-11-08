#include <getopt.h>
int DEFAULT_DATE[6] = {7, 4, 1, 7, 7, 6};
int DEFAULT_RANDOM[6] = {7, 7, 6, 5, 1};
char *DEFAULT_MESSAGE = "WE ARE PLEASED TO HEAR OF YOUR SUCCESS IN ESTABLISHING YOUR FALSE IDENTITY YOU WILL BE SENT SOME MONEY TO COVER EXPENSES WITHIN A MONTH";
char *DEFAULT_KEYPHRASE = "IDREAMOFJEANNIEWITHT";
int DEFAULT_PERSONAL_NUMBER = 8;

struct option longopts[] = {        
        { "date", 1, NULL, 'd'   },      
        { "personal", 1, NULL, 'p' },
        { "keyphrase", 1, NULL, 'k' },
        { "message", 1, NULL, 'm' },
        { 0,    0,    0,    0   }    
};
