Steps to run this program : 
1. In the program (L49), modify [dbname], [username], [password] to
   yours ([dbname] is the same as your [username] by default).
2. Preprocessor - $ ecpg -I "D:\PostgreSql\include" sdap_1.pgc
3. Compile      - $ gcc -c -I "D:\PostgreSql\include" sdap_1.c
4. Link         - $ gcc -L "D:\PostgreSql\lib" -lecpg -o sdap_1 sdap_1.o
5. Execute      - $ .\sdap_1