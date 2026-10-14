# System monitorowania parametrów - statek badawczy ARGO

Program konsolowy w języku C, który symuluje system monitorowania jednego z modułów pokładowych statku badawczego ARGO. Odczyty nie są wczytywane z pliku, wpisuje je użytkownik w trakcie działania programu.

## Opis zadania

Każdy odczyt jest liczbą całkowitą z przedziału `[-50; 50]`. System przechowuje ograniczoną liczbę ostatnich odczytów i umożliwia ich bieżącą analizę. Odczyt alarmowy to wartość spoza przedziału `[-40; 40]`.

### Logowanie

- użytkownik ma maksymalnie 3 próby podania PIN-u
- po 3 błędnych próbach program kończy działanie
- po wylogowaniu program wraca do ekranu logowania, a zapisane odczyty pozostają w pamięci

### Menu

| Opcja | Działanie |
|-------|-----------|
| 1 | Dodanie nowego odczytu |
| 2 | Zmiana wybranego odczytu |
| 3 | Wyświetlenie zapisanych odczytów |
| 4 | Wyświetlenie podstawowych statystyk |
| 5 | Wyświetlenie odczytów przekraczających poziom alarmowy |
| 6 | Wyczyszczenie zapisanych danych |
| 7 | Wylogowanie |

### Bufor odczytów

System przechowuje maksymalnie **8** ostatnich odczytów. Po zapełnieniu pamięci dodanie nowego odczytu usuwa najstarszą wartość, a pozostałe są przesuwane.

### Statystyki

- średnia wartość odczytów
- liczba odczytów większych od średniej
- największy wzrost pomiędzy kolejnymi odczytami
- największy spadek pomiędzy kolejnymi odczytami

### Obsługa błędów

Program kontroluje poprawność danych wejściowych:

- wartość niewłaściwego typu (np. litery zamiast liczby)
- odczyt spoza zakresu `[-50; 50]`
- nieistniejąca opcja menu
- nieistniejąca pozycja przy edycji odczytu

W każdym z tych przypadków wyświetlany jest komunikat i użytkownik może ponowić wprowadzanie. Operacje na pustym buforze (statystyki, edycja, wyświetlanie, czyszczenie) kończą się informacją, że lista jest pusta. Błędne dane nie powodują odwołania poza granice tablicy.

## Kompilacja i uruchomienie

```bash
gcc ZadanieGlowneArgo2.c -o ZadanieGlowneArgo2
./ZadanieGlowneArgo2
```

## Domyślny PIN

`1234` (zmienna `pin` w kodzie)
