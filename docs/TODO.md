# TODO so_long

## Liste de contrôle de la carte

- ✅ Analyser la carte Lors de l'analyse de la carte, vous pouvez déjà vérifier certaines erreurs, avant même d'aller plus loin
  - ✅ Le fichier map existe-t-il ?
  - ✅ La carte est-elle rectangulaire ?
  - ✅ Toutes les lignes doivent avoir la même longueur.
  - ✅ Y a-t-il quelque chose dans le fichier map ?
  - ✅ La carte est-elle enfermée dans des murs ?
    - ✅ Vérifiez les première et dernière lignes et colonnes, elles doivent toutes être `1`
  - ✅ Il n'y a qu'une seule sortie ?
    - ✅ Comptez simplement combien `E` vous en trouvez sur la carte.
  - ✅ Y a-t-il une seule position de départ ?
    - ✅ Comptez simplement combien `P` vous en trouvez sur la carte.
  - ✅ Y a-t-il au moins un objet de collection ?
    - ✅ Comptez simplement combien `C` vous en trouvez sur la carte.
- ✅ La sortie est-elle accessible depuis la position de départ
- ✅ Tous les objets de collection sont-ils accessibles depuis la position de départ.

## Liste de contrôle du jeu

- Créer une fenêtre en utilisant MiniLibX
  - Créez la structure requise pour stocker toutes les informations nécessaires
- Chargez tous les sprites (images) requis pour votre jeu et stockez-les en mémoire
- Créer les différents crochets
  - gestionnaire_de_clés
  - mouse_handler (si nécessaire)
  - close_handler, c'est un hook sur la croix rouge qui ferme correctement le programme
  - loop_hook (=> votre boucle de jeu)

## Liste de contrôle de rendu

- Dessiner l'arrière-plan
- Dessinez les parties non mobiles de la carte
- Dessine le joueur

## Gestionnaire de clés

Le gestionnaire de touches (au moins dans mon jeu), est principalement utilisé pour appeler la fonction update_player_position lorsque W, A, S ou D est pressé ou pour fermer correctement le programme lorsque nous appuyons sur la touche ESC.

Il y a certaines choses auxquelles vous devez penser avant de mettre à jour la position du joueur.

- La nouvelle position demandée est-elle un mur ?
  - si la nouvelle position est un mur, ne faites rien. Le sujet dit que le joueur ne devrait pas pouvoir traverser les murs
- La nouvelle position demandée est-elle à l'intérieur de la carte ?
  - Si la nouvelle position est en dehors de la carte, ne faites rien. Normalement, cela ne devrait pas arriver puisque la carte est entourée de murs, mais bon, on n'en est jamais sûr.
- Le nouveau poste demandé est-il un objet de collection ?
  - si oui, mettez à jour le compteur d'objets collectés et vérifiez
    - vérifier si tous les objets de collection ont été collectés
      - si oui, déverrouillez la sortie
    - mettez à jour votre tableau de cartes 2D et remplacez l'objet de collection par une tuile « sol » afin qu'il ne soit pas dessiné dans la prochaine itération de la boucle de jeu.
- Si la nouvelle position demandée n'est ni un mur, ni un objet de collection, ni à l'extérieur de la carte, définissez simplement la position du joueur sur la nouvelle position demandée.
