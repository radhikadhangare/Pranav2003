% Facts
parent(john, mary).
parent(john, paul).
parent(mary, susan).
parent(paul, james).
parent(paul, anna).
parent(susan, lisa).
parent(susan, mark).

male(john).
male(paul).
male(james).
male(mark).
female(mary).
female(susan).
female(anna).
female(lisa).

% Rules
father(X, Y) :- parent(X, Y), male(X).
mother(X, Y) :- parent(X, Y), female(X).
grandparent(X, Y) :- parent(X, Z), parent(Z, Y).
sibling(X, Y) :- parent(Z, X), parent(Z, Y), X \= Y.
uncle(X, Y) :- sibling(X, Z), parent(Z, Y), male(X).
aunt(X, Y) :- sibling(X, Z), parent(Z, Y), female(X).
cousin(X, Y) :- parent(Z, X), sibling(Z, W), parent(W, Y).

% Example Queries
% Who are the siblings of Paul?
% ?- sibling(paul, Sibling).

% Who are the uncles of Mark?
% ?- uncle(Uncle, mark).

% Who are the aunts of Lisa?
% ?- aunt(Aunt, lisa).

% Who are the cousins of James?
% ?- cousin(james, Cousin).
