# So_long

Jeu 2D avec MiniLibX - Projet 42 Paris

## À propos

So_long est un projet de jeu vidéo 2D développé avec la bibliothèque MiniLibX. L'objectif est de créer un jeu où le joueur doit collecter tous les items et atteindre la sortie pour gagner.

Ce projet m'a permis de découvrir la programmation graphique, la gestion d'événements, et la création d'un jeu complet avec sprites, collisions, et mécaniques de gameplay. C'est un excellent projet pour apprendre à travailler avec des bibliothèques graphiques et à structurer un projet de jeu.

## Gameplay

Le joueur contrôle un personnage qui doit :
- Collecter tous les items (collectibles) sur la carte
- Éviter les ennemis (si présents)
- Atteindre la sortie pour gagner
- Le jeu affiche le nombre de mouvements effectués

## Utilisation

### Compilation

```bash
make
```

### Exécution

```bash
./so_long maps/map.ber
```

### Contrôles

- **W / ↑** : Déplacer vers le haut
- **S / ↓** : Déplacer vers le bas
- **A / ←** : Déplacer vers la gauche
- **D / →** : Déplacer vers la droite
- **ESC** : Quitter le jeu

## Format de carte (.ber)

La carte est un fichier texte avec les caractères suivants :

- **1** : Mur (wall)
- **0** : Sol (floor)
- **P** : Position de départ du joueur (player)
- **C** : Collectible (collectible)
- **E** : Sortie (exit)

### Exemple de carte

```
1111111111
1P00000001
1C00000001
1C00000001
1C00000001
1C00000001
1C00000001
1C00000001
1C000000E1
1111111111
```

## Règles de validation

- La carte doit être rectangulaire
- La carte doit être entourée de murs (1)
- Il doit y avoir exactement un joueur (P)
- Il doit y avoir au moins un collectible (C)
- Il doit y avoir exactement une sortie (E)
- La carte doit être jouable (chemin valide)

## Fonctionnalités

- Affichage graphique avec MiniLibX
- Gestion des textures et images
- Déplacement fluide du joueur
- Détection des collisions avec les murs
- Système de collecte d'items
- Compteur de mouvements
- Validation de la carte et gestion des erreurs

## Ce que j'ai appris

- Utilisation de la bibliothèque graphique MiniLibX
- Rendu 2D, sprites, textures
- Gestion des touches clavier et fermeture de fenêtre
- Lecture et validation de fichiers de configuration (cartes)
- Vérification de la jouabilité de la carte
- Organisation d'un projet de jeu
- Allocation et libération pour les graphiques

## Structure du projet

```
so_long/
├── src/
│   ├── main.c           # Fonction principale
│   ├── game.c           # Logique du jeu
│   ├── map.c            # Parsing et validation de carte
│   ├── player.c         # Gestion du joueur
│   ├── render.c         # Rendu graphique
│   └── utils.c          # Fonctions utilitaires
├── includes/
│   └── so_long.h        # Headers
├── textures/            # Images et sprites
├── maps/                # Fichiers de cartes
├── libft/               # Bibliothèque libft
├── mlx/                 # MiniLibX
├── Makefile
└── README.md
```

## Notes

- Le projet utilise MiniLibX qui est spécifique à macOS/Linux
- Les textures doivent être au format XPM
- La carte doit respecter strictement le format .ber
- Le jeu doit gérer proprement la fermeture de fenêtre

---

**Projet réalisé dans le cadre du cursus 42 Paris**
