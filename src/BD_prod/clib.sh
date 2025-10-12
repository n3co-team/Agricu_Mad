# creation fichier objet
gcc -c -fPIC tubercule-test_fr.c

# creation de bibliotheque
gcc -shared -o libbdproduit.so tubercule-test_fr.o

#deplacement
mv *.so ../../lib/lib_so/

#suppression 
rm *.o
