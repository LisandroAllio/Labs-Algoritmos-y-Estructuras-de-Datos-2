#ifndef STRFUNCS_H_
#define STRFUNCS_H_

/**
* @brief Return the lenght of the chain 
* @param str A pointer to char
* @return the lenght of the chain
*/
size_t string_length(const char *str);

/**
* @brief Creates a chain in dinamyc memory only with those chars which are diferent from a single char c.  
* @param str A pointer to char
* @param c A char
* @return A Chain in dinamyc memory
*/
char *string_filter(const char *str, char c);

#endif