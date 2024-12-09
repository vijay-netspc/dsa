Algorithm Postfix_Eval(string pexp)
//Initialize a Stack S
Begin
pos = 0;
while (pexp(pos) != NULL)
if (pexp(pos) is an operand)
push(S, pexp(pos))
else //operator
b = pop(S)
a = pop(S)
c = evaluate a & b using pexp(pos)
push(S, c)
endif
pos = pos + 1
end while
print (“Result is “+ pop(S))
End
