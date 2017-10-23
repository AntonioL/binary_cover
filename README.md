# Covers of query results
This is a proof of concept implementation showing how one can compute covers of the result of the conjunctive query **R1(A, B), R2(A, C)**.
Covers are shown to be isomorphic to factorized representations [1], but they benefit of a tabular representation which makes their implementation in mainstream database engines easier compared to d-representations [2].

In my example I show how one can adapt the nested loop join query algorithm in order to compute a cover of a query result (with the main ingredient being the addition of a map for the keys).
One can get rid of this map for the keys by exploiting sort-merge join, in which case the cover can be computed in linearithmic time).

In the toy example there is no enumeration of the tuples of the query result. The implementation was done in a quick 30mins as means of a proof of concept.

## To do
- Generalize to arbitrary (and acyclic) conjunctive queries, and to arbitrary relations
- Tuple enumeration from a cover of the result

## References
[1] Covers of Query Results. Ahmet Kara, Dan Olteanu. arXiv:1709.01600

[2] Storage Layer for Factorized Data. Antonio Lombardo, MSc Thesis, University of Oxford
