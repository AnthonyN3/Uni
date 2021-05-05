/* Question 1 */
isort([],[]).	/*base*/
isort([H|List], Result):- isort(List, Temp), insert(H, Temp, Result). /*recursive call and insert per call*/

/* ! is a cut (saw online) to remove redundancy. Comparison done here then inserts correctly into sorted list */
insert(X, [H|List], [H|Result]):-H < X, !, insert(X, List, Result).
insert(X, List, [X|List]).	/*if list empty, or is found to be first of list, insert into top of sorted list*/

/* Question 2 */
/*(a)*/
edge(a,b).
edge(a,c).
edge(b,c).
edge(c,d).
edge(d,e).
edge(f,e).
edge(f,g).
/*(b)*/
path(X, X).
path(X, Y):-edge(X, Z), path(Z, Y).

/*(c) - (f)*/
/*
	path(a,g) --> false
	path(f,e) --> true
	path(f,g) --> true
	path(g,e) --> false
*/