int braces(char* A) {

    int len=strlen(A);
    int top=-1;
    int i=0;
    char * stack=(char *)malloc(len*sizeof(char));
    
    while(i<len)
        {
            if(A[i]==')' && ( top==-1 || stack[top]=='(' || stack[top-1]=='(') )
                return 1;
                
            else if( A[i]==')' )
                {
                while(stack[top] != '(')
                    top--;
                top--;    
                }
            else
                {
                    stack[++top]=A[i];
                }
                
            i++;
        }
        
    if(top!=-1)
        {
            for(i=0;i<top;i++)
                if(stack[i]=='(')
                    return 1;
        }
    
    return 0;
}