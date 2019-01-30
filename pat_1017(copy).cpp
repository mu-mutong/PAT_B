#include "stdio.h"
#include"string.h"
#include <stdlib.h>
int main(){
     char a[1001];
     int ge,shi,i,count,b=7;
     gets(a);
     count=strlen(a);
     b=a[count-1]-'0';
     shi=a[0]-'0';
     ge=a[1]-'0';
     if(count<=3)
         printf("%d %d",shi/b,shi%b );
     else
        { 
        if(count==4)
           printf("%d %d",(shi*10+ge)/b,(shi*10+ge)%b ); 
        else
            {
        		for(i=2;i<count-1;i++)
                 {
                    printf("%d",(shi*10+ge)/b );
                    shi =(shi*10+ge)%b;
                    ge=a[i]-'0';
              	 }
              printf(" %d",shi );
          	 }

       }
    return 0;
	}
