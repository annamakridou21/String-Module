#include <stddef.h>
#include <stdio.h>
#include <assert.h>

/*Return the length of s1.
It is a checked runtime error for s1 to be NULL.*/
size_t ms_length(const char*s1);

/*Return s1, in which we copy s2.
It is a checked runtime error for s1,s2 to be NULL.*/
char* ms_copy(char*s1,const char*s2);

/*Return s1, in which we copy the first n characters of s2.
If n>length of s2 then we fill in with '\0' to make s1 length reach n characters.
It is a checked runtime error for s1,s2 to be NULL.*/
char* ms_ncopy(char*s1, const char*s2, size_t n);

/*Return s1, in which we concatenate s2.
It is a checked runtime error for s1,s2 to be NULL.*/
char* ms_concat(char*s1, const char*s2);

/*Return s1, in which we copy the first n characters of s2.
It is a checked runtime error for s1,s2 to be NULL.*/
char* ms_nconcat(char*s1, const char*s2, size_t n);

/*Lexicographical comparison of s1 and s2.
Return 0 if s1=s2, return an integer greater than 0(1) if s1>s2,
return an integer less than 0(-1) if s1<s2.
It is a checked runtime error for s1,s2 to be NULL.*/
int ms_compare(const char*s1, const char*s2);

/*Lexicographical comparison of s1 and the first n characters of s2.
Return 0 if s1=s2, return an integer greater than 0(1) if s1>s2,
return an integer less than 0(-1) if s1<s2.
It is a checked runtime error for s1,s2 to be NULL.*/
int ms_ncompare(const char*s1, const char*s2, size_t n);

/*Search for substring s2 in s1.
Return NULL if s2 is not found in s1 or Return a pointer to the first character
of the first occurence of s2. Return s1 if s2 is an empty string.
It is a checked runtime error for s1,s2 to be NULL.*/
char* ms_search(char*s1, const char*s2);
