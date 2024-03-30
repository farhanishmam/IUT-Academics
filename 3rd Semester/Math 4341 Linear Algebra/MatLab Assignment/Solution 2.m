%Problem 1 

A = [2 3;4 5]
x = [1;7]
b = [24;5]

if(A*x == b)
	disp('A*x is equal to b')
else
	disp('A*x is not equal to b')
end

%Problem 2

%Output of A*v is v or the column vector (3,4,5)
%Output of v'*v is 50
%Gives error for using operator * with incorrect dimensions

%Problem 3

%Output is column vector (4,4,4,4)
%Output is column vector (10,10,10,10)

%Problem 4
P=pascal(4);
inv(P)

%Problem 5
L = abs(pascal(4,1))

if P == L*L'
	disp('P is equal to L*L''')
else
	disp('P is not equal to L*L''')
end