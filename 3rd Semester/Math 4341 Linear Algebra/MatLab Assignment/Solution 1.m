%Basic commands 

E = eye(3)
u = E(:,1)
E(3,1) = 5
v = E*u
A = ones(3) + eye(3)
b = A(:,3)
c = inv(A)
x = A\b

%How to input a row or column vector

u = [2 4 5]
v = [2; 4; 5]
v = [2 4 5]'
w = 2:5
u = 1:2:7

%How to input a matrix 

A = [1 2 3; 4 5 6]
A = [1 2 3
	4 5 6]
B = [1 2 3; 4 5 6]'

%How to create special matrices

diag(v)
toeplitz(v)
toeplitz(w,v)
ones(n)
zeros(n)
eye(n)
rand(n)
randn(n)
ones(m,n)
zeros(m,n)
rand(m,n)
ones(size(A))
zeros(size(A))
eye(size(A))

%How to change entries in a given matrix 

A(3,2) = 7
A(3,:) = v
A(:,2) = w
A([2 3],:) = A([3 2],:)

%How to create submatrices of an m x n matrix A

A(i,j)
A(i,:)
A(:,j)
A(2:4,3:7)
a([2 4],:)
A(:)
triu(A)
tril(A)

%Matrix Multiplication and Inversion

A*B
A.*B
inv(A)
pinv(A)
A\B
x = A\b

%Numbers and matrices associated with A

det(A)
rank(A)
size(A)
trace(A)
null(A)
orth(A)

%Examples

E = eye(4);E(2,1)
E*A
B = [A b]
E = eye(3);P = E([2 1 3],:)

%Built-in M-files for matrix factorization 

[L,U,P] = lu(A)
e = eig(A)
[S, E] = eig(A)
[Q, R] = qr(A)

