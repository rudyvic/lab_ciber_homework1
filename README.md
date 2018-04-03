# lab_ciber_homework1
Per risolvere questo homework sono stati utilizzati 3 nodi ed 1 messaggio.

Il messaggio è Student e contiene il nome, l'età e il corso di laurea.

I nodi sono:
<br>_ generator: è il nodo che si occupa di pubblicare un utente nuovo 1 volta al secondo. Pubblica sul topic 'students'.
<br>_ selector_key_op: è il nodo che si occupa di leggere da tastiera i comandi dell'utente e di pubblicare il comando selezionato. Pubblica sul topic 'selection'.
<br>_ viewer: è il nodo che si occupa di stampare a video le informazioni sugli studenti in base ai comandi scelti dall'utente. E' iscritto ai topic 'students' (dal quale prende le informazioni dello studente) e 'selection' (dal quale prende il comando per poter poi scegliere quale campo stampare).

<br>Scelte progettuali:
<br>_ per il nodo generator i messaggi vengono generati in modo casuale tramite la rand().
<br>_ per il nodo selector_key_op la lettura da tastiera avviene tramite delle getchar(), e quindi è necessario un ENTER da parte dell'utente per poter inviare il comando.
