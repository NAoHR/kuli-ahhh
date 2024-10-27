FUNCTION tower_of_hanoi(n, t1, t2, t3)
    IF n == 1 THEN
        PRINT "Pindahkan DISK " + n + " DARI " t1 + " KE " t3
        RETURN
    END IF

    CALL tower_of_hanoi(n-1, t1, t3, t2)

    PRINT "Pindahkan DISK " + n + " DARI " t1 + " KE " t3
    
    CALL tower_of_hanoi(n-1, t2, t1, t3)

END FUNCTION



BEGIN PROGRAM
    DECLARE disc AS INTEGER

    PRINT "Masukkan Jumlah Disc: "
    READ input TO disc

    CALL tower_of_hanoi(disc, "T1", "T2", "T3")
END PROGRAM