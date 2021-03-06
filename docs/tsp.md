# Travelling Salesman Problem

The [Travelling Salesman Problem](https://en.wikipedia.org/wiki/Travelling_salesman_problem) is a wellknown NP-hard problem in combinatorial optimization. The goal is to find the shortest possible route that visits each city and returns to the origin city.

## Material
  - Acrylic sheet
  - Laser cutting
  - Blu-Tack of different colors
  - String

## DIY
  1. Cut the [map](https://github.com/mpelleau/FunCS/tree/master/TSP/france.svg) in an acrylic sheet
  2. Cut tokens
  3. Tie the string to a token
  
  ![Start token](https://raw.githubusercontent.com/mpelleau/FunCS/master/TSP/pictures/DSC_0030.JPG)
  
  4. Fix the tokens to the map using the Blu-Tack
  
  ![Tokens ready](https://raw.githubusercontent.com/mpelleau/FunCS/master/TSP/pictures/DSC_0031.JPG)
  
  5. Using the notes, mark the string where the solution is
  
  ![Activity ready](https://raw.githubusercontent.com/mpelleau/FunCS/master/TSP/pictures/DSC_0032.JPG)
  
## Activity description
  1. Tell the participants that they are big stars with their own jet, and that they want to visit all of their friends living in the cities in green, but they do not want to spend to much time in their jet eventhough it is a very comfy jet
  2. Let them play, and try to find the optimal route
  3. If they did not find the optimal guide them towards the optimal route (cf. [note](https://github.com/mpelleau/FunCS/tree/master/TSP/en/noteGreen.pdf))
  4. When the optimal route is found, repeat adding the [blue](https://github.com/mpelleau/FunCS/tree/master/TSP/en/noteBlue.pdf) cities, then the [red](https://github.com/mpelleau/FunCS/tree/master/TSP/en/noteRed.pdf) ones, and finally the [black](https://github.com/mpelleau/FunCS/tree/master/TSP/en/noteBlack.pdf) ones

## Sources
  - a vectoriel image for the [map of France](https://github.com/mpelleau/FunCS/tree/master/TSP/france.svg)
  - notes in english ([green](https://github.com/mpelleau/FunCS/tree/master/TSP/en/noteGreen.pdf), [blue](https://github.com/mpelleau/FunCS/tree/master/TSP/en/noteBlue.pdf), [red](https://github.com/mpelleau/FunCS/tree/master/TSP/en/noteRed.pdf), [black](https://github.com/mpelleau/FunCS/tree/master/TSP/en/noteBlack.pdf) and [complete](https://github.com/mpelleau/FunCS/tree/master/TSP/en/noteComplete.pdf) route) and in french ([green](https://github.com/mpelleau/FunCS/tree/master/TSP/fr/ficheVert.pdf), [blue](https://github.com/mpelleau/FunCS/tree/master/TSP/fr/ficheBleu.pdf), [red](https://github.com/mpelleau/FunCS/tree/master/TSP/fr/ficheRouge.pdf), [black](https://github.com/mpelleau/FunCS/tree/master/TSP/fr/ficheNoir.pdf) and [complete](https://github.com/mpelleau/FunCS/tree/master/TSP/fr/ficheComplet.pdf) route)
  - you can add your cities to the map and generate the corresponding LaTeX file for the notes using `java -jar "svg2tikz.jar" france.svg` (jar available [here](https://github.com/mpelleau/FunCS/tree/master/TSP/svg2tikz/svg2tikz.jar))

## Other Activities
  - [Lights out](./lights-out.md)
  - [N-queens](./n-queens.md)
