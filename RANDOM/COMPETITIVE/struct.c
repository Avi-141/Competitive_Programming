#include<stdio.h>
void main()
{
struct sample{
char name[7],*str;
};
struct sample s1={"Udupiaaa","Manipal"};
printf("%s",s1.name);
printf("%c",*s1.str+4);
}
