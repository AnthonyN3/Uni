#lang racket
(require racket/trace)

(define (quadratic_roots_old a b c)
   (list
    (/ (-(+ b (sqrt (- (expt b 2) (* 4 a c))))) (* 2 a))
    (/ (-(- b (sqrt (- (expt b 2) (* 4 a c))))) (* 2 a))
    )
  )

(define (quadratic_roots a b c)
  (let
    (
     (negB (- b))
     (num (sqrt (- (expt b 2) (* 4 a c))))
     (den (* 2 a))
    )
    (list
     (/ (+ negB num) den)
     (/ (- negB num) den)
    )
  )
)

(define (cmplists l1 l2)
  (if (null? (append l1 l2)) 0 (if (null? l1) 2 (if (null? l2) 1 (cmplists (cdr l1) (cdr l2)))))
)

(define (rem num den)
  (if (> den num) num (if (= den num) 0 (rem (- num den) den)))
)

(define (reduce op ls id)
  (if (null? ls) id (op(car ls) (reduce op (cdr ls) id)))
)
(trace reduce)

(define (reducE op ls id) (reducE-helper op ls id id))

(define (reducE-helper op ls id so-far-result)
  (if (null? ls) so-far-result (reducE-helper op (cdr ls) id (op (car ls) so-far-result)))
)
(trace reducE-helper)

(define (mlist_old L)
  (cond(
        (null? L)1)
       (else
        (* (car L) (mlist (cdr L)))
        )
       )
  )

(define (mlist L)
  (mlist-helper L 1)
)

(define (mlist-helper L so-far)
  (cond(
    (null? L) so-far)
    ((= (car L) 0) 0)
    (else 
       (mlist-helper (cdr L) (* (car L) so-far))
    )
  )
)


  