#creatio de fichier objet
gcc -c -fPIC conven_a.c

#creatio de bibliotheque dynamique
gcc -shared -o libconven.so conven_a.o

#deplacement
mv *.so ../../lib/lib_so/

#suppression des objets dans le repertoire courant
rm *.o
