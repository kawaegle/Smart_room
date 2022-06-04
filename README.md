[english version](english.md)

# SMART_R00M led
SMART_R00M est un système de gestion de led et d'ambiance lumineuse sans fils qui ce base sur différents modes adaptable au choix grâce à un boutons et à 3 potentiometre pour changer le RGB

## modes
La lumière sera definie par differents modes

1. Mode 1:
    - totalement blanc
    - idéale pour une ambiance de travail
2. Mode 2:
    - couleur definie par l'utilisateur a l'aide des potentiometre
    - idéal pour mettre une ambiance plus tamisé ou douce a une piéce
3. Mode 3:
    - arc en ciel
    - mouvement de rayon arc en ciel sur la bande
4. Mode 4: 
    - ambiance selon le son dans la piéce sur une seule couleur
    - plus agréable lors de session streaming
5. Mode 5:
    - ambiance selon le son de la piéce mais avec une disposition de couleur RGB
    - pour les soirées entre amis

l'utilisateur peut changer de mode grâce au boutons et configurer le mode 2 en maintenant le bouton

# Materiel

| Quantité        | Materiel        | Usage                     |
|---------------- | --------------- | ---------------           |
| 2               | [esp8266](https://fr.aliexpress.com/item/32631693796.html?spm=a2g0o.productlist.0.0.5bcb353dZYoU6U&algo_pvid=d8332e76-d9ec-4257-b02d-8042ef34f19f&algo_exp_id=d8332e76-d9ec-4257-b02d-8042ef34f19f-1&pdp_ext_f=%7B%22sku_id%22%3A%2259445695492%22%7D&pdp_pi=-1%3B2.22%3B-1%3B-1%40salePrice%3BEUR%3Bsearch-mainSearch)         | serveur et client         |
| 1               | [bandeau led](https://fr.aliexpress.com/item/4000501670491.html?spm=a2g0o.productlist.0.0.7329fea5cxc0KC&algo_pvid=ca294c14-8321-4bda-be78-3c7cb5f7dbe1&algo_exp_id=ca294c14-8321-4bda-be78-3c7cb5f7dbe1-15&pdp_ext_f=%7B%22sku_id%22%3A%2210000002384888360%22%7D&pdp_pi=-1%3B25.41%3B-1%3B-1%40salePrice%3BEUR%3Bsearch-mainSearch)    | source de lumiere         |
| 1               | [alimentation 12v 5A](https://fr.aliexpress.com/item/32794814341.html?gatewayAdapt=glo2fra&spm=a2g0o.9042311.0.0.340c6c37mzKLhG) | alimenté les led et le client|
| 1               | [microphone](https://fr.aliexpress.com/item/32238538869.html?gatewayAdapt=glo2fra&spm=a2g0o.9042311.0.0.27426c37jvYyF2)      | analyse du son ambiant    |
| 1               | [bouton](https://fr.aliexpress.com/item/1005003115135192.html?spm=a2g0o.productlist.0.0.122678c6tJRvrY&algo_pvid=ef812e8b-8061-4471-9c74-56c03aeefeb2&algo_exp_id=ef812e8b-8061-4471-9c74-56c03aeefeb2-30&pdp_ext_f=%7B%22sku_id%22%3A%2212000024181858304%22%7D&pdp_pi=-1%3B1.1%3B-1%3B-1%40salePrice%3BEUR%3Bsearch-mainSearch)          | changer de mode           |
| 1               | [interupteur](https://fr.aliexpress.com/item/4000899502087.html?gatewayAdapt=glo2fra&spm=a2g0o.9042311.0.0.27426c37jvYyF2)        | ON / OFF               |
| 3               | [potentiometre](https://fr.aliexpress.com/item/1005002222402620.html?gatewayAdapt=glo2fra&spm=a2g0o.9042311.0.0.340c6c37mzKLhG)   | changer les valeurs RGB   |
| 1               | [batterie](https://fr.aliexpress.com/item/1005001975519545.html?gatewayAdapt=glo2fra&spm=a2g0s.12269583.0.0.198d4a72BAOVVf) et [socle](https://fr.aliexpress.com/item/1005001707889794.html?gatewayAdapt=glo2fra&spm=a2g0o.9042311.0.0.27426c37jvYyF2)               | alimenter le server     |
| 1               | [chargeur usbC](https://fr.aliexpress.com/item/32798858483.html?gatewayAdapt=glo2fra&spm=a2g0o.9042311.0.0.27426c37jvYyF2) |  charger la batterie |
| 1               | [alimentation jack](https://fr.aliexpress.com/item/4000648876487.html?gatewayAdapt=glo2fra&spm=a2g0o.9042311.0.0.340c6c37mzKLhG) | alimenter le client |

# ressources
Dans l'idée que ceci est un projet, je me dois de garder une trace des eventuels resources qui m'ont aider a avancer dans le code ou dans la comprehension des probleme rencontrer.
