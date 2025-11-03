// Menu burger qui permet de changer la section "Mode" qui est visible
document.addEventListener('DOMContentLoaded', function() { // Attend que le DOM soit complètement chargé sinon cas d'erreur possible
    const menuLinks = document.querySelectorAll('#MenuBurger a'); // Sélectionne tous les liens dans le menu burger
    const modes = document.querySelectorAll('.Mode'); // Sélectionne tous les "modes"
    
    menuLinks.forEach(link => { // Ajoute un écouteur d'événement à chaque lien
        link.addEventListener('click', function(event) { // Check le click
            event.preventDefault(); // Empêche le comportement par défaut du lien (donc le rechargement de la page)
            // Donne au bouton cliquer la classe CSS "menu-selected" pour indiquer qu'il est sélectionné
            menuLinks.forEach(l => l.querySelector('.menu-icon').classList.remove('menu-selected'));
            this.querySelector('.menu-icon').classList.add('menu-selected');
            
            
            const targetId = this.getAttribute('href').substring(1); // Récupère l'ID de la section cible (sans le #)
            modes.forEach(mode => { // Parcourt tous les modes
                mode.style.display = mode.id === targetId ? 'block' : 'none'; // Affiche le mode cible et cache les autres
            });
        });
    });
    modes.forEach(mode => { // Au chargement de la page, cache tous les modes
        mode.style.display = 'none';
    });
    if (modes.length > 0) { // Affiche le premier mode par défaut (dans notre cas, ModeImagesManuel)
        modes[0].style.display = 'block'; // Affiche le premier mode
    }
});