# Introduction

Ce projet d'informatique a été réalisé par Mehdi Tarchoul et Thomas Labb-Nobili dans le cadre du module programmation C.

## Démineur

Le champ de mines est représenté par une grille en deux dimensions, avec un pavage rectangulaire.

Chaque case de la grille peut soit cacher une mine, soit être vide. Le but du jeu est de découvrir toutes les cases libres sans faire exploser les mines, c'est-à-dire sans cliquer sur les cases qui les dissimulent.

Lorsque le joueur clique sur une case libre comportant au moins une mine dans l'une de ses cases avoisinantes, un chiffre apparaît, indiquant ce nombre de mines. Si en revanche toutes les cases adjacentes sont vides, une case vide est affichée et la même opération est répétée sur ces cases, et ce jusqu'à ce que la zone vide soit entièrement délimitée par des chiffres. En comparant les différentes informations récoltées, le joueur peut ainsi progresser dans le déminage du terrain. S'il se trompe et clique sur une mine, il a perdu.

On peut signaler les cases contenant des mines présumées par un drapeau en cliquant sur le bouton droit de la souris — mais ce n'est aucunement obligatoire. Il faut faire attention à ne pas signaler une case saine par un drapeau, car cela peut induire en erreur ; ce n'est toutefois pas aussi pénalisant que de découvrir une mine.

# Installation

`gcc main.c -o main`

`./main`

### Facile

Le jeu se déroulera sur une grille de 9x9 et le nombre de mine sera limité à 10.

### Medium

Le jeu se déroulera sur une grille de 16x16 et le nombre de mine sera limité à 40.


