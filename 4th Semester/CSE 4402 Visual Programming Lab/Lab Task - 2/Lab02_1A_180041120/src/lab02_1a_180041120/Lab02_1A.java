package lab02_1a_180041120;

public class Lab02_1A
{
    public static class myStack
    {
        char items[]; 
        int top; 
        //Following is the constructor that initializes the attributes
         myStack(int size)
         {
             items = new char[size];
             top = -1;
         }
         public void push(char c)
         {
                //COMPLETE THIS PART - should add a new element in the items array and update the top
             top++;
             items[top] = c;
         }
        public char pop()
        {
            if(isEmpty())
             {
                 System.out.println("Nothing left to pop");
                 System.exit(1);
            }
            // COMPLETE THIS PART - should return the top element and reduce the top
          
           top--;
           return items[top+1];
         }
         public Boolean isEmpty()
         {
         // COMPLETE THIS PART - should return true or false based on whether the stack is empty
             if(top==-1)
                 return true;
             else
                 return false;
          }
         public char viewTop()
         {
             if(isEmpty())
             {
                 System.out.println("Nothing left to view");
                 System.exit(1);
             }
             return items[top];
         }
     }
    
    static int precedence(char c)
        {
             switch (c)
             {
                 case '+':
                 case '-':
                    return 1;
                case '*':
                case '/':
                    return 2;
                case '^':
                    return 3;
            }
            return -1;
         }
    
    public static void main(String[] args) 
    {
        int size = 100;
        myStack st = new myStack(size);
        String infix  = "c*(a+b)^2";
        String postfix = "";
        for(int i = 0;i<infix.length();i++)
        {
            char cur = infix.charAt(i);
            if( Character.isLetter(cur)||Character.isDigit(cur)) //Operand is directly added to output string
            {
                postfix+=cur;
            }
            else if(cur=='(')          //The starting bracket only needs to be stored in stack
            {
                st.push(cur);
            }
            else if(cur==')')
            {
                char top_char = st.pop();
                while(top_char!='(')   //Pop everything until the starting bracket is found in the stack
                {
                    postfix += top_char;
                    top_char = st.pop();
                }
            }
            else                        //character is an operator 
            { 
                while(!st.isEmpty())
                {
                    if(precedence(st.viewTop())<precedence(cur))  //If current Operator has higher precedence than stack's top then nothing needs to be popped
                    { 
                        break;
                    }
                    else                         //else we add the operators in stack to our output string  and remove that operator from stack
                    {
                        postfix += st.pop();
                    }
                }
                st.push(cur); //Current operator is pushed
            }
        }
        while(!st.isEmpty())    //remaining operators in stack are added to output string
        {
            postfix+=st.pop();
        }
        System.out.println(postfix);
    }
 }

