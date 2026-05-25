
(define/contract (count-pyramids grid)
  (-> (listof (listof exact-integer?)) exact-integer?)
  
  (define m (length grid))
  (define n (length (first grid)))
  
  (define g (list->vector (map list->vector grid)))
  
  (define memo (make-hash))
  
  (define (val i j)
    (vector-ref (vector-ref g i) j))
  
  (define (dp i j dr)
    (define key (list i j dr))
    
    (cond
      [(hash-has-key? memo key)
       (hash-ref memo key)]
      
      [else
       (define res
         (if (and (= (val i j) 1)
                  (<= 0 (+ i dr))
                  (< (+ i dr) m)
                  (> j 0)
                  (< (+ j 1) n)
                  (= (val (+ i dr) j) 1))
             
             (+ 1
                (min (dp (+ i dr) (- j 1) dr)
                     (dp (+ i dr) (+ j 1) dr)))
             
             (val i j)))
       
       (hash-set! memo key res)
       res]))
  
  (define ans 0)
  
  (for* ([i (in-range m)]
         [j (in-range n)])
    
    (set! ans (+ ans (max 0 (- (dp i j 1) 1))))
    (set! ans (+ ans (max 0 (- (dp i j -1) 1)))))
  
  ans)