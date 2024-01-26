from PIL import Image

# Charger l'image
image_grande = Image.open("tileset.png")

# Obtenir la taille de l'image
largeur, hauteur = image_grande.size

# Taille des petites images
taille_petite_image = 192
i = 0

# Boucle pour découper l'image en petites images
for y in range(0, hauteur, taille_petite_image):
    for x in range(0, largeur, taille_petite_image):
        # Découper la région de l'image
        region = (x, y, x + taille_petite_image, y + taille_petite_image)
        petite_image = image_grande.crop(region)
        i += 1
        # Enregistrer la petite image
        nom_fichier = f"petite_image_{i}.png"
        petite_image.save(nom_fichier)

print("Découpage terminé.")
