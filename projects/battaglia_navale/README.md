# Battaglia Navale

Un semplice gioco di battaglia navale implementato in C che si gioca nel terminale.

## Descrizione

Questo programma simula il classico gioco della battaglia navale con navi di dimensione 1. Il giocatore deve indovinare la posizione delle navi nemiche nascoste in una griglia. Ogni nave occupa una sola cella.

## Funzionalità

- Dimensioni del campo di gioco personalizzabili (righe e colonne)
- Numero di navi personalizzabile o generato casualmente
- Numero di turni personalizzabile o generato casualmente
- Visualizzazione grafica della griglia nel terminale
- Input delle coordinate in formato alfanumerico (es. "A10")
- Statistiche finali sul risultato della partita

## Legenda del campo di gioco

- ` ` (spazio): nessuna nave, nessun colpo
- `.`: nave nascosta (visibile solo per debug)
- `O`: colpo a vuoto
- `X`: nave colpita e affondata

## Esempio di utilizzo

```
+==========================+
|   BATTAGLIA NAVALE 1.0   |
|      Giulio Mareschi     |
+==========================+

Questo gioco simula la battaglia navale con navi di dimensione |1|.

[?] Inserire il numero di colonne (min 2 | max 26): 10

[?] Inserire il numero di righe (min 2 | max 99): 10

[?] Inserire il numero di navi (min 1 | max 100 | 0 per random): 0
[i] Numero navi generato: 15

[?] Inserire il numero di turni (min 15 | max 100 | 0 per random): 30
[i] Numero turni generato: 45

-- TURNO 1/45 --

   A B C D E F G H I J 
 1| | | | | | | | | | |
 2| | | | | | | | | | |
...

Inserire coordinate: B5
[^] NAVE AFFONDATA!
```

## Autore

Giulio Mareschi
