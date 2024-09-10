#include "mystring.h"
/*Return the length of s1.
It is a checked runtime error for s1 to be NULL.*/
size_t ms_length(const char s1[]) {
   size_t uiLength = 0U;
   assert(s1);
   while (s1[uiLength]) {
	  uiLength++;
   }
   return uiLength;
}

/*Return s1, in which we copy s2.
It is a checked runtime error for s1,s2 to be NULL.*/
char* ms_copy(char s1[],const char s2[]) {
   int i=0;
   assert(s1);
   assert(s2);       
   while(s2[i]){        /*diatrexoume olo to s2*/
	s1[i]=s2[i];      /*kai antigrafoume enan enan tous xarakthres sto s1*/
    	   i++;
   }	
   s1[i]='\0';          /*termatizoume me '\0' gia na thewththei string*/
   return s1;
}

/*Return s1, in which we copy the first n characters of s2.
1)If n>length of s2 then we fill in with '\0' to make s1 length reach n characters.
It is a checked runtime error for s1,s2 to be NULL.*/
char* ms_ncopy(char s1[], const char s2[], size_t n){
   int i,length;
   assert(s1);
   assert(s2);
   length=ms_length(s2);
   if(length<n) {
      for(i=0;i<length;i++) {
    	   s1[i]=s2[i];         /*first case antigrafw olo to string*/
      }
      for(i=length;i<n;i++){
         s1[i]='\0';       /*kai gemizw mexri na ftasei n length me '\0'*/
      }
   }
   else{
      for(i=0;i<n;i++) {
    	   s1[i]=s2[i];         /*second case antigrafw olo to string*/
      }	
   }
   return s1;
}

/*Return s1, in which we concatenate s2.
It is a checked runtime error for s1,s2 to be NULL.*/
char* ms_concat(char s1[], const char s2[]){
   int i=0,length1;
   assert(s1);
   assert(s2);
   length1=ms_length(s1);     /*vriskw to telos tou s1 gia na sunexisw apo ekeino to shmeio*/
   while(s2[i]){                 /*diatrexw olo to s2*/
      s1[length1]=s2[i];         /*sto telos tou s1 enwnw tous xarakthres tou s2*/
      length1++;
      i++;
   }
   s1[length1]='\0';        /*teleutaio stoixeio to '\0'*/
   return s1;
}

/*Return s1, in which we copy the first n characters of s2.
It is a checked runtime error for s1,s2 to be NULL.*/
char* ms_nconcat(char s1[], const char s2[], size_t n){
   int i=0,length1;
   assert(s1);
   assert(s2);
   length1=ms_length(s1);
   while(s2[i] && i<n){          /*enwnw sto telos tou s1 n characters apo to s2*/
      s1[length1]=s2[i];
      length1++;
      i++;
   }
   s1[length1]='\0';      /*teleutaio stoixeio to '\0'*/
   return s1;
}

/*Lexicographical comparison of s1 and s2.
Return 0 if s1=s2, return an integer greater than 0 if s1>s2,
return an integer less than 0 if s1<s2.This integer is the difference in ascii table.
It is a checked runtime error for s1,s2 to be NULL.*/
int ms_compare(const char s1[], const char s2[]){
   int i=0;
   assert(s1);
   assert(s2);
   while(s1[i] && s2[i] && s1[i]==s2[i]) {      /*oso einai isa proxwraw*/
      i++;
   }
   if(s1[i]==s2[i]) return 0;       /*an to loop teleiwse epeidh teleiwsan ta strings tote einai isa ara return 0*/
   return s1[i]-s2[i];  /*an to loop teleiwse epeidh vrethike diaforetiko stoixeio epistrefw th diafora sto ascii*/
}

/*Lexicographical comparison of s1 and the first n characters of s2.
Return 0 if s1=s2, return an integer greater than 0 if s1>s2,
return an integer less than 0 if s1<s2. This integer is the difference in ascii table.
It is a checked runtime error for s1,s2 to be NULL.*/
int ms_ncompare(const char s1[], const char s2[], size_t n){
   int i=0,stop=0;
   assert(s1);
   assert(s2);
   i=0;
   for(i=0;i<n;i++) {
      if(s1[i]==s2[i]) stop=0;
      else {
         stop=1;        /*an vrethei diaforetikos xarakthras stous prwtous n xarakthres*/
         break;         /*tote vgainw apo to loop*/
      }
   }
   if(stop==0) return 0;   /*an to loop termatise xwris na vrethei diaforetikos xarakthras tote einai isa ara return 0*/
   return s1[i]-s2[i];   /*an to loop teleiwse epeidh vrethike diaforetiko stoixeio epistrefw th diafora sto ascii*/
}

/*Search for substring s2 in s1.
Return NULL if s2 is not found in s1 or Return a pointer to the first character
of the first occurence of s2. Return s1 if s2 is an empty string.
It is a checked runtime error for s1,s2 to be NULL.*/
char* ms_search(char s1[], const char s2[]){
   int i=0,j=0,s=0,tmp=0,k=0,length=0,m=0;
   assert(s1);
   assert(s2);
   length=ms_length(s2);
   if(s2[0]=='\0') return s1;
   while(s1[j]) {             /*diatrexw to prwto string, anazhtwntas to s2 mesa tou*/
      if(s1[j]==s2[i]) {         /*an vrethei enas idios xarakthras tote elegxw an vrhka to substring*/
        tmp=j;                /*apothikeuw sto tmp to shmeio pou ksekinaei to substring entos tou s1, an to vrw*/
        m=j;
        for(k=0;k<length;k++) {     /*diatrexw to s2 kai elegxw an emperiexetai sto s1*/
            if(s1[m]!=s2[k]) {
                s=0;
                break;
            }
            else {
               s=1;
            }
            m++;
        }
        if(s==1) break;          /*an einai isoi oi xarakthres tote teleiwnei h epanalhpsh giati vrhkame to substring*/
      }
      j++;
   }
   if(s==1){         /*an vrhkame to substring*/
         j=0;
         while(s1[tmp]){      /*apo to tmp kai meta*/
               s1[j]=s1[tmp];          /*vazw sto s1 tous xarakthres apo to substring kai meta*/
               tmp++;
               j++;
            }
         s1[j]='\0';       /*termatizw me '\0'*/
   }
   else s1=NULL;     /*an de vrhka to substring gurnaw null*/
   return s1;
}
