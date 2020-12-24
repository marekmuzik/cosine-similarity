# cosine-similarity
Napište program, který bude představovat jednoduchý klasifikátor založený na kosinové míře podobnosti (cosine similarity measure).

Váš program bude dynamicky alokovat dvourozměrné pole desetinných čísel o velikosti M x N (M řádků, N sloupců), které naplní náhodnými hodnotami. K tomu vyalokuje jednorozměrné pole desetinných čísel o N prvcích. Interval pro generování náhodných čísel je pro obě pole stejný: <-100;100>. Desetinná čísla náhodně generujte se dvěma desetinnými místy (pozor, funkce rand() vrací pouze celá čísla, je tedy třeba provést ještě nějaké kroky navíc, abyste získali desetinné číslo).

Nakonec vyalokujte ještě jedno 1D pole, které bude mít M prvků. Toto bude pole řetězců, které bude obsahovat barvy (tedy řetězce „cervena“, „zelena“, „modra“, „bila“, „cerna“ - celkem pět barev). Účelem tohoto pole je „obarvit“ jednotlivé řádky 2D pole, každý řádek tedy bude mít svou barvu (řádek s indexem i bude mít takovou barvu, jaká se nachází na indexu i v poli barev). I toto pole barev vygenerujte náhodně.

Dynamická alokace polí a generování jejich hodnot bude probíhat v samostatných funkcích.

Dále napište samostatnou funkci, která jako argumenty přijme 2D a 1D pole desetinných čísel a pro každý řádek 2D pole vypočítá kosinovou podobnost s 1D polem. Algoritmus výpočtu najdete třeba na Wiki: https://en.wikipedia.org/wiki/Cosine_similarity

Pro některý řádek 2D pole vyjde podobnost s 1D polem největší (podobnost může nabývat hodnot z intervalu <-1;1>). 1D poli tedy přiřaďte barvu tohoto řádku a tuto barvu vypište.
