pythag(A,B,C) :- length(_,N),
                 between(1, N, A),
                 between(1, N, B),
                 between(1, N, C),
                 C*C =:= A*A + B*B,
                 1000 =:= A + B + C.
