STRUCT Siswa
    no_registrasi: INTEGER
    nama: STRING
    umur: INTEGER
END STRUCT

FUNCTION tambah_siswa()

    OPEN "database_siswa.csv" WITH reading AND writing MODE AS file

    IF file IS NULL THEN
        PRINT "Gagal membuka file."
        RETURN
    END IF

    DECLARE siswa AS Siswa
    
    PRINT "Masukkan Nomor Registrasi:"
    READ siswa.no_registrasi
    
    WHILE NOT END OF file
        READ line

        SPLIT line FROM DELIMITER ";"
        DECLARE no_reg FROM LINE FIRST ELEMENT

        IF no_reg EQUALS siswa.no_registrasi THEN
            PRINT "Data Sudah Ada Dalam Database"
            CLOSE file
            RETURN
    END WHILE

    MOVE TO END OF file

    PRINT "Masukkan nama siswa:"
    READ siswa.nama

    PRINT "Masukkan umur siswa:"
    READ siswa.umur

    WRITE siswa.no_registrasi + ";" + siswa.nama + ";" + siswa.umur + "\n" TO file

    PRINT "Data siswa berhasil ditambahkan!"

    CLOSE file

END FUNCTION

FUNCTION cari_siswa()
    
    OPEN "database_siswa.csv" WITH reading MODE as file

    IF file IS NOT opened THEN
        PRINT "Gagal membuka file."
        RETURN
    END IF

    DECLARE no_registrasi
    DECLARE siswa AS Siswa
    DECLARE is_found = 0

    PRINT "Masukkan nomor registrasi siswa: "
    READ no_registrasi

    WHILE NOT END OF file
        READ line
        
        SPLIT line FROM DELIMITER ";"
        ASSIGN siswa.no_registrasi FROM FIRST line ELEMENT
        ASSIGN siswa.nama FROM SECOND line ELEMENT
        ASSIGN siswa.umur FROM THIRD line ELEMENT

        IF siswa.no_registrasi EQUALS no_registrasi THEN
            PRINT "Data ditemukan:"
            PRINT "Nama:", siswa.nama, "Umur:", siswa.umur, "No. Registrasi:", siswa.no_registrasi
            is_found = 1
            BREAK
        END IF
    END WHILE
    
    CLOSE file

    IF is_found IS 0 THEN
        PRINT "Data Tidak Ditemukan."
    END IF


END FUNCTION

FUNCTION hapus_siswa()
    
    OPEN file "database_siswa.csv" IN read mode
    OPEN tempFile "temp.csv" IN write mode
    
    IF file OR tempFile IS NOT opened THEN
        PRINT "Gagal membuka file."
        RETURN
    END IF

    DECLARE no_registrasi, found AS INTEGER
    DECLARE siswa AS Siswa
    found = 0

    PRINT "Masukkan nomor registrasi: "
    READ no_registrasi

    WHILE NOT end of file
        READ line
        
        SPLIT line FROM DELIMITER ";"
        DECLARE existing_reg FROM FIRST line ELEMENT

        IF existing_reg NOT EQUALS no_registrasi THEN
            WRITE line TO tempFile
        ELSE
            found = 1
        END IF
    END WHILE

    CLOSE file
    CLOSE tempFile

    DELETE "database_siswa.csv"
    RENAME "temp.csv" TO "database_siswa.csv"

    IF found IS 1 THEN
        PRINT "Data berhasil dihapus."
    ELSE
        PRINT "Data tidak ditemukan."
    END IF

END FUNCTION

FUNCTION main()
DECLARE pilihan AS INTEGER

    DO
        PRINT "--- Siswa Database Management ---"
        PRINT "1. Tambah Siswa"
        PRINT "2. Cari Siswa"
        PRINT "3. Hapus Siswa"
        PRINT "4. Keluar"
        PRINT "Pilih opsi:"
        READ pilihan

        SWITCH pilihan
            CASE 1:
                CALL tambah_siswa()
            CASE 2:
                CALL cari_siswa()
            CASE 3:
                CALL hapus_siswa()
            CASE 4:
                PRINT "Keluar dari program."
                EXIT
            DEFAULT:
                PRINT "Input Tidak Valid"
        END SWITCH
    WHILE pilihan NOT EQUALS 4

END FUNCTION
