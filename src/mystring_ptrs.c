#include "mystring.h"
/*Return the length of s1.
It is a checked runtime error for s1 to be NULL.*/
size_t ms_length(const char *s1) {
	const char *s1End = s1;
	assert(s1);
	while (*s1End) {
	  s1End++;
   }
	return s1End - s1;
}

/*Return s1, in which we copy s2.
It is a checked runtime error for s1,s2 to be NULL.*/
char* ms_copy(char* s1,const char* s2) {
   char*p=s1;
   assert(s1);
   assert(s2);
	while(*s2){          /*oso o s2 pointer einai diaforos tou null*/
		*s1=*s2;
		s1++;             /*o s1 tha deixnei sto idio char me to s2*/
		s2++;
	}
	*s1='\0';         /*teleutaio stoixeio to '\0*/
   return p;         /*epistrefw to p pou deixnei sto prwto stoixeio tou string*/
}

/*Return s1, in which we copy the first n characters of s2.
1)If n>length of s2 then we fill in with '\0' to make s1 length reach n characters.
It is a checked runtime error for s1,s2 to be NULL.*/
char* ms_ncopy(char *s1, const char *s2, size_t n){
   int i,length;
   char*p=s1;
   assert(s1);
   assert(s2);
   length=ms_length(s2);
   if(length<n) {
      for(i=0;i<length;i++) {          /*first case o s1 deixnei sto idio char me to s2-*/
    	   *s1=*s2;
         s1++;
         s2++;
      }
      for(i=length;i<n;i++){
         *s1='\0';               /*-kai gemizw mexri na ftasw n length me '\0'*/
         s1++;
      }
   }
	else{
      for(i=0;i<n;i++) {
    	   *s1=*s2;                /*second case antigrafw olo to string*/
         s1++;
         s2++;
      }	
      *s1='\0';
   }
   return p;
}

/*Return s1, in which we concatenate s2.
It is a checked runtime error for s1,s2 to be NULL.*/
char* ms_concat(char* s1, const char*s2){
   int length1;
   char* p;
   assert(s1);
   assert(s2);
   length1=ms_length(s1);
   p=s1+length1;              /*vazw to p na deixnei sto telos tou s1 ws vohthitikh metavlhth*/
   while(*s2){
      *p=*s2;              /*vazw sto telos tou p to s2*/
      p++;
	   s2++;
   }  
   *p='\0';      /*vazw sto telos tou neou p to '\0' gia na teleiwsei to string*/
   return s1;           /*gurnaw to s1 afou to tropopoihsa me th voitheia tou pointer p*/
}

/*Return s1, in which we copy the first n characters of s2.
It is a checked runtime error for s1,s2 to be NULL.*/
char* ms_nconcat(char* s1, const char* s2, size_t n){
   int i=0,length1;
   char* p;
   assert(s1);
   assert(s2);
   length1=ms_length(s1);
   p=s1+length1;                  /*vazw to p na deixnei sto telos tou s1 ws vohthitikh metavlhth*/
   for(i=0;i<n;i++){
      *p=*s2;              /*vazw sto telos tou p tous prwtous n characters tou s2*/
      p++;
	   s2++;
   }
   *p='\0';             /*vazw sto telos tou neou p to '\0' gia na teleiwsei to string*/
   return s1;            /*gurnaw to s1 afou to tropopoihsa me th voitheia tou pointer p*/
}

/*Lexicographical comparison of s1 and s2.
Return 0 if s1=s2, return an integer greater than 0 if s1>s2,
return an integer less than 0 if s1<s2.This integer is the difference in ascii table.
It is a checked runtime error for s1,s2 to be NULL.*/
int ms_compare(const char *s1, const char *s2){
   assert(s1);
   assert(s2);
   while(*s1 && *s2 && *s1==*s2) { /*oso oi pointers dn einai null kai ta stoixeia sta opoia deixnoun einai idia diatrexw*/
      s1++;
	   s2++;
   }
   if(*s1==*s2) return 0;           /*an vghka apto loop kai einai isa return 0*/
   return (*s1-*s2);                   /*an to loop teleiwse epeidh vrethike diaforetiko stoixeio epistrefw th diafora sto ascii*/
}

/*Lexicographical comparison of s1 and the first n characters of s2.
Return 0 if s1=s2, return an integer greater than if s1>s2,
return an integer less than 0 if s1<s2. This integer is the difference in ascii table.
It is a checked runtime error for s1,s2 to be NULL.*/
int ms_ncompare(const char *s1, const char *s2, size_t n){
   int stop=0,i=0;
   assert(s1);
   assert(s2);
   while(*s1 && *s2 && i<n) {     /*oso oi pointers dn einai null mexri na ftasw to n diatrexw*/
	if(*s1==*s2) stop=0;
    else {
        stop=1;      /*an den einai isa tote vgainw apto loop*/
        break;
    }
   s1++;
	s2++;
	i++;
   }
   if(stop==0) return 0;  /*an de vrethike aniso character einai isa ara return 0*/
   return (*s1-*s2);    /*an to loop teleiwse epeidh vrethike diaforetiko stoixeio epistrefw th diafora sto ascii*/
}

/*Search for substring s2 in s1.
Return NULL if s2 is not found in s1 or Return a pointer to the first character
of the first occurence of s2. Return s1 if s2 is an empty string.
It is a checked runtime error for s1,s2 to be NULL.*/
char* ms_search(char s1[], const char s2[]){
   int s=0,k=0,length=0;
   char* p1;
   char* tmp;
   assert(s1);
   assert(s2);
   length=ms_length(s2);
   if(*s2=='\0') return s1;
   while(*s1) {               /*diatrexw to prwto string, anazhtwntas to s2 mesa tou*/
      p1=s1;               /*an vrethei enas idios xarakthras tote elegxw an vrhka to substring*/
      if(*s1==*s2) {       /*apothikeuw sto p1 to shmeio pou ksekinaei to substring entos tou s1, an to vrw*/
        tmp=s1;
        for(k=0;k<length;k++) {
            if(*p1!=*(s2+k)) {     /*diatrexw to s2 kai elegxw an emperiexetai sto s1*/
               s=0;
               break;
            }
            else {
               s=1;
            }
            p1++;
        }
        if(s==1) break;    /*spaei to loop an vrethike to substring*/
      }  
      s1++;
   }
   if(s==1){
      s1=tmp;           /*vazw to shmeio pou arxizei to substring sto s1*/
   }
   if(s==0) s1=NULL;       /*alliws an de vrhka substring return null*/
   return s1;
}

